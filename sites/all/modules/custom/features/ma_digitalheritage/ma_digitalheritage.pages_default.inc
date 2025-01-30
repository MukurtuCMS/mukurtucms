<?php

/**
 * @file
 * ma_digitalheritage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ma_digitalheritage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'digital_heritage_browse';
  $page->task = 'page';
  $page->admin_title = 'Digital Heritage Browse';
  $page->admin_description = '';
  $page->path = 'digital-heritage';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'logged-in-user',
        'name' => 'perm',
        'not' => FALSE,
        'settings' => array(
          'perm' => 'access content',
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'menu-browse-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'Browse Digital Heritage',
    'type' => 'none',
    'weight' => '0',
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_digital_heritage_browse_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'digital_heritage_browse';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'not' => FALSE,
          'settings' => array(
            'description' => '',
            'php' => 'if ($_COOKIE[\'dh_browse_mode\'] <> \'map-view\') return TRUE;',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'grid-list',
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
        ),
        'contains' => 'column',
        'parent' => NULL,
        'type' => 'row',
      ),
      'center' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'Left',
        'type' => 'region',
        'width' => '69.9671129903688',
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'center',
          1 => 'right',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'right' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'Right',
        'type' => 'region',
        'width' => '30.0328870096312',
        'width_type' => '%',
      ),
    ),
  );
  $display->panel_settings = array(
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'style_settings' => array(
      'bottom' => NULL,
      'center' => NULL,
      'center_' => NULL,
      'default' => NULL,
      'left' => array(
        'column' => array(
          'lg' => '0',
          'md' => '3',
          'sm' => '4',
          'xs' => '12',
        ),
        'css_class' => '',
        'css_id' => '',
        'offset' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'pull' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'push' => array(
          'lg' => '0',
          'md' => '9',
          'sm' => '8',
          'xs' => '0',
        ),
      ),
      'right' => array(
        'column' => array(
          'lg' => '0',
          'md' => '9',
          'sm' => '8',
          'xs' => '12',
        ),
        'css_class' => '',
        'css_id' => '',
        'offset' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'pull' => array(
          'lg' => '0',
          'md' => '3',
          'sm' => '4',
          'xs' => '0',
        ),
        'push' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
      ),
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Digital Heritage';
  $display->uuid = '24bcf2ea-02cc-4d74-bace-67910f710d6d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_digital_heritage_browse_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6c119b7c-db07-4516-a837-7a2d9b1bac33';
  $pane->panel = 'left';
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
  $pane->uuid = '6c119b7c-db07-4516-a837-7a2d9b1bac33';
  $display->content['new-6c119b7c-db07-4516-a837-7a2d9b1bac33'] = $pane;
  $display->panels['left'][0] = 'new-6c119b7c-db07-4516-a837-7a2d9b1bac33';
  $pane = new stdClass();
  $pane->pid = 'new-8a8e267f-b314-49a2-b302-7733e2c3d5d7';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'ma_search_api-ma_custom_sorts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Sort by',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8a8e267f-b314-49a2-b302-7733e2c3d5d7';
  $display->content['new-8a8e267f-b314-49a2-b302-7733e2c3d5d7'] = $pane;
  $display->panels['left'][1] = 'new-8a8e267f-b314-49a2-b302-7733e2c3d5d7';
  $pane = new stdClass();
  $pane->pid = 'new-e48911e6-4193-46a0-b098-cf99c8fff402';
  $pane->panel = 'left';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e48911e6-4193-46a0-b098-cf99c8fff402';
  $display->content['new-e48911e6-4193-46a0-b098-cf99c8fff402'] = $pane;
  $display->panels['left'][2] = 'new-e48911e6-4193-46a0-b098-cf99c8fff402';
  $pane = new stdClass();
  $pane->pid = 'new-afdbb213-6d9a-4279-ad64-095e8827c08d';
  $pane->panel = 'left';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'afdbb213-6d9a-4279-ad64-095e8827c08d';
  $display->content['new-afdbb213-6d9a-4279-ad64-095e8827c08d'] = $pane;
  $display->panels['left'][3] = 'new-afdbb213-6d9a-4279-ad64-095e8827c08d';
  $pane = new stdClass();
  $pane->pid = 'new-a5b15850-59f2-4cdc-82dd-84bbfa30cca6';
  $pane->panel = 'left';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a5b15850-59f2-4cdc-82dd-84bbfa30cca6';
  $display->content['new-a5b15850-59f2-4cdc-82dd-84bbfa30cca6'] = $pane;
  $display->panels['left'][4] = 'new-a5b15850-59f2-4cdc-82dd-84bbfa30cca6';
  $pane = new stdClass();
  $pane->pid = 'new-2b11112e-39ed-4cc0-9eb2-1ab56b64fc8e';
  $pane->panel = 'left';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '2b11112e-39ed-4cc0-9eb2-1ab56b64fc8e';
  $display->content['new-2b11112e-39ed-4cc0-9eb2-1ab56b64fc8e'] = $pane;
  $display->panels['left'][5] = 'new-2b11112e-39ed-4cc0-9eb2-1ab56b64fc8e';
  $pane = new stdClass();
  $pane->pid = 'new-63bd75bf-67c5-4bd2-a1c4-1690fc9dc556';
  $pane->panel = 'left';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '63bd75bf-67c5-4bd2-a1c4-1690fc9dc556';
  $display->content['new-63bd75bf-67c5-4bd2-a1c4-1690fc9dc556'] = $pane;
  $display->panels['left'][6] = 'new-63bd75bf-67c5-4bd2-a1c4-1690fc9dc556';
  $pane = new stdClass();
  $pane->pid = 'new-098bdedb-a93d-4fef-a1ac-a416de23aa60';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'digital_heritage_grid_list-all';
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
  $pane->uuid = '098bdedb-a93d-4fef-a1ac-a416de23aa60';
  $display->content['new-098bdedb-a93d-4fef-a1ac-a416de23aa60'] = $pane;
  $display->panels['right'][0] = 'new-098bdedb-a93d-4fef-a1ac-a416de23aa60';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_digital_heritage_browse__map';
  $handler->task = 'page';
  $handler->subtask = 'digital_heritage_browse';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'not' => FALSE,
          'settings' => array(
            'description' => '',
            'php' => 'if ($_COOKIE[\'dh_browse_mode\'] == \'map-view\') return TRUE;',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'map',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'map',
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
        ),
        'contains' => 'column',
        'parent' => NULL,
        'type' => 'row',
      ),
      'center' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'Left',
        'type' => 'region',
        'width' => '69.9671129903688',
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'center',
          1 => 'right',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'right' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'Right',
        'type' => 'region',
        'width' => '30.0328870096312',
        'width_type' => '%',
      ),
    ),
  );
  $display->panel_settings = array(
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'style_settings' => array(
      'bottom' => NULL,
      'center' => NULL,
      'center_' => NULL,
      'default' => NULL,
      'left' => array(
        'column' => array(
          'lg' => '0',
          'md' => '3',
          'sm' => '4',
          'xs' => '12',
        ),
        'css_class' => '',
        'css_id' => '',
        'offset' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'pull' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'push' => array(
          'lg' => '0',
          'md' => '9',
          'sm' => '8',
          'xs' => '0',
        ),
      ),
      'right' => array(
        'column' => array(
          'lg' => '0',
          'md' => '9',
          'sm' => '8',
          'xs' => '12',
        ),
        'css_class' => '',
        'css_id' => '',
        'offset' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'pull' => array(
          'lg' => '0',
          'md' => '3',
          'sm' => '4',
          'xs' => '0',
        ),
        'push' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
      ),
      'top' => array(
        'column' => array(
          'lg' => '0',
          'md' => '3',
          'sm' => '4',
          'xs' => '12',
        ),
        'css_class' => '',
        'css_id' => '',
        'offset' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'pull' => array(
          'lg' => '0',
          'md' => '0',
          'sm' => '0',
          'xs' => '0',
        ),
        'push' => array(
          'lg' => '0',
          'md' => '9',
          'sm' => '8',
          'xs' => '0',
        ),
      ),
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Digital Heritage';
  $display->uuid = 'ec86842b-dca2-4773-9bee-be7ede7eed66';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_digital_heritage_browse__map';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6073cbed-b276-4931-be5b-b418f191b1da';
  $pane->panel = 'left';
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
  $display->panels['left'][0] = 'new-6073cbed-b276-4931-be5b-b418f191b1da';
  $pane = new stdClass();
  $pane->pid = 'new-dc34cff6-2753-4761-9488-6dcd2062bad7';
  $pane->panel = 'left';
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
  $display->panels['left'][1] = 'new-dc34cff6-2753-4761-9488-6dcd2062bad7';
  $pane = new stdClass();
  $pane->pid = 'new-e5b7cbe5-1fd0-4149-b689-73c9aa070be9';
  $pane->panel = 'left';
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
  $display->panels['left'][2] = 'new-e5b7cbe5-1fd0-4149-b689-73c9aa070be9';
  $pane = new stdClass();
  $pane->pid = 'new-017e03f2-9240-4b7e-af9f-78606aeab0c5';
  $pane->panel = 'left';
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
  $display->panels['left'][3] = 'new-017e03f2-9240-4b7e-af9f-78606aeab0c5';
  $pane = new stdClass();
  $pane->pid = 'new-ce0544ae-e26a-475d-b91e-31f30e01a30d';
  $pane->panel = 'left';
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
  $display->panels['left'][4] = 'new-ce0544ae-e26a-475d-b91e-31f30e01a30d';
  $pane = new stdClass();
  $pane->pid = 'new-1776b3c5-7697-4d48-8224-7e2c2b2de9c0';
  $pane->panel = 'left';
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
  $display->panels['left'][5] = 'new-1776b3c5-7697-4d48-8224-7e2c2b2de9c0';
  $pane = new stdClass();
  $pane->pid = 'new-bb3451b9-027e-415e-9dc8-926a7680ddcb';
  $pane->panel = 'right';
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
  $display->panels['right'][0] = 'new-bb3451b9-027e-415e-9dc8-926a7680ddcb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['digital_heritage_browse'] = $page;

  return $pages;

}
