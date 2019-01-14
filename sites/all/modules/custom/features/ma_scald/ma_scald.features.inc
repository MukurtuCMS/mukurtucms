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
          'width' => 240,
          'height' => 146,
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
