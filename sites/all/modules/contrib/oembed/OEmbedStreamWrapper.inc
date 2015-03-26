<?php

/**
 *  @file
 *  Create a oEmbed Stream Wrapper class.
 */
class OEmbedStreamWrapper implements DrupalStreamWrapperInterface {

  /**
   * Instance URI (stream).
   *
   * A stream is referenced as "scheme://target".
   *
   * @var String
   */
  protected $uri;

  protected function getTarget($uri = NULL) {
    return FALSE;
  }

  /**
   * Base implementation of getMimeType().
   */
  public static function getMimeType($uri, $mapping = NULL) {
    $url = rawurldecode(substr($uri, 9));
    $embed = oembed_get_data($url);

    // The mime type can be specified in hook_oembed_response_alter() which is
    // useful to map responses with type 'rich' and 'link' to more appropriate
    // Drupal file entity bundles. See oembed_oembed_response_alter().
    if (isset($embed['mime_type'])) {
      return $embed['mime_type'];
    }

    if ($embed) {
      switch ($embed['type']) {
        case 'video':
          return 'video/oembed';
        case 'photo':
          return 'image/oembed';
        default:
          return 'text/oembed';
      }
    }
    else {

      // URIs for valid oEmbed responses may become invalid after they are saved
      // to the file_managed table. This might happen because the oEmbed
      // endpoint is down or the provider is misconfigured. The content may
      // have been deleted or become inaccessible. Some of these
      // situations are temporary, so the stream wrapper should try to return a
      // MIME type for URIs that are already saved as Drupal file entities.
      $type = db_select('file_managed', 'f')
        ->fields('f', array('type'))
        ->condition('uri', $uri)
        ->execute()
        ->fetchField();

      if (in_array($type, array('image', 'video', 'audio'))) {
        return $type .'/oembed';
      }
      else if ($type) {
        return 'text/oembed';
      }
    }

    return FALSE;
  }

  // As part of the inode protection mode returned by stat(), identifies the
  // file as a regular file, as opposed to a directory, symbolic link, or other
  // type of "file".
  // @see http://linux.die.net/man/2/stat

  const S_IFREG = 0100000;

  /**
   * Template for stat calls.
   *
   * All elements must be initialized.
   */
  protected $_stat = array(
    0 => 0, // Device number
    'dev' => 0,
    1 => 0, // Inode number
    'ino' => 0,
    // Inode protection mode. file_unmanaged_delete() requires is_file() to
    // return TRUE.
    2 => self::S_IFREG,
    'mode' => self::S_IFREG,
    3 => 0, // Number of links.
    'nlink' => 0,
    4 => 0, // Userid of owner.
    'uid' => 0,
    5 => 0, // Groupid of owner.
    'gid' => 0,
    6 => -1, // Device type, if inode device *
    'rdev' => -1,
    7 => 0, // Size in bytes.
    'size' => 0,
    8 => 0, // Time of last access (Unix timestamp).
    'atime' => 0,
    9 => 0, // Time of last modification (Unix timestamp).
    'mtime' => 0,
    10 => 0, // Time of last inode change (Unix timestamp).
    'ctime' => 0,
    11 => -1, // Blocksize of filesystem IO.
    'blksize' => -1,
    12 => -1, // Number of blocks allocated.
    'blocks' => -1,
  );

  /**
   * Returns a web accessible URL for the resource.
   *
   * This function should return a URL that can be embedded in a web page
   * and accessed from a browser. For example, the external URL of
   * "youtube://xIpLd0WQKCY" might be
   * "http://www.youtube.com/watch?v=xIpLd0WQKCY".
   *
   * @return string
   *   Returns a string containing a web accessible URL for the resource.
   */
  public function getExternalUrl() {
    return rawurldecode(substr($this->getUri(), 9));
  }

  /**
   * Base implementation of realpath().
   */
  public function realpath() {
    return $this->getExternalUrl();
  }

  /**
   * Base implementation of setUri().
   */
  public function setUri($uri) {
    $this->uri = $uri;
  }

  /**
   * Base implementation of getUri().
   */
  public function getUri() {
    return $this->uri;
  }

  /**
   * Support for fopen(), file_get_contents(), file_put_contents() etc.
   *
   * @param string $uri
   *   A string containing the path to the file to open.
   * @param string $mode
   *   The file mode ("r", "wb" etc.).
   * @param bitmask $options
   *   A bit mask of STREAM_USE_PATH and STREAM_REPORT_ERRORS.
   * @param string &$opened_url
   *   A string containing the path actually opened.
   *
   * @return bool
   *   TRUE if file was opened successfully.
   */
  public function stream_open($uri, $mode, $options, &$opened_url) {
    $this->setUri($uri);

    // We only handle Read-Only mode by default.
    if ($mode != 'r' && $mode != 'rb') {
      return FALSE;
    }

    $matches = array();
    $provider = oembed_get_provider($this->getExternalUrl(), $matches);

    if ($provider === FALSE) {
      return FALSE;
    }

    if ((bool) $provider && ($options & STREAM_USE_PATH)) {
      $opened_url = $uri;
    }

    return (bool) $provider;
  }

