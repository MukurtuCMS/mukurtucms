<?php

/**
 * @file
 * Provides a panels pane that shows the content's visibility.
 */

$plugin = array(
  'title' => t('Visibility toolbar'),
  'description' => t('Show content visibility.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_widgets_visibility_toolbar_edit_form',
  'render callback' => 'oa_widgets_visibility_toolbar_render',
);

/**
 * Render callback for the content visibility panel.
 */
function oa_widgets_visibility_toolbar_render($subtype, $conf, $args, $context = NULL) {
  $node = menu_get_object();
  if (!isset($node->type)) {
    return;
  }
  if (!variable_get('oa_show_visibility_toolbar', TRUE)) {
    return;
  }

  $block = new stdClass();
  $block->title = '';

  $vars = oa_core_visibility_data($node);
  $block->content = theme('oa_widgets_visibility_toolbar', $vars);
  return $block;
}

/**
 * Custom edit form
 */
function oa_widgets_visibility_toolbar_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_widgets_visibility_toolbar_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

