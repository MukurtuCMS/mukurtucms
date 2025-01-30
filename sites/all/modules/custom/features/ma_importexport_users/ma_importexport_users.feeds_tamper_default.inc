<?php

/**
 * @file
 * ma_importexport_users.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ma_importexport_users_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_communities-nid-require_valid_community';
  $feeds_tamper->importer = 'import_communities';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'community',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid Community';
  $export['import_communities-nid-require_valid_community'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_communities-nid-trim';
  $feeds_tamper->importer = 'import_communities';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_communities-nid-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_communities-parent_community-require_valid_parent_community';
  $feeds_tamper->importer = 'import_communities';
  $feeds_tamper->source = 'Parent Community';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'community',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Require valid Parent Community';
  $export['import_communities-parent_community-require_valid_parent_community'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-group_register-required';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Group Register';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['import_cultural_protocols-group_register-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-name-required';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Name';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['import_cultural_protocols-name-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-nid-require_valid_cultural_protocol';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 1,
    'node_type' => 'cultural_protocol_group',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Require valid Cultural Protocol';
  $export['import_cultural_protocols-nid-require_valid_cultural_protocol'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-nid-trim';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'nid';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['import_cultural_protocols-nid-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-parent_community-explode';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Parent Community';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ';',
    'limit' => '',
    'real_separator' => ';',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['import_cultural_protocols-parent_community-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-parent_community-require_valid_community';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Parent Community';
  $feeds_tamper->plugin_id = 'require_valid_node';
  $feeds_tamper->settings = array(
    'allow_empty' => 0,
    'node_type' => 'community',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Require valid Community Parent';
  $export['import_cultural_protocols-parent_community-require_valid_community'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-parent_community-trim';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Parent Community';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Trim';
  $export['import_cultural_protocols-parent_community-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-sharing_protocol-find_replace';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Sharing Protocol';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'strict',
    'replace' => '2',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 6;
  $feeds_tamper->description = 'Replace \'strict\' with 2';
  $export['import_cultural_protocols-sharing_protocol-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-sharing_protocol-find_replace_open_zero';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Sharing Protocol';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'open',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Replace \'open\' with 0';
  $export['import_cultural_protocols-sharing_protocol-find_replace_open_zero'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_cultural_protocols-sharing_protocol-required';
  $feeds_tamper->importer = 'import_cultural_protocols';
  $feeds_tamper->source = 'Sharing Protocol';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 0,
  );
  $feeds_tamper->weight = 7;
  $feeds_tamper->description = 'Required field';
  $export['import_cultural_protocols-sharing_protocol-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_users-community_affiliations-explode';
  $feeds_tamper->importer = 'import_users';
  $feeds_tamper->source = 'Community Affiliations';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_users-community_affiliations-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_users-community_affiliations-trim';
  $feeds_tamper->importer = 'import_users';
  $feeds_tamper->source = 'Community Affiliations';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['import_users-community_affiliations-trim'] = $feeds_tamper;

  return $export;
}
