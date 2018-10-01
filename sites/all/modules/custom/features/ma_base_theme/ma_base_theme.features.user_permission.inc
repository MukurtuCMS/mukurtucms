<?php
/**
 * @file
 * ma_base_theme.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_base_theme_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any hero_image_one_column bean'.
  $permissions['create any hero_image_one_column bean'] = array(
    'name' => 'create any hero_image_one_column bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any hero_image_two_columns bean'.
  $permissions['create any hero_image_two_columns bean'] = array(
    'name' => 'create any hero_image_two_columns bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any hero_image_one_column bean'.
  $permissions['delete any hero_image_one_column bean'] = array(
    'name' => 'delete any hero_image_one_column bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any hero_image_two_columns bean'.
  $permissions['delete any hero_image_two_columns bean'] = array(
    'name' => 'delete any hero_image_two_columns bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any hero_image_one_column bean'.
  $permissions['edit any hero_image_one_column bean'] = array(
    'name' => 'edit any hero_image_one_column bean',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any hero_image_two_columns bean'.
  $permissions['edit any hero_image_two_columns bean'] = array(
    'name' => 'edit any hero_image_two_columns bean',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any hero_image_one_column bean'.
  $permissions['view any hero_image_one_column bean'] = array(
    'name' => 'view any hero_image_one_column bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any hero_image_two_columns bean'.
  $permissions['view any hero_image_two_columns bean'] = array(
    'name' => 'view any hero_image_two_columns bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
