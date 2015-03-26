<?php

/**
 * @file
 * Field module functionality for the oEmbed module.
 */

/**
 * Implements hook_field_formatter_info().
 */
function oembed_field_formatter_info() {
  $formatters = array(
    'oembed_default' => array(
      'label' => t('OEmbed'),
      'field types' => array('link_field'),
      'description' => t('Embeds links if possible - otherwise just links them.'),
      'settings' => array('maxwidth' => '', 'maxheight' => ''),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function oembed_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();
  $element['maxwidth'] = array(
    '#title' => t('Maximum Width'),
    '#type' => 'textfield',
    '#default_value' => $settings['maxwidth'],
  );
  $element['maxheight'] = array(
    '#title' => t('Maximum Height'),
    '#type' => 'textfield',
    '#default_value' => $settings['maxheight'],
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function oembed_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = '';

  $summary .= t('Max Width') . ': ' . (!empty($settings['maxwidth']) ?  $settings['maxwidth'] : 'default');
  $summary .= '<br />';
  $summary .= t('Max Height') . ': ' . (!empty($settings['maxheight']) ?  $settings['maxheight'] : 'default');

  return $summary;
}

/**
 * Implements hook_field_formatter_view().
 */
function oembed_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  foreach ($items as $delta => $item) {
    $url = url($item['url'], $item + array('external' => TRUE));
    $parameters = $display['settings'];

    $element[$delta] = oembed_render_element('oembed', $url, $parameters);
  }

  return $element;
}
