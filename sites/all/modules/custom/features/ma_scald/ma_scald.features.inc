<?php

/**
 * @file
 * ma_scald.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_scald_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "scald" && $api == "context_config") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_scald_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_styles_alter().
 */
function ma_scald_image_styles_alter(&$data) {
  if (isset($data['large'])) {

  if (!isset($data['large']['storage']) || $data['large']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['large']['effects'] = array_values($data['large']['effects']);
    $data['large']['effects'][0]['name'] = 'imagecache_autorotate';
  }

  if (!isset($data['large']['storage']) || $data['large']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['large']['effects'] = array_values($data['large']['effects']);
    $data['large']['effects'][0]['weight'] = -2;
  }

  if (!isset($data['large']['storage']) || $data['large']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['large']['effects'] = array_values($data['large']['effects']);
    $data['large']['effects'][1] = array(
      'data' => array(),
      'name' => 'imagecache_autorotate',
      'weight' => -1,
    );
  }

  if (!isset($data['large']['storage']) || $data['large']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['large']['effects'] = array_values($data['large']['effects']);
    $data['large']['effects'][2] = array(
      'data' => array(
        'height' => 480,
        'upscale' => 0,
        'width' => 480,
      ),
      'name' => 'image_scale',
      'weight' => 0,
    );
  }

  if (!isset($data['large']['storage']) || $data['large']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['large']['effects'][0]['data']['height']);
  }

  if (!isset($data['large']['storage']) || $data['large']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['large']['effects'][0]['data']['upscale']);
  }

  if (!isset($data['large']['storage']) || $data['large']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['large']['effects'][0]['data']['width']);
  }
  }
  if (isset($data['medium'])) {

  if (!isset($data['medium']['storage']) || $data['medium']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['medium']['effects'] = array_values($data['medium']['effects']);
    $data['medium']['effects'][0]['name'] = 'imagecache_autorotate';
  }

  if (!isset($data['medium']['storage']) || $data['medium']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['medium']['effects'] = array_values($data['medium']['effects']);
    $data['medium']['effects'][0]['weight'] = -2;
  }

  if (!isset($data['medium']['storage']) || $data['medium']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['medium']['effects'] = array_values($data['medium']['effects']);
    $data['medium']['effects'][1] = array(
      'data' => array(
        'height' => 220,
        'upscale' => 1,
        'width' => 220,
      ),
      'name' => 'image_scale',
      'weight' => 0,
    );
  }

  if (!isset($data['medium']['storage']) || $data['medium']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['medium']['effects'] = array_values($data['medium']['effects']);
    $data['medium']['effects'][2] = array(
      'data' => array(),
      'name' => 'imagecache_autorotate',
      'weight' => -1,
    );
  }

  if (!isset($data['medium']['storage']) || $data['medium']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['medium']['effects'][0]['data']['height']);
  }

  if (!isset($data['medium']['storage']) || $data['medium']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['medium']['effects'][0]['data']['upscale']);
  }

  if (!isset($data['medium']['storage']) || $data['medium']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['medium']['effects'][0]['data']['width']);
  }
  }
  if (isset($data['thumbnail'])) {

  if (!isset($data['thumbnail']['storage']) || $data['thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['thumbnail']['effects'] = array_values($data['thumbnail']['effects']);
    $data['thumbnail']['effects'][0]['name'] = 'imagecache_autorotate';
  }

  if (!isset($data['thumbnail']['storage']) || $data['thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['thumbnail']['effects'] = array_values($data['thumbnail']['effects']);
    $data['thumbnail']['effects'][0]['weight'] = -2;
  }

  if (!isset($data['thumbnail']['storage']) || $data['thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['thumbnail']['effects'] = array_values($data['thumbnail']['effects']);
    $data['thumbnail']['effects'][1] = array(
      'data' => array(
        'height' => 100,
        'upscale' => 1,
        'width' => 100,
      ),
      'name' => 'image_scale',
      'weight' => 0,
    );
  }

  if (!isset($data['thumbnail']['storage']) || $data['thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['thumbnail']['effects'] = array_values($data['thumbnail']['effects']);
    $data['thumbnail']['effects'][2] = array(
      'data' => array(),
      'name' => 'imagecache_autorotate',
      'weight' => -1,
    );
  }

  if (!isset($data['thumbnail']['storage']) || $data['thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['thumbnail']['effects'][0]['data']['height']);
  }

  if (!isset($data['thumbnail']['storage']) || $data['thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['thumbnail']['effects'][0]['data']['upscale']);
  }

  if (!isset($data['thumbnail']['storage']) || $data['thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['thumbnail']['effects'][0]['data']['width']);
  }
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ma_scald_image_default_styles() {
  $styles = array();

  // Exported image style: taxonomy_thumbnail_image.
  $styles['taxonomy_thumbnail_image'] = array(
    'label' => 'Taxonomy Thumbnail Image',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 292,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tiny_thumbnail.
  $styles['tiny_thumbnail'] = array(
    'label' => 'Tiny Thumbnail',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 35,
          'height' => 35,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
