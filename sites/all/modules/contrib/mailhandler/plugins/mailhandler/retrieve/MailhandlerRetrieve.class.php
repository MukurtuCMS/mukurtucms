<?php
/**
 * @file
 * Definition of MailhandlerRetrieve class.
 */

/**
 * Retrieve messages from a Mailhandler Mailbox.
 */
abstract class MailhandlerRetrieve {

  /**
   * Connect to mailbox and run message retrieval.
   *
   * @param array $mailbox
   *   Array of mailbox configuration.
   * @param string $filter_name
   *   Mailhandler filter to restrict what messages are retrieved.
   */
  public function retrieve($mailbox, $filter_name = 'MailhandlerFilters') {
  }

  /**
   * Test connection.
   */
  public function test($mailbox) {
    return array();
  }

  /**
   * Purge given message.
   */
  public function purge_message($mailbox, $message) {
  }
}
