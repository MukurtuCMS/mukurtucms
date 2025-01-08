<?php

/**
 * @file
 * ma_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_person_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_person_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_person_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Add detailed information about a specific person.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function ma_person_paragraphs_info() {
  $items = array(
    'person_relationship_bundle' => array(
      'name' => 'Related Person',
      'bundle' => 'person_relationship_bundle',
      'label' => '',
      'description' => '',
      'locked' => '1',
    ),
    'text_section' => array(
      'name' => 'Text Section',
      'bundle' => 'text_section',
      'label' => '',
      'description' => '',
      'locked' => '1',
    ),
  );
  return $items;
}
