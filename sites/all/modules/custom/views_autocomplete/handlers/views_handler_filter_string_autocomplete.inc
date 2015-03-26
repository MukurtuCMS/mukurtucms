<?php

/**
 * Basic textfield filter to handle string filtering commands
 * including equality, like, not like, etc.
 */
class views_handler_filter_string_autocomplete extends views_handler_filter_string {
  function option_definition() {
    $options = parent::option_definition();
    $options['autocomplete'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['autocomplete'] = array(
      '#type' => 'textfield',
      '#title' => t('Autocomplete path'),
      '#description' => t('Path to use for autocompletion.'),
      '#default_value' => $this->options['autocomplete'],
    );
  }

  /**
   * Provide a simple textfield for equality
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    if (!empty($this->options['autocomplete'])) {
      $form['value']['#autocomplete_path'] = $this->options['autocomplete'];
    }
  }
}
