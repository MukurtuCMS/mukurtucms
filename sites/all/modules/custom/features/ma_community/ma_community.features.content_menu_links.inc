<?php
/**
 * @file
 * ma_community.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function ma_community_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: main-menu:node/add/community
  $menu_links['main-menu:node/add/community'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/community',
    'router_path' => 'node/add/community',
    'link_title' => 'Community',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'mukurtu-actions',
        ),
      ),
      'identifier' => 'main-menu_community:node/add/community',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Community');


  return $menu_links;
}
