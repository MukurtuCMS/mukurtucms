<?php
/**
 * @file
 * ma_single_browse_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ma_single_browse_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'single_dh_browse_page';
  $page->task = 'page';
  $page->admin_title = 'Single DH Browse Page';
  $page->admin_description = '';
  $page->path = 'browse';
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
    'title' => 'Browse Digital Heritage',
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
  $handler->name = 'page_single_dh_browse_page__panel_context_1e036bf5-7f44-4308-8abc-f1bb703574b7';
  $handler->task = 'page';
  $handler->subtask = 'single_dh_browse_page';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
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
      'center_' => NULL,
      'right' => NULL,
    ),
    'right' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Digital Heritage';
  $display->uuid = 'ec86842b-dca2-4773-9bee-be7ede7eed66';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_single_dh_browse_page__panel_context_1e036bf5-7f44-4308-8abc-f1bb703574b7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1b3fca68-b5f8-4527-8bbd-c90a1f511dc4';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'digital_heritage_grid_list-all_single_browse_page_map';
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
  $pane->uuid = '1b3fca68-b5f8-4527-8bbd-c90a1f511dc4';
  $display->content['new-1b3fca68-b5f8-4527-8bbd-c90a1f511dc4'] = $pane;
  $display->panels['center'][0] = 'new-1b3fca68-b5f8-4527-8bbd-c90a1f511dc4';
  $pane = new stdClass();
  $pane->pid = 'new-fe63fb67-3038-41b0-a2a4-ff1c73ae9bed';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-single_browse_page_right_column';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'single-browse-page-right-column',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fe63fb67-3038-41b0-a2a4-ff1c73ae9bed';
  $display->content['new-fe63fb67-3038-41b0-a2a4-ff1c73ae9bed'] = $pane;
  $display->panels['right'][0] = 'new-fe63fb67-3038-41b0-a2a4-ff1c73ae9bed';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['single_dh_browse_page'] = $page;

  return $pages;

}
