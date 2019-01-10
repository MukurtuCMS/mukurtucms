<?php
/**
 * @file
 * Code for Access Control functions for OpenAtrium spaces
 */

/**
 * Determine access to a Open Atrium Section
 * do NOT use node_load here as it gets called from hook_node_grants()
 * TODO: No longer called from node_grants, but called from tests.  Is this still needed?
 */
function oa_core_section_access($row, $spaces, $account) {

  $gid = $row['field_oa_group_ref_target_id'];
  $team_id = $row['field_oa_team_ref_target_id'];
  $user_id = $row['field_oa_user_ref_target_id'];

  // check if no access fields are set
  if (is_null($gid) && is_null($team_id) && is_null($user_id)) {
    return NODE_ACCESS_ALLOW;
  }

  // Test Group membership
  if (!is_null($gid) && !empty($spaces['node'])) {
    if (in_array($gid, $spaces['node'])) {
      return NODE_ACCESS_ALLOW;
    }
  }

  // Test Team membership
  if (!is_null($team_id)) {
    if (oa_core_member_of_team($team_id, $account->uid)) {
      return NODE_ACCESS_ALLOW;
    }
  }

  // Test User membership
  if (!is_null($user_id)) {
    if ($user_id == $account->uid) {
      return NODE_ACCESS_ALLOW;
    }
  }

  // none of the groups, teams, or users allowed access, so deny access
  return NODE_ACCESS_DENY;
}

/**
 * Implements hook_og_subgroups_is_parent_private_alter().
 * Handle special Atrium case where a private Group Parent does not make a public
 * space private.  Only having a private SPACE Parent makes a public space private.
 * @param $result
 * @param $entity_type
 * @param $entity
 */
function oa_core_og_subgroups_is_parent_private_alter(&$result, $entity_type, $entity) {
  if ($result && ($entity_type == 'node')) {
    if ($entity->type == OA_GROUP_TYPE) {
      // A Private parent GROUP does not make the child space private
      $result = FALSE;
    }
  }
}

/**
 * Implements hook_node_grants().
 * Define node access grant realm for Open Atrium sections
 */
function oa_core_node_grants($account, $op) {
  $cache = &drupal_static('oa_core_node_grants', array());

  if ($op != 'view' || !$account->uid) {
    return array();
  }

  if (isset($cache[$account->uid])) {
    return $cache[$account->uid];
  }

  // Handle unpublished content permissions
  if (user_access('view own unpublished content') && $account->uid) {
    $grants[OA_UNPUBLISHED_REALM] = array($account->uid);
  }

  // Combine the spaces the user is part of with public spaces.
  $member_spaces = oa_core_get_groups_by_user($account, 'node');
  $spaces = array_merge($member_spaces, oa_core_get_public_spaces(array(OA_SPACE_TYPE => OA_SPACE_TYPE), NULL,  FALSE, FALSE));
  if (!empty($spaces)) {
    $query = db_select('node', 'n');

    // Join the og table to filter by spaces.
    $query->join('og_membership', 'og', "n.nid = og.etid AND og.entity_type = 'node' AND og.field_name = '" . OA_SPACE_FIELD . "'");
    $query->condition('og.gid', $spaces, 'IN');

    // we join with the Groups, Teams, Users fields
    $query->fields('n', array('nid'));
    $query->condition('n.type', OA_SECTION_TYPE);

    // Create an or condition that finds if section is allowed.
    $db_or = db_or();

    // Allow author of section.
    $db_or->condition('n.uid', $account->uid , '=');

    // If user is specified in user ref column.
    $query->leftJoin('field_data_field_oa_user_ref', 'u', "n.nid = u.entity_id AND u.entity_type = 'node'");
    $db_or->condition('u.field_oa_user_ref_target_id', $account->uid , '=');


    // If one of the groups are included.
    if ($member_spaces) {
      $query->leftJoin('field_data_field_oa_group_ref', 'o', "n.nid = o.entity_id AND o.entity_type = 'node'");
      $db_or->condition('o.field_oa_group_ref_target_id', $member_spaces , 'IN');
    }

    // If one of the teams are included.
    $query->leftJoin('field_data_field_oa_team_ref', 't', "n.nid = t.entity_id AND t.entity_type = 'node'");
    $query->leftJoin('node', 'tn', "tn.nid = t.field_oa_team_ref_target_id");
    // Add creater of team.
    $db_or->condition('tn.uid', $account->uid , '=');
    $query->leftJoin('field_data_field_oa_team_users', 'tu', "t.field_oa_team_ref_target_id = tu.entity_id AND tu.entity_type = 'node' AND tu.deleted=0");
    // If user is part of team.
    $db_or->condition('tu.field_oa_team_users_target_id', $account->uid , '=');

    // Add or to query.
    $query->condition($db_or);


    // Set grants to nids, which should be only valid ones.
    $grants[OA_ACCESS_REALM] = $query->execute()->fetchCol(0);
  }

  $cache[$account->uid] = !empty($grants) ? $grants : array();
  return $cache[$account->uid];
}

