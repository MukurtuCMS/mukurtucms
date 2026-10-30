<?php

/**
 * @file
 * Stub file for "image" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "image" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see theme_image()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_image(array &$variables) {
  // Add image shape, if necessary.
  if ($shape = bootstrap_setting('image_shape')) {
    _bootstrap_add_class($shape, $variables);
  }

  // Add responsiveness, if necessary.
  if (bootstrap_setting('image_responsive')) {
    _bootstrap_add_class('img-responsive', $variables);
  }
}
