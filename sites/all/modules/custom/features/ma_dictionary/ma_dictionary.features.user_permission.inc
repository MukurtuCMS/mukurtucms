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

  // Exported permission: 'clear import_dictionary_word_additional_entries feeds'.
  $permissions['clear import_dictionary_word_additional_entries feeds'] = array(
    'name' => 'clear import_dictionary_word_additional_entries feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear import_dictionary_word_lists feeds'.
  $permissions['clear import_dictionary_word_lists feeds'] = array(
    'name' => 'clear import_dictionary_word_lists feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear import_dictionary_words feeds'.
  $permissions['clear import_dictionary_words feeds'] = array(
    'name' => 'clear import_dictionary_words feeds',
    'roles' => array(),
    'module' => 'feeds',
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
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'create word_list content'.
  $permissions['create word_list content'] = array(
    'name' => 'create word_list content',
    'roles' => array(
      'Curator' => 'Curator',
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
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

  // Exported permission: 'delete any word_list content'.
  $permissions['delete any word_list content'] = array(
    'name' => 'delete any word_list content',
    'roles' => array(
      'Curator' => 'Curator',
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

  // Exported permission: 'delete own word_list content'.
  $permissions['delete own word_list content'] = array(
    'name' => 'delete own word_list content',
    'roles' => array(
      'Curator' => 'Curator',
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
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'eck add alphabetical_order_definition alphabetical_order_definition entities'.
  $permissions['eck add alphabetical_order_definition alphabetical_order_definition entities'] = array(
    'name' => 'eck add alphabetical_order_definition alphabetical_order_definition entities',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add alphabetical_order_definition bundles'.
  $permissions['eck add alphabetical_order_definition bundles'] = array(
    'name' => 'eck add alphabetical_order_definition bundles',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer alphabetical_order_definition alphabetical_order_definition entities'.
  $permissions['eck administer alphabetical_order_definition alphabetical_order_definition entities'] = array(
    'name' => 'eck administer alphabetical_order_definition alphabetical_order_definition entities',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer alphabetical_order_definition bundles'.
  $permissions['eck administer alphabetical_order_definition bundles'] = array(
    'name' => 'eck administer alphabetical_order_definition bundles',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete alphabetical_order_definition alphabetical_order_definition entities'.
  $permissions['eck delete alphabetical_order_definition alphabetical_order_definition entities'] = array(
    'name' => 'eck delete alphabetical_order_definition alphabetical_order_definition entities',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete alphabetical_order_definition bundles'.
  $permissions['eck delete alphabetical_order_definition bundles'] = array(
    'name' => 'eck delete alphabetical_order_definition bundles',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit alphabetical_order_definition alphabetical_order_definition entities'.
  $permissions['eck edit alphabetical_order_definition alphabetical_order_definition entities'] = array(
    'name' => 'eck edit alphabetical_order_definition alphabetical_order_definition entities',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit alphabetical_order_definition bundles'.
  $permissions['eck edit alphabetical_order_definition bundles'] = array(
    'name' => 'eck edit alphabetical_order_definition bundles',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list alphabetical_order_definition alphabetical_order_definition entities'.
  $permissions['eck list alphabetical_order_definition alphabetical_order_definition entities'] = array(
    'name' => 'eck list alphabetical_order_definition alphabetical_order_definition entities',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list alphabetical_order_definition bundles'.
  $permissions['eck list alphabetical_order_definition bundles'] = array(
    'name' => 'eck list alphabetical_order_definition bundles',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view alphabetical_order_definition alphabetical_order_definition entities'.
  $permissions['eck view alphabetical_order_definition alphabetical_order_definition entities'] = array(
    'name' => 'eck view alphabetical_order_definition alphabetical_order_definition entities',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view alphabetical_order_definition bundles'.
  $permissions['eck view alphabetical_order_definition bundles'] = array(
    'name' => 'eck view alphabetical_order_definition bundles',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
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

  // Exported permission: 'edit any word_list content'.
  $permissions['edit any word_list content'] = array(
    'name' => 'edit any word_list content',
    'roles' => array(
      'Curator' => 'Curator',
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

  // Exported permission: 'edit own word_list content'.
  $permissions['edit own word_list content'] = array(
    'name' => 'edit own word_list content',
    'roles' => array(
      'Curator' => 'Curator',
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

  // Exported permission: 'import import_dictionary_word_additional_entries feeds'.
  $permissions['import import_dictionary_word_additional_entries feeds'] = array(
    'name' => 'import import_dictionary_word_additional_entries feeds',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import import_dictionary_word_lists feeds'.
  $permissions['import import_dictionary_word_lists feeds'] = array(
    'name' => 'import import_dictionary_word_lists feeds',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import import_dictionary_words feeds'.
  $permissions['import import_dictionary_words feeds'] = array(
    'name' => 'import import_dictionary_words feeds',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'manage alphabetical_order_definition properties'.
  $permissions['manage alphabetical_order_definition properties'] = array(
    'name' => 'manage alphabetical_order_definition properties',
    'roles' => array(
      'Mukurtu Administrator' => 'Mukurtu Administrator',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
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

  // Exported permission: 'tamper import_dictionary_word_additional_entries'.
  $permissions['tamper import_dictionary_word_additional_entries'] = array(
    'name' => 'tamper import_dictionary_word_additional_entries',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper import_dictionary_word_lists'.
  $permissions['tamper import_dictionary_word_lists'] = array(
    'name' => 'tamper import_dictionary_word_lists',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper import_dictionary_words'.
  $permissions['tamper import_dictionary_words'] = array(
    'name' => 'tamper import_dictionary_words',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock import_dictionary_word_additional_entries feeds'.
  $permissions['unlock import_dictionary_word_additional_entries feeds'] = array(
    'name' => 'unlock import_dictionary_word_additional_entries feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock import_dictionary_word_lists feeds'.
  $permissions['unlock import_dictionary_word_lists feeds'] = array(
    'name' => 'unlock import_dictionary_word_lists feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock import_dictionary_words feeds'.
  $permissions['unlock import_dictionary_words feeds'] = array(
    'name' => 'unlock import_dictionary_words feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'update paragraph content dictionary_word_bundle'.
  $permissions['update paragraph content dictionary_word_bundle'] = array(
    'name' => 'update paragraph content dictionary_word_bundle',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'use search_api_sorts'.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      'Community Administrator' => 'Community Administrator',
      'Curator' => 'Curator',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_sorts',
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
