<?php

/**
 * @file
 * Handler for references_plugin_row_fields.
 */

/**
 * Default class for plugin row fields.
 *
 * @codingStandardsIgnoreStart
 */
class references_plugin_row_fields extends views_plugin_row_fields {

  /**
   * Option Definition.
   */
  public function option_definition() {
    // @codingStandardsIgnoreEnd
    $options = parent::option_definition();

    $options['separator'] = array('default' => '-');

    return $options;
  }

  /**
   * Provide a form for setting options.
   *
   * @codingStandardsIgnoreStart
   */
  public function options_form(&$form, &$form_state) {
    // @codingStandardsIgnoreEnd
    parent::options_form($form, $form_state);

    // Expand the description of the 'Inline field' checkboxes.
    $form['inline']['#description'] .= '<br>' . t("<strong>Note:</strong> In 'References' displays, all fields will be displayed inline unless an explicit selection of inline fields is made here.");
  }

  /**
   * Pre Render.
   *
   * @codingStandardsIgnoreStart
   */
  public function pre_render($row) {
    // @codingStandardsIgnoreEnd
    // Force all fields to be inline by default.
    if (empty($this->options['inline'])) {
      $fields = $this->view->get_items('field', $this->display->id);
      $this->options['inline'] = drupal_map_assoc(array_keys($fields));
    }

    return parent::pre_render($row);
  }

}
