<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_user_form.png',
  'title' => t('User form password field'),
  'description' => t('The user password form.'),
  'required context' => new ctools_context_required(t('Form'), 'form'),
  'category' => t('Form'),
);

/**
 * Ctools plugin content type render for the password form field.
 */
function ctools_user_form_password_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('user-form');

  $block->delta = 'title-options';

  if (isset($context->form)) {
    // The current password is required to change the password.
    if (!empty($context->form['account']['current_pass'])) {
      $block->content['current_pass'] = $context->form['account']['current_pass'];
      unset($context->form['account']['current_pass']);
    }
    if (!empty($context->form['account']['pass'])) {
      $block->content['pass'] = $context->form['account']['pass'];
      unset($context->form['account']['pass']);
    }
  }
  else {
    $block->content = t('User password form.');
  }
  return $block;
}

/**
 * Ctools plugin admin title function for the password form field.
 */
function ctools_user_form_password_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user form password field', array('@s' => $context->identifier));
}

/**
 * Ctools plugin configuration edit form for the password form field.
 *
 * Provide a blank form so we have a place to have context setting.
 */
function ctools_user_form_password_content_type_edit_form($form, &$form_state) {
  return $form;
}
