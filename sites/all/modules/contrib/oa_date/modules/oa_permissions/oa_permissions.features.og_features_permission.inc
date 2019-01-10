<?php
/**
 * @file
 * oa_permissions.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function oa_permissions_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:oa_group:add user'
  $permissions['node:oa_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:administer group'
  $permissions['node:oa_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:administer taxonomy'
  $permissions['node:oa_group:administer taxonomy'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:approve and deny subscription'
  $permissions['node:oa_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:delete terms'
  $permissions['node:oa_group:delete terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:edit terms'
  $permissions['node:oa_group:edit terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:manage appearance'
  $permissions['node:oa_group:manage appearance'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:manage members'
  $permissions['node:oa_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:manage menu'
  $permissions['node:oa_group:manage menu'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:manage permissions'
  $permissions['node:oa_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:manage roles'
  $permissions['node:oa_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:manage variables'
  $permissions['node:oa_group:manage variables'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:subscribe'
  $permissions['node:oa_group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:oa_group:subscribe without approval'
  $permissions['node:oa_group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:trash any content'
  $permissions['node:oa_group:trash any content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:unsubscribe'
  $permissions['node:oa_group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_group:untrash any content'
  $permissions['node:oa_group:untrash any content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:update group'
  $permissions['node:oa_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:use any oa button space_type'
  $permissions['node:oa_group:use any oa button space_type'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:view trash content'
  $permissions['node:oa_group:view trash content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:view trash bin'
  $permissions['node:oa_group:view trash bin'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:add user'
  $permissions['node:oa_space:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:administer group'
  $permissions['node:oa_space:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:administer taxonomy'
  $permissions['node:oa_space:administer taxonomy'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:approve and deny subscription'
  $permissions['node:oa_space:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:delete terms'
  $permissions['node:oa_space:delete terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:edit terms'
  $permissions['node:oa_space:edit terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:manage appearance'
  $permissions['node:oa_space:manage appearance'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:manage members'
  $permissions['node:oa_space:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:manage menu'
  $permissions['node:oa_space:manage menu'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:manage permissions'
  $permissions['node:oa_space:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:manage roles'
  $permissions['node:oa_space:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:manage variables'
  $permissions['node:oa_space:manage variables'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:subscribe'
  $permissions['node:oa_space:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:oa_space:subscribe without approval'
  $permissions['node:oa_space:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:trash any content'
  $permissions['node:oa_space:trash any content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:unsubscribe'
  $permissions['node:oa_space:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_space:untrash any content'
  $permissions['node:oa_space:untrash any content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:update group'
  $permissions['node:oa_space:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:use any oa button space_type'
  $permissions['node:oa_space:use any oa button space_type'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:view trash content'
  $permissions['node:oa_space:view trash content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:view trash bin'
  $permissions['node:oa_space:view trash bin'] = array(
    'roles' => array(),
  );

  return $permissions;
}
