<?php
/**
 * @file
 * Code for Utility functions for OpenAtrium spaces
 *
 * Also contains various node hooks (update,delete,insert) for cache handling
 */

/**
 * Name of various caches.
 */
define('OA_CACHE_GROUPS_BY_USER', 'oa_groups_by_user');
define('OA_CACHE_GROUPS_BY_USER_ACCESS', 'oa_groups_by_user_access');
define('OA_CACHE_GET_PARENTS', 'oa_get_parents');
define('OA_CACHE_GROUPS_BY_PARENT', 'oa_groups_by_parent');
define('OA_CACHE_TOP_PARENTS', 'oa_top_parents');

/**
 * Get the group IDs of all the groups a user is an approved member of.
 *
 * REPLACES og_get_groups_by_user() in OG and returns a list of groups
 * including subspaces including via INHERITED membership
 *
 * @param $account
 *   (optional) The user object to fetch group memberships for. Defaults to the
 *   acting user.
 * @param $group_type
 *   (optional) The entity type of the groups to fetch. By default all group
 *   types will be fetched. (e.g. 'node', 'user')
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 *
 * @return array
 *   An array with the group IDs or an empty array, or returns NULL if there was an error
 */
function oa_core_get_groups_by_user($account = NULL, $group_type = NULL, $include_archived = FALSE) {
  if (!isset($account)) {
    global $user;
    $account = $user;
  }

  $cid = oa_core_get_cache_id(OA_CACHE_GROUPS_BY_USER, $account->uid, $include_archived, array($group_type));
  if (oa_core_get_cache(OA_CACHE_GROUPS_BY_USER, $cid, $result)) {
    return $result;
  }

  // Do NOT call og_get_groups_by_user as it loads all entities
  // Here we do a faster db query

  $query = db_select('node', 'n');
  $query->join('og_membership', 'ogm', 'ogm.gid = n.nid');
  $query
    ->fields('n', array('nid'))
    ->condition('ogm.etid', $account->uid)
    ->condition('ogm.entity_type', 'user')
    ->condition('ogm.state', OG_STATE_ACTIVE)
    ->condition('n.type', array(OA_SPACE_TYPE, OA_GROUP_TYPE), 'IN');

  if (module_exists('flag') && !$include_archived) {
    if ($flag = flag_get_flag('trash')) {
      $query->leftJoin('flagging', 'a', "a.fid = :fid AND a.entity_id = n.nid", array(':fid' => $flag->fid));
      // This makes sure that archived content isn't included, because 'uid'
      // will be NULL if the join didn't connect anything.
      $query->isNull('a.uid');
    }
  }

  $user_groups = drupal_map_assoc($query->execute()->fetchCol(0));

  if (module_exists('og_subgroups') && $user_groups) {
    $user_groups = oa_core_get_groups_by_parent($user_groups, array(OA_SPACE_TYPE, OA_GROUP_TYPE), NULL, $include_archived, NULL, TRUE);
  }

  oa_core_set_cache(OA_CACHE_GROUPS_BY_USER, $cid, $user_groups);

  return $user_groups;
}

/**
 * Get the group IDs and Titles of all the groups a user is an approved member of.
 *
 * SIMILAR to oa_core_get_groups_by_user above but respects the NODE ACCESS
 * of the spaces and allows an optional space status (published)
 * Only returns spaces a user is ACTIVE in (not BLOCKED or PENDING)
 * Also, returns both nids and titles in result
 *
 * DOES NOT return INHERITED subspaces
 *
 * @param $account
 *   (optional) The user object to fetch group memberships for. Defaults to the
 *   acting user.  Can be a full user node or just a user uid
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 * @param int $status
 *   (optional) The space node status to include.  If NULL, all spaces are
 *   included.  If NODE_PUBLISHED, then only include published spaces
 * @param array $page
 *   (optional) Adds a pager to the query for the given page number
 * @param string $filter
 *   (optional) Filters the space titles that are returned
 * @param string $type
 *   (optional) Type of group.  Defaults to OA_SPACE_TYPE
 * @param string $sort
 *   (optional) Field to sort on.  Use 'history' to sort by most recently accessed.  Start with - to reverse sort direction
 *
 * @return array
 *   An array with the group IDs or an empty array, or returns NULL if there was an error
 */
function oa_core_get_groups_by_user_access($account = NULL, $include_archived = FALSE, $status = NULL, $page = NULL, $filter = NULL, $type = NULL, $sort = NULL, $limit = NULL) {
  if (!isset($account)) {
    global $user;
    $uid = $user->uid;
  }
  elseif (is_numeric($account)) {
    $uid = $account;
  }
  else {
    $uid = $account->uid;
  }

  $sort = !empty($sort) ? $sort : 'title';
  $limit = !empty($limit) ? $limit : 0;
  $type = !empty($type) ? $type : OA_SPACE_TYPE;

  $cid = oa_core_get_cache_id(OA_CACHE_GROUPS_BY_USER_ACCESS, $uid, $include_archived, array($status, $type, $sort, $limit));
  if (!isset($page) && empty($filter) && ($sort != 'history') && oa_core_get_cache(OA_CACHE_GROUPS_BY_USER_ACCESS, $cid, $result)) {
    return $result;
  }

  $query = db_select('node', 'n');
  if (isset($page)) {
    if (!isset($_GET['page'])) {
      $_GET['page'] = $page;
    }
    $query = $query->extend('PagerDefault')->limit(20);
  }

  $query->join('og_membership', 'ogm', 'ogm.gid = n.nid');
  if ($sort == 'history') {
    $query->join('history', 'h', 'h.nid = n.nid');
    $query->condition('h.uid', $uid);
    $query->orderBy('h.timestamp', 'DESC');
  }
  $query
    ->fields('n', array('nid', 'title'))
    ->condition('ogm.etid', $uid)
    ->condition('ogm.entity_type', 'user')
    ->condition('ogm.state', OG_STATE_ACTIVE)
    ->addTag('node_access');

  if (!empty($sort) && ($sort != 'history')) {
    $dir = 'ASC';
    if (substr($sort,0,1) == '-') {
      $dir = 'DESC';
      $sort = substr($sort, 1, strlen($sort)-1);
    }
    $query->orderBy('n.' . $sort, $dir);
    // secondary sort on title
    $query->orderBy('n.title');
  }

  if (isset($type)) {
    if (is_array($type)) {
      $query->condition('n.type', $type, 'IN');
    }
    else {
      $query->condition('n.type', $type);
    }
  }

  if (isset($status)) {
    $query->condition('n.status', $status);
  }

  if (!empty($filter)) {
    $query->condition('n.title', '%' . db_like($filter) . '%', 'LIKE');
  }

  if ($limit > 0) {
    $query->range(0, $limit);
  }

  if (module_exists('flag') && !$include_archived) {
    if ($flag = flag_get_flag('trash')) {
      $query->leftJoin('flagging', 'a', "a.fid = :fid AND a.entity_id = n.nid", array(':fid' => $flag->fid));
      // This makes sure that archived content isn't included, because 'uid'
      // will be NULL if the join didn't connect anything.
      $query->isNull('a.uid');
    }
  }

  $result = $query
    ->execute()
    ->fetchAll();

  if (empty($filter)) {
    oa_core_set_cache(OA_CACHE_GROUPS_BY_USER_ACCESS, $cid, $result);
  }

  return $result;
}

/**
 * Returns the current space id context
 * @param  boolean $from_session only use the context stored in $SESSION
 *   set this to TRUE if calling from a access hook to avoid infinite loops
 * @return int Space ID
 */
function oa_core_get_space_context($from_session = FALSE) {
  if (variable_get('install_task') !== 'done') {
    // don't run this during the installer
    return 0;
  }
  if ($from_session) {
    if (defined('OG_SESSION_CONTEXT_ID') && isset($_SESSION[OG_SESSION_CONTEXT_ID])) {
      return $_SESSION[OG_SESSION_CONTEXT_ID];
    }
    return 0;
  }

  $context = og_context('node');
  if (!empty($context['gid'])) {
    og_session_context_set_context($context['gid']);
    return $context['gid'];
  }
  else {
    return og_session_context_get_context();
  }
}

