<?php

/**
 * @file
 * ma_community_manage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ma_community_manage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'admin_dashboard_communities';
  $page->task = 'page';
  $page->admin_title = 'Admin Dashboard Communities';
  $page->admin_description = '';
  $page->path = 'dashboard/communities';
  $page->access = array(
    'logic' => 'and',
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
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_admin_dashboard_communities_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'admin_dashboard_communities';
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
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Admin Communities';
  $display->uuid = '244b9463-99be-4358-b123-148f830f9483';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_admin_dashboard_communities_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-537ee9c8-5566-4795-9bad-f0d668807272';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views-communities_structure-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '537ee9c8-5566-4795-9bad-f0d668807272';
  $display->content['new-537ee9c8-5566-4795-9bad-f0d668807272'] = $pane;
  $display->panels['center'][0] = 'new-537ee9c8-5566-4795-9bad-f0d668807272';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['admin_dashboard_communities'] = $page;

  return $pages;

}
