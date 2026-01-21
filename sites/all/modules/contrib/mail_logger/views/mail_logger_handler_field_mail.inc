<?php
/**
 * @file
 * Views handlers for the Mail Logger module.
 */

/**
 * Field handler to provide a mailto link for email fields.
 */
class mail_logger_handler_field_mail extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['link'] = array('default' => 'mailto');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link'] = array(
      '#title' => t('Link this field'),
      '#type' => 'radios',
      '#options' => array(
        0 => t('No link'),
        'mailto' => t("With a mailto:"),
        'user' => t("User account, if one exists."),
      ),
      '#default_value' => $this->options['link'],
    );
  }

  function render($values) {
    if ($this->options['link'] == 'mailto') {
      return l($values->{$this->field_alias}, "mailto:" . $values->{$this->field_alias});
    }
    elseif ($this->options['link'] == 'user') {
      // Return a link to an account page if one exists; otherwise, fall back.
      if ($account = mail_logger_email_user($values->{$this->field_alias})) {
        return l($values->{$this->field_alias}, 'user/' . $account->uid);
      }
    }
    return check_plain($values->{$this->field_alias});
  }
}
