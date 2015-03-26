<?php
/**
 * @file
 * ma_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ma_core_user_default_roles() {
  $roles = array();

  // Exported role: Curator.
  $roles['Curator'] = array(
    'name' => 'Curator',
    'weight' => 5,
  );

  return $roles;
}
