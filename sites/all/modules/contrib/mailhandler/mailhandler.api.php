<?php
/**
 * @file
 * Document hooks created by mailhandler.
 */

/**
 * Respond to a parsed message failing authentification.
 *
 * @param array $message
 *   The mail message Feeds was trying to parse.
 */
function hook_mailhandler_auth_failed($message) {
  // Log the failure to Recent Log Entries.
  watchdog('mailhandler', 'User could not be authenticated. Please check your Mailhandler authentication plugin settings.', array(), WATCHDOG_WARNING);
  // Alert the user.
  drupal_set_message(t('Oops, not able to authenticate mail.', array(), 'warning'));
}
