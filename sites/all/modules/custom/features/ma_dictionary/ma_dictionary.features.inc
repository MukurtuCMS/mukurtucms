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
  $items['node:dictionary_word:field_dictionary_word_synonyms*node:dictionary_word:field_dictionary_word_synonyms'] = entity_import('cer', '{
    "identifier" : "node:dictionary_word:field_dictionary_word_synonyms*node:dictionary_word:field_dictionary_word_synonyms",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:dictionary_word:field_dictionary_word_synonyms" } ] },
    "cer_right" : { "und" : [ { "path" : "node:dictionary_word:field_dictionary_word_synonyms" } ] },
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
  );
  drupal_alter('node_info', $items);
  return $items;
}
