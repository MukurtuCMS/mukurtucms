<?php
/**
 * @file
 * oa_sections.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_sections_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_sections_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oa_sections_node_info() {
  $items = array(
    'oa_section' => array(
      'name' => t('Section Page'),
      'base' => 'node_content',
      'description' => t('A landing page and collection of content within a Space.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
