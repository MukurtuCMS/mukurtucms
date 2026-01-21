<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_user_form.png',
  'title' => t('User form signature settings field'),
  'description' => t('The user signature settings form.'),
  'required context' => new ctools_context_required(t('Form'), 'form'),
  'category' => t('Form'),
);

/**
 * Ctools plugin content type render for the signature settings form field.
 */
function ctools_user_form_signature_settings_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('user-form');

  $block->delta = 'title-options';

  if (isset($context->form)) {
    if (!empty($context->form['signature_settings'])) {
      $block->content['signature_settings'] = $context->form['signature_settings'];
      unset($context->form['signature_settings']);
    }
  }
  else {
    $block->content = t('User signature settings form.');
  }
  return $block;
}

/**
 * Ctools plugin admin title function for the signature settings form field.
 */
function ctools_user_form_signature_settings_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user form signature settings field', array('@s' => $context->identifier));
}

/**
 * Ctools plugin configuration edit form for the signature settings form field.
 *
 * Provide a blank form so we have a place to have context setting.
 */
function ctools_user_form_signature_settings_content_type_edit_form($form, &$form_state) {
  return $form;
}
