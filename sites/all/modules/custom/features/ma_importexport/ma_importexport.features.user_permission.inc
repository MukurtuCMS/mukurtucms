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

  // Exported permission: 'clear import_media_audio feeds'.
  $permissions['clear import_media_audio feeds'] = array(
    'name' => 'clear import_media_audio feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear import_media_files feeds'.
  $permissions['clear import_media_files feeds'] = array(
    'name' => 'clear import_media_files feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear import_media_images feeds'.
  $permissions['clear import_media_images feeds'] = array(
    'name' => 'clear import_media_images feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear import_media_video feeds'.
  $permissions['clear import_media_video feeds'] = array(
    'name' => 'clear import_media_video feeds',
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

  // Exported permission: 'import import_media_audio feeds'.
  $permissions['import import_media_audio feeds'] = array(
    'name' => 'import import_media_audio feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import import_media_files feeds'.
  $permissions['import import_media_files feeds'] = array(
    'name' => 'import import_media_files feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import import_media_images feeds'.
  $permissions['import import_media_images feeds'] = array(
    'name' => 'import import_media_images feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import import_media_video feeds'.
  $permissions['import import_media_video feeds'] = array(
    'name' => 'import import_media_video feeds',
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

  // Exported permission: 'tamper import_media_audio'.
  $permissions['tamper import_media_audio'] = array(
    'name' => 'tamper import_media_audio',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper import_media_files'.
  $permissions['tamper import_media_files'] = array(
    'name' => 'tamper import_media_files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper import_media_images'.
  $permissions['tamper import_media_images'] = array(
    'name' => 'tamper import_media_images',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper import_media_video'.
  $permissions['tamper import_media_video'] = array(
    'name' => 'tamper import_media_video',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper media_feed_importer'.
  $permissions['tamper media_feed_importer'] = array(
    'name' => 'tamper media_feed_importer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock import_media_audio feeds'.
  $permissions['unlock import_media_audio feeds'] = array(
    'name' => 'unlock import_media_audio feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock import_media_files feeds'.
  $permissions['unlock import_media_files feeds'] = array(
    'name' => 'unlock import_media_files feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock import_media_images feeds'.
  $permissions['unlock import_media_images feeds'] = array(
    'name' => 'unlock import_media_images feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock import_media_video feeds'.
  $permissions['unlock import_media_video feeds'] = array(
    'name' => 'unlock import_media_video feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  return $permissions;
}
