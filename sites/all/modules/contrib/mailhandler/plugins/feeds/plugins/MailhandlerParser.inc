<?php
/**
 * @file
 * MailhandlerParser class.
 */

$plugin = array(
  'name' => 'Mailhandler IMAP stream parser',
  'description' => 'Parses an IMAP stream.',
  'handler' => array(
    'parent' => 'FeedsParser',
    'class' => 'MailhandlerParser',
  ),
);
