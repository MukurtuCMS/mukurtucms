<?php

/**
 * @file
 * Administrative page callback for the FullCalendar Options module.
 */

/**
 * Options configuration form for exposing new FullCalendar options.
 */
function fullcalendar_options_admin_settings() {
  // Use a fieldset with #tree so that it is saved as a single variable.
  $form['fullcalendar_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#description' => t('Each setting can be exposed for all views.'),
    '#tree' => TRUE,
  );

  // Gather all of the available options and convert them to checkboxes.
  $values = variable_get('fullcalendar_options', array());
  foreach (_fullcalendar_options_list(TRUE) as $key => $info) {
    $form['fullcalendar_options'][$key] = array(
      '#type' => 'checkbox',
      '#default_value' => isset($values[$key]) ? $values[$key] : FALSE,
    ) + $info;
  }

  return system_settings_form($form);
}
