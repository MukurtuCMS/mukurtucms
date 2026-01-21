<?php
/**
 * @file
 * oa_layouts.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_layouts_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_2';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Section Edit Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'node-edit',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'oa_section' => 'oa_section',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
    'sidebar' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '563a3f84-c66d-4903-a574-105c0a2c1c73';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-aa634e94-5af3-45d9-b467-95a598e4f927';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
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
  $pane->uuid = 'aa634e94-5af3-45d9-b467-95a598e4f927';
  $display->content['new-aa634e94-5af3-45d9-b467-95a598e4f927'] = $pane;
  $display->panels['contentmain'][0] = 'new-aa634e94-5af3-45d9-b467-95a598e4f927';
  $pane = new stdClass();
  $pane->pid = 'new-5e54bab5-b799-447c-ae08-571ac4ef3583';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_path';
  $pane->subtype = 'node_form_path';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5e54bab5-b799-447c-ae08-571ac4ef3583';
  $display->content['new-5e54bab5-b799-447c-ae08-571ac4ef3583'] = $pane;
  $display->panels['contentmain'][1] = 'new-5e54bab5-b799-447c-ae08-571ac4ef3583';
  $pane = new stdClass();
  $pane->pid = 'new-24ec7526-d8c1-44b2-91df-a6ab6f456c40';
  $pane->panel = 'contentmain';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '24ec7526-d8c1-44b2-91df-a6ab6f456c40';
  $display->content['new-24ec7526-d8c1-44b2-91df-a6ab6f456c40'] = $pane;
  $display->panels['contentmain'][2] = 'new-24ec7526-d8c1-44b2-91df-a6ab6f456c40';
  $pane = new stdClass();
  $pane->pid = 'new-c8298a7c-1893-4af7-95b4-75de4ebc84b6';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_section_override';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c8298a7c-1893-4af7-95b4-75de4ebc84b6';
  $display->content['new-c8298a7c-1893-4af7-95b4-75de4ebc84b6'] = $pane;
  $display->panels['contentmain'][3] = 'new-c8298a7c-1893-4af7-95b4-75de4ebc84b6';
  $pane = new stdClass();
  $pane->pid = 'new-55ea3207-3c38-4668-804a-e3db4f01f978';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_node_types';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '55ea3207-3c38-4668-804a-e3db4f01f978';
  $display->content['new-55ea3207-3c38-4668-804a-e3db4f01f978'] = $pane;
  $display->panels['contentmain'][4] = 'new-55ea3207-3c38-4668-804a-e3db4f01f978';
  $pane = new stdClass();
  $pane->pid = 'new-e22d40ca-611d-4fa7-a864-9d382304006c';
  $pane->panel = 'contentmain';
  $pane->type = 'panelizer_form_default';
  $pane->subtype = 'panelizer_form_default';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'e22d40ca-611d-4fa7-a864-9d382304006c';
  $display->content['new-e22d40ca-611d-4fa7-a864-9d382304006c'] = $pane;
  $display->panels['contentmain'][5] = 'new-e22d40ca-611d-4fa7-a864-9d382304006c';
  $pane = new stdClass();
  $pane->pid = 'new-46cc1635-49e8-4fc4-9308-16c25aa33df5';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_group_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Section Visibility',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '46cc1635-49e8-4fc4-9308-16c25aa33df5';
  $display->content['new-46cc1635-49e8-4fc4-9308-16c25aa33df5'] = $pane;
  $display->panels['sidebar'][0] = 'new-46cc1635-49e8-4fc4-9308-16c25aa33df5';
  $pane = new stdClass();
  $pane->pid = 'new-6e6ee8aa-adff-4dc7-900e-ef9d3f8e75ac';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_team_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6e6ee8aa-adff-4dc7-900e-ef9d3f8e75ac';
  $display->content['new-6e6ee8aa-adff-4dc7-900e-ef9d3f8e75ac'] = $pane;
  $display->panels['sidebar'][1] = 'new-6e6ee8aa-adff-4dc7-900e-ef9d3f8e75ac';
  $pane = new stdClass();
  $pane->pid = 'new-72c0d70a-67ac-4c38-8aaf-77ec8cbd5f6e';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_user_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '72c0d70a-67ac-4c38-8aaf-77ec8cbd5f6e';
  $display->content['new-72c0d70a-67ac-4c38-8aaf-77ec8cbd5f6e'] = $pane;
  $display->panels['sidebar'][2] = 'new-72c0d70a-67ac-4c38-8aaf-77ec8cbd5f6e';
  $pane = new stdClass();
  $pane->pid = 'new-87ab1eca-a386-4079-a448-ca9dd19399b9';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_oa_notifications';
  $pane->subtype = 'node_form_oa_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '87ab1eca-a386-4079-a448-ca9dd19399b9';
  $display->content['new-87ab1eca-a386-4079-a448-ca9dd19399b9'] = $pane;
  $display->panels['sidebar'][3] = 'new-87ab1eca-a386-4079-a448-ca9dd19399b9';
  $pane = new stdClass();
  $pane->pid = 'new-c05d2a58-37bd-4746-8a7b-87f9993ad0bb';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Featured image',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c05d2a58-37bd-4746-8a7b-87f9993ad0bb';
  $display->content['new-c05d2a58-37bd-4746-8a7b-87f9993ad0bb'] = $pane;
  $display->panels['sidebar'][4] = 'new-c05d2a58-37bd-4746-8a7b-87f9993ad0bb';
  $pane = new stdClass();
  $pane->pid = 'new-de50f2a5-e620-4233-9282-63600c09374c';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Content category',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'de50f2a5-e620-4233-9282-63600c09374c';
  $display->content['new-de50f2a5-e620-4233-9282-63600c09374c'] = $pane;
  $display->panels['sidebar'][5] = 'new-de50f2a5-e620-4233-9282-63600c09374c';
  $pane = new stdClass();
  $pane->pid = 'new-d5933ecb-c588-41e4-b034-c32f633858d5';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_menu';
  $pane->subtype = 'node_form_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd5933ecb-c588-41e4-b034-c32f633858d5';
  $display->content['new-d5933ecb-c588-41e4-b034-c32f633858d5'] = $pane;
  $display->panels['sidebar'][6] = 'new-d5933ecb-c588-41e4-b034-c32f633858d5';
  $pane = new stdClass();
  $pane->pid = 'new-c96e32b6-0181-46ef-9766-99aa0fe75da3';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'c96e32b6-0181-46ef-9766-99aa0fe75da3';
  $display->content['new-c96e32b6-0181-46ef-9766-99aa0fe75da3'] = $pane;
  $display->panels['sidebar'][7] = 'new-c96e32b6-0181-46ef-9766-99aa0fe75da3';
  $pane = new stdClass();
  $pane->pid = 'new-58d201ba-93ed-4044-b2d6-5e312c180620';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_author';
  $pane->subtype = 'node_form_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '58d201ba-93ed-4044-b2d6-5e312c180620';
  $display->content['new-58d201ba-93ed-4044-b2d6-5e312c180620'] = $pane;
  $display->panels['sidebar'][8] = 'new-58d201ba-93ed-4044-b2d6-5e312c180620';
  $pane = new stdClass();
  $pane->pid = 'new-5b92ecd3-a44a-40e8-9da0-a826187b64ae';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_comment';
  $pane->subtype = 'node_form_comment';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '5b92ecd3-a44a-40e8-9da0-a826187b64ae';
  $display->content['new-5b92ecd3-a44a-40e8-9da0-a826187b64ae'] = $pane;
  $display->panels['sidebar'][9] = 'new-5b92ecd3-a44a-40e8-9da0-a826187b64ae';
  $pane = new stdClass();
  $pane->pid = 'new-aa9e83a8-3ff8-4b5e-a3af-b22f94e4d4a6';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'aa9e83a8-3ff8-4b5e-a3af-b22f94e4d4a6';
  $display->content['new-aa9e83a8-3ff8-4b5e-a3af-b22f94e4d4a6'] = $pane;
  $display->panels['sidebar'][10] = 'new-aa9e83a8-3ff8-4b5e-a3af-b22f94e4d4a6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_4';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Space Edit Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'node-edit',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'oa_space' => 'oa_space',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
    'sidebar' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9d735f0b-9d0a-47a9-842d-8610092c1ed2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4337c991-7c62-489b-ad38-9c34a794bb10';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
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
  $pane->uuid = '4337c991-7c62-489b-ad38-9c34a794bb10';
  $display->content['new-4337c991-7c62-489b-ad38-9c34a794bb10'] = $pane;
  $display->panels['contentmain'][0] = 'new-4337c991-7c62-489b-ad38-9c34a794bb10';
  $pane = new stdClass();
  $pane->pid = 'new-70872ecc-36ac-4e01-87ba-7b516ac1a29b';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_path';
  $pane->subtype = 'node_form_path';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '70872ecc-36ac-4e01-87ba-7b516ac1a29b';
  $display->content['new-70872ecc-36ac-4e01-87ba-7b516ac1a29b'] = $pane;
  $display->panels['contentmain'][1] = 'new-70872ecc-36ac-4e01-87ba-7b516ac1a29b';
  $pane = new stdClass();
  $pane->pid = 'new-52a2aed5-0553-4b02-90bd-7ce232ce411b';
  $pane->panel = 'contentmain';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '52a2aed5-0553-4b02-90bd-7ce232ce411b';
  $display->content['new-52a2aed5-0553-4b02-90bd-7ce232ce411b'] = $pane;
  $display->panels['contentmain'][2] = 'new-52a2aed5-0553-4b02-90bd-7ce232ce411b';
  $pane = new stdClass();
  $pane->pid = 'new-78d06d0a-7a05-49c0-bbfe-c8614caffecf';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_section_override';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '78d06d0a-7a05-49c0-bbfe-c8614caffecf';
  $display->content['new-78d06d0a-7a05-49c0-bbfe-c8614caffecf'] = $pane;
  $display->panels['contentmain'][3] = 'new-78d06d0a-7a05-49c0-bbfe-c8614caffecf';
  $pane = new stdClass();
  $pane->pid = 'new-b6886e00-79a8-48df-ac92-d05e0491481a';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_node_types';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'b6886e00-79a8-48df-ac92-d05e0491481a';
  $display->content['new-b6886e00-79a8-48df-ac92-d05e0491481a'] = $pane;
  $display->panels['contentmain'][4] = 'new-b6886e00-79a8-48df-ac92-d05e0491481a';
  $pane = new stdClass();
  $pane->pid = 'new-392c7c95-3a78-442c-8ace-755e906bb52f';
  $pane->panel = 'contentmain';
  $pane->type = 'panelizer_form_default';
  $pane->subtype = 'panelizer_form_default';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '392c7c95-3a78-442c-8ace-755e906bb52f';
  $display->content['new-392c7c95-3a78-442c-8ace-755e906bb52f'] = $pane;
  $display->panels['contentmain'][5] = 'new-392c7c95-3a78-442c-8ace-755e906bb52f';
  $pane = new stdClass();
  $pane->pid = 'new-97166f46-2055-4bfa-8aae-9be59da43bd6';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:group_access';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = '97166f46-2055-4bfa-8aae-9be59da43bd6';
  $display->content['new-97166f46-2055-4bfa-8aae-9be59da43bd6'] = $pane;
  $display->panels['sidebar'][0] = 'new-97166f46-2055-4bfa-8aae-9be59da43bd6';
  $pane = new stdClass();
  $pane->pid = 'new-03266a67-2fe8-443d-b5e0-fe331c153ab7';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Featured image',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '03266a67-2fe8-443d-b5e0-fe331c153ab7';
  $display->content['new-03266a67-2fe8-443d-b5e0-fe331c153ab7'] = $pane;
  $display->panels['sidebar'][1] = 'new-03266a67-2fe8-443d-b5e0-fe331c153ab7';
  $pane = new stdClass();
  $pane->pid = 'new-5df9b6d3-49aa-47e9-a927-40a7633af019';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_oa_notifications';
  $pane->subtype = 'node_form_oa_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5df9b6d3-49aa-47e9-a927-40a7633af019';
  $display->content['new-5df9b6d3-49aa-47e9-a927-40a7633af019'] = $pane;
  $display->panels['sidebar'][2] = 'new-5df9b6d3-49aa-47e9-a927-40a7633af019';
  $pane = new stdClass();
  $pane->pid = 'new-fb7d66f3-419f-46f2-b474-d9237000724a';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_menu';
  $pane->subtype = 'node_form_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'fb7d66f3-419f-46f2-b474-d9237000724a';
  $display->content['new-fb7d66f3-419f-46f2-b474-d9237000724a'] = $pane;
  $display->panels['sidebar'][3] = 'new-fb7d66f3-419f-46f2-b474-d9237000724a';
  $pane = new stdClass();
  $pane->pid = 'new-8f33366c-32a6-4d4b-9729-00badbcacd7f';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '8f33366c-32a6-4d4b-9729-00badbcacd7f';
  $display->content['new-8f33366c-32a6-4d4b-9729-00badbcacd7f'] = $pane;
  $display->panels['sidebar'][4] = 'new-8f33366c-32a6-4d4b-9729-00badbcacd7f';
  $pane = new stdClass();
  $pane->pid = 'new-d2758140-4708-4afc-ab3e-d0e65b9d6a33';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_author';
  $pane->subtype = 'node_form_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'd2758140-4708-4afc-ab3e-d0e65b9d6a33';
  $display->content['new-d2758140-4708-4afc-ab3e-d0e65b9d6a33'] = $pane;
  $display->panels['sidebar'][5] = 'new-d2758140-4708-4afc-ab3e-d0e65b9d6a33';
  $pane = new stdClass();
  $pane->pid = 'new-04e718bb-cabe-44b1-a5bc-7df6637a2d40';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_comment';
  $pane->subtype = 'node_form_comment';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = '04e718bb-cabe-44b1-a5bc-7df6637a2d40';
  $display->content['new-04e718bb-cabe-44b1-a5bc-7df6637a2d40'] = $pane;
  $display->panels['sidebar'][6] = 'new-04e718bb-cabe-44b1-a5bc-7df6637a2d40';
  $pane = new stdClass();
  $pane->pid = 'new-d8bb9a24-4195-4a17-b925-367b28850082';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'd8bb9a24-4195-4a17-b925-367b28850082';
  $display->content['new-d8bb9a24-4195-4a17-b925-367b28850082'] = $pane;
  $display->panels['sidebar'][7] = 'new-d8bb9a24-4195-4a17-b925-367b28850082';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_4'] = $handler;

  return $export;
}
