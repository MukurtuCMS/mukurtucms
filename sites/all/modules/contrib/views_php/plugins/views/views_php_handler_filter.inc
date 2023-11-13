<?php

/**
 * A handler to filter a view using PHP defined by the administrator.
 *
 * @ingroup views_filter_handlers
 */
class views_php_handler_filter extends views_handler_filter {

  protected $php_static_variable = NULL;

  /**
   * Implements views_handler#can_expose().
   */
  public function can_expose() {
    return FALSE;
  }

  /**
   * Implements views_object#admin_summary().
   */
  public function admin_summary() {
    return t('PHP');
  }

  /**
   * Implements views_object#option_definition().
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['use_php_setup'] = array('default' => FALSE);
    $options['php_setup'] = array('default' => '');
    $options['php_filter'] = array('default' => '');
    return $options;
  }

  /**
   * Implements views_handler#option_definition().
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
      array('php_filter', t('Filter code'), t('If the code returns TRUE the current row is removed from the results.'), FALSE),
      array('$view', '$handler', '$static', '$row', '$data')
    );
  }

  /**
   * Implements views_handler_filter#query().
   */
  public function query() {
    // Inform views_php_views_pre_execute() to seize control over the query.
    $this->view->views_php = TRUE;
    $this->view->views_php_query_all = TRUE;
  }

  /**
   *
   * @see views_php_views_pre_execute()
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
    // Evaluate the PHP code.
    if (!empty($this->options['php_filter'])) {
      $code = $this->options['php_filter'] . ';';
      $function = function ($view, $handler, &$static, $row, $data) use ($code) {
        return eval($code);
      };
      ob_start();
      foreach ($this->view->result as $i => $row) {
        $normalized_row = new stdClass();
        foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
          $normalized_row->$field = isset($row->{$handler->field_alias}) ? $row->{$handler->field_alias} : NULL;
        }
        if ($function($this->view, $this, $this->php_static_variable, $normalized_row, $row)) {
          unset($this->view->result[$i]);
        }
      }
      ob_end_clean();
    }
  }

}
