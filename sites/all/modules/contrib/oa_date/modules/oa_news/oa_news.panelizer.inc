<?php
/**
 * @file
 * oa_news.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_news_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Document Section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:oa_section:oa_section_news';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array(
    0 => array(
      'identifier' => 'Space',
      'keyword' => 'space',
      'name' => 'entity_from_field:og_group_ref-node-node',
      'delta' => 0,
      'context' => 'panelizer',
      'id' => 1,
    ),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
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
  $display->title = '';
  $display->uuid = '4da17148-a7a9-4da8-a9bf-ef168121174a';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_section:oa_section_news';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b';
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
  $pane->uuid = '2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b';
  $display->content['new-2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b'] = $pane;
  $display->panels['contentmain'][0] = 'new-2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b';
  $pane = new stdClass();
  $pane->pid = 'new-a1345e0e-4ffb-4445-b615-b8922b7dba10';
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
  $pane->uuid = 'a1345e0e-4ffb-4445-b615-b8922b7dba10';
  $display->content['new-a1345e0e-4ffb-4445-b615-b8922b7dba10'] = $pane;
  $display->panels['contentmain'][1] = 'new-a1345e0e-4ffb-4445-b615-b8922b7dba10';
  $pane = new stdClass();
  $pane->pid = 'new-d2e48391-04fd-4e47-a3ee-9442c060a4e8';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'open_atrium_news-oa_recent_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '10',
    'fields_override' => array(
      'title' => 1,
      'timestamp' => 1,
      'created' => 1,
      'body' => 1,
      'name' => 1,
      'field_user_picture' => 1,
      'term_node_tid' => 1,
      'field_featured_image' => 1,
      'field_oa_media' => 1,
      'edit_node' => 1,
    ),
    'exposed' => array(
      'type' => array(
        'oa_wiki_page' => 'oa_wiki_page',
      ),
      'og_group_ref_target_id' => '',
      'og_group_ref_target_id_mine' => 0,
      'og_subspaces_view_all' => 0,
      'og_subspaces_view_parent' => 0,
      'oa_section_ref_target_id' => '',
      'flagged' => '0',
    ),
    'context' => array(
      0 => 'relationship_entity_from_field:og_group_ref-node-node_1',
      1 => 'panelizer',
    ),
    'override_title' => '',
    'override_title_text' => '',
    'view_mode' => 'teaser',
    'widget_title' => '',
    'use_pager' => 1,
    'pager_id' => '',
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
    'view_settings' => 'fields',
    'header_type' => 'none',
    'show_exposed_form' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'oa_styles_oa_pane',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd2e48391-04fd-4e47-a3ee-9442c060a4e8';
  $display->content['new-d2e48391-04fd-4e47-a3ee-9442c060a4e8'] = $pane;
  $display->panels['contentmain'][2] = 'new-d2e48391-04fd-4e47-a3ee-9442c060a4e8';
  $pane = new stdClass();
  $pane->pid = 'new-60764651-f3d4-4f32-a25e-56c63162c11f';
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
  $pane->uuid = '60764651-f3d4-4f32-a25e-56c63162c11f';
  $display->content['new-60764651-f3d4-4f32-a25e-56c63162c11f'] = $pane;
  $display->panels['contentmain'][3] = 'new-60764651-f3d4-4f32-a25e-56c63162c11f';
  $pane = new stdClass();
  $pane->pid = 'new-e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc';
  $pane->panel = 'sidebar';
  $pane->type = 'oa_widgets_content_visibility';
  $pane->subtype = 'oa_widgets_content_visibility';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'form_build_id' => 'form-AHJUfpYPcZ4fsSHUHIFy0Adu0CXy4e79Kcslz2yLodI',
    'form_token' => 'BzH8uxEwTjsQGuqkcXBIlcjCxMTFGGufXWz-7ckhC2M',
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
  $pane->uuid = 'e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc';
  $display->content['new-e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc'] = $pane;
  $display->panels['sidebar'][0] = 'new-e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc';
  $pane = new stdClass();
  $pane->pid = 'new-83087d0e-6633-4275-baea-7bb63a3fb92f';
  $pane->panel = 'sidebar';
  $pane->type = 'oa_files_treeview';
  $pane->subtype = 'oa_files_treeview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'oa_files_treeview_mode' => '0',
    'oa_files_menu_mode' => '0',
    'oa_files_fields' => array(
      'size' => 0,
      'date' => 0,
      'modified' => 0,
      'filename' => 0,
      'body' => 0,
    ),
    'oa_files_showcount' => 0,
    'oa_files_showfilter' => 0,
    'oa_files_actions' => array(),
    'oa_files_sort' => 'title',
    'oa_files_dir' => 'ASC',
    'oa_files_all' => 0,
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'override_title' => 0,
    'override_title_text' => '',
    'og_menu_single_depth' => '0',
    'og_menu_single_parent' => 'auto',
    'oa_files_vocabulary' => '1',
    'oa_files_action_title_download' => 'Download',
    'oa_files_action_download' => '1',
    'oa_files_action_title_view' => 'View metadata',
    'oa_files_action_view' => '1',
    'oa_files_action_title_edit' => 'Edit metadata',
    'oa_files_action_edit' => '1',
    'oa_files_action_title_folder' => 'New folder',
    'oa_files_action_folder' => '1',
    'oa_files_action_title_addfile' => 'Add file',
    'oa_files_action_addfile' => '1',
    'form_build_id' => 'form-E-8F_3fhIPASvCPKRrkdlDy-bBgtvWqYY0lr8T25SzE',
    'form_token' => 'ztpT-HVzPIjqObt5Te84nGdciMOCn1VD4lwSQPUOw5s',
    'form_id' => 'oa_files_treeview_settings_form',
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
  $pane->uuid = '83087d0e-6633-4275-baea-7bb63a3fb92f';
  $display->content['new-83087d0e-6633-4275-baea-7bb63a3fb92f'] = $pane;
  $display->panels['sidebar'][1] = 'new-83087d0e-6633-4275-baea-7bb63a3fb92f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_section:oa_section_news'] = $panelizer;

  return $export;
}
