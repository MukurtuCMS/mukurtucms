<?php
/**
 * @file
 * Admin stuff for the Mail Logger module.
 */

/**
 * Mail Logger admin form.
 */
function mail_logger_admin_settings_form($form, &$form_state) {
  $options_log_maximum_age = array(
    0 => t('Never'),
  );
  $time_intervals = array(
    0,
    86400,     // 1 day.
    172800,    // 2 days.
    259200,    // 3 days.
    604800,    // 7 days.
    1209600,   // 14 days (2 weeks).
    2592000,   // 30 days (1 month).
    5184000,   // 60 days (2 months).
    7776000,   // 90 days (3 months).
    15552000,  // 180 days (6 months).
    31536000,  // 365 days (1 year).
    63072000,  // 730 days (2 years).
    94608000,  // 1095 days (3 years).
    157680000, // 1825 days (5 years).
    315360000, // 3650 days (10 years),
  );
  $options_log_maximum_age += drupal_map_assoc($time_intervals, 'format_interval');
  $form['mail_logger_log_maximum_age'] = array(
    '#type' => 'select',
    '#title' => t('Discard mail logs older than'),
    '#default_value' => variable_get('mail_logger_log_maximum_age', 0),
    '#options' => $options_log_maximum_age,
    '#description' => t('Older log entries will be automatically discarded during cron. Requires a correctly configured <a href="@cron">cron maintenance task</a>. Choose "Never" if you don\'t want logs to be deleted.', array('@cron' => url('admin/reports/status'))),
  );

  $date_types = array();
  foreach (system_get_date_types() as $name => $info) {
    $date_types[$name] = $info['title'] . ' <small>(' . format_date(REQUEST_TIME, $name) . ')</small>';
  }
  $form['mail_logger_log_date_format'] = array(
    '#type' => 'radios',
    '#options' => $date_types,
    '#title' => t('Date format'),
    '#default_value' => variable_get('mail_logger_log_date_format', 'short'),
    '#description' => t('This format will be used in the log display page.'),
    );

  $form['mail_logger_log_lines_per_page'] = array(
    '#type' => 'radios',
    '#options' => array(10 => 10, 20 => 20, 30 => 30, 40 => 40, 50 => 50, 75 => 75, 100 => 100),
    '#title' => t('Lines per page'),
    '#default_value' => variable_get('mail_logger_log_lines_per_page', 50),
    '#description' => t('This is the number of lines that will appear on the log display page.'),
    );

  $form['mail_logger_log_empty_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Empty TO text'),
    '#default_value' => variable_get('mail_logger_log_empty_to', '* empty *'),
    '#description' => t('This will be used when there are no recipients in the "To" field.'),
    );

  $form['mail_logger_log_mail_body'] = array(
    '#type' => 'radios',
    '#options' => array(t('No'), t('Yes')),
    '#title' => t('Log the body of the mail.'),
    '#default_value' => variable_get('mail_logger_log_mail_body', 1),
    '#description' => t('This determines whether or not to include the body of the email in the log.')
      . ' '
      . t('Some sites, for security or privacy considerations, may elect to not rexord the body.'),
    '#attributes' => array('class' => array('container-inline')),
    );

  $form['mail_logger_log_exclude_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text to replace the body'),
    '#default_value' => variable_get('mail_logger_log_exclude_text', '[MESSAGE BODY EXCLUDED]'),
    '#description' => t('This text will be placed in the body area when lgging the email.'),
    '#states' => array(
      // Only show when previous field is "No".
      'visible' => array(
        ':input[name="mail_logger_log_mail_body"]' => array('value' => 0),
        ),
      ),
    );

  $form = system_settings_form($form);
  return $form;
}
