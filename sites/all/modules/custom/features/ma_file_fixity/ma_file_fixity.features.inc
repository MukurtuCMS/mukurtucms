<?php

/**
 * @file
 * ma_file_fixity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_file_fixity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_file_fixity_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_file_fixity_node_info() {
  $items = array(
    'fixity_check' => array(
      'name' => t('Fixity Check'),
      'base' => 'node_content',
      'description' => t('Fixity Checks can be created and run by Mukurtu Administrators to verify that media assets have not been tampered with. They can be run both manually and on schedule.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