/**
 * Implements hook_node_access_records().
 */
function oa_core_node_access_records($node) {
  $grants = array();
  $sids = array();
  if ($node->status == 0) {
    // Grant author access to unpublished content.
    if ($node->uid) {
      $grants[] = array(
        'realm' => OA_UNPUBLISHED_REALM,
        'gid' => $node->uid,
        'grant_view' => 1,
        'grant_update' => 0,
        'grant_delete' => 0,
        'priority' => 0,
      );
    }
    return $grants;
  }
  elseif ($node->type == OA_SECTION_TYPE) {
    if (!oa_core_section_is_public($node)) {
      $sids[] = $node->nid;
    }
  }
  // Look for the default section reference
  elseif (!empty($node->{OA_SECTION_FIELD})) {
    foreach ($node->{OA_SECTION_FIELD}[LANGUAGE_NONE] as $entity_ref) {
      $section = node_load($entity_ref['target_id']);
      if (!oa_core_section_is_public($section)) {
        $sids[] = $entity_ref['target_id'];
      }
    }
  }
  if (empty($sids)) {
    return array();
  }

  foreach ($sids as $sid) {
    $grants[] = array(
      'realm' => OA_ACCESS_REALM,
      'gid' => $sid,
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
      // Priority 1 means lesser grants for this node will be ignored.
      'priority' => 1,
    );
  }

  return !empty($grants) ? $grants : array();
}

/**
 * Implements hook_node_access().
 *
 * Add proper 'create' access checks that OG doesn't handle
 */
function oa_core_node_access($node, $op, $account) {
  $type = is_string($node) ? $node : (is_array($node) ? $node['type'] : $node->type);

  if ($op == 'create' && (($type == OA_SPACE_TYPE) || og_is_group_content_type('node', $type))) {
    // In og.module, og_node_access doesn't handle 'create' because
    // it doesn't have a Group context.
    // Well, in OA2 we *have* a Group context most of the time.
    // Can't call oa_core_get_space_context() however since
    // og_context_determine_context() will cause an infinite loop
    if (defined('OG_SESSION_CONTEXT_ID') && isset($_SESSION[OG_SESSION_CONTEXT_ID])) {
      $space_id = $_SESSION[OG_SESSION_CONTEXT_ID];
      // so let's use that to test 'create' access
      if ($space_id) {
        $return = og_user_access('node', $space_id, "$op $type content", $account);
        if ($return) {
          return NODE_ACCESS_ALLOW;
        }
      }
      if ($type != OA_SPACE_TYPE) {
        return NODE_ACCESS_DENY;
      }
    }
  }

  return NODE_ACCESS_IGNORE;
}

