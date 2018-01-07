<?php
/**
 * @file
 * ma_file_fixity.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_file_fixity_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|fixity_check|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'fixity_check';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|fixity_check|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_file_fixity_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_fixity_report|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_fixity_report';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_fixity_time_of_check',
        1 => 'field_fixity_processing_time',
        2 => 'field_fixity_files_checked',
        3 => 'field_fixity_check_fails',
      ),
    ),
    'fields' => array(
      'field_fixity_time_of_check' => 'ds_content',
      'field_fixity_processing_time' => 'ds_content',
      'field_fixity_files_checked' => 'ds_content',
      'field_fixity_check_fails' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_fixity_report|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_fixity_report|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_fixity_report';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_fixity_time_of_check',
        1 => 'field_fixity_processing_time',
        2 => 'field_fixity_files_checked',
        3 => 'field_fixity_check_fails',
      ),
      'hidden' => array(
        4 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_fixity_time_of_check' => 'ds_content',
      'field_fixity_processing_time' => 'ds_content',
      'field_fixity_files_checked' => 'ds_content',
      'field_fixity_check_fails' => 'ds_content',
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
  $export['field_collection_item|field_fixity_report|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|fixity_check|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'fixity_check';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_fixity_latest_check_status',
        2 => 'field_fixity_latest_check_time',
        3 => 'field_fixity_report',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_fixity_latest_check_status' => 'ds_content',
      'field_fixity_latest_check_time' => 'ds_content',
      'field_fixity_report' => 'ds_content',
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
  $export['node|fixity_check|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|fixity_check|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'fixity_check';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        2 => 'field_fixity_schedule',
        3 => 'field_fixity_days_frequency',
        4 => 'field_fixity_cps',
        5 => 'redirect',
        6 => 'path',
      ),
      'hidden' => array(
        1 => 'title',
        7 => 'field_fixity_report',
        8 => 'field_fixity_latest_check_status',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'hidden',
      'field_fixity_schedule' => 'ds_content',
      'field_fixity_days_frequency' => 'ds_content',
      'field_fixity_cps' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'field_fixity_report' => 'hidden',
      'field_fixity_latest_check_status' => 'hidden',
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
  $export['node|fixity_check|form'] = $ds_layout;

  return $export;
}
