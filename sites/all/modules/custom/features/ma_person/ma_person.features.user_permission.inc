<?php
/**
 * @file
 * ma_person.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ma_person_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create paragraph content person_relationship_bundle'.
  $permissions['create paragraph content person_relationship_bundle'] = array(
    'name' => 'create paragraph content person_relationship_bundle',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'create paragraph content text_section'.
  $permissions['create paragraph content text_section'] = array(
    'name' => 'create paragraph content text_section',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'create person content'.
  $permissions['create person content'] = array(
    'name' => 'create person content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any person content'.
  $permissions['delete any person content'] = array(
    'name' => 'delete any person content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own person content'.
  $permissions['delete own person content'] = array(
    'name' => 'delete own person content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete paragraph content person_relationship_bundle'.
  $permissions['delete paragraph content person_relationship_bundle'] = array(
    'name' => 'delete paragraph content person_relationship_bundle',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'delete paragraph content text_section'.
  $permissions['delete paragraph content text_section'] = array(
    'name' => 'delete paragraph content text_section',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'delete terms in interpersonal_relationship'.
  $permissions['delete terms in interpersonal_relationship'] = array(
    'name' => 'delete terms in interpersonal_relationship',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any person content'.
  $permissions['edit any person content'] = array(
    'name' => 'edit any person content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own person content'.
  $permissions['edit own person content'] = array(
    'name' => 'edit own person content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in interpersonal_relationship'.
  $permissions['edit terms in interpersonal_relationship'] = array(
    'name' => 'edit terms in interpersonal_relationship',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'merge interpersonal_relationship terms'.
  $permissions['merge interpersonal_relationship terms'] = array(
    'name' => 'merge interpersonal_relationship terms',
    'roles' => array(),
    'module' => 'term_merge',
  );

  // Exported permission: 'update paragraph content person_relationship_bundle'.
  $permissions['update paragraph content person_relationship_bundle'] = array(
    'name' => 'update paragraph content person_relationship_bundle',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'update paragraph content text_section'.
  $permissions['update paragraph content text_section'] = array(
    'name' => 'update paragraph content text_section',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content person_relationship_bundle'.
  $permissions['view paragraph content person_relationship_bundle'] = array(
    'name' => 'view paragraph content person_relationship_bundle',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content text_section'.
  $permissions['view paragraph content text_section'] = array(
    'name' => 'view paragraph content text_section',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  return $permissions;
}