/**
 * Implements hook_node_update().
 *
 * if saving a section or space node, update access locks on related content
 */
function oa_core_node_update($node) {
  if (($node->type == OA_SPACE_TYPE) || ($node->type == OA_GROUP_TYPE)) {
    // check if group access changed and update space content grants
    $rebuild = module_invoke_all('oa_core_og_content_needs_rebuild', $node);
    if (in_array(TRUE, $rebuild, TRUE)) {
      // Get all subgroups for this node.
      $subgroup_nids = oa_core_get_groups_by_parent($node->nid, $node->type, NULL, FALSE, NULL, TRUE, FALSE);
      $batch = batch_get();
      // Don't do nested batch
      if (empty($batch)) {
        // Prepare the batch.
        _oa_core_update_access_records_batch_prepare($subgroup_nids);
        // Trigger the batch.
        batch_process();
      }
      else {
        oa_core_update_access_records($subgroup_nids);
      }
    }
    oa_core_clear_group_cache($node);
  }
  elseif ($node->type == OA_SECTION_TYPE) {
    // if section node changed from public to private, update content grants
    $was_public = oa_core_section_is_public($node->original);
    $is_public  = oa_core_section_is_public($node);
    if ($was_public != $is_public) {
      // rebuild section content nodes
      $nids = db_select('field_data_' . OA_SECTION_FIELD, 'n')
        ->fields('n', array('entity_id'))
        ->condition('n.entity_type', 'node')
        ->condition('n.oa_section_ref_target_id', $node->nid)
        ->execute()
        ->fetchCol(0);
      // clear the static node cache for the space node so correct access
      // values are tested in hook_node_access_records
      entity_get_controller('node')->resetCache(array($node->nid));
      oa_core_update_access_records($nids);
    }
  }
}

/**
 * Update the node_access_records of the given nodes.
 *
 * @param array $nids
 *   Node nids that need updated node grants.
 */
function oa_core_update_access_records($nids) {
  drupal_static_reset('oa_core_node_grants');
  foreach ($nids as $nid) {
    $node = node_load($nid);
    // Clear the static node cache for the space node so correct access
    // values are tested in hook_node_access_records.
    entity_get_controller('node')->resetCache(array($nid));
    // Update the node grants.
    node_access_acquire_grants($node);
  }
}

/**
 * Set up the batch process to update node records.
 *
 * @param array $subgroup_nids
 *   Nids for all subgroups of the node being updated.
 */
function _oa_core_update_access_records_batch_prepare($subgroup_nids) {

  // Define the batch.
  $batch = array(
    'title' => t('Updating node access records due to a change in "Group Visibility"'),
    'init_message' => t('Preparing to update records.'),
    'operations' => array(array('_oa_core_update_access_records_batch', array($subgroup_nids))),
    'finished' => '_oa_core_update_access_records_batch_finished',
  );

  // Set the batch using a helper in case drush is used.
  oa_core_batch_set($batch);
}

/**
 * Batch for updating node access records.
 *
 * @param array $subgroup_nids
 *   Nids for all subgroups of the node being updated.
 * @param array $context
 *   Carried over between batches.
 */
function _oa_core_update_access_records_batch($subgroup_nids, &$context) {
  if (empty($context['sandbox']['nids'])) {

    $context['sandbox']['nids'] = $subgroup_nids;

    // These are nids returned from oa_core_get_groups_by_parent().
    foreach ($subgroup_nids as $nid) {
      // Get membership nids using the og_group_ref field.
      $membership_nids = oa_core_get_membership_nodes($nid);
      // Merge the results.
      $new_array = array_merge($context['sandbox']['nids'], $membership_nids);
      // Update the sandbox.
      $context['sandbox']['nids'] = $new_array;
    }
    $context['results'] = count($context['sandbox']['nids']);
  }

  // Number of nodes updated per pass.
  $records_per_pass = 25;

  // Define the records to run for this pass.
  $current_records = array_splice($context['sandbox']['nids'], 0, $records_per_pass);

  // Update the node access records for this pass.
  oa_core_update_access_records($current_records);

  // We are done when the sandbox nids array is empty.
  $context['finished'] = empty($context['sandbox']['nids']) ? 1 : 0;

}

