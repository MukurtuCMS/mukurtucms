<?php
/**
 * @file
 * ma_community.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_community_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ma_community_node_info() {
  $items = array(
    'community' => array(
      'name' => t('Community'),
      'base' => 'node_content',
      'description' => t('Community Groups can be used for content and user assignments, and community content can be made available to members of the group only.'),
      'has_title' => '1',
      'title_label' => t('Community Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
