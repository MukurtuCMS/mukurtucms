<?php
/**
 * @file
 * ma_glossary.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_glossary_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
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
function ma_glossary_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_glossary_node_info() {
  $items = array(
    'glossary' => array(
      'name' => t('Glossary'),
      'base' => 'node_content',
      'description' => t('A collection of glossary terms.'),
      'has_title' => '1',
      'title_label' => t('Glossary Name'),
      'help' => '',
    ),
    'glossary_term' => array(
      'name' => t('Glossary Term'),
      'base' => 'node_content',
      'description' => t('Provide definitions, sample sentences, and audio/video for terms.'),
      'has_title' => '1',
      'title_label' => t('Term'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
