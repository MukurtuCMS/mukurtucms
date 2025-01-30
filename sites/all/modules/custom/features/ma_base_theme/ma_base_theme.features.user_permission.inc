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

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

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

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
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

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
