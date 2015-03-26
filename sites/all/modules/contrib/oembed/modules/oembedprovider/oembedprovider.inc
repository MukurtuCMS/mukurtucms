<?php

/**
 * @file
 * Functions for the oEmbed provider
 */

define('OEMBEDPROVIDER_NOT_ACCEPTABLE', 406);

/**
 * Callback handler for oembed requests.
 */
function _oembedprovider_handle_request() {

  // Check that we got a url
  if (!filter_has_var(INPUT_GET, 'url')) {
    return OEMBEDPROVIDER_NOT_ACCEPTABLE;
  }

  $url = filter_input(INPUT_GET, 'url', FILTER_VALIDATE_URL, array('flags' => FILTER_FLAG_PATH_REQUIRED));

  if (empty($url)) {
    return OEMBEDPROVIDER_NOT_ACCEPTABLE;
  }

  $parameters = array();
  $input_vars = array(
    'maxwidth' => FILTER_VALIDATE_INT,
    'maxheight' => FILTER_VALIDATE_INT,
    'view_mode' => FILTER_SANITIZE_STRING,
    'langcode' => FILTER_SANITIZE_STRING,
  );
  foreach ($input_vars as $key => $filter) {
    if (filter_has_var(INPUT_GET, $key)) {
      $parameters[$key] = filter_input(INPUT_GET, $key, $filter);
    }
  }

  if ($plugin = oembed_get_provider($url, $matches, 'provider')) {
    $data = oembed_oembed_fetch($plugin, $url, $matches, $parameters);
  }

  if ($data) {

    // Providers might include private attributes intended only for internal requests.
    foreach (array_keys($data) as $key) {
      if ($key[0] === '#') {
        unset($data[$key]);
      }
    }

    return _oembedprovider_result($data['type'], $data);
  }

  return MENU_NOT_FOUND;
}

/**
 * oEmbed response delivery callback.
 */
function oembedprovider_deliver_response($page_callback_result) {
  // Menu status constants are integers; page content is a string or array.
  if (is_int($page_callback_result)) {

    switch ($page_callback_result) {
      case OEMBEDPROVIDER_NOT_ACCEPTABLE:
        drupal_add_http_header('Status', '406 Not acceptable. The url parameter is required.');
        $page_callback_result = _oembedprovider_result('link', array(
          'title' => t('The URL parameter is required'),
          'error' => 1,
        ));
        break;

      case MENU_NOT_FOUND:
        drupal_add_http_header('Status', '404 Not found.');
        $page_callback_result = _oembedprovider_result('rich', array(
          'title' => t('Could not find a provider that supports this URL.'),
          'error' => 1,
        ));
        break;
    }
  }

  $format = 'json';
  if (filter_has_var(INPUT_GET, 'format')) {
    $format = filter_input(INPUT_GET, 'format', FILTER_SANITIZE_STRING);
  }
  else if (arg(2)) {
    $format = arg(2);
  }

  $formats = oembedprovider_formats();
  if (!isset($formats[$format])) {
    drupal_add_http_header('Status', '501 Not implemented. Unsupported response format "'. check_plain($format) . '"');
    die;
  }

  drupal_add_http_header('Content-Type', $formats[$format]['mime']);

  print $formats[$format]['callback']($page_callback_result);
}

/**
 * Returns all the registered response formats
 *
 * @return array
 */
function oembedprovider_formats($reset = FALSE) {
  $formats = &drupal_static(__FUNCTION__, array());

  if (!$formats) {
    $cache_key = 'oembedprovider:formats';

    if (!$reset && ($cache = cache_get($cache_key)) && isset($cache->data)) {
      $formats = $cache->data;
    }
    else {
      $formats = array(
        'json' => array(
          'mime' => 'application/json',
          'callback' => 'drupal_json_encode',
        ),
        'jsonp' => array(
          'mime' => 'text/javascript',
          'callback' => '_oembedprovider_formats_jsonp',
        ),
        'xml' => array(
          'mime' => 'text/xml',
          'callback' => '_oembedprovider_formats_xml',
        ),
      );
      drupal_alter('oembedprovider_formats', $formats);

      cache_set($cache_key, $formats);
    }
  }

  return $formats;
}

/**
 * JSONP formatter
 */
function _oembedprovider_formats_jsonp($page_callback_result) {
  $callback = filter_has_var(INPUT_GET, 'callback') ? filter_input(INPUT_GET, 'callback') : 'callback';
  return sprintf('%s(%s)', $callback, drupal_json_encode($page_callback_result));
}

/**
 * XML formatter
 */
function _oembedprovider_formats_xml($page_callback_result) {
  $output = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
  $output .= "<oembed>\n";
  $output .= format_xml_elements($page_callback_result);
  $output .= "</oembed>";
  return $output;
}
