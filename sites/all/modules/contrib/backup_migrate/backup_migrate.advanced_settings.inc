<?php

/**
 * @file
 * Functionality required for the advanced settings form.
 */

/**
 * The advanced settings form.
 */
function backup_migrate_ui_advanced_settings_form($form, &$form_state) {
  $form['backup_migrate_advanced_settings_intro'] = array(
    '#markup' => t('These settings should be handled with care, it is recommended to leave them at their defaults unless there is a specific need to modify them.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  $form['backup_migrate_memory_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Memory Limit'),
    '#default_value' => variable_get('backup_migrate_memory_limit', BACKUP_MIGRATE_MEMORY_LIMIT),
    '#description' => t('If backups fail due to an out-of-memory, try adjusting the memory limit using a php.ini style value, for example 512M for 512 megabytes or 1G for 1 gigabyte. Default: !default.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_MEMORY_LIMIT) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('backup_migrate_memory_limit_validate'),
  );
  $form['backup_migrate_backup_max_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time Limit'),
    '#default_value' => variable_get('backup_migrate_backup_max_time', BACKUP_MIGRATE_BACKUP_MAX_TIME),
    '#description' => t('If backups fail due to a PHP timeout error, especially an error saying "MySQL server has gone away", increase this setting. Before doing this, check to see what PHP\'s "max_execution_time" is set to, then set this field to a higher number, e.g. if max_execution_time is 180 (seconds) try setting Time Limit to 240 seconds (4 minutes), or 300 seconds (5 minutes). Default: !default.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_BACKUP_MAX_TIME) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['backup_migrate_verbose'] = array(
    '#type' => 'checkbox',
    '#title' => t('Verbose Output'),
    '#default_value' => variable_get('backup_migrate_verbose', BACKUP_MIGRATE_VERBOSE),
    '#description' => t('Enable this to make the module log additional messages to watchdog as the module performs certain actions. Default: !default.', array('!default' => (BACKUP_MIGRATE_VERBOSE ? 'on' : 'off'))),
    '#required' => FALSE,
  );
  $form['backup_migrate_disable_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Cron'),
    '#default_value' => variable_get('backup_migrate_disable_cron', BACKUP_MIGRATE_DISABLE_CRON),
    '#description' => t('It can be frustrating working from a production database backup on non-prod servers as schduled backups will automatically run via cron the same as they run on production. The custom cron tasks may be disabled using this checkbox. Note: this doesn\'t prevent people from manually running backups via the UI or from the Drush commands, so it is safe to enable on all site instances and then disable on production environments. Default: !default.', array('!default' => (BACKUP_MIGRATE_DISABLE_CRON ? 'on' : 'off'))),
    '#required' => FALSE,
  );
  $form['backup_migrate_data_rows_per_query'] = array(
    '#type' => 'textfield',
    '#title' => t('Rows Per Query'),
    '#default_value' => variable_get('backup_migrate_data_rows_per_query', BACKUP_MIGRATE_DATA_ROWS_PER_QUERY),
    '#description' => t('Controls how many records are loaded from the database at once. Defaults to "!default", i.e. !default rows. Note that setting this to a high number can cause problems when exporting large data sets, e.g. cache tables can have huge volumes of data per record.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_DATA_ROWS_PER_QUERY) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['backup_migrate_data_rows_per_line'] = array(
    '#type' => 'textfield',
    '#title' => t('Rows Per Line'),
    '#default_value' => variable_get('backup_migrate_data_rows_per_line', BACKUP_MIGRATE_DATA_ROWS_PER_LINE),
    '#description' => t('Controls how many records are included in a single INSERT statement. Defaults to "!default", i.e. !default records.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_DATA_ROWS_PER_LINE) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['backup_migrate_data_bytes_per_line'] = array(
    '#type' => 'textfield',
    '#title' => t('Data Bytes Per Line'),
    '#default_value' => variable_get('backup_migrate_data_bytes_per_line', BACKUP_MIGRATE_DATA_BYTES_PER_LINE),
    '#description' => t('Controls how much data will be inserted at once using a single INSERT statement. This works with the "backup_migrate_data_rows_per_line" variable to ensure that each INSERT statement doesn\'t end up being too large. Defaults to "!default", i.e. !default bytes.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_DATA_BYTES_PER_LINE) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['backup_migrate_max_email_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum E-mail Size'),
    '#default_value' => variable_get('backup_migrate_max_email_size', BACKUP_MIGRATE_MAX_EMAIL_SIZE),
    '#description' => t('In bytes. Limits the size of e-mails with attached back-ups that can be sent. Default: !default.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_MAX_EMAIL_SIZE) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('backup_migrate_unsigned_integer_validate'),
  );
  $form['backup_migrate_cleanup_temp_files'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clean up Temporary Files'),
    '#default_value' => variable_get('backup_migrate_cleanup_temp_files', BACKUP_MIGRATE_CLEANUP_TEMP_FILES),
    '#description' => t('Should temporary files be deleted during the current back-up run? Default: !default.', array('!default' => (BACKUP_MIGRATE_CLEANUP_TEMP_FILES ? 'on' : 'off'))),
    '#required' => FALSE,
  );
  $form['backup_migrate_cleanup_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Clean-up Time'),
    '#default_value' => variable_get('backup_migrate_cleanup_time', BACKUP_MIGRATE_CLEANUP_TIME),
    '#description' => t('Delete temporary files belonging to this modules that are older than the expire time. In seconds. 21600 seconds is 6 hours. Default: !default.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_CLEANUP_TIME) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('element_validate_integer'),
  );
  $form['backup_migrate_schedule_buffer'] = array(
    '#type' => 'textfield',
    '#title' => t('Schedule buffer'),
    '#default_value' => variable_get('backup_migrate_schedule_buffer', BACKUP_MIGRATE_SCHEDULE_BUFFER),
    '#description' => t('Add a small negative buffer (for example 1% of the entire period) to the time to account for slight difference in cron run length. Format: percentage of the period as a decimal fraction between 0 and 1. Default: !default.', array('!default' => '<kbd>' . check_plain(BACKUP_MIGRATE_SCHEDULE_BUFFER) . '</kbd>')),
    '#required' => FALSE,
    '#element_validate' => array('backup_migrate_fraction_validate'),
  );

  // Check for overrides and report them to the user.
  $keys = array_keys($form);
  $query = db_query('SELECT name, value FROM {variable} WHERE name IN (:keys)', array(':keys' => $keys));
  $result = $query->fetchAllKeyed();
  foreach ($form as $key => $field) {
    if (isset($result[$key])) {
      // Compare the value with what we have in the database.
      $db_value = unserialize($result[$key]);
      if ($field['#default_value'] != $db_value) {
        $form[$key]['#description'] .= ' <b>Overridden in settings.php: ' . check_plain($field['#default_value']) . '.</b>';
      }
    }
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * The advanced settings form.
 */
function backup_migrate_ui_advanced_settings_form_submit($form, &$form_state) {
  $variables = array(
    'backup_migrate_backup_max_time' => BACKUP_MIGRATE_BACKUP_MAX_TIME,
    'backup_migrate_cleanup_temp_files' => BACKUP_MIGRATE_CLEANUP_TEMP_FILES,
    'backup_migrate_cleanup_time' => BACKUP_MIGRATE_CLEANUP_TIME,
    'backup_migrate_data_bytes_per_line' => BACKUP_MIGRATE_DATA_BYTES_PER_LINE,
    'backup_migrate_data_rows_per_line' => BACKUP_MIGRATE_DATA_ROWS_PER_LINE,
    'backup_migrate_data_rows_per_query' => BACKUP_MIGRATE_DATA_ROWS_PER_QUERY,
    'backup_migrate_disable_cron' => BACKUP_MIGRATE_DISABLE_CRON,
    'backup_migrate_max_email_size' => BACKUP_MIGRATE_MAX_EMAIL_SIZE,
    'backup_migrate_memory_limit' => BACKUP_MIGRATE_MEMORY_LIMIT,
    'backup_migrate_schedule_buffer' => BACKUP_MIGRATE_SCHEDULE_BUFFER,
    'backup_migrate_verbose' => BACKUP_MIGRATE_VERBOSE,
  );
  foreach ($variables as $var_name => $var_default) {
    if (isset($form_state['values'][$var_name])) {
      // There's no need to save the variable if it's just the default.
      if ($form_state['values'][$var_name] == $var_default) {
        variable_del($var_name);
      }
      // The variable is not the default, so save it.
      else {
        variable_set($var_name, $form_state['values'][$var_name]);
      }
    }
  }
}

/**
 * Validate fields that require a PHP.ini-like memory_limit value.
 */
function backup_migrate_memory_limit_validate($element, &$form_state, $form) {
  if (!_backup_migrate_is_valid_memory_limit($element['#value'])) {
    form_error($element, t('%name must be a valid memory limit setting.', array('%name' => $element['#title'])));
  }
}

/**
 * Validate fields that require zero or a positive integer.
 */
function backup_migrate_unsigned_integer_validate($element, &$form_state, $form) {
  $value = $element['#value'];
  $test = preg_match('/^[0-9]+$/', $value);
  if ($test !== 1) {
    form_error($element, t('%name must be zero or a positive integer.', array('%name' => $element['#title'])));
  }
}

/**
 * Validate fields that require a decimal between 0 and 1.
 *
 * @todo Better name.
 */
function backup_migrate_fraction_validate($element, &$form_state, $form) {
  $value = $element['#value'];
  $test = preg_match('/^(0|1|0?\.[0-9]+)$/', $value);
  if ($test !== 1) {
    form_error($element, t('%name must be a decimal between 0 and 1.', array('%name' => $element['#title'])));
  }
}
