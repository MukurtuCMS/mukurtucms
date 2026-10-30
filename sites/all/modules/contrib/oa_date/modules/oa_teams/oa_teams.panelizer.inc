<?php
/**
 * @file
 * oa_teams.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_teams_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_team';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:oa_team:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_bryant_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_styles_oa_pane',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '9e4bbd87-bff1-439a-aa0a-278edd786774';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_team:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-00ca7d81-3814-430c-8c25-5b35d0f36f95';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '00ca7d81-3814-430c-8c25-5b35d0f36f95';
  $display->content['new-00ca7d81-3814-430c-8c25-5b35d0f36f95'] = $pane;
  $display->panels['contentmain'][0] = 'new-00ca7d81-3814-430c-8c25-5b35d0f36f95';
  $pane = new stdClass();
  $pane->pid = 'new-99e1abdd-3d05-47dc-b8e2-c19c1195011c';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'page_manager',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '99e1abdd-3d05-47dc-b8e2-c19c1195011c';
  $display->content['new-99e1abdd-3d05-47dc-b8e2-c19c1195011c'] = $pane;
  $display->panels['contentmain'][1] = 'new-99e1abdd-3d05-47dc-b8e2-c19c1195011c';
  $pane = new stdClass();
  $pane->pid = 'new-f0716b0b-c542-4df3-a986-9ddabb49bd25';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_teams_members';
  $pane->subtype = 'oa_teams_members';
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
  $pane->uuid = 'f0716b0b-c542-4df3-a986-9ddabb49bd25';
  $display->content['new-f0716b0b-c542-4df3-a986-9ddabb49bd25'] = $pane;
  $display->panels['contentmain'][2] = 'new-f0716b0b-c542-4df3-a986-9ddabb49bd25';
  $pane = new stdClass();
  $pane->pid = 'new-ba8f7d2d-6879-411d-b75f-cfe0c12513d2';
  $pane->panel = 'contentmain';
  $pane->type = 'node_comment_wrapper';
  $pane->subtype = 'node_comment_wrapper';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mode' => '1',
    'comments_per_page' => '50',
    'context' => 'panelizer',
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
  $pane->uuid = 'ba8f7d2d-6879-411d-b75f-cfe0c12513d2';
  $display->content['new-ba8f7d2d-6879-411d-b75f-cfe0c12513d2'] = $pane;
  $display->panels['contentmain'][3] = 'new-ba8f7d2d-6879-411d-b75f-cfe0c12513d2';
  $pane = new stdClass();
  $pane->pid = 'new-592610e3-760b-4707-a5cd-110f439132bb';
  $pane->panel = 'sidebar';
  $pane->type = 'oa_teams_add_member';
  $pane->subtype = 'oa_teams_add_member';
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
  $pane->uuid = '592610e3-760b-4707-a5cd-110f439132bb';
  $display->content['new-592610e3-760b-4707-a5cd-110f439132bb'] = $pane;
  $display->panels['sidebar'][0] = 'new-592610e3-760b-4707-a5cd-110f439132bb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_team:default'] = $panelizer;

  return $export;
}
