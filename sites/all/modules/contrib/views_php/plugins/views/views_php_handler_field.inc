<?php

/**
 * A handler to provide a field that is constructed by the administrator using PHP.
 *
 * @ingroup views_field_handlers
 */
class views_php_handler_field extends views_handler_field {
  const CLICK_SORT_DISABLED = 0;
  const CLICK_SORT_NUMERIC = 1;
  const CLICK_SORT_ALPHA = 2;
  const CLICK_SORT_ALPHA_CASE = 3;
  const CLICK_SORT_NAT = 4;
  const CLICK_SORT_NAT_CASE = 5;
  const CLICK_SORT_PHP = 6;

  protected $php_static_variable = NULL;

  /**
   * Implements views_object#option_definition().
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['use_php_setup'] = array('default' => FALSE);
    $options['php_setup'] = array('default' => '');
    $options['php_value'] = array('default' => '');
    $options['php_output'] = array('default' => '');
    $options['use_php_click_sortable'] = array('default' => self::CLICK_SORT_DISABLED);
    $options['php_click_sortable'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Implements views_handler#options_form().
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form += views_php_form_element($this,
      array('use_php_setup', t('Use setup code'), t('If checked, you can provide PHP code to be run once right before execution of the view. This may be useful to define functions to be re-used in the value and/or output code.')),
      array('php_setup', t('Setup code'), t('Code to run right before execution of the view.'), FALSE),
      array('$view', '$handler', '$static')
    );
    $form += views_php_form_element($this,
      FALSE,
      array('php_value', t('Value code'), t('Code to construct the value of this field.'), FALSE),
      array('$view', '$handler', '$static', '$row', '$data')
    );
    $form += views_php_form_element($this,
      array('use_php_click_sortable', t('Enable click sort'), t('If checked, you can use PHP code to enable click sort on the field. This may have a large performance impact as all results will be loaded from the database, and pager limits will only be applied in PHP.')),
      array('php_click_sortable', t('Click sort code'), t('The comparison code must return an integer less than, equal to, or greater than zero if the first row should respectively appear before, stay where it was compared to, or appear after the second row.'), FALSE),
      array(
        '$view', '$handler', '$static',
        '$row1' => t('Data of row.'),
        '$row2' => t('Data of row to compare against.'),
      )
    );
    $form['use_php_click_sortable']['#type'] = 'select';
    $form['use_php_click_sortable']['#options'] = array(
      self::CLICK_SORT_DISABLED => t('No'),
      self::CLICK_SORT_NUMERIC => t('Sort numerically'),
      self::CLICK_SORT_ALPHA => t('Sort alphabetically'),
      self::CLICK_SORT_ALPHA_CASE => t('Sort alphabetically (case insensitive)'),
      self::CLICK_SORT_NAT => t('Sort using a "natural order" algorithm'),
      self::CLICK_SORT_NAT_CASE => t('Sort using a "natural order" algorithm (case insensitive)'),
      self::CLICK_SORT_PHP => t('Sort using custom PHP code'),
    );
    $form['use_php_click_sortable']['#default_value'] = $this->options['use_php_click_sortable'];
    $form['php_click_sortable']['#states'] = array(
      'visible' => array(
        ':input[name="options[use_php_click_sortable]"]' => array('value' => (string) self::CLICK_SORT_PHP),
      ),
    );
    $form += views_php_form_element($this,
      FALSE,
      array('php_output', t('Output code'), t('Code to construct the output of this field.'), TRUE),
      array('$view', '$handler', '$static', '$row', '$data', '$value' => t('Value of this field.'))
    );
  }

  /**
   * Implements views_handler_field#query().
   *
   * @see views_php_views_pre_execute()
   */
  public function query() {
    // Provide an field alias but don't actually alter the query.
    $this->field_alias = 'views_php_' . $this->position;
    // Inform views_php_views_pre_execute() to seize control over the query.
    $this->view->views_php = TRUE;
    if ($this->click_sortable()) {
      $this->view->views_php_query_all = TRUE;
    }
  }

  /**
   * Implements views_handler_field#click_sortable().
   */
  public function click_sortable() {
    return $this->options['use_php_click_sortable'] != self::CLICK_SORT_DISABLED;
  }

  /**
   * Implements views_handler_field#click_sort().
   *
   * @see self::php_post_execute()
   */
  public function click_sort($order) {
    $this->php_click_sort_order = $order;
  }

