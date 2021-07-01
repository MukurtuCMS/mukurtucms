<?php
/**
 * @file
 * paragraphs_test.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function paragraphs_test_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'paragraphs_item:ptest:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'paragraphs_item';
  $panelizer->panelizer_key = 'ptest';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
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
  $display->title = '';
  $display->uuid = 'a6e355d2-2f62-4351-81bc-b72a8c82b8f6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-66fc9124-fc10-4bc8-9d66-f0ed5b5245ec';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'paragraphs_item:field_ptest_text';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '66fc9124-fc10-4bc8-9d66-f0ed5b5245ec';
    $display->content['new-66fc9124-fc10-4bc8-9d66-f0ed5b5245ec'] = $pane;
    $display->panels['center'][0] = 'new-66fc9124-fc10-4bc8-9d66-f0ed5b5245ec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['paragraphs_item:ptest:default:default'] = $panelizer;

  return $export;
}
