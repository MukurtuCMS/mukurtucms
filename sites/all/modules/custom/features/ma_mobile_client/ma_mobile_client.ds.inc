<?php

/**
 * @file
 * ma_mobile_client.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_mobile_client_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'mm_sync_content_view_field';
  $ds_field->label = 'My Mukurtu Mobile Content View Field';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|mm_synced_content-block',
    'block_render' => '2',
    'block_visibility' => 0,
  );
  $export['mm_sync_content_view_field'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'mukurtu_mobile_sync';
  $ds_field->label = 'Mukurtu Mobile Sync';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
print ma_mobile_client_generate_toggle_link($entity);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['mukurtu_mobile_sync'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'mukurtu_mobile_sync_white';
  $ds_field->label = 'Mukurtu Mobile Sync White';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
print ma_mobile_client_generate_toggle_link($entity, \'white\');
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['mukurtu_mobile_sync_white'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_mobile_client_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'mukurtu_mobile';
  $ds_view_mode->label = 'Mukurtu Mobile';
  $ds_view_mode->entities = array(
    'scald_atom' => 'scald_atom',
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['mukurtu_mobile'] = $ds_view_mode;

  return $export;
}
