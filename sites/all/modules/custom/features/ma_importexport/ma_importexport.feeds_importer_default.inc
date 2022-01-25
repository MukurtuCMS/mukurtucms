<?php

/**
 * @file
 * ma_importexport.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_importexport_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'digital_heritage_metadata';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import metadata associated with Digital Heritage items.',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'csv',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'delete_uploaded_file' => FALSE,
        'direct' => 0,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Import Digital Heritage Metadata',
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
        'author' => '1',
        'authorize' => 1,
        'bundle' => 'digital_heritage',
        'expire' => '-1',
        'input_format' => 'filtered_html',
        'insert_new' => 1,
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
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Media Assets',
            'target' => 'field_media_asset',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Sharing Settings',
            'target' => 'field_item_privacy_setting',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Sharing Protocols',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
          ),
          6 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Category',
            'target' => 'field_category',
            'term_search' => '0',
          ),
          7 => array(
            'language' => 'und',
            'source' => 'Summary',
            'target' => 'field_summary',
            'unique' => FALSE,
          ),
          8 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Creator',
            'target' => 'field_creator',
            'term_search' => '0',
          ),
          9 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Contributor',
            'target' => 'field_contributor',
            'term_search' => '0',
          ),
          10 => array(
            'language' => 'und',
            'source' => 'Date',
            'target' => 'field_date',
            'unique' => FALSE,
          ),
          11 => array(
            'language' => 'und',
            'source' => 'Cultural Narrative',
            'target' => 'body',
            'unique' => FALSE,
          ),
          12 => array(
            'language' => 'und',
            'source' => 'Traditional Knowledge',
            'target' => 'field_tk_body',
            'unique' => FALSE,
          ),
          13 => array(
            'language' => 'und',
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          14 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Keywords',
            'target' => 'field_tags',
            'term_search' => '0',
          ),
          15 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Publisher',
            'target' => 'field_publisher',
            'term_search' => '0',
          ),
          16 => array(
            'language' => 'und',
            'source' => 'Rights',
            'target' => 'field_rights',
            'unique' => FALSE,
          ),
          17 => array(
            'language' => 'und',
            'source' => 'Traditional Licensing URL',
            'target' => 'field_licence_trad',
            'unique' => FALSE,
          ),
          18 => array(
            'language' => 'und',
            'source' => 'Standard and Creative Commons Licensing URL',
            'target' => 'field_licence_std_cc',
            'unique' => FALSE,
          ),
          19 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Format',
            'target' => 'field_format',
            'term_search' => '0',
          ),
          20 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Type',
            'target' => 'field_dh_type',
            'term_search' => '0',
          ),
          21 => array(
            'language' => 'und',
            'source' => 'Identifier',
            'target' => 'field_identifier',
            'unique' => FALSE,
          ),
          22 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Language',
            'target' => 'field_language',
            'term_search' => '0',
          ),
          23 => array(
            'language' => 'und',
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          24 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Subject',
            'target' => 'field_subject',
            'term_search' => '0',
          ),
          25 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
          ),
          26 => array(
            'language' => 'und',
            'source' => 'Transcription',
            'target' => 'field_transcription',
            'unique' => FALSE,
          ),
          27 => array(
            'language' => 'und',
            'source' => 'Latitude',
            'target' => 'field_coverage:lat',
            'unique' => FALSE,
          ),
          28 => array(
            'language' => 'und',
            'source' => 'Longitude',
            'target' => 'field_coverage:lon',
            'unique' => FALSE,
          ),
          29 => array(
            'language' => 'und',
            'source' => 'Location Description',
            'target' => 'field_coverage_description',
            'unique' => FALSE,
          ),
          30 => array(
            'language' => 'und',
            'source' => 'Collections',
            'target' => 'field_collection:guid_or_target_id',
            'unique' => FALSE,
          ),
          31 => array(
            'language' => 'und',
            'source' => 'Related Items',
            'target' => 'field_dictionary_word_related_dh:guid_or_target_id',
            'unique' => FALSE,
          ),
          32 => array(
            'language' => 'und',
            'source' => 'Book Pages',
            'target' => 'field_book_children:guid_or_target_id',
            'unique' => FALSE,
          ),
          33 => array(
            'language' => 'und',
            'source' => 'Community Records',
            'target' => 'field_community_record_children:guid_or_target_id',
            'unique' => FALSE,
          ),
          34 => array(
            'language' => 'und',
            'source' => 'Username',
            'target' => 'user_name',
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
  $export['digital_heritage_metadata'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_digital_heritage_community_records';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import metadata associated with Digital Heritage community records',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'csv',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'delete_uploaded_file' => FALSE,
        'direct' => 0,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Import Digital Heritage Community Records',
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
        'author' => '1',
        'authorize' => 1,
        'bundle' => 'digital_heritage',
        'expire' => '-1',
        'input_format' => 'filtered_html',
        'insert_new' => 1,
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
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Media Assets',
            'target' => 'field_media_asset',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Sharing Settings',
            'target' => 'field_item_privacy_setting',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Sharing Protocols',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
          ),
          6 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Category',
            'target' => 'field_category',
            'term_search' => '0',
          ),
          7 => array(
            'language' => 'und',
            'source' => 'Summary',
            'target' => 'field_summary',
            'unique' => FALSE,
          ),
          8 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Creator',
            'target' => 'field_creator',
            'term_search' => '0',
          ),
          9 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Contributor',
            'target' => 'field_contributor',
            'term_search' => '0',
          ),
          10 => array(
            'language' => 'und',
            'source' => 'Date',
            'target' => 'field_date',
            'unique' => FALSE,
          ),
          11 => array(
            'language' => 'und',
            'source' => 'Cultural Narrative',
            'target' => 'body',
            'unique' => FALSE,
          ),
          12 => array(
            'language' => 'und',
            'source' => 'Traditional Knowledge',
            'target' => 'field_tk_body',
            'unique' => FALSE,
          ),
          13 => array(
            'language' => 'und',
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          14 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Keywords',
            'target' => 'field_tags',
            'term_search' => '0',
          ),
          15 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Publisher',
            'target' => 'field_publisher',
            'term_search' => '0',
          ),
          16 => array(
            'language' => 'und',
            'source' => 'Rights',
            'target' => 'field_rights',
            'unique' => FALSE,
          ),
          17 => array(
            'language' => 'und',
            'source' => 'Traditional Licensing URL',
            'target' => 'field_licence_trad',
            'unique' => FALSE,
          ),
          18 => array(
            'language' => 'und',
            'source' => 'Standard and Creative Commons Licensing URL',
            'target' => 'field_licence_std_cc',
            'unique' => FALSE,
          ),
          19 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Format',
            'target' => 'field_format',
            'term_search' => '0',
          ),
          20 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Type',
            'target' => 'field_dh_type',
            'term_search' => '0',
          ),
          21 => array(
            'language' => 'und',
            'source' => 'Identifier',
            'target' => 'field_identifier',
            'unique' => FALSE,
          ),
          22 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Language',
            'target' => 'field_language',
            'term_search' => '0',
          ),
          23 => array(
            'language' => 'und',
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          24 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Subject',
            'target' => 'field_subject',
            'term_search' => '0',
          ),
          25 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
          ),
          26 => array(
            'language' => 'und',
            'source' => 'Transcription',
            'target' => 'field_transcription',
            'unique' => FALSE,
          ),
          27 => array(
            'language' => 'und',
            'source' => 'Latitude',
            'target' => 'field_coverage:lat',
            'unique' => FALSE,
          ),
          28 => array(
            'language' => 'und',
            'source' => 'Longitude',
            'target' => 'field_coverage:lon',
            'unique' => FALSE,
          ),
          29 => array(
            'language' => 'und',
            'source' => 'Location Description',
            'target' => 'field_coverage_description',
            'unique' => FALSE,
          ),
          30 => array(
            'language' => 'und',
            'source' => 'Collections',
            'target' => 'field_collection:guid_or_target_id',
            'unique' => FALSE,
          ),
          31 => array(
            'language' => 'und',
            'source' => 'Related Items',
            'target' => 'field_dictionary_word_related_dh:guid_or_target_id',
            'unique' => FALSE,
          ),
          32 => array(
            'language' => 'und',
            'source' => 'Book Pages',
            'target' => 'field_book_children:guid_or_target_id',
            'unique' => FALSE,
          ),
          33 => array(
            'language' => 'und',
            'source' => 'Community Record Parent',
            'target' => 'field_community_record_parent:guid_or_target_id',
            'unique' => FALSE,
          ),
          34 => array(
            'language' => 'und',
            'source' => 'Username',
            'target' => 'user_name',
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
  $export['import_digital_heritage_community_records'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_audio';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import audio files with metadata into the Scald Atom Library',
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
    'name' => 'Import Media: Audio',
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
        'authorize' => TRUE,
        'bundle' => 'audio',
        'input_format' => 'filtered_html',
        'insert_new' => 1,
        'language' => 'und',
        'mappings' => array(
          0 => array(
            'language' => 'und',
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'File',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Thumbnail',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
          ),
          6 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
          ),
          7 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Contributors',
            'target' => 'field_contributor',
            'term_search' => '0',
          ),
          8 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
          ),
          9 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Tags',
            'target' => 'scald_tags',
            'term_search' => '0',
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'values' => array(
          'actions' => '7',
          'base_id' => '0',
          'changed' => '0',
          'created' => '0',
          'provider' => 'scald_audio',
          'publisher' => '0',
          'title' => 'Default Title',
        ),
      ),
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
    ),
    'update' => 0,
  );
  $export['import_media_audio'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_files';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import files with metadata into the Scald Atom Library',
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
    'name' => 'Import Media: Files',
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
        'authorize' => TRUE,
        'bundle' => 'file',
        'input_format' => 'filtered_html',
        'insert_new' => 1,
        'language' => 'und',
        'mappings' => array(
          0 => array(
            'language' => 'und',
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'File',
            'target' => 'scald_file:uri',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Thumbnail',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
          ),
          6 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
          ),
          7 => array(
            'language' => 'und',
            'source' => 'People',
            'target' => 'field_people',
            'unique' => FALSE,
          ),
          8 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Tags',
            'target' => 'scald_tags',
            'term_search' => '0',
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'values' => array(
          'actions' => '7',
          'base_id' => '0',
          'changed' => '0',
          'created' => '0',
          'provider' => 'scald_file',
          'publisher' => '0',
          'title' => 'Default Title',
        ),
      ),
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
    ),
    'update' => 0,
  );
  $export['import_media_files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_images';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import images with metadata into the Scald Atom Library',
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
    'name' => 'Import Media: Images',
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
        'authorize' => TRUE,
        'bundle' => 'image',
        'input_format' => 'filtered_html',
        'insert_new' => 1,
        'language' => 'und',
        'mappings' => array(
          0 => array(
            'language' => 'und',
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Identifier',
            'target' => 'field_scald_identifier',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Image',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
          ),
          6 => array(
            'language' => 'und',
            'source' => 'Original DNG',
            'target' => 'field_original_dng:uri',
            'unique' => FALSE,
          ),
          7 => array(
            'language' => 'und',
            'source' => 'Archival TIFF',
            'target' => 'field_archival_tiff:uri',
            'unique' => FALSE,
          ),
          8 => array(
            'language' => 'und',
            'source' => 'Full-Size JPEG',
            'target' => 'field_full_size_jpeg:uri',
            'unique' => FALSE,
          ),
          9 => array(
            'language' => 'und',
            'source' => 'Caption',
            'target' => 'field_scald_headline',
            'unique' => FALSE,
          ),
          10 => array(
            'language' => 'und',
            'source' => 'Created',
            'target' => 'field_scald_created:start',
            'unique' => FALSE,
          ),
          11 => array(
            'language' => 'und',
            'source' => 'Creator',
            'target' => 'field_scald_creator',
            'unique' => FALSE,
          ),
          12 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
          ),
          13 => array(
            'language' => 'und',
            'source' => 'Description',
            'target' => 'field_scald_description',
            'unique' => FALSE,
          ),
          14 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Keywords',
            'target' => 'scald_tags',
            'term_search' => '0',
          ),
          15 => array(
            'language' => 'und',
            'source' => 'People',
            'target' => 'field_people',
            'unique' => FALSE,
          ),
          16 => array(
            'language' => 'und',
            'source' => 'Latitude',
            'target' => 'field_scald_geo_location:lat',
            'unique' => FALSE,
          ),
          17 => array(
            'language' => 'und',
            'source' => 'Longitude',
            'target' => 'field_scald_geo_location:lon',
            'unique' => FALSE,
          ),
          18 => array(
            'language' => 'und',
            'source' => 'Location',
            'target' => 'field_scald_location',
            'unique' => FALSE,
          ),
          19 => array(
            'language' => 'und',
            'source' => 'Rights',
            'target' => 'field_rights',
            'unique' => FALSE,
          ),
          20 => array(
            'language' => 'und',
            'source' => 'Licensing',
            'target' => 'field_licence_std_cc',
            'unique' => FALSE,
          ),
          21 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Categories',
            'target' => 'field_category',
            'term_search' => '0',
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'values' => array(
          'actions' => '7',
          'base_id' => '0',
          'changed' => '0',
          'created' => '0',
          'provider' => 'scald_image',
          'publisher' => '0',
          'title' => 'Default Title',
        ),
      ),
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
    ),
    'update' => 0,
  );
  $export['import_media_images'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_video';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import videos and metadata into the Scald Atom Library',
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
    'name' => 'Import Media: Video',
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
        'authorize' => TRUE,
        'bundle' => 'video',
        'input_format' => 'filtered_html',
        'insert_new' => 1,
        'language' => 'und',
        'mappings' => array(
          0 => array(
            'language' => 'und',
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'File',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Thumbnail',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
          ),
          6 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
          ),
          7 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'Tags',
            'target' => 'scald_tags',
            'term_search' => '0',
          ),
          8 => array(
            'autocreate' => 1,
            'language' => 'und',
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'values' => array(
          'actions' => '7',
          'base_id' => '0',
          'changed' => '0',
          'created' => '0',
          'provider' => 'scald_video',
          'publisher' => '0',
          'title' => 'Default Title',
        ),
      ),
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
    ),
    'update' => 0,
  );
  $export['import_media_video'] = $feeds_importer;

  return $export;
}
