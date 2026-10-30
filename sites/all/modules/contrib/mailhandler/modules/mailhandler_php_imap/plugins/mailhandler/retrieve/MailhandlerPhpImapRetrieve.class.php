<?php
/**
 * @file
 * Definition of MailhandlerPhpImapRetrieve class.
 */

/**
 * Retrieve messages using PHP IMAP library.
 */
class MailhandlerPhpImapRetrieve extends MailhandlerRetrieve {
  private $suppress_errors = FALSE;

  /**
   * Connect to mailbox and run message retrieval.
   *
   * @param object $mailbox
   *   The mailbox to retrieve from.
   * @param string|null $filter_name
   *   (optional) Mailhandler filter to restrict what messages are retrieved.
   *
   * @return array
   *   Retrieved messages.
   */
  public function retrieve($mailbox, $filter_name = 'MailhandlerFilters') {
    extract($mailbox->settings);
    if (!($result = $this->open_mailbox($mailbox))) {
      mailhandler_report('error', 'Unable to connect to %mail. Please check the <a href="@mailbox-edit">connection settings</a> for this mailbox.', array('%mail' => $mailbox->mail, '@mailbox-edit' => url(MAILHANDLER_MENU_PREFIX . '/mailhandler/list/' . $mailbox->mail . '/edit')));
      $this->report_errors($mailbox);
    }
    $new = $this->get_unread_messages($result, $mailbox);
    $messages = array();
    $retrieved = 0;
    while ($new && (!$limit || $retrieved < $limit)) {
      if (!($message = $this->retrieve_message($result, $mailbox, array_shift($new), $filter_name))) {
        continue;
      }
      $messages[] = $message;
      $retrieved++;
    }
    mailhandler_report('status', 'Mailbox %mail was checked and contained %retrieved messages.', array('%mail' => $mailbox->admin_title, '%retrieved' => $retrieved));
    $this->close_mailbox($result, $mailbox);
    return $messages;
  }

  /**
   * Test connection to a mailbox.
   *
   * @param object $mailbox
   *   The mailbox to test.
   *
   * @return array
   *   Test results.
   */
  public function test($mailbox) {
    extract($mailbox->settings);
    $ret = array();

    $this->suppress_errors = TRUE;

    $is_local = ($type == 'local');
    $folder_is_set = (!empty($folder) && $folder != 'INBOX');
    $connect_is_set = !empty($domain) && !empty($port) && !empty($name) && !empty($pass);

    if (($is_local && $folder_is_set) || (!$is_local && $connect_is_set)) {
      if (!($result = $this->open_mailbox($mailbox))) {
        $errors = imap_errors();
        foreach ($errors as $error) {
          $ret[] = array('severity' => 'error', 'message' => t($error));
        }
        $ret[] = array('severity' => 'error', 'message' => t('Mailhandler could not access the mailbox using these settings'));
        return $ret;
      }
      $ret[] = array('severity' => 'status', 'message' => t('Mailhandler was able to connect to the mailbox.'));
      $box = $this->mailbox_string($mailbox);
      $box = ltrim($box, '/');
      $status = imap_status($result, $box, SA_MESSAGES);
      if ($status) {
        $ret[] = array('severity' => 'status', 'message' => t('There are @messages messages in the mailbox folder.', array('@messages' => $status->messages)));
      }
      else {
        $ret[] = array('severity' => 'warning', 'message' => t('Mailhandler could not open the mailbox.'));
      }
      $this->close_mailbox($result, $mailbox);
    }
    return $ret;
  }

  /**
   * Purge (mark as read or delete) a message.
   *
   * @param object $mailbox
   *   Mailbox configuration.
   * @param array $message
   *   Message to purge.
   */
  public function purge_message($mailbox, $message) {
    if (!isset($message['imap_uid'])) {
      return;
    }
    if (!($result = $this->open_mailbox($mailbox))) {
      mailhandler_report('error', 'Unable to connect to %mail. Following errors may provide details.', array('%mail' => $mailbox->mail));
      $this->report_errors($mailbox);
    }
    if ($mailbox->settings['delete_after_read']) {
      imap_delete($result, $message['imap_uid'], FT_UID);
    }
    elseif (!isset($mailbox->settings['flag_after_read']) || ($mailbox->settings['flag_after_read'])) {
      imap_setflag_full($result, (string) $message['imap_uid'], '\Seen', FT_UID);
    }
    $this->close_mailbox($result, $mailbox);
  }

