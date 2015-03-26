<?php
/**
 * @file
 * ma_culturalprotocol.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function ma_culturalprotocol_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: main-menu:node/add/cultural-protocol-group
  $menu_links['main-menu:node/add/cultural-protocol-group'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/cultural-protocol-group',
    'router_path' => 'node/add/cultural-protocol-group',
    'link_title' => 'Cultural Protocol ',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'mukurtu-actions',
        ),
      ),
      'identifier' => 'main-menu_cultural-protocol-:node/add/cultural-protocol-group',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Cultural Protocol ');


  return $menu_links;
}
