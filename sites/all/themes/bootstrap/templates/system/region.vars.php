<?php

/**
 * @file
 * Stub file for "region" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "region" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see region.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_region(array &$variables) {
  global $theme;

  $region = $variables['region'];
  $classes = &$variables['classes_array'];

  // Content region.
  if ($region === 'content') {
    // @todo is this actually used properly?
    $variables['theme_hook_suggestions'][] = 'region__no_wrapper';
  }
  // Help region.
  elseif ($region === 'help' && !empty($variables['content'])) {
    $variables['content'] = _bootstrap_icon('question-sign') . $variables['content'];
    $classes[] = 'alert';
    $classes[] = 'alert-info';
    $classes[] = 'messages';
    $classes[] = 'info';
  }

  // Support for "well" classes in regions.
  static $wells;
  if (!isset($wells)) {
    foreach (system_region_list($theme) as $name => $title) {
      $wells[$name] = bootstrap_setting('region_well-' . $name);
    }
  }
  if (!empty($wells[$region])) {
    $classes[] = $wells[$region];
  }
}
