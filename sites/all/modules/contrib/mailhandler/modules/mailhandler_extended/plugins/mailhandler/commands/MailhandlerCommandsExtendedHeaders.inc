<?php
/**
 * @file
 * MailhandlerCommandsExtendedHeaders class.
 */

$plugin = array(
  'name' => 'Extended headers processor',
  'description' => 'Provides arbitrary IMAP headers as mapping sources.',
  'handler' => array(
    'class' => 'MailhandlerCommandsExtendedHeaders',
    'parent' => 'MailhandlerCommandsHeaders',
  ),
  'file' => 'MailhandlerCommandsExtendedHeaders.class.php',
  'weight' => 0,
);
