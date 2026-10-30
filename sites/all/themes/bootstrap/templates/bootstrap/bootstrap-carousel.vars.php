<?php

/**
 * @file
 * Stub file for "bootstrap_carousel" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "bootstrap_carousel" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see bootstrap-carousel.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_bootstrap_carousel(array &$variables) {
  $variables['attributes']['class'][] = 'carousel';
  $variables['attributes']['class'][] = 'slide';
  $variables['attributes']['data-ride'] = 'carousel';
  if (empty($variables['attributes']['id'])) {
    $variables['attributes']['id'] = drupal_html_id('carousel');
  }
  $default_data_attributes = array(
    'interval' => 5000,
    'pause' => TRUE,
    'wrap' => TRUE,
  );
  foreach ($default_data_attributes as $name => $value) {
    if ($variables[$name] !== $value) {
      // Convert PHP booleans to the JSON equivalent, otherwise they'll be
      // interpreted as integers when they're parsed.
      if (is_bool($variables[$name])) {
        $variables[$name] = $variables[$name] ? 'true' : 'false';
      }
      $variables['attributes']['data-' . $name] = $variables[$name];
    }
  }
}

/**
 * Processes variables for the "bootstrap_carousel" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see bootstrap-carousel.tpl.php
 *
 * @ingroup theme_process
 */
function bootstrap_process_bootstrap_carousel(array &$variables) {
  $variables['target'] = '#' . $variables['attributes']['id'];
  $variables['attributes'] = drupal_attributes($variables['attributes']);

  // Ensure the item arrays are constructed properly for the template.
  foreach ($variables['items'] as $delta => $item) {
    // Convert items that are string into the appropriate array structure.
    if (is_string($item)) {
      $variables['items'][$delta] = array(
        'image' => $item,
      );
    }
    // Populate defaults.
    $variables['items'][$delta] += array(
      'title' => NULL,
      'description' => NULL,
      'url' => NULL,
    );

    if (!empty($variables['items'][$delta]['title'])) {
      $variables['items'][$delta]['title'] = is_scalar($item['title']) ? filter_xss_admin($item['title']) : render($item['title']);
    }

    if (!empty($variables['items'][$delta]['description'])) {
      $variables['items'][$delta]['description'] = is_scalar($item['description']) ? filter_xss_admin($item['description']) : render($item['description']);
    }

  }
}
