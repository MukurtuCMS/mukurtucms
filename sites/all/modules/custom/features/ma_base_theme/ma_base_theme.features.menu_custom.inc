<?php

/**
 * @file
 * ma_base_theme.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ma_base_theme_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-log-in-log-out.
  $menus['menu-log-in-log-out'] = array(
    'menu_name' => 'menu-log-in-log-out',
    'title' => 'Log In/Log Out',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Log In/Log Out');

  return $menus;
}
