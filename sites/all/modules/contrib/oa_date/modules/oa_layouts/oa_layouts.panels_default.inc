<?php
/**
 * @file
 * oa_layouts.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function oa_layouts_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'default_section_sidebar';
  $mini->category = 'Open Atrium';
  $mini->admin_title = 'Open Atrium Sidebar Bottom';
  $mini->admin_description = 'Provides bottom default section sidebar content';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3d1931ce-af4b-436d-b1f7-3101b7d40c2a';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'default_section_sidebar';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f2ec5f94-339a-49f9-b2da-a7ef498420dc';
  $pane->panel = 'middle';
  $pane->type = 'oa_related_ref';
  $pane->subtype = 'oa_related_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'requiredcontext_entity:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'form_build_id' => 'form-uc-eBXCbIBlj8aVe3u_YgXJRlYvn3wwXcD943s6g5hw',
    'form_token' => '6gDe-0oKLid466aveG1Pz21kCxrr0ZEkp8corDP0Mzs',
    'form_id' => 'oa_related_ref_edit_form',
    'op' => 'Finish',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f2ec5f94-339a-49f9-b2da-a7ef498420dc';
  $display->content['new-f2ec5f94-339a-49f9-b2da-a7ef498420dc'] = $pane;
  $display->panels['middle'][0] = 'new-f2ec5f94-339a-49f9-b2da-a7ef498420dc';
  $pane = new stdClass();
  $pane->pid = 'new-e88f722e-09b5-451c-b694-f6b79c2d8554';
  $pane->panel = 'middle';
  $pane->type = 'oa_notifications_pane';
  $pane->subtype = 'oa_notifications_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'requiredcontext_entity:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'form_build_id' => 'form-cqM7WI7hjRznriZxDFBrm8G4I9_mm6Yzvz7wALJklco',
    'form_token' => 'hj-U86RUhHElqbcZxCaB5y1kMBIyQjRYApEWJ5pwg1M',
    'form_id' => 'oa_notifications_settings_form',
    'op' => 'Finish',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e88f722e-09b5-451c-b694-f6b79c2d8554';
  $display->content['new-e88f722e-09b5-451c-b694-f6b79c2d8554'] = $pane;
  $display->panels['middle'][1] = 'new-e88f722e-09b5-451c-b694-f6b79c2d8554';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['default_section_sidebar'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'oa_footer_panel';
  $mini->category = 'OA Admin';
  $mini->admin_title = 'Open Atrium Footer';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_sutro_double';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
      'middle' => NULL,
      'secondcolumn1' => NULL,
      'secondcolumn2' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c94dbbdc-f52c-491e-bde7-a61c98b5cbd3';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'oa_footer_panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-39727060-3c1c-4478-ac3f-fa1a0800ad6f';
  $pane->panel = 'footer';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-footer',
    'parent_mlid' => '',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 1,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-left',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '39727060-3c1c-4478-ac3f-fa1a0800ad6f';
  $display->content['new-39727060-3c1c-4478-ac3f-fa1a0800ad6f'] = $pane;
  $display->panels['footer'][0] = 'new-39727060-3c1c-4478-ac3f-fa1a0800ad6f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['oa_footer_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'section_sidebar_top';
  $mini->category = 'Open Atrium';
  $mini->admin_title = 'Open Atrium Sidebar Top';
  $mini->admin_description = 'Provides the top default section sidebar content';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9f0c0534-ba65-4249-bb78-180cd3e7aa44';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'section_sidebar_top';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9ed591f8-ab5b-4f63-b168-5acab75ccfb7';
  $pane->panel = 'middle';
  $pane->type = 'oa_widgets_content_visibility';
  $pane->subtype = 'oa_widgets_content_visibility';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'requiredcontext_entity:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'form_build_id' => 'form-uRTcRQO6bSpNFP0fFiN_Py_Fq4JgR6M0fwB0DjBfo00',
    'form_token' => 'ftELGes9cSP07D0rKXmZzilWqzY8HXgZvejPQwIpx0w',
    'form_id' => 'oa_widgets_content_visibility_edit_form',
    'op' => 'Finish',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9ed591f8-ab5b-4f63-b168-5acab75ccfb7';
  $display->content['new-9ed591f8-ab5b-4f63-b168-5acab75ccfb7'] = $pane;
  $display->panels['middle'][0] = 'new-9ed591f8-ab5b-4f63-b168-5acab75ccfb7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['section_sidebar_top'] = $mini;

  return $export;
}
