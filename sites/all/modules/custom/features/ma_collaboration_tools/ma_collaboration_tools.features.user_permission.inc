<?php

/**
 * @file
 * ma_collaboration_tools.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_collaboration_tools_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access draggableviews'.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'draggableviews',
  );

  // Exported permission: 'create following_notification content'.
  $permissions['create following_notification content'] = array(
    'name' => 'create following_notification content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any following_notification content'.
  $permissions['delete any following_notification content'] = array(
    'name' => 'delete any following_notification content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own following_notification content'.
  $permissions['delete own following_notification content'] = array(
    'name' => 'delete own following_notification content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any following_notification content'.
  $permissions['edit any following_notification content'] = array(
    'name' => 'edit any following_notification content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own following_notification content'.
  $permissions['edit own following_notification content'] = array(
    'name' => 'edit own following_notification content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any following_notification content'.
  $permissions['view any following_notification content'] = array(
    'name' => 'view any following_notification content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own following_notification content'.
  $permissions['view own following_notification content'] = array(
    'name' => 'view own following_notification content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node_view_permissions',
  );

  return $permissions;
}
