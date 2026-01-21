<?php

/**
 * @file
 * Drush integration providing scald_index tasks.
 */

/**
 * Implements hook_drush_command().
 */
function scald_index_drush_command() {
  return array(
    'scald-index-generate' => array(
      'description' => 'Generate Scald index.',
      'drupal dependencies' => array('scald_index'),
      'aliases' => array('sigen'),
    ),
  );
}

/**
 * Generate Scald sitemap files.
 */
function drush_scald_index_generate() {
  // Deleting old entries.
  drush_print(dt('Deleting old scald index...'));
  db_delete('scald_index')->execute();
  drush_print(dt('Scald index deletion ok.'));

  drush_print(dt('Generating scald index...'));

  $nids = db_query('SELECT nid FROM {node}')->fetchCol();

  // Create the batch.
  $batch = array(
    'title' => t('Generate Scald index.'),
    'operations' => array(
      array('scald_index_rebuild_run', array($nids)),
    ),
    'progress_message' => '',
    'progressive' => FALSE
  );
  batch_set($batch);

  // Throw batch.
  drush_backend_batch_process();

  drush_print(dt('Scald index generation ok.'));
}
