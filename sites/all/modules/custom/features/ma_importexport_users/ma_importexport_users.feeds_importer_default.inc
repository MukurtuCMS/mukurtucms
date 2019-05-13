<?php

/**
 * @file
 * ma_importexport_users.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_importexport_users_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_categories';
  $feeds_importer->config = array(
    'name' => 'Import Categories',
    'description' => 'Import Categories into Mukurtu',
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
          ),
          1 => array(
            'source' => 'Term name',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
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
  $export['import_categories'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_communities';
  $feeds_importer->config = array(
    'name' => 'Import Communities',
    'description' => 'Import Communities into Mukurtu.',
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
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'guid',
            'target' => 'guid',
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
            'source' => 'Description',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Banner Image',
            'target' => 'field_community_image',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Thumbnail Image',
            'target' => 'field_community_image_thumbnail',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Parent Community',
            'target' => 'field_parent_community:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Group Register',
            'target' => 'group_register',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Group Roles',
            'target' => 'og_roles_permissions',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Membership Display',
            'target' => 'field_membership_list_options',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'authorize' => 1,
        'update_non_existent' => 'skip',
        'skip_hash_check' => 0,
        'bundle' => 'community',
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
  $export['import_communities'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_cultural_protocols';
  $feeds_importer->config = array(
    'name' => 'Import Cultural Protocols',
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
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'guid',
            'target' => 'guid',
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
            'source' => 'Sharing Protocol',
            'target' => 'group_access',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Parent Community',
            'target' => 'field_parent_community:guid_or_target_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Description',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Banner Image',
            'target' => 'field_protocol_image',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Thumbnail Image',
            'target' => 'field_protocol_image_thumbnail',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Auto Add Users',
            'target' => 'field_protocol_auto_join',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Group Register',
            'target' => 'group_register',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Membership Display',
            'target' => 'field_membership_list_options',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'authorize' => 1,
        'update_non_existent' => 'skip',
        'skip_hash_check' => 0,
        'bundle' => 'cultural_protocol_group',
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
  $export['import_cultural_protocols'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_users';
  $feeds_importer->config = array(
    'name' => 'Import Users',
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
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          4 => 0,
          5 => 0,
          7 => 0,
          6 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Name',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Language',
            'target' => 'language',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 0,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'E-mail',
            'target' => 'mail',
            'unique' => 0,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Created date',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => 1,
        'input_format' => 'plain_text',
        'insert_new' => 1,
        'update_non_existent' => 'skip',
        'skip_hash_check' => FALSE,
        'bundle' => 'user',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['import_users'] = $feeds_importer;

  return $export;
}
