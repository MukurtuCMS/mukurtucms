<?php

/**
 * @file
 * ma_community.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ma_community_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_-community:node/add/community.
  $menu_links['main-menu_-community:node/add/community'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/community',
    'router_path' => 'node/add/community',
    'link_title' => '+ Community',
    'options' => array(
      'identifier' => 'main-menu_-community:node/add/community',
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
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('+ Community');

  return $menu_links;
}
