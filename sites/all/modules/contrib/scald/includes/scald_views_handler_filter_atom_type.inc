<?php
/**
 * @file
 * Filter by Scald Atom type.
 */

class scald_views_handler_filter_atom_type extends views_handler_filter_in_operator {
  /**
   * Overrides views_handler_filter_in_operator::get_value_options().
   */
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Atom type');
      $types = scald_types();
      $options = array();
      foreach ($types as $type => $info) {
        $options[$type] = scald_type_property_translate($info);
      }
      $this->value_options = $options;
    }
  }
}
