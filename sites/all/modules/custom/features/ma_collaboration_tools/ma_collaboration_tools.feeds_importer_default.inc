<?php

/**
 * @file
 * ma_collaboration_tools.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_collaboration_tools_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'mukurtu_comments_via_email_importer';
  $feeds_importer->config = array(
    'name' => 'Mukurtu Comments-via-Email importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'MailhandlerFilters',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'MailhandlerParser',
      'config' => array(
        'authenticate_plugin' => 'MailcommentAuthenticate',
        'available_commands' => 'status',
        'extended_headers' => NULL,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'input_format' => 'plain_text',
        'update_existing' => '2',
        'skip_hash_check' => 0,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'parent_nid',
            'target' => 'nid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'parent_cid',
            'target' => 'pid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'authenticated_uid',
            'target' => 'uid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'message_id',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'body_html',
            'target' => 'subject',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'bundle' => 'comment_node_discussion_space',
        'language' => 'und',
        'authorize' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['mukurtu_comments_via_email_importer'] = $feeds_importer;

  return $export;
}
