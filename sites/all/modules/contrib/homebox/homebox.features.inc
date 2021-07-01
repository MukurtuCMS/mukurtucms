<?php

/**
 * @file
 * Features support.
 */

/**
 * Return API information for features.
 */
function _homebox_features_api() {
  return array(
    'homebox' => array(
      'name' => t('Homebox'),
      'default_hook' => 'homebox',
      'default_file' => FEATURES_DEFAULTS_INCLUDED_COMMON,
      'features_source' => TRUE,
      'file' => drupal_get_path('module', 'homebox') . '/homebox.features.inc',
    ),
  );
}

/**
 * Implements hook_features_export_options().
 */
function homebox_features_export_options() {
  $exports = array();
  $pages = homebox_pages();
  if ($pages) {
    foreach ($pages as $page) {
      $exports[$page->name] = $page->name;
    }
  }

  return $exports;
}

/**
 * Implements hook_features_export().
 */
function homebox_features_export($data, &$export, $module_name = '') {
  $pipe = array();
  $export['dependencies']['homebox'] = 'homebox';
  foreach ($data as $name) {
    $export['features']['homebox'][$name] = $name;
  }

  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function homebox_features_export_render($module = 'foo', $data) {
  $code = array();

  // Begin code
  $code[] = '  $homeboxes = array();' . "\n";

  foreach ($data as $name) {
    // Load the page
    $page = homebox_get_page($name);
    // Create exported settings
    $export = features_var_export($page->settings);
    // Fix spacing
    $export = str_replace("\n", "\n  ", $export);
    // Add to code
    $code[] = '  $homeboxes[\'' . $page->name . '\'] = ' . $export . ";\n";
  }

  // End code
  $code[] = "\n" . '  return $homeboxes;';

  // Put code into a string
  $code = implode($code, "\n");

  return array('homebox' => $code);
}

/**
 * Implements hook_features_revert().
 */
function homebox_features_revert($module = NULL) {
  // Get homebox pages from feature
  if (module_hook($module, 'homebox')) {
    $pages = module_invoke($module, 'homebox');

    foreach ($pages as $name => $settings) {
      homebox_delete_page($name);
    }
  }
}
