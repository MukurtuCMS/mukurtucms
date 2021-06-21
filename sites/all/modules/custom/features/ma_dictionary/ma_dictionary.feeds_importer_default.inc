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
    'content_type' => '',
    'description' => '',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'csv',
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'direct' => 0,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Import Dictionary Word Additional Entries',
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
        'bundle' => 'dictionary_word_bundle',
        'input_format' => 'filtered_html',
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
            'source' => 'Dictionary Word',
            'target' => 'item_id:guid_or_nid',
            'unique' => FALSE,
          ),
          2 => array(
            'language' => 'und',
            'source' => 'Alternate Spelling',
            'target' => 'field_alternate_spelling',
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          4 => array(
            'language' => 'und',
            'source' => 'Translation',
            'target' => 'field_translation',
            'unique' => FALSE,
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Pronunciation',
            'target' => 'field_pronunciation',
            'unique' => FALSE,
          ),
          6 => array(
            'language' => 'und',
            'source' => 'Sample Sentences',
            'target' => 'field_sample_sentence',
            'unique' => FALSE,
          ),
          7 => array(
            'autocreate' => 1,
            'source' => 'Part of Speech',
            'target' => 'field_part_of_speech',
            'term_search' => '0',
          ),
          8 => array(
            'language' => 'und',
            'source' => 'Recording',
            'target' => 'field_dictionary_word_recording',
            'unique' => FALSE,
          ),
          9 => array(
            'language' => 'und',
            'source' => 'Definition',
            'target' => 'field_definition',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'values' => array(),
      ),
      'plugin_key' => 'FeedsEntityProcessorParagraphs_item',
    ),
    'update' => 0,
  );
  $export['import_dictionary_word_additional_entries'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_dictionary_word_lists';
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
        'direct' => FALSE,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Import Dictionary Word Lists',
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
        'bundle' => 'word_list',
        'expire' => '-1',
        'input_format' => 'plain_text',
        'insert_new' => '1',
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
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Summary',
            'target' => 'field_collection_summary',
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
            'source' => 'Words',
            'target' => 'field_words:guid_or_nid',
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
  $export['import_dictionary_word_lists'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_dictionary_words';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => '',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'csv',
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'direct' => 0,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Import Dictionary Words',
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
        'bundle' => 'dictionary_word',
        'expire' => '-1',
        'input_format' => 'filtered_html',
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
            'source' => 'Term',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'language' => 'und',
            'source' => 'Language',
            'target' => 'field_dictionary_word_language',
            'unique' => FALSE,
          ),
          4 => array(
            'autocreate' => 1,
            'field_language' => 'und',
            'source' => 'Keywords',
            'target' => 'field_tags',
            'term_search' => '0',
          ),
          5 => array(
            'language' => 'und',
            'source' => 'Additional Media',
            'target' => 'field_additional_media',
            'unique' => FALSE,
          ),
          6 => array(
            'language' => 'und',
            'source' => 'Related Dictionary Words',
            'target' => 'field_related_dictionary_words:guid_or_nid',
            'unique' => FALSE,
          ),
          7 => array(
            'language' => 'und',
            'source' => 'Related Digital Heritage Items',
            'target' => 'field_dictionary_word_related_dh:guid_or_nid',
            'unique' => FALSE,
          ),
          8 => array(
            'language' => 'und',
            'source' => 'Word List',
            'target' => 'field_word_list:guid_or_nid',
            'unique' => FALSE,
          ),
          9 => array(
            'language' => 'und',
            'source' => 'Protocol',
            'target' => 'og_group_ref:guid_or_nid',
            'unique' => FALSE,
          ),
          10 => array(
            'language' => 'und',
            'source' => 'Sharing Settings',
            'target' => 'field_item_privacy_setting',
            'unique' => FALSE,
          ),
          11 => array(
            'language' => 'und',
            'source' => 'Alternate Spelling',
            'target' => 'field_alternate_spelling',
            'unique' => FALSE,
          ),
          12 => array(
            'language' => 'und',
            'source' => 'Source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          13 => array(
            'language' => 'und',
            'source' => 'Translation',
            'target' => 'field_translation',
            'unique' => FALSE,
          ),
          14 => array(
            'language' => 'und',
            'source' => 'Pronunciation',
            'target' => 'field_pronunciation',
            'unique' => FALSE,
          ),
          15 => array(
            'language' => 'und',
            'source' => 'Sample Sentences',
            'target' => 'field_sample_sentence',
            'unique' => FALSE,
          ),
          16 => array(
            'language' => 'und',
            'source' => 'Part of Speech',
            'target' => 'field_part_of_speech',
            'unique' => FALSE,
          ),
          17 => array(
            'language' => 'und',
            'source' => 'Recording',
            'target' => 'field_dictionary_word_recording',
            'unique' => FALSE,
          ),
          18 => array(
            'language' => 'und',
            'source' => 'Definition',
            'target' => 'field_definition',
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
  $export['import_dictionary_words'] = $feeds_importer;

  return $export;
}
