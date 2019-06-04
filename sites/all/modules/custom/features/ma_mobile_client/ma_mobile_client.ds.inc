<?php

/**
 * @file
 * ma_mobile_client.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_mobile_client_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'community_record_title' => array(
      'weight' => '1',
      'label' => 'above',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '34',
      'label' => 'above',
      'format' => 'author',
    ),
  );
  $export['node|digital_heritage|mukurtu_mobile'] = $ds_fieldsetting;

  return $export;
}

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
 * Implements hook_ds_layout_settings_info().
 */
function ma_mobile_client_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'community_record_title',
        2 => 'field_media_asset',
        3 => 'field_summary',
        4 => 'field_description',
        5 => 'body',
        6 => 'field_tk_body',
        7 => 'field_people',
        8 => 'field_transcription',
        9 => 'field_coverage',
        10 => 'field_coverage_description',
        11 => 'field_related_dh_items',
        12 => 'field_related_dictionary_words',
        13 => 'field_community_ref',
        14 => 'field_community_record_parent',
        15 => 'field_community_record_children',
        16 => 'og_group_ref',
        17 => 'field_category',
        18 => 'field_tags',
        19 => 'field_collection',
        20 => 'field_original_date',
        21 => 'field_date',
        22 => 'field_creator',
        23 => 'field_contributor',
        24 => 'field_language',
        25 => 'field_rights',
        26 => 'field_licence_trad',
        27 => 'field_licence_std_cc',
        28 => 'field_source',
        29 => 'field_publisher',
        30 => 'field_identifier',
        31 => 'field_subject',
        32 => 'field_dh_type',
        33 => 'field_format',
        34 => 'author',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'community_record_title' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'body' => 'ds_content',
      'field_tk_body' => 'ds_content',
      'field_people' => 'ds_content',
      'field_transcription' => 'ds_content',
      'field_coverage' => 'ds_content',
      'field_coverage_description' => 'ds_content',
      'field_related_dh_items' => 'ds_content',
      'field_related_dictionary_words' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_community_record_parent' => 'ds_content',
      'field_community_record_children' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_category' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_original_date' => 'ds_content',
      'field_date' => 'ds_content',
      'field_creator' => 'ds_content',
      'field_contributor' => 'ds_content',
      'field_language' => 'ds_content',
      'field_rights' => 'ds_content',
      'field_licence_trad' => 'ds_content',
      'field_licence_std_cc' => 'ds_content',
      'field_source' => 'ds_content',
      'field_publisher' => 'ds_content',
      'field_identifier' => 'ds_content',
      'field_subject' => 'ds_content',
      'field_dh_type' => 'ds_content',
      'field_format' => 'ds_content',
      'author' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|digital_heritage|mukurtu_mobile'] = $ds_layout;

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
    'node' => 'node',
  );
  $export['mukurtu_mobile'] = $ds_view_mode;

  return $export;
}
