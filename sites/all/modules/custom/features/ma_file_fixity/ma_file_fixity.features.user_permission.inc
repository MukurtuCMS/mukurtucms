<?php

/**
 * @file
 * ma_file_fixity.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_file_fixity_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fixity_check content'.
  $permissions['create fixity_check content'] = array(
    'name' => 'create fixity_check content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any fixity_check content'.
  $permissions['delete any fixity_check content'] = array(
    'name' => 'delete any fixity_check content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own fixity_check content'.
  $permissions['delete own fixity_check content'] = array(
    'name' => 'delete own fixity_check content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any fixity_check content'.
  $permissions['edit any fixity_check content'] = array(
    'name' => 'edit any fixity_check content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own fixity_check content'.
  $permissions['edit own fixity_check content'] = array(
    'name' => 'edit own fixity_check content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any fixity_check content'.
  $permissions['view any fixity_check content'] = array(
    'name' => 'view any fixity_check content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own fixity_check content'.
  $permissions['view own fixity_check content'] = array(
    'name' => 'view own fixity_check content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node_view_permissions',
  );

  return $permissions;
}
