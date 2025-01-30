<?php
/**
 * @file
 * ma_media.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_media_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'exif_empty_values';
  $strongarm->value = 1;
  $export['exif_empty_values'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'exif_mediatypes';
  $strongarm->value = array(
    'audio' => 'audio',
    'image' => 'image',
    'video' => 'video',
    'document' => 0,
  );
  $export['exif_mediatypes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'exif_nodetypes';
  $strongarm->value = array(
    'digital_heritage' => 'digital_heritage',
    'collection' => 0,
    'community' => 0,
    'article' => 0,
    'page' => 0,
    'cultural_protocol_group' => 0,
    'panel' => 0,
  );
  $export['exif_nodetypes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'exif_update';
  $strongarm->value = 1;
  $export['exif_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'exif_vocabulary';
  $strongarm->value = '2';
  $export['exif_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_link_settings';
  $strongarm->value = array(
    'audio' => array(
      'media_preview' => '2',
      'media_small' => '1',
      'default' => '0',
      'media_large' => '0',
      'media_original' => '0',
      'full_content' => '2',
      'component_media_item' => '2',
      'collab_doc_attachments' => 0,
    ),
    'video' => array(
      'media_preview' => '0',
      'media_small' => '1',
      'media_original' => '0',
      'media_large' => '0',
      'default' => '0',
      'media_link' => '0',
      'full_content' => '2',
      'component_media_item' => '2',
      'collab_doc_attachments' => 0,
    ),
    'image' => array(
      'media_small' => '1',
      'media_preview' => '2',
      'media_original' => '0',
      'default' => '0',
      'media_link' => '0',
      'media_large' => '0',
      'full_content' => '2',
      'component_media_item' => '2',
      'collab_doc_attachments' => 0,
    ),
    'default' => array(
      'media_preview' => '2',
      'media_small' => '1',
      'default' => '0',
      'media_link' => '0',
      'media_large' => '0',
      'full_content' => '2',
      'component_media_item' => '2',
    ),
    'text' => array(
      'component_media_item' => '2',
      'default' => '0',
      'media_small' => '1',
      'full_content' => '2',
    ),
    'application' => array(
      'component_media_item' => '2',
      'media_small' => '1',
      'full_content' => '2',
      'default' => '1',
      'media_preview' => '0',
      'media_large' => '2',
      'media_original' => '0',
    ),
    'document' => array(
      'collab_doc_attachments' => 0,
    ),
  );
  $export['file_entity_link_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mediaelement_sitewide';
  $strongarm->value = 1;
  $export['mediaelement_sitewide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_grid_window_height';
  $strongarm->value = 400;
  $export['media_grid_window_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_media_per_page';
  $strongarm->value = 30;
  $export['media_media_per_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_page_items_per_page';
  $strongarm->value = 10;
  $export['media_page_items_per_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_root_folder';
  $strongarm->value = 'media';
  $export['media_root_folder'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media__file_extensions';
  $strongarm->value = 'jpg jpeg gif png tif tiff txt doc xls pdf ppt pps odt ods odp mp3 mov m4v mp4 mpeg avi ogg wmv webm ico wav swf';
  $export['media__file_extensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media__icon_base_directory';
  $strongarm->value = 'sites/all/modules/custom/mukurtu_custom/custom_media_icon_sets';
  $export['media__icon_base_directory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media__max_filesize';
  $strongarm->value = '100 MB';
  $export['media__max_filesize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_api_key';
  $strongarm->value = '7034e370471e11e1b4764040d3dc5c07';
  $export['oembedembedly_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_default';
  $strongarm->value = '1';
  $export['oembedembedly_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_media_folders_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_media_folders_pattern'] = $strongarm;

  return $export;
}
