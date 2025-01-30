<?php

/**
 * @file
 * Stub file for "image_srcset" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "image_srcset" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see theme_image_srcset()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_image_srcset(array &$variables) {
  // Add image shape, if necessary.
  if ($shape = bootstrap_setting('image_shape')) {
    $variables['attributes']['class'][] = $shape;
  }
}