  /**
   * Establish IMAP stream connection to specified mailbox.
   *
   * @param array $mailbox
   *   Mailbox configuration.
   *
   * @return resource|false
   *   IMAP stream.
   */
  public function open_mailbox($mailbox) {
    extract($mailbox->settings);

    if (!function_exists('imap_open')) {
      mailhandler_report('error', 'The PHP IMAP extension must be enabled in order to use Mailhandler.');
    }
    $box = $this->mailbox_string($mailbox);
    if ($type != 'local') {
      $result = imap_open($box, $name, $pass, NULL, 1);
    }
    else {
      // This is a local mbox.
      // Change HOME to work around php_imap access restrictions.
      $orig_home = getenv('HOME');
      if (strpos($box, '/') === 0) {
        $new_home = '/';
        $box = ltrim($box, '/');
      }
      else {
        // This is hackish, but better than using $_SERVER['DOCUMENT_ROOT']
        $new_home = realpath(drupal_get_path('module', 'node') . '/../../');
      }
      if (!putenv("HOME=$new_home")) {
        mailhandler_error('error', 'Could not set home directory to %home.', array('%home' => $new_home));
      }
      $result = imap_open($box, '', '', NULL, 1);
      // Restore HOME directory.
      putenv("HOME=$orig_home");
    }
    return $result;
  }

  /**
   * Constructs a mailbox string based on mailbox object.
   */
  public function mailbox_string($mailbox) {
    extract($mailbox->settings);

    switch ($type) {
      case 'imap':
        return '{' . $domain . ':' . $port . $extraimap . '}' . $folder;

      case 'pop3':
        return '{' . $domain . ':' . $port . '/pop3' . $extraimap . '}' . $folder;

      case 'local':
        $box = ltrim($folder, '/');
        if ($readonly) {
          // Copy mbox to avoid modifying original.
          $source = $box;
          $destination = 'temporary://';
          $replace = FILE_EXISTS_REPLACE;
          $path = file_unmanaged_copy($source, $destination, $replace);
          $box = drupal_realpath($path);
        }
        return $box;
    }
  }

  /**
   * Returns an array of parts as file objects.
   *
   * @param object $stream
   *   The IMAP stream.
   * @param int $msg_number
   *   The message number.
   *
   * @return array
   *   An array of message parts (text body, html body, and attachments).
   */
  public function get_parts($stream, $msg_number) {
    $parts = array('text_body' => '', 'html_body' => '', 'attachments' => array());

    // Load structure.
    if (!($structure = imap_fetchstructure($stream, $msg_number))) {
      mailhandler_report('error', 'Could not fetch structure for message number %msg_number', array('%msg_number' => $msg_number));
    }

    // Get message parts.
    if ($structure->type == TYPEMULTIPART) {
      // Multi-part message.\r
      foreach ($structure->parts as $index => $sub_structure) {
        $this->get_part($stream, $msg_number, $sub_structure, $index + 1, $parts);
      }
    }
    else {
      // Single-part message.
      $this->get_part($stream, $msg_number, $structure, FALSE, $parts);
    }
    return $parts;
  }

  /**
   * Gets a message part and adds it to $parts.
   *
   * @param object $stream
   *   The IMAP stream from which to fetch data.
   * @param int $msg_number
   *   The message number.
   * @param object $structure
   *   The structure definition.
   * @param int $part_number
   *   The part number to add.
   * @param array $parts
   *   The array of added parts.
   */
  public function get_part($stream, $msg_number, $structure, $part_number, &$parts) {
    // Get data.
    $data = '';
    if ($part_number) {
      $data = imap_fetchbody($stream, $msg_number, $part_number, FT_PEEK);
    }
    else {
      $data = imap_body($stream, $msg_number, FT_PEEK);
    }

    // Get params.
    $params = array();
    if ($structure->ifparameters) {
      foreach ($structure->parameters as $parameter) {
        $params[drupal_strtolower($parameter->attribute)] = $parameter->value;
      }
    }
    if ($structure->ifdparameters) {
      foreach ($structure->dparameters as $parameter) {
        $params[drupal_strtolower($parameter->attribute)] = $parameter->value;
      }
    }

    $charset = 'auto';
    if (isset($params['charset'])) {
      $charset = $params['charset'];
    }

    // Decode data.
    switch ($structure->encoding) {
      case ENCQUOTEDPRINTABLE:
        $data = quoted_printable_decode($data);
        // Properly decode most Microsoft encodings (Hotmail and Windows).
        $data = drupal_convert_to_utf8($data, $charset);
        break;

      case ENCBASE64:
        $data = base64_decode($data);
        break;

      case ENC7BIT:
      case ENC8BIT:
        $data = imap_utf8($data);
        // Properly decode most Microsoft encodings (Hotmail and Windows).
        $data = drupal_convert_to_utf8($data, $charset);
        break;
    }

    // Get attachments.
    foreach ($params as $attribute => $value) {
      switch ($attribute) {
        case 'filename':
        case 'name':
          $attachment = new stdClass();
          $attachment->filename = $value;
          $attachment->data = $data;
          if (isset($structure->id)) {
            $attachment->id = $structure->id;
          }
          if (!$attachment->filemime = $this->get_mime_type($structure)) {
            mailhandler_report('warning', 'Could not fetch mime type for message part. Defaulting to application/octet-stream.');
            $attachment->filemime = 'application/octet-stream';
          }
          $parts['attachments'][] = $attachment;
          break 2;
      }
    }

    // Get bodies.
    if (($structure->type == TYPETEXT || $structure->type == TYPEMESSAGE) && $data) {
      // Messages may be split in different parts because of inline attachments,
      // so append parts together with blank row.
      if (drupal_strtolower($structure->subtype) == 'plain') {
        $parts['text_body'] .= trim($data);
      }
      else {
        $parts['html_body'] .= $data;
      }
    }

    // Recurse for multi-part messages.
    if ($structure->type = TYPEMULTIPART && isset($structure->parts)) {
      foreach ($structure->parts as $index => $sub_structure) {
        $this->get_part($stream, $msg_number, $sub_structure, $part_number . '.' . ($index + 1), $parts);
      }
    }
  }

