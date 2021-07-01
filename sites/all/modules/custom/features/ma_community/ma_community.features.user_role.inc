<?php

/**
 * @file
 * ma_community.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ma_community_user_default_roles() {
  $roles = array();

  // Exported role: Community Administrator.
  $roles['Community Administrator'] = array(
    'name' => 'Community Administrator',
    'weight' => 6,
  );

  return $roles;
}
