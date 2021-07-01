<?php

/**
 * @file
 * Plugin definition for duplicate suggestion based on names.
 */

$plugin = array(
  'title' => t('Terms names are the same'),
  'description' => t('Mark terms as duplicates if they have the same name.'),
  'hash callback' => 'term_merge_duplicate_suggestion_name_hash',
  'weight' => -10,
);

/**
 * Hash term based on its name.
 */
function term_merge_duplicate_suggestion_name_hash($term) {
  // Making upper case.
  $name = drupal_strtoupper($term->name);
  // Trying transliteration, if available.
  if (module_exists('transliteration')) {
    $name = transliteration_get($name);
    // Keeping only ASCII chars.
    $name = preg_replace('#\W#', '', $name);
  }
  return $name;
}
