<?php
/**
 * @file
 * MailhandlerAuthenticateDefault class.
 */

/**
 * Default authentication mechanism.
 */
class MailhandlerAuthenticateDefault extends MailhandlerAuthenticate {

  /**
   * Implements authenticate().
   */
  public function authenticate(&$message, $mailbox) {
    list($fromaddress, ) = _mailhandler_get_fromaddress($message['header'], $mailbox);
    $uid = 0;
    if ($from_user = user_load_by_mail($fromaddress)) {
      $uid = $from_user->uid;
    }
    return $uid;
  }

}
