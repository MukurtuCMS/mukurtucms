<?php
/**
 * @file
 * MailhandlerAuthenticate class.
 */

/**
 * Base authentication class.
 */
abstract class MailhandlerAuthenticate {

  /**
   * Authenticates an incoming message.
   *
   * @param array $message
   *   Array containing message headers, body, and mailbox information.
   */
  public function authenticate(&$message, $mailbox) {
    $uid = 0;
    return $uid;
  }

}
