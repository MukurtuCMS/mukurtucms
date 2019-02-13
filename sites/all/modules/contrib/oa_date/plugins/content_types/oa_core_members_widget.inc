<?php

/**
 * @file
 * Defines the space members panels pane.
 */

$plugin = array(
  'title' => t('Space Members'),
  'description' => t("Show the owners, teams, and members of a Space"),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'edit form' => 'oa_core_members_widget_edit_form',
  'render callback' => 'oa_core_members_widget_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'hide_owner' => FALSE,
    'hide_teams' => FALSE,
    'hide_members' => FALSE,
    'hide_inherited' => FALSE,
    'show_number' => 10,
    'show_as_tabs' => FALSE,
  ),
);


/**
 * Main render function for oa_core_members_widget.
 */
function oa_core_members_widget_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  if (!isset($context->data->nid)
    || !(($space_nid = oa_core_get_group_from_node($context->data))
      && ($space = node_load($space_nid)))
    || !node_access('view', $space)) {
    return;
  }

  $is_admin = og_user_access('node', $space->nid, 'manage members');

  $block = new stdClass();
  $block->title = t('Members');

  $local_teams = array();
  $inherited_teams = array();
  if (empty($conf['hide_teams']) && module_exists('oa_teams')) {
    $local_teams_nids = array_keys(oa_teams_get_teams_for_space($space->nid, FALSE));
    $inherited_teams_nids = array_diff(array_keys(oa_teams_get_teams_for_space($space->nid, TRUE)), $local_teams_nids);
    $local_teams = node_load_multiple($local_teams_nids);
    $inherited_teams = node_load_multiple($inherited_teams_nids);
  }

  $pending = array();
  if ($is_admin && empty($conf['hide_members']) && empty($conf['hide_owner'])) {
    $pending = oa_core_get_users_for_space($space->nid, OG_STATE_PENDING);
  }

  $blocked = array();
  if ($is_admin && empty($conf['hide_members']) && empty($conf['hide_owner'])) {
    $blocked = oa_core_get_users_for_space($space->nid, OG_STATE_BLOCKED);
  }

  $members = empty($conf['hide_owner']) || empty($conf['hide_members'])
    ? oa_core_get_users_for_space($space->nid, OG_STATE_ACTIVE, TRUE)
    : array();
  uasort($members, 'oa_core_sort_users_by_name');
  $owners = array();
  if (empty($conf['hide_owner'])) {
    foreach ($members as $member) {
      $roles = og_get_user_roles('node', $space->nid, $member->uid);
      if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $space->uid) {
        $owners[$member->uid] = $member;
      }
    }
  }
  if (!empty($conf['hide_members'])) {
    $members = array();
  }

  $parents = array();
  $parent_spaces = array();
  $parent_groups = array();
  $parent_no_inherit = array();
  if (module_exists('oa_subspaces') && empty($conf['hide_inherited']) && $is_admin && ($parent_field = field_get_items('node', $space, OA_PARENT_SPACE))) {
    foreach ($parent_field as $parent) {
      if (!empty($parent['target_id'])) {
        $parents[$parent['target_id']] = $parent['target_id'];
      }
    }
    $parents = node_load_multiple(array_keys($parents));
    foreach ($parents as $node) {
      $wrapper = entity_metadata_wrapper('node', $node);
      // If inheritance disabled on parent, separate this node from the rest.
      if (!empty($wrapper->{OG_USER_INHERITANCE_FIELD}) && !$wrapper->{OG_USER_INHERITANCE_FIELD}->value()) {
        $parent_no_inherit[] = $node;
      }
      elseif ($node->type == OA_SPACE_TYPE) {
        $parent_spaces[] = $node;
      }
      else {
        $parent_groups[] = $node;
      }
    }
  }

  $vars = array();

  $show_number = isset($conf['show_number']) ? $conf['show_number'] : 10;
  if ($show_number > 0) {
    $vars['see_all_link'] = l(t('See all members'), 'node/' . $space->nid . '/members');
    $members = array_slice($members, 0, $show_number-1);
  }
  else {
    $vars['see_all_link'] = '';
  }
  $vars['show_as_tabs'] = isset($conf['show_as_tabs']) ? $conf['show_as_tabs'] : FALSE;
  // set the order the tabs/categories show on page
  $vars['categories'] = $vars['show_as_tabs']
    ? array('members', 'pending', 'blocked', 'owners', 'parents', 'teams')
    : array('owners', 'teams', 'pending', 'members', 'blocked', 'parents');

  $space_type = node_type_get_name($space->type);

  $tabs = array();
  if (!empty($members)) {
    $tabs['members'] = array(
      'caption' => t('Members'),
      'title' => '',
      'items' => array($members),
      'links' => array('dashboard', 'remove', 'remove-child', 'add-admin', 'block'),
    );
  }
  if (!empty($pending)) {
    $tabs['pending'] = array(
      'caption' => t('Pending') . ' <span class="oa_pending_count">' . count($pending) . '</span>',
      'title' => t('Pending members'),
      'items' => array($pending),
      'links' => array('dashboard', 'add', 'remove'),
    );
  }
  if (!empty($blocked)) {
    $tabs['blocked'] = array(
      'caption' => t('Blocked'),
      'title' => t('Blocked users'),
      'items' => array($blocked),
      'links' => array('dashboard', 'add', 'remove'),
    );
  }
  if (!empty($owners)) {
    $tabs['owners'] = array(
      'caption' => t('Administrators'),
      'title' => t('@type administrators', array('@type' => $space_type)),
      'items' => array($owners),
      'links' => array('dashboard', 'remove-admin'),
    );
  }
  if (module_exists('oa_subspaces') && (!isset($conf['hide_inherited']) || !$conf['hide_inherited'])) {
    $tabs['parents'] = array(
      'caption' => t('Inherited'),
      'title' => t('Inheriting members from:'),
      'items' => array(
        t('Spaces') => $parent_spaces,
        t('Groups') => $parent_groups,
        t('Inheritance disabled') => $parent_no_inherit,
      ),
      'links' => array(),
      'subpage' => array(
        t('Spaces') => '/members',
      ),
    );
    if (user_access('create ' . OA_GROUP_TYPE . ' content', $user)) {
      $tabs['parents']['global_links'][] = array(
        'title' => t('Create New Group'),
        'url'   => url('node/add/' . str_replace('_', '-', OA_GROUP_TYPE)),
      );
    }
    if (og_user_access('node', $space->nid, 'administer group')) {
      $tabs['parents']['form'] = drupal_get_form('oa_core_members_widget_add_group_form', $space);
    }
  }

  if (module_exists('oa_teams') && ($space->type == OA_SPACE_TYPE)) {
    $tabs['teams'] = array(
      'caption' => t('Teams'),
      'title' => t('Teams'),
      'items' => array($local_teams),
      'links' => array(),
    );
    if (count($inherited_teams) > 0) {
      $tabs['teams']['items'] = array(
        t('Local teams') => $tabs['teams']['items'][0],
        t('Inherited teams') => $inherited_teams,
      );
    }
    if (og_user_access('node', $space->nid, 'create ' . OA_TEAM_TYPE . ' content')) {
      $tabs['teams']['global_links'][] = array(
        'title' => t('Create New Team'),
        'url'   => url('node/add/' . str_replace('_', '-', OA_TEAM_TYPE)),
      );
    }
  }

  $ajax = (variable_get('oa_use_ajax', FALSE)) ? '/nojs' : '';
  foreach ($tabs as $category => $tab) {
    $tabs[$category]['items'] = array();
    if (!empty($tab['items'])) {
      foreach ($tab['items'] as $key => $items) {
        $subpage = !empty($tabs[$category]['subpage'][$key]) ? $tabs[$category]['subpage'][$key] : '';
        foreach ($items as $id => $entity) {
          $tabs[$category]['items'][$key][$id] = oa_core_entity_build_display($entity, $id, $space, $subpage);
          if ($entity->uid == $space->uid) {
            // don't show links for main space owner
            $tabs[$category]['items'][$key][$id]['uid'] = 0;
          }
          if (!$ajax) {
            unset($tabs[$category]['items'][$key][$id]['options']['attributes']);
          }
        }
      }
    }
    elseif (empty($tab['global_links'])) {
      unset($tabs[$category]);
    }
  }
  // don't show extra title if only one type of user being shown in a block
  if (count($tabs) == 1) {
    unset($tabs[key($tabs)]['title']);
  }
  $links = array(
    'dashboard' => array(
      'title' => t('Dashboard'),
      'url' => 'user/%uid',
      'noajax' => TRUE,
    ),
    'remove' => array(
      'title' => t('Remove from @label', array('@label' => $space_type)),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/remove/single/%uid' . $ajax : '',
    ),
    'add' => array(
      'title' => t('Approve/Add to @label', array('@label' => $space_type)),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/add-member/%uid/' . OA_SPACE_FIELD . $ajax : '',
    ),
    'block' => array(
      'title' => t('Block user'),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/block/%uid' . $ajax : '',
    ),
    'add-admin' => array(
      'title' => t('Add as Admin'),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/add-admin/%uid' . $ajax : '',
    ),
    'remove-admin' => array(
      'title' => t('Remove as Admin'),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/remove-admin/%uid' . $ajax : '',
    ),
    'remove-child' => array(
      'title' => t('Remove from @label and any children spaces', array('@label' => $space_type)),
      'url' => (og_user_access('node', $space->nid, 'administer group') && module_exists('oa_subspaces') && og_subgroups_children_load('node', $space->nid, FALSE))
        ? 'group/node/' . $space->nid . '/remove/all/%uid' . $ajax
        : '',
    ),
  );

  $vars['tabs'] = $tabs;
  $vars['links'] = $links;
  $vars['active'] = isset($args[1]) ? $args[1] : 'members';

  $block->content = theme('oa_core_members_widget', $vars);
  return $block;
}