/**
 * Called when the batch is finished.
 *
 * @param boolean $success
 * @param int $results
 * @param $operations
 */
function _oa_core_update_access_records_batch_finished($success, $results, $operations) {
  if ($success && !empty($results)) {
    drupal_set_message(t('Updated node access records for @count nodes.', array('@count' => $results)));
  }
}

/**
 * Implements hook_oa_core_og_content_needs_rebuild().
 */
function oa_core_oa_core_og_content_needs_rebuild($node) {
  return isset($node->group_access[LANGUAGE_NONE][0]['value']) &&
    isset($node->original->group_access[LANGUAGE_NONE][0]['value']) &&
    ($node->group_access[LANGUAGE_NONE][0]['value'] !=
     $node->original->group_access[LANGUAGE_NONE][0]['value']);
}

/**
 * Implements hook_file_entity_access().
 *
 * Check permissions of private files based upon the node they are attached to
 */
function oa_core_file_entity_access($op, $file, $account) {
  if (is_object($file) && in_array($op, array('view', 'download'))) {
    $scheme = file_uri_scheme($file->uri);
    $wrapper = file_entity_get_stream_wrapper($scheme);
    if (!empty($wrapper['private'])) {
      $query = db_select('node', 'n');
      if (user_access('view revisions')) {
        $query->join('field_revision_field_oa_media', 'f', "n.nid = f.entity_id AND f.entity_type = 'node'");
      }
      else {
        $query->join('field_data_field_oa_media', 'f', "n.nid = f.entity_id AND f.entity_type = 'node'");
      }
      $nids = $query
        ->fields('n', array('nid'))
        ->condition('f.field_oa_media_fid', $file->fid)
        ->addTag('node_access')
        ->execute()
        ->fetchCol(0);
      // add paragraph references
      if (module_exists('paragraphs')) {
        $query = db_select('node', 'n');
        if (user_access('view revisions')) {
          $query->join('field_revision_field_oa_related', 'r', "n.nid = r.entity_id AND r.entity_type = 'node'");
          $query->join('field_revision_field_oa_media', 'f', "r.field_oa_related_value = f.entity_id AND f.entity_type = 'paragraphs_item'");
        }
        else {
          $query->join('field_data_field_oa_related', 'r', "n.nid = r.entity_id AND r.entity_type = 'node'");
          $query->join('field_data_field_oa_media', 'f', "r.field_oa_related_value = f.entity_id AND f.entity_type = 'paragraphs_item'");
        }
        $related_nids = $query
          ->fields('n', array('nid'))
          ->condition('f.field_oa_media_fid', $file->fid)
          ->addTag('node_access')
          ->execute()
          ->fetchCol(0);
        $nids = array_merge($nids, $related_nids);
      }
      if (!empty($nids)) {
        $nids = array_unique($nids);
        // Ensure the user *really* has access to the nodes
        // since addTag('node_access') doesn't call node_access hooks.
        // Since the number of nodes the file is attached to is small, this
        // shouldn't be a performance issue.
        if (user_access('view files', $account)) {
          foreach ($nids as $nid) {
            if (($node = node_load($nid)) && node_access('view', $node, $account)) {
              return FILE_ENTITY_ACCESS_ALLOW;
            }
          }
        }
        // Otherwise, file is attached to nodes we don't have access to
        // so deny access.
        return FILE_ENTITY_ACCESS_DENY;
      }
      else {
        // File is not attached to a node we have specific node grants for
        // so now check if file is attached to ANY other revision.
        $query = db_select('node', 'n');
        $query->join('field_revision_field_oa_media', 'f', "n.nid = f.entity_id AND f.entity_type = 'node'");
        $nids = $query
          ->fields('n', array('nid'))
          ->condition('f.field_oa_media_fid', $file->fid)
          ->execute()
          ->fetchCol(0);
        // add paragraph references
        if (module_exists('paragraphs')) {
          $query = db_select('node', 'n');
          $query->join('field_data_field_oa_related', 'r', "n.nid = r.entity_id AND r.entity_type = 'node'");
          $query->join('field_data_field_oa_media', 'f', "r.field_oa_related_value = f.entity_id AND f.entity_type = 'paragraphs_item'");
          $related_nids = $query
            ->fields('n', array('nid'))
            ->condition('f.field_oa_media_fid', $file->fid)
            ->execute()
            ->fetchCol(0);
          $nids = array_merge($nids, $related_nids);
        }
        if (empty($nids)) {
          // File is not referenced by any node revision, so allow it if they can access content
          // Open Atrium treats unattached files as public since everything is
          // stored in the private file system.
          if (user_access('access content', $account) && user_access('view files', $account) &&
            !user_access('view private files', $account)) {
            // Default Open Atrium permissions are set, so allow access.
            return FILE_ENTITY_ACCESS_ALLOW;
          }
          // Otherwise defer to the rest of Drupal for access.
          else return FILE_ENTITY_ACCESS_IGNORE;
        }
        else {
          // File is referenced by node that we don't have access to, so deny.
          return FILE_ENTITY_ACCESS_DENY;
        }
      }
    }
  }
  return FILE_ENTITY_ACCESS_IGNORE;
}

