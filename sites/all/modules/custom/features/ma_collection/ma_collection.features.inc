<?php

/**
 * @file
 * ma_collection.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function ma_collection_default_cer() {
  $items = array();
  $items['node:collection:field_collections_parent_coll*node:collection:field_collections_child_coll'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:collection:field_collections_parent_coll" } ] },
    "cer_right" : { "und" : [ { "path" : "node:collection:field_collections_child_coll" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "identifier" : "node:collection:field_collections_parent_coll*node:collection:field_collections_child_coll",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_collection_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
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
function ma_collection_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_collection_node_info() {
  $items = array(
    'collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => t('A collection of digital heritage items.'),
      'has_title' => '1',
      'title_label' => t('Collection Name'),
      'help' => '',
    ),
    'personal_collection' => array(
      'name' => t('Personal Collection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Personal Collection Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
