<?php
/**
 * @file
 * ma_collection.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_collection_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_collection';
  $feeds_importer->config = array(
    'name' => 'Import Collection',
    'description' => 'Import a collection of digital heritage items.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'collection',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'NID',
            'target' => 'nid',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Type',
            'target' => 'field_term_ma_collection',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Tags',
            'target' => 'field_tags',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Cultural Protocols',
            'target' => 'field_cultural_protocol_groups',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Community Groups',
            'target' => 'field_community_groups',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          8 => array(
            'source' => 'Audience',
            'target' => 'group_audience',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Digital Heritage',
            'target' => 'field_reference_digital_heritage',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_collection'] = $feeds_importer;

  return $export;
}
