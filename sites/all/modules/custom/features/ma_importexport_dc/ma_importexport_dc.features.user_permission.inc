<?php

/**
 * @file
 * ma_importexport_dc.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_importexport_dc_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clear digital_heritage_dc feeds'.
  $permissions['clear digital_heritage_dc feeds'] = array(
    'name' => 'clear digital_heritage_dc feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear digital_heritage_mods feeds'.
  $permissions['clear digital_heritage_mods feeds'] = array(
    'name' => 'clear digital_heritage_mods feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import digital_heritage_dc feeds'.
  $permissions['import digital_heritage_dc feeds'] = array(
    'name' => 'import digital_heritage_dc feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import digital_heritage_mods feeds'.
  $permissions['import digital_heritage_mods feeds'] = array(
    'name' => 'import digital_heritage_mods feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper digital_heritage_dc'.
  $permissions['tamper digital_heritage_dc'] = array(
    'name' => 'tamper digital_heritage_dc',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper digital_heritage_mods'.
  $permissions['tamper digital_heritage_mods'] = array(
    'name' => 'tamper digital_heritage_mods',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock digital_heritage_dc feeds'.
  $permissions['unlock digital_heritage_dc feeds'] = array(
    'name' => 'unlock digital_heritage_dc feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock digital_heritage_mods feeds'.
  $permissions['unlock digital_heritage_mods feeds'] = array(
    'name' => 'unlock digital_heritage_mods feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  return $permissions;
}
