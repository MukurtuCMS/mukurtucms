<?php
/**
 * @file
 * oa_layouts.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function oa_layouts_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer');

  return $menus;
}
