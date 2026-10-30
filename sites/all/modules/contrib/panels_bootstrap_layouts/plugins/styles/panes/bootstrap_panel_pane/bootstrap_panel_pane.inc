<?php

/**
 * @file
 */

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap Panel'),
  'description' => t('Bootstrap Panel style.'),

  'render pane' => 'panels_bootstrap_layouts_panel_style_pane_render',
  'pane settings form' => 'panels_bootstrap_layouts_panel_style_pane_settings_form',

  'hook theme' => array(
    'panels_bootstrap_layouts_panel_pane' => array(
      'path' => panels_get_path('plugins/styles/panes/bootstrap_panel_pane', FALSE, 'panels_bootstrap_layouts'),
      'template' => 'panels-bootstrap-layouts-panel-pane',
    ),
  ),
);


/**
 * Pane settings form callback.
 */
function panels_bootstrap_layouts_panel_style_pane_settings_form($style_settings, $display, $pid, $type, $form_state) {
  $form = array();

  $form['style'] = array(
    '#type' => 'select',
    '#title' => t('Contextual alternatives'),
    '#options' => array(
      'default' => t('Default'),
      'primary' => t('Primary'),
      'success' => t('Success'),
      'info' => t('Info'),
      'warning' => t('Warning'),
      'danger' => t('Danger'),
    ),
    '#default_value' => isset($style_settings['style']) ? $style_settings['style'] : 'default',
  );

  $form['padding'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add padding to content.'),
    '#default_value' => (bool)$style_settings['padding'],
  );

  return $form;
}

/**
 * Render pane callback.
 *
 * @ingroup themeable
 */
function theme_panels_bootstrap_layouts_panel_style_pane_render($vars) {
  return theme('panels_bootstrap_layouts_panel_pane', $vars);
}

function template_preprocess_panels_bootstrap_layouts_panel_pane(&$vars) {
  $vars['classes_array'][] = 'panel-' . $vars['settings']['style'];

  $vars['add_padding'] = $vars['settings']['padding'];
}
