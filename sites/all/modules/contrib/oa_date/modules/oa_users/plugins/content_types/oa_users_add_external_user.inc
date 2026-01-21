<?php

/**
 * @file
 * Defines a widget used to add external users to the site and then to the space and team if necessary.
 */

$plugin = array(
  'title' => t('Add External User'),
  'description' => t('Allows new users to be added to the site and then as members to the space.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'render callback' => 'oa_users_add_external_user_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Render callback for the add external user plugin.
 */
function oa_users_add_external_user_render($subtype, $conf, $args, $context = NULL) {

  if (empty($context->data->nid)
    || !(($nid = oa_core_get_group_from_node($context->data))
      && ($group = node_load(oa_core_get_group_from_node($nid))))
    || !node_access('view', $group)
    || !og_user_access('node', $group->nid, 'add external user')) {
    return;
  }

  ctools_include('modal');
  ctools_modal_add_js();

  // A simple form with a button.
  $form = drupal_get_form('oa_users_add_external_user_button', $context->data);
  $output = drupal_render($form);

  $block = new stdClass();
  $block->title = t('Add External User');
  $block->content = $output;

  return $block;
}

/**
 * This is what the widget will render. It's just a button that triggers a modal that contains the modified user
 * registration form to add a new user.
 *
 * @param $form
 * @param $form_state
 * @param $group
 * @return mixed
 */
function oa_users_add_external_user_button($form, &$form_state, $group) {

  $form['url'] = array(
    '#type' => 'hidden',
    // The name of the class is the #id of $form['ajax_button'] with a "-url" suffix.
    '#attributes' => array('class' => array('oa-users-add-external-url')),
    '#value' => url('oa_users/add/nojs/' . $group->nid),
  );

  $form['ajax_button'] = array(
    '#type' => 'button',
    '#value' => t('Add User'),
    '#attributes' => array('class' => array('ctools-use-modal btn-primary')),
    '#id' => 'oa-users-add-external',
  );

  return $form;
}

/**
 * This is the page callback for "oa_users/add/%ctools_js/%node".
 *
 * @param bool|FALSE $js
 * @param $group
 * @return array|mixed
 */
function oa_users_register_external_user_modal($js = FALSE, $group = NULL) {
  $group = !empty($group) ? $group : node_load(oa_core_get_space_context());

  if (empty($group) && !node_access('view', $group) || !og_user_access('node', $group->nid, 'add external user')) {
    return;
  }

  // This is kind of hacky but there really isn't a good way to get the underlying page url.
  if ($group->type == OA_SPACE_TYPE) {
    // If it's an oa_space then we know we came from the members page.
    $url = 'node/' . $group->nid . '/members';
  }
  else if ($group->type == OA_TEAM_TYPE || $group->type == OA_GROUP_TYPE) {
    // If it's an oa_team then we came from the team node.
    $url = 'node/' . $group->nid;
  }

  if ($js) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Add external user to ' . $group->title),
    );
    $form_state['#group'] = $group;
    // Build the form for the modal.
    $output = ctools_modal_form_wrapper('oa_users_external_user_form', $form_state);
    // If we don't find the form or it has already been submitted.
    if (empty($output) || $form_state['executed']) {
      $output = array();
      // Give the user something so they know the modal will close and the page will reload.
      // @todo: This would be better if we just added a loader.
      $output[] = ctools_modal_command_display('', '<h2>Processing...</h2>');
      $output[] = ctools_modal_command_loading();
      $output[] = ctools_ajax_command_redirect($url);
    }
    // Render the output and exit.
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('oa_users_external_user_form');
  }
}

function oa_users_external_user_form($form, &$form_state) {
  $form['#user'] = drupal_anonymous_user();
  $form['#user_category'] = 'register';

  $form['#group'] = $form_state['#group'];
  $form['#validate'][] = 'user_account_form_validate';
  $form['#submit'][] = 'oa_users_pre_user_register_submit';
  $form['#submit'][] = 'user_register_submit';
  $form['#submit'][] = 'oa_users_external_user_form_submit';

  // Account information.
  $form['account'] = array(
    '#type'   => 'container',
    '#weight' => -10,
  );

  $form['account']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#description' => t('Spaces are allowed; punctuation is not allowed except for periods, hyphens, apostrophes, and underscores.'),
    '#required' => TRUE,
    '#attributes' => array('class' => array('username')),
    '#default_value' => '',
    '#weight' => -10,
  );

  $form['account']['mail'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address'),
    '#maxlength' => EMAIL_MAX_LENGTH,
    '#description' => t('A valid e-mail address. All e-mails from the system will be sent to this address. The e-mail address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by e-mail.'),
    '#required' => TRUE,
    '#default_value' => '',
  );

  // The personal welcome message will be added to the top of the mail.
  //        * updated by ajax call back (we shouldn't show tokens to users)
  //        * or in a second step of the form
  //        Both approaches have ramifications for the use of the form in ajaxy popups.
  $form['welcome_message_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Personal welcome message'),
    '#default_value' => '',
    '#description' => t('This welcome message will appear at the top of the e-mail notification sent to the new user.'),
    // TODO: Implement this field in the future and then set access back to TRUE
    '#access' => FALSE,
  );

  $form['account']['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#default_value' => 1,
    '#options' => array(t('Blocked'), t('Active')),
    '#access' => FALSE,
  );

  $form['account']['notify'] = array(
    '#type' => 'checkbox',
    '#title' => t('Notify user of new account'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
    '#weight' => 20,
  );
  return $form;
}

function oa_users_pre_user_register_submit($form, &$form_state) {
  $form_state['values']['field_user_display_name'][LANGUAGE_NONE][0]['value'] = $form_state['values']['name'];
  $form_state['values']['administer_users'] = TRUE;
  $form_state['values']['pass'] = user_password();
}

/**
 * Submit handler for adding member.
 *
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function oa_users_external_user_form_submit($form, &$form_state) {

  if (($account = $form['#user']) && ($group = $form['#group'])) {

    // This is an oa_space or oa_group type.
    if ($group->type == OA_SPACE_TYPE || $group->type == OA_GROUP_TYPE) {
      // Add the member to the space.
      oa_core_add_member_api('node', $group->nid, $account->uid);
    }
    // This is an oa_team type.
    else if ($group->type == OA_TEAM_TYPE) {
      // Load the space the team belongs to.
      $space_nid = oa_core_get_group_from_node($group);
      // Add the member to the space.
      oa_core_add_member_api('node', $space_nid, $account->uid);
      // Add the member to the team.
      oa_teams_add_member($group, $account->uid);
      // A message gets set for the space. We need to add one for the team as well. Use the 'Display name' so we match
      // the message added when adding a user to a space.
      $wrapper = entity_metadata_wrapper('user', $account);
      // Get the 'Display Name' instead of using the actual name.
      $name = $wrapper->field_user_display_name->value();
      drupal_set_message(t('@name has been added to the team @team.', array('@name' => $name, '@team' => $group->title)));
    }
  }
  else {
    // Something went wrong with creating the user.
    drupal_set_message(t('There was an error creating the user. Please contact your group administrator.'), 'error');
  }
}


