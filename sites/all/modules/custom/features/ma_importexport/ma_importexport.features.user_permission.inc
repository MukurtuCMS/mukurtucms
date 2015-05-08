<?php
/**
 * @file
 * ma_importexport.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_importexport_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'clear digital_heritage_metadata feeds'.
  $permissions['clear digital_heritage_metadata feeds'] = array(
    'name' => 'clear digital_heritage_metadata feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear import_collection feeds'.
  $permissions['clear import_collection feeds'] = array(
    'name' => 'clear import_collection feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'export media in zip format'.
  $permissions['export media in zip format'] = array(
    'name' => 'export media in zip format',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'zip_export_media',
  );

  // Exported permission: 'import digital_heritage_metadata feeds'.
  $permissions['import digital_heritage_metadata feeds'] = array(
    'name' => 'import digital_heritage_metadata feeds',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import import_collection feeds'.
  $permissions['import import_collection feeds'] = array(
    'name' => 'import import_collection feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper digital_heritage_metadata'.
  $permissions['tamper digital_heritage_metadata'] = array(
    'name' => 'tamper digital_heritage_metadata',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper import_collection'.
  $permissions['tamper import_collection'] = array(
    'name' => 'tamper import_collection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  return $permissions;
}