/**
 * Returns the current space id context
 * Returns zero if on the site home page
 * @param  boolean $from_session only use the context stored in $SESSION
 * @return int Space ID
 */
function oa_core_get_space_home_context() {
  if (variable_get('install_task') !== 'done') {
    // don't run this during the installer
    return 0;
  }
  $space_id = oa_core_get_space_context();
  $node = menu_get_object();
  if (drupal_is_front_page() && !(isset($node) && ($node->type == OA_SPACE_TYPE))) {
    return 0;  // front page, not a space page
  }
  return $space_id;
}

/**
 * Returns the current section id context
 * @param $node optional current page node
 * @return int Section ID
 */
function oa_core_get_section_context($node = NULL) {
  if (isset($node) && ($node->type == OA_SECTION_TYPE)) {
    return $node->nid;
  }
  elseif (defined('OA_SESSION_SECTION') && isset($_SESSION[OA_SESSION_SECTION])) {
    return $_SESSION[OA_SESSION_SECTION];
  }
  else {
    return oa_section_get_section_context();
  }
}

/**
 * Get parent Spaces and Groups.
 *
 * @param int $nid
 *   The NID of the Space or Group to check.
 * @param string|NULL $bundle
 *   (optional) The node type (default: OA_SPACE_TYPE). If NULL is passed, it
 *   will include all node types.
 * @param int|NULL $status
 *   (optional) If specified, the node status (ex. NODE_PUBLISHED or
 *   NODE_NOT_PUBLISHED) to look for. If not specified, it return
 *   nodes of either status.
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 * @param book $fetch_all
 *   (optional) Set to true to return all parents, rather than just direct parents
 *
 * @return array
 *   Array of parent NIDs to titles.
 */
function oa_core_get_parents_with_titles($nid, $bundle = OA_SPACE_TYPE, $status = NULL, $include_archived = FALSE, $fetch_all = FALSE, $account = NULL) {
  if (!isset($account)) {
    global $user;
    $uid = $user->uid;
  }
  elseif (is_numeric($account)) {
    $uid = $account;
  }
  else {
    $uid = $account->uid;
  }

  $cid = oa_core_get_cache_id(OA_CACHE_GET_PARENTS, $nid . '_' . $uid . '_' . ($fetch_all ? '1' : '0'), $include_archived, array($bundle, $status));
  if (oa_core_get_cache(OA_CACHE_GET_PARENTS, $cid, $result)) {
    return $result;
  }

  $result = og_subgroups_parents_load('node', $nid, FALSE, $fetch_all);
  $result = !empty($result['node']) ? oa_core_get_nids_title_matching($result['node'], $bundle, $status, $include_archived, $account) : array();

  oa_core_set_cache(OA_CACHE_GET_PARENTS, $cid, $result);

  return $result;
}

/**
 * Get parent Spaces and Groups.
 *
 * @param int $nid
 *   The NID of the Space or Group to check.
 * @param string|NULL $bundle
 *   (optional) The node type (default: OA_SPACE_TYPE). If NULL is passed, it
 *   will include all node types.  Can also be an array of types.
 * @param int|NULL $status
 *   (optional) If specified, the node status (ex. NODE_PUBLISHED or
 *   NODE_NOT_PUBLISHED) to look for. If not specified, it return
 *   nodes of either status.
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 *
 * @return array
 *   Array of parent NIDs to titles.
 */
function oa_core_get_parents($nid, $bundle = OA_SPACE_TYPE, $status = NULL, $include_archived = FALSE, $fetch_all = FALSE, $account = NULL) {
  $parents = oa_core_get_parents_with_titles($nid, $bundle, $status, $include_archived, $fetch_all, $account);
  return array_keys($parents);
}

/**
 * Get the nids => title matching criteria from a set of nids.
 *
 * @param int[] $nids
 *   The NIDs of the nodes to check.
 * @param string|NULL $bundle
 *   (optional) The node type (default: OA_SPACE_TYPE). If NULL is passed, it
 *   will include all node types.  Can also be an array of types.
 * @param int|NULL $status
 *   (optional) If specified, the node status (ex. NODE_PUBLISHED or
 *   NODE_NOT_PUBLISHED) to look for. If not specified, it return
 *   nodes of either status.
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 * @param stdClass|NULL $account
 *   (optional) the account used to check access to the results. Defaults to
 *   the current user.
 *
 * @return array
 *   Array of parent NIDs to title.
 */
function oa_core_get_nids_title_matching($nids, $bundle = OA_SPACE_TYPE, $status = NULL, $include_archived = FALSE, $account = NULL) {
  if (is_numeric($account)) {
    $account = user_load($account);
  }
  elseif (!$account) {
    global $user;
    $account = $user;
  }
  sort($nids);
  $cid = implode(':', $nids);
  if (is_array($bundle)) {
    $cid .= implode(':', $bundle);
  }
  elseif (!empty($bundle)) {
    $cid .= ':' . $bundle;
  }
  $cid .= ':' . $status . ':' . $include_archived . ':' . $account->uid;
  $cache = &drupal_static(__FUNCTION__, array());
  if (!isset($cache[$cid])) {
    $query = db_select('node', 'n');
    if ($bundle) {
      $query->condition('n.type', $bundle);
    }
    if (isset($status)) {
      $query->condition('n.status', $status);
    }
    $query->condition('n.nid', $nids);
    $query
      ->fields('n', array('nid', 'title'))
      ->addTag('node_access')
      ->addMetaData('account', $account);
    if (module_exists('oa_archive') && !$include_archived) {
      if ($flag = flag_get_flag('trash')) {
        $query->leftJoin('flagging', 'a', "a.fid = :fid AND a.entity_id = n.nid", array(':fid' => $flag->fid));
        // This makes sure that archived content isn't included, because 'uid'
        // will be NULL if the join didn't connect anything.
        $query->isNull('a.uid');
      }
    }
    $cache[$cid] = $query->execute()->fetchAllKeyed();
  }
  return $cache[$cid];
}

/**
 * Get child Spaces or Groups.
 *
 * @param int $nid
 *   The NID of the Space or Group to check, or an array of nids
 * @param string|NULL $bundle
 *   (optional) The node type (default: OA_SPACE_TYPE). If NULL is passed, it
 *   will include all node types.
 * @param int|NULL $status
 *   (optional) If specified, the node status (ex. NODE_PUBLISHED or
 *   NODE_NOT_PUBLISHED) to look for. If not specified, it return
 *   nodes of either status.
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 * @param int|NULL $account
 *   (optional) user to control node acess.  If Null, use current user
 * @param bool $subspaces
 *   (optional) determine if subspaces are also fetched, or if just top level children are fetched
 * @param bool $inheritance
 *   (optional) if TRUE, only return subspaces that have inheritance enabled
 *
 * @return array
 *   Array of children NIDs.
 */
