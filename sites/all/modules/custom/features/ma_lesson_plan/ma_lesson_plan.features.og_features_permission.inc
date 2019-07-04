<?php

/**
 * @file
 * ma_lesson_plan.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ma_lesson_plan_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:cultural_protocol_group:create unit_plan content'
  $permissions['node:cultural_protocol_group:create unit_plan content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any unit_plan content'
  $permissions['node:cultural_protocol_group:delete any unit_plan content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own unit_plan content'
  $permissions['node:cultural_protocol_group:delete own unit_plan content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any unit_plan content'
  $permissions['node:cultural_protocol_group:update any unit_plan content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own unit_plan content'
  $permissions['node:cultural_protocol_group:update own unit_plan content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  return $permissions;
}
