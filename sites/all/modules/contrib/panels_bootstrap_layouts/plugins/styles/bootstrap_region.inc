<?php

/**
 * @file
 * Definition of the 'list' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap'),
  'description' => t('Bootstrap settings.'),

  'render region' => 'panels_bootstrap_layouts_style_region_render',
  'settings form' => 'panels_bootstrap_layouts_style_region_settings_form',
);

/**
 * Render region callback.
 *
 * @ingroup themeable
 */
function theme_panels_bootstrap_layouts_style_region_render($vars) {
  $display = $vars['display'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  if ($panes) {
    $class = array('panel-panel', $vars['region_id']);

    if (!empty($settings['css_class'])) {
      $class[] = $settings['css_class'];
    }

    foreach (array('xs', 'sm', 'md', 'lg') as $size) {
      if (isset($settings['column'][$size])) {
        if ($settings['column'][$size] === 'hidden') {
          $class[] = 'hidden-' . $size;
        }
        elseif (!empty($settings['column'][$size])) {
          $class[] = 'col-' . $size . '-' . $settings['column'][$size];
        }
      }

      if (isset($settings['offset'][$size]) && !empty($settings['offset'][$size])) {
        $class[] = 'col-' . $size . '-offset-' . $settings['offset'][$size];
      }

      if (isset($settings['push'][$size]) && !empty($settings['push'][$size])) {
        $class[] = 'col-' . $size . '-push-' . $settings['push'][$size];
      }

      if (isset($settings['pull'][$size]) && !empty($settings['pull'][$size])) {
        $class[] = 'col-' . $size . '-pull-' . $settings['pull'][$size];
      }
    }

    // Compatibility with previous version.
    if (empty($class)) {
      $class[] = _panels_bootstrap_layouts_legacy_get_col_classes($settings);
    }

    $element = array(
      '#tag' => 'div',
      '#value' => implode('', $panes),
      '#attributes' => array('class' => $class)
    );

    if (!empty($settings['css_id'])) {
      $element['#attributes']['id'] = $settings['css_id'];
    }

    return theme('html_tag', array('element' => $element));
  }
}

/**
 * Region settings form callback.
 */
function panels_bootstrap_layouts_style_region_settings_form($style_settings, $display, $pid, $type, $form_state) {
  $form = array();

  $form['css_id'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS ID'),
    '#default_value' => isset($style_settings['css_id']) ? $style_settings['css_id'] : '',
    '#description' => t('CSS ID to apply to this pane. This may be blank.'),
  );

  $form['css_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#default_value' => isset($style_settings['css_class']) ? $style_settings['css_class'] : '',
    '#description' => t('CSS class to apply to this pane. This may be blank.'),
  );

  $options = range(0, 12);
  $options[0] = t('-- None --');
  $options['hidden'] = t('-- Hidden --');

  $column_sizes = array(
    'xs' => t('Extra small devices'),
    'sm' => t('Small devices'),
    'md' => t('Medium devices'),
    'lg' => t('Large devices'),
  );

  $form['column'] = array(
    '#type' => 'fieldset',
    '#title' => t('Grid options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['offset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Offsetting'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['push'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pushing'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['pull'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pulling'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  foreach ($column_sizes as $size => $description) {
    $form['column'][$size] = array(
      '#type' => 'select',
      '#title' => t('Column size !size', array('!size' => strtoupper($size))),
      '#options' => $options,
      '#default_value' => isset($style_settings['column'][$size])
        ? $style_settings['column'][$size]
        : 1,
      '#description' => t('Column size for !description (col-!size-*)', array(
        '!description' => $description,
        '!size' => $size,
      )),
    );

    $form['offset'][$size] = array(
      '#type' => 'select',
      '#title' => t('Offset size !size', array('!size' => strtoupper($size))),
      '#options' => $options,
      '#default_value' => isset($style_settings['offset'][$size]) ? $style_settings['offset'][$size] : 0,
      '#description' => t('Offset size for !description (col-!size-offset-*)', array(
        '!description' => $description,
        '!size' => $size,
      )),
    );

    $form['push'][$size] = array(
      '#type' => 'select',
      '#title' => t('Push size !size', array('!size' => strtoupper($size))),
      '#options' => $options,
      '#default_value' => isset($style_settings['push'][$size]) ? $style_settings['push'][$size] : 0,
      '#description' => t('Push size for !description (col-!size-push-*)', array(
        '!description' => $description,
        '!size' => $size,
      )),
    );

    $form['pull'][$size] = array(
      '#type' => 'select',
      '#title' => t('Pull size !size', array('!size' => strtoupper($size))),
      '#options' => $options,
      '#default_value' => isset($style_settings['pull'][$size]) ? $style_settings['pull'][$size] : 0,
      '#description' => t('Pull size for !description (col-!size-pull-*)', array(
        '!description' => $description,
        '!size' => $size,
      )),
    );
  }

  return $form;
}

/**
 * Helper to keep compatibility with old versions of the module.
 *
 * @param $settings
 *
 * @return string
 *  Column class.
 *
 * @deprecated
 */
function _panels_bootstrap_layouts_legacy_get_col_classes($settings) {
  $class = array();

  if ($settings['column_size']) {
    if (empty($settings['column_type'])) {
      $settings['column_type'] = 'col-lg';
    }

    $class[] = $settings['column_type'] . '-' . $settings['column_size'];
  }

  if ($settings['offset_type'] && $settings['offset_size']) {
    $class[] = $settings['offset_type'] . '-' . $settings['offset_size'];
  }

  return implode(' ', $class);
}
