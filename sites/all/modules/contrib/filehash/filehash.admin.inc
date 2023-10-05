<?php

/**
 * @file
 * File Hash configuration.
 */

/**
 * Builds the File Hash settings form.
 */
function filehash_settings() {
  $form['filehash_algos'] = array(
    '#default_value' => variable_get('filehash_algos', array()),
    '#description' => t('The checked hash algorithm(s) will be calculated when a file is saved. For optimum performance, only enable the hash algorithm(s) you need.'),
    '#options' => filehash_names(),
    '#title' => t('Enabled hash algorithms'),
    '#type' => 'checkboxes',
  );
  $form['filehash_local_only'] = array(
    '#default_value' => variable_get('filehash_local_only', FALSE),
    '#description' => t('If checked, file hashes will be generated only for files using local stream wrappers (public, temporary, etc.).'),
    '#title' => t('Hash local files only'),
    '#type' => 'checkbox',
  );
  $form['filehash_dedupe'] = array(
    '#default_value' => variable_get('filehash_dedupe', 0),
    '#description' => t('If checked, prevent duplicate uploaded files from being saved. Note, enabling this setting has privacy implications, as it allows users to determine if a particular file has been uploaded to the site.'),
    '#title' => t('Disallow duplicate files'),
    '#type' => 'checkbox',
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'filehash_settings_submit';
  $form['#attached']['css'][] = drupal_get_path('module', 'filehash') . '/filehash.css';
  return $form;
}

/**
 * Settings submit callback.
 */
function filehash_settings_submit() {
  filehash_add_columns();
}

/**
 * Builds the File Hash bulk generate form.
 */
function filehash_bulk() {
  $form['explanation'] = array(
    '#type' => 'item',
    '#description' => t('Use this button to generate hashes for each uploaded file. Existing hashes will be left untouched.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Bulk generate file hashes'),
  );
  return $form;
}

/**
 * Submit callback for File Hash bulk generate.
 */
function filehash_bulk_submit($form, &$form_state) {
  if (!filehash_algos()) {
    drupal_set_message(t('You have no enabled hash algorithms. Nothing to do.'));
    return;
  }
  batch_set(array(
    'operations' => array(array('filehash_bulk_process', array())),
    'finished' => 'filehash_bulk_finished',
    'title' => t('Generating file hashes'),
    'init_message' => t('File hash generation is starting.'),
    'progress_message' => t('Please wait...'),
    'error_message' => t('File hash generation has encountered an error.'),
    'file' => drupal_get_path('module', 'filehash') . '/filehash.admin.inc',
  ));
}

/**
 * Batch generate file hashes.
 */
function filehash_bulk_process(&$context) {
  if (!isset($context['results']['processed'])) {
    $context['results']['processed'] = 0;
    $query = new EntityFieldQuery();
    $context['sandbox']['count'] = $query->entityCondition('entity_type', 'file')->addMetaData('account', user_load(1))->count()->execute();
  }
  $query = new EntityFieldQuery();
  $files = $query->entityCondition('entity_type', 'file')->addMetaData('account', user_load(1))->range($context['results']['processed'], 1)->execute();
  foreach ($files['file'] as $file) {
    $file = file_load($file->fid);
    $context['message'] = t('Processed file ID !fid (%filename).', array(
      '!fid' => $file->fid,
      '%filename' => $file->filename,
    ));
    $context['results']['processed']++;
    $context['finished'] = $context['results']['processed'] / $context['sandbox']['count'];
  }
}

/**
 * Batch finish callback.
 */
function filehash_bulk_finished($success, $results, $operations) {
  $variables = array('@processed' => $results['processed']);
  if ($success) {
    drupal_set_message(t('Processed all @processed files and generated any missing file hashes.', $variables));
  }
  else {
    drupal_set_message(t('An error occurred after processing @processed files.', $variables), 'warning');
  }
}

/**
 * Builds the File Hash clean up form.
 */
function filehash_clean() {
  $columns = filehash_get_disabled_columns_with_data();
  if (!$columns) {
    drupal_set_message(t('All clean! No disabled hash algorithms are installed.'));
    return;
  }
  $form['explanation'] = array(
    '#type' => 'item',
    '#description' => t('Are you sure you want to delete data for disabled hash algorithms? @count hash algorithm columns (@algos) will be purged from the database.', array(
      '@count' => count($columns),
      '@algos' => implode(', ', $columns),
    )),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete data'),
  );
  return $form;
}

/**
 * Submit callback for File Hash clean up.
 */
function filehash_clean_submit($form, &$form_state) {
  batch_set(array(
    'operations' => array(array('filehash_clean_process', array())),
    'finished' => 'filehash_clean_finished',
    'title' => t('Removing disabled database columns'),
    'init_message' => t('File hash clean up is starting.'),
    'progress_message' => t('Please wait...'),
    'error_message' => t('File hash clean up has encountered an error.'),
    'file' => drupal_get_path('module', 'filehash') . '/filehash.admin.inc',
  ));
}

/**
 * Returns an arry of disabled hash algorithms that have a database column.
 */
function filehash_get_disabled_columns_with_data() {
  $columns = array();
  $enabled = filehash_columns();
  foreach (filehash_names() as $column => $name) {
    if (empty($enabled[$column]) && db_field_exists('filehash', $column)) {
      $columns[$column] = $name;
    }
  }
  return $columns;
}

/**
 * Drops database columns for disabled hash algorithms.
 */
function filehash_clean_process(&$context) {
  $columns = filehash_get_disabled_columns_with_data();
  if (!isset($context['results']['processed'])) {
    $context['results']['processed'] = 0;
    $context['sandbox']['count'] = count($columns);
  }
  foreach ($columns as $column => $name) {
    db_drop_field('filehash', $column);
    $context['results']['processed']++;
    $context['message'] = t('Dropped %name column.', array('%name' => $name));
    break;
  }
  $context['finished'] = $context['sandbox']['count'] ? ($context['results']['processed'] / $context['sandbox']['count']) : 1;
}

/**
 * Batch finish callback.
 */
function filehash_clean_finished($success, $results, $operations) {
  $variables = array('@processed' => $results['processed']);
  if ($success) {
    drupal_set_message(format_plural($results['processed'], 'Processed @processed hash algorithm column.', 'Processed @processed hash algorithm columns.', $variables));
  }
  else {
    drupal_set_message(format_plural($results['processed'], 'An error occurred after processing @processed hash algorithm column.', 'An error occurred after processing @processed hash algorithm columns.', $variables), 'warning');
  }
}
