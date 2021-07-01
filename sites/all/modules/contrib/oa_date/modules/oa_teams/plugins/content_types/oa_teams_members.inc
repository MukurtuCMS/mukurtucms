<?php

/**
 * @file
 * Defines the team members panels pane.
 */

$plugin = array(
  'title' => t('Team Members'),
  'description' => t("Show the members of a Team"),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'render callback' => 'oa_team_members_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Main render function for oa_team_members.
 */
function oa_team_members_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  if (!isset($context->data)) {
    return;
  }

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

  $block = new stdClass();
  $block->title = 'Team Members';

  $members = oa_teams_get_team_members($team->nid);
  $members = user_load_multiple(array_keys($members));
  uasort($members, 'oa_core_sort_users_by_name');

  $vars = array();

  foreach ($members as $id => $entity) {
    $vars['members'][$id] = oa_teams_entity_build_display($entity, $id);
    $vars['links']['remove_options'][$id] = array(
      'query' => drupal_get_destination() + array('token' => drupal_get_token('remove-team-membmer-' . $id)),
    );
  }
  $vars['links']['dashboard'] = 'user/';
  if ($is_admin) {
    $vars['links']['remove'] = 'group/node/' . $space->nid . '/remove-team/' . $team->nid . '/';
  }
  else {
    $vars['links']['remove'] = '';
  }
  $block->content = theme('oa_teams_members', $vars);
  return $block;
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_teams_entity_build_display($entity, $id) {
  $type = isset($entity->nid) ? 'node' : 'user';
  $title = ($type == 'user') ? oa_core_realname($entity) : $entity->title;
  $display['title'] = l($title, $type . '/' . $id);
  $display['uid'] = $id;

  if ($type == 'user') {
    $display['picture'] = oa_users_picture($entity);
  }
  else {
    $display['picture'] = '';
  }

  return $display;
}
