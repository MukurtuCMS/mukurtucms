<?php

/**
 * @file
 * Plugin definition for duplicate suggestion based on parents.
 */

$plugin = array(
  'title' => t('Terms parents are the same'),
  'description' => t('Mark terms as duplicates if they have the same parent.'),
  'hash callback' => 'term_merge_duplicate_suggestion_parent_hash',
);

/**
 * Hash term based on its parent.
 */
function term_merge_duplicate_suggestion_parent_hash($term) {
  return $term->parents[0];
}
