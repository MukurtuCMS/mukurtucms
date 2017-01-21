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
    'title' => 'map',
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
      'right' => NULL,
      'center_' => NULL,
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
  $pane->pid = 'new-bb3451b9-027e-415e-9dc8-926a7680ddcb';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'digital_heritage_grid_list-all_map';
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
  $pane->uuid = 'bb3451b9-027e-415e-9dc8-926a7680ddcb';
  $display->content['new-bb3451b9-027e-415e-9dc8-926a7680ddcb'] = $pane;
  $display->panels['center'][0] = 'new-bb3451b9-027e-415e-9dc8-926a7680ddcb';
  $pane = new stdClass();
  $pane->pid = 'new-6073cbed-b276-4931-be5b-b418f191b1da';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'views-ee32d6a0eefea96d62828df6beda043f';
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
  $pane->uuid = '6073cbed-b276-4931-be5b-b418f191b1da';
  $display->content['new-6073cbed-b276-4931-be5b-b418f191b1da'] = $pane;
  $display->panels['right'][0] = 'new-6073cbed-b276-4931-be5b-b418f191b1da';
  $pane = new stdClass();
  $pane->pid = 'new-dc34cff6-2753-4761-9488-6dcd2062bad7';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-Gj3vZUW0Rn8qj4cRmT3iTpzD0M9jF5D6';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Community',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dc34cff6-2753-4761-9488-6dcd2062bad7';
  $display->content['new-dc34cff6-2753-4761-9488-6dcd2062bad7'] = $pane;
  $display->panels['right'][1] = 'new-dc34cff6-2753-4761-9488-6dcd2062bad7';
  $pane = new stdClass();
  $pane->pid = 'new-e5b7cbe5-1fd0-4149-b689-73c9aa070be9';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-B9Y1914fi53ViZQDzGYKMTOLNRa91P6M';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Collection',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e5b7cbe5-1fd0-4149-b689-73c9aa070be9';
  $display->content['new-e5b7cbe5-1fd0-4149-b689-73c9aa070be9'] = $pane;
  $display->panels['right'][2] = 'new-e5b7cbe5-1fd0-4149-b689-73c9aa070be9';
  $pane = new stdClass();
  $pane->pid = 'new-017e03f2-9240-4b7e-af9f-78606aeab0c5';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-W6Y01TnXzLiqUKc7f9pIbDZKgyVZ0i1g';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Category',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '017e03f2-9240-4b7e-af9f-78606aeab0c5';
  $display->content['new-017e03f2-9240-4b7e-af9f-78606aeab0c5'] = $pane;
  $display->panels['right'][3] = 'new-017e03f2-9240-4b7e-af9f-78606aeab0c5';
  $pane = new stdClass();
  $pane->pid = 'new-ce0544ae-e26a-475d-b91e-31f30e01a30d';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-6Ldp5zx9fAnaRtQHglU51ONNmrHP2CtK';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Media Type',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ce0544ae-e26a-475d-b91e-31f30e01a30d';
  $display->content['new-ce0544ae-e26a-475d-b91e-31f30e01a30d'] = $pane;
  $display->panels['right'][4] = 'new-ce0544ae-e26a-475d-b91e-31f30e01a30d';
  $pane = new stdClass();
  $pane->pid = 'new-1776b3c5-7697-4d48-8224-7e2c2b2de9c0';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-IPaCM7H1dF7Clj1WBtiZQw516MCvTYka';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Keywords',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '1776b3c5-7697-4d48-8224-7e2c2b2de9c0';
  $display->content['new-1776b3c5-7697-4d48-8224-7e2c2b2de9c0'] = $pane;
  $display->panels['right'][5] = 'new-1776b3c5-7697-4d48-8224-7e2c2b2de9c0';
  $pane = new stdClass();
  $pane->pid = 'new-663b2429-ba94-4088-94e0-05dacc2425d3';
  $pane->panel = 'right';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '663b2429-ba94-4088-94e0-05dacc2425d3';
  $display->content['new-663b2429-ba94-4088-94e0-05dacc2425d3'] = $pane;
  $display->panels['right'][6] = 'new-663b2429-ba94-4088-94e0-05dacc2425d3';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['single_dh_browse_page'] = $page;

  return $pages;

}
