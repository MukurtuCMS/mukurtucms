<?php
/**
 * @file
 * ma_community_manage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ma_community_manage_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Community',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '9726da91-c7f6-4417-8ff9-3d8ac436e0dc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9592a742-43d7-4532-ad43-c3cf2c60029f';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'mukurtu_splash-mukurtu_group_management';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'management-links',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9592a742-43d7-4532-ad43-c3cf2c60029f';
  $display->content['new-9592a742-43d7-4532-ad43-c3cf2c60029f'] = $pane;
  $display->panels['left'][0] = 'new-9592a742-43d7-4532-ad43-c3cf2c60029f';
  $pane = new stdClass();
  $pane->pid = 'new-0da92637-289e-4a07-b185-d847457576c6';
  $pane->panel = 'left';
  $pane->type = 'token';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'sanitize' => 1,
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0da92637-289e-4a07-b185-d847457576c6';
  $display->content['new-0da92637-289e-4a07-b185-d847457576c6'] = $pane;
  $display->panels['left'][1] = 'new-0da92637-289e-4a07-b185-d847457576c6';
  $pane = new stdClass();
  $pane->pid = 'new-49f106ca-e064-422b-868c-fb1b74e91080';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_parent_community';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '49f106ca-e064-422b-868c-fb1b74e91080';
  $display->content['new-49f106ca-e064-422b-868c-fb1b74e91080'] = $pane;
  $display->panels['left'][2] = 'new-49f106ca-e064-422b-868c-fb1b74e91080';
  $pane = new stdClass();
  $pane->pid = 'new-dbf1c0cd-d49a-440f-959d-88ef2fe27541';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_child_communities';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'textformatter_list',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
      'textformatter_type' => 'comma',
      'textformatter_class' => 'textformatter-list',
      'textformatter_comma_full_stop' => 0,
      'textformatter_comma_and' => 0,
      'textformatter_comma_tag' => 'div',
      'textformatter_comma_override' => 0,
      'textformatter_separator_custom' => '',
      'textformatter_separator_custom_tag' => 'span',
      'textformatter_separator_custom_class' => 'textformatter-separator',
      'textformatter_contrib' => array(
        'entityreference_link' => 1,
      ),
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'dbf1c0cd-d49a-440f-959d-88ef2fe27541';
  $display->content['new-dbf1c0cd-d49a-440f-959d-88ef2fe27541'] = $pane;
  $display->panels['left'][3] = 'new-dbf1c0cd-d49a-440f-959d-88ef2fe27541';
  $pane = new stdClass();
  $pane->pid = 'new-7c3a642c-0cfa-461e-b308-dcee669d3954';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'community_dh_items-community';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_community_ref_nid' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7c3a642c-0cfa-461e-b308-dcee669d3954';
  $display->content['new-7c3a642c-0cfa-461e-b308-dcee669d3954'] = $pane;
  $display->panels['left'][4] = 'new-7c3a642c-0cfa-461e-b308-dcee669d3954';
  $pane = new stdClass();
  $pane->pid = 'new-3f1568a3-d435-4a7a-9dc8-7cb3168555dd';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_members-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => 'Members',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-pane',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3f1568a3-d435-4a7a-9dc8-7cb3168555dd';
  $display->content['new-3f1568a3-d435-4a7a-9dc8-7cb3168555dd'] = $pane;
  $display->panels['right'][0] = 'new-3f1568a3-d435-4a7a-9dc8-7cb3168555dd';
  $pane = new stdClass();
  $pane->pid = 'new-f7b83a63-fda5-4319-bf0a-86d91fa53c44';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'community_protocol_items-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'gid' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-pane',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f7b83a63-fda5-4319-bf0a-86d91fa53c44';
  $display->content['new-f7b83a63-fda5-4319-bf0a-86d91fa53c44'] = $pane;
  $display->panels['right'][1] = 'new-f7b83a63-fda5-4319-bf0a-86d91fa53c44';
  $pane = new stdClass();
  $pane->pid = 'new-dc575ae8-070e-4be9-bc68-be281646b2dd';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_community_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'mukurtu_scald_banner_image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => '0',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'dc575ae8-070e-4be9-bc68-be281646b2dd';
  $display->content['new-dc575ae8-070e-4be9-bc68-be281646b2dd'] = $pane;
  $display->panels['top'][0] = 'new-dc575ae8-070e-4be9-bc68-be281646b2dd';
  $pane = new stdClass();
  $pane->pid = 'new-32418e10-b0bb-49e1-bb5e-9acd0f7c324a';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:group_group';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'og_group_subscribe',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'field_name' => 'og_user_node',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '32418e10-b0bb-49e1-bb5e-9acd0f7c324a';
  $display->content['new-32418e10-b0bb-49e1-bb5e-9acd0f7c324a'] = $pane;
  $display->panels['top'][1] = 'new-32418e10-b0bb-49e1-bb5e-9acd0f7c324a';
  $pane = new stdClass();
  $pane->pid = 'new-85af5eb5-c767-49f3-87f1-7fb43b6a938e';
  $pane->panel = 'top';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h2',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '85af5eb5-c767-49f3-87f1-7fb43b6a938e';
  $display->content['new-85af5eb5-c767-49f3-87f1-7fb43b6a938e'] = $pane;
  $display->panels['top'][2] = 'new-85af5eb5-c767-49f3-87f1-7fb43b6a938e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}

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
