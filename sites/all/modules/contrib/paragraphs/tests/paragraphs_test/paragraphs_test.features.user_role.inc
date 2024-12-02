<?php

/**
 * @file
 * paragraphs_test.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function paragraphs_test_user_default_roles() {
  $roles = array();

  // Exported role: ptest creator.
  $roles['ptest creator'] = array(
    'name' => 'ptest creator',
    'weight' => 2,
  );

  return $roles;
}
