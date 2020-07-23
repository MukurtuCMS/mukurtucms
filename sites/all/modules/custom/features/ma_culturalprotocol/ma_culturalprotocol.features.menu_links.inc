<?php

/**
 * @file
 * ma_culturalprotocol.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ma_culturalprotocol_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_-cultural-protocol:node/add/cultural-protocol-group.
  $menu_links['main-menu_-cultural-protocol:node/add/cultural-protocol-group'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/cultural-protocol-group',
    'router_path' => 'node/add/cultural-protocol-group',
    'link_title' => '+ Cultural Protocol',
    'options' => array(
      'identifier' => 'main-menu_-cultural-protocol:node/add/cultural-protocol-group',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('+ Cultural Protocol');

  return $menu_links;
}
