<?php



/**
 * Popup administration settings form
 */
function popup_admin_settings(){

  module_load_include('inc', 'popup', 'includes/popup.util');

  $form = array();
  $style_names = array_keys(_popup_styles());
  $style_options = array_combine(
    $style_names,
    $style_names
  );
  array_unshift($style_options, t('No style'));

  $form['popup-style'] = array(
    '#default_value' => variable_get(
      'popup-style',
      'white'
    ),
    '#description' => 'Select the default style in which to display popups. Note that
                       "No style" should be used if the theme is to override popup
                       themeing.',
    '#options' => $style_options,
    '#title' => 'Default style',
    '#type' => 'select',
  );

  $width_options = range(100, 500, 50);
  $width_options = array_combine($width_options, $width_options);
  $form['popup-width'] = array(
    '#default_value' => variable_get('popup-width', 150),
    '#description' => 'Select the default width of popups in px.',
    '#options' => $width_options,
    '#title' => 'Default width',
    '#type' => 'select',
  );

  $linger_options = range(0, 2000, 250);
  $linger_options = array_combine($linger_options, $linger_options);
  $form['popup-hover-linger'] = array(
    '#default_value' => variable_get('popup-hover-linger', 250),
    '#description' => 'Select the amount of time in ms that hover popups should
                       linger before closing.',
    '#options' => $linger_options,
    '#title' => 'Hover linger',
    '#type' => 'select',
  );

  $delay_options = range(0, 2000, 250);
  $delay_options = array_combine($delay_options, $delay_options);
  $form['popup-hover-delay'] = array(
    '#default_value' => variable_get('popup-hover-delay', 0),
    '#description' => 'Select the amount of time in ms that hover popups should
                       delay before showing.',
    '#options' => $delay_options,
    '#title' => 'Hover delay',
    '#type' => 'select',
  );

  $form['popup-preprocess'] = array(
    '#default_value' => variable_get('popup-preprocess', FALSE),
    '#description' => 'Allow Drupal to compress and aggregate popup CSS and
                       Javascript.',
    '#title' => 'Allow performance optimization',
    '#type' => 'checkbox',
  );

  return system_settings_form($form);
}