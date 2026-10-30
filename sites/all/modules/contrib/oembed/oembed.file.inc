<?php

/**
 * Implements hook_file_formatter_info().
 */
function oembed_file_formatter_info() {
  $formatters = array();
  $formatters['oembed'] = array(
    'label' => t('oEmbed'),
    'file types' => array('audio, document, image, video'),
    'default settings' => array('width' => '560', 'height' => '340', 'wmode' => ''),
    'view callback' => 'oembed_file_formatter_view',
    'settings callback' => 'oembed_file_formatter_oembed_settings',
    'description' => t('All-purpose oEmbed formatter.'),
    'mime types' => array('audio/oembed', 'image/oembed', 'text/oembed', 'video/oembed'),
  );
  $formatters['oembed_thumbnail'] = array(
    'label' => t('oEmbed thumbnail'),
    'file types' => array('audio, document, image, video'),
    'default settings' => array('width' => '180', 'height' => ''),
    'view callback' => 'oembed_file_formatter_view',
    'settings callback' => 'oembed_file_formatter_oembed_thumbnail_settings',
    'description' => t('oEmbed thumbnail media.'),
    'mime types' => array('audio/oembed', 'image/oembed', 'text/oembed', 'video/oembed'),
  );
  return $formatters;
}

/**
 * Implements hook_file_formatter_info_alter().
 */
function oembed_file_formatter_info_alter(&$info) {
  if (isset($info['file_image'])) {
    $info['oembed_image'] = array(
      'label' => t('oEmbed image'),
      'view callback' => 'oembed_remote_file_formatter_view',
      'description' => t('oEmbed photo or thumbnail is saved to local filesystem and transformed by image styles.'),
      'hidden' => FALSE,
      'mime types' => array('audio/oembed', 'image/oembed', 'text/oembed', 'video/oembed'),
    ) + $info['file_image'];
  }
}

/**
 * Implements hook_file_mimetype_mapping_alter().
 */
function oembed_file_mimetype_mapping_alter(&$mapping) {
  $mapping['mimetypes'][] = 'video/oembed';
  $mapping['mimetypes'][] = 'image/oembed';
  $mapping['mimetypes'][] = 'text/oembed';
  $mapping['mimetypes'][] = 'audio/oembed';
}

/**
 * Implements hook_file_operations().
 */
function oembed_file_operation_info() {
  $operations = array(
    'refresh' => array(
      'label' => t('Refresh from source'),
      'callback' => 'oembed_cache_clear',
    ),
  );
  return $operations;
}

/**
 * Implements hook_file_presave().
 */
function oembed_file_presave($file) {
  // For new oEmbed files, set the filename to the oEmbed response's title or calculated
  // alt attribute.
  if (empty($file->fid) && isset($file->metadata['oembed'])) {
    $embed = $file->metadata['oembed'];
    $file->filename = truncate_utf8(empty($embed['title']) ? oembed_alt_attr($embed) : $embed['title'], 255);
  }

  // Fetch image dimensions.
  oembed_metadata_fetch_image_dimensions($file);
}

/**
 * Implements hook_file_load().
 */
function oembed_file_load($files) {
  foreach ($files as $file) {
    $scheme = file_uri_scheme($file->uri);
    if ($scheme == 'oembed' && !isset($file->metadata['oembed'])) {

      // Load plain oEmbed response onto file entity.
      /** @var \DrupalStreamWrapperInterface $wrapper */
      $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
      $file->metadata['oembed'] = oembed_get_data($wrapper->getExternalUrl());

      // Retrieve any missing images dimensions.
      oembed_metadata_fetch_image_dimensions($file);

      foreach (array('oembed', 'width', 'height') as $name) {
        if (!empty($file->metadata[$name])) {
          $value = $file->metadata[$name];
          db_merge('file_metadata')
            ->fields(array(
              'value' => serialize($value),
            ))
            ->key(array(
              'fid' => $file->fid,
              'name' => $name,
            ))
            ->execute();
        }
      }
    }
  }
}

/**
 * Fetch the dimensions of an image and store them in the file metadata array.
 */
function oembed_metadata_fetch_image_dimensions($file) {

  $scheme = file_uri_scheme($file->uri);
  if ($scheme != 'oembed') {
    return;
  }

  // Do not bother proceeding if this file does not have an image mime type.
  if (file_entity_file_get_mimetype_type($file) != 'image') {
    return;
  }

  // We have a non-empty image file.
  $embed = $file->metadata['oembed'];
  if ($embed && $embed['type'] == 'photo' && !empty($embed['width']) && !empty($embed['height'])) {
    $file->metadata['width'] = $embed['width'];
    $file->metadata['height'] = $embed['height'];
  }
  else {
    // Fallback to NULL values.
    $file->metadata['width'] = NULL;
    $file->metadata['height'] = NULL;
  }
}

/**
 * Implements hook_file_metadata_info().
 */
function oembed_file_metadata_info() {
  $info = array();
  $info['oembed'] = array('label' => t('oEmbed'), 'type' => 'array');
  return $info;
}
