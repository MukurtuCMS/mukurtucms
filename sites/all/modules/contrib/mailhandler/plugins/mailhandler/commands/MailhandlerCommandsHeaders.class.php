<?php
/**
 * @file
 * MailhandlerCommandsHeaders class.
 */

/**
 * Provides commands for basic headers.
 */
class MailhandlerCommandsHeaders extends MailhandlerCommands {

  /**
   * Set known sources and parse additional sources from body.
   */
  public function process(&$message, $source) {
    // Populate $message with all values from 'header' object.
    $parts = (array) $message['header'];
    foreach ($parts as $key => $value) {
      // Some keys are already taken, so do not overwrite them.
      if (!in_array($key, array('header', 'body_text', 'body_html', 'mimeparts', 'mailbox', 'attachments'))) {
        // Some headers are arrays of objects.
        if (in_array($key, array('to', 'from', 'reply_to', 'sender', 'cc', 'bcc', 'return_path'))) {
          $message[$key . '-name'] = array();
          $message[$key . '-address'] = array();
          $message[$key . '-mailbox'] = array();
          $message[$key . '-host'] = array();
          foreach ($value as $valkey => $val) {
            $message[$key . '-name'][$valkey] = isset($val->personal) ? iconv_mime_decode($val->personal, 0, "UTF-8") : '';
            $message[$key . '-address'][$valkey] = (isset($val->mailbox) && isset($val->host)) ? $val->mailbox . '@' . $val->host : '';
            $message[$key . '-mailbox'] = isset($val->mailbox) ? $val->mailbox : '';
            $message[$key . '-host'] = isset($val->host) ? $val->host : '';
          }
        }
        else {
          $message[$key] = iconv_mime_decode($value, 0, "UTF-8");
        }
      }
    }
  }

  /**
   * Return mapping sources.
   */
  public function getMappingSources($config) {
    $sources = array();
    // Make all IMAP header keys available as selectable mapping sources.
    $sources['date'] = array(
      'name' => t('Date (date)'),
      'description' => t('The message date as found in its headers, e.g., Wed, 16 Nov 2011 09:12:29 -0600.'),
    );
    $sources['udate'] = array(
      'name' => t('Date (udate)'),
      'description' => t('The message date in Unix time, e.g., 12345678.'),
    );
    $sources['subject'] = array(
      'name' => t('Subject'),
      'description' => t('The message subject.'),
    );
    $sources['message_id'] = array(
      'name' => t('Message ID'),
      'description' => t('The message ID (message_id), e.g., <testmessage1@example.com>.'),
    );
    $sources['Msgno'] = array(
      'name' => t('Message number'),
      'description' => t('The message number.'),
    );
    $sources['toaddress'] = array(
      'name' => t('To address line'),
      'description' => t('Full To: line, up to 1024 characters, e.g., Joe Smith <joe@example.com>.'),
    );
    $sources['fromaddress'] = array(
      'name' => t('From address line'),
      'description' => t('Full From: line, up to 1024 characters, e.g., Joe Smith <joe@example.com>.'),
    );
    $sources['reply_toaddress'] = array(
      'name' => t('Reply-To address line'),
      'description' => t('Full Reply-To: line, up to 1024 characters, e.g., Joe Smith <joe@example.com>.'),
    );
    $sources['senderaddress'] = array(
      'name' => t('Sender address line'),
      'description' => t('Full Sender: line, up to 1024 characters, e.g., Joe Smith <joe@example.com>.'),
    );
    $sources['ccaddress'] = array(
      'name' => t('CC address line'),
      'description' => t('Full CC: line, up to 1024 characters, e.g., Joe Smith <joe@example.com>.'),
    );
    $sources['bccaddress'] = array(
      'name' => t('BCC address line'),
      'description' => t('Full BCC: line, up to 1024 characters, e.g., Joe Smith <joe@example.com>.'),
    );
    $sources['Recent'] = array(
      'name' => t('Recent flag'),
      'description' => t("R if recent and seen, N if recent and not seen, ' ' if not recent."),
    );
    $sources['Unseen'] = array(
      'name' => t('Unseen flag'),
      'description' => t("U if not seen AND not recent, ' ' if seen OR not seen and recent."),
    );
    $sources['Flagged'] = array(
      'name' => t('Flagged flag'),
      'description' => t("F if flagged, ' ' if not flagged."),
    );
    $sources['Answered'] = array(
      'name' => t('Answered flag'),
      'description' => t("A if answered, ' ' if unanswered."),
    );
    $sources['Deleted'] = array(
      'name' => t('Deleted flag'),
      'description' => t("D if deleted, ' ' if not deleted."),
    );
    $sources['Draft'] = array(
      'name' => t('Draft flag'),
      'description' => t("X if draft, ' ' if not draft."),
    );
    $sources['Size'] = array(
      'name' => t('Message size'),
      'description' => t('Message size.'),
    );
    $parts = array(
      'to',
      'from',
      'reply_to',
      'sender',
      'cc',
      'bcc',
      'return_path',
    );
    foreach ($parts as $part) {
      $sources[$part . '-name'] = array(
        'name' => t($part . ' name'),
        'description' => t($part . " header 'personal' property, e.g., Joe Smith"),
      );
      $sources[$part . '-address'] = array(
        'name' => t($part . ' address'),
        'description' => t($part . " header 'mailbox' and 'host' properties, e.g., joe@example.com"),
      );
      $sources[$part . '-mailbox'] = array(
        'name' => t($part . ' mailbox'),
        'description' => t($part . " header 'mailbox' property, e.g., joe"),
      );
      $sources[$part . '-host'] = array(
        'name' => t($part . ' host'),
        'description' => t($part . " header 'host' property, e.g., example.com"),
      );
    }
    return $sources;
  }
}
