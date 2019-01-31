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
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
    'override_title_text' => 'Title',
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
    'override_title_text' => 'Language',
    'override_title_heading' => 'h2',
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
    'override_title_text' => 'Keywords',
    'override_title_heading' => 'h2',
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
    'override_title_text' => 'Part of Speech',
    'override_title_heading' => 'h2',
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
    'override_title_text' => 'Word Lists',
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
    'title' => 'Dictionary Browse Theme v2',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'dictionary-browse-theme-v2',
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
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Dictionary Words',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'search_facets',
        ),
        'parent' => 'main',
        'class' => 'dictionary-facets',
        'hide_empty' => 0,
      ),
      'search_facets' => array(
        'type' => 'region',
        'title' => 'Search Facets',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'dictionary-facets-region',
        'hide_empty' => 0,
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
      'sort' => NULL,
      'middle' => NULL,
      'search_facets' => NULL,
    ),
    'search_facets' => array(
      'style' => 'default',
    ),
    'center' => array(
      'style' => 'default',
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
    'override_title_text' => 'Title',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'facet-glossary',
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
    'override_title_text' => 'Sort by',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
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
    'override_title_text' => 'Language',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
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
    'override_title_text' => 'Keywords',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
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
    'override_title_text' => 'Part of Speech',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
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
    'override_title_text' => 'Word Lists',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-xs-12 col-md-4 col-lg-3',
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
    'override_title_text' => 'Search',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
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
