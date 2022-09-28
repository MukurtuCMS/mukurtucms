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
    '#description' => t('Limit download speed in KB/s, set to 0 for unlimited speed'),
  );
  /*
  $form['resumable_download_part_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum download speed for partial requests'),
    '#default_value' => variable_get('resumable_download_part_speed', 0),
    '#description' => t('Partial requests are made when people resume downloads. However, they are also made by download accelerators, so sometimes you get a lot of partial requests. this lets you set a separate speed for parital requests (in kb/s)'),
  );
  */
  return system_settings_form($form);
}

function resumable_download_admin_settings_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['resumable_download_max_speed']) || $form_state['values']['resumable_download_max_speed'] < 0) {
    form_set_error('resumable_download_max_speed', t('Not a valid Number'));
  }
  /*
  if (!is_numeric($form_state['values']['resumable_download_part_speed']) || $form_state['values']['resumable_download_part_speed'] < 0) {
    form_set_error('resumable_download_part_speed', t('Not a valid Number'));
  }
  */
}