/**
 * Implements hook_query_media_browser_alter().
 * Add private file access support to media browser
 */
function oa_core_query_media_browser_alter(QueryAlterableInterface $query) {

  if (!user_access('administer nodes') && module_implements('node_grants')) {
    // first, remove the existing condition from media.media.inc that prevents private files
    $where =& $query->conditions();
    foreach ($where as $delta => $condition) {
      if (isset($condition['value']) && isset($condition['operator']) &&
        ($condition['value'] == 'private://%') && ($condition['operator'] == 'NOT LIKE')) {
        unset($where[$delta]);
        break;
      }
    }

    // next, add a proper node_access query restriction
    $or = db_or();
    // Ensure that the query is against the file_managed table.
    $tables = $query->getTables();
    if (empty($tables['file_managed'])) {
      throw new Exception(t('Media browser being queried without the file_managed table.'));
    }
    $alias = $tables['file_managed']['alias'];

    // get down to which node has the attachment
    $query->addJoin('LEFT', 'field_data_field_oa_media', 'media_field', "media_field.field_oa_media_fid = $alias.fid AND media_field.entity_type = 'node'");
    $query->addJoin('LEFT', 'node', 'node', "node.nid = media_field.entity_id");
    $query->addJoin('LEFT', 'node_access', 'node_access', "node.nid = node_access.nid");

    // this is from views_handler_filter_node_access.inc
    // cannot just use the addTag('node access') because base table of query is not node
    $table = 'node_access';
    $grants = db_or();
    foreach (node_access_grants('view') as $realm => $gids) {
      foreach ($gids as $gid) {
        $grants->condition(db_and()
          ->condition($table . '.gid', $gid)
          ->condition($table . '.realm', $realm)
        );
      }
    }
    $or->condition(db_and()
      ->condition($grants)
      ->condition($table . '.grant_view', 1, '>=')
    );

    // finally, put back the "private" condition as an OR state for public files
    $or->condition($alias . '.uri', db_like('private://') . '%', 'NOT LIKE');
    $query->condition($or);
  }
}

/**
 * Implements hook_og_membership_insert().
 */
function oa_core_og_membership_insert($og_membership) {
  drupal_static_reset('oa_core_node_grants');
  if ($og_membership->entity_type == 'user') {
    oa_core_clear_group_cache(NULL, $og_membership->etid);
  }
}

