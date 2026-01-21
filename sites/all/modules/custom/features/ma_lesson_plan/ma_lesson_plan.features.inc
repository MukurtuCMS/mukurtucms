<?php

/**
 * @file
 * ma_lesson_plan.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_lesson_plan_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ma_lesson_plan_node_info() {
  $items = array(
    'lesson' => array(
      'name' => t('Lesson'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Lesson Title'),
      'help' => '',
    ),
    'unit_plan' => array(
      'name' => t('Unit Plan'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Unit Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
