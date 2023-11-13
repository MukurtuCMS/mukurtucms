<?php

/**
 * @file
 * Contains SearchApiViewsHandlerFilterNumeric.
 */

/**
 * Views filter handler class for handling numeric and "string" fields.
 */
class SearchApiViewsHandlerFilterNumeric extends SearchApiViewsHandlerFilter {

  /**
   * {@inheritdoc}
   */
  public function init(&$view, &$options) {
    parent::init($view, $options);

    $this->normalizeValue();
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['value'] = array(
      'contains' => array(
        'value' => array('default' => ''),
        'min' => array('default' => ''),
        'max' => array('default' => ''),
      ),
    );

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function operator_options() {
    $operators = parent::operator_options();

    $index = search_api_index_load(substr($this->table, 17));
    $server = NULL;
    try {
      if ($index) {
        $server = $index->server();
      }
    }
    catch (SearchApiException $e) {
      // Ignore.
    }
    if ($server && $server->supportsFeature('search_api_between')) {
      $operators += array(
        'between' => t('Is between'),
        'not between' => t('Is not between'),
      );
    }

    return $operators;
  }

  /**
   * Provides a form for setting the filter value.
   *
   * Heavily borrowed from views_handler_filter_numeric.
   *
   * @see views_handler_filter_numeric::value_form()
   */
  public function value_form(&$form, &$form_state) {
    $form['value']['#tree'] = TRUE;

    $single_field_operators = $this->operator_options();
    unset(
      $single_field_operators['empty'],
      $single_field_operators['not empty'],
      $single_field_operators['between'],
      $single_field_operators['not between']
    );
    $between_operators = array('between', 'not between');

    // We have to make some choices when creating this as an exposed
    // filter form. For example, if the operator is locked and thus
    // not rendered, we can't render dependencies; instead we only
    // render the form items we need.
    $which = 'all';
    $source = NULL;
    if (!empty($form['operator'])) {
      $source = ($form['operator']['#type'] == 'radios') ? 'radio:options[operator]' : 'edit-options-operator';
    }

    $identifier = NULL;
    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (empty($this->options['expose']['use_operator']) || empty($this->options['expose']['operator_id'])) {
        // Exposed and locked.
        $which = in_array($this->operator, $between_operators) ? 'minmax' : 'value';
      }
      else {
        $source = 'edit-' . drupal_html_id($this->options['expose']['operator_id']);
      }
    }

    // Hide the value box if the operator is 'empty' or 'not empty'.
    // Radios share the same selector so we have to add some dummy selector.
    if ($which == 'all') {
      $form['value']['value'] = array(
        '#type' => 'textfield',
        '#title' => empty($form_state['exposed']) ? t('Value') : '',
        '#size' => 30,
        '#default_value' => $this->value['value'],
        '#dependency' => array($source => array_keys($single_field_operators)),
      );
      if ($identifier && !isset($form_state['input'][$identifier]['value'])) {
        $form_state['input'][$identifier]['value'] = $this->value['value'];
      }
    }
    elseif ($which == 'value') {
      // When exposed we drop the value-value and just do value if
      // the operator is locked.
      $form['value'] = array(
        '#type' => 'textfield',
        '#title' => empty($form_state['exposed']) ? t('Value') : '',
        '#size' => 30,
        '#default_value' => isset($this->value['value']) ? $this->value['value'] : '',
      );
      if ($identifier && !isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = isset($this->value['value']) ? $this->value['value'] : '';
      }
    }

    if ($which == 'all' || $which == 'minmax') {
      $form['value']['min'] = array(
        '#type' => 'textfield',
        '#title' => empty($form_state['exposed']) ? t('Min') : '',
        '#size' => 30,
        '#default_value' => $this->value['min'],
      );
      $form['value']['max'] = array(
        '#type' => 'textfield',
        '#title' => empty($form_state['exposed']) ? t('And max') : t('And'),
        '#size' => 30,
        '#default_value' => $this->value['max'],
      );

      if ($which == 'all') {
        $form['value']['min']['#dependency'] = array($source => $between_operators);
        $form['value']['max']['#dependency'] = array($source => $between_operators);
      }

      if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier]['min'])) {
        $form_state['input'][$identifier]['min'] = $this->value['min'];
      }
      if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier]['max'])) {
        $form_state['input'][$identifier]['max'] = $this->value['max'];
      }

      if (!isset($form['value']['value'])) {
        // Ensure there is something in the 'value'.
        $form['value']['value'] = array(
          '#type' => 'value',
          '#value' => NULL,
        );
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function admin_summary() {
    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }

    if ($this->operator === 'empty') {
      return t('is empty');
    }
    if ($this->operator === 'not empty') {
      return t('is not empty');
    }

    if (in_array($this->operator, array('between', 'not between'), TRUE)) {
      // This is of course wrong for translation purposes, but copied from
      // views_handler_filter_numeric::admin_summary() so probably still better
      // to re-use this than to do it correctly.
      $operator = $this->operator === 'between' ? t('between') : t('not between');
      $vars = array(
        '@min' => (string) $this->value['min'],
        '@max' => (string) $this->value['max'],
      );
      return $operator . ' ' . t('@min and @max', $vars);
    }

    return check_plain((string) $this->operator) . ' ' . check_plain((string) $this->value['value']);
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->normalizeValue();

    if (in_array($this->operator, array('between', 'not between'), TRUE)) {
      $min = $this->value['min'];
      $max = $this->value['max'];
      if ($min !== '' && $max !== '') {
        $this->query->condition($this->real_field, array($min, $max), strtoupper($this->operator), $this->options['group']);
      }
      elseif ($min !== '') {
        $operator = $this->operator === 'between' ? '>=' : '<';
        $this->query->condition($this->real_field, $min, $operator, $this->options['group']);
      }
      elseif ($max !== '') {
        $operator = $this->operator === 'between' ? '<=' : '>';
        $this->query->condition($this->real_field, $max, $operator, $this->options['group']);
      }
    }
    else {
      // The parent handler doesn't expect our value structure, just pass the
      // scalar value instead.
      $this->value = $this->value['value'];
      parent::query();
    }
  }

  /**
   * Sets $this->value to an array of options as defined by the filter.
   *
   * @see SearchApiViewsHandlerFilterNumeric::option_definition()
   */
  protected function normalizeValue() {
    $value = $this->value;
    if (is_array($value) && isset($value[0])) {
      $value = $value[0];
    }
    if (!is_array($value)) {
      $value = array('value' => $value);
    }
    $this->value = array(
      'value' => isset($value['value']) ? $value['value'] : '',
      'min' => isset($value['min']) ? $value['min'] : '',
      'max' => isset($value['max']) ? $value['max'] : '',
    );
  }

}
