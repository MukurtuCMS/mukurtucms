<?php
/**
 * @file
 * ma_dictionary.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_dictionary_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create dictionary_word content'.
  $permissions['create dictionary_word content'] = array(
    'name' => 'create dictionary_word content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any dictionary_word content'.
  $permissions['delete any dictionary_word content'] = array(
    'name' => 'delete any dictionary_word content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dictionary_word content'.
  $permissions['delete own dictionary_word content'] = array(
    'name' => 'delete own dictionary_word content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any dictionary_word content'.
  $permissions['edit any dictionary_word content'] = array(
    'name' => 'edit any dictionary_word content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dictionary_word content'.
  $permissions['edit own dictionary_word content'] = array(
    'name' => 'edit own dictionary_word content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
