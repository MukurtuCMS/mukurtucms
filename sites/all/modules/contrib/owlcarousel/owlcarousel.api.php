<?php

/**
 * @file
 * API documentation for Owl Carousel.
 */

/**
 * Implements hook_owlcarousel_settings_alter().
 *
 * @param array $settings
 *   Instance settings.
 * @param string $instance
 *   Carousel identifier.
 */
function hook_owlcarousel_settings_alter(&$settings, $instance) {
  switch ($instance) {
    case 'owlcarousel_settings_default':
      // Update the number of items displayed
      $settings['items'] = 2;
      break;
  }
}

/**
 * Implements hook_owlcarousel_pre_render_alter().
 *
 * @param array $element
 *  Pre render array of carousel output & settings.
 */
function hook_owlcarousel_pre_render_alter(&$element) {
  // Alter the fully built carousel & settings array
  // before render.

  // Push an additional item onto the carousel.
  $element['#markup']['#output']['#items'][] = array(
    'row' => 'Imagine some HTML here'
  );
}