function oa_core_get_groups_by_parent($nids, $bundle = OA_SPACE_TYPE, $status = NULL, $include_archived = FALSE, $account = NULL, $subspaces = FALSE, $inheritance = TRUE) {

  if ($nids == 0) {
    return oa_core_get_top_parents($bundle, $status, $include_archived, $account);
  }

  if (!isset($account)) {
    global $user;
    $uid = $user->uid;
  }
  elseif (is_numeric($account)) {
    $uid = $account;
  }
  else {
    $uid = $account->uid;
  }
  if (is_array($nids)) {
    $hash = md5(serialize($nids));
  }
  else {
    $hash = $nids;
  }

  $cid = oa_core_get_cache_id(OA_CACHE_GROUPS_BY_PARENT, $hash . '_' . $uid, $include_archived, array(serialize($bundle), $status, $subspaces));
  if (oa_core_get_cache(OA_CACHE_GROUPS_BY_PARENT, $cid, $result)) {
    return $result;
  }

  if (!is_array($nids)) {
    $nids = array($nids);
  }
  $query = db_select('node', 'n');
  $query->join('og_membership', 'f', "n.nid = f.etid AND f.entity_type = 'node'");
  $query
    ->fields('n', array('nid'))
    ->orderBy('n.title');

  // to find all subspaces, we query *all* spaces with parents
  // otherwise, if just getting top level children we can filter it here.
  if (!$subspaces) {
    $query->condition('f.gid', $nids, 'IN');
    $query->addTag('node_access');
  }

  if (isset($bundle)) {
    if (is_array($bundle)) {
      $query->condition('n.type', $bundle, 'IN');
    }
    else {
      $query->condition('n.type', $bundle);
    }
  }
  if (isset($status)) {
    $query->condition('n.status', $status);
  }

  if (module_exists('flag') && !$include_archived) {
    if ($flag = flag_get_flag('trash')) {
      $query->leftJoin('flagging', 'a', "a.fid = :fid AND a.entity_id = n.nid", array(':fid' => $flag->fid));
      // This makes sure that archived content isn't included, because 'uid'
      // will be NULL if the join didn't connect anything.
      $query->isNull('a.uid');
    }
  }

  if ($subspaces) {
    $query->fields('f', array('gid'));
    $query->condition('f.etid', $nids, 'NOT IN');
    $query->join('field_data_og_user_inheritance', 'inh', "inh.entity_id = f.gid && f.group_type = 'node'");
    $query->fields('inh', array('og_user_inheritance_value'));
    $result = $query->execute()->fetchAll();

    // to get a list of all subspaces, we can now loop through the list of all parents recursively
    // to build our children list
    $all_parents = array();
    foreach ($result as $parent) {
      if (!$inheritance || $parent->og_user_inheritance_value == 1) {
        $all_parents[$parent->gid][] = $parent->nid;
      }
    }
    $result = _oa_core_get_all_children($all_parents, $nids);
  }
  else {
    $result = $query->execute()->fetchCol(0);
  }
  $result = drupal_map_assoc($result);

  oa_core_set_cache(OA_CACHE_GROUPS_BY_PARENT, $cid, $result);

  return $result;
}

/**
 * Helper function to return children of a list of parents.
 *
 * @param $all_parents array of sub-space nids keyed by space id for all spaces
 * @param $nids array an array of parents we want children for
 */
function _oa_core_get_all_children($all_parents, $nids, &$processed = array()) {
  $processed = array_merge($nids, $processed);
  $result = array();
  $children = array();
  foreach (array_intersect_key($all_parents, array_flip($nids)) as $parent_children) {
    $children = array_merge($children, $parent_children);
  }
  if ($new_children = array_diff($children, $processed)) {
    $result = _oa_core_get_all_children($all_parents, $new_children, $processed);
  }
  $result = array_unique(array_merge($nids, $result), SORT_NUMERIC);
  return $result;
}

/**
 * Get top-level spaces/groups (no parents of same bundle type)
 *
 * @param string $bundle
 *   The node type (default: OA_SPACE_TYPE).
 * @param int|NULL $status
 *   (optional) If specified, the node status (ex. NODE_PUBLISHED or
 *   NODE_NOT_PUBLISHED) to look for. If not specified, it return
 *   nodes of either status.
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 *
 * @return array
 *   Array of children NIDs.
 */
function oa_core_get_top_parents($bundle, $status = NULL, $include_archived = FALSE, $account = NULL) {
  if (!isset($account)) {
    global $user;
    $uid = $user->uid;
  }
  elseif (is_numeric($account)) {
    $uid = $account;
  }
  else {
    $uid = $account->uid;
  }

  $cid = oa_core_get_cache_id(OA_CACHE_TOP_PARENTS, $uid, $include_archived, array($bundle, $status));
  if (oa_core_get_cache(OA_CACHE_TOP_PARENTS, $cid, $result)) {
    return $result;
  }

  // need to also add the spaces whose parents are not the correct bundle
  $query_parents = db_select('node', 'n');
  $query_parents->join('og_membership', 'f', "n.nid = f.etid");
  $query_parents->join('node', 'n2', "n2.nid = f.gid");
  $query_parents
    ->fields('n', array('nid'))
    ->condition('f.entity_type', 'node')
    ->condition('n.type', $bundle)
    ->condition('n2.type', $bundle);

  $query = db_select('node', 'n');
  $query->fields('n', array('nid'))
    ->orderBy('n.title')
    ->addTag('node_access')
    ->condition('n.type', $bundle)
    ->condition('n.nid', $query_parents, 'NOT IN');

  if (isset($status)) {
    $query->condition('n.status', $status);
  }

  if (module_exists('flag') && !$include_archived) {
    if ($flag = flag_get_flag('trash')) {
      $query->leftJoin('flagging', 'a', "a.fid = :fid AND a.entity_id = n.nid", array(':fid' => $flag->fid));
      // This makes sure that archived content isn't included, because 'uid'
      // will be NULL if the join didn't connect anything.
      $query->isNull('a.uid');
    }
  }

  $result = $query->execute()->fetchCol(0);

  oa_core_set_cache(OA_CACHE_TOP_PARENTS, $cid, $result);

  return $result;
}

/**
 * Get all the content within a particular Section.
 *
 * @param int $nid
 *   The node ID of the Section.
 *
 * @return array
 *   An array of node IDs.
 */
function oa_core_get_section_content($nid) {
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->fieldCondition('oa_section_ref', 'target_id', $nid);
  $result = $query->execute();
  if (isset($result['node'])) {
    return array_keys($result['node']);
  }
  return array();
}

/**
 * Determine if a user is a member of a team
 * @param  int $team_id
 * @param  int $user_id
 * @return boolean TRUE if user is in team
 */
function oa_core_member_of_team($team_id, $user_id) {
  $cache = &drupal_static(__FUNCTION__);

  if (!isset($cache[$team_id][$user_id])) {
    $result = db_select('field_data_field_oa_team_users', 'f')
      ->fields('f', array('field_oa_team_users_target_id'))
      ->condition('field_oa_team_users_target_id', $user_id)
      ->condition('entity_type', 'node')
      ->condition('entity_id', $team_id)
      ->condition('deleted', 0)
      ->execute();
    if ($result->rowCount() > 0) {
      $access = TRUE;
    }
    else {
      // not explicitly in team, but check ownership of team node
      // do NOT use node_load as this is called from hook_node_grants()
      $result = db_select('node', 'n')
        ->fields('n', array('uid'))
        ->condition('nid', $team_id)
        ->execute()
        ->fetchAssoc();
      $access = ($result['uid'] == $user_id) ? TRUE : FALSE;
    }
    $cache[$team_id][$user_id] = $access;
  }

  return $cache[$team_id][$user_id];
}

/**
 * Returns TRUE if the section $node has open access to public
 */
function oa_core_section_is_public($node) {
  return (
       empty($node->field_oa_group_ref[LANGUAGE_NONE])
    && empty($node->field_oa_team_ref[LANGUAGE_NONE])
    && empty($node->field_oa_user_ref[LANGUAGE_NONE])
    );
}

/**
 * Returns a list of group-content types throughout the system. List
 *   leaves out content types excluded by other modules/apps.
 *
 * @return array of strings denoting content types marked for omission
 */
function oa_core_list_content_types($space_content = FALSE, $include_core = TRUE) {
  $nodes = node_type_get_types();
  if ($space_content) {
    // remove types that are not space content
    foreach ($nodes as $key => $node) {
      if (!og_is_group_content_type('node', $node->type)) {
        unset($nodes[$key]);
      }
    }
  }

  // Queries hook_oa_omit_content_types to determine what content types
  //   modules wants to hide.
  $deny = module_invoke_all('oa_omit_content_types');
  if (!$include_core) {
    $deny = array_merge($deny, array(OA_SPACE_TYPE, OA_GROUP_TYPE, OA_SECTION_TYPE, OA_TEAM_TYPE));
  }
  if (!empty($deny)) {
    foreach ($deny as $remove) {
      unset($nodes[$remove]);
    }
  }

  return $nodes;
}

/**
 * Create a new content node within a space/section
 * @param  string $bundle  name of node bundle to create
 * @param  object $context an optional code to copy space/section from
 *   if not specified, current Session space/section context is used
 * @return object $wrapper entity metadata wrapper around node
 *
 * NOTE: The created node is NOT SAVED.  You need to use:
 *   $wrapper = oa_core_create_node(...);
 *   $wrapper->save();
 * to actually save the created node.  This allows you to set other
 * wrapper fields before saving
 */
