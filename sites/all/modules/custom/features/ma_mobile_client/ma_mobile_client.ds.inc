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

  return $export;
}
