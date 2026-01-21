<?php
/**
 * @file
 * Code for OpenAtrium caching helpers
 */

/**
 * Helper function to get a value from static or db cache
 * @param $cid : the cache id (see oa_core_get_cache_id)
 * @param $value : the value returned
 * @return bool : TRUE if cache value is returned
 */
function oa_core_get_cache($name, $cid, &$value) {
  $static_cache = &drupal_static($name);
  if (isset($static_cache[$cid])) {
    $value = $static_cache[$cid];
    return TRUE;
  }

  if ($cache = cache_get($cid)) {
    $static_cache[$cid] = $cache->data;
    $value = $cache->data;
    return TRUE;
  }
  return FALSE;
}

/**
 * Helper function to set a value to the static and db cache
 * @param $cid: the cache id (see oa_core_get_cache_id)
 * @param $value : the value to save in cache
 */
function oa_core_set_cache($name, $cid, $value) {
  $static_cache = &drupal_static($name);
  $static_cache[$cid] = $value;
  cache_set($cid, $value);
}

/**
 * Helper function to clear the static and db cache
 * @param $cid: the cache id (see oa_core_get_cache_id)
 * @param $value : the value to save in cache
 */
function oa_core_clear_cache($name, $cid) {
  cache_clear_all($cid, 'cache', TRUE);
  drupal_static_reset($name);
}

/**
 * Helper function to return a caching ids.
 * @param $cache_name : The name of the cache table.
 * @param null $id : if not-null, adds the id to the cache id.  Typically passes the $user->uid
 * @param bool $include_archived : if TRUE, adds _archived to the cache id
 * @param array $args : appends each argument to the cache id
 * @return string : the cache_id for cache_get/set
 */
function oa_core_get_cache_id($cache_name, $id = NULL, $include_archived = FALSE, $args = array()) {

  $cid = $cache_name . '_';

  if (!empty($id)) {
    $cid .= $id;

    if ($include_archived) {
      $cid .= '_archived';
    }

    foreach ($args as $arg) {
      if (!empty($arg) && is_array($arg)) {
        $cid .= '_' . implode(':', $arg);
      }
      else {
        $cid .= '_' . (!empty($arg) ? $arg : '');
      }
    }
  }

  return $cid;
}

/**
 * Helper function to clear the various caches by calling a hook for each module.
 */
function oa_core_clear_group_cache($node = NULL, $uid = NULL, $include_archived = FALSE) {
  module_invoke_all('oa_clear_cache', $node, $uid, $include_archived);
}

/**
 * Implements hook_oa_clear_cache().
 */
function oa_core_oa_clear_cache($node = NULL, $uid = NULL, $include_archived = FALSE) {
  $cid = oa_core_get_cache_id(OA_CACHE_GROUPS_BY_USER, $uid, $include_archived);
  oa_core_clear_cache(OA_CACHE_GROUPS_BY_USER, $cid);

  $cid = oa_core_get_cache_id(OA_CACHE_GROUPS_BY_USER_ACCESS, $uid, $include_archived);
  oa_core_clear_cache(OA_CACHE_GROUPS_BY_USER_ACCESS, $cid);

  $cid = oa_core_get_cache_id(OA_CACHE_GET_PARENTS, NULL, $include_archived);
  oa_core_clear_cache(OA_CACHE_GET_PARENTS, $cid);

  $cid = oa_core_get_cache_id(OA_CACHE_GROUPS_BY_PARENT, NULL, $include_archived);
  oa_core_clear_cache(OA_CACHE_GROUPS_BY_PARENT, $cid);

  $cid = oa_core_get_cache_id(OA_CACHE_TOP_PARENTS, NULL, $include_archived);
  oa_core_clear_cache(OA_CACHE_TOP_PARENTS, $cid);
}

/**
 * Implements hook_flag_flag().
 */
function oa_core_flag_flag($flag, $content_id, $account, $flagging) {
  oa_core_trigger_flag('flag', $flag, $content_id, $account);
}

/**
 * Implements hook_flag_unflag().
 */
function oa_core_flag_unflag($flag, $content_id, $account, $flagging) {
  oa_core_trigger_flag('unflag', $flag, $content_id, $account);
}

/**
 * Helper function for flag and unflag hooks.
 */
function oa_core_trigger_flag($op, $flag, $content_id, $account) {
  if ($flag->name == 'trash') {
    if (empty($account)) {
      global $user;
      $account = $user;
    }
    oa_core_clear_group_cache(NULL, $account->uid, TRUE);
  }
}

/**
 * Implements hook_flag_reset().
 */
function oa_core_flag_reset($flag, $entity_id, $rows) {
  if ($flag->name == 'trash') {
    oa_core_clear_group_cache();
  }
}

/** NOTE: hook_node_update is in oa_core.access.inc **/

/**
 * Implements hook_node_insert().
 */
function oa_core_node_insert($node) {
  if (($node->type == OA_SPACE_TYPE) || ($node->type == OA_GROUP_TYPE)) {
    entity_get_controller('node')->resetCache(array($node->nid));
    drupal_static_reset('oa_core_node_grants');
    oa_core_clear_group_cache($node);
  }
  elseif ($node->type == OA_SECTION_TYPE) {
    // clear the static node cache for the space node so correct access
    // values are tested in hook_node_access_records
    entity_get_controller('node')->resetCache(array($node->nid));
    drupal_static_reset('oa_core_node_grants');
  }
}

/**
 * Implements hook_node_delete().
 */
function _oa_core_node_delete($node) {
  if (($node->type == OA_SPACE_TYPE) || ($node->type == OA_GROUP_TYPE)) {
    oa_core_clear_group_cache($node);
  }
}

/**
 * Implements hook_user_update()
 */
function oa_core_user_update(&$edit, $account, $category) {
  if (empty($account)) {
    global $user;
    $account = $user;
  }
  oa_core_clear_group_cache(NULL, $account->uid);
}

/** NOTE: oa_core_og_membership_insert is in oa_core.access.inc **/

/**
 * Implements hook_og_membership_update().
 */
function oa_core_og_membership_update($og_membership) {
  if ($og_membership->entity_type == 'user') {
    oa_core_clear_group_cache(NULL, $og_membership->etid);
  }
}

/**
 * Implements hook_og_membership_delete().
 */
function oa_core_og_membership_delete($og_membership) {
  if ($og_membership->entity_type == 'user') {
    oa_core_clear_group_cache(NULL, $og_membership->etid);
  }
}
