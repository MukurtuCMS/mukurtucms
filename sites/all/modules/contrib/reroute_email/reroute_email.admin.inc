<?php

/**
 * @file
 * Reroute Email admin configuration functions.
 */

/**
 * Settings form.
 */
function reroute_email_settings() {
  // In case of absence of the 'variable' module, the inc file should be loaded
  // manually.
  module_load_include('inc', 'reroute_email', 'reroute_email.variable');

  // Getting titles and descriptions of variables. We will not use foreach()
  // loop of $variables in the form below for better code readability.
  // @see reroute_email_variable_info()
  $variables = module_invoke('reroute_email', 'variable_info', array());

  // Checkbox to enable or disable email rerouting.
  $form[REROUTE_EMAIL_ENABLE] = array(
    '#type' => 'checkbox',
    '#title' => $variables[REROUTE_EMAIL_ENABLE]['title'],
    '#default_value' => variable_get(REROUTE_EMAIL_ENABLE, 0),
    '#description' => $variables[REROUTE_EMAIL_ENABLE]['description'],
  );

  // Define #states to be used for visibility of all variables.
  $states = array(
    'visible' => array(':input[name=' . REROUTE_EMAIL_ENABLE . ']' => array('checked' => TRUE)),
  );

  // Text field for email rerouting targets.
  $form[REROUTE_EMAIL_ADDRESS] = array(
    '#type' => 'textfield',
    '#title' => $variables[REROUTE_EMAIL_ADDRESS]['title'],
    '#default_value' => variable_get(REROUTE_EMAIL_ADDRESS, variable_get('site_mail', ini_get('sendmail_from'))),
    '#description' => $variables[REROUTE_EMAIL_ADDRESS]['description'],
    '#states' => $states,
    '#element_validate' => array('reroute_email_element_validate_addresses'),
  );

  // Text field for email whitelisting.
  $form[REROUTE_EMAIL_WHITELIST] = array(
    '#type' => 'textfield',
    '#title' => $variables[REROUTE_EMAIL_WHITELIST]['title'],
    '#default_value' => variable_get(REROUTE_EMAIL_WHITELIST, ''),
    '#description' => $variables[REROUTE_EMAIL_WHITELIST]['description'],
    '#states' => $states,
    '#element_validate' => array('reroute_email_element_validate_addresses'),
  );

  // Checkbox to enable additional information in email body message.
  $form[REROUTE_EMAIL_ENABLE_MESSAGE] = array(
    '#type' => 'checkbox',
    '#title' => $variables[REROUTE_EMAIL_ENABLE_MESSAGE]['title'],
    '#default_value' => variable_get(REROUTE_EMAIL_ENABLE_MESSAGE, 1),
    '#description' => $variables[REROUTE_EMAIL_ENABLE_MESSAGE]['description'],
    '#states' => $states,
  );

  // Checkbox to enable the display of a Drupal message after rerouting email.
  $form[REROUTE_EMAIL_ENABLE_DSM] = array(
    '#type' => 'checkbox',
    '#title' => $variables[REROUTE_EMAIL_ENABLE_DSM]['title'],
    '#default_value' => variable_get(REROUTE_EMAIL_ENABLE_DSM, 1),
    '#description' => $variables[REROUTE_EMAIL_ENABLE_DSM]['description'],
    '#states' => $states,
  );

  $form['mail_keys'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#states' => $states,
    '#collapsible' => TRUE,
    '#collapsed' => variable_get(REROUTE_EMAIL_MAIL_KEYS, '') === '',
  );

  $form['mail_keys'][REROUTE_EMAIL_MAIL_KEYS] = array(
    '#title' => $variables[REROUTE_EMAIL_MAIL_KEYS]['title'],
    '#type' => 'textarea',
    '#rows' => 3,
    '#default_value' => variable_get(REROUTE_EMAIL_MAIL_KEYS, ''),
    '#description' => $variables[REROUTE_EMAIL_MAIL_KEYS]['description'],
  );

  return system_settings_form($form);
}

/**
 * Form for sending test messages.
 */
function reroute_email_test_email_form() {
  return array(
    'addresses' => array(
      '#type' => 'fieldset',
      '#description' => t('Email addresses are not validated: any valid or invalid email address format could be submitted.'),
      'to' => array(
        '#type' => 'textfield',
        '#title' => t('To'),
        '#required' => TRUE,
      ),
      'cc' => array(
        '#type' => 'textfield',
        '#title' => t('Cc'),
      ),
      'bcc' => array(
        '#type' => 'textfield',
        '#title' => t('Bcc'),
      ),
    ),
    'subject' => array(
      '#type' => 'textfield',
      '#title' => t('Subject'),
      '#default_value' => t('Reroute Email Test'),
    ),
    'body' => array(
      '#type' => 'textarea',
      '#title' => t('Body'),
      '#default_value' => t('Reroute Email Body'),
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Send email'),
    ),
  );
}

/**
 * Submit handler for email test.
 */
function reroute_email_test_email_form_submit(&$form, &$form_state) {
  $to = $form_state['values']['to'];
  $param_keys = array('cc', 'bcc', 'subject', 'body');
  $params = array_intersect_key($form_state['values'], array_flip($param_keys));
  $message = drupal_mail('reroute_email', 'test_email_form', $to, language_default(), $params);
  if (!empty($message['result'])) {
    drupal_set_message(t('Test email submitted for delivery.'));
  }
}
