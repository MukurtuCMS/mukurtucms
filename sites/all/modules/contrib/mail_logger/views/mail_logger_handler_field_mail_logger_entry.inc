<?php
/**
 * @file
 * Views handlers for the Mail Logger module.
 */

/**
 * Field handler to provide a link to the mail logger entry.
 */
class mail_logger_handler_field_mail_logger_entry extends views_handler_field {
  /**
   * Constructor to provide additional field to add.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['mlid'] = array('table' => 'mail_logger', 'field' => 'mlid');
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_entry'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_entry'] = array(
      '#title' => t('Link this field to its mail logger entry'),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_entry']),
    );
  }

  /**
   * Render whatever the data is as a link to the mail entry.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    // Check the user has access.
    if (!empty($this->options['link_to_entry']) && $data !== NULL && $data !== '' && user_access('access mail logger')) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'admin/reports/mail-logger/mail/' . $values->{$this->aliases['mlid']};
    }
    return $data;
  }

  function render($values) {
    return $this->render_link(check_plain($values->{$this->field_alias}), $values);
  }
}
