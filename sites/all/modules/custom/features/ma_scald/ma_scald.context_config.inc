<?php
/**
 * @file
 * ma_scald.context_config.inc
 */

/**
 * Implements hook_default_scald_context_config().
 */
function ma_scald_default_scald_context_config() {
  $export = array();

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'file_representation';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'passthrough',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['file_representation'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'full';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'style-digital_heritage_full_content',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['full'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'ma_colorbox';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'passthrough',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '100%',
    'height' => '100%',
  );
  $export['ma_colorbox'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'ma_scald_search_results';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'style-medium',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '220px',
    'height' => '220px',
  );
  $export['ma_scald_search_results'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'mukurtu_scald_banner_image';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'passthrough',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['mukurtu_scald_banner_image'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'mukurtu_scald_media_assets_edit_';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'passthrough',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '750',
    'height' => '560',
  );
  $export['mukurtu_scald_media_assets_edit_'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'mukurtu_scald_related_items';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'style-related_items_teaser',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '280px',
    'height' => '280px',
  );
  $export['mukurtu_scald_related_items'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'mukurtu_scald_thumbnail_image';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'style-medium',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['mukurtu_scald_thumbnail_image'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'sdl_editor_representation';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'style-digital_heritage_full_content',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '750',
    'height' => '560',
  );
  $export['sdl_editor_representation'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'sdl_library_item';
  $context_config->transcoder = array(
    'image' => array(
      '*' => 'style-Library',
    ),
    'audio' => array(
      '*' => 'passthrough',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['sdl_library_item'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'sdl_preview';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'style-thumbnail',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['sdl_preview'] = $context_config;

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'title';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'passthrough',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'image' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'video' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
      'settings' => array(),
    ),
  );
  $context_config->data = array(
    'width' => '',
    'height' => '',
  );
  $export['title'] = $context_config;

  return $export;
}
