<?php

/**
 * @file
 * ma_community.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ma_community_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:community:community manager'.
  $roles['node:community:community manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'community',
    'name' => 'community manager',
  );

  return $roles;
}
