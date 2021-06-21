<?php

/**
 * @file
 * ma_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'mm_sync_content_view_field' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'personal_collections' => array(
      'weight' => '1',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'My Personal Collections',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'og_user_node' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'My Communities',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_profile_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'personal_collections';
  $ds_field->label = 'Personal Collections';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|personal_collections-block',
    'block_render' => '3',
  );
  $export['personal_collections'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'og_user_node',
        1 => 'personal_collections',
        2 => 'mm_sync_content_view_field',
      ),
    ),
    'fields' => array(
      'og_user_node' => 'central',
      'personal_collections' => 'central',
      'mm_sync_content_view_field' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['user|user|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|form';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'account',
        1 => 'googleanalytics',
        2 => 'contact',
        3 => 'locale',
        4 => 'picture',
        5 => 'timezone',
        6 => 'og_user_node',
        7 => 'redirect',
      ),
      'hidden' => array(
        8 => 'field_notifications_freq_def',
        9 => 'field_dhan_frequency',
        10 => 'ckeditor',
        11 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'account' => 'ds_content',
      'googleanalytics' => 'ds_content',
      'contact' => 'ds_content',
      'locale' => 'ds_content',
      'picture' => 'ds_content',
      'timezone' => 'ds_content',
      'og_user_node' => 'ds_content',
      'redirect' => 'ds_content',
      'field_notifications_freq_def' => 'hidden',
      'field_dhan_frequency' => 'hidden',
      'ckeditor' => 'hidden',
      '_add_existing_field' => 'hidden',
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
  $export['user|user|form'] = $ds_layout;

  return $export;
}
