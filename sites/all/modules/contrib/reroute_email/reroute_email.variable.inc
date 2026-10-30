<?php

/**
 * @file
 * Variable module integration.
 */

/**
 * Implements hook_variable_info().
 */
function reroute_email_variable_info($options) {
  $variable[REROUTE_EMAIL_ENABLE] = array(
    'title' => t('Enable rerouting', array(), $options),
    'description' => t('Check this box if you want to enable email rerouting. Uncheck to disable rerouting.', array(), $options),
    'type' => 'boolean',
    'default' => 0,
    'group' => 'reroute_email',
  );

  $variable[REROUTE_EMAIL_ADDRESS] = array(
    'title' => t('Rerouting email addresses', array(), $options),
    'description' => t('Provide a space, comma, or semicolon-delimited list of email addresses.<br />Every destination email address which is not on "Whitelisted email addresses" list will be rerouted to these addresses.<br />If the field is empty and no value is provided, all outgoing emails would be aborted and the email would be recorded in the recent log entries (if enabled).', array(), $options),
    'type' => 'reroute_mail_addresses',
    'default' => variable_get('site_mail', ini_get('sendmail_from')),
    'group' => 'reroute_email',
  );

  $variable[REROUTE_EMAIL_WHITELIST] = array(
    'title' => t('Whitelisted email addresses', array(), $options),
    'description' => t('Provide a space, comma, or semicolon-delimited list of email addresses to pass through.<br />Every destination email address which is not on this list will be rerouted.<br />If the field is empty and no value is provided, all outgoing emails would be rerouted.<br />We can use wildcard email "*@example.com" to whitelist all emails by the domain.', array(), $options),
    'type' => 'reroute_mail_addresses',
    'default' => '',
    'group' => 'reroute_email',
  );

  $variable[REROUTE_EMAIL_ENABLE_MESSAGE] = array(
    'title' => t('Show rerouting description in mail body', array(), $options),
    'description' => t('Check this box if you want a message to be inserted into the email body when the mail is being rerouted. Otherwise, SMTP headers will be used to describe the rerouting. If sending rich-text email, leave this unchecked so that the body of the email will not be disturbed.', array(), $options),
    'type' => 'boolean',
    'default' => 1,
    'group' => 'reroute_email',
  );

  // Checkbox to enable the display of a Drupal message after rerouting email.
  $variable[REROUTE_EMAIL_ENABLE_DSM] = array(
    'title' => t('Display a Drupal status message after rerouting submitted email', array(), $options),
    'description' => t('Check this box if you would like a Drupal status message to be displayed to users after submitting an email to let them know it was aborted to send or rerouted to a different email address.', array(), $options),
    'type' => 'boolean',
    'default' => 1,
    'group' => 'reroute_email',
  );

  // Format a list of modules that implement hook_mail.
  $mail_modules = module_implements('mail');
  $all_modules = system_list('module_enabled');
  foreach ($mail_modules as $key => $module) {
    $mail_modules[$key] = t("%module's module possible mail keys are `!machine_name`, `!machine_name_%`;", array(
      '%module' => isset($all_modules[$module]->info['name']) ? $all_modules[$module]->info['name'] : $module,
      '!machine_name' => $module,
    ), $options);
  }
  $variable[REROUTE_EMAIL_MAIL_KEYS] = array(
    'title' => t('Mail Keys', array(), $options),
    'description' => t('Provide a space, comma, semicolon, or newline-delimited list of message keys to be rerouted. Either module machine name or specific mail key can be used for that.<br />Only matching messages will be rerouted. If left empty (as default), <strong>all emails will be selected for rerouting</strong>. Here is a list of modules that send emails:<br />!modules_list Where `%` is one of a specific mail key provided by the module.', array(
      '!modules_list' => theme('item_list', array('items' => $mail_modules)),
    ), $options),
    'default' => '',
    'group' => 'reroute_email',
  );

  return $variable;
}

/**
 * Implements hook_variable_group_info().
 */
function reroute_email_variable_group_info() {
  $groups['reroute_email'] = array(
    'title' => t('Reroute Email'),
    'description' => t('Reroute email configuration settings'),
    'access' => 'administer reroute email',
    'path' => array('admin/config/development/reroute_email'),
  );
  return $groups;
}

/**
 * Implements hook_variable_type_info().
 */
function reroute_email_variable_type_info() {
  $type['reroute_mail_addresses'] = array(
    'title' => t('Multiple e-mail addresses'),
    'element' => array(
      '#type' => 'textfield',
      '#element_validate' => array('reroute_email_element_validate_addresses'),
    ),
  );
  return $type;
}
