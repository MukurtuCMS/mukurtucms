<?php

/**
 * @file
 * Stub file for "page" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_page(array &$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-6"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-9"';
  }
  else {
    $variables['content_column_class'] = ' class="col-sm-12"';
  }

  if (bootstrap_setting('fluid_container') == 1) {
    $variables['container_class'] = 'container-fluid';
  }
  else {
    $variables['container_class'] = 'container';
  }

  $i18n = module_exists('i18n_menu');

  // Primary nav.
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Load the tree.
    $tree = menu_tree_page_data(variable_get('menu_main_links_source', 'main-menu'));

    // Localize the tree.
    if ($i18n) {
      $tree = i18n_menu_localize_tree($tree);
    }

    // Build links.
    $variables['primary_nav'] = menu_tree_output($tree);

    // Provide default theme wrapper function.
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav.
  $variables['secondary_nav'] = FALSE;
  if ($variables['secondary_menu']) {
    // Load the tree.
    $tree = menu_tree_page_data(variable_get('menu_secondary_links_source', 'user-menu'));

    // Localize the tree.
    if ($i18n) {
      $tree = i18n_menu_localize_tree($tree);
    }

    // Build links.
    $variables['secondary_nav'] = menu_tree_output($tree);

    // Provide default theme wrapper function.
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }

  $variables['navbar_classes_array'] = array('navbar');

  if (bootstrap_setting('navbar_position') !== '') {
    $variables['navbar_classes_array'][] = 'navbar-' . bootstrap_setting('navbar_position');
  }
  elseif (bootstrap_setting('fluid_container') == 1) {
    $variables['navbar_classes_array'][] = 'container-fluid';
  }
  else {
    $variables['navbar_classes_array'][] = 'container';
  }
  if (bootstrap_setting('navbar_inverse')) {
    $variables['navbar_classes_array'][] = 'navbar-inverse';
  }
  else {
    $variables['navbar_classes_array'][] = 'navbar-default';
  }
}

/**
 * Processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_process
 */
function bootstrap_process_page(array &$variables) {
  $variables['navbar_classes'] = implode(' ', $variables['navbar_classes_array']);
}
