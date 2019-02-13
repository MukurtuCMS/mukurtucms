<?php

/**
 * @file
 * Provides a panels pane that shows user information.
 */

$plugin = array(
  'title' => t('User Profile'),
  'description' => t('A small panel containing a user\'s name, picture, and links to user functionality.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_widgets_user_profile_edit_form',
  'render callback' => 'oa_widgets_user_profile_render',
);


/**
 * Render callback for the panel.
 */
function oa_widgets_user_profile_render($subtype, $conf, $args, $context = NULL) {
  $block = new stdClass();
  $block->title = '';

  $vars = array();
  template_preprocess_oa_user_badge($vars);

  global $user;
  if ($user->uid) {
    $user = user_load($user->uid);
    $vars = oa_users_build_user_details($user, 'oa_medium_thumbnail');
    $block->content = theme('oa_widgets_user_profile', $vars);
  }
  return $block;
}


/**
 * Edit form for the panel.
 */
function oa_widgets_user_profile_edit_form($form, &$form_state) {
  return $form;
}
