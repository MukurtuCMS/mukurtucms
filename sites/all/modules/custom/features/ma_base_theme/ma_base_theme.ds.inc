<?php
/**
 * @file
 * ma_base_theme.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_base_theme_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'admin_actions';
  $ds_field->label = 'Admin Actions';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['admin_actions'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'component_media_items';
  $ds_field->label = 'More Media Items';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['component_media_items'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_base_theme_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'component_media_item';
  $ds_view_mode->label = 'Component Media Item';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['component_media_item'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'full_content';
  $ds_view_mode->label = 'Full content';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['full_content'] = $ds_view_mode;

  return $export;
}
