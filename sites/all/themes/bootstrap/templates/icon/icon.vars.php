<?php
/**
 * @file
 * Stub file for "icon" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "icon" theme hook.
 *
 * Bootstrap requires an additional "glyphicon" class for all icons.
 *
 * See theme function for list of available variables.
 *
 * @see icon_preprocess_icon_image()
 * @see template_preprocess_icon()
 * @see theme_icon()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_icon(&$variables) {
  $bundle = &$variables['bundle'];
  if ($bundle['provider'] === 'bootstrap') {
    $variables['attributes']['class'][] = 'glyphicon';
  }
}
