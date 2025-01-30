<?php

/**
 * @file
 * Holds relevant functions for paragraph Migrate API.
 */

/**
 * Implements hook_migrate_api().
 */
function paragraphs_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array(
      'ParagraphsMigrateParagraphsFieldHandler',
    ),
  );
}
