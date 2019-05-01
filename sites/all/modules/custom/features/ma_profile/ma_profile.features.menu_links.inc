<?php

/**
 * @file
 * ma_profile.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ma_profile_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_-user:admin/people/create.
  $menu_links['main-menu_-user:admin/people/create'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/people/create',
    'router_path' => 'admin/people/create',
    'link_title' => '+ User',
    'options' => array(
      'identifier' => 'main-menu_-user:admin/people/create',
      'attributes' => array(
        'class' => array(
          0 => 'mukurtu-actions',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('+ User');

  return $menu_links;
}
