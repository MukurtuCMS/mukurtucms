<?php

/**
 * @file
 * ma_community.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function ma_community_default_cer() {
  $items = array();
  $items['node:community:field_comm_dh_items*node:digital_heritage:field_community_ref'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:community:field_comm_dh_items" } ] },
    "cer_right" : { "und" : [ { "path" : "node:digital_heritage:field_community_ref" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "identifier" : "node:community:field_comm_dh_items*node:digital_heritage:field_community_ref",
    "rdf_mapping" : []
  }');
  $items['node:community:field_comm_protocols*node:cultural_protocol_group:og_group_ref'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:community:field_comm_protocols" } ] },
    "cer_right" : { "und" : [ { "path" : "node:cultural_protocol_group:og_group_ref" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "identifier" : "node:community:field_comm_protocols*node:cultural_protocol_group:og_group_ref",
    "rdf_mapping" : []
  }');
  $items['node:community:field_parent_community*node:community:field_child_communities'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:community:field_parent_community" } ] },
    "cer_right" : { "und" : [ { "path" : "node:community:field_child_communities" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "identifier" : "node:community:field_parent_community*node:community:field_child_communities",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_community_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_views_api().
 */
function ma_community_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_community_node_info() {
  $items = array(
    'community' => array(
      'name' => t('Community'),
      'base' => 'node_content',
      'description' => t('Community Groups can be used for content and user assignments, and community content can be made available to members of the group only.'),
      'has_title' => '1',
      'title_label' => t('Community Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
