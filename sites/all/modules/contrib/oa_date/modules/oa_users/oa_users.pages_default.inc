<?php
/**
 * @file
 * oa_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function oa_users_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_actitivy';
  $page->task = 'page';
  $page->admin_title = 'user_actitivy';
  $page->admin_description = 'Recent activity from user';
  $page->path = 'user/%user/activity';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access user profiles',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Activity',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user_actitivy_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_actitivy';
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
  $display->layout = 'radix_bryant';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%user:name';
  $display->uuid = '17ecd678-184e-4145-8f01-b2e0027e8b27';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e8325655-b395-490f-bdd3-fe100bd92c0a';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_recent_activity-user_activity';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '20',
    'context' => array(
      0 => 'argument_entity_id:user_1',
    ),
    'view_mode' => 'full',
    'widget_title' => 'Recent Activity',
    'exposed' => array(
      'field_oa_message_space_target_id' => 'All',
      'field_oa_message_section_target_id' => array(),
      'type' => array(),
    ),
    'use_pager' => 1,
    'pager_id' => '',
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
    'view_settings' => 'fields',
    'header_type' => 'none',
    'show_exposed_form' => 1,
    'override_title' => '',
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'oa_styles_oa_pane',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e8325655-b395-490f-bdd3-fe100bd92c0a';
  $display->content['new-e8325655-b395-490f-bdd3-fe100bd92c0a'] = $pane;
  $display->panels['contentmain'][0] = 'new-e8325655-b395-490f-bdd3-fe100bd92c0a';
  $pane = new stdClass();
  $pane->pid = 'new-8ec62ea8-940b-4143-a050-3aa9de481a98';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'panopoly_image_quarter',
      'image_link' => '',
    ),
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
    'view_mode' => NULL,
    'widget_title' => NULL,
    'items_per_page' => NULL,
    'exposed' => array(
      'sort_by' => NULL,
      'sort_order' => NULL,
    ),
    'use_pager' => NULL,
    'pager_id' => NULL,
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8ec62ea8-940b-4143-a050-3aa9de481a98';
  $display->content['new-8ec62ea8-940b-4143-a050-3aa9de481a98'] = $pane;
  $display->panels['sidebar'][0] = 'new-8ec62ea8-940b-4143-a050-3aa9de481a98';
  $pane = new stdClass();
  $pane->pid = 'new-c04f3f8b-1b0d-4bcf-9a12-c0f2aac599a7';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_user_about';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
    'view_mode' => NULL,
    'widget_title' => NULL,
    'items_per_page' => NULL,
    'exposed' => array(
      'sort_by' => NULL,
      'sort_order' => NULL,
    ),
    'use_pager' => NULL,
    'pager_id' => NULL,
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
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
  $pane->uuid = 'c04f3f8b-1b0d-4bcf-9a12-c0f2aac599a7';
  $display->content['new-c04f3f8b-1b0d-4bcf-9a12-c0f2aac599a7'] = $pane;
  $display->panels['sidebar'][1] = 'new-c04f3f8b-1b0d-4bcf-9a12-c0f2aac599a7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_actitivy'] = $page;

  return $pages;

}
