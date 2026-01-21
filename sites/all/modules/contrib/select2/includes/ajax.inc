<?php
/**
 * @file
 * ajax integration for select2.
 */

/**
 * Ajax settings.
 */
function select2_get_settings_ajax() {

  $process_all_selects = FALSE;

  if (variable_get('select2_use_for_all_select_elements', FALSE)) {
    if (!path_is_admin(current_path()) ||
        (path_is_admin(current_path()) && variable_get('select2_use_for_all_select_elements_for_admin_pages', FALSE))) {
      $process_all_selects = TRUE;
    }
  }

  drupal_add_js(
    array(
      'select_2' => array(
        'excludes' => array(
          'by_id' => array(
            'values' => array(),
            'reg_exs' => array(),
          ),
          'by_class' => array(),
          'by_selectors' => array(),
        ),
        'default_settings' => _select2_default_settings(),
        'process_all_selects_on_page' => $process_all_selects,
        'elements' => array(),
      ),
    ),
    'setting');

  _select2_set_exuled_for_settings();
}