function oa_core_create_node($bundle, $title = '', $context = NULL) {
  global $user;

  $values = array(
    'type' => $bundle,
    'uid' => $user->uid,
    'status' => 1,
    'comment' => 0,
    'promote' => 0,
  );
  $entity = entity_create('node', $values);
  $wrapper = entity_metadata_wrapper('node', $entity);

  $wrapper->title = $title;

  $space_id = oa_core_get_space_context();
  $section_id = oa_core_get_section_context();
  if (isset($context)) {
    // copy space and section fields from context node
    $context_wrapper = entity_metadata_wrapper('node', $context);
    if (isset($context_wrapper->{OA_SPACE_FIELD})) {
      $space_id = $context_wrapper->{OA_SPACE_FIELD}->value();
      if (is_array($space_id)) {
        // if multi-value space field, just use first space for message
        $space_id = array_shift($space_id);
      }
    }
    if (isset($context_wrapper->{OA_SECTION_FIELD})) {
      $section_id = $context_wrapper->{OA_SECTION_FIELD}->value();
    }
  }
  if (isset($wrapper->{OA_SPACE_FIELD})) {
    $wrapper->{OA_SPACE_FIELD} = $space_id;
  }
  if (isset($wrapper->{OA_SECTION_FIELD})) {
    $wrapper->{OA_SECTION_FIELD} = $section_id;
  }

  return $wrapper;
}

/**
 * Helper function to retrieve an array of node titles and links given
 * a list of node ids
 * @param  array  $ids array of node ids to fetch
 * @param  string $type optional node type to filter
 * @param  array $fields a list of fields to fetch (link is a special fieldname)
 * @param  integer $limit max number of return results
 * @return array      associative array:
 *   'titles' is a list of node titles (clean)
 *   'links' is a list of node links
 *   'ids' is a list of the node ids
 */
function oa_core_get_titles($ids = array(), $type = '', $sort_field = 'title', $fields = array('title', 'link', 'id', 'type'), $sanitize = TRUE, $limit = 100) {
  $query_fields = array('nid', 'title');
  $return = array();
  foreach ($fields as $field) {
    // for backwards compatibility the array keys of the $return are
    // ids, titles, links, types.  So we append an 's' to the field name
    $return[$field . 's'] = array();
    // the 'link' and 'id' field names are handled specially and are not
    // direct query field names
    if (!in_array($field, array('link', 'id')) && !in_array($field, $query_fields)) {
      $query_fields[] = $field;
    }
  }
  if (!empty($ids)) {
    $query = db_select('node', 'n');
    if (!empty($sort_field) && ($sort_field != 'title')) {
      $query->leftJoin('field_data_' . $sort_field, 's',
        "n.nid = s.entity_id AND s.entity_type = 'node'");
    }
    $query
      ->fields('n', $query_fields)
      ->condition('n.nid', $ids, 'IN');
    if ($sort_field == 'title') {
      $query->orderBy('title');
    }
    elseif (!empty($sort_field)) {
      $query->orderBy('s.' . $sort_field . '_value');
    }
    if (!empty($type)) {
      $query->condition('n.type', $type);
    }
    if ($limit) {
      $query->range(0, $limit);
    }
    $result = $query->execute();

    // if $sort_field is empty, maintain the order of the original $ids
    // so create a lookup table.
    $nid_row = array();
    $index = 0;
    while ($row = $result->fetchAssoc()) {
      $id = empty($sort_field) ? $row['nid'] : $index;
      $nid_row[$id] = $row;
      $index++;
    }

    $index = 0;
    foreach ($ids as $nid) {
      $id = empty($sort_field) ? $nid : $index;
      if (!empty($nid_row[$id])) {
        foreach ($fields as $field) {
          $field_name = ($field == 'id') ? 'nid' : $field;
          $value = isset($nid_row[$id][$field_name]) ? $nid_row[$id][$field_name] : NULL;
          if (($field == 'title') && $sanitize) {
            $value = check_plain($value);
          }
          if ($field == 'link') {
            $value = l($nid_row[$id]['title'], 'node/' . $nid_row[$id]['nid']);
          }
          $return[$field . 's'][$nid_row[$id]['nid']] = $value;
        }
      }
      $index++;
    }
  }
  return $return;
}

/**
 * truncate a list to a given number of items with optional More link
 * @param  array $list      array to be truncated
 * @param  int $count     number of items desired
 * @param  string $more_link optional "More" link added to end of array
 * @param  boolean $always_link TRUE to always display more link
 * @return array            new list of items
 */
function oa_core_truncate_list($list, $count, $more_link = '', $always_link = FALSE) {
  $new_list = array_slice($list, 0, $count);
  if (!empty($more_link) && ($always_link ||(count($list) != count($new_list)))) {
    $new_list[] = $more_link;
  }
  return $new_list;
}

/**
 * Get a list of public spaces.
 *
 * Necessary since og_get_entity_groups() doesn't return anything for anonymous users
 *
 * @param array $group_types
 *   (optional) An associative array of node types.
 *   (default: array(OA_SPACE_TYPE => OA_SPACE_TYPE)
 * @param int $status
 *   (optional) If specified, the node status (ex. NODE_PUBLISHED or
 *   NODE_NOT_PUBLISHED) to look for. If not specified, it return
 *   nodes of either status.
 * @param bool $include_archived
 *   (optional) Whether to include archived nodes or not. By default, archived
 *   items aren't included.
 * @param bool $check_access
 *   Check node access, defaults to TRUE.
 * @param bool $only_top restrict to top-level spaces
 *
 * @return array
 *   An array of Space NIDs.
 */
function oa_core_get_public_spaces($group_types = array(OA_SPACE_TYPE => OA_SPACE_TYPE), $status = NULL, $include_archived = FALSE, $check_access = TRUE, $only_top = FALSE) {
  $cache = &drupal_static(__FUNCTION__);

  $group_types_cid = implode(',', $group_types);
  if (!isset($cache[$group_types_cid][$status][$include_archived])) {
    $query = db_select('node', 'n');
    $query->join('field_data_group_access', 'g', "n.nid = g.entity_id AND g.entity_type = 'node'");
    $query->fields('n', array('nid'));
    if ($only_top) {
      // need to restrict to space with either no parent, or just oa_group parents
      $query->leftJoin('og_membership', 'og', "og.etid = n.nid AND og.entity_type = 'node'");
      $query->leftJoin('node', 'pn', 'og.gid = pn.nid');
      $query->fields('pn', array('type'));
      // trick is to group the results and count the number of different parent types
      $query->addExpression('COUNT(DISTINCT pn.type)', 'num');
      $query->groupBy('n.nid');
      // so we either return spaces with 0 parents, or 1 parent type that is a group
      $query->having("num = 0 OR (num = 1 AND pn.type = '" . OA_GROUP_TYPE . "')");
    }
    $query
      ->condition('n.type', $group_types, 'IN')
      ->condition('g.group_access_value', 0);
    if (isset($status)) {
      $query->condition('n.status', $status);
    }
    if ($check_access) {
      $query->addTag('node_access');
    }
    if (module_exists('flag') && !$include_archived) {
      if ($flag = flag_get_flag('trash')) {
        $query->leftJoin('flagging', 'a', "a.fid = :fid AND a.entity_id = n.nid", array(':fid' => $flag->fid));
        // This makes sure that archived content isn't included, because 'uid'
        // will be NULL if the join didn't connect anything.
        $query->isNull('a.uid');
      }
    }

    $cache[$group_types_cid][$status][$include_archived] = $query->execute()->fetchCol(0);
  }

  return $cache[$group_types_cid][$status][$include_archived];
}

/**
 * Return a list of sections within a space
 * Uses access control, so only sections with access are returned
 * @param  int $gid space ID
 * @param  int $status NULL for any status, otherwise specify status to return
 * @param  bool $bypass_access_check, TRUE to bypass access control
 * @param  array $fields, array of additional fields to return, otherwise just title
 *   fields array has format fieldname|column.  e.g., field_oa_space|tid
 * @param  bool $include_archived Whether to include archived nodes or not
 * @return array of section data: $array[$nid] = $title.  If $fields is specified
 *   the return array is the full associative array of nid, title, fields
 */
