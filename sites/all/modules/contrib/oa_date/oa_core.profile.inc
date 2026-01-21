<?php

/**
 * @file
 * An installation file for OpenAtrium Core
 */

/**
 * Task handler to load our install profile and enhance the dependency information
 */
function oa_core_install_load_profile(&$install_state) {
  $private_path = variable_get('file_private_path', FALSE);
  if (!$private_path) {
    $private_path = variable_get('file_public_path', conf_path() . '/files') . '/private';
    // can't set variables here yet, but this will be set in oa_config later in install
    // variable_set('file_private_path', $private_path);
  }
  if (!empty($private_path) && !is_dir($private_path)) {
    mkdir($private_path, 0775, TRUE);
  }

  // ** Code from panopoly_core.profile.inc copied here **
  //
  // Cannot call this directly because of a Pantheon issue
  // require_once(drupal_get_path('module', 'panopoly_core') . '/panopoly_core.profile.inc');
  // panopoly_core_install_load_profile($install_state);

  // Loading the install profile normally
  install_load_profile($install_state);

  // Include any dependencies that we might have missed...
  $dependencies = $install_state['profile_info']['dependencies'];
  foreach ($dependencies as $module) {
    $module_info = drupal_parse_info_file(drupal_get_path('module', $module) . '/' . $module . '.info');
    if (!empty($module_info['dependencies'])) {
      foreach ($module_info['dependencies'] as $dependency) {
        $parts = explode(' (', $dependency, 2);
        $dependencies[] = array_shift($parts);
      }
    }
  }
  $install_state['profile_info']['dependencies'] = array_unique($dependencies);
}
