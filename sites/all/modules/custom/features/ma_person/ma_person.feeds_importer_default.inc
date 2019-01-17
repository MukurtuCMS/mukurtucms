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
    'name' => 'Import People',
    'description' => 'Import content of the \'Person\' type',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'delete_uploaded_file' => 0,
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 1,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Media Assets',
            'target' => 'field_media_asset',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Date Born',
            'target' => 'field_date_born:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Date Died',
            'target' => 'field_date_died:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Deceased',
            'target' => 'field_deceased',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Term Attachments',
            'target' => 'field_mukurtu_terms:guid_or_tid',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'person',
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
  $export['import_people'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_people_taxonomy_terms';
  $feeds_importer->config = array(
    'name' => 'Import People Taxonomy Terms',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'delete_uploaded_file' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'category',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Term name',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'skip_hash_check' => 0,
        'bundle' => 'people',
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
  $export['import_people_taxonomy_terms'] = $feeds_importer;

  return $export;
}
