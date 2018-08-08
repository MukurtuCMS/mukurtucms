<?php

/**
 * @file
 * Stub file for "menu_link" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "menu_link" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see bootstrap_menu_link()
 * @see theme_menu_link()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_menu_link(array &$variables) {
  $element = &$variables['element'];

  // Determine if the link should be shown as "active" based on the current
  // active trail (set by core/contrib modules).
  // @see https://www.drupal.org/node/2618828
  // @see https://www.drupal.org/node/1896674
  if (in_array('active-trail', _bootstrap_get_classes($element)) || ($element['#href'] == '<front>' && drupal_is_front_page())) {
    $element['#attributes']['class'][] = 'active';
  }
}
