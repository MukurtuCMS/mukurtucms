<?php

/**
 * @file
 * Provides a panels pane that shows the content's visibility.
 */

$plugin = array(
  'title' => t('Content Visibility'),
  'description' => t('Show content visibility.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_widgets_content_visibility_edit_form',
  'render callback' => 'oa_widgets_content_visibility_render',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
  'defaults' => array(
    'mode' => '',
  ),
);

/**
 * Render callback for the content visibility panel.
 */
function oa_widgets_content_visibility_render($subtype, $conf, $args, $context = NULL) {
  $node = isset($context->data) ? $context->data : menu_get_object();

  if (!isset($node->type)) {
    return;
  }

  if (empty($conf['mode'])) {
    // Visibility block
    if (!variable_get('oa_show_visibility_panel', TRUE)) {
      return;
    }

    $vars = oa_core_visibility_data($node);

    $block = new stdClass();
    $block->title = t('Content Visibility');
    $block->content = theme('oa_widgets_content_visibility', $vars);
    return $block;
  }
  else {
    // Visibility button
    if (!variable_get('oa_show_visibility_toolbar', TRUE)) {
      return;
    }

    $vars = oa_core_visibility_data($node);
    $vars['oa_toolbar_btn_class'] = 'btn-small btn-sm btn-default';
    $vars['direction'] = 'dropup';

    $block = new stdClass();
    $block->title = '';
    $block->content = theme('oa_widgets_visibility_toolbar', $vars);
    return $block;
  }
}

/**
 * Custom edit form to allow users to enable/disable selectable content types
 */
function oa_widgets_content_visibility_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['mode'] = array(
    '#type' => 'select',
    '#options' => array(
      '' => 'Panel',
      'btn' => 'Button',
    ),
    '#title' => 'Mode',
    '#default_value' => $conf['mode'],
  );

  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_widgets_content_visibility_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

