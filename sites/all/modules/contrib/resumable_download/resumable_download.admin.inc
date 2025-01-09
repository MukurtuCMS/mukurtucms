<?php

/**
 * @file
 * Functions that are only called on the admin page.
 */

/**
 * Module settings form.
 */
function resumable_download_admin_settings() {
  $form['resumable_download_max_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum download speed'),
    '#default_value' => variable_get('resumable_download_max_speed', 0),
    '#element_validate' => array('element_validate_number'),
    '#description' => t('Limit download speed in KB/s, set to 0 for unlimited speed'),
  );
  $form['resumable_download_max_kb_per_read'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum KB per read'),
    '#element_validate' => array('element_validate_number'),
    '#default_value' => variable_get('resumable_download_max_kb_per_read', 2),
    '#description' => t('Set the maximum bytes per file read, which is used to calculate sleep time for performance as well.'),
  );
  /*
  $form['resumable_download_part_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum download speed for partial requests'),
    '#element_validate' => array('element_validate_number'),
    '#default_value' => variable_get('resumable_download_part_speed', 0),
    '#description' => t('Partial requests are made when people resume downloads. However, they are also made by download accelerators, so sometimes you get a lot of partial requests. this lets you set a separate speed for parital requests (in kb/s)'),
  );
  */
  return system_settings_form($form);
}

function resumable_download_admin_settings_validate($form, &$form_state) {
  if ($form_state['values']['resumable_download_max_speed'] < 0) {
    form_set_error('resumable_download_max_speed', t('Max speed must be zero or greater.'));
  }
  $max_kb_per_read = $form_state['values']['resumable_download_max_kb_per_read'];
  if ($max_kb_per_read < 2 || $max_kb_per_read > 8) {
    form_set_error('resumable_download_max_kb_per_read', t('Max byte per read must be between 2 and 8.'));
  }
  /*
  if (!is_numeric($form_state['values']['resumable_download_part_speed']) || $form_state['values']['resumable_download_part_speed'] < 0) {
    form_set_error('resumable_download_part_speed', t('Not a valid Number'));
  }
  */
}