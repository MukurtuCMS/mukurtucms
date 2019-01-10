<?php

/**
 * @file
 * Custom date handler for Views
 * Code came from the http://drupal.org/project/reldate module
 */

class oa_date_handler_field_date extends views_handler_field_date {
  /**
   * Override of option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['oa_date'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Override of options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['oa_date'] = array(
      '#title' => t('Custom formats'),
      '#type' => 'select',
      '#options' => array(
        FALSE => '< ' . t('Custom format') . ' >',
        'oa_date' => t('Relative date'),
      ),
      '#default_value' => $this->options['oa_date'],
      '#description' => t('Use a custom format for this field. This will override any other date format settings.'),
    );
    if (module_exists('date_api')) {
      $time = time();
      $custom_formats = array_diff_key(system_get_date_formats(), array_fill_keys(array('short', 'medium', 'long', 'custom'), TRUE));
      if (!empty($custom_formats)) {
        foreach ($custom_formats as $format => $format_options) {
          $form['oa_date']['#options'][$format] = format_date($time, 'custom', variable_get("date_format_{$format}", key($format_options)));
        }
      }
    }
  }

  /**
   * Override of render().
   */
  function render($values) {
    if (!empty($this->options['oa_date'])) {
      $value = $values->{$this->field_alias};
      if ($this->options['oa_date'] === 'oa_date') {
        return $value ? oa_date_format_date($value) : theme('views_nodate');
      }
      else {
        $format = variable_get("date_format_{$this->options['reldate']}", FALSE);
        return $value && $format ? format_date($value, 'custom', $format) : theme('views_nodate');
      }
    }
    return parent::render($values);
  }
}
