<?php

/**
 * @file
 * File hash configuration.
 */

/**
 * Builds the file hash settings form.
 */
function filehash_settings() {
  $form['filehash_algos'] = array(
    '#default_value' => variable_get('filehash_algos', array()),
    '#description' => t('The checked hash algorithm(s) will be calculated when a file is saved. For optimum performance, only enable the hash algorithm(s) you need.'),
    '#options' => filehash_names(),
    '#title' => t('Enabled hash algorithms'),
    '#type' => 'checkboxes',
  );
  $form['filehash_dedupe'] = array(
    '#default_value' => variable_get('filehash_dedupe', 0),
    '#description' => t('If checked, prevent duplicate uploaded files from being saved. Note, enabling this setting has privacy implications, as it allows users to determine if a particular file has been uploaded to the site.'),
    '#title' => t('Disallow duplicate files'),
    '#type' => 'checkbox',
  );
  return system_settings_form($form);
}

/**
 * Builds the file hash bulk generate form.
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
 * Submit callback for file hash bulk generate.
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
    $context['message'] = t('Processed file ID !fid (%filename).', array('!fid' => $file->fid, '%filename' => $file->filename));
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
