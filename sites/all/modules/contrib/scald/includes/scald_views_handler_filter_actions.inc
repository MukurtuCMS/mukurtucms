<?php
/**
 * @file
 * Provides a filter allowing to restrict the results by atoms actions.
 */

class scald_views_handler_filter_actions extends views_handler_filter {
  public function option_definition() {
    $options = parent::option_definition();

    $options['operator']['default'] = '&';
    $options['value']['default'] = array();

    return $options;
  }

  public function operators() {
    $operators = array(
      '&' => array(
        'title' => t('Is all of'),
        'short' => t('is'),
      ),
      'in' => array(
        'title' => t('Is one of'),
        'short' => t('in'),
      ),
      'not in' => array(
        'title' => t('Is not one of'),
        'short' => t('not in'),
      ),
    );

    return $operators;
  }

  function operator_options($which = 'title') {
    $options = array();
    foreach ($this->operators() as $id => $info) {
      $options[$id] = $info[$which];
    }

    return $options;
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
    if (is_array($this->value)) {
      $values = drupal_map_assoc($this->value);
      $bitmask = 0;
      $actions = scald_actions();
      foreach ($actions as $name => $action) {
        if (!empty($values[$name])) {
          $bitmask |= $action['bitmask'];
        }
      }
    }
    else {
      $bitmask = $this->value;
    }

    switch ($this->operator) {
      case '&':
        $this->operator = ' & ' . $bitmask . ' = ';
        $this->value = $bitmask;
        break;
      case 'in':
        $this->operator = ' & ' . $bitmask . ' >';
        $this->value = 0;
        break;
      case 'not in':
        $this->operator = ' & ' . $bitmask . ' = ';
        $this->value = 0;
        break;
    }

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
