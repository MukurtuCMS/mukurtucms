<?php

/**
 * @file
 * paragraphs_test.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function paragraphs_test_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer paragraphs_item ptest choice'.
  $permissions['administer panelizer paragraphs_item ptest choice'] = array(
    'name' => 'administer panelizer paragraphs_item ptest choice',
    'roles' => array(
      'ptest creator' => 'ptest creator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer paragraphs_item ptest content'.
  $permissions['administer panelizer paragraphs_item ptest content'] = array(
    'name' => 'administer panelizer paragraphs_item ptest content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer paragraphs_item ptest context'.
  $permissions['administer panelizer paragraphs_item ptest context'] = array(
    'name' => 'administer panelizer paragraphs_item ptest context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer paragraphs_item ptest defaults'.
  $permissions['administer panelizer paragraphs_item ptest defaults'] = array(
    'name' => 'administer panelizer paragraphs_item ptest defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer paragraphs_item ptest layout'.
  $permissions['administer panelizer paragraphs_item ptest layout'] = array(
    'name' => 'administer panelizer paragraphs_item ptest layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer paragraphs_item ptest overview'.
  $permissions['administer panelizer paragraphs_item ptest overview'] = array(
    'name' => 'administer panelizer paragraphs_item ptest overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer paragraphs_item ptest settings'.
  $permissions['administer panelizer paragraphs_item ptest settings'] = array(
    'name' => 'administer panelizer paragraphs_item ptest settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer paragraphs bundles'.
  $permissions['administer paragraphs bundles'] = array(
    'name' => 'administer paragraphs bundles',
    'roles' => array(),
    'module' => 'paragraphs',
  );

  // Exported permission: 'create paragraph_test content'.
  $permissions['create paragraph_test content'] = array(
    'name' => 'create paragraph_test content',
    'roles' => array(
      'ptest creator' => 'ptest creator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any paragraph_test content'.
  $permissions['delete any paragraph_test content'] = array(
    'name' => 'delete any paragraph_test content',
    'roles' => array(
      'ptest creator' => 'ptest creator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own paragraph_test content'.
  $permissions['delete own paragraph_test content'] = array(
    'name' => 'delete own paragraph_test content',
    'roles' => array(
      'ptest creator' => 'ptest creator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any paragraph_test content'.
  $permissions['edit any paragraph_test content'] = array(
    'name' => 'edit any paragraph_test content',
    'roles' => array(
      'ptest creator' => 'ptest creator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own paragraph_test content'.
  $permissions['edit own paragraph_test content'] = array(
    'name' => 'edit own paragraph_test content',
    'roles' => array(
      'ptest creator' => 'ptest creator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
