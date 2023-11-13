<?php

/**
 * @file
 * ma_digitalheritage.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ma_digitalheritage_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_-category:admin/structure/taxonomy/category/add.
  $menu_links['main-menu_-category:admin/structure/taxonomy/category/add'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/structure/taxonomy/category/add',
    'router_path' => 'admin/structure/taxonomy/%/add',
    'link_title' => '+ Category',
    'options' => array(
      'identifier' => 'main-menu_-category:admin/structure/taxonomy/category/add',
      'attributes' => array(
        'title' => 'Add a term to the existing taxonomy "category"',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );
  // Exported menu link: main-menu_-digital-heritage:node/add/digital-heritage.
  $menu_links['main-menu_-digital-heritage:node/add/digital-heritage'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/digital-heritage',
    'router_path' => 'node/add/digital-heritage',
    'link_title' => '+ Digital Heritage',
    'options' => array(
      'identifier' => 'main-menu_-digital-heritage:node/add/digital-heritage',
      'attributes' => array(
        'title' => 'Add digital heritage content to the archive',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('+ Category');
  t('+ Digital Heritage');

  return $menu_links;
}
