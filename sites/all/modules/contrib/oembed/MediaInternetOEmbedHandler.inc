<?php

/**
 * @file MediaInternetOEmbedHandler.inc
 *
 * Contains MediaInternetOEmbedHandler.
 */

// If MediaInternetBaseHandler class does not exist, prevent the rest of this
// file from being loaded.
if (!class_exists('MediaInternetBaseHandler')) {
  return;
}

/**
 * Implementation of MediaInternetBaseHandler.
 *
 * @see hook_media_internet_providers().
 */
class MediaInternetOEmbedHandler extends MediaInternetBaseHandler {

  public $fileObject;

  /**
   * Claim this URL.
   */
  public function claim($embedCode) {
    $matches = array();
    if (oembed_get_provider($embedCode, $matches)) {
      return TRUE;
    }
  }

  /**
   * File should not validate if we cannot fetch valid oEmbed data.
   */
  public function validate() {
    $file = $this->getFileObject();

    $validators = array('oembed_file_validator_type' => array());

    $errors = file_validate($file, $validators);

    foreach ($errors as $error) {
      throw new MediaInternetValidationException($error);
    }
  }

  /**
   * Returns a file object which can be used for validation
   *
   * @return StdClass
   */
  public function getFileObject() {
    if (!$this->fileObject) {
      $file = oembed_url_to_file($this->embedCode);
      $this->fileObject = $file;
    }
    return $this->fileObject;
  }

  /**
   * Returns an array representation of the oEmbed data, or NULL on failure.
   *
   * An example project that calls this method is Media Browser Plus
   * (http://drupal.org/project/media_browser_plus). Other projects may do so
   * in the future.
   */
  public function getOEmbed() {
    $embed = oembed_get_data($this->embedCode);
    return $embed ? (array) $embed : NULL;
  }
}
