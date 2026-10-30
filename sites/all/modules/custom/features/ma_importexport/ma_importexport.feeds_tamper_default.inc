<?php

/**
 * @file
 * ma_importexport.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ma_importexport_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-book_pages-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Book Pages';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-book_pages-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-book_pages-require_valid_book_pages';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Book Pages';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Book Pages';
  $export['digital_heritage_metadata-book_pages-require_valid_book_pages'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-book_pages-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Book Pages';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-book_pages-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-category-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Category';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-category-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-category-required';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Category';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['digital_heritage_metadata-category-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-category-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Category';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-category-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-collections-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Collections';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-collections-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-collections-require_valid_collection';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Collections';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'collection',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Collection';
  $export['digital_heritage_metadata-collections-require_valid_collection'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-collections-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Collections';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-collections-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-communities-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Communities';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ',',
    'separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-communities-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-communities-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Communities';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-communities-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-community_record_parent-require_valid_community_record_p';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Community Record Parent';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Require valid Community Record Parent';
  $export['digital_heritage_metadata-community_record_parent-require_valid_community_record_p'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-community_records-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Community Records';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-community_records-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-community_records-require_valid_community_records';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Community Records';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Community Records';
  $export['digital_heritage_metadata-community_records-require_valid_community_records'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-community_records-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Community Records';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-community_records-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-contributor-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Contributor';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-contributor-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-contributor-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Contributor';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-contributor-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-creator-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Creator';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-creator-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-creator-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Creator';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-creator-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-cultural_protocols-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Cultural Protocols';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ',',
    'separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-cultural_protocols-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-cultural_protocols-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Cultural Protocols';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-cultural_protocols-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-format-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Format';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-format-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-format-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Format';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-format-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-keywords-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-keywords-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-keywords-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-keywords-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-language-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Language';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-language-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-language-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Language';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-language-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-media-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Media';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ',',
    'separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-media-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-media-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Media';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-media-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-media_assets-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Media Assets';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-media_assets-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-media_assets-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Media Assets';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-media_assets-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-media_internet-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Media Internet';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ',',
    'separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-media_internet-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-media_internet-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Media Internet';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-media_internet-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-nid-require_valid_digital_heritage';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid digital heritage node';
  $export['digital_heritage_metadata-nid-require_valid_digital_heritage'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-nid-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-nid-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-people-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-people-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-people-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-people-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-publisher-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Publisher';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-publisher-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-publisher-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Publisher';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-publisher-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-related_items-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Related Items';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-related_items-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-related_items-require_valid_related_items';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Related Items';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Related Items';
  $export['digital_heritage_metadata-related_items-require_valid_related_items'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-related_items-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Related Items';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-related_items-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-sharing_protocols-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-sharing_protocols-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-sharing_protocols-require_valid_cultural_protocol';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Require valid Cultural Protocol';
  $export['digital_heritage_metadata-sharing_protocols-require_valid_cultural_protocol'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-sharing_protocols-required';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['digital_heritage_metadata-sharing_protocols-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-sharing_protocols-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-sharing_protocols-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-sharing_settings-convert_case';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Sharing Settings';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['digital_heritage_metadata-sharing_settings-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-sharing_settings-required';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Sharing Settings';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['digital_heritage_metadata-sharing_settings-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-subject-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Subject';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-subject-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-subject-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Subject';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-subject-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-title-required';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'title';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['digital_heritage_metadata-title-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-traditional_licensing_url-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Traditional Licensing URL';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-traditional_licensing_url-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-traditional_licensing_url-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Traditional Licensing URL';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-traditional_licensing_url-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-type-explode';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Type';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['digital_heritage_metadata-type-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'digital_heritage_metadata-type-trim';
  $feeds_tamper->importer = 'digital_heritage_metadata';
  $feeds_tamper->source = 'Type';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['digital_heritage_metadata-type-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-book_pages-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Book Pages';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-book_pages-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-book_pages-require_valid_book_pages';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Book Pages';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Book Pages';
  $export['import_digital_heritage_community_records-book_pages-require_valid_book_pages'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-book_pages-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Book Pages';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-book_pages-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-category-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Category';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-category-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-category-required';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Category';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['import_digital_heritage_community_records-category-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-category-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Category';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-category-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-collections-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Collections';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-collections-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-collections-require_valid_collection';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Collections';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'collection',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Collection';
  $export['import_digital_heritage_community_records-collections-require_valid_collection'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-collections-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Collections';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-collections-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-community_record_parent-require_valid_node';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Community Record Parent';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 0,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid community record parent';
  $export['import_digital_heritage_community_records-community_record_parent-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-community_record_parent-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Community Record Parent';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-community_record_parent-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-contributor-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Contributor';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-contributor-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-contributor-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Contributor';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-contributor-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-creator-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Creator';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-creator-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-creator-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Creator';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-creator-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-keywords-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-keywords-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-keywords-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-keywords-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-language-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Language';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-language-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-language-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Language';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-language-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-media_assets-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Media Assets';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-media_assets-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-media_assets-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Media Assets';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-media_assets-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-nid-require_valid_digital_heritage';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid digital heritage node';
  $export['import_digital_heritage_community_records-nid-require_valid_digital_heritage'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-nid-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-nid-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-people-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-people-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-people-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-people-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-publisher-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Publisher';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-publisher-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-publisher-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Publisher';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-publisher-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-related_items-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Related Items';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-related_items-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-related_items-require_valid_related_items';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Related Items';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'digital_heritage',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Related Items';
  $export['import_digital_heritage_community_records-related_items-require_valid_related_items'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-related_items-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Related Items';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-related_items-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-sharing_protocols-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-sharing_protocols-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-sharing_protocols-require_valid_cultural_protocol';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Require valid Cultural Protocol';
  $export['import_digital_heritage_community_records-sharing_protocols-require_valid_cultural_protocol'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-sharing_protocols-required';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['import_digital_heritage_community_records-sharing_protocols-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-sharing_protocols-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Sharing Protocols';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-sharing_protocols-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-sharing_settings-convert_case';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Sharing Settings';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['import_digital_heritage_community_records-sharing_settings-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-sharing_settings-required';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Sharing Settings';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['import_digital_heritage_community_records-sharing_settings-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-subject-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Subject';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-subject-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-subject-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Subject';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-subject-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-title-required';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'title';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['import_digital_heritage_community_records-title-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-traditional_licensing_url-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Traditional Licensing URL';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-traditional_licensing_url-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-traditional_licensing_url-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Traditional Licensing URL';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-traditional_licensing_url-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-type-explode';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Type';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_digital_heritage_community_records-type-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_digital_heritage_community_records-type-trim';
  $feeds_tamper->importer = 'import_digital_heritage_community_records';
  $feeds_tamper->source = 'Type';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_digital_heritage_community_records-type-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-authors-explode';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_audio-authors-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-authors-trim';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_audio-authors-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-contributors-explode';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Contributors';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_audio-contributors-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-contributors-trim';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Contributors';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_audio-contributors-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-file-required';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'File';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['import_media_audio-file-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-people-explode';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_audio-people-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-people-trim';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_audio-people-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-protocol-explode';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_audio-protocol-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-protocol-require_valid_node';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Protocol';
  $export['import_media_audio-protocol-require_valid_node'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-protocol-trim';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_audio-protocol-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-tags-explode';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Tags';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_audio-tags-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_audio-tags-trim';
  $feeds_tamper->importer = 'import_media_audio';
  $feeds_tamper->source = 'Tags';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_audio-tags-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-authors-explode';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_files-authors-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-authors-strtotime';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = '';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['import_media_files-authors-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-authors-trim';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Trim';
  $export['import_media_files-authors-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-file-required';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'File';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['import_media_files-file-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-people-explode';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_files-people-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-people-trim';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_files-people-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-protocol-explode';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_files-protocol-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-protocol-require_valid_protocol';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Protocol';
  $export['import_media_files-protocol-require_valid_protocol'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-protocol-trim';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_files-protocol-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-tags-explode';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Tags';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_files-tags-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_files-tags-trim';
  $feeds_tamper->importer = 'import_media_files';
  $feeds_tamper->source = 'Tags';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_files-tags-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-authors-explode';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_images-authors-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-authors-trim';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_images-authors-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-categories-explode';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Categories';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_images-categories-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-categories-trim';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Categories';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_images-categories-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-image-required';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Image';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Required field';
  $export['import_media_images-image-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-keywords-explode';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_images-keywords-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-keywords-trim';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Keywords';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_images-keywords-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-people-explode';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_images-people-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-people-trim';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_images-people-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-protocol-explode';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_images-protocol-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-protocol-require_valid_protocol';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Protocol';
  $export['import_media_images-protocol-require_valid_protocol'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_images-protocol-trim';
  $feeds_tamper->importer = 'import_media_images';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_images-protocol-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-authors-explode';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_video-authors-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-authors-trim';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'Authors';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_video-authors-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-file-required';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'File';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Required field';
  $export['import_media_video-file-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-people-explode';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_video-people-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-people-trim';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'People';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_video-people-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-protocol-explode';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_video-protocol-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-protocol-require_valid_protocol';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Require valid Protocol';
  $export['import_media_video-protocol-require_valid_protocol'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-protocol-trim';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'Protocol';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_video-protocol-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-tags-explode';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'Tags';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_media_video-tags-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_media_video-tags-trim';
  $feeds_tamper->importer = 'import_media_video';
  $feeds_tamper->source = 'Tags';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_media_video-tags-trim'] = $feeds_tamper;

  return $export;
}
