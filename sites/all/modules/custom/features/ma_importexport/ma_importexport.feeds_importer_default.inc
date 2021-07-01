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
    'name' => 'Import Digital Heritage Metadata',
    'description' => 'Import metadata associated with Digital Heritage items.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 0,
        'allowed_extensions' => 'csv',
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
        'update_existing' => '2',
        'expire' => '-1',
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
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Media Assets',
            'target' => 'field_media_asset',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Sharing Settings',
            'target' => 'field_item_privacy_setting',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Sharing Protocols',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Category',
            'target' => 'field_category',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Summary',
            'target' => 'field_summary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Creator',
            'target' => 'field_creator',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Contributor',
            'target' => 'field_contributor',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Date',
            'target' => 'field_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Cultural Narrative',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Traditional Knowledge',
            'target' => 'field_tk_body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Keywords',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Publisher',
            'target' => 'field_publisher',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Rights',
            'target' => 'field_rights',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Traditional Licensing URL',
            'target' => 'field_licence_trad',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Standard and Creative Commons Licensing URL',
            'target' => 'field_licence_std_cc',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Format',
            'target' => 'field_format',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'Type',
            'target' => 'field_dh_type',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Identifier',
            'target' => 'field_identifier',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'Language',
            'target' => 'field_language',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'Subject',
            'target' => 'field_subject',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'Transcription',
            'target' => 'field_transcription',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Latitude',
            'target' => 'field_coverage:lat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'Longitude',
            'target' => 'field_coverage:lon',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'Location Description',
            'target' => 'field_coverage_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          30 => array(
            'source' => 'Collections',
            'target' => 'field_collection:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          31 => array(
            'source' => 'Related Items',
            'target' => 'field_dictionary_word_related_dh:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          32 => array(
            'source' => 'Book Pages',
            'target' => 'field_book_children:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          33 => array(
            'source' => 'Community Records',
            'target' => 'field_community_record_children:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          34 => array(
            'source' => 'Username',
            'target' => 'user_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'input_format' => 'filtered_html',
        'author' => '1',
        'authorize' => 1,
        'skip_hash_check' => 0,
        'bundle' => 'digital_heritage',
        'update_non_existent' => 'skip',
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
  $export['digital_heritage_metadata'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_digital_heritage_community_records';
  $feeds_importer->config = array(
    'name' => 'Import Digital Heritage Community Records',
    'description' => 'Import metadata associated with Digital Heritage community records',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 0,
        'allowed_extensions' => 'csv',
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
        'update_existing' => '2',
        'expire' => '-1',
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
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Media Assets',
            'target' => 'field_media_asset',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Sharing Settings',
            'target' => 'field_item_privacy_setting',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Sharing Protocols',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Category',
            'target' => 'field_category',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Summary',
            'target' => 'field_summary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Creator',
            'target' => 'field_creator',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Contributor',
            'target' => 'field_contributor',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Date',
            'target' => 'field_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Cultural Narrative',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Traditional Knowledge',
            'target' => 'field_tk_body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Keywords',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Publisher',
            'target' => 'field_publisher',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Rights',
            'target' => 'field_rights',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Traditional Licensing URL',
            'target' => 'field_licence_trad',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Standard and Creative Commons Licensing URL',
            'target' => 'field_licence_std_cc',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Format',
            'target' => 'field_format',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'Type',
            'target' => 'field_dh_type',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Identifier',
            'target' => 'field_identifier',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'Language',
            'target' => 'field_language',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'Subject',
            'target' => 'field_subject',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'Transcription',
            'target' => 'field_transcription',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Latitude',
            'target' => 'field_coverage:lat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'Longitude',
            'target' => 'field_coverage:lon',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'Location Description',
            'target' => 'field_coverage_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          30 => array(
            'source' => 'Collections',
            'target' => 'field_collection:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          31 => array(
            'source' => 'Related Items',
            'target' => 'field_dictionary_word_related_dh:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          32 => array(
            'source' => 'Book Pages',
            'target' => 'field_book_children:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          33 => array(
            'source' => 'Community Record Parent',
            'target' => 'field_community_record_parent:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          34 => array(
            'source' => 'Username',
            'target' => 'user_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'input_format' => 'filtered_html',
        'author' => '1',
        'authorize' => 1,
        'skip_hash_check' => 0,
        'bundle' => 'digital_heritage',
        'update_non_existent' => 'skip',
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
  $export['import_digital_heritage_community_records'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_audio';
  $feeds_importer->config = array(
    'name' => 'Import Media: Audio',
    'description' => 'Import audio files with metadata into the Scald Atom Library',
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
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'File',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Thumbnail',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Contributors',
            'target' => 'field_contributor',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Tags',
            'target' => 'scald_tags',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'audio',
        'values' => array(
          'provider' => 'scald_audio',
          'base_id' => '0',
          'title' => 'Default Title',
          'actions' => '7',
          'publisher' => '0',
          'created' => '0',
          'changed' => '0',
        ),
        'authorize' => TRUE,
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
  $export['import_media_audio'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_files';
  $feeds_importer->config = array(
    'name' => 'Import Media: Files',
    'description' => 'Import files with metadata into the Scald Atom Library',
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
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'File',
            'target' => 'scald_file:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Thumbnail',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'People',
            'target' => 'field_people',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Tags',
            'target' => 'scald_tags',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'file',
        'values' => array(
          'provider' => 'scald_file',
          'base_id' => '0',
          'title' => 'Default Title',
          'actions' => '7',
          'publisher' => '0',
          'created' => '0',
          'changed' => '0',
        ),
        'authorize' => TRUE,
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
  $export['import_media_files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_images';
  $feeds_importer->config = array(
    'name' => 'Import Media: Images',
    'description' => 'Import images with metadata into the Scald Atom Library',
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
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Identifier',
            'target' => 'field_scald_identifier',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Image',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Original DNG',
            'target' => 'field_original_dng:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Archival TIFF',
            'target' => 'field_archival_tiff:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Full-Size JPEG',
            'target' => 'field_full_size_jpeg:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Caption',
            'target' => 'field_scald_headline',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Created',
            'target' => 'field_scald_created:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Creator',
            'target' => 'field_scald_creator',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Description',
            'target' => 'field_scald_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Keywords',
            'target' => 'scald_tags',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'People',
            'target' => 'field_people',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Latitude',
            'target' => 'field_scald_geo_location:lat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Longitude',
            'target' => 'field_scald_geo_location:lon',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Location',
            'target' => 'field_scald_location',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Rights',
            'target' => 'field_rights',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'Licensing',
            'target' => 'field_licence_std_cc',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Categories',
            'target' => 'field_category',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'image',
        'values' => array(
          'provider' => 'scald_image',
          'base_id' => '0',
          'title' => 'Default Title',
          'actions' => '7',
          'publisher' => '0',
          'created' => '0',
          'changed' => '0',
        ),
        'authorize' => TRUE,
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
  $export['import_media_images'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_media_video';
  $feeds_importer->config = array(
    'name' => 'Import Media: Video',
    'description' => 'Import videos and metadata into the Scald Atom Library',
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
      'plugin_key' => 'FeedsEntityProcessorScald_atom',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'sid',
            'target' => 'sid',
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
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'File',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Protocol',
            'target' => 'field_scald_protocol:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Thumbnail',
            'target' => 'scald_thumbnail:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Authors',
            'target' => 'scald_authors',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Tags',
            'target' => 'scald_tags',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'People',
            'target' => 'field_people',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'video',
        'values' => array(
          'provider' => 'scald_video',
          'base_id' => '0',
          'title' => 'Default Title',
          'actions' => '7',
          'publisher' => '0',
          'created' => '0',
          'changed' => '0',
        ),
        'authorize' => TRUE,
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
  $export['import_media_video'] = $feeds_importer;

  return $export;
}
