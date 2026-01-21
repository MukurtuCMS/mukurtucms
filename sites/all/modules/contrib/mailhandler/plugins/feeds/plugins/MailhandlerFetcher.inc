<?php

/**
 * @file
 * Checks for new messages in a mailbox (IMAP, POP3, etc...).
 */

$plugin = array(
  'name' => 'Mailhandler fetcher',
  'description' => 'Connects to an IMAP/POP mailbox.',
  'handler' => array(
    'parent' => 'FeedsFetcher',
    'class' => 'MailhandlerFetcher',
  ),
);
