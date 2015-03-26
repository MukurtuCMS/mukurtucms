<?php

/**
 * @file
 * Provides a wrapper class for media_internet providers.
 */

/**
 * Wraps a media_internet provider to implement the interface of
 * MediaFeedsProvider and provide workarounds for some issues. As the issues
 * get fixed the workarounds can be removed.
 */
class MediaFeedsInternetProvider extends MediaFeedsProvider {

  protected $provider;

  /**
   * Construcor.
   *
   * @param $provider
   *   The media_internet provider to wrap for workarounds.
   */
  public function __construct($value, $config = array()) {
    parent::__construct($value, $config);
    $this->provider = media_internet_get_provider($this->value);
  }

  private $existingFile = NULL;

  /**
   * Looks for an existing file.
   *
   * @return
   *   The fid, if an existing file is in the database. FALSE if no existing
   *   file is found.
   */
  public function getExistingFile() {
    if ($this->existingFile === NULL) {
      $this->existingFile = FALSE;

      $file = $this->provider->getFileObject();
      if ($file) {
        $query = new EntityFieldQuery();
        $existing = $query
          ->entityCondition('entity_type', 'file')
          ->propertyCondition('uri', $file->uri)
          ->execute();
        if ($existing && isset($existing['file']) && is_array($existing['file'])) {
          $this->existingFile = reset($existing['file'])->fid;
        }
      }
    }

    return $this->existingFile;
  }

  /**
   * If required, providers can validate the embedCode.
   *
   * However some providers fail validation, if the file already exists in the
   * media library. That means that validation has to be skipped for existing
   * files. Currently known providers don't do others things in validate(), so
   * skipping should be OK.
   *
   * Related Issue: When pasting the URL of a file which already exists in the
   * media library, media_internet throws a validation error
   * (http://drupal.org/node/1121808).
   */
  public function validate() {
    if (!$this->getExistingFile()) {
      return $this->provider->validate();
    }
  }

  /**
   * Get the file object that can be validated and saved.
   *
   * When saving an existing file $file->fid must be this fid of the existing
   * file and $file->is_new must be FALSE. Otherwise a PDOException will be
   * thrown, because the file uri is a unique key.
   *
   * See for example: Trying to add the same YouTube URL twice causes a primary
   * key violation (http://drupal.org/node/952422).
   *
   * Instead of skipping those files (by failing validation) we must work
   * around that issue.
   */
  public function getFileObject() {
    $file = $this->provider->getFileObject();

    $fid = $this->getExistingFile();
    if ($fid) {
      $file->fid = $fid;
      $file->is_new = FALSE;
    }

    return $file;
  }

  public static $currentExistingFile = FALSE;

  /**
   * Let the provider save the file. Since providers don't use the workaround
   * at MediaFeedsProviderWrapper::getFileObject() internally, hook into that
   * process using hook_file_presave().
   *
   * MediaFeedsProviderWrapper::$currentExistingFile will be the fid of an
   * existing file, if a workaround is required. Otherwise it is FALSE.
   */
  public function save() {
    self::$currentExistingFile = $this->getExistingFile();
    $file = $this->provider->save();
    self::$currentExistingFile = FALSE;
    return $file;
  }
}
