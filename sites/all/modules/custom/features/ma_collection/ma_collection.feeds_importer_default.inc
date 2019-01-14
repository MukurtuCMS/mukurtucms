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
    'name' => 'Import Collections',
    'description' => 'Import Digital Heritage collections.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'delete_uploaded_file' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
        'encoding' => 'UTF-8',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'NID',
            'target' => 'nid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Summary',
            'target' => 'field_description:summary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Image',
            'target' => 'field_collection_image',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Credit',
            'target' => 'field_collection_credit',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Digital Heritage Items',
            'target' => 'field_digital_heritage_items:guid_or_target_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'authorize' => 1,
        'update_non_existent' => 'skip',
        'skip_hash_check' => 0,
        'bundle' => 'collection',
        'insert_new' => 1,
        'language' => 'und',
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
