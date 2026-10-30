<?php

/**
 * @file
 * Defines the Add Member panels pane.
 */

$plugin = array(
  'title' => t('Add Space Member'),
  'description' => t('Allows members to be added to the space.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'render callback' => 'oa_core_add_member_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_core_add_member_render($subtype, $conf, $args, $context = NULL) {
  if (empty($context->data->nid)
    || !(($nid = oa_core_get_group_from_node($context->data))
      && ($group = node_load(oa_core_get_group_from_node($nid))))
    || !node_access('view', $group)
    || !og_user_access('node', $group->nid, 'add user')) {
    return;
  }

  $block = new stdClass();
  $block->title = t('Add Existing User');
  $block->content = drupal_get_form('oa_core_add_member_form', $group);
  return $block;
}

/**
 * Render the form for Add Member
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $space
 *    The space being viewed
 * @return
 *    The form
 */
function oa_core_add_member_form($form, &$form_state, $space) {
  // Since this form functions via AJAX we need to tell the form handlers to include it when processing the form
  ctools_form_include_file($form_state, drupal_get_path('module', 'oa_core') . '/plugins/content_types/oa_core_add_member.inc');

  $form['#space'] = $space;
  $name = node_type_get_name($space->type);

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('User name'),
    '#autocomplete_path' => 'user/autocomplete',
    '#prefix' => '<div id="og-core-member-replace-me">',
    '#suffix' => '</div>',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add to @name', array('@name' => drupal_strtolower(node_type_get_name($space->type)))),
  );
  if (variable_get('oa_use_ajax', FALSE)) {
    $form['submit']['#ajax'] = array(
      'callback' => 'oa_core_add_member_ajax',
      'wrapper' => 'og-core-member-replace-me',
    );
  }

  return $form;
}

function oa_core_add_member_ajax($form, $form_state) {
  if (!form_get_errors()) {
    $form['name']['#value'] = '';
  }
  return $form['name'];
}

/**
 * Validate handler; Add users to group.
 */
function oa_core_add_member_form_validate($form, &$form_state) {
  $account = user_load_by_name($form_state['values']['name']);
  $space = $form['#space'];
  if (!$account || empty($account->uid)) {
    form_set_error('name', t('You have entered an invalid user name.'));
  }
  elseif (og_get_membership('node', $space->nid, 'user', $account->uid)) {
    form_set_error('name', t('User %name is already a member of that @type.', array('@type' => drupal_strtolower(node_type_get_name($space->type)), '%name' => format_username($account))));
  }
}

/**
 * Submit handler for adding member
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function oa_core_add_member_form_submit($form, &$form_state) {
  $space = $form['#space'];
  $account = user_load_by_name($form_state['values']['name']);
  oa_core_add_member_api('node', $space->nid, $account->uid);
}


