<?php

/**
 * @file
 * Contains FeedsExEncoderInterface and FeedsExTextEncoder.
 */

/**
 * Coverts text encodings.
 */
interface FeedsExEncoderInterface {

  /**
   * Constructs a FeedsExEncoderInterface object.
   *
   * @param array $encoding_list
   *   The list of encodings to search through.
   */
  public function __construct(array $encoding_list);

  /**
   * Converts a string to UTF-8.
   *
   * @param string $data
   *   The string to convert.
   *
   * @return string
   *   The encoded string, or the original string if encoding failed.
   */
  public function convertEncoding($data);

  /**
   * Returns the configuration form to select encodings.
   *
   * @param array $form
   *   The current form.
   * @param array &$form_state
   *   The form state.
   *
   * @return array
   *   The modified form array.
   */
  public function configForm(array $form, array &$form_state);

  /**
   * Validates the encoding configuration form.
   *
   * @param array &$values
   *   The form values.
   */
  public function configFormValidate(array &$values);

}

/**
 * Generic text encoder.
 */
class FeedsExTextEncoder implements FeedsExEncoderInterface {

  /**
   * Whether the current system handles mb_* functions.
   *
   * @var bool
   */
  protected $isMultibyte = FALSE;

  /**
   * The set of encodings compatible with UTF-8.
   *
   * @param array
   */
  protected static $utf8Compatible = array('utf-8', 'utf8', 'us-ascii', 'ascii');

  /**
   * The list of encodings to search for.
   *
   * @var array
   */
  protected $encodingList;

  /**
   * {@inheritdoc}
   */
  public function __construct(array $encoding_list) {
    $this->encodingList = $encoding_list;
    $this->isMultibyte = $GLOBALS['multibyte'] == UNICODE_MULTIBYTE;
  }

  /**
   * {@inheritdoc}
   */
  public function convertEncoding($data) {
    if (!$detected = $this->detectEncoding($data)) {
      return $data;
    }
    return $this->doConvert($data, $detected);
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(array $form, array &$form_state) {
    if (!$this->isMultibyte) {
      return $form;
    }

    $args = array('%encodings' => implode(', ', mb_detect_order()));
    $form['source_encoding'] = array(
      '#type' => 'textfield',
      '#title' => t('Source encoding'),
      '#description' => t('The possible encodings of the source files. auto: %encodings', $args),
      '#default_value' => implode(', ', $this->encodingList),
      '#autocomplete_path' => '_feeds_ex/encoding_autocomplete',
      '#maxlength' => 1024,
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function configFormValidate(array &$values) {
    if (!$this->isMultibyte) {
      return;
    }
    // Normalize encodings. Make them exactly as they are defined in
    // mb_list_encodings(), but maintain user-defined order.
    $encodings = array_map('strtolower', array_map('trim', explode(',', $values['source_encoding'])));

    $values['source_encoding'] = array();
    foreach (mb_list_encodings() as $encoding) {
      // Maintain order.
      $pos = array_search(strtolower($encoding), $encodings);
      if ($pos !== FALSE) {
        $values['source_encoding'][$pos] = $encoding;
      }
    }
    ksort($values['source_encoding']);
    // Make sure there's some value set.
    if (!$values['source_encoding']) {
      $values['source_encoding'][] = 'auto';
    }
  }

  /**
   * Detects the encoding of a string.
   *
   * @param string $data
   *   The string to guess the encoding for.
   *
   * @return string|bool
   *   Returns the encoding, or false if one could not be detected.
   */
  protected function detectEncoding($data) {
    if (!$this->isMultibyte) {
      return FALSE;
    }
    if ($detected = mb_detect_encoding($data, $this->encodingList, TRUE)) {
      return $detected;
    }
    return mb_detect_encoding($data, $this->encodingList);
  }

  /**
   * Performs the actual encoding conversion.
   *
   * @param string $data
   *   The data to convert.
   * @param string $source_encoding
   *   The detected encoding.
   *
   * @return string
   *   The encoded string.
   */
  protected function doConvert($data, $source_encoding) {
    if (in_array(strtolower($source_encoding), self::$utf8Compatible)) {
      return $data;
    }
    $converted = drupal_convert_to_utf8($data, $source_encoding);
    if ($converted === FALSE) {
      return $data;
    }
    return $converted;
  }

}
