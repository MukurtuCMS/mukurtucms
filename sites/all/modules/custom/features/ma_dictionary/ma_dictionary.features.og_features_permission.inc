<?php

/**
 * @file
 * ma_dictionary.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ma_dictionary_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:community:create dictionary_word content'
  $permissions['node:community:create dictionary_word content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:create language_community content'
  $permissions['node:community:create language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:delete any dictionary_word content'
  $permissions['node:community:delete any dictionary_word content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:delete any language_community content'
  $permissions['node:community:delete any language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:delete own dictionary_word content'
  $permissions['node:community:delete own dictionary_word content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:delete own language_community content'
  $permissions['node:community:delete own language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:update any dictionary_word content'
  $permissions['node:community:update any dictionary_word content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:update any language_community content'
  $permissions['node:community:update any language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:update own dictionary_word content'
  $permissions['node:community:update own dictionary_word content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:update own language_community content'
  $permissions['node:community:update own language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:create dictionary_word content'
  $permissions['node:cultural_protocol_group:create dictionary_word content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:create language_community content'
  $permissions['node:cultural_protocol_group:create language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any dictionary_word content'
  $permissions['node:cultural_protocol_group:delete any dictionary_word content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any language_community content'
  $permissions['node:cultural_protocol_group:delete any language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own dictionary_word content'
  $permissions['node:cultural_protocol_group:delete own dictionary_word content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own language_community content'
  $permissions['node:cultural_protocol_group:delete own language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any dictionary_word content'
  $permissions['node:cultural_protocol_group:update any dictionary_word content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any language_community content'
  $permissions['node:cultural_protocol_group:update any language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own dictionary_word content'
  $permissions['node:cultural_protocol_group:update own dictionary_word content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own language_community content'
  $permissions['node:cultural_protocol_group:update own language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:add user'
  $permissions['node:language_community:add user'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:administer group'
  $permissions['node:language_community:administer group'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:approve and deny subscription'
  $permissions['node:language_community:approve and deny subscription'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:create community content'
  $permissions['node:language_community:create community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:create dictionary_word content'
  $permissions['node:language_community:create dictionary_word content'] = array(
    'roles' => array(
      'language contributor' => 'language contributor',
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:create digital_heritage content'
  $permissions['node:language_community:create digital_heritage content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:create language_community content'
  $permissions['node:language_community:create language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:delete any community content'
  $permissions['node:language_community:delete any community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:delete any dictionary_word content'
  $permissions['node:language_community:delete any dictionary_word content'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:delete any digital_heritage content'
  $permissions['node:language_community:delete any digital_heritage content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:delete any language_community content'
  $permissions['node:language_community:delete any language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:delete own community content'
  $permissions['node:language_community:delete own community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:delete own dictionary_word content'
  $permissions['node:language_community:delete own dictionary_word content'] = array(
    'roles' => array(
      'language contributor' => 'language contributor',
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:delete own digital_heritage content'
  $permissions['node:language_community:delete own digital_heritage content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:delete own language_community content'
  $permissions['node:language_community:delete own language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:invite any user'
  $permissions['node:language_community:invite any user'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:manage members'
  $permissions['node:language_community:manage members'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:manage permissions'
  $permissions['node:language_community:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:manage roles'
  $permissions['node:language_community:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:subscribe'
  $permissions['node:language_community:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:language_community:subscribe without approval'
  $permissions['node:language_community:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:unsubscribe'
  $permissions['node:language_community:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:language_community:update any community content'
  $permissions['node:language_community:update any community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:update any dictionary_word content'
  $permissions['node:language_community:update any dictionary_word content'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:update any digital_heritage content'
  $permissions['node:language_community:update any digital_heritage content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:update any language_community content'
  $permissions['node:language_community:update any language_community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:update group'
  $permissions['node:language_community:update group'] = array(
    'roles' => array(
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:update own community content'
  $permissions['node:language_community:update own community content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:update own dictionary_word content'
  $permissions['node:language_community:update own dictionary_word content'] = array(
    'roles' => array(
      'language contributor' => 'language contributor',
      'language steward' => 'language steward',
    ),
  );

  // Exported og permission: 'node:language_community:update own digital_heritage content'
  $permissions['node:language_community:update own digital_heritage content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:language_community:update own language_community content'
  $permissions['node:language_community:update own language_community content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
