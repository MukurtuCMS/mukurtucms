<?php

/**
 * @file
 * ma_collection.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ma_collection_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_-collection:node/add/collection.
  $menu_links['main-menu_-collection:node/add/collection'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/collection',
    'router_path' => 'node/add/collection',
    'link_title' => '+ Collection',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_-collection:node/add/collection',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );
  // Exported menu link: main-menu_-personal-collection:node/add/personal-collection.
  $menu_links['main-menu_-personal-collection:node/add/personal-collection'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/personal-collection',
    'router_path' => 'node/add/personal-collection',
    'link_title' => '+ Personal Collection',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_-personal-collection:node/add/personal-collection',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('+ Collection');
  t('+ Personal Collection');

  return $menu_links;
}
