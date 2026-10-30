<?php

/**
 * @file
 * Holds relevant functions for paragraph field formatters.
 */

/**
 * Implements hook_field_formatter_info().
 */
function paragraphs_field_formatter_info() {
  return array(
    'paragraphs_view' => array(
      'label' => t('Paragraphs items'),
      'field types' => array('paragraphs'),
      'settings' => array(
        'view_mode' => 'full',
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function paragraphs_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $elements = array();

  if ($display['type'] == 'paragraphs_view') {

    $entity_type = entity_get_info('paragraphs_item');
    $options = array();
    foreach ($entity_type['view modes'] as $mode => $info) {
      $options[$mode] = $info['label'];
    }

    $elements['view_mode'] = array(
      '#type' => 'select',
      '#title' => t('View mode'),
      '#options' => $options,
      '#default_value' => $settings['view_mode'],
      '#description' => t('Select the view mode'),
    );
  }

  return $elements;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function paragraphs_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $output = array();

  if ($display['type'] == 'paragraphs_view') {
    $entity_type = entity_get_info('paragraphs_item');
    if (!empty($entity_type['view modes'][$settings['view_mode']]['label'])) {
      $output[] = t('View mode: @mode', array('@mode' => $entity_type['view modes'][$settings['view_mode']]['label']));
    }
    else {
      $output[] = ' ';
    }
  }

  return implode('<br>', $output);
}

/**
 * Implements hook_field_formatter_view().
 */
function paragraphs_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'paragraphs_view':

      // Prevent displaying useless markup if we don't have any values.
      if (empty($items)) {
        return $element;
      }
      // Get view mode from entity.
      $display_view_mode = empty($display['settings']['view_mode']) ? 'full' : $display['settings']['view_mode'];
      // Get view mode from field instance (if configured).
      $view_mode = empty($instance['display'][$display_view_mode]['settings']['view_mode']) ? $display_view_mode : $instance['display'][$display_view_mode]['settings']['view_mode'];
      $element['#theme_wrappers'] = array('paragraphs_items');
      $element['#attributes']['class'][] = drupal_clean_css_identifier('paragraphs-items');
      $element['#attributes']['class'][] = drupal_clean_css_identifier('paragraphs-items-view-mode-' . $view_mode);
      $element['#attributes']['class'][] = drupal_clean_css_identifier('paragraphs-items-field-' . $instance['field_name']);
      $element['#paragraphs_items_view_mode'] = $view_mode;

      foreach ($items as $delta => $item) {
        if ($paragraph = paragraphs_field_get_entity($item)) {
          $paragraph->setHostEntity($entity_type, $entity, $langcode);
          if (entity_access('view', 'paragraphs_item', $paragraph)) {
            $element[$delta]['entity'] = $paragraph->view($view_mode, $langcode);
          }
        }
      }
      break;
  }
  return $element;
}
