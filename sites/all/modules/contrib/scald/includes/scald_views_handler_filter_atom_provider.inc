<?php
/**
 * @file
 * Views filter handler to filter by Atom provider.
 */

class scald_views_handler_filter_atom_provider extends views_handler_filter_in_operator {
  /**
   * Overrides views_handler_filter_in_operator::get_value_options().
   */
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Atom provider');
      $providers = array();
      $types = scald_atom_providers();
      foreach ($types as $type_name => $type_providers) {
        $providers = array_merge($providers, $type_providers);
      }
      $providers = array_map('t', $providers);
      $this->value_options = $providers;
    }
  }
}
