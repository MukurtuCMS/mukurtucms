<?php
/**
 * @file
 * Defines mailhandler_comments importer.
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mailcomment_default_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'mailhandler_comments';
  $feeds_importer->config = array(
    'name' => 'Mailhandler comments',
    'description' => 'Imports comments from a Mailhandler mailbox',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'MailhandlerFiltersComments',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'MailhandlerParser',
      'config' => array(
        'if_auth_fails' => 'remove',
        'default_commands' => 'status: 1',
        'command_plugin' => array(
          'MailhandlerCommandsDefault' => 'MailhandlerCommandsDefault',
          'MailhandlerCommandsHeaders' => 'MailhandlerCommandsHeaders',
        ),
        'authenticate_plugin' => 'MailcommentAuthenticate',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'input_format' => 'plain_text',
        'update_existing' => 0,
	'skip_hash_check' => FALSE,
        'expire' => -1,
        'mappings' => array(
          0 => array(
            'source' => 'parent_nid',
            'target' => 'nid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'parent_cid',
            'target' => 'pid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'subject',
            'target' => 'subject',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'body_html',
            'target' => 'comment',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'authenticated_uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
	  5 => array(
	    'source' => 'message_id',
	    'target' => 'guid',
	    'unique' => 1,
	  ),
	  6 => array(
	    'source' => 'status',
	    'target' => 'status',
	    'unique' => FALSE,
	  ),
        ),
        'author' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '900',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['mailhandler_comments'] = $feeds_importer;

  return $export;
}
