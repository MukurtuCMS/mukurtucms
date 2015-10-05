<?php
/**
 * @file
 * ma_glossary.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_glossary_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create glossary content'.
  $permissions['create glossary content'] = array(
    'name' => 'create glossary content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create glossary_term content'.
  $permissions['create glossary_term content'] = array(
    'name' => 'create glossary_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any glossary content'.
  $permissions['delete any glossary content'] = array(
    'name' => 'delete any glossary content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any glossary_term content'.
  $permissions['delete any glossary_term content'] = array(
    'name' => 'delete any glossary_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own glossary content'.
  $permissions['delete own glossary content'] = array(
    'name' => 'delete own glossary content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own glossary_term content'.
  $permissions['delete own glossary_term content'] = array(
    'name' => 'delete own glossary_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any glossary content'.
  $permissions['edit any glossary content'] = array(
    'name' => 'edit any glossary content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any glossary_term content'.
  $permissions['edit any glossary_term content'] = array(
    'name' => 'edit any glossary_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own glossary content'.
  $permissions['edit own glossary content'] = array(
    'name' => 'edit own glossary content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own glossary_term content'.
  $permissions['edit own glossary_term content'] = array(
    'name' => 'edit own glossary_term content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
