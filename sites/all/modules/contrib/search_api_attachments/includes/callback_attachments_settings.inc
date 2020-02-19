<?php

/**
 * @file
 * Search API data alteration callback.
 */

/**
 * Indexes files content.
 */
class SearchApiAttachmentsAlterSettings extends SearchApiAbstractAlterCallback {

  // Cache table name.
  const CACHE_TABLE = 'cache_search_api_attachments';

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {

    if ($this->index->getEntityType() == 'file' || $this->isMultipleIndexWithFile()) {
      foreach ($items as &$item) {
        $file = array();
        if ($this->isMultipleIndexWithFile()) {
          $file = (array) $item->file;
        } else {
          foreach ($item as $key => $value) {
            $file[$key] = $value;
          }
        }
        if ($this->isFileIndexable($file, $item)) {
          $item->attachments_content = $this->getFileContent($file);
        }
      }
    }
    else {
      $fields = $this->getIndexableFileFields();
      foreach ($items as &$item) {
        foreach ($fields as $name => $field) {
          if (isset($item->$name)) {
            foreach ($item->$name as $value) {
              // Limit to the max number of value per field.
              if (isset($this->options['number_indexed']) && $this->options['number_indexed'] != '0' && count($value) > $this->options['number_indexed']) {
                $value = array_slice($value, 0, $this->options['number_indexed']);
              }
              foreach ($value as $file) {
                if ($this->isFileIndexable($file, $item, $name)) {
                  $attachments = 'attachments_' . $name;
                  if (isset($item->{$attachments})) {
                    $item->{$attachments} .= ' ' . $this->getFileContent($file);
                  }
                  else {
                    $item->{$attachments} = $this->getFileContent($file);
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /**
   * Checks if file is allowed to be indexed.
   *
   * @param object $file
   *   The file object.
   * @param object $item
   *   The search api item.
   * @param string $field_name
   *   The file name.
   *
   * @return bool
   *   TRUE is the file is allowed to be indexed, FALSE otherwise.
   */
  public function isFileIndexable($file, $item, $field_name = NULL) {
    // File entity bundle restriction.
    if (isset($this->options['excluded_file_entity_bundles'])) {
      if (!empty($this->options['excluded_file_entity_bundles'])) {
        if (in_array($file->type, $this->options['excluded_file_entity_bundles'])) {
          return FALSE;
        }
      }
    }

    // Extension restriction.
    $exclude = array();
    foreach (explode(' ', $this->options['excluded_extensions']) as $ext) {
      $exclude[$ext] = file_get_mimetype('dummy.' . $ext);
    }

    // File size restriction.
    if (isset($this->options['max_file_size'])) {
      $max_file_size = parse_size($this->options['max_file_size']);
    }
    else {
      $max_file_size = '0';
    }

    // Checking for missing content.
    if (empty($file)) {
      watchdog('search_api_attachments', 'file is empty for item %item_title (%item_nid)',
        array(
          '%item_title' => empty($item->title) ? t('empty') : $item->title,
          '%item_nid' => empty($item->nid) ? (empty($item->id) ? t('empty') : $item->id) : $item->nid),
        WATCHDOG_ERROR);
    }
    // Private file restriction.
    else if (!$this->isTemporary($file) && !($this->options['excluded_private'] && $this->isPrivate($file))) {
      // Extension restriction.
      if (!in_array($file['filemime'], $exclude)) {
        // File size restriction.
        $file_size_errors = file_validate_size((object) $file, $max_file_size);
        if (empty($file_size_errors)) {
          // Allow customization of indexability rules.
          foreach (module_implements('search_api_attachments_indexable') as $module) {
            if (module_invoke($module, 'search_api_attachments_indexable', $file, $item, $field_name) === FALSE) {
              return FALSE;
            }
          }
          return TRUE;
        }
      }
    }
    return FALSE;
  }

  /**
   * Adds configuration form.
   *
   * @return array
   *   The configuration form.
   */
  public function configurationForm() {
    $default = implode(' ', search_api_attachments_default_excluded());
    $form['excluded_extensions'] = array(
      '#type' => 'textfield',
      '#title' => t('Excluded file extensions'),
      '#default_value' => isset($this->options['excluded_extensions']) ? $this->options['excluded_extensions'] : $default,
      '#size' => 80,
      '#maxlength' => 255,
      '#description' => t('File extensions that are excluded from indexing. Separate extensions with a space and do not include the leading dot. Extensions are internally mapped to a MIME type, so it is not necessary to put variations that map to the same type (e.g. tif is sufficient for tif and tiff)'),
    );
    $form['number_indexed'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of file indexed per file field'),
      '#default_value' => isset($this->options['number_indexed']) ? $this->options['number_indexed'] : '0',
      '#size' => 5,
      '#description' => t('The number of files to index per file field. The order of indexation is the weight in the widget. 0 for no restriction.'),
    );
    $form['max_file_size'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum file size'),
      '#default_value' => isset($this->options['max_file_size']) ? $this->options['max_file_size'] : '0',
      '#description' => t('Enter a value like "512" (bytes), "80 KB" (kilobytes) or "50 MB" (megabytes) in order to restrict the max file size of files that should be indexed.'),
      '#size' => 80,
      '#maxlength' => 255,
      '#element_validate' => array('_file_generic_settings_max_filesize'),
    );
    $form['excluded_private'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude private files'),
      '#default_value' => isset($this->options['excluded_private']) ? $this->options['excluded_private'] : TRUE,
      '#description' => t('Check this box if you want to exclude private files to be indexed.'),
    );
    // Add setting specific for the file entity.
    if (module_exists('file_entity')) {
      // Build the select options.
      $bundle_options = array();
      foreach (field_info_bundles('file') as $bundle => $info) {
        $bundle_options[$bundle] = $info['label'];
      }
      if ($bundle_options) {
        $form['excluded_file_entity_bundles'] = array(
          '#type' => 'select',
          '#title' => t('Exclude file entity bundles'),
          '#options' => $bundle_options,
          '#multiple' => TRUE,
          '#default_value' => isset($this->options['excluded_file_entity_bundles']) ? $this->options['excluded_file_entity_bundles'] : array(),
          '#description' => t('File entity bundles that are excluded from indexing.'),
        );
      }
    }
    return $form;
  }

  /**
   * Adds attachments property.
   *
   * @return array
   *   containing the property.
   */
  public function propertyInfo() {
    $ret = array();
    if ($this->index->getEntityType() == 'file' || $this->isMultipleIndexWithFile()) {
      $ret['attachments_content'] = array(
        'label' => 'File content',
        'description' => 'File content',
        'type' => 'text',
      );
    }
    if ($this->index->getEntityType() != 'file') {
      $fields = $this->getFileFields();
      foreach ($fields as $name => $field) {
        $ret['attachments_' . $name] = array(
          'label' => 'Attachment content: ' . $name,
          'description' => $name,
          'type' => 'text',
        );
      }
    }
    return $ret;
  }

  protected function isMultipleIndexWithFile() {
    return $this->index->item_type == 'multiple' && isset($this->index->options['datasource']['types']) && in_array('file', $this->index->options['datasource']['types']);
  }

  /**
   * Helper method to get all file fields.
   *
   * @return array
   *   contaigning all the file fields names.
   */
  protected function getFileFields() {
    $ret = array();
    foreach (field_info_fields() as $name => $field) {
      if ($field['type'] == 'file' && array_key_exists($this->index->getEntityType(), $field['bundles'])) {
        $ret[$name] = $field;
      }
    }
    return $ret;
  }

  /**
   * Retrieve list of fields, that should be indexed.
   *
   * @return array
   *   Array of fields, ready to be indexed.
   */
  protected function getIndexableFileFields() {
    $all_fields = $this->getFileFields();
    $index_fields = $this->index->getFields();

    $indexable = array();

    foreach ($all_fields as $name => $field) {
      // If field is not in the index, then it was not selected by the user,
      // so we don't have to perform extraction of unnecessary files.
      if (isset($index_fields["attachments_$name"])) {
        $indexable[$name] = $field;
      }
    }

    return $indexable;
  }

  /**
   * Extracts th file content.
   *
   * @param object $file
   *   The file object.
   *
   * @return string
   *   The extracted content.
   */
  protected function getFileContent($file) {
    $extraction = FALSE;
    // Let's make the variable consistent.
    $file = (array) $file;

    // Before running the (performance-intensive) extraction process, check
    // if we already have a cached copy of the extracted data.
    if (isset($file['fid'])) {
      // Load cached extraction based off file ID.
      $cid = 'cached_extraction_:' . $file['fid'];
      $cached_extraction = cache_get($cid, self::CACHE_TABLE);

      // If we have a cache hit, there really is no need to continue.
      if (!empty($cached_extraction->data)) {
        return $cached_extraction->data;
      }
    }

    if (file_exists($file['uri'])) {
      if (in_array($file['filemime'], $this->textMimetypes())) {
        $extraction = $this->extractSimple($file);
      }
      elseif (in_array($file['filemime'], $this->imageMimetypes())) {
        $extraction = $this->extractExif($file);
      }
      else {
        $extraction_method = variable_get('search_api_attachments_extract_using', 'tika');
        // Send the extraction request to the right place depending on the
        // current setting.
        if ($extraction_method == 'tika') {
          $extraction = $this->extractTika($file);
        }
        elseif ($extraction_method == 'tika_server') {
          $extraction = $this->extractTikaServer($file);
        }
        elseif ($extraction_method == 'python_pdf2txt') {
          if (in_array($file['filemime'], $this->pdfMimetypes())) {
            $extraction = $this->extractPythonPdf2txt($file);
          }
          elseif (variable_get('search_api_attachments_debug', FALSE)) {
            watchdog('search_api_attachments', 'The python_pdf2txt extraction method does not support %mime_type', array('%mime_type' => $file['filemime']), WATCHDOG_WARNING);
          }
        }
        elseif ($extraction_method == 'pdftotext') {
          if (in_array($file['filemime'], $this->pdfMimetypes())) {
            $extraction = $this->extractPdftotext($file);
          }
          elseif (variable_get('search_api_attachments_debug', FALSE)) {
            watchdog('search_api_attachments', 'The pdftotext extraction method does not support %mime_type', array('%mime_type' => $file['filemime']), WATCHDOG_WARNING);
          }
        }
        else {
          $extraction = $this->extractSolr($file);
        }
      }
    }
    else {
      // Log the missing file information.
      watchdog('search_api_attachments', "Couldn't index %filename content because this file was missing.", array('%filename' => $file['filename']));
    }

    // If we have actual extracted data, write it to the cache.
    if ($extraction !== FALSE && isset($cid)) {
      cache_set($cid, $extraction, self::CACHE_TABLE);
    }
    if (variable_get('search_api_attachments_debug', FALSE)) {
      watchdog('search_api_attachments', "File: @filename\nExtraction: @extraction", array('@filename' => $file['uri'], '@extraction' => $extraction), WATCHDOG_DEBUG);
    }
    return $extraction;
  }

  /**
   * Extracts file content for text files.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The text.
   */
  protected function extractSimple($file) {
    $text = file_get_contents($this->getRealpath($file));
    $text = iconv("UTF-8", "UTF-8//IGNORE", $text);
    $text = filter_xss(str_replace(array('<', '>'), array(' <', '> '), $text), array());
    $text = htmlspecialchars(html_entity_decode($text, ENT_NOQUOTES, 'UTF-8'), ENT_NOQUOTES, 'UTF-8');
    $text = trim($text);
    return $text;
  }

  /**
   * Extracts images metadata.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The metadata.
   */
  protected function extractExif($file) {
    $ret = '';
    $url = file_create_url($file['uri']);
    $info = array();
    getimagesize($url, $info);
    if (isset($info['APP13'])) {
      $iptc = iptcparse($info['APP13']);
      if (is_array($iptc)) {
        foreach ($iptc as $value) {
          foreach ($value as $innervalue) {
            $ret .= $innervalue . ' ';
          }
        }
      }
    }
    return $ret;
  }

  /**
   * Extracts file content using local tika executable.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The file content.
   *
   * @throws Exception
   */
  protected function extractTika($file) {
    $filepath = $this->getRealpath($file);
    $tika_path = realpath(variable_get('search_api_attachments_tika_path', ''));
    $tika = realpath($tika_path . '/' . variable_get('search_api_attachments_tika_jar', 'tika-app-1.6.jar'));
    if (!($tika) || !is_file($tika)) {
      throw new Exception(t('Invalid path or filename for tika application jar.'));
    }
    // UTF-8 multibyte characters will be stripped by escapeshellargs() for the
    // default C-locale.
    // So temporarily set the locale to UTF-8 so that the filepath
    // remains valid.
    $backup_locale = setlocale(LC_CTYPE, '0');
    setlocale(LC_CTYPE, 'en_US.UTF-8');
    $param = '';
    if ($file['filemime'] != 'audio/mpeg') {
      $param = ' -Dfile.encoding=UTF8 -cp ' . escapeshellarg($tika_path);
    }

    // Force running the Tika jar headless.
    $param = ' -Djava.awt.headless=true ' . $param;

    $cmd = variable_get('search_api_attachments_java', 'java') . $param . ' -jar ' . escapeshellarg($tika) . ' -t ' . escapeshellarg($filepath);
    if (strpos(ini_get('extension_dir'), 'MAMP/')) {
      $cmd = 'export DYLD_LIBRARY_PATH=""; ' . $cmd;
    }
    // Restore the locale.
    setlocale(LC_CTYPE, $backup_locale);
    // Support UTF-8 commands:
    // http://www.php.net/manual/en/function.shell-exec.php#85095
    shell_exec("LANG=en_US.utf-8");
    return shell_exec($cmd);
  }

  /**
   * Extracts file content using a tika server.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The file content.
   */
  protected function extractTikaServer($file) {
    $filepath = $this->getRealpath($file);

    $url = 'http://' . variable_get('search_api_attachments_tika_server_host', '') . ':' . variable_get('search_api_attachments_tika_server_port', 9998) . '/tika';

    // Server tika.
    $ch = curl_init($url);
    // Request will be a PUT.
    curl_setopt($ch, CURLOPT_PUT, 1);
    // Set the file to send.
    $file_path_str = $filepath;
    $fh_res = fopen($file_path_str, 'r');
    curl_setopt($ch, CURLOPT_INFILE, $fh_res);
    curl_setopt($ch, CURLOPT_INFILESIZE, filesize($file_path_str));
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    // Send the request.
    $curl_response_res = curl_exec($ch);
    fclose($fh_res);

    return $curl_response_res;
  }

  /**
   * Extracts pdf file content using pdftotext.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The file content.
   */
  protected function extractPdftotext($file) {
    $filepath = $this->getRealpath($file);
    // UTF-8 multibyte characters will be stripped by escapeshellargs() for the
    // default C-locale.
    // So temporarily set the locale to UTF-8 so that the filepath remains
    // valid.
    $backup_locale = setlocale(LC_CTYPE, '0');
    setlocale(LC_CTYPE, 'en_US.UTF-8');
    // Pdftotext descriptions states that '-' as text-file will send text to
    // stdout.
    $cmd = escapeshellcmd('pdftotext') . ' ' . escapeshellarg($filepath) . ' -';
    // Restore the locale.
    setlocale(LC_CTYPE, $backup_locale);
    // Support UTF-8 commands :
    // http://www.php.net/manual/en/function.shell-exec.php#85095
    shell_exec("LANG=en_US.utf-8");
    return shell_exec($cmd);
  }

  /**
   * Extracts pdf file content using python pdf2txt script.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The file content.
   */
  protected function extractPythonPdf2txt($file) {
    $filepath = $this->getRealpath($file);
    // Restore the locale.
    $pdf2txt_path = realpath(variable_get('search_api_attachments_python_pdf2txt_path', '/usr/bin'));
    $pdf2txt = realpath($pdf2txt_path . '/' . variable_get('search_api_attachments_python_pdf2txt_script', 'pdf2txt'));
    $cmd = escapeshellcmd('python') . ' ' . escapeshellarg($pdf2txt) . ' -C -t text ' . escapeshellarg($filepath);
    // UTF-8 multibyte characters will be stripped by escapeshellargs() for the
    // default C-locale.
    // So temporarily set the locale to UTF-8 so that the filepath remains
    // valid.
    $backup_locale = setlocale(LC_CTYPE, '0');
    setlocale(LC_CTYPE, $backup_locale);
    // Support UTF-8 commands:
    // http://www.php.net/manual/en/function.shell-exec.php#85095
    shell_exec("LANG=en_US.utf-8");
    return shell_exec($cmd);
  }

  /**
   * Extract data using Solr.
   *
   * This is done via the ExtractingRequestHandler or using the
   * remote Tika servlet.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The file content.
   *
   * @throws SearchApiException
   *
   * @see http://wiki.apache.org/solr/ExtractingRequestHandler
   * @see http://wiki.apache.org/tika/TikaJAXRS
   */
  protected function extractSolr($file) {
    $extraction = FALSE;

    $filepath = $this->getRealpath($file);
    try {
      $filename = basename($filepath);

      // Server name is stored in the index.
      $server_name = $this->index->server;

      $server = search_api_server_load($server_name, TRUE);

      // Make sure this is a solr server.
      $class_info = search_api_get_service_info($server->class);
      $classes = class_parents($class_info['class']);
      $classes[$class_info['class']] = $class_info['class'];
      if (!in_array('SearchApiSolrService', $classes)) {
        throw new SearchApiException(t('Server %server is not a Solr server, unable to extract file.', array(
          '%server' => $server_name,
        )));
      }

      // Open a connection to the server.
      $solr_connection = $server->getSolrConnection();

      // Path for our servlet request.
      $servlet_path = variable_get('search_api_attachments_extracting_servlet_path', 'update/extract');

      // Parameters for the extraction request.
      $params = array(
        'extractOnly' => 'true',
        'resource.name' => $filename,
        // Matches the -t command for the tika CLI app.
        'extractFormat' => 'text',
        'wt' => 'json',
        'hl' => 'on',
      );

      // Heavily inspired by apachesolr_file.
      // @see apachesolr_file_extract().
      // Construct a multi-part form-data POST body in $data.
      $boundary = '--' . md5(uniqid(REQUEST_TIME));
      $data = "--{$boundary}\r\n";
      // The 'filename' used here becomes the property name in the response.
      $data .= 'Content-Disposition: form-data; name="file"; filename="extracted"';
      $data .= "\r\nContent-Type: application/octet-stream\r\n\r\n";
      $data .= file_get_contents($filepath);
      $data .= "\r\n--{$boundary}--\r\n";
      $headers = array('Content-Type' => 'multipart/form-data; boundary=' . $boundary);
      $options = array(
        'method' => 'POST',
        'headers' => $headers,
        'data' => $data,
      );

      // Make a servlet request using the solr connection.
      $response = $solr_connection->makeServletRequest($servlet_path, $params, $options);

      // If we have an extracted response, all is well.
      if (isset($response->extracted)) {
        $extraction = $response->extracted;
      }
    }
    catch (Exception $e) {
      // Log the exception to watchdog. Exceptions from Solr may be transient,
      // or indicate a problem with a specific file.
      watchdog('search_api_attachments', 'Exception occurred sending %filepath to Solr.', array(
        '%filepath' => $file['uri'],
      ));
      watchdog_exception('search_api_attachments', $e);
    }

    return $extraction;
  }

  /**
   * Check if the file is private.
   *
   * @param array $file
   *   A file array.
   *
   * @return bool
   *   TRUE if the file is private. FALSE otherwise.
   */
  protected function isPrivate(array $file) {
    $result = FALSE;
    $wrapper = 'private://';
    $uri = $file['uri'];
    if (substr($uri, 0, 10) == $wrapper) {
      $result = TRUE;
    }
    return $result;
  }

  /**
   * Check if the file is temporary.
   *
   * @param array $file
   *   A file array.
   *
   * @return bool
   *   TRUE if the file is temporary. FALSE otherwise.
   */
  protected function isTemporary(array $file) {
    $result = FALSE;
    $wrapper = 'temporary://';
    $uri = $file['uri'];
    if (substr($uri, 0, 12) == $wrapper) {
      $result = TRUE;
    }
    return $result;
  }

  /**
   * Helper method to get a file's real path.
   *
   * @param object $file
   *   The file.
   *
   * @return string
   *   The real path.
   */
  protected function getRealpath($file) {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file['uri']);
    $scheme = file_uri_scheme($file['uri']);
    $local_wrappers = file_get_stream_wrappers(STREAM_WRAPPERS_LOCAL);
    if (in_array($scheme, array_keys($local_wrappers))) {
      return $wrapper->realpath();
    }
    elseif (is_object($wrapper)) {
      return $wrapper->getExternalUrl();
    }
  }

  /**
   * Helper function to store pdf's mimetypes.
   *
   * @return array
   *   Supported mime types.
   */
  protected function pdfMimetypes() {
    return array(
      'application/pdf',
      'application/x-pdf',
      'application/acrobat',
      'text/x-pdf',
      'text/pdf',
      'applications/vnd.pdf',
    );
  }

  /**
   * Helper function to store image's mimetypes.
   *
   * @return array
   *   Supported mime types.
   */
  protected function imageMimetypes() {
    return array(
      'image/jpeg',
      'image/jpg',
      'image/tiff',
    );
  }

  /**
   * Helper function to store text's mimetypes.
   *
   * @return array
   *   Supported mime types.
   */
  protected function textMimetypes() {
    return array(
      'text/plain',
      'text/x-diff',
    );
  }

}
