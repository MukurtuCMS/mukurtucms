<?php
/**
 * @file
 * Provides a field showing the filesize of the file in the atom.
 */

/**
 * Scald_file_views_handler_field_filesize class.
 *
 * @codingStandardsIgnoreStart
 */
class scald_file_views_handler_field_filesize extends views_handler_field {
  /**
   * Overrides views_handler_field::option_definition().
   */
  public function option_definition() {
    // @codingStandardsIgnoreEnd
    $options = parent::option_definition();

    return $options;
  }

  /**
   * Overrides views_handler_field::options_form().
   *
   * @codingStandardsIgnoreStart
   */
  public function options_form(&$form, &$form_state) {
    // @codingStandardsIgnoreEnd
    parent::options_form($form, $form_state);
  }

  /**
   * Overrides views_handler_field::render().
   */
  public function render($values) {
    $data = $values->{$this->field_alias};
    $file = file_load($data);
    if ($file) {
      return format_size($file->filesize);
    }
    return '';
  }

}
