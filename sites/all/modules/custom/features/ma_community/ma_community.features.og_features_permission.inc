<?php

/**
 * @file
 * ma_community.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ma_community_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:community:add user'
  $permissions['node:community:add user'] = array(
    'roles' => array(
      'community manager' => 'community manager',
    ),
  );

  // Exported og permission: 'node:community:administer group'
  $permissions['node:community:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:approve and deny subscription'
  $permissions['node:community:approve and deny subscription'] = array(
    'roles' => array(
      'community manager' => 'community manager',
    ),
  );

  // Exported og permission: 'node:community:invite any user'
  $permissions['node:community:invite any user'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:manage members'
  $permissions['node:community:manage members'] = array(
    'roles' => array(
      'community manager' => 'community manager',
    ),
  );

  // Exported og permission: 'node:community:manage permissions'
  $permissions['node:community:manage permissions'] = array(
    'roles' => array(
      'community manager' => 'community manager',
    ),
  );

  // Exported og permission: 'node:community:manage roles'
  $permissions['node:community:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:subscribe'
  $permissions['node:community:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:community:subscribe without approval'
  $permissions['node:community:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community:unsubscribe'
  $permissions['node:community:unsubscribe'] = array(
    'roles' => array(
      'community manager' => 'community manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community:update group'
  $permissions['node:community:update group'] = array(
    'roles' => array(
      'community manager' => 'community manager',
    ),
  );

  return $permissions;
}
