<?php

/**
 * @file
 * ma_community.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_community_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create community content'.
  $permissions['create community content'] = array(
    'name' => 'create community content',
    'roles' => array(
      'Community Administrator' => 'Community Administrator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any community content'.
  $permissions['delete any community content'] = array(
    'name' => 'delete any community content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own community content'.
  $permissions['delete own community content'] = array(
    'name' => 'delete own community content',
    'roles' => array(
      'Community Administrator' => 'Community Administrator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any community content'.
  $permissions['edit any community content'] = array(
    'name' => 'edit any community content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own community content'.
  $permissions['edit own community content'] = array(
    'name' => 'edit own community content',
    'roles' => array(
      'Community Administrator' => 'Community Administrator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
