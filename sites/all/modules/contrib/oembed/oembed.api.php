<?php

/**
 * @file
 * Hooks provided by the oEmbed module.
 */

/**
 * Alters an oEmbed request parameters and provider.
 *
 * @param array $parameters
 *   oEmbed request parameters.
 * @param object $provider
 *   oEmbed provider info.
 * @param string $url
 *   The original URL or embed code to parse.
 */
function hook_oembed_request_alter(&$parameters, &$provider, $url) {
  if ($provider['name'] == 'default:youtube') {
    $parameters['iframe'] = '1';
  }
}

/**
 * Alters an oEmbed response.
 *
 * @param array $response
 *   oEmbed response data.
 */
function hook_oembed_response_alter(&$response) {
}

/**
 * Modify the provider's set of supported oEmbed response formats.
 *
 * @param array $formats
 *   Format handlers keyed by format name.
 */
function hook_oembedprovider_formats_alter(&$formats) {
  $formats['jsonp'] = array(
    'mime' => 'text/javascript',
    'callback' => '_oembedprovider_formats_jsonp',
  );
}

/**
 * oEmbed filter replacement callback.
 *
 * Override basic function by setting Drupal system variable
 * `oembed_resolve_link_callback` to a new function name with this signature.
 *
 * @param string $url
 *   URL to embed.
 * @param array $options
 *   oEmbed request options.
 *
 * @return string
 *   Rendered oEmbed response.
 */
function hook_oembed_resolve_link($url, $options = array()) {

  // If file_entity module is enabled, treat the URL as an uploaded file.
  // Inline is used to defer the rendering of the embedded content until the
  // entity is actually viewed. This technique allows content to be cached by
  // Drupal's filter system.
  $view_mode = 'full';
  if (isset($options['view_mode'])) {
    $view_mode = $options['view_mode'];
    unset($options['view_mode']);
  }

  $url = decode_entities($url);

  $return = '';

  $file = oembed_url_to_file($url);
  $file->override = $options;
  if (isset($file->fid)) {
    $macro_params = array();
    $macro_params[] = 'entity';
    $macro_params[] = 'type=file';
    $macro_params[] = 'id=' . $file->fid;
    $macro_params[] = 'view_mode=' . $view_mode;
    $return = '[' . implode('|', $macro_params) . ']';
  }

  if (empty($return)) {
    $return = $url;
  }

  return $return;
}
