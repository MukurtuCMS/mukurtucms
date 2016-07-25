<?php
/**
 * @file
 * paragraphs_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function paragraphs_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function paragraphs_test_node_info() {
  $items = array(
    'paragraph_test' => array(
      'name' => t('Paragraph Test'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function paragraphs_test_paragraphs_info() {
  $items = array(
    'ptest' => array(
      'name' => 'PTest',
      'bundle' => 'ptest',
      'locked' => '1',
    ),
  );
  return $items;
}
