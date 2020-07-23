<?php

/**
 * @file
 * ma_culturalprotocol.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_culturalprotocol_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cultural_protocol_group content'.
  $permissions['create cultural_protocol_group content'] = array(
    'name' => 'create cultural_protocol_group content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cultural_protocol_group content'.
  $permissions['delete any cultural_protocol_group content'] = array(
    'name' => 'delete any cultural_protocol_group content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cultural_protocol_group content'.
  $permissions['delete own cultural_protocol_group content'] = array(
    'name' => 'delete own cultural_protocol_group content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any cultural_protocol_group content'.
  $permissions['edit any cultural_protocol_group content'] = array(
    'name' => 'edit any cultural_protocol_group content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cultural_protocol_group content'.
  $permissions['edit own cultural_protocol_group content'] = array(
    'name' => 'edit own cultural_protocol_group content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
