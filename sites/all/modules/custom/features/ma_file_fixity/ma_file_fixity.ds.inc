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
    'fixity_reports' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'fixity_run_check' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|fixity_check|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_file_fixity_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'fixity_reports';
  $ds_field->label = 'Check Runs';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'fixity_check|*';
  $ds_field->properties = array(
    'block' => 'views|fixity_reports-block_1',
    'block_render' => '3',
  );
  $export['fixity_reports'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'fixity_run_check';
  $ds_field->label = 'Run fixity check';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'fixity_check|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php print l(\'Run this check now.\', \'run-fixity-check/\' . $entity->nid); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['fixity_run_check'] = $ds_field;

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
        2 => 'field_fixity_algos_checked',
        3 => 'field_fixity_files_checked',
        4 => 'field_fixity_check_fails_count',
        5 => 'field_fixity_check_fails_details',
      ),
    ),
    'fields' => array(
      'field_fixity_time_of_check' => 'ds_content',
      'field_fixity_processing_time' => 'ds_content',
      'field_fixity_algos_checked' => 'ds_content',
      'field_fixity_files_checked' => 'ds_content',
      'field_fixity_check_fails_count' => 'ds_content',
      'field_fixity_check_fails_details' => 'ds_content',
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
        2 => 'field_fixity_algos_checked',
        3 => 'field_fixity_files_checked',
        4 => 'field_fixity_check_fails_count',
        5 => 'field_fixity_check_fails_details',
      ),
      'hidden' => array(
        6 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_fixity_time_of_check' => 'ds_content',
      'field_fixity_processing_time' => 'ds_content',
      'field_fixity_algos_checked' => 'ds_content',
      'field_fixity_files_checked' => 'ds_content',
      'field_fixity_check_fails_count' => 'ds_content',
      'field_fixity_check_fails_details' => 'ds_content',
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
        0 => 'field_fixity_latest_check_status',
        1 => 'field_fixity_latest_check_time',
        2 => 'field_fixity_next_check_run_time',
        3 => 'field_fixity_hashes_to_use',
        4 => 'field_fixity_email_all_admins',
        5 => 'fixity_run_check',
        6 => 'fixity_reports',
      ),
    ),
    'fields' => array(
      'field_fixity_latest_check_status' => 'ds_content',
      'field_fixity_latest_check_time' => 'ds_content',
      'field_fixity_next_check_run_time' => 'ds_content',
      'field_fixity_hashes_to_use' => 'ds_content',
      'field_fixity_email_all_admins' => 'ds_content',
      'fixity_run_check' => 'ds_content',
      'fixity_reports' => 'ds_content',
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
        1 => 'field_fixity_schedule',
        2 => 'field_fixity_days_frequency',
        3 => 'field_fixity_cps',
        4 => 'field_fixity_hashes_to_use',
        5 => 'field_fixity_email_all_admins',
        6 => 'redirect',
        7 => 'path',
      ),
      'hidden' => array(
        8 => 'field_fixity_latest_check_status',
        9 => 'field_fixity_latest_check_time',
        10 => 'title',
        11 => 'field_fixity_report',
        12 => 'field_fixity_next_check_run_time',
        13 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'field_fixity_schedule' => 'ds_content',
      'field_fixity_days_frequency' => 'ds_content',
      'field_fixity_cps' => 'ds_content',
      'field_fixity_hashes_to_use' => 'ds_content',
      'field_fixity_email_all_admins' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'field_fixity_latest_check_status' => 'hidden',
      'field_fixity_latest_check_time' => 'hidden',
      'title' => 'hidden',
      'field_fixity_report' => 'hidden',
      'field_fixity_next_check_run_time' => 'hidden',
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
