<?php

/**
 * @file
 * ma_dictionary.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ma_dictionary_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:language_community:language contributor'.
  $roles['node:language_community:language contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'language_community',
    'name' => 'language contributor',
  );

  // Exported OG Role: 'node:language_community:language steward'.
  $roles['node:language_community:language steward'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'language_community',
    'name' => 'language steward',
  );

  return $roles;
}
