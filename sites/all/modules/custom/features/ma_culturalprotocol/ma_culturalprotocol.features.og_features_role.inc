<?php
/**
 * @file
 * ma_culturalprotocol.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ma_culturalprotocol_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:cultural_protocol_group:contributor'.
  $roles['node:cultural_protocol_group:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'cultural_protocol_group',
    'name' => 'contributor',
  );

  // Exported OG Role: 'node:cultural_protocol_group:protocol manager'.
  $roles['node:cultural_protocol_group:protocol manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'cultural_protocol_group',
    'name' => 'protocol manager',
  );

  return $roles;
}
