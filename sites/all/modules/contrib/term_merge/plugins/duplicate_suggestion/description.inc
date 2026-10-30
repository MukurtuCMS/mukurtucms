<?php

/**
 * @file
 * Plugin definition for duplicate suggestion based on description.
 */

$plugin = array(
  'title' => t('Terms description are the same'),
  'description' => t('Mark terms as duplicates if they have the same description.'),
  'hash callback' => 'term_merge_duplicate_suggestion_description_hash',
);

/**
 * Hash term based on its description.
 */
function term_merge_duplicate_suggestion_description_hash($term) {
  return drupal_strtoupper($term->description);
}
