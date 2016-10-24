<?php
/**
 * @file
 * ma_collection.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ma_collection_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'collections_browse';
  $page->task = 'page';
  $page->admin_title = 'Collections Browse';
  $page->admin_description = '';
  $page->path = 'collections';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Browse Collections',
    'name' => 'menu-browse-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_collections_browse_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'collections_browse';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '69.9671129903688',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '30.0328870096312',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'center_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Collections';
  $display->uuid = '19178ba9-0caf-474f-b588-d95d7ef79ca6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_collections_browse_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-acd6e9d8-2756-4295-8b83-f0f27d304c8c';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'collections_grid_list-all';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'acd6e9d8-2756-4295-8b83-f0f27d304c8c';
  $display->content['new-acd6e9d8-2756-4295-8b83-f0f27d304c8c'] = $pane;
  $display->panels['center'][0] = 'new-acd6e9d8-2756-4295-8b83-f0f27d304c8c';
  $pane = new stdClass();
  $pane->pid = 'new-d7e6f156-c2b7-4707-883e-1218ae5cadbf';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-collections_grid_list-all';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_text' => 'Search',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd7e6f156-c2b7-4707-883e-1218ae5cadbf';
  $display->content['new-d7e6f156-c2b7-4707-883e-1218ae5cadbf'] = $pane;
  $display->panels['right'][0] = 'new-d7e6f156-c2b7-4707-883e-1218ae5cadbf';
  $pane = new stdClass();
  $pane->pid = 'new-590402f1-fa21-4585-a80b-7f7cf586fcce';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-8FIPJ09s0OwWZePRWCc51dsaXQQONRP0';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Digital Heritage Count',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '590402f1-fa21-4585-a80b-7f7cf586fcce';
  $display->content['new-590402f1-fa21-4585-a80b-7f7cf586fcce'] = $pane;
  $display->panels['right'][1] = 'new-590402f1-fa21-4585-a80b-7f7cf586fcce';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['collections_browse'] = $page;

  return $pages;

}
