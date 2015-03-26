<?php
/**
 * @file
 * ma_core.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function ma_core_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: main-menu:dashboard
  $menu_links['main-menu:dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Exported menu link: main-menu:user
  $menu_links['main-menu:user'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu:user/login
  $menu_links['main-menu:user/login'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: main-menu:user/logout
  $menu_links['main-menu:user/logout'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_-category:admin/structure/taxonomy/category/add
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
  );
  // Exported menu link: main-menu_-collection:node/add/collection
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
  );
  // Exported menu link: main-menu_-community:node/add/community
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
  );
  // Exported menu link: main-menu_-cultural-protocol:node/add/cultural-protocol-group
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
  );
  // Exported menu link: main-menu_-digital-heritage:node/add/digital-heritage
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
  );
  // Exported menu link: main-menu_-user:admin/people/create
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
    'weight' => -45,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('+ Category');
  t('+ Collection');
  t('+ Community');
  t('+ Cultural Protocol');
  t('+ Digital Heritage');
  t('+ User');
  t('Dashboard');
  t('Log in');
  t('Log out');
  t('User account');


  return $menu_links;
}