/**
 * Render the form for Add Group
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $space
 *    The space the group is added to
 * @return
 *    The form
 */
function oa_core_members_widget_add_group_form($form, &$form_state, $space) {
  $form['#space'] = $space;

  $groups = oa_core_get_all_groups();
  $options = array();
  foreach ($groups as $group) {
    $options[$group->nid] = $group->title;
  }
  $form['group_name'] = array(
    '#type' => 'select',
    '#title' => '',
    '#options' => $options,
    '#default_value' => '',
    '#multiple' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add Group'),
  );
  $form['group_help'] = array(
    '#markup' => '<p class="description">' . t('Edit space to remove inherited groups/spaces.') . '</p>',
  );

  return $form;
}

/**
 * Submit handler for adding group
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function oa_core_members_widget_add_group_form_submit($form, &$form_state) {
  $space = $form['#space'];
  $groups = $form_state['values']['group_name'];
  foreach ($groups as $gid) {
    $group = node_load($gid);
    og_group('node', $gid, array(
      'entity_type' => 'node',
      'entity' => $space,
      'field_name' => OA_PARENT_SPACE));
    drupal_set_message(t('Group @group added to space.', array('@group' => $group->title)));
  }
  $form_state['redirect'] = 'node/' . $space->nid . '/members/parents';
}


/**
 * Edit form for the widget.
 */
function oa_core_members_widget_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['show_as_tabs'] = array(
    '#title' => t('Show as Tabs'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_as_tabs'],
  );
  $form['hide_owner'] = array(
    '#title' => t('Hide administrators'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_owner'],
  );
  $form['hide_teams'] = array(
    '#title' => t('Hide teams'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_teams'],
  );
  $form['hide_members'] = array(
    '#title' => t('Hide members'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_members'],
  );
  $form['hide_inherited'] = array(
    '#title' => t('Hide inherited'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_inherited'],
  );
  $form['show_number'] = array(
    '#title' => t('Number of members to show'),
    '#type' => 'textfield',
    '#default_value' => $conf['show_number'],
    '#description' => 'Enter zero to show all members.'
  );

  return $form;
}

function oa_core_members_widget_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

