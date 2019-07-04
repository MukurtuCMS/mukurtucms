<?php

/**
 * @file
 * ma_lesson_plan.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_lesson_plan_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create lesson content'.
  $permissions['create lesson content'] = array(
    'name' => 'create lesson content',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create unit_plan content'.
  $permissions['create unit_plan content'] = array(
    'name' => 'create unit_plan content',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any lesson content'.
  $permissions['delete any lesson content'] = array(
    'name' => 'delete any lesson content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any unit_plan content'.
  $permissions['delete any unit_plan content'] = array(
    'name' => 'delete any unit_plan content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own lesson content'.
  $permissions['delete own lesson content'] = array(
    'name' => 'delete own lesson content',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own unit_plan content'.
  $permissions['delete own unit_plan content'] = array(
    'name' => 'delete own unit_plan content',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any lesson content'.
  $permissions['edit any lesson content'] = array(
    'name' => 'edit any lesson content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any unit_plan content'.
  $permissions['edit any unit_plan content'] = array(
    'name' => 'edit any unit_plan content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own lesson content'.
  $permissions['edit own lesson content'] = array(
    'name' => 'edit own lesson content',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own unit_plan content'.
  $permissions['edit own unit_plan content'] = array(
    'name' => 'edit own unit_plan content',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
