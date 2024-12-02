<?php

/**
 * @file
 * ma_dictionary.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function ma_dictionary_default_cer() {
  $items = array();
  $items['node:dictionary_word:field_word_list*node:word_list:field_words'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:dictionary_word:field_word_list" } ] },
    "cer_right" : { "und" : [ { "path" : "node:word_list:field_words" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "identifier" : "node:dictionary_word:field_word_list*node:word_list:field_words",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_dictionary_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ma_dictionary_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function ma_dictionary_eck_bundle_info() {
  $items = array(
    'alphabetical_order_definition_alphabetical_order_definition' => array(
      'machine_name' => 'alphabetical_order_definition_alphabetical_order_definition',
      'entity_type' => 'alphabetical_order_definition',
      'name' => 'alphabetical_order_definition',
      'label' => 'Alphabetical Order Definition',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function ma_dictionary_eck_entity_type_info() {
  $items = array(
    'alphabetical_order_definition' => array(
      'name' => 'alphabetical_order_definition',
      'label' => 'Alphabetical Order Definition',
      'properties' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function ma_dictionary_node_info() {
  $items = array(
    'dictionary_word' => array(
      'name' => t('Dictionary Word'),
      'base' => 'node_content',
      'description' => t('Provide definitions, sample sentences, and audio/video for terms.'),
      'has_title' => '1',
      'title_label' => t('Term'),
      'help' => '',
    ),
    'language_community' => array(
      'name' => t('Language Community'),
      'base' => 'node_content',
      'description' => t('Language Community Groups are used to give users the ability to add and edit dictionary words for a given language.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'word_list' => array(
      'name' => t('Word List'),
      'base' => 'node_content',
      'description' => t('A collection of dictionary words.'),
      'has_title' => '1',
      'title_label' => t('Word List Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function ma_dictionary_paragraphs_info() {
  $items = array(
    'dictionary_word_bundle' => array(
      'name' => 'Dictionary Word Bundle',
      'bundle' => 'dictionary_word_bundle',
      'label' => '',
      'description' => '',
      'locked' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function ma_dictionary_default_search_api_sort() {
  $items = array();
  $items['default_node_index__search_api_aggregation_1'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "search_api_aggregation_1",
    "name" : "Translation",
    "enabled" : "1",
    "weight" : "-98",
    "identifier" : "default_node_index__search_api_aggregation_1",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Translation Sort" },
    "rdf_mapping" : []
  }');
  $items['default_node_index__search_api_aggregation_2'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "search_api_aggregation_2",
    "name" : "Term",
    "enabled" : "1",
    "weight" : "-100",
    "identifier" : "default_node_index__search_api_aggregation_2",
    "default_sort" : "0",
    "default_sort_no_terms" : "1",
    "default_order" : "asc",
    "options" : { "field_name" : "Node Title" },
    "rdf_mapping" : []
  }');
  return $items;
}
