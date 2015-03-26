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
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_collection-digital_heritage-explode';
  $feeds_tamper->importer = 'import_collection';
  $feeds_tamper->source = 'Digital Heritage';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_collection-digital_heritage-explode'] = $feeds_tamper;

  return $export;
}
