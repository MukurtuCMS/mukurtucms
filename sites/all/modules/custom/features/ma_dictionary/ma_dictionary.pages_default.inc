<?php

/**
 * @file
 * ma_dictionary.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ma_dictionary_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dictionary_browse';
  $page->task = 'page';
  $page->admin_title = 'Dictionary Browse';
  $page->admin_description = '';
  $page->path = 'dictionary';
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
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = TRUE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dictionary_browse__panel_context_3b1b1956-d62b-4fab-880d-23a0810f73af';
  $handler->task = 'page';
  $handler->subtask = 'dictionary_browse';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
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
    'style_settings' => array(
      'center' => NULL,
      'center_' => NULL,
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'sort' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Dictionary';
  $display->uuid = '388dbfc4-8d69-4c3e-acbc-9ca6d6862526';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dictionary_browse__panel_context_3b1b1956-d62b-4fab-880d-23a0810f73af';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e6bce864-13f6-4b13-983a-abce5169f5d1';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'dictionary_words-all';
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
  $pane->uuid = 'e6bce864-13f6-4b13-983a-abce5169f5d1';
  $display->content['new-e6bce864-13f6-4b13-983a-abce5169f5d1'] = $pane;
  $display->panels['center'][0] = 'new-e6bce864-13f6-4b13-983a-abce5169f5d1';
  $pane = new stdClass();
  $pane->pid = 'new-26b93ec4-5e74-41c2-afac-74e74c21b336';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-dictionary_words-all';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '26b93ec4-5e74-41c2-afac-74e74c21b336';
  $display->content['new-26b93ec4-5e74-41c2-afac-74e74c21b336'] = $pane;
  $display->panels['right'][0] = 'new-26b93ec4-5e74-41c2-afac-74e74c21b336';
  $pane = new stdClass();
  $pane->pid = 'new-7c3cd695-0acc-4d50-a278-8f4668daae15';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'search_api_sorts-search-sorts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '7c3cd695-0acc-4d50-a278-8f4668daae15';
  $display->content['new-7c3cd695-0acc-4d50-a278-8f4668daae15'] = $pane;
  $display->panels['right'][1] = 'new-7c3cd695-0acc-4d50-a278-8f4668daae15';
  $pane = new stdClass();
  $pane->pid = 'new-073b3bf5-9165-4d50-b532-8ec26bb49807';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-j4ofkY8Mm2DXhtD0cJlPexdUQ4v5sH7l';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Title',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '073b3bf5-9165-4d50-b532-8ec26bb49807';
  $display->content['new-073b3bf5-9165-4d50-b532-8ec26bb49807'] = $pane;
  $display->panels['right'][2] = 'new-073b3bf5-9165-4d50-b532-8ec26bb49807';
  $pane = new stdClass();
  $pane->pid = 'new-76ec807b-75d0-4438-b12c-2619e12211da';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-ouKoXsqCwerg0QTUdl8QMqWGs15NtJKc';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Language',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '76ec807b-75d0-4438-b12c-2619e12211da';
  $display->content['new-76ec807b-75d0-4438-b12c-2619e12211da'] = $pane;
  $display->panels['right'][3] = 'new-76ec807b-75d0-4438-b12c-2619e12211da';
  $pane = new stdClass();
  $pane->pid = 'new-7fec3237-0e7d-4e45-95ff-e1c9fbfadc80';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-IPaCM7H1dF7Clj1WBtiZQw516MCvTYka';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Keywords',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7fec3237-0e7d-4e45-95ff-e1c9fbfadc80';
  $display->content['new-7fec3237-0e7d-4e45-95ff-e1c9fbfadc80'] = $pane;
  $display->panels['right'][4] = 'new-7fec3237-0e7d-4e45-95ff-e1c9fbfadc80';
  $pane = new stdClass();
  $pane->pid = 'new-f41bd9f8-c25f-4aed-9340-ce0c83257469';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-K69pQqakWYP7PdiK9WmOOmTW3V5z0fxx';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Part of Speech',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f41bd9f8-c25f-4aed-9340-ce0c83257469';
  $display->content['new-f41bd9f8-c25f-4aed-9340-ce0c83257469'] = $pane;
  $display->panels['right'][5] = 'new-f41bd9f8-c25f-4aed-9340-ce0c83257469';
  $pane = new stdClass();
  $pane->pid = 'new-9b1c73d3-1eaa-42a3-a05b-89e0e2db207e';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-hllvj31fytBpciVb7gPV1cfmTaoRBjC0';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Word Lists',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '9b1c73d3-1eaa-42a3-a05b-89e0e2db207e';
  $display->content['new-9b1c73d3-1eaa-42a3-a05b-89e0e2db207e'] = $pane;
  $display->panels['right'][6] = 'new-9b1c73d3-1eaa-42a3-a05b-89e0e2db207e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dictionary_browse__dictionary-browse-theme-v2';
  $handler->task = 'page';
  $handler->subtask = 'dictionary_browse';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'dictionary-browse-theme-v2',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Dictionary Browse Theme v2',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
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
        'hide_empty' => 0,
        'parent' => 'main-row',
        'title' => 'Dictionary Words',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'center',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'search_facets' => array(
        'class' => 'dictionary-facets-region',
        'hide_empty' => 0,
        'parent' => '1',
        'title' => 'Search Facets',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 'search_facets',
        ),
        'class' => 'dictionary-facets',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $display->panel_settings = array(
    'center' => array(
      'style' => 'default',
    ),
    'search_facets' => array(
      'style' => 'default',
    ),
    'style_settings' => array(
      'center' => NULL,
      'center_' => NULL,
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'search_facets' => NULL,
      'sort' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Dictionary';
  $display->uuid = '388dbfc4-8d69-4c3e-acbc-9ca6d6862526';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dictionary_browse__dictionary-browse-theme-v2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-073b3bf5-9165-4d50-b532-8ec26bb49807';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-j4ofkY8Mm2DXhtD0cJlPexdUQ4v5sH7l';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Title',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'facet-glossary',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '073b3bf5-9165-4d50-b532-8ec26bb49807';
  $display->content['new-073b3bf5-9165-4d50-b532-8ec26bb49807'] = $pane;
  $display->panels['center'][0] = 'new-073b3bf5-9165-4d50-b532-8ec26bb49807';
  $pane = new stdClass();
  $pane->pid = 'new-06ab722a-ad48-4247-9610-3de27dedfbf0';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'dictionary_words-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '06ab722a-ad48-4247-9610-3de27dedfbf0';
  $display->content['new-06ab722a-ad48-4247-9610-3de27dedfbf0'] = $pane;
  $display->panels['center'][1] = 'new-06ab722a-ad48-4247-9610-3de27dedfbf0';
  $pane = new stdClass();
  $pane->pid = 'new-7c3cd695-0acc-4d50-a278-8f4668daae15';
  $pane->panel = 'search_facets';
  $pane->type = 'block';
  $pane->subtype = 'search_api_sorts-search-sorts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Sort by',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7c3cd695-0acc-4d50-a278-8f4668daae15';
  $display->content['new-7c3cd695-0acc-4d50-a278-8f4668daae15'] = $pane;
  $display->panels['search_facets'][0] = 'new-7c3cd695-0acc-4d50-a278-8f4668daae15';
  $pane = new stdClass();
  $pane->pid = 'new-76ec807b-75d0-4438-b12c-2619e12211da';
  $pane->panel = 'search_facets';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-ouKoXsqCwerg0QTUdl8QMqWGs15NtJKc';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Language',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '76ec807b-75d0-4438-b12c-2619e12211da';
  $display->content['new-76ec807b-75d0-4438-b12c-2619e12211da'] = $pane;
  $display->panels['search_facets'][1] = 'new-76ec807b-75d0-4438-b12c-2619e12211da';
  $pane = new stdClass();
  $pane->pid = 'new-7fec3237-0e7d-4e45-95ff-e1c9fbfadc80';
  $pane->panel = 'search_facets';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-IPaCM7H1dF7Clj1WBtiZQw516MCvTYka';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Keywords',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7fec3237-0e7d-4e45-95ff-e1c9fbfadc80';
  $display->content['new-7fec3237-0e7d-4e45-95ff-e1c9fbfadc80'] = $pane;
  $display->panels['search_facets'][2] = 'new-7fec3237-0e7d-4e45-95ff-e1c9fbfadc80';
  $pane = new stdClass();
  $pane->pid = 'new-f41bd9f8-c25f-4aed-9340-ce0c83257469';
  $pane->panel = 'search_facets';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-K69pQqakWYP7PdiK9WmOOmTW3V5z0fxx';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Part of Speech',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f41bd9f8-c25f-4aed-9340-ce0c83257469';
  $display->content['new-f41bd9f8-c25f-4aed-9340-ce0c83257469'] = $pane;
  $display->panels['search_facets'][3] = 'new-f41bd9f8-c25f-4aed-9340-ce0c83257469';
  $pane = new stdClass();
  $pane->pid = 'new-9b1c73d3-1eaa-42a3-a05b-89e0e2db207e';
  $pane->panel = 'search_facets';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-hllvj31fytBpciVb7gPV1cfmTaoRBjC0';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Word Lists',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9b1c73d3-1eaa-42a3-a05b-89e0e2db207e';
  $display->content['new-9b1c73d3-1eaa-42a3-a05b-89e0e2db207e'] = $pane;
  $display->panels['search_facets'][4] = 'new-9b1c73d3-1eaa-42a3-a05b-89e0e2db207e';
  $pane = new stdClass();
  $pane->pid = 'new-26b93ec4-5e74-41c2-afac-74e74c21b336';
  $pane->panel = 'search_facets';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-dictionary_words-all';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Search',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '26b93ec4-5e74-41c2-afac-74e74c21b336';
  $display->content['new-26b93ec4-5e74-41c2-afac-74e74c21b336'] = $pane;
  $display->panels['search_facets'][5] = 'new-26b93ec4-5e74-41c2-afac-74e74c21b336';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dictionary_browse'] = $page;

  return $pages;

}