  /**
   * Undocumented PHP stream wrapper method.
   */
  function stream_lock($operation) {
    return FALSE;
  }

  /**
   * Support for fread(), file_get_contents() etc.
   *
   * @param int $count
   *   Maximum number of bytes to be read.
   *
   * @return bool
   *   The string that was read, or FALSE in case of an error.
   */
  public function stream_read($count) {
    return FALSE;
  }

  /**
   * Support for fwrite(), file_put_contents() etc.
   *
   * Since this is a read only stream wrapper this always returns false.
   *
   * @param string $data
   *   The string to be written.
   *
   * @return bool
   *   Returns FALSE.
   */
  public function stream_write($data) {
    return FALSE;
  }

  /**
   * Support for feof().
   *
   * @return bool
   *   TRUE if end-of-file has been reached.
   */
  public function stream_eof() {
    return FALSE;
  }

  /**
   * Support for fseek().
   *
   * @todo document why this returns false.
   *
   * @param int $offset
   *   The byte offset to got to.
   * @param string $whence
   *   SEEK_SET, SEEK_CUR, or SEEK_END.
   *
   * @return bool
   *   TRUE on success
   */
  public function stream_seek($offset, $whence) {
    return FALSE;
  }

  /**
   * Support for fflush().
   *
   * @todo document why this returns false.
   *
   * @return bool
   *   TRUE if data was successfully stored (or there was no data to store).
   */
  public function stream_flush() {
    return FALSE;
  }

  /**
   * Support for ftell().
   *
   * @todo document why this returns false.
   *
   * @return bool
   *   The current offset in bytes from the beginning of file.
   */
  public function stream_tell() {
    return FALSE;
  }

  /**
   * Support for fstat().
   *
   * @return array
   *   An array with file status, or FALSE in case of an error - see fstat()
   *   for a description of this array.
   */
  public function stream_stat() {
    return $this->_stat;
  }

  /**
   * Support for fclose().
   *
   * @todo document why this returns TRUE.
   *
   * @return bool
   *   TRUE if stream was successfully closed.
   */
  public function stream_close() {
    return TRUE;
  }

  /**
   * Support for stat().
   *
   * @param string $url
   *   A string containing the url to get information about.
   * @param bitmask $flags
   *   A bit mask of STREAM_URL_STAT_LINK and STREAM_URL_STAT_QUIET.
   *
   * @return array
   *   An array with file status, or FALSE in case of an error - see fstat()
   *   for a description of this array.
   */
  public function url_stat($url, $flags) {
    return $this->stream_stat();
  }

  /**
   * Support for opendir().
   *
   * @param string $url
   *   A string containing the url to the directory to open.
   * @param int $options
   *   Whether or not to enforce safe_mode (0x04).
   *
   * @return bool
   *   TRUE on success.
   */
  public function dir_opendir($url, $options) {
    return FALSE;
  }

  /**
   * Support for readdir().
   *
   * @return bool
   *   The next filename, or FALSE if there are no more files in the directory.
   */
  public function dir_readdir() {
    return FALSE;
  }

  /**
   * Support for rewinddir().
   *
   * @return bool
   *   TRUE on success.
   */
  public function dir_rewinddir() {
    return FALSE;
  }

  /**
   * Support for closedir().
   *
   * @return bool
   *   TRUE on success.
   */
  public function dir_closedir() {
    return FALSE;
  }

  /**
   * Undocumented.
   *
   * @todo document.
   */
  public function getDirectoryPath() {
    return '';
  }

  /**
   * DrupalStreamWrapperInterface requires that these methods be implemented,
   * but none of them apply to a read-only stream wrapper. On failure they
   * are expected to return FALSE.
   */

  /**
   * Implements DrupalStreamWrapperInterface::unlink().
   */
  public function unlink($uri) {
    // Although the remote file itself can't be deleted, return TRUE so that
    // file_delete() can remove the file record from the Drupal database.
    return TRUE;
  }

  /**
   * Implements DrupalStreamWrapperInterface::rename().
   */
  public function rename($from_uri, $to_uri) {
    return FALSE;
  }

  /**
   * Implements DrupalStreamWrapperInterface::mkdir().
   */
  public function mkdir($uri, $mode, $options) {
    return FALSE;
  }

  /**
   * Implements DrupalStreamWrapperInterface::rmdir().
   */
  public function rmdir($uri, $options) {
    return FALSE;
  }

  /**
   * Implements DrupalStreamWrapperInterface::chmod().
   */
  public function chmod($mode) {
    return FALSE;
  }

  /**
   * Implements DrupalStreamWrapperInterface::dirname().
   */
  public function dirname($uri = NULL) {
    return FALSE;
  }
}
