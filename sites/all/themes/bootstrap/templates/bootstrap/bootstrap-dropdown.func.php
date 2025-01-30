<?php

/**
 * @file
 * Stub file for bootstrap_bootstrap_dropdown().
 */

/**
 * Returns HTML for a Bootstrap dropdown component.
 *
 * @param array $variables
 *   An associative array of variables.
 *
 * @return string
 *   The constructed HTML markup.
 *
 * @ingroup theme_functions
 */
function bootstrap_bootstrap_dropdown(array $variables) {
  return drupal_render($variables['dropdown']);
}
