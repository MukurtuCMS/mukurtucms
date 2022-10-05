<?php
DEFINE('RESUMABLE_DOWNLOAD_KB_PER_READ', 2);    // min = 1, max = 8
// don't touch the defines below, they are automatically calculated:
DEFINE('RESUMABLE_DOWNLOAD_SLEEP_NUMERATOR', RESUMABLE_DOWNLOAD_KB_PER_READ * 1000000);
DEFINE('RESUMABLE_DOWNLOAD_MINIMUM_SLEEP_TIME', RESUMABLE_DOWNLOAD_KB_PER_READ * 100);
DEFINE('RESUMABLE_DOWNLOAD_BYTES_PER_READ', RESUMABLE_DOWNLOAD_KB_PER_READ * 1024);

function _resumable_download_download() {
  // Merge remainder of arguments from GET['q'], into relative file path.
  $args = func_get_args();
  $priv_or_pub = $args[0];
  unset($args[0]);
  $filepath = implode('/', $args);
  // Maintain compatibility with old ?file=paths saved in node bodies.
  /*
  if (isset($_GET['file'])) {
    $filepath =  $_GET['file'];
  }
  *///do we still need this above?

  $uri = $priv_or_pub . '://' . $filepath;
  $filepath = drupal_realpath($uri);

  if (file_exists($filepath)) {
    $headers = module_invoke_all('file_download', $uri);
    if (in_array(-1, $headers)) {
      return drupal_access_denied();
    }
    if (count($headers)) {
	  $max_speed = variable_get('resumable_download_max_speed', NULL);
	  if (user_access('bypass download speed limit')) {
	    $max_speed = NULL;
	  }
      _resumable_download($filepath, $headers, $max_speed);
    }
  }
  return drupal_not_found();
}

function _resumable_download($source, $headers, $max_speed = NULL) {
  if (ob_get_level()) {
    ob_end_clean();
  }
  
  // IE cannot download private files because it cannot store files downloaded
  // over https in the browser cache. The problem can be solved by sending
  // custom headers to IE. See http://support.microsoft.com/kb/323308/en-us
  if (isset($_SERVER['HTTPS']) && ($_SERVER['HTTPS'] == 'on')) {
    resumable_download_drupal_add_http_header('Cache-Control','private');
    resumable_download_drupal_add_http_header('Pragma','private');
  }
  
  foreach ($headers as $key => $header) {
    // To prevent HTTP header injection, we delete new lines that are
    // not followed by a space or a tab.
    // See http://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html#sec4.2
    //$header = preg_replace('/\r?\n(?!\t| )/', '', $header);
    resumable_download_drupal_add_http_header($key, $header);
  }
  
  if ($fd = fopen($source, 'rb')) {
    // Get file size.
    $filesize = filesize($source);
    $end_file = $filesize - 1;
    // Set Last-Modified and ETag headers.
    $filemtime = filemtime($source);
    resumable_download_drupal_add_http_header('Last-Modified', gmdate('D, d M Y H:i:s', $filemtime) . ' GMT');
    resumable_download_drupal_add_http_header('ETag', dechex(fileinode($source)) . '-' . dechex($filemtime) . '-' . dechex($filesize));
	//resumable_download_drupal_add_http_header('Content-Disposition', 'attachment; filename="' . basename($filesize) . '"'); 
	//resumable_download_drupal_add_http_header('Content-type', 'application/octet-stream');
   
    // Tell client that we accept byte ranges.
    resumable_download_drupal_add_http_header('Accept-Ranges', 'bytes');
	
    $valid = FALSE;
    $satisfiable = FALSE;
    // Is this a partial request?
	
    if (isset($_SERVER['HTTP_RANGE'])) {
      preg_match('/^bytes=(\S+)$/i', $_SERVER['HTTP_RANGE'], $ranges);
      $ranges = explode(',', array_pop($ranges));
	  			
      // Check for valid ranges.
      foreach ($ranges as $key => $range) {
        if (substr_count($range, '-') == 1) {
          $valid = TRUE;
          if (substr($range, 0, 1) == '-') {
            $satisfiable = TRUE;
            $ranges[$key] = array('from' => max(0, $end_file + $range), 'to' => $end_file);
          }
          else {
            $range = explode('-', $range);
            if ($range[0] <= $end_file) {
              if ($range[1] === '') {
                $satisfiable = TRUE;
                $ranges[$key] = array('from' => $range[0], 'to' => $end_file);
              }
              elseif ($range[0] <= $range[1]) {
                $satisfiable = TRUE;
                $ranges[$key] = array('from' => $range[0], 'to' => min($range[1], $end_file));
              }
            }
          }
        }
        if (!$valid || !$satisfiable) {
          unset($ranges[$key]);
        }
      }
      // Check for overlapping ranges.
      $cranges = $ranges;
      foreach ($ranges as $key => $range) {
        foreach ($cranges as $ckey => $crange) {
          // Don't compare a range to itself.
          if ($key == $ckey) {
            unset($cranges[$ckey]);
          }
          else {
            $overlap = FALSE;
            // The beginning of this range is in another range.
            if ($range['from'] >= $crange['from'] && $range['from'] <= $crange['to'] + 1) {
              $ranges[$key]['from'] = $range['from'] = $crange['from'];
              $overlap = TRUE;
            }
            // The end of this range is in another range.
            if ($range['to'] <= $crange['to'] && $range['to'] >= $crange['from'] - 1) {
              $ranges[$key]['to'] = $range['to'] = $crange['to'];
              $overlap = TRUE;
            }
            if ($overlap) {
              unset($ranges[$ckey], $cranges[$ckey]);
            }
          }
        }
      }
    }
	
    if ($satisfiable) {
      resumable_download_drupal_add_http_header('Status', '206 Partial Content');
	  
      if (count($ranges) == 1) {
        $range = array_shift($ranges);
        resumable_download_drupal_add_http_header('Content-Range' , sprintf('bytes %d-%d/%d', $range['from'], $range['to'], $filesize));
        resumable_download_drupal_add_http_header('Content-Length', sprintf('%d', $range['to'] + 1 - $range['from']));
        resumable_download_transfer_range($fd, $range['to'] + 1 - $range['from'], $range['from'], $max_speed);
      }
      else {
        $type = '';
        foreach ($headers as $header) {
          $header = trim($header);
          if (stripos($header, 'Content-Type') === 0) {
            $type = "$header\n";
            break;
          }
        }
        $boundary = md5(rand());
        resumable_download_drupal_add_http_header('Content-Type', 'multipart/byteranges; boundary=$boundary');
        foreach ($ranges as $range) {
          print "--$boundary\n";
          print $type;
          print sprintf('Content-Range: bytes %d-%d/%d', $range['from'], $range['to'], $filesize) . "\n";
          resumable_download_transfer_range($fd, $range['to'] + 1 - $range['from'], $range['from'], $max_speed);
          print "\n";
        }
        print "--$boundary--";
      }
    }
    else {
      if ($valid && !isset($_SERVER['If-Range'])) {
        resumable_download_drupal_add_http_header('Status', '416 Requested Range Not Satisfiable');
        resumable_download_drupal_add_http_header('Content-Range', '*');
      }
      else {
        $length = $filesize;
      }
    }
    if (isset($length)) {
      resumable_download_drupal_add_http_header('Content-Length', $length);
      resumable_download_transfer_range($fd, $length, 0, $max_speed);
    }
    fclose($fd);
  }
  else {
    drupal_not_found();
  }
  exit();
}


