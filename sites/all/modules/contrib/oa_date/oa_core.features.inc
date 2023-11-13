<?php
/**
 * @file
 * oa_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function oa_core_image_default_styles() {
  $styles = array();

  // Exported image style: oa_medium_thumbnail.
  $styles['oa_medium_thumbnail'] = array(
    'label' => 'oa_medium_thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: oa_small_thumbnail.
  $styles['oa_small_thumbnail'] = array(
    'label' => 'oa_small_thumbnail',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function oa_core_node_info() {
  $items = array(
    'oa_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('A collection of users that exists across all spaces.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_space' => array(
      'name' => t('Space'),
      'base' => 'node_content',
      'description' => t('A collection of content and users (members)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
