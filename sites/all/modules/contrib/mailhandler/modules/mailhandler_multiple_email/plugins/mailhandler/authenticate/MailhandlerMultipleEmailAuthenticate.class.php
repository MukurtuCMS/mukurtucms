<?php
/**
 * @file
 * MailhandlerMultipleEmailAuthenticate  class.
 */

/**
 * Integrates with Multiple Email module.
 */
class MailhandlerMultipleEmailAuthenticate extends MailhandlerAuthenticate {

  /**
   * Implements authenticate().
   */
  public function authenticate(&$message, $mailbox) {
    list($fromaddress,) = _mailhandler_get_fromaddress($message['header'], $mailbox);
    $uid = 0;
    if ($address = multiple_email_find_address($fromaddress)) {
      $uid = $address->uid;
    }
    return $uid;
  }
}
