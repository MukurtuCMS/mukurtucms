<?php

/**
 * @file
 * Administrative page callbacks for the FullCalendar module.
 */

/**
 * General configuration form for controlling the FullCalendar behaviour.
 */
function fullcalendar_admin_settings() {
  $fullcalendar_path = variable_get('fullcalendar_path', fullcalendar_default_path());

  $form['fullcalendar_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to FullCalendar'),
    '#default_value' => $fullcalendar_path,
    '#description' => t('Enter the path relative to Drupal root where the FullCalendar plugin directory is located.'),
  );
  $form['fullcalendar_compression_type'] = array(
    '#type' => 'radios',
    '#title' => t('Choose FullCalendar compression level'),
    '#options' => array(
      'min' => t('Production (Minified)'),
      'none' => t('Development (Uncompressed code)'),
    ),
    '#default_value' => variable_get('fullcalendar_compression_type', 'min'),
  );

  return system_settings_form($form);
}

/**
 * Form validation handler for fullcalendar_admin_settings().
 */
function fullcalendar_admin_settings_validate($form, &$form_state) {
  form_set_value($form['fullcalendar_path'], rtrim($form['fullcalendar_path']['#value'], "/"), $form_state);
}
