<?php
/**
 * @file
 * MailcommentAuthenticate class.
 */

/**
 * Authenticates messages based on unique signatures embedded in the body and headers of emails.
 */
class MailcommentAuthenticate extends MailhandlerAuthenticate {

  public function authenticate(&$message, $mailbox) {
    $uid = 0;
    // Check and parse messageid for parameters.  URL will be encoded.
    $force_user_lookup = FALSE;
    $identifier = _mailcomment_get_signature(rawurldecode($message['body_html']));
    // Failed to find signature in body -- replicate mailhandler functionality to find node->threading
    if (!$identifier) {
      if (!empty($message['header']->references)) {
        // we want the final element in references header, watching out for white space
        $identifier = drupal_substr(strrchr($message['header']->references, '<'), 0);
      }
      elseif (!empty($message['header']->in_reply_to)) {
        // Some MUAs send more info in this header.
        $identifier = str_replace(strstr($message['header']->in_reply_to, '>'), '>', $message['header']->in_reply_to);
      }
      if (isset($identifier)) {
        $identifier = rtrim(ltrim($identifier, '<'), '>');
        $force_user_lookup = TRUE;
      }
    }
    $params = mailcomment_check_messageparams($identifier);

    if ($force_user_lookup) {
      // get uid from email address because we are using the header information to load the params
      // these contain the uid of the person who's post you are responding to
      $sender = $message['header']->from[0]->mailbox . '@' . $message['header']->from[0]->host;
      $params['uid'] =  user_load_by_mail($sender)->uid;
    }

    if ($params['uid']) {
      $account = user_load($params['uid']);
      $uid = $account->uid;
    }

    return $uid;
  }
}
