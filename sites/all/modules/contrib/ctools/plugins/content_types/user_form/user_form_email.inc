<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_user_form.png',
  'title' => t('User form email field'),
  'description' => t('The user email form.'),
  'required context' => new ctools_context_required(t('Form'), 'form'),
  'category' => t('Form'),
);

/**
 * Ctools plugin content type render for the email form field.
 */
function ctools_user_form_email_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('user-form');

  $block->delta = 'title-options';

  if (isset($context->form)) {
    // The current password is required to change the email.
    if (!empty($context->form['account']['current_pass'])) {
      $block->content['current_pass'] = $context->form['account']['current_pass'];
      unset($context->form['account']['current_pass']);
    }
    if (!empty($context->form['account']['mail'])) {
      $block->content['mail'] = $context->form['account']['mail'];
      unset($context->form['account']['mail']);
    }
  }
  else {
    $block->content = t('User email form.');
  }
  return $block;
}

/**
 * Ctools plugin admin title function for the email form field.
 */
function ctools_user_form_email_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user form email field', array('@s' => $context->identifier));
}

/**
 * Ctools plugin configuration edit form for the email form field.
 *
 * Provide a blank form so we have a place to have context setting.
 */
function ctools_user_form_email_content_type_edit_form($form, &$form_state) {
  return $form;
}