/**
 * Transfer a byte-range in 1024 byte chunks to save memory usage.
 * @param $fd A file system pointer resource
 * @param $length Number of bytes to transfer
 * @param $byte Starting byte for this range
 * @param $max_speed Download speed in byte
 */
function resumable_download_transfer_range($fd, $length, $byte = 0, $max_speed = NULL) {
  /*
   * The following code attempts to balance the needs of:
   * - large files don't overly degrade server performance (max flush once per second)
   * - download rate limits can be as low as 1kb/s
   * - browsers with poor connections don't time out easily
   */
  if ($max_speed == 0) {
    $max_speed = NULL;
  }
  
  if (!is_null($max_speed)) {
    $sleepTime = RESUMABLE_DOWNLOAD_SLEEP_NUMERATOR / $max_speed;
    $sleepTime = max($sleepTime, RESUMABLE_DOWNLOAD_MINIMUM_SLEEP_TIME);    // limit stress on server
   
    $expectedreads = ceil($length / RESUMABLE_DOWNLOAD_BYTES_PER_READ);

    $reads_per_second = $max_speed / RESUMABLE_DOWNLOAD_KB_PER_READ;
    $reads_until_flush = $reads_per_second;
    set_time_limit(0);                // we do not want to time out from our end
   
    // Move file pointer to starting byte.
    fseek($fd, $byte);
  
    for (
    $numreads = $expectedreads;
    !(connection_aborted() || connection_status() == 1) && ($numreads>0);
    --$numreads)
    {
      print(fread($fd, RESUMABLE_DOWNLOAD_BYTES_PER_READ));    // transfer chunk of data (note: fread max is 8k)
      usleep($sleepTime);                    // limit the output rate (give the web server a rest)
      --$reads_until_flush;
      if ($reads_until_flush <= 0) {
        flush();                        // push it to the browser (avoids timeouts)
        $reads_until_flush = $reads_per_second;
      }
    }
  } else {
    // Move file pointer to starting byte.
    fseek($fd, $byte);
    while (!(connection_aborted() || connection_status() == 1) && $length > 0) {
      $read = min(1024, $length);
      print fread($fd, $read);
      $length -= $read;
    }  
  }
}

/**
* For compatiblity with Drupal 6 and 7
*/
function resumable_download_drupal_add_http_header($name, $value, $append = FALSE) {
  return drupal_add_http_header($name, $value, $append);  
}