<?php
/**
 * @file
 * oa_teams.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_teams_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_3';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Team Edit Page',
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
              'oa_team' => 'oa_team',
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
  $display->uuid = '62c1d8a2-539e-4504-9a56-128a880384f9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2efcccfe-7736-4d90-b984-d22b40eaf3f2';
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
  $pane->uuid = '2efcccfe-7736-4d90-b984-d22b40eaf3f2';
  $display->content['new-2efcccfe-7736-4d90-b984-d22b40eaf3f2'] = $pane;
  $display->panels['contentmain'][0] = 'new-2efcccfe-7736-4d90-b984-d22b40eaf3f2';
  $pane = new stdClass();
  $pane->pid = 'new-5c4f754b-e3ce-43fa-820b-c173a0d77e98';
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
  $pane->uuid = '5c4f754b-e3ce-43fa-820b-c173a0d77e98';
  $display->content['new-5c4f754b-e3ce-43fa-820b-c173a0d77e98'] = $pane;
  $display->panels['contentmain'][1] = 'new-5c4f754b-e3ce-43fa-820b-c173a0d77e98';
  $pane = new stdClass();
  $pane->pid = 'new-07259854-ceba-42e2-9232-6cf387b5889f';
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
  $pane->uuid = '07259854-ceba-42e2-9232-6cf387b5889f';
  $display->content['new-07259854-ceba-42e2-9232-6cf387b5889f'] = $pane;
  $display->panels['contentmain'][2] = 'new-07259854-ceba-42e2-9232-6cf387b5889f';
  $pane = new stdClass();
  $pane->pid = 'new-eaa8564d-f45c-4fee-995d-cff315947d99';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_oa_team_users';
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
  $pane->uuid = 'eaa8564d-f45c-4fee-995d-cff315947d99';
  $display->content['new-eaa8564d-f45c-4fee-995d-cff315947d99'] = $pane;
  $display->panels['sidebar'][0] = 'new-eaa8564d-f45c-4fee-995d-cff315947d99';
  $pane = new stdClass();
  $pane->pid = 'new-10064383-7356-4981-aae6-f0c9daa1a272';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '10064383-7356-4981-aae6-f0c9daa1a272';
  $display->content['new-10064383-7356-4981-aae6-f0c9daa1a272'] = $pane;
  $display->panels['sidebar'][1] = 'new-10064383-7356-4981-aae6-f0c9daa1a272';
  $pane = new stdClass();
  $pane->pid = 'new-65cf5ce7-b37a-431e-9e2e-096989f92be2';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '65cf5ce7-b37a-431e-9e2e-096989f92be2';
  $display->content['new-65cf5ce7-b37a-431e-9e2e-096989f92be2'] = $pane;
  $display->panels['sidebar'][2] = 'new-65cf5ce7-b37a-431e-9e2e-096989f92be2';
  $pane = new stdClass();
  $pane->pid = 'new-1e56eca0-2242-4579-b89e-a0a3c313f5d7';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '1e56eca0-2242-4579-b89e-a0a3c313f5d7';
  $display->content['new-1e56eca0-2242-4579-b89e-a0a3c313f5d7'] = $pane;
  $display->panels['sidebar'][3] = 'new-1e56eca0-2242-4579-b89e-a0a3c313f5d7';
  $pane = new stdClass();
  $pane->pid = 'new-e7ebc128-a2c3-4af7-8a5f-ae7f35333878';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'e7ebc128-a2c3-4af7-8a5f-ae7f35333878';
  $display->content['new-e7ebc128-a2c3-4af7-8a5f-ae7f35333878'] = $pane;
  $display->panels['sidebar'][4] = 'new-e7ebc128-a2c3-4af7-8a5f-ae7f35333878';
  $pane = new stdClass();
  $pane->pid = 'new-8a6b9e1b-838a-4f2f-996a-43540bcf78ff';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '8a6b9e1b-838a-4f2f-996a-43540bcf78ff';
  $display->content['new-8a6b9e1b-838a-4f2f-996a-43540bcf78ff'] = $pane;
  $display->panels['sidebar'][5] = 'new-8a6b9e1b-838a-4f2f-996a-43540bcf78ff';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_3'] = $handler;

  return $export;
}
