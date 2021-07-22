<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_user_form.png',
  'title' => t('User form: add a specific component'),
  'description' => t('The user form component by selection.'),
  'required context' => new ctools_context_required(t('Form'), 'form'),
  'category' => t('Form'),
);

/**
 * Ctools plugin content type render for the picture form field.
 */
function ctools_user_form_component_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('user-form');

  $block->delta = 'title-options';

  if (isset($context->form)) {
    if (!empty($context->form[$conf['field']])) {
      $block->content[$conf['field']] = $context->form[$conf['field']];
      unset($context->form[$conf['field']]);
    }
  }
  else {
    $block->content = t('User form edit components.');
  }
  return $block;
}

/**
 * Ctools plugin admin title function for the a selectable form field.
 */
function ctools_user_form_component_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user form @field field', array('@s' => $context->identifier, '@field' => $conf['field']));
}

/**
 * Ctools plugin configuration edit form for the selectable form field.
 *
 * Provide the list of fields in the user profile edit form to select from the
 * plugin configuration.
 */
function ctools_user_form_component_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $user_form = drupal_get_form('user_profile_form');

  $field_keys = element_children($user_form);
  $options = array_combine($field_keys, $field_keys);

  $form['field'] = array(
    '#type' => 'select',
    '#title' => t('User form field'),
    '#options' => $options,
    '#description' => t('Select a form field from the current user form to display in this pane.'),
    '#default_value' => !empty($conf['field']) ? $conf['field'] : '',
  );
  return $form;
}

/**
 * Ctools plugin configuration edit form submit handler.
 */
function ctools_user_form_component_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['field'] = $form_state['values']['field'];
}
