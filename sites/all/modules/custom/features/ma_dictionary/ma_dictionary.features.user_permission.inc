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

  // Exported permission: 'administer paragraphs bundles'.
  $permissions['administer paragraphs bundles'] = array(
    'name' => 'administer paragraphs bundles',
    'roles' => array(
      'Curator' => 'Curator',
    ),
    'module' => 'paragraphs',
  );

  // Exported permission: 'bypass paragraphs bundle content access'.
  $permissions['bypass paragraphs bundle content access'] = array(
    'name' => 'bypass paragraphs bundle content access',
    'roles' => array(
      'Curator' => 'Curator',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'create dictionary_word content'.
  $permissions['create dictionary_word content'] = array(
    'name' => 'create dictionary_word content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create language_community content'.
  $permissions['create language_community content'] = array(
    'name' => 'create language_community content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create paragraph content dictionary_word_bundle'.
  $permissions['create paragraph content dictionary_word_bundle'] = array(
    'name' => 'create paragraph content dictionary_word_bundle',
    'roles' => array(),
    'module' => 'paragraphs_bundle_permissions',
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

  // Exported permission: 'delete any language_community content'.
  $permissions['delete any language_community content'] = array(
    'name' => 'delete any language_community content',
    'roles' => array(),
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

  // Exported permission: 'delete own language_community content'.
  $permissions['delete own language_community content'] = array(
    'name' => 'delete own language_community content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete paragraph content dictionary_word_bundle'.
  $permissions['delete paragraph content dictionary_word_bundle'] = array(
    'name' => 'delete paragraph content dictionary_word_bundle',
    'roles' => array(),
    'module' => 'paragraphs_bundle_permissions',
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

  // Exported permission: 'edit any language_community content'.
  $permissions['edit any language_community content'] = array(
    'name' => 'edit any language_community content',
    'roles' => array(),
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

  // Exported permission: 'edit own language_community content'.
  $permissions['edit own language_community content'] = array(
    'name' => 'edit own language_community content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'update paragraph content dictionary_word_bundle'.
  $permissions['update paragraph content dictionary_word_bundle'] = array(
    'name' => 'update paragraph content dictionary_word_bundle',
    'roles' => array(),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content dictionary_word_bundle'.
  $permissions['view paragraph content dictionary_word_bundle'] = array(
    'name' => 'view paragraph content dictionary_word_bundle',
    'roles' => array(),
    'module' => 'paragraphs_bundle_permissions',
  );

  return $permissions;
}