  /**
   * Retrieve MIME type of the message structure.
   */
  public function get_mime_type(&$structure) {
    static $primary_mime_type = array('text', 'multipart', 'message', 'application', 'audio', 'image', 'video', 'other');
    $type_id = (int) $structure->type;
    if (isset($primary_mime_type[$type_id]) && !empty($structure->subtype)) {
      return $primary_mime_type[$type_id] . '/' . drupal_strtolower($structure->subtype);
    }
    return 'text/plain';
  }

  /**
   * Obtain the number of unread messages for an imap stream.
   *
   * @param object $result
   *   IMAP stream - as opened by imap_open
   * @param object $mailbox
   *   The mailbox to retrieve from.
   *
   * @return array
   *   IMAP message numbers of unread messages.
   */
  public function get_unread_messages($result, $mailbox) {
    $unread_messages = array();
    $number_of_messages = imap_num_msg($result);
    for ($i = 1; $i <= $number_of_messages; $i++) {
      $header = imap_headerinfo($result, $i);
      if ($header->Unseen == 'U' || $header->Recent == 'N') {
        $unread_messages[] = $i;
      }
    }
    return $unread_messages;
  }

  /**
   * Retrieve individual messages from an IMAP result.
   *
   * @param object $result
   *   IMAP stream.
   * @param object $mailbox
   *   Mailbox to retrieve from.
   * @param int $msg_number
   *   IMAP message number.
   * @param string $filter_name
   *   Mailhandler Filter plugin to use.
   *
   * @return array|false
   *   Retrieved message, or FALSE if message cannot / should not be retrieved.
   */
  public function retrieve_message($result, $mailbox, $msg_number, $filter_name) {
    extract($mailbox->settings);
    $header = imap_headerinfo($result, $msg_number);
    // Check to see if we should retrieve this message at all.
    if ($filter = mailhandler_plugin_load_class('mailhandler', $filter_name, 'filters', 'handler')) {
      if (!$filter->fetch($header)) {
        return FALSE;
      }
    }
    // Initialize the subject in case it's missing.
    if (!isset($header->subject)) {
      $header->subject = '';
    }

    // Parse MIME parts.
    $parts = $this->get_parts($result, $msg_number);
    $message = FALSE;
    // Is this an empty message with no body and no mimeparts?
    if (!empty($parts)) {
      $imap_uid = ($type == 'pop3') ? $this->fetch_uid($mailbox, $msg_number) : imap_uid($result, $msg_number);
      $message = compact('header', 'imap_uid');
      $message['body_text'] = ($parts['text_body']) ? $parts['text_body'] : $parts['html_body'];
      $message['body_html'] = ($parts['html_body']) ? $parts['html_body'] : $parts['text_body'];
      $message['mimeparts'] = $parts['attachments'];
    }
    return $message;
  }

  /**
   * Close a mailbox.
   */
  public function close_mailbox($result, $mailbox) {
    $this->report_errors($mailbox);
    imap_close($result, CL_EXPUNGE);
  }

  /**
   * Fetch UID for a message in a POP mailbox.
   *
   * Taken from PHP.net.
   */
  public function fetch_uid($mailbox, $msg_number) {
    extract($mailbox->settings);
    $retval = 0;
    $fp = fsockopen($domain, $port);
    if ($fp > 0) {
      $buf = fgets($fp, 1024);
      fwrite($fp, "USER $name\r\n");
      $buf = fgets($fp, 1024);
      fwrite($fp, "PASS $pass\r\n");
      $buf = fgets($fp, 1024);
      fwrite($fp, "UIDL $msg_number\r\n");
      $retval = fgets($fp, 1024);
      fwrite($fp, "QUIT\r\n");
      $buf = fgets($fp, 1024);
      fclose($fp);
    }
    return drupal_substr($retval, 6, 30);
  }

  /**
   * Capture and report IMAP errors.
   */
  public function report_errors($mailbox) {
    // Need to be able to suppress errors when we are testing from an AJAX call.
    // Otherwise we get nasty AJAX dialogs.
    if (!$this->suppress_errors) {
      $errors = imap_errors();
      if ($errors) {
        list(, $caller) = debug_backtrace(FALSE);
        $function = $caller['function'];
        foreach ($errors as $error) {
          if ($error == "SECURITY PROBLEM: insecure server advertised AUTH=PLAIN" && $mailbox->settings['insecure']) {
            continue;
          }
          mailhandler_report('error', 'IMAP error in %function: %error', array('%function' => $function, '%error' => $error));
        }
      }
    }
  }

}
