<?php

/**
 * A mail sending implementation that captures sent messages to a variable.
 *
 * @see https://www.drupal.org/node/2279851
 */
class oaTestingMailSystem extends DefaultMailSystem implements MailSystemInterface {
  /**
   * Accept an e-mail message and store it in a variable.
   *
   * @param $message
   *   An e-mail message.
   */
  public function mail(array $message) {
    $captured_emails = variable_get('drupal_test_email_collector', array());
    // Remove objects so they don't fatal on varialize initlization.
    foreach ($message['params'] as $key => $param) {
      if (is_object($param) && get_class($param) !== 'stdClass') {
        unset($message['params'][$key]);
      }
    }
    $captured_emails[] = $message;
    variable_set('drupal_test_email_collector', $captured_emails);
    return TRUE;
  }
}
