<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_user_form.png',
  'title' => t('User form actions / buttons'),
  'description' => t('The user form actions / buttons.'),
  'required context' => new ctools_context_required(t('Form'), 'form'),
  'category' => t('Form'),
);

/**
 * Ctools plugin content type render for the picture form field.
 */
function ctools_user_form_actions_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('user-form');

  $block->delta = 'title-options';

  if (isset($context->form)) {
    if (!empty($context->form['actions'])) {
      $block->content['actions'] = $context->form['actions'];
      unset($context->form['actions']);
    }
    // Because we are adding the submit buttons outside the General form
    // we can assume the necessary hidden components should be added as well.
    if (!empty($context->form['form_build_id'])) {
      $block->content['form_build_id'] = $context->form['form_build_id'];
      unset($context->form['form_build_id']);
    }
    if (!empty($context->form['form_token'])) {
      $block->content['form_token'] = $context->form['form_token'];
      unset($context->form['form_token']);
    }
    if (!empty($context->form['form_id'])) {
      $block->content['form_id'] = $context->form['form_id'];
      unset($context->form['form_id']);
    }
  }
  else {
    $block->content = t('User actions / buttons form components.');
  }
  return $block;
}

/**
 * Ctools plugin admin title function for the actions form field.
 */
function ctools_user_form_actions_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user form actions / buttons field', array('@s' => $context->identifier));
}

/**
 * Ctools plugin configuration edit form for the actions form field.
 *
 * Provide a blank form so we have a place to have context setting.
 */
function ctools_user_form_actions_content_type_edit_form($form, &$form_state) {
  return $form;
}
