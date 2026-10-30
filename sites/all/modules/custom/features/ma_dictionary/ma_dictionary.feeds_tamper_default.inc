<?php

/**
 * @file
 * ma_dictionary.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ma_dictionary_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_additional_entries-dictionary_word-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_word_additional_entries';
  $feeds_tamper->source = 'Dictionary Word';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 0,
    'node_type' => 'dictionary_word',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Require valid dictionary word node reference';
  $export['import_dictionary_word_additional_entries-dictionary_word-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_additional_entries-part_of_speech-explode';
  $feeds_tamper->importer = 'import_dictionary_word_additional_entries';
  $feeds_tamper->source = 'Part of Speech';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_word_additional_entries-part_of_speech-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_additional_entries-part_of_speech-trim';
  $feeds_tamper->importer = 'import_dictionary_word_additional_entries';
  $feeds_tamper->source = 'Part of Speech';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_word_additional_entries-part_of_speech-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_additional_entries-recording-explode';
  $feeds_tamper->importer = 'import_dictionary_word_additional_entries';
  $feeds_tamper->source = 'Recording';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_word_additional_entries-recording-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_additional_entries-recording-trim';
  $feeds_tamper->importer = 'import_dictionary_word_additional_entries';
  $feeds_tamper->source = 'Recording';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_word_additional_entries-recording-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_additional_entries-sample_sentences-explode';
  $feeds_tamper->importer = 'import_dictionary_word_additional_entries';
  $feeds_tamper->source = 'Sample Sentences';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_word_additional_entries-sample_sentences-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_additional_entries-sample_sentences-trim';
  $feeds_tamper->importer = 'import_dictionary_word_additional_entries';
  $feeds_tamper->source = 'Sample Sentences';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_word_additional_entries-sample_sentences-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_lists-nid-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_word_lists';
  $feeds_tamper->source = 'NID';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'word_list',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid Word List';
  $export['import_dictionary_word_lists-nid-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_lists-nid-trim';
  $feeds_tamper->importer = 'import_dictionary_word_lists';
  $feeds_tamper->source = 'NID';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_word_lists-nid-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_lists-words-explode';
  $feeds_tamper->importer = 'import_dictionary_word_lists';
  $feeds_tamper->source = 'Words';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_word_lists-words-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_lists-words-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_word_lists';
  $feeds_tamper->source = 'Words';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'dictionary_word',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid node reference';
  $export['import_dictionary_word_lists-words-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_word_lists-words-trim';
  $feeds_tamper->importer = 'import_dictionary_word_lists';
  $feeds_tamper->source = 'Words';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_word_lists-words-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-keywords-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-keywords-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-keywords-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-keywords-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-language-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Language';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-language-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-nid-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'dictionary_word',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid dictionary word node reference';
  $export['import_dictionary_words-nid-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-nid-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-nid-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-part_of_speech-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Part of Speech';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-part_of_speech-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-part_of_speech-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Part of Speech';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-part_of_speech-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-protocol-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-protocol-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-protocol-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid cultural protocol node reference';
  $export['import_dictionary_words-protocol-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-protocol-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-protocol-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-recording-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Recording';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-recording-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-recording-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Recording';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-recording-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-related_dictionary_words-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Related Dictionary Words';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-related_dictionary_words-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-related_dictionary_words-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Related Dictionary Words';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'dictionary_word',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid dictionary word node reference';
  $export['import_dictionary_words-related_dictionary_words-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-related_dictionary_words-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Related Dictionary Words';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-related_dictionary_words-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-related_digital_heritage_items-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Related Digital Heritage Items';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-related_digital_heritage_items-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-related_digital_heritage_items-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Related Digital Heritage Items';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid digital heritage node reference';
  $export['import_dictionary_words-related_digital_heritage_items-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-related_digital_heritage_items-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Related Digital Heritage Items';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-related_digital_heritage_items-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-sample_sentences-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Sample Sentences';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-sample_sentences-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-sample_sentences-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Sample Sentences';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-sample_sentences-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-sharing_settings-convert_case';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Sharing Settings';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['import_dictionary_words-sharing_settings-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-word_list-explode';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Word List';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_dictionary_words-word_list-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-word_list-require_valid_node';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Word List';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'word_list',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid node reference';
  $export['import_dictionary_words-word_list-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_dictionary_words-word_list-trim';
  $feeds_tamper->importer = 'import_dictionary_words';
  $feeds_tamper->source = 'Word List';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_dictionary_words-word_list-trim'] = $feeds_tamper;

  return $export;
}
