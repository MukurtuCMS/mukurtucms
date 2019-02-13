<?php

/**
 * @file
 * ma_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ma_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'This menu shows for all users. It includes the "utility" buttons (login, logout, my account) and for all content curators and above, the content creation buttons.',
  );
  // Exported menu: menu-browse-menu.
  $menus['menu-browse-menu'] = array(
    'menu_name' => 'menu-browse-menu',
    'title' => 'Browse Menu',
    'description' => 'The Browse Menu is for viewing content.
',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Browse Menu');
  t('Main menu');
  t('The Browse Menu is for viewing content.
');
  t('This menu shows for all users. It includes the "utility" buttons (login, logout, my account) and for all content curators and above, the content creation buttons.');

  return $menus;
}
