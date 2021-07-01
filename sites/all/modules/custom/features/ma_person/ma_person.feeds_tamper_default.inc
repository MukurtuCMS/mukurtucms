<?php

/**
 * @file
 * ma_person.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ma_person_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-deceased-convert_case';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Deceased';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert to lower case';
  $export['import_people-deceased-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-deceased-find_replace';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Deceased';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'yes',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '1',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Find replace \'yes\' -> 1';
  $export['import_people-deceased-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-deceased-find_replace_deceased_n_0';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Deceased';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'n',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '0',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Find replace \'n\' -> 0';
  $export['import_people-deceased-find_replace_deceased_n_0'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-deceased-find_replace_deceased_no';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Deceased';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'no',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '0',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Find replace \'no\' -> 0';
  $export['import_people-deceased-find_replace_deceased_no'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-deceased-find_replace_deceased_y_1';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Deceased';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'y',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '1',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Find replace \'y\' -> 1';
  $export['import_people-deceased-find_replace_deceased_y_1'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-deceased-trim';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Deceased';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_people-deceased-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-media_assets-explode';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Media Assets';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_people-media_assets-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-media_assets-trim';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Media Assets';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_people-media_assets-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-term_attachments-explode';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Term Attachments';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_people-term_attachments-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_people-term_attachments-trim';
  $feeds_tamper->importer = 'import_people';
  $feeds_tamper->source = 'Term Attachments';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_people-term_attachments-trim'] = $feeds_tamper;

  return $export;
}
