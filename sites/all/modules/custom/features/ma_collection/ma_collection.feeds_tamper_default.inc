<?php

/**
 * @file
 * ma_collection.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ma_collection_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_collection-digital_heritage-explode';
  $feeds_tamper->importer = 'import_collection';
  $feeds_tamper->source = 'Digital Heritage';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ',',
    'separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_collection-digital_heritage-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_collection-digital_heritage_items-explode';
  $feeds_tamper->importer = 'import_collection';
  $feeds_tamper->source = 'Digital Heritage Items';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_collection-digital_heritage_items-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_collection-digital_heritage_items-require_valid_digital_heritage';
  $feeds_tamper->importer = 'import_collection';
  $feeds_tamper->source = 'Digital Heritage Items';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Digital Heritage';
  $export['import_collection-digital_heritage_items-require_valid_digital_heritage'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_collection-digital_heritage_items-trim';
  $feeds_tamper->importer = 'import_collection';
  $feeds_tamper->source = 'Digital Heritage Items';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_collection-digital_heritage_items-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_collection-nid-require_valid_collection';
  $feeds_tamper->importer = 'import_collection';
  $feeds_tamper->source = 'NID';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'collection',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid Collection';
  $export['import_collection-nid-require_valid_collection'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_collection-nid-trim';
  $feeds_tamper->importer = 'import_collection';
  $feeds_tamper->source = 'NID';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_collection-nid-trim'] = $feeds_tamper;

  return $export;
}
