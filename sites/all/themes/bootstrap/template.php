<?php

/**
 * @file
 * The primary PHP file for the Drupal Bootstrap base theme.
 *
 * This file should only contain light helper functions and point to stubs in
 * other files containing more complex functions.
 *
 * The stubs should point to files within the `./includes` folder named after
 * the function itself minus the theme prefix. If the stub contains a group of
 * functions, then please organize them so they are related in some way and name
 * the file appropriately to at least hint at what it contains.
 *
 * All [pre]process functions, theme functions and template files lives inside
 * the `./templates` folder. This is a highly automated and complex system
 * designed to only load the necessary files when a given theme hook is invoked.
 *
 * Visit this project's official documentation site https://drupal-bootstrap.org
 * or the markdown files inside the `./docs` folder.
 *
 * @see _bootstrap_theme()
 */

/**
 * Include common functions used through out theme.
 */
include_once dirname(__FILE__) . '/includes/common.inc';

/**
 * Include any deprecated functions.
 */
bootstrap_include('bootstrap', 'includes/deprecated.inc');

/**
 * Implements hook_theme().
 *
 * Register theme hook implementations.
 *
 * The implementations declared by this hook have two purposes: either they
 * specify how a particular render array is to be rendered as HTML (this is
 * usually the case if the theme function is assigned to the render array's
 * #theme property), or they return the HTML that should be returned by an
 * invocation of theme().
 *
 * @see _bootstrap_theme()
 */
function bootstrap_theme(&$existing, $type, $theme, $path) {
  bootstrap_include($theme, 'includes/registry.inc');
  return _bootstrap_theme($existing, $type, $theme, $path);
}

/**
 * Clear any previously set element_info() static cache.
 *
 * If element_info() was invoked before the theme was fully initialized, this
 * can cause the theme's alter hook to not be invoked.
 *
 * @see https://www.drupal.org/node/2351731
 */
drupal_static_reset('element_info');

/**
 * Declare various hook_*_alter() hooks.
 *
 * All hook_*_alter() implementations must live (via include) inside this file
 * so they are properly detected when drupal_alter() is invoked.
 */
bootstrap_include('bootstrap', 'includes/alter.inc');
