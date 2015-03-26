<?php
/**
 * @file
 * ma_digitalheritage.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function ma_digitalheritage_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: main-menu:node/add/digital-heritage
  $menu_links['main-menu:node/add/digital-heritage'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/digital-heritage',
    'router_path' => 'node/add/digital-heritage',
    'link_title' => 'Digital Heritage',
    'options' => array(
      'attributes' => array(
        'title' => 'Add digital heritage content to the archive',
        'class' => array(
          0 => 'mukurtu-actions',
        ),
      ),
      'identifier' => 'main-menu_digital-heritage:node/add/digital-heritage',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Heritage');


  return $menu_links;
}
