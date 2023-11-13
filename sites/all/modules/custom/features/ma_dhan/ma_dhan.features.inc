<?php

/**
 * @file
 * ma_dhan.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_dhan_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ma_dhan_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_dhan_node_info() {
  $items = array(
    'dhan' => array(
      'name' => t('Digital Heritage Admin Notification'),
      'base' => 'node_content',
      'description' => t('Digital Heritage Admin (Community Managers and Protocol Stewards) Notification'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
