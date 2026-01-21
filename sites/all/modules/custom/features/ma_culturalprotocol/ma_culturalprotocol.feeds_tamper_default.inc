<?php
/**
 * @file
 * ma_culturalprotocol.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ma_culturalprotocol_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-sharing_protocol-convert_case';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Sharing Protocol';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['import_cultural_protocols-sharing_protocol-convert_case'] = $feeds_tamper;

  return $export;
}
