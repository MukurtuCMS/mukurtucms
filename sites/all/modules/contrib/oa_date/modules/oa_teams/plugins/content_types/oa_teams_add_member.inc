<?php

/**
 * @file
 * Defines the Add Team Member panels pane.
 */

$plugin = array(
  'title' => t('Add Team Member'),
  'description' => t('Allows members to be added to the team.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'render callback' => 'oa_teams_add_team_member_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_teams_add_team_member_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }

  global $user;
  $team = $context->data;
  $group = og_get_entity_groups($entity_type = 'node', $team);
  if (empty($group['node'])) {
    return;
  }
  $space = current(entity_load('node', $group['node']));

  $is_admin = ($user->uid == 1) ? TRUE : FALSE;
  $members = oa_teams_get_team_members($space->nid);
  $roles = og_get_user_roles('node', $space->nid, $user->uid);
  if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $user->uid == $space->uid) {
    $is_admin = TRUE;
  }

  if ($is_admin) {
    $output = drupal_get_form('oa_teams_add_team_member_form', $team);

    $block = new stdClass();
    $block->title = t('Add Existing User');
    $block->content = $output;
    return $block;
  }
  return;
}

/**
 * Render the form for Add Team Member
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $team
 *    The team being viewed
 * @return
 *    The form
 */
function oa_teams_add_team_member_form($form, &$form_state, $team) {
  $form['#team'] = $team;

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('User name'),
    '#autocomplete_path' => 'entityreference/autocomplete/single/field_oa_team_users/node/oa_team/' . $team->nid,
    '#field_name' => 'field_oa_team_users',
    '#entity_type' => 'node',
    '#bundle' => 'oa_team',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add to team'),
  );

  return $form;
}

/**
 * Validate handler; Add users to team.
 */
function oa_teams_add_team_member_form_validate($form, &$form_state) {
  _entityreference_autocomplete_validate($form['name'], $form_state, $form);
  $account = user_load($form_state['values']['name']);
  $team = $form['#team'];
  if (!$account) {
    form_set_error('name', t('You have entered an invalid user name.'));
    return;
  }
  elseif ($users = field_get_items('node', $team, 'field_oa_team_users')) {
    $user_list = array();
    foreach ($users as $user) {
      if ($user['target_id'] == $account->uid) {
        form_set_error('name', t('User %name is already a member of that group.', array('%name' => format_username($account))));
        break;
      }
    }
  }
}

/**
 * Submit handler for adding member
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function oa_teams_add_team_member_form_submit($form, &$form_state) {
  $team = $form['#team'];
  $account = user_load($form_state['values']['name']);
  oa_teams_add_member($team, $account->uid);
  drupal_set_message(t('%user has been added to the team %title.', array('%user' => format_username($account), '%title' => $team->title)));
}


