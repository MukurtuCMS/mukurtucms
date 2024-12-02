<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_user_form.png',
  'title' => t('User form status field'),
  'description' => t('The user status form.'),
  'required context' => new ctools_context_required(t('Form'), 'form'),
  'category' => t('Form'),
);

/**
 * Ctools plugin content type render for the status form field.
 */
function ctools_user_form_status_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('user-form');

  $block->delta = 'title-options';

  if (isset($context->form)) {
    if (!empty($context->form['account']['status'])) {
      $block->content['status'] = $context->form['account']['status'];
      unset($context->form['account']['status']);
    }
  }
  else {
    $block->content = t('User status form.');
  }
  return $block;
}

/**
 * Ctools plugin admin title function for the status form field.
 */
function ctools_user_form_status_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user form status field', array('@s' => $context->identifier));
}

/**
 * Ctools plugin configuration edit form for the status form field.
 *
 * Provide a blank form so we have a place to have context setting.
 */
function ctools_user_form_status_content_type_edit_form($form, &$form_state) {
  return $form;
}