  /**
   *
   * @see views_php_views_pre_execute()
   * @see self::php_post_execute()
   */
  public function php_pre_execute() {
    // Execute static PHP code.
    if (!empty($this->options['php_setup'])) {
      $code = $this->options['php_setup'] . ';';
      $function = function ($view, $handler, &$static) use ($code) {
        eval($code);
      };
      ob_start();
      $function($this->view, $this, $this->php_static_variable);
      ob_end_clean();
    }
  }

  /**
   *
   * @see views_php_views_post_execute()
   */
  public function php_post_execute() {
    // Execute value PHP code.
    if (!empty($this->options['php_value'])) {
      $code = $this->options['php_value'] . ';';
      $function = function ($view, $handler, &$static, $row, $data) use ($code) {
        return eval($code);
      };
      ob_start();
      foreach ($this->view->result as $i => &$row) {
        $normalized_row = new stdClass();
        foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
          $normalized_row->$field = isset($row->{$handler->field_alias}) ? $row->{$handler->field_alias} : NULL;
        }
        $row->{$this->field_alias} = $function($this->view, $this, $this->php_static_variable, $normalized_row, $row);
      }
      ob_end_clean();
    }

    // If we're sorting, do the actual sorting then fix the results as per the pager info.
    if (!empty($this->options['use_php_click_sortable']) && !empty($this->php_click_sort_order)) {
      if ($this->options['use_php_click_sortable'] == self::CLICK_SORT_PHP) {
        if (!empty($this->options['php_click_sortable'])) {
          $this->php_click_sort_function = TRUE;
        }
      }
      else {
        $predefined = array(
          self::CLICK_SORT_NUMERIC => array($this, 'php_click_sort_numeric'),
          self::CLICK_SORT_ALPHA => 'strcasecmp',
          self::CLICK_SORT_ALPHA_CASE => 'strcmp',
          self::CLICK_SORT_NAT => 'strnatcasecmp',
          self::CLICK_SORT_NAT_CASE => 'strnatcmp',
        );
        $this->php_click_sort_function = $predefined[$this->options['use_php_click_sortable']];
      }

      if (isset($this->php_click_sort_function)) {
        usort($this->view->result, array($this, 'php_click_sort'));
      }
    }
  }

  /**
   * Helper function; usort() callback for click sort support.
   */
  public function php_click_sort($row1, $row2) {
    $factor = strtoupper($this->php_click_sort_order) == 'ASC' ? 1 : -1;
    $function = $this->php_click_sort_function;
    if (is_bool($this->php_click_sort_function)) {
      $code = $this->options['php_click_sortable'] . ';';
      $function = function ($view, $handler, &$static, $row1, $row2) use ($code) {
        return eval($code);
      };
    }

    if ($this->options['use_php_click_sortable'] == self::CLICK_SORT_PHP) {
      foreach (array('row1' => 'normalized_row1', 'row2' => 'normalized_row2') as $name => $normalized_name) {
        $$normalized_name = new stdClass();
        foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
          $$normalized_name->$field = isset($$name->{$handler->field_alias}) ? $$name->{$handler->field_alias} : NULL;
        }
      }
      ob_start();
      $result = (int) $function($this->view, $this, $this->php_static_variable, $normalized_row1, $normalized_row2);
      ob_end_clean();
    }
    else {
      $result = $function($row1->{$this->field_alias}, $row2->{$this->field_alias});
    }
    return $factor * $result;
  }

  /**
   * Helper function; usort callback for numeric sort.
   */
  public function php_click_sort_numeric($a, $b) {
    return $a - $b;
  }

  /**
   * Implements views_handler_field#render().
   */
  public function render($values) {
    // Execute output PHP code.
    if (!empty($this->options['php_output'])) {
      $normalized_row = new stdClass();
      foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
        $normalized_row->$field = isset($values->{$handler->field_alias}) ? $values->{$handler->field_alias} : NULL;
      }

      $code = ' ?>' . $this->options['php_output'];
      $function = function ($view, $handler, &$static, $row, $data, $value) use ($code) {
        eval($code);
      };
      ob_start();
      $function($this->view, $this, $this->php_static_variable, $normalized_row, $values, isset($values->{$this->field_alias}) ? $values->{$this->field_alias} : NULL);
      $value = ob_get_clean();
    }
    else {
      if (isset($values->{$this->field_alias})) {
        $value = check_plain($values->{$this->field_alias});
      }
    }

    if (isset($value)) {
      return $value;
    }
  }

}
