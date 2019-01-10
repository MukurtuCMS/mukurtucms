<?php
/**
 * @file
 * Administration pages and forms for the Open Atrium Access module.
 */

/**
 * Form constructor for the Group permissions form.
 *
 * Internally it uses _oa_access_permissions_form() to build the
 * actual form and handle submit.
 *
 * @see _oa_access_permissions_form()
 * @see _oa_access_permissions_form_submit()
 */
function oa_access_group_permissions_form($form, &$form_state) {
  $message = '<p>' . t('Please select which Groups have which permissions.') . '</p>';

  $form['message'] = array(
    '#markup' => $message
  );

  $groups = oa_core_get_all_groups();
  // Add a magic group to represent the 'All' option.
  $groups[] = (object)array(
    'nid' => 0,
    'title' => t('All site users'),
  );
  return _oa_access_permissions_form($form, $form_state, OA_ACCESS_GROUP_PERMISSION, t('Groups'), $groups, 0);
}

/**
 * Form constructor for the Team permissions form.
 *
 * Internally it uses _oa_access_permissions_form() to build the
 * actual form and handle submit.
 *
 * @see _oa_access_permissions_form()
 * @see _oa_access_permissions_form_submit()
 */
function oa_access_team_permissions_form($form, &$form_state, $group_type, $gid) {
  $message = '<p>' . t('Please select which Teams have which permissions.') . '</p>';
  if (user_permission('administer oa_access permissions')) {
    $message .= '<p>' . t('You can also <a href="!url">use Groups</a> to control who has which permission.', array('!url' => url('groups/oa_access'))) . '</p>';
  }

  $form['message'] = array(
    '#markup' => $message
  );

  // Add the node to the form so that alter functions can access it.
  $form['#gid'] = $gid;

  $groups = oa_teams_get_teams_for_space($gid);
  // Add a magic team to represent the 'All' option.
  $groups[] = (object)array(
    'nid' => $gid,
    'title' => t('All Space members'),
  );
  return _oa_access_permissions_form($form, $form_state, OA_ACCESS_TEAM_PERMISSION, t('Teams'), $groups, $gid);
}

/**
 * Internal form constructor for both the Group and Team permissions forms.
 *
 * @param int $type
 *   A permission type flag for which permissions should be included.
 * @param string $groups_label
 *   The label to use for the groups field.
 * @param array $groups
 *   An array of nodes representing each of the available groups.
 * @param int $all_nid
 *   The NID used to represent the magic 'All' option.
 *
 * @see _oa_access_permissions_form_submit()
 * @see oa_access_group_permissions_form()
 * @see oa_access_team_permissions_form()
 *
 * @ingroup forms
 */
function _oa_access_permissions_form($form, &$form_state, $type, $group_label, $groups, $all_nid = 0) {
  $permissions = array();
  foreach (oa_access_get_permissions() as $name => $perm) {
    if ($perm['type'] & $type) {
      $permissions[$perm['module']][$name] = $perm;
    }
  }

  $group_options = array();
  foreach ($groups as $group) {
    $group_options[$group->nid] = $group->title;
  }

  // Load the current values from the database and put into the format needed
  // by #default_value for a multiple select.
  $values = array();
  $group_permissions = oa_access_get_group_permissions(array_keys($group_options));
  foreach ($group_permissions as $gid => $modules) {
    foreach ($modules as $module => $perms) {
      foreach ($perms as $perm) {
        $values[$perm][$gid] = $gid;
      }
    }
  }

  $form['groups'] = array(
    '#type' => 'value',
    '#value' => $groups,
  );

  // Get a list of all the modules implementing a hook_permission() and sort by
  // display name.
  $module_info = system_get_info('module');
  $modules = array();
  foreach (array_keys($permissions) as $module) {
    $modules[$module] = $module_info[$module]['name'];
  }
  asort($modules);

  // Use the same 'Compact mode' setting as the normal user permissions page.
  $hide_descriptions = system_admin_compact_mode();

  // Put each of the permissions on the form with a list of Groups that can
  // do them. This will be themed into a table.
  $form['permissions'] = array(
    '#tree' => TRUE,
    '#theme' => 'oa_access_permissions_form',
  );
  foreach ($modules as $module => $module_name) {
    $form['permissions'][$module] = array(
      '#type' => 'item',
      '#markup' => $module_name,
      '#id' => $module,
    );
    foreach ($permissions[$module] as $name => $perm) {
      $form['permissions'][$module][$name]['name'] = array(
        '#type' => 'item',
        '#title' => t('Permission'),
        '#markup' => $perm['title'],
        '#description' => !empty($perm['description']) && !$hide_descriptions ? $perm['description'] : '',
      );

      $form['permissions'][$module][$name]['groups'] = array(
        '#type' => 'select',
        '#title' => $group_label,
        '#multiple' => TRUE,
        '#options' => $group_options,
        '#default_value' => isset($values[$name]) ? $values[$name] : array(),
        '#attributes' => array(
          'class' => array('chosen-widget'),
        ),
      );

      // If the 'All' option is not allowed, we remove it from this permission.
      if (!($perm['type'] & OA_ACCESS_ALLOW_OPTION_ALL)) {
        unset($form['permissions'][$module][$name]['groups']['#options'][$all_nid]);
      }
    }
  }

  // Setup submit button and handler.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save permissions'),
  );
  $form['#submit'][] = '_oa_access_permissions_form_submit';

  // Setup Javascript to deal with the 'All' option.
  $form['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(
      'oa_access' => array(
        'all_nid' => $all_nid,
      ),
    ),
  );
  $form['#attached']['js'][] = array(
    'type' => 'file',
    'data' => drupal_get_path('module', 'oa_access') . '/oa_access.js',
  );

  return $form;
}

/**
 * Form submission handler for both the Group and Team permissions forms.
 *
 * @see _oa_access_permissions_form()
 * @see oa_access_group_permissions_form()
 * @see oa_access_team_permissions_form()
 */
function _oa_access_permissions_form_submit($form, &$form_state) {
  // Re-organize the form values into the format expected by
  // oa_access_set_group_permissions().
  $group_permissions = array();
  foreach ($form_state['values']['groups'] as $group) {
    $group_permissions[$group->nid] = array();
  }
  foreach ($form_state['values']['permissions'] as $module => $permissions) {
    foreach ($permissions as $name => $perm) {
      foreach ($perm['groups'] as $nid) {
        $group_permissions[$nid][$module][] = $name;
      }
    }
  }

  // Actually save to the database.
  oa_access_set_group_permissions($group_permissions);

  drupal_set_message(t('The changes have been saved.'));
}
