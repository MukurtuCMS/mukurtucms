<?php

/**
 * @file
 * ma_digitalheritage.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function ma_digitalheritage_default_cer() {
  $items = array();
  $items['node:digital_heritage:field_book_parent*node:digital_heritage:field_book_children'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:digital_heritage:field_book_parent" } ] },
    "cer_right" : { "und" : [ { "path" : "node:digital_heritage:field_book_children" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "identifier" : "node:digital_heritage:field_book_parent*node:digital_heritage:field_book_children",
    "rdf_mapping" : []
  }');
  $items['node:digital_heritage:field_community_record_parent*node:digital_heritage:field_community_record_children'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:digital_heritage:field_community_record_parent" } ] },
    "cer_right" : { "und" : [ { "path" : "node:digital_heritage:field_community_record_children" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "identifier" : "node:digital_heritage:field_community_record_parent*node:digital_heritage:field_community_record_children",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_digitalheritage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_digitalheritage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_digitalheritage_node_info() {
  $items = array(
    'digital_heritage' => array(
      'name' => t('Digital Heritage'),
      'base' => 'node_content',
      'description' => t('Content & media items: images, movies, audio, documents'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
