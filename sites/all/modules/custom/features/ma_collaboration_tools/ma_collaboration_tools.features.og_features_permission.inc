<?php
/**
 * @file
 * ma_collaboration_tools.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ma_collaboration_tools_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:cultural_protocol_group:create calendar content'
  $permissions['node:cultural_protocol_group:create calendar content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:create collection content'
  $permissions['node:cultural_protocol_group:create collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:create discussion_space content'
  $permissions['node:cultural_protocol_group:create discussion_space content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:create document_library content'
  $permissions['node:cultural_protocol_group:create document_library content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:create oa_discussion_post content'
  $permissions['node:cultural_protocol_group:create oa_discussion_post content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:create oa_event content'
  $permissions['node:cultural_protocol_group:create oa_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:create oa_wiki_page content'
  $permissions['node:cultural_protocol_group:create oa_wiki_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any calendar content'
  $permissions['node:cultural_protocol_group:delete any calendar content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any discussion_space content'
  $permissions['node:cultural_protocol_group:delete any discussion_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any document_library content'
  $permissions['node:cultural_protocol_group:delete any document_library content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any oa_discussion_post content'
  $permissions['node:cultural_protocol_group:delete any oa_discussion_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any oa_event content'
  $permissions['node:cultural_protocol_group:delete any oa_event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete any oa_wiki_page content'
  $permissions['node:cultural_protocol_group:delete any oa_wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own calendar content'
  $permissions['node:cultural_protocol_group:delete own calendar content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own discussion_space content'
  $permissions['node:cultural_protocol_group:delete own discussion_space content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own document_library content'
  $permissions['node:cultural_protocol_group:delete own document_library content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own oa_discussion_post content'
  $permissions['node:cultural_protocol_group:delete own oa_discussion_post content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own oa_event content'
  $permissions['node:cultural_protocol_group:delete own oa_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:delete own oa_wiki_page content'
  $permissions['node:cultural_protocol_group:delete own oa_wiki_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any calendar content'
  $permissions['node:cultural_protocol_group:update any calendar content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any discussion_space content'
  $permissions['node:cultural_protocol_group:update any discussion_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any document_library content'
  $permissions['node:cultural_protocol_group:update any document_library content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any oa_discussion_post content'
  $permissions['node:cultural_protocol_group:update any oa_discussion_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any oa_event content'
  $permissions['node:cultural_protocol_group:update any oa_event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update any oa_wiki_page content'
  $permissions['node:cultural_protocol_group:update any oa_wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own calendar content'
  $permissions['node:cultural_protocol_group:update own calendar content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own discussion_space content'
  $permissions['node:cultural_protocol_group:update own discussion_space content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own document_library content'
  $permissions['node:cultural_protocol_group:update own document_library content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own oa_discussion_post content'
  $permissions['node:cultural_protocol_group:update own oa_discussion_post content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own oa_event content'
  $permissions['node:cultural_protocol_group:update own oa_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  // Exported og permission: 'node:cultural_protocol_group:update own oa_wiki_page content'
  $permissions['node:cultural_protocol_group:update own oa_wiki_page content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'member' => 'member',
      'protocol steward' => 'protocol steward',
    ),
  );

  return $permissions;
}
