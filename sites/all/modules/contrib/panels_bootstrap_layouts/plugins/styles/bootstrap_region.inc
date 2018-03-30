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

  $layouts = array(
    'bootstrap_twocol_stacked',
    'bootstrap_threecol_stacked',
  );

  if (in_array($display->layout, $layouts) && $panes) {
    $class = array('panel-panel', $vars['region_id']);

    if ($settings['column_size']) {
      if (empty($settings['column_type'])) {
        $settings['column_type'] = 'col-lg';
      }

      $class[] = $settings['column_type'] . '-' . $settings['column_size'];
    }

    if ($settings['offset_type'] && $settings['offset_size']) {
      $class[] = $settings['offset_type'] . '-' . $settings['offset_size'];
    }

    $class = implode(' ', $class);
    $html = implode('', $panes);

    return "<div class='$class'>$html</div>";
  }
}

/**
 * Region settings form callback.
 */
function panels_bootstrap_layouts_style_region_settings_form($style_settings, $display, $pid, $type, $form_state) {
  $options = range(0, 12);
  $options[0] = t('-- None --');

  $form['column_type'] = array(
    '#type' => 'select',
    '#title' => t('Сolumn type'),
    '#options' => array(
      'col' => t('Tiny devices'),
      'col-sm' => t('Small & medium devices'),
      'col-lg' => t('Large devices'),
    ),
    '#default_value' => isset($style_settings['column_type'])
      ? $style_settings['column_type']
      : 'col-lg',
  );

  $form['column_size'] = array(
    '#type' => 'select',
    '#title' => t('Сolumn size'),
    '#options' => $options,
    '#default_value' => isset($style_settings['column_size'])
      ? $style_settings['column_size']
      : _panels_bootstrap_layouts_get_default_column_size($display->layout, $pid),
  );

  $form['offset_type'] = array(
    '#type' => 'select',
    '#title' => t('Offset type'),
    '#options' => array(
      'col-offset' => t('Tiny devices'),
      'col-sm-offset' => t('Small & medium devices'),
      'col-lg-offset' => t('Large devices'),
    ),
    '#default_value' => isset($style_settings['offset_type'])
      ? $style_settings['offset_type']
      : 'col-lg-offset',
  );

  $form['offset_size'] = array(
    '#type' => 'select',
    '#title' => t('Offset size'),
    '#options' => $options,
    '#default_value' => isset($style_settings['offset_size'])
      ? $style_settings['offset_size']
      : 0,
  );

  return $form;
}

function _panels_bootstrap_layouts_get_default_column_size($layout, $pid) {
  if (in_array($pid, array('top', 'bottom'))) {
    return 12;
  }

  if ($layout == 'bootstrap_twocol_stacked') {
    return 6;
  }

  if ($layout == 'bootstrap_threecol_stacked') {
    return 4;
  }

  return 1;
}
