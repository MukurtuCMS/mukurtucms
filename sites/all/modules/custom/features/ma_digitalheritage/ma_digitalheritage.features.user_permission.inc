<?php

/**
 * @file
 * ma_digitalheritage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_digitalheritage_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create digital_heritage content'.
  $permissions['create digital_heritage content'] = array(
    'name' => 'create digital_heritage content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any digital_heritage content'.
  $permissions['delete any digital_heritage content'] = array(
    'name' => 'delete any digital_heritage content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own digital_heritage content'.
  $permissions['delete own digital_heritage content'] = array(
    'name' => 'delete own digital_heritage content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any digital_heritage content'.
  $permissions['edit any digital_heritage content'] = array(
    'name' => 'edit any digital_heritage content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own digital_heritage content'.
  $permissions['edit own digital_heritage content'] = array(
    'name' => 'edit own digital_heritage content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'merge category terms'.
  $permissions['merge category terms'] = array(
    'name' => 'merge category terms',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  return $permissions;
}
