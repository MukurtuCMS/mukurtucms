<?php
/**
 * @file
 * mailhandler_default.mailhandler_mailbox.inc
 */

/**
 * Implements hook_default_mailhandler_mailbox().
 */
function mailhandler_default_default_mailhandler_mailbox() {
  $export = array();

  $mailbox = new stdClass();
  $mailbox->disabled = FALSE; /* Edit this to true to make a default mailbox disabled initially */
  $mailbox->api_version = 2;
  $mailbox->mail = 'test_mailbox';
  $mailbox->admin_title = 'Test mailbox';
  $mailbox->settings = array(
    'type' => 'local',
    'folder' => 'sites/all/modules/mailhandler/tests/mbox/test1',
    'domain' => '',
    'port' => '',
    'insecure' => 1,
    'name' => '',
    'pass' => '',
    'extraimap' => '',
    'limit' => '0',
    'encoding' => 'UTF-8',
    'flag_after_read' => 1,
    'delete_after_read' => 0,
    'fromheader' => 'From',
    'security' => '0',
    'replies' => '0',
    'retrieve' => 'MailhandlerPhpImapRetrieve',
    'readonly' => 1,
  );
  $export['test_mailbox'] = $mailbox;

  return $export;
}
