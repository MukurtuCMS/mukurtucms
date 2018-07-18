<?php
/**
 * @file
 * MailhandlerCommandsFiles class.
 */

/**
 * Provides file attachments.
 */
class MailhandlerCommandsFiles extends MailhandlerCommands {

  /**
   * Parse attachments from message mimeparts.
   */
  public function process(&$message, $source) {
    $message['attachments'] = array();

    foreach ($message['mimeparts'] as $attachment) {
      // 'unnamed_attachment' files are not really attachments, but mimeparts like HTML or Plain Text.
      // We only want to save real attachments, like images and files.
      if ($attachment->filename !== 'unnamed_attachment') {
        $filename = mb_decode_mimeheader($attachment->filename);

        $cid = NULL;
        if (!empty($attachment->id)) {
          $cid = trim($attachment->id, '<>');
        }

        $message['attachments'][] = new MailhandlerAttachmentEnclosure($filename, $attachment->filemime, $attachment->data, $cid);
      }
    }
    unset($message['mimeparts']);
  }

  /**
   * Implements getMappingSources().
   */
  public function getMappingSources($config) {
    $sources = array();
    $sources['attachments'] = array(
      'title' => t('Attachments'),
      'description' => t('Files attached to message.'),
    );
    return $sources;
  }

}

/**
 * Attachment enclosure, can be part of the result array.
 */
class MailhandlerAttachmentEnclosure extends FeedsEnclosure {

  /**
   * The Content-ID.
   *
   * @var string
   */
  protected $cid;

  /**
   * The file content.
   *
   * @var string
   */
  protected $data;

  /**
   * Constructs an attachment enclosure.
   *
   * @param string $filename
   *   The file name.
   * @param string $mime_type
   *   The mime type.
   * @param string $data
   *   The file content.
   * @param string $cid
   *   (optional) The Content-ID.
   */
  public function __construct($filename, $mime_type, $data, $cid = NULL) {
    parent::__construct($filename, $mime_type);
    $this->data = $data;
    $this->cid = $cid;
  }

  /**
   * Get the Content-ID.
   *
   * @return string
   *   The Content-ID or NULL if it is not defined.
   */
  public function getContentId() {
    return $this->cid;
  }

  /**
   * Get the file content.
   *
   * @return string
   *   The file content.
   */
  public function getContent() {
    return $this->data;
  }

  /**
   * {@inheritdoc}
   *
   * Save the attachment data the same way as the parent class for remote files.
   */
  public function getFile($destination, $replace = FILE_EXISTS_RENAME) {
    $file = FALSE;
    if ($this->getValue()) {
      // Prepare destination directory.
      file_prepare_directory($destination, FILE_MODIFY_PERMISSIONS | FILE_CREATE_DIRECTORY);

      // Save the file.
      if (file_uri_target($destination)) {
        $destination = trim($destination, '/') . '/';
      }
      try {
        $filename = $this->getLocalValue();

        if (module_exists('transliteration')) {
          require_once drupal_get_path('module', 'transliteration') . '/transliteration.inc';
          $filename = transliteration_clean_filename($filename);
        }

        $file = file_save_data($this->getContent(), $destination . $filename, $replace);
      }
      catch (Exception $e) {
        watchdog_exception('Feeds', $e, nl2br(check_plain($e)));
      }

      // We couldn't make sense of this enclosure, throw an exception.
      if (!$file) {
        throw new Exception(t('Invalid enclosure %enclosure', array('%enclosure' => $this->getValue())));
      }

      return $file;
    }
  }

}
