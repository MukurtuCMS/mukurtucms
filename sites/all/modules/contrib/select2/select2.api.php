<?php

/**
 * @file
 * Hooks provided by the Select2 module.
 */

/**
 * Alter the form element processed by Select2 module.
 *
 * This hook is called before element select2 setting stored in $element['#select2']
 * key, will be added to global js settings array.
 *
 * @param $element
 *   A renderable array representing the form element processed by Select2 process functions.
 *
 * @see select2_process_textfield()
 * @see select2_select_element_process()
 *
 */
function hook_select2_element_alter(&$element) {

  // Change width option value.
  $element['#select2']['width'] = 'auto';

  // Add a new custom_option with specific value.
  $element['#select2']['new_custom_option'] = 'new_custopm_option_value';
}