function oa_core_space_sections($gid, $status = NULL, $bypass_access_check = FALSE, $fields = array(), $include_archived = FALSE) {
  $query = db_select('node', 'n');
  $query->rightJoin('og_membership', 'og', 'n.nid = og.etid');
  $query->leftJoin('field_data_field_oa_section_weight', 'w',
        "n.nid = w.entity_id AND w.entity_type = 'node'");
  $extra_fields = array();
  foreach ($fields as $field) {
    if ((strpos($field, 'field_') === 0) || (strpos($field, '|') !== FALSE)) {
      $field_list = explode('|', $field);
      $field_name = $field_list[0];
      $column = !empty($field_list[1]) ? $field_list[1] : 'value';
      $query->leftJoin('field_data_' . $field_name, $field_name,
        'n.nid = ' . $field_name . '.entity_id');
      $query->fields($field_name, array($field_name . '_' . $column));
    }
    else {
      $extra_fields[] = $field;
    }
  }
  if (isset($status)) {
    $query->condition('n.status', $status);
  }
  $query
    ->fields('n', array('nid', 'title') + $extra_fields)
    ->condition('n.type', OA_SECTION_TYPE)
    ->condition('og.entity_type', 'node')
    ->condition('og.field_name', OA_SPACE_FIELD)
    ->condition('og.gid', $gid)
    ->orderBy('w.field_oa_section_weight_value')
    ->orderBy('n.title');
  if (!$bypass_access_check) {
    $query->addTag('node_access');
  }
  if (module_exists('flag') && !$include_archived) {
    if ($flag = flag_get_flag('trash')) {
      $query->leftJoin('flagging', 'a', "a.fid = :fid AND a.entity_id = n.nid", array(':fid' => $flag->fid));
      // This makes sure that archived content isn't included, because 'uid'
      // will be NULL if the join didn't connect anything.
      $query->isNull('a.uid');
    }
  }
  $result = $query->execute();
  if (empty($fields)) {
    return $result->fetchAllKeyed(0, 1);
  }
  else {
    return $result->fetchAllAssoc('nid');
  }
}

/**
 * Return a list of all Groups
 *
 * @param $match string for autocomplete lookup
 * @param $match_operator string for autocomplete lookup
 * @param $limit int number to limit, or zero for no limit
 * @return
 *    An array of group nid, title, keyed by the group nid.
 */
function oa_core_get_all_groups($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'))
      ->condition('n.type', OA_GROUP_TYPE)
      ->addTag('node_access');
  if (!empty($match)) {
    $match = ($match_operator == 'CONTAINS') ? '%' . $match . '%' : $match;
    $match = ($match_operator == 'STARTS_WITH') ? '%' . $match : $match;
    $query->condition('n.title', $match, 'LIKE');
  }
  if (!empty($limit)) {
    $query->range(0, $limit);
  }
  return $query->execute()->fetchAllAssoc('nid');
}

/**
 * Get the users that are in a space (excluding inherited users).
 *
 * @param int $space_id
 *   The NID of the Space.
 * @param int $state
 *   (Optional) The state of the OG membership, for example:
 *   - OG_STATE_ACTIVE (the default)
 *   - OG_STATE_PENDING
 *   - OG_STATE_BLOCKED
 *
 * @return array
 *   An associative array of fully loaded user objects, keyed by user id.
 */
function oa_core_get_users_for_space($space_id, $state = OG_STATE_ACTIVE, $sort = FALSE) {
  $query = db_select('og_membership', 'og')
    ->fields('og', array('etid'))
    ->condition('og.entity_type', 'user')
    ->condition('og.state', $state)
    ->condition('og.group_type', 'node')
    ->condition('og.gid', $space_id);
  $query->join('users', 'u', 'u.uid = og.etid');
  $query->condition('u.status', 1);
  if (!empty($sort)) {
    $query->join('realname', 'n', 'n.uid = og.etid');
    $query->orderBy('n.realname');
  }
  $uids = $query->execute()->fetchCol();
  return user_load_multiple($uids);
}

/**
 * Helper to get membership nids for a group.
 *
 * @param int $nid
 *   The nid of the group to find og_membership nodes.
 * @param bool $loaded
 *   Whether to return just the nids or fully loaded nodes.
 *
 * @return array
 *   The og_membership nids or fully loaded node objects.
 */
function oa_core_get_membership_nodes($nid, $loaded = FALSE) {
  $nids = db_select('og_membership', 'og')
    ->fields('og', array('etid'))
    ->condition('og.entity_type', 'node')
    ->condition('og.gid', $nid)
    ->condition('og.field_name', OG_AUDIENCE_FIELD)
    ->execute()
    ->fetchCol(0);

  if ($loaded) {
    return node_load_multiple($nids);
  }
  else {
    return $nids;
  }
}

/**
 * Get the users that are in a space, including inherited users.
 *
 * @param int $space_id
 *   The NID of the Space.
 * @param int $state
 *   (Optional) The state of the OG membership, for example:
 *   - OG_STATE_ACTIVE (the default)
 *   - OG_STATE_PENDING
 *   - OG_STATE_BLOCKED
 *
 * @return array
 *   An associative array of fully loaded user objects, keyed by user id.
 */
function oa_core_get_inherited_users_for_space($space_id, $state = OG_STATE_ACTIVE) {
  $users = oa_core_get_users_for_space($space_id, $state);

  if (module_exists('og_subgroups') && function_exists('_og_subgroups_get_inherited_users')) {
    $inherited_users = _og_subgroups_get_inherited_users('node', $space_id);
    foreach ($inherited_users as $uid => $data) {
      foreach ($data as $item) {
        if ($item['membership']->state == $state) {
          $users[$uid] = $item['user'];
        }
      }
    }
  }

  return $users;
}

/**
 * Return the users that are the intersection of Group and Space membership.
 *
 * @param int $space_id
 *    The Space ID of the Open Atrium site
 * @param $group_id
 *    The Group ID
 * @return
 *    An array of Users keyed by uid
 */
function oa_core_get_group_users_for_space($space_id, $group_id) {
  $query = db_select('users', 'u');
  $query->innerJoin('og_membership', 'og1', 'u.uid = og1.etid');
  $query->innerJoin('og_membership', 'og2', 'u.uid = og2.etid');
  $query->fields('u', array('uid'))
      ->condition('og1.entity_type', 'user')
      ->condition('og1.gid', $space_id)
      ->condition('og1.group_type', 'node')
      ->condition('og2.entity_type', 'user')
      ->condition('og2.gid', $group_id)
      ->condition('og1.group_type', 'node');

  $results = $query->execute()->fetchAllAssoc('uid');
  return user_load_multiple(array_keys($results));
}

/**
 * Return a list of space ids that a user belongs to.
 *
 * @deprecated This function is redundant - use oa_core_get_groups_by_user().
 *
 * @see oa_core_get_groups_by_user()
 */
function oa_core_get_user_spaces($uid) {
  $groups = oa_core_get_groups_by_user(user_load($uid), 'node');
  return !empty($groups) ? $groups : array();
}

/**
 * Helper function to return the id of the space/group that contains the nid node
 *
 * This function is called a lot, so it needs to be fast
 * Do not use node_load here!
 *
 * @param $node
 *  A numeric NID or a complete $node object.
 * @param $allowed_types
 *  an array of content types that this node can be part of.
 *
 * @return
 *   A numeric NID of the group that this content is part of.
 *   If $node is a group or not member of a group, its NID is returned.
 */
function oa_core_get_group_from_node($node, $allowed_types = array(OA_SPACE_TYPE, OA_GROUP_TYPE)) {
  $cache = &drupal_static('oa_core_groups', array());
  // Find the NID in case a $node object was passed in..
  if (is_object($node) && !empty($node->nid)) {
    $nid = $node->nid;
    if (!empty($allowed_types) && in_array($node->type, $allowed_types)) {
      $cache[$nid] = $nid;
    }
  }
  else {
    $nid = $node;
  }

  if (isset($cache[$nid])) {
    return $cache[$nid];
  }

  $query = db_select('og_membership', 'f');
  $query->leftJoin('node', 'n', 'n.nid = f.gid');
  $result = $query
    ->fields('f', array('gid'))
    ->condition('f.etid', $nid)
    ->condition('f.group_type', 'node')
    ->condition('f.entity_type', 'node')
    ->condition('f.field_name', OA_SPACE_FIELD)
    ->condition('n.type', $allowed_types)
    ->execute()
    ->fetchAssoc();

  if (!empty($result)) {
    $cache[$nid] = $result['gid'];
  }
  else {
    $cache[$nid] = $nid;
  }
  return $cache[$nid];
}

