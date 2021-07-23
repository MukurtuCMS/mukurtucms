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
    'content_type' => '',
    'description' => 'Import Digital Heritage collections.',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Import Collections',
    'parser' => array(
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
      'plugin_key' => 'FeedsCSVParser',
    ),
    'process_in_background' => 0,
    'processor' => array(
      'config' => array(
        'author' => 0,
        'authorize' => 1,
        'bundle' => 'collection',
        'expire' => '-1',
        'input_format' => 'filtered_html',
        'insert_new' => 1,
        'language' => 'und',
        'mappings' => array(
          0 => array(
            'language' => 'und',
            'source' => 'NID',
            'target' => 'nid',
            'unique' => 1,
          ),
          1 => array(
            'language' => 'und',
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'language' => 'und',
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Summary',
            'target' => 'field_description:summary',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Image',
            'target' => 'field_collection_image',
            'unique' => FALSE,
          ),
          6 => array(
            'language' => 'und',
            'source' => 'Credit',
            'target' => 'field_collection_credit',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Digital Heritage Items',
            'target' => 'field_digital_heritage_items:guid_or_target_id',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
      ),
      'plugin_key' => 'FeedsNodeProcessor',
    ),
    'update' => 0,
  );
  $export['import_collection'] = $feeds_importer;

  return $export;
}
