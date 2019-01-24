<?php

/**
 * @file
 * ma_base_theme.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ma_base_theme_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-browse-menu_browse:browse.
  $menu_links['menu-browse-menu_browse:browse'] = array(
    'menu_name' => 'menu-browse-menu',
    'link_path' => 'browse',
    'router_path' => 'browse',
    'link_title' => 'Browse',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-browse-menu_browse:browse',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-log-in-log-out_log-in:user/login.
  $menu_links['menu-log-in-log-out_log-in:user/login'] = array(
    'menu_name' => 'menu-log-in-log-out',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-log-in-log-out_log-in:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-log-in-log-out_log-out:user/logout.
  $menu_links['menu-log-in-log-out_log-out:user/logout'] = array(
    'menu_name' => 'menu-log-in-log-out',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-log-in-log-out_log-out:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Browse');
  t('Log in');
  t('Log out');

  return $menu_links;
}
