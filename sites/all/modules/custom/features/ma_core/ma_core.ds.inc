<?php

/**
 * @file
 * ma_core.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_core_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'create_content_block_ds_field';
  $ds_field->label = 'Create Content Block DS';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'ma_core|create_content',
    'block_render' => '1',
  );
  $export['create_content_block_ds_field'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_core_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_category',
        2 => 'field_tags',
        3 => 'field_image',
        4 => 'body',
        5 => 'flag',
        6 => 'path',
        7 => 'field_test_assets',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_category' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'flag' => 'ds_content',
      'path' => 'ds_content',
      'field_test_assets' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|article|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = '3col_unbalanced_html5';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'comments',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'comments' => 'left',
    ),
    'classes' => array(
      'header' => array(
        'grid-6' => 'grid-6',
      ),
      'left' => array(
        'grid-6' => 'grid-6',
      ),
      'right' => array(
        'grid-2' => 'grid-2',
      ),
    ),
  );
  $export['node|page|full'] = $ds_layout;

  return $export;
}
