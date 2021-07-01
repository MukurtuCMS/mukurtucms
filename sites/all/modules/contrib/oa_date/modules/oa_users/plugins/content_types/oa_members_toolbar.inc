<?php

/**
 * @file
 * Provides a panel pane that displays a toolbar button for space members.
 */

$plugin = array(
  'title' => t('Space Member Toolbar'),
  'description' => t('A toolbar button for showing space members.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_users_oa_members_toolbar_form',
  'render callback' => 'oa_users_oa_members_toolbar_render',
  'defaults' => array(
    'show_members' => TRUE,
    'btn_class' => 'btn',
    'icon_class' => 'icon-user',
    'direction' => '',
  ),
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_users_oa_members_toolbar_render($subtype, $conf, $args, $context = NULL) {
  $block = FALSE;
  $space_id = oa_core_get_space_context();
  if (isset($space_id) && ($space = node_load($space_id)) && node_access('view', $space)) {
    $vars = array();
    $vars['title'] = t('Space Members');
    $member_url = 'node/' . $space_id . '/members';
    $vars['member_url'] = drupal_valid_path($member_url) ? url($member_url) : '';
    $vars['space_title'] = $space->title;
    $admins = array();
    $members = array();

    if (!empty($conf['show_members'])) {
      $users = oa_core_get_users_for_space($space->nid);
      uasort($users, 'oa_core_sort_users_by_name');
      foreach ($users as $index => $member) {
        $link = array(
          'title' => $member->name,
          'href' => 'user/' . $member->uid,
        );
        $roles = og_get_user_roles('node', $space->nid, $member->uid);
        if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $space->uid) {
          $admins[$member->uid] = $link;
        }
        else {
          $members[$member->uid] = $link;
        }
      }

      $links = array();
      if (drupal_valid_path($member_url)) {
        $links[] = array(
          'title' => t('Member list'),
          'href' => $member_url,
        );
      }
      $url = 'group/node/' . $space_id . '/admin/people';
      if (drupal_valid_path($url)) {
        $links[] = array(
          'title' => t('Bulk manage'),
          'href' => $url,
        );
      }

      $vars['links'] = theme('links', array(
        'links' => $links,
      ));
      $vars['admins'] = theme('links', array(
        'links' => $admins,
      ));
      $vars['members'] = theme('links', array(
        'links' => $members,
      ));
    }

    $vars['btn_class'] = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn';
    $vars['direction'] = !empty($conf['direction']) ? check_plain($conf['direction']) : '';
    $vars['icon'] = !empty($conf['icon_class']) ? check_plain($conf['icon_class']) : 'icon-user';

    $block = new stdClass();
    $block->title = '';
    $block->content = theme('oa_members_toolbar', $vars);
    }
  return $block;
}

/**
 * Widget config form
 */
function oa_users_oa_members_toolbar_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['show_members'] = array(
    '#title' => t('Show members'),
    '#description' => t('Show members in dropdown menu.'),
    '#type' => 'checkbox',
    '#default_value' => !empty($conf['show_members']) ? $conf['show_members'] : TRUE,
  );

  $form['direction'] = array(
    '#type' => 'select',
    '#title' => t('Direction'),
    '#options' => array(
      '' => t('Drop down'),
      'dropup' => t('Drop up'),
    ),
    '#default_value' => (isset($conf['direction'])) ? $conf['direction'] : '',
    '#description' => t('Controls whether menu expands downwards or upwards.  Default is drop down.'),
  );
  $form['icon_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class'),
    '#description' => t('CSS class name for icon.  Default is icon-cog.'),
    '#default_value' => !empty($conf['icon_class']) ? $conf['icon_class'] : 'icon-cog',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : '',
  );

  return $form;
}


/**
 * Saves changes to the widget.
 */
function oa_users_oa_members_toolbar_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