/**
 * Determine true privacy of a space by checking node grants
 * @param $node object or nid
 * @return TRUE if space is private
 */
function oa_core_get_group_privacy($node) {
  $nid = is_numeric($node) ? $node : $node->nid;
  $query = db_select('node_access', 'n')
    ->fields('n', array('grant_view'))
    ->condition('nid', $nid)
    ->condition('realm', 'all');
  $result = $query->execute()->fetchcol(0);
  return empty($result);
}

/**
 * Utility function to return visibility data for a given node
 * $data['public'] TRUE if node is public, FALSE if private
 * $data['title'] either "Public" or "Private"
 * $data['accessors']['group'] list of groups that can access
 * $data['accessors']['space'] list of spaces that can access
 * $data['accessors']['teams'] list of teams that can access
 * $data['accessors']['users'] list of users that can access
 */
function oa_core_visibility_data($node) {
  $static = &drupal_static(__FUNCTION__, array());
  if (!empty($static[$node->nid])) {
    return $static[$node->nid];
  }
  $data = array();
  $data['published'] = !empty($node->status);
  $data['archived'] = FALSE;
  if (module_exists('flag') && $flag = flag_get_flag('trash')) {
    $data['archived'] = $flag->is_flagged($node->nid);
  }
  if ($node->type == OA_SPACE_TYPE || $node->type == OA_GROUP_TYPE) {
    $visibility = field_get_items('node', $node, 'group_access');

    $private = oa_core_get_group_privacy($node);
    $data['public'] = !$private;
    $data['space_public_in_private'] = $private && empty($visibility[0]['value']);
    if (!$data['public'] && ($ids = og_subgroups_parents_load('node', $node->nid)) && !empty($ids['node'])) {
      if ($groups = array_filter(oa_core_get_titles($ids['node'], 'oa_group', 'title', array('link'), TRUE, 0))) {
        $data['accessors']['group'] = array(
          'links' => $groups['links'],
          'label' => t('Groups'),
        );
      }
      if ($spaces = array_filter(oa_core_get_titles($ids['node'], 'oa_space', 'title', array('link'), TRUE, 0))) {
        $data['accessors']['space'] = array(
          'links' => $spaces['links'],
          'label' => t('Spaces'),
        );
      }
    }
  }
  else {

    if ($node->type == OA_SECTION_TYPE) {
      $section_node = $node;
    }
    else {
      $section_reference_field = field_get_items('node', $node, OA_SECTION_FIELD);
      if (isset($section_reference_field[0]['target_id'])) {
        $section_node = node_load($section_reference_field[0]['target_id']);
      }
    }
    if (empty($section_node)) {
      $section_node = $node;
    }

    $space_reference_field = field_get_items('node', $section_node, OA_SPACE_FIELD);
    $space_node = node_load($space_reference_field[0]['target_id']);

    if (empty($space_node)) {
      $data['public'] = TRUE;
    }
    else {
      $space_private = oa_core_get_group_privacy($space_node);
      $visibility = field_get_items('node', $space_node, 'group_access');
      $data['space_public_in_private'] = $space_private && empty($visibility[0]['value']);

      $private = oa_core_get_group_privacy($space_reference_field[0]['target_id']);
      $data['public'] = ((($section_node->type != OA_SECTION_TYPE) || oa_core_section_is_public($section_node))
        && !$private);

      if (!$data['public']) {
        $spaces = _oa_core_build_visibility_links('node', $section_node, OA_GROUP_FIELD, OA_SPACE_TYPE);
        if ($private || !empty($spaces)) {
          $data['accessors']['space'] = array(
            'links' => $spaces + _oa_core_build_visibility_links('node', $section_node, OA_SPACE_FIELD, OA_SPACE_TYPE),
            'label' => t('Spaces'),
          );
        }
        $spaces = _oa_core_build_visibility_links('node', $section_node, OA_GROUP_FIELD, OA_GROUP_TYPE);
        if ($private || !empty($spaces)) {
          $data['accessors']['group'] = array(
            'links' => $spaces + _oa_core_build_visibility_links('node', $section_node, OA_SPACE_FIELD, OA_GROUP_TYPE),
            'label' => t('Groups'),
          );
        }
        $data['accessors']['teams'] = array(
          'links' => _oa_core_build_visibility_links('node', $section_node, OA_TEAM_FIELD),
          'label' => t('Teams'),
        );
        $data['accessors']['users'] = array(
          'links' => _oa_core_build_visibility_links('user', $section_node, OA_USER_FIELD),
          'label' => t('Additional Users'),
        );
      }
    }
  }
  $data['title'] = $data['public'] ? t('Public') : t('Private');
  $static[$node->nid] = $data;
  return $data;
}

