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
      'administrator' => 'administrator',
    ),
    'module' => 'paragraphs',
  );

  // Exported permission: 'administer part_of_speech vocabulary terms'.
  $permissions['administer part_of_speech vocabulary terms'] = array(
    'name' => 'administer part_of_speech vocabulary terms',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'bypass paragraphs bundle content access'.
  $permissions['bypass paragraphs bundle content access'] = array(
    'name' => 'bypass paragraphs bundle content access',
    'roles' => array(
      'administrator' => 'administrator',
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
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create paragraph content dictionary_word_bundle'.
  $permissions['create paragraph content dictionary_word_bundle'] = array(
    'name' => 'create paragraph content dictionary_word_bundle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
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

  // Exported permission: 'delete own language_community content'.
  $permissions['delete own language_community content'] = array(
    'name' => 'delete own language_community content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete paragraph content dictionary_word_bundle'.
  $permissions['delete paragraph content dictionary_word_bundle'] = array(
    'name' => 'delete paragraph content dictionary_word_bundle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'delete terms in part_of_speech'.
  $permissions['delete terms in part_of_speech'] = array(
    'name' => 'delete terms in part_of_speech',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'edit own language_community content'.
  $permissions['edit own language_community content'] = array(
    'name' => 'edit own language_community content',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in part_of_speech'.
  $permissions['edit terms in part_of_speech'] = array(
    'name' => 'edit terms in part_of_speech',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'merge part_of_speech terms'.
  $permissions['merge part_of_speech terms'] = array(
    'name' => 'merge part_of_speech terms',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'update paragraph content dictionary_word_bundle'.
  $permissions['update paragraph content dictionary_word_bundle'] = array(
    'name' => 'update paragraph content dictionary_word_bundle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content dictionary_word_bundle'.
  $permissions['view paragraph content dictionary_word_bundle'] = array(
    'name' => 'view paragraph content dictionary_word_bundle',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  return $permissions;
}
