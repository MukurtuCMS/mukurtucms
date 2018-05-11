<?php

/**
 * @file
 * Stub file for "table" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "table" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see bootstrap_table()
 * @see theme_table()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_table(array &$variables) {
  // Prepare classes array if necessary.
  if (!isset($variables['attributes']['class'])) {
    $variables['attributes']['class'] = array();
  }
  // Convert classes to an array.
  elseif (isset($variables['attributes']['class']) && is_string($variables['attributes']['class'])) {
    $variables['attributes']['class'] = explode(' ', $variables['attributes']['class']);
  }

  // Add the necessary classes to the table.
  _bootstrap_table_add_classes($variables['attributes']['class'], $variables);
}

/**
 * Helper function for adding the necessary classes to a table.
 *
 * @param array $classes
 *   The array of classes, passed by reference.
 * @param array $variables
 *   The variables of the theme hook, passed by reference.
 */
function _bootstrap_table_add_classes(array &$classes, array &$variables) {
  $context = $variables['context'];

  // Generic table class for all tables.
  $classes[] = 'table';

  // Bordered table.
  if (!empty($context['bordered']) || (!isset($context['bordered']) && bootstrap_setting('table_bordered'))) {
    $classes[] = 'table-bordered';
  }

  // Condensed table.
  if (!empty($context['condensed']) || (!isset($context['condensed']) && bootstrap_setting('table_condensed'))) {
    $classes[] = 'table-condensed';
  }

  // Hover rows.
  if (!empty($context['hover']) || (!isset($context['hover']) && bootstrap_setting('table_hover'))) {
    $classes[] = 'table-hover';
  }

  // Striped rows.
  if (!empty($context['striped']) || (!isset($context['striped']) && bootstrap_setting('table_striped'))) {
    $classes[] = 'table-striped';
  }

  // Responsive table.
  $responsive = (int) (isset($context['responsive']) ? $context['responsive'] : bootstrap_setting('table_responsive', NULL, 'bootstrap', -1));
  $variables['responsive'] = $responsive === -1 ? !path_is_admin(current_path()) : !!$responsive;
}
