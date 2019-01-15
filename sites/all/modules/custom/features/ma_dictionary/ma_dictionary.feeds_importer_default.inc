<?php

/**
 * @file
 * ma_dictionary.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_dictionary_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_dictionary_word_additional_entries';
  $feeds_importer->config = array(
    'name' => 'Import Dictionary Word Additional Entries',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
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
      'plugin_key' => 'FeedsEntityProcessorParagraphs_item',
      'config' => array(
        'values' => array(),
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Dictionary Word',
            'target' => 'item_id:guid_or_nid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Alternate Spelling',
            'target' => 'field_alternate_spelling',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Translation',
            'target' => 'field_translation',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Pronunciation',
            'target' => 'field_pronunciation',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Sample Sentences',
            'target' => 'field_sample_sentence',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Part of Speech',
            'target' => 'field_part_of_speech',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          8 => array(
            'source' => 'Recording',
            'target' => 'field_dictionary_word_recording',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Definition',
            'target' => 'field_definition',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'dictionary_word_bundle',
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
  $export['import_dictionary_word_additional_entries'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_dictionary_word_lists';
  $feeds_importer->config = array(
    'name' => 'Import Dictionary Word Lists',
    'description' => '',
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
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Summary',
            'target' => 'field_collection_summary',
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
            'source' => 'Words',
            'target' => 'field_words:guid_or_nid',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'word_list',
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
  $export['import_dictionary_word_lists'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_dictionary_words';
  $feeds_importer->config = array(
    'name' => 'Import Dictionary Words',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
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
            'source' => 'Term',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Language',
            'target' => 'field_dictionary_word_language',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Keywords',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
            'field_language' => 'und',
          ),
          5 => array(
            'source' => 'Additional Media',
            'target' => 'field_additional_media',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Related Dictionary Words',
            'target' => 'field_related_dictionary_words:guid_or_nid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Related Digital Heritage Items',
            'target' => 'field_dictionary_word_related_dh:guid_or_nid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Word List',
            'target' => 'field_word_list:guid_or_nid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Protocol',
            'target' => 'og_group_ref:guid_or_nid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Sharing Settings',
            'target' => 'field_item_privacy_setting',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Alternate Spelling',
            'target' => 'field_alternate_spelling',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Translation',
            'target' => 'field_translation',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Pronunciation',
            'target' => 'field_pronunciation',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Sample Sentences',
            'target' => 'field_sample_sentence',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Part of Speech',
            'target' => 'field_part_of_speech',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Recording',
            'target' => 'field_dictionary_word_recording',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Definition',
            'target' => 'field_definition',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'dictionary_word',
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
  $export['import_dictionary_words'] = $feeds_importer;

  return $export;
}
