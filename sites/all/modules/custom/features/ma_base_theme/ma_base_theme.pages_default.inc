<?php

/**
 * @file
 * ma_base_theme.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ma_base_theme_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'browse_all_content';
  $page->task = 'page';
  $page->admin_title = 'Browse All Content';
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
  $handler->name = 'page_browse_all_content__panel_context_4df1fadf-c119-4662-b498-162567a2c520';
  $handler->task = 'page';
  $handler->subtask = 'browse_all_content';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'grid-list',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => '',
            'php' => 'if ($_COOKIE[\'dh_browse_mode\'] <> \'map-view\') return TRUE;',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
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
      'left' => array(
        'css_id' => '',
        'css_class' => '',
        'column' => array(
          'xs' => '12',
          'sm' => '4',
          'md' => '3',
          'lg' => '0',
        ),
        'offset' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
        'push' => array(
          'xs' => '0',
          'sm' => '8',
          'md' => '9',
          'lg' => '0',
        ),
        'pull' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
      ),
      'right' => array(
        'css_id' => '',
        'css_class' => '',
        'column' => array(
          'xs' => '12',
          'sm' => '8',
          'md' => '9',
          'lg' => '0',
        ),
        'offset' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
        'push' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
        'pull' => array(
          'xs' => '0',
          'sm' => '4',
          'md' => '3',
          'lg' => '0',
        ),
      ),
      'center_' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Browse';
  $display->uuid = '24bcf2ea-02cc-4d74-bace-67910f710d6d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_browse_all_content__panel_context_4df1fadf-c119-4662-b498-162567a2c520';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5032a8bf-e70f-4c35-bd01-e768627e6e91';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-browse_all_content-all';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_text' => 'Search',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5032a8bf-e70f-4c35-bd01-e768627e6e91';
  $display->content['new-5032a8bf-e70f-4c35-bd01-e768627e6e91'] = $pane;
  $display->panels['left'][0] = 'new-5032a8bf-e70f-4c35-bd01-e768627e6e91';
  $pane = new stdClass();
  $pane->pid = 'new-8a8e267f-b314-49a2-b302-7733e2c3d5d7';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'ma_search_api-ma_custom_sorts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => 'Sort by',
    'override_title_heading' => 'h2',
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
  $pane->pid = 'new-1af0b978-5cc2-437f-b33e-cd58dd977e70';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Content Type',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1af0b978-5cc2-437f-b33e-cd58dd977e70';
  $display->content['new-1af0b978-5cc2-437f-b33e-cd58dd977e70'] = $pane;
  $display->panels['left'][2] = 'new-1af0b978-5cc2-437f-b33e-cd58dd977e70';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e48911e6-4193-46a0-b098-cf99c8fff402';
  $display->content['new-e48911e6-4193-46a0-b098-cf99c8fff402'] = $pane;
  $display->panels['left'][3] = 'new-e48911e6-4193-46a0-b098-cf99c8fff402';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'afdbb213-6d9a-4279-ad64-095e8827c08d';
  $display->content['new-afdbb213-6d9a-4279-ad64-095e8827c08d'] = $pane;
  $display->panels['left'][4] = 'new-afdbb213-6d9a-4279-ad64-095e8827c08d';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a5b15850-59f2-4cdc-82dd-84bbfa30cca6';
  $display->content['new-a5b15850-59f2-4cdc-82dd-84bbfa30cca6'] = $pane;
  $display->panels['left'][5] = 'new-a5b15850-59f2-4cdc-82dd-84bbfa30cca6';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '2b11112e-39ed-4cc0-9eb2-1ab56b64fc8e';
  $display->content['new-2b11112e-39ed-4cc0-9eb2-1ab56b64fc8e'] = $pane;
  $display->panels['left'][6] = 'new-2b11112e-39ed-4cc0-9eb2-1ab56b64fc8e';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '63bd75bf-67c5-4bd2-a1c4-1690fc9dc556';
  $display->content['new-63bd75bf-67c5-4bd2-a1c4-1690fc9dc556'] = $pane;
  $display->panels['left'][7] = 'new-63bd75bf-67c5-4bd2-a1c4-1690fc9dc556';
  $pane = new stdClass();
  $pane->pid = 'new-f1fb0100-495c-41e7-9475-e8cef7e754f6';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'browse_all_content-all';
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
  $pane->uuid = 'f1fb0100-495c-41e7-9475-e8cef7e754f6';
  $display->content['new-f1fb0100-495c-41e7-9475-e8cef7e754f6'] = $pane;
  $display->panels['right'][0] = 'new-f1fb0100-495c-41e7-9475-e8cef7e754f6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_browse_all_content__panel_context_709c9b38-cca2-469e-8fd6-dc59ba0a1525';
  $handler->task = 'page';
  $handler->subtask = 'browse_all_content';
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
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => '',
            'php' => 'if ($_COOKIE[\'dh_browse_mode\'] == \'map-view\') return TRUE;',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
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
      'left' => array(
        'css_id' => '',
        'css_class' => '',
        'column' => array(
          'xs' => '12',
          'sm' => '4',
          'md' => '3',
          'lg' => '0',
        ),
        'offset' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
        'push' => array(
          'xs' => '0',
          'sm' => '8',
          'md' => '9',
          'lg' => '0',
        ),
        'pull' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
      ),
      'right' => array(
        'css_id' => '',
        'css_class' => '',
        'column' => array(
          'xs' => '12',
          'sm' => '8',
          'md' => '9',
          'lg' => '0',
        ),
        'offset' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
        'push' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
        'pull' => array(
          'xs' => '0',
          'sm' => '4',
          'md' => '3',
          'lg' => '0',
        ),
      ),
      'center_' => NULL,
      'top' => array(
        'css_id' => '',
        'css_class' => '',
        'column' => array(
          'xs' => '12',
          'sm' => '4',
          'md' => '3',
          'lg' => '0',
        ),
        'offset' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
        'push' => array(
          'xs' => '0',
          'sm' => '8',
          'md' => '9',
          'lg' => '0',
        ),
        'pull' => array(
          'xs' => '0',
          'sm' => '0',
          'md' => '0',
          'lg' => '0',
        ),
      ),
      'bottom' => NULL,
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Digital Heritage';
  $display->uuid = 'ec86842b-dca2-4773-9bee-be7ede7eed66';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_browse_all_content__panel_context_709c9b38-cca2-469e-8fd6-dc59ba0a1525';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7a118868-5355-4b7e-af4c-0df8224a6106';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-browse_all_content-all';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7a118868-5355-4b7e-af4c-0df8224a6106';
  $display->content['new-7a118868-5355-4b7e-af4c-0df8224a6106'] = $pane;
  $display->panels['left'][0] = 'new-7a118868-5355-4b7e-af4c-0df8224a6106';
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
  $pane->pid = 'new-a2305874-25de-43f9-8c62-dedc168df485';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Content Type',
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
  $pane->uuid = 'a2305874-25de-43f9-8c62-dedc168df485';
  $display->content['new-a2305874-25de-43f9-8c62-dedc168df485'] = $pane;
  $display->panels['left'][6] = 'new-a2305874-25de-43f9-8c62-dedc168df485';
  $pane = new stdClass();
  $pane->pid = 'new-03d6df36-648d-4212-9c28-742854d931d8';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'browse_all_content-all_map';
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
  $pane->uuid = '03d6df36-648d-4212-9c28-742854d931d8';
  $display->content['new-03d6df36-648d-4212-9c28-742854d931d8'] = $pane;
  $display->panels['right'][0] = 'new-03d6df36-648d-4212-9c28-742854d931d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['browse_all_content'] = $page;

  return $pages;

}
