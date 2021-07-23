<?php

/**
 * @file
 * ma_collaboration_tools.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ma_collaboration_tools_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:cultural_protocol_group:contributor'.
  $roles['node:cultural_protocol_group:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'cultural_protocol_group',
    'name' => 'contributor',
  );

  // Exported OG Role: 'node:cultural_protocol_group:protocol steward'.
  $roles['node:cultural_protocol_group:protocol steward'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'cultural_protocol_group',
    'name' => 'protocol steward',
  );

  return $roles;
}
