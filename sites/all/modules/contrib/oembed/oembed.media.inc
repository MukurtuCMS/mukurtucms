<?php

/**
 *  Implements hook_media_parse().
 *
 *  @todo: this might be deprecated now that we have media_internet,
 *  but the hook is still being called in a couple places in media.
 */
function oembed_media_parse($url, $options = array()) {
  $scheme = 'oembed://';
  $matches = array();
  if ($provider = oembed_get_provider($url, $matches)) {
    return file_stream_wrapper_uri_normalize($scheme . drupal_encode_path($url));
  }
  // @TODO: Validate for malformed oembed urls.
}

/**
 * Implements hook_media_internet_providers();
 */
function oembed_media_internet_providers() {
  $info['MediaInternetOEmbedHandler'] = array(
    'title' => t('oEmbed'),
  );

  return $info;
}
