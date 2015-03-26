<?php
/**
 * @file
 * Implements views_plugin_style for views_json
 */

/**
 * Implements views_plugin_style
 */
class views_plugin_style_autocomplete extends views_plugin_style_json {
  /**
   * Provide a form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['root_object']);
    unset($form['top_child_object']);
  }

  /**
   * Implementation of view_style_plugin::render()
   */
  function render() {
    $view = $this->view;
    $options = $this->options;
    $field = $view->field;

    $rows = array();
    foreach ($view->result as $count => $row) {
      $view->row_index = $count;
      $rows[] = _views_json_render_fields($view, $row);
    }
    unset($view->row_index);

    return theme('views_views_autocomplete', array('view' => $view, 'options' => $options, 'rows' => $rows));
  }

  function query() {
    $this->view->args = array(0);
  }
}