/**
 * Helper function, builds links for the various visibility fields on content.
 */
function _oa_core_build_visibility_links($type, $node, $field, $bundle = '') {
  $links = array();
  $nids = array();
  if ($field == OA_SPACE_FIELD) {
    // Get all parent spaces instead of just direct parent
    $spaces = field_get_items('node', $node, $field);
    if (!empty($spaces)) {
      $space = current($spaces);
      $nids = oa_core_get_parents($space['target_id'], $bundle, NODE_PUBLISHED, FALSE, TRUE);
      // Add current space to list
      if ($bundle == OA_SPACE_TYPE) {
        $nids[] = $space['target_id'];
      }
    }
  }
  else {
    $values = field_get_items('node', $node, $field);
    if (!empty($values)) {
      foreach ($values as $value) {
        $nids[] = $value['target_id'];
      }
    }
  }
  if (!empty($nids)) {
    if ($type == 'node') {
      $titles = oa_core_get_titles($nids, $bundle);
      $links = $titles['links'];
    }
    elseif ($type == 'user') {
      $links = array();
      $query = db_select('realname', 'u');
      $query->fields('u', array('uid', 'realname'))
        ->condition('u.uid', $nids, 'IN');
      $users = $query->execute()->fetchAllAssoc('uid');
      foreach ($users as $uid => $user) {
        $links[] = l($user->realname, "user/" . $uid);
      }
    }
  }
  return $links;
}

/**
 * Helper function to determine access to create nodes of certain taxonomy terms
 * @param $tid
 * @param null $gid
 * @param string $vocab_name
 */
function oa_core_get_taxonomy_term_access($tid, $gid = NULL, $vocab_name = 'space_type') {
  global $user;
  $cache = &drupal_static('oa_core_get_taxonomy_term_access', array());

  $gid = isset($gid) ? $gid : oa_core_get_space_context();
  if (isset($cache[$tid][$gid][$vocab_name])) {
    return $cache[$tid][$gid][$vocab_name];
  }

  $result = FALSE;
  // When checking OG Permission, don't let Admin Group override this since all
  // Space admins typically have Admin Group but we want to limit types of subspaces
  // to be created.
  if (!$gid || !module_exists('oa_subspaces') || $vocab_name == 'section_type'
    || user_access('administer group') || user_access('create oa_space content')
    || og_user_access('node', $gid, 'use any oa button space_type', NULL, FALSE, TRUE)) {
    $result = TRUE;
  }
  elseif ($gid && $user->uid) {
    $result = og_user_access('node', $gid, _oa_buttons_perm_name($vocab_name, $tid), NULL, FALSE, TRUE);
  }

  // Allow other modules to override access to terms.
  $context = array(
    'tid' => $tid,
    'gid' => $gid,
    'vocab_name' => $vocab_name,
  );
  drupal_alter('oa_core_get_taxonomy_term_access', $result, $context);

  $cache[$tid][$gid][$vocab_name] = $result;
  return $result;
}
