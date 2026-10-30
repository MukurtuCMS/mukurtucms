<?php

/**
 * @file
 * Batch process callbacks for Term Merge module.
 */

/**
 * Process batch function.
 *
 * Trigger action 'term_merge_action' on each pair of term branch:term trunk.
 *
 * @param array $term_branch
 *   An array of term tids to be merged, aka term branches
 * @param int $term_trunk
 *   The tid of the term to merge term branches into, aka term trunk
 * @param array $merge_settings
 *   Array of settings that control how merging should happen. Currently
 *   supported settings are:
 *     - term_branch_keep: (bool) Whether the term branches should not be
 *       deleted, also known as "merge only occurrences" option
 *     - merge_fields: (array) Array of field names whose values should be
 *       merged into the values of corresponding fields of term trunk (until
 *       each field's cardinality limit is reached)
 *     - keep_only_unique: (bool) Whether after merging within one field only
 *       unique taxonomy term references should be kept in other entities. If
 *       before merging your entity had 2 values in its taxonomy term reference
 *       field and one was pointing to term branch while another was pointing to
 *       term trunk, after merging you will end up having your entity
 *       referencing to the same term trunk twice. If you pass TRUE in this
 *       parameter, only a single reference will be stored in your entity after
 *       merging
 *     - redirect: (int) HTTP code for redirect from $term_branch to
 *       $term_trunk, 0 stands for the default redirect defined in Redirect
 *       module. Use constant TERM_MERGE_NO_REDIRECT to denote not creating any
 *       HTTP redirect. Note: this parameter requires Redirect module enabled,
 *       otherwise it will be disregarded
 *     - synonyms: (string) Optional field name of trunk term into which branch
 *       terms should be added as synonyms (until field's cardinality limit
 *       is reached). Note: this parameter requires Synonyms module enabled,
 *       otherwise it will be disregarded
 *     - step: (int) How many term branches to merge per script run in batch. If
 *       you are hitting time or memory limits, decrease this parameter
 * @param array $context
 *   Drupal Batch API context array
 */
function _term_merge_batch_process($term_branch, $term_trunk, $merge_settings, &$context) {
  // Initializing sandbox.
  if (!isset($context['sandbox']['current'])) {
    $context['sandbox']['current'] = 0;
  }

  // Populating $merge_settings with defaults.
  $merge_settings += array(
    'term_branch_keep' => FALSE,
    'merge_fields' => array(),
    'keep_only_unique' => TRUE,
    'redirect' => TERM_MERGE_NO_REDIRECT,
    'synonyms' => NULL,
    'step' => 40,
  );

  $total = count($term_branch);
  // To speed up the process we take advantage of taxonomy_term_load_multiple()
  // instead of just repeating calls to taxonomy_term_load().
  $till = min($total, $context['sandbox']['current'] + $merge_settings['step']);
  $length = $till - $context['sandbox']['current'];
  $term_branch = array_slice($term_branch, $context['sandbox']['current'], $length);
  $term_branch = array_values(taxonomy_term_load_multiple($term_branch));
  for ($i = 0; $i < $merge_settings['step'] && $context['sandbox']['current'] < $total; $i++) {
    actions_do('term_merge_action', $term_branch[$i], array(
      'term_trunk' => $term_trunk,
      'term_branch_keep' => $merge_settings['term_branch_keep'],
      'merge_fields' => $merge_settings['merge_fields'],
      'keep_only_unique' => $merge_settings['keep_only_unique'],
      'redirect' => $merge_settings['redirect'],
      'synonyms' => $merge_settings['synonyms'],
    ));
    $context['sandbox']['current']++;
  }

  if ($context['sandbox']['current'] != $total) {
    $context['finished'] = $context['sandbox']['current'] / $total;
    $term = $term_branch[$i - 1];
    $context['message'] = t('Merged up to @term', array('@term' => $term->name));
  }
}

/**
 * Batch 'finished' callback.
 *
 * Process results of Term Merge batch.
 */
function term_merge_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('The terms have been successfully merged.'));
  }
  else {
    // An error happened. We have to notify the user.
    drupal_set_message(t('An error occurred. We are sorry, please, report this error to the maintainers of Term Merge module.'), 'error');
  }
}
