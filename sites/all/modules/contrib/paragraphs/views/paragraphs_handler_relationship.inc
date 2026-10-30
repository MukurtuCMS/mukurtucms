<?php

/**
 * Provide relationship handler for paragraphs fields.
 */
class paragraphs_handler_relationship extends views_handler_relationship {

  /**
   * Returns extra option definitions for the form.
   *
   * @return array
   *   An array of option definitions.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['delta'] = array('default' => -1);

    return $options;
  }

  /**
   * Add a delta selector for multiple fields.
   *
   * @param $form
   *   The form structure array.
   * @param $form_state
   *   An associative array containing the current state of the form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $field = field_info_field($this->definition['field_name']);

    // Only add the delta selector if the field is multiple.
    if ($field['cardinality']) {
      $max_delta = ($field['cardinality'] == FIELD_CARDINALITY_UNLIMITED) ? 10 : $field['cardinality'];

      $options = array('-1' => t('All'));
      for ($i = 0; $i < $max_delta; $i++) {
        $options[$i] = $i + 1;
      }
      $form['delta'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $this->options['delta'],
        '#title' => t('Delta'),
        '#description' => t('The delta allows you to select which item in a multiple value field to key the relationship off of. Select "1" to use the first item, "2" for the second item, and so on. If you select "All", each item in the field will create a new row, which may appear to cause duplicates.'),
      );
    }
  }

  /**
   * Makes sure our table is added to the join.
   *
   * @return mixed
   *   The alias of the table of this handler which is used in the query.
   */
  public function ensure_my_table() {
    $field = field_info_field($this->definition['field_name']);

    if (!isset($this->table_alias)) {
      $join = $this->get_join();
      if ($this->options['delta'] != -1 && $field['cardinality']) {
        $join->extra[] = array(
          'field' => 'delta',
          'value' => $this->options['delta'],
          'numeric' => TRUE,
        );
      }
      $this->table_alias = $this->query->add_table($this->table, $this->relationship, $join);
    }
    return $this->table_alias;
  }

}
