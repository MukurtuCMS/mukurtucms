<?php
/**
 * @file
 * ma_media.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_media_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer image metadata'.
  $permissions['administer image metadata'] = array(
    'name' => 'administer image metadata',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'exif',
  );

  // Exported permission: 'administer oembed'.
  $permissions['administer oembed'] = array(
    'name' => 'administer oembed',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oembed',
  );

  return $permissions;
}
