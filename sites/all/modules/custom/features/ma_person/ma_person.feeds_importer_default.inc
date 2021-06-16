<?php

/**
 * @file
 * ma_person.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_person_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_people';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import content of the \'Person\' type',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'csv',
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'delete_uploaded_file' => 0,
        'direct' => 0,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Import People',
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
        'bundle' => 'person',
        'expire' => '-1',
        'input_format' => 'full_html',
        'insert_new' => '1',
        'language' => 'und',
        'mappings' => array(
          0 => array(
            'language' => 'und',
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'language' => 'und',
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 1,
          ),
          2 => array(
            'language' => 'und',
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Media Assets',
            'target' => 'field_media_asset',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Date Born',
            'target' => 'field_date_born:start',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Date Died',
            'target' => 'field_date_died:start',
            'unique' => FALSE,
          ),
          6 => array(
            'language' => 'und',
            'source' => 'Deceased',
            'target' => 'field_deceased',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Term Attachments',
            'target' => 'field_mukurtu_terms:guid_or_tid',
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
  $export['import_people'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_people_taxonomy_terms';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => '',
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
    'name' => 'Import People Taxonomy Terms',
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
        'bundle' => 'people',
        'input_format' => 'full_html',
        'insert_new' => '1',
        'language' => 'und',
        'mappings' => array(
          0 => array(
            'language' => 'und',
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'language' => 'und',
            'source' => 'Term name',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'language' => 'und',
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'vocabulary' => 'category',
      ),
      'plugin_key' => 'FeedsTermProcessor',
    ),
    'update' => 0,
  );
  $export['import_people_taxonomy_terms'] = $feeds_importer;

  return $export;
}
