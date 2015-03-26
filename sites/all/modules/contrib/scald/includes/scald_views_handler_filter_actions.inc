<?php
/**
 * @file
 * Provides a filter allowing to restrict the results by atoms actions.
 */

class scald_views_handler_filter_actions extends views_handler_filter {
  /**
   * Overrides operator_form.
   *
   * Hardcode our bitwise AND, and tells Views that this filter doesn't
   * expose an operator.
   */
  public function operator_form(&$form, &$form_state) {
    $this->no_operator = TRUE;
    $form['operator'] = array(
      '#type' => 'value',
      '#value' => '&',
    );
  }

  /**
   * Overrides value_form.
   *
   * Provides checkboxes for the defined actions.
   */
  public function value_form(&$form, &$form_state) {
    $old_default = !is_array($this->options['value']);
    $defaults = $old_default ? array() : $this->options['value'];
    foreach (scald_actions() as $slug => $action) {
      $options[$slug] = $action['title'];
      if ($old_default) {
        $defaults[$slug] = ($this->options['value'] & $action['bitmask']) ? $slug : '';
      }
    }
    // And now, we just need to add our select item with the values
    // we've prepared above.
    $form['value'] = array(
      '#title' => t('Actions'),
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => $defaults,
    );
  }

  /**
   * Overrides query.
   *
   * Change the operator before querying.
   */
  public function query() {
    if (is_array($this->options['value'])) {
      $this->value = 0;
      $actions = scald_actions();
      foreach ($actions as $name => $action) {
        if (!empty($this->options['value'][$name])) {
          $this->value |= $action['bitmask'];
        }
      }
    }
    else {
      $this->value = $this->options['value'];
    }
    $this->operator = ' & ' . $this->value . ' = ';
    parent::query();
  }

  /**
   * Overrides admin_summary.
   *
   * Display user friendly label.
   */
  public function admin_summary() {
    $actions = scald_actions();
    $names = array();
    foreach ($actions as $name => $action) {
      if (!empty($this->options['value'][$name])) {
        $names[] = $action['title'];
      }
    }
    return implode(',', $names);
  }
}
