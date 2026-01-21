<?php

/**
 * @file
 * Provides extra FullCalendar configuration options.
 */

/**
 * Implements hook_fullcalendar_options_info().
 */
function fullcalendar_options_fullcalendar_options_info() {
  return array(
    'fullcalendar_options' => array(
      'name' => t('Extra'),
      'js' => TRUE,
    ),
  );
}

/**
 * Implements hook_fullcalendar_options_definition().
 */
function fullcalendar_options_fullcalendar_options_definition() {
  $options = array();

  foreach (_fullcalendar_options_list() as $key => $info) {
    $options[$key]['default'] = $info['#default_value'];
    // If this is a Boolean value, set the 'bool' flag for export.
    if (isset($info['#data_type']) && $info['#data_type'] == 'bool') {
      $options[$key]['bool'] = TRUE;
    }
  }

  return array(
    'fullcalendar_options' => array(
      'contains' => $options,
    ),
  );
}

/**
 * Implements hook_fullcalendar_options_form().
 */
function fullcalendar_options_fullcalendar_options_form(&$form, &$form_state, &$view) {
  $options = _fullcalendar_options_list();
  // There were no options added, remove the parent fieldset.
  if (empty($options)) {
    unset($form['fullcalendar_options']);
    return;
  }

  // Add the default value to each option.
  foreach ($options as $key => $info) {
    $form['fullcalendar_options'][$key] = $info;
    if (isset($view->options['fullcalendar_options'][$key])) {
      $form['fullcalendar_options'][$key]['#default_value'] = $view->options['fullcalendar_options'][$key];
    }
  }
}