/**
 * Sort function to sort users by name.
 */
function oa_core_sort_users_by_name($u1, $u2) {
  // Get last name for sorting.
  $name1 = !empty($u1->realname) ? oa_core_get_last_word($u1->realname) : $u1->name;
  $name2 = !empty($u2->realname) ? oa_core_get_last_word($u2->realname) : $u2->name;
  return strcasecmp($name1, $name2);
}

/**
 * Helper to return last word of a string
 */
function oa_core_get_last_word($string) {
  // Strip any text in parens or brackets
  // Also strip any title ending in period, like PhD.
  // Also strip roman numerals I, II, IV, etc
  $string = preg_replace('/([\(\[].*[\)\]]|\s[^\s]+\.$|\s[IV]+)/', '', $string);
  $string = trim($string);
  return ($pos =  strrpos($string, ' ')) ?  substr($string, $pos + 1) : $string;
}

/**
 * Return the name of a user
 */
function oa_core_realname($user) {
  return isset($user) ? (!empty($user->realname) ? $user->realname : $user->name) : '';
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_core_entity_build_display($entity, $id, $space, $subpage = '') {
  if (!empty($entity->nid)) {
    if (node_access('view', $entity)) {
      $display['title'] = l($entity->title, 'node/' . $entity->nid . $subpage);
    }
    else {
      $display['title'] = t('A @type', array('@type' => node_type_get_name($entity->type)));
    }
    $display['picture'] = '';
    $display['uid'] = 0;
    $display['options'] = array();
  }
  else {
    $display['title'] = l(format_username($entity), 'user/' . $entity->uid . $subpage);
    $display['uid'] = $entity->uid;
    $display['picture'] = oa_users_picture($entity);
    $display['options'] = array(
      'attributes' => array(
        'class' => array('use-ajax'),
      ),
      'query' => drupal_get_destination() + array(
        'token' => drupal_get_token('node_' . $space->nid . '_' . $entity->uid),
      ),
    );
  }

  return $display;
}

/**
 * Return vocabularies assigned to a specific content type
 */
function oa_core_get_entity_vocabs($entity_type, $bundle) {
  $vocabs = array();
  $fields = field_info_instances($entity_type, $bundle);
  foreach ($fields as $field_name => $field) {
    $info = field_info_field($field_name);
    // handle normal taxonomy_term_reference fields
    if ($info['type'] == 'taxonomy_term_reference') {
      foreach ($info['settings']['allowed_values'] as $value) {
        if (!empty($value['vocabulary'])) {
          $vocabs[$value['vocabulary']] = $value['vocabulary'];
        }
      }
    }
    // also handle entityreference fields pointing to taxonomy
    elseif (($info['type'] == 'entityreference') && ($info['settings']['target_type'] == 'taxonomy_term')) {
      if (!empty($info['settings']['handler_settings']['target_bundles'])) {
        foreach ($info['settings']['handler_settings']['target_bundles'] as $value) {
          $vocabs[$value] = $value;
        }
      }
    }
  }
  return $vocabs;
}

/**
 * Returns the named vocabulary
 * Cannot use core taxonomy_vocabulary_machine_name_load because og_vocab
 * alters the query to only return vocabs associated with the current space
 * see issue https://drupal.org/node/2270529
 */
function oa_core_taxonomy_vocabulary($machine_name) {
  // EntityFieldQuery is not subject to the
  // og_vocab_query_taxonomy_vocabulary_load_multiple_alter() function
  $efq = new EntityFieldQuery();
  $result = $efq->entityCondition('entity_type', 'taxonomy_vocabulary')
    ->propertyCondition('machine_name', $machine_name)
    ->execute();
  return !empty($result['taxonomy_vocabulary']) ? current($result['taxonomy_vocabulary']) : NULL;
}

/**
 * Return terms for a list of vocabularies
 */
function oa_core_get_vocab_terms($vocabs) {
  $options = array();
  foreach ($vocabs as $vocab) {
    if ($vocabulary = oa_core_taxonomy_vocabulary($vocab)) {
      if ($terms = taxonomy_get_tree($vocabulary->vid)) {
        foreach ($terms as $term) {
          $options[$term->tid] = str_repeat('-', $term->depth) . $term->name;
        }
      }
    }
  }
  return $options;
}

/**
 * Returns the version of Bootstrap (via Radix) being used
 * Returns 2 or 3 for Bootstrap, returns 0 if no Bootstrap is used
 */
function oa_core_get_bootstrap_version() {
  static $radix_version = NULL;
  if (isset($radix_version)) {
    return $radix_version;
  }

  // set default to 3 so if using a git clone without version info
  // we assume it's the latest -dev version
  $radix_version = 3;
  // parse the Radix info file to determine version
  $path = drupal_get_path('theme', 'radix') . '/' . 'radix.info';
  $info = drupal_parse_info_file($path);
  if (empty($info)) {
    // no Radix theme found, so return zero.
    $radix_version = 0;
  }
  elseif (!empty($info['version']) && strpos($info['version'], '7.x-') === 0) {
    $radix_version = intval(substr($info['version'], 4, 1));
  }
  return $radix_version;
}

/**
 * Helper function to create a new Section or Space Type taxonomy term
 * @param string $vocab
 *   Machine name of vocabulary to add term to
 * @param string $name
 *   Human readable label of the term
 * @param array $params
 *   expected to have fields for:
 *   'taxonomy' - vocabulary machine name.
 *   'name' - The human readable label of the term.
 *   'description' - The human readable description of the term.
 *   'node_options' - An array of node types which should be allowed within the section.
 *   'layout' - The panelizer layout key to use for this section.
 *   'icon' - The icon class to use in the sitemap.
 * @param bool $update
 *   Whether an existing term is allowed to be updated.
 */
function oa_core_create_term($vocab_name, $name, $params, $update = TRUE) {
  $vocab = oa_core_taxonomy_vocabulary($vocab_name);
  $term = NULL;

  // This function can get called from install hooks.
  // Make sure the Taxonomy is available.
  if (!$vocab) {
    features_revert(array(
      'oa_core' => array('taxonomy'),
      'oa_sections' => array('taxonomy'),
    ));
    drupal_static('taxonomy_vocabulary_get_names');
    $vocab = oa_core_taxonomy_vocabulary($vocab_name);
  }

  if (!empty($vocab)) {
    $conditions = array(
      'name' => trim($name),
      'vid' => $vocab->vid,
    );
    $term = current( entity_load('taxonomy_term', array(), $conditions));

    if (!$term || $update) {

      // Make sure the fields are available.
      $field_info = field_info_instances('taxonomy_term', $vocab_name);
      $revert = array();
      if (empty($field_info['field_oa_node_types'])) {
        $revert['oa_buttons'] = array('field_base', 'field_instance');
      }
      if (empty($field_info['field_oa_section_layout'])) {
        $revert['oa_core'] = array('field_base', 'field_instance');
      }
      if (empty($field_info['field_oa_icon_class'])) {
        $revert['oa_sections'] = array('field_base', 'field_instance');
      }
      if (!empty($revert)) {
        features_revert($revert);
        field_info_cache_clear();
      }

      $description = $params['description'];
      $node_options = $params['node_options'];
      $layout = $params['layout'];
      $icon = !empty($params['icon']) ? $params['icon'] : '';

      if ($term && $update) {
        // Update existing term.
        if (isset($term->field_oa_icon_class)) {
          $term->field_oa_icon_class[LANGUAGE_NONE][0]['value'] = $icon;
        }
        $term->field_oa_section_layout[LANGUAGE_NONE][0]['value'] = $layout;
        $term->field_oa_node_types[LANGUAGE_NONE] = array();
      }
      else {
        // Create new term.
        $term = (object)array(
          'vid' => $vocab->vid,
          'name' => $name,
          'description' => $description,
          'format' => 'panopoly_wysiwyg_text',
          'field_oa_icon_class' => array(
            LANGUAGE_NONE => array(
              array('value' => $icon),
            ),
          ),
          'field_oa_section_layout' => array(
            LANGUAGE_NONE => array(
              array('value' => $layout),
            ),
          ),
          'field_oa_node_types' => array(
            LANGUAGE_NONE => array(),
          ),
          'path' => array(
            'alias' => '',
            'pathauto' => '',
          ),
          'oa_button' => TRUE,
        );
      }

      if (!empty($node_options)) {
        foreach ($node_options as $type) {
          $term->field_oa_node_types[LANGUAGE_NONE][] = array('value' => $type);
        }
      }
      taxonomy_term_save($term);
    }
  }
  return $term;
}

/**
 * Helper function to replace HTML tags in $str.
 * @param $str - string to process
 * @param $tags - array of oldtag=>newtag items
 * @return string
 */
function oa_core_replace_tags($str, $tags) {
  foreach ($tags as $old => $new) {
    $str = preg_replace("~<(/)?$old>~", "<\\1$new>", $str);
  }
  return $str;
}

/**
 * Trim text to a specified length
 * Similar to views_trim_text or the Smart Trim module
 * but includes consistent options for removing tags needed by OA2
 */
function oa_core_trim_text($value, $more_link = '', $max_length = NULL) {
  $trimmed = FALSE;
  // Remove and replace some HTML tags
  $value = oa_core_replace_tags($value, array(
    'h1' => 'h4',
    'h2' => 'h4',
    'h3' => 'h4',
  ));
  $value = strip_tags($value, '<br><p><h1><h2><h3><h4><h5><h6><ol><ul><li><dl><dd><dt><a><b><i><strong><em><table><tbody><th><tr><td>');

  $max_length = isset($max_length) ? $max_length : variable_get('teaser_length', 600);
  if (drupal_strlen($value) > $max_length) {
    $value = drupal_substr($value, 0, $max_length);

    // only trim on word boundries
    $regex = "(.*)\b.+";
    if (function_exists('mb_ereg')) {
      mb_regex_encoding('UTF-8');
      $matches = array();
      $found = mb_ereg($regex, $value, $matches);
    }
    else {
      $found = preg_match("/$regex/us", $value, $matches);
    }
    if ($found) {
      $value = $matches[1];
    }

    // Remove scraps of HTML entities from the end of a strings
    $value = rtrim(preg_replace('/(?:<(?!.+>)|&(?!.+;)).*$/us', '', $value));
    $value .= '…';

    $trimmed = TRUE;
  }
  // add any needed closing tags.
  $value = _filter_htmlcorrector($value);

  if ($trimmed) {
    if (!empty($more_link)) {
      $value .= '<span class="more-link">' .
        l(t('more…'), $more_link) . '</span>';
    }
  }

  return $value;
}

/**
 * Helper function to return the summary of a node or the trimmed body text
 * @param $node
 */
function oa_core_get_summary($node) {
  $body_field = field_view_field('node', $node, 'body');
  $body = !empty($body_field['#items'][0]['summary']) ? $body_field['#items'][0]['summary'] :
    (!empty($body_field[0]['#markup']) ? oa_core_trim_text($body_field[0]['#markup'], 'node/' . $node->nid . '/view') : '');
  return $body;
}


/**
 * Determine whether a user has a given privilege for groups.
 *
 * This modules the logic of og_user_access but for multiple node groups.
 * IMPORTANT, any changes to og_user_access reflect here.
 *
 * We cannot offer any speed improvements if og_user_access_alter is implemented
 * as it requires a entity_load.
 *
 * @param $group_type
 *  This will fall through to og_user_access access if not 'node'
 * @param $nids
 *   Array of node nids that are groups.
 * @param $string
 *  String can be a string or array of strings (which diverges from
 *   og_user_access) of permissions to check. If an array is passed,
 *   it'll be TRUE for that group if user has ANY of the permissions.
 *
 * @return
 *   An array of nids to access.
 */
function oa_user_access_nids($group_type, $nids, $string, $account = NULL, $skip_alter = FALSE, $ignore_admin = FALSE) {
  global $user;
  $strings = is_array($string) ? $string : array($string);

  $access = &drupal_static(__FUNCTION__, array());
  if (empty($account)) {
    $account = $user;
  }

  $nids = drupal_map_assoc($nids);

  // Administer group permission. We don't cache it cause ignore_admin can change.
  if ($account->uid == 1 || (!$ignore_admin && user_access('administer group', $account))) {
    $return = array();
    foreach ($nids as $nid) {
      $return[$nid] = TRUE;
    }
    return $return;
  }

  // We don't handle not-nodes (cause hard to look up owner), the alter hook
  // (it needs full node_load).
  $alter = module_implements('og_user_access_alter');
  foreach (array('og_subgroups', 'og_ui') as $remove) {
    $pos = array_search($remove, $alter);
    if ($pos !== FALSE) {
      unset($alter[$pos]);
    }
  }
  // We cannot replicate unknown alters or unsubscribe logic, so fallback.
  // @see og_ui_og_user_access_alter().
  if ($group_type != 'node' || (!$skip_alter && $alter) || in_array('unsubscribe', $strings)) {
    foreach ($nids as $nid) {
      foreach ($strings as $string) {
        if (!isset($access[$account->uid][$string][$nid])) {
          $access[$account->uid][$string][$nid] = og_user_access($group_type, $nid, $string, $account, $skip_alter, $ignore_admin);
        }
      }
    }
  }

  $lookup = array();
  $all_lookup = array();
  // Find what nodes/permissions still need to be looked up.
  foreach ($strings as $string) {
    if (!empty($access[$account->uid][$string])) {
      $lookup[$string] = array_diff_key($nids, $access[$account->uid][$string]);
    }
    else {
      $lookup[$string] = $nids;
    }
    if (!$lookup[$string]) {
      unset($lookup[$string]);
    }
  }
  foreach ($lookup as $string => $nids_array) {
    $all_lookup += $nids_array;
  }

  // Group manager has all privileges (if variable is TRUE).
  if ($all_lookup && !empty($account->uid) && variable_get('og_group_manager_full_access', TRUE)) {
    $authored = db_query('SELECT nid FROM {node} WHERE nid in (:nids) AND uid = :uid', array(':nids' => $all_lookup, ':uid' => $account->uid))->fetchCol();
    foreach ($authored as $nid) {
      foreach ($strings as $string) {
        $access[$account->uid][$string][$nid] = TRUE;
        unset($lookup[$string][$nid]);
        unset($all_lookup[$nid]);
      }
    }
  }

  if ($all_lookup && !empty($account->uid)) {
    // Add administer group as first permission checked (as most likely).
    if (!$ignore_admin) {
      array_unshift($strings, 'administer group');
    }

    /**
     * The query needed is quite complex for regular oa access.
     *
     * The rid in og_users_roles can either be associated with no group if
     * the roles have not been overriden or with the group if they have.
     *
     * The rid can either be associated with the user or the 'member' role
     * which is added automatically.
     *
     * Below is a sample query.
     * @code
     * SELECT om.gid, orp.permission
     * FROM og_role_permission orp
     * INNER JOIN og_role oro ON oro.rid = orp.rid
     * INNER JOIN og_membership om ON om.group_type = 'node' AND oro.group_type = 'node' AND om.entity_type='user'
     * INNER JOIN node n ON n.nid = om.gid
     * INNER JOIN field_data_og_roles_permissions fdp on fdp.entity_type = 'node' AND fdp.entity_id = om.gid
     * LEFT JOIN og_users_roles our ON our.rid = oro.rid AND our.uid = om.etid AND our.group_type = "node" AND our.gid = om.gid
     * WHERE om.etid = 159
     *   AND (oro.gid = om.gid OR (fdp.og_roles_permissions_value = 0 and oro.gid = 0 AND oro.group_bundle = n.type))
     *   AND (our.uid = 159 OR oro.name = 'member')
     *   AND om.state = 1 AND om.gid IN (139);
     * @endcode
     *
     * @todo BUNDLE DAMMIT
     */
    $query = db_select('og_role_permission', 'orp');
    $query->innerJoin('og_role', 'oro', 'oro.rid = orp.rid');
    $query->innerJoin('og_membership', 'om', "om.group_type = 'node' AND oro.group_type = 'node' AND om.entity_type='user'");
    $query->innerJoin('node', 'n', "n.nid = om.gid");
    $query->innerJoin('field_data_og_roles_permissions', 'fdp', "fdp.entity_type = 'node' AND fdp.entity_id = om.gid");
    $query->leftJoin('og_users_roles', 'our', "our.rid = oro.rid AND our.uid = om.etid AND our.group_type = 'node' AND our.gid = om.gid");
    $query->fields('om', array('gid'));
    $query->fields('orp', array('permission'));
    $query->condition('om.etid', $account->uid);
    $and = db_and()
      ->condition('fdp.og_roles_permissions_value', 0)
      ->condition('oro.gid', 0)
      ->where('n.type = oro.group_bundle');
    $or = db_or()
      ->where('oro.gid = om.gid')
      ->condition($and);
    $query->condition($or);
    $or = db_or()
      ->condition('our.uid', $account->uid)
      ->condition('oro.name', 'member');;
    $query->condition($or);
    $query->condition('orp.permission', $strings);
    $query->condition('state', OG_STATE_ACTIVE);
    $query->condition('om.gid', $all_lookup);
    $result = $query->execute();
    $rows = $result->fetchAll();
    foreach ($rows as $row) {
      $access[$account->uid][$row->permission][$row->gid] = TRUE;
      unset($lookup[$row->permission][$row->gid]);
    }
  }
  // Check parent access.
  // This needs further optomization.
  if ($lookup && !$skip_alter && in_array('og_subgroups', module_implements('og_user_access_alter'))) {
    $user_groups = og_subgroup_user_groups_load($account, FALSE);
    foreach ($lookup as $string => $nids_array) {
      foreach ($nids_array as $nid) {
        if (oa_og_subgroups_check_access($string, $group_type, $nid, $user_groups, TRUE)) {
          $access[$account->uid][$string][$nid] = TRUE;
          unset($lookup[$string][$nid]);
        }
      }
    }
  }

  // Any extra NID is no access.
  foreach ($lookup as $string => $nids_array) {
    foreach ($nids_array as $nid) {
      // This should not be set, but just in case only set to false if not.
      if (!isset($access[$account->uid][$string][$nid])) {
        $access[$account->uid][$string][$nid] = FALSE;
      }
    }
  }

  // Figure out if user has any access.
  $return = array();
  $remaining_nids = $nids;
  do {
    $string = array_shift($strings);
    if (!empty($access[$account->uid][$string])) {
      $return += array_filter(array_intersect_key($access[$account->uid][$string], $remaining_nids));
    }
    $remaining_nids = array_diff_key($nids, $return);
  } while ($remaining_nids && $strings);
  // If no strings left, there are no access.
  if ($remaining_nids) {
    foreach ($remaining_nids as $nid) {
      $return[$nid] = FALSE;
    }
  }

  // Need to return array as combination of strings.
  return $return;
}

/**
 * Check access for this group's parents.
 *
 * Copy of _og_subgroups_check_access but using our functions for optomization.
 *
 * @see _og_subgroups_check_access().
 */
function oa_og_subgroups_check_access($string, $group_type, $id, $user_groups, $check_member_access = FALSE) {
  // Check only one level at a time due to permission inheritance field.
  if ($parent_groups = og_subgroups_intersect_groups(og_subgroups_parents_load($group_type, $id, TRUE, FALSE), $user_groups)) {
    foreach ($parent_groups as $parent_group_type => $ids) {
      // Find all groups that ahve inheritence set to child (assume inherit
      // [default] otherwise).
      $child_inheritence = _og_subgroups_get_field_matching($parent_group_type, $ids, OG_USER_INHERITANCE_PERMISSION_FIELD, OG_USER_INHERITANCE_PERMISSION_CHILD);
      $parent_inheritence = array_diff($ids, $child_inheritence);
      if ($parent_inheritence = array_diff($ids, $child_inheritence)) {
        if (array_filter(oa_user_access_nids($parent_group_type, $parent_inheritence, $string, NULL, TRUE))) {
          return TRUE;
        }
      }
      if ($check_member_access) {
        foreach ($child_inheritence as $parent_group_id) {
          if (og_subgroups_check_member_user_access($group_type, $id, $string)) {
            return TRUE;
          }
        }
      }
      // Check parents if neither current nor member gave access.
      foreach ($parent_inheritence as $parent_group_id) {
        if (oa_og_subgroups_check_access($string, $parent_group_type, $parent_group_id, $user_groups)) {
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

/**
 * Replacement for og_user_access.
 *
 * Because we don't use the alter hook, we don't need to do the full entity load
 * so often checking via direct query (if node is unlikely to have been loaded)
 * is faster.
 *
 * @see og_user_access
 */
function oa_user_access($group_type, $gid, $string, $account = NULL, $skip_alter = FALSE, $ignore_admin = FALSE) {
  $access = oa_user_access_nids($group_type, array($gid), $string, $account, $skip_alter, $ignore_admin);
  return reset($access);
}

/**
 * Helper function to return a file object that represents the default site banner.
 */
function oa_core_get_banner_default() {
  global $base_url;
  $filename = module_invoke_all('oa_core_banner_default');
  if (!empty($filename)) {
    $filename = current($filename);
    $uri = $base_url . '/' . $filename;
  }
  else {
    $uri = theme_get_setting('logo');
    $filename = str_replace($base_url .'/', '', $uri);
  }
  if (file_exists($filename)) {
    $site_file = new stdClass();
    $site_file->uri = $uri;
    $info = image_get_info($filename);
    $site_file->metadata['height'] = $info['height'];
    $site_file->metadata['width'] = $info['width'];
    return $site_file;
  }
  return NULL;
}

/**
 * Helper function to return/add classes to the body tag
 * @param array $styles
 */
function oa_core_body_classes($new_classes = array()) {
  static $classes = array();
  if (!empty($new_classes)) {
    if (!is_array($new_classes)) {
      $new_classes = array($new_classes);
    }
    $classes = array_merge($classes, $new_classes);
  }
  return $classes;
}

/**
 * Add the node layout as a body class to the page
 * @param $node
 */
function oa_core_add_node_class($node) {
  if (!empty($node->panelizer['page_manager']->name)) {
    oa_core_add_layout_class($node->panelizer['page_manager']->name);
  }
}

/**
 * Add the taxonomy layout as a body class to the page
 * @param $vocab_name
 * @param $tid
 */
function oa_core_add_taxonomy_class($tid) {
  if ($term = taxonomy_term_load($tid)) {
    if (!empty($term->field_oa_section_layout[LANGUAGE_NONE][0]['value'])) {
      oa_core_add_layout_class($term->field_oa_section_layout[LANGUAGE_NONE][0]['value']);
    }
  }
}

/**
 * Add the given layout name as a body class on the page
 * @param $name of layout.  The node: part is skipped
 * @param $prefix optional prefix for the class
 */
function oa_core_add_layout_class($name, $prefix = '') {
  $list = explode(':', $name);
  $prefix = !empty($prefix) ? $prefix . '-' : '';
  if (count($list) > 1) {
    $class_name = $prefix . $list[1];
    if (count($list) > 2) {
      $class_name .= '-' . $list[2];
      oa_core_body_classes(drupal_html_class($class_name));
    }
  }
}

/**
 * Wrapper around @see batch_set().
 *
 * @param array $batch
 */
function oa_core_batch_set(&$batch) {
  // For Drush.
  if (drupal_is_cli()) {
    $batch['progressive'] = FALSE;
    batch_set($batch);
    if (function_exists('drush_backend_batch_process')) {
      // Running via drush, to start the batch processing.
      drush_backend_batch_process();
    }
  }
  else {
    // Running interactively via the UI so just set the batch.
    batch_set($batch);
  }
}

/**
 * Helper to combine multiple calls in OA to features_template_revert() to
 * just a single call.
 */
function oa_core_features_template_revert() {
  if (!variable_get('oa_core_template_revert', FALSE)) {
    variable_set('oa_core_template_revert', TRUE);
    drupal_register_shutdown_function('oa_core_revert_template', 'oa_core_template_revert');
  }
}

/**
 * This is called when all modules, using oa_core_features_template_revert(),
 * have registered for a template revert.
 *
 * @param string $variable
 *   Variable name to delete.
 */
function oa_core_revert_template($variable) {
  features_template_revert();
  variable_delete($variable);
}
