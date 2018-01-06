<?php
/**
 * @file
 * ma_file_fixity.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_file_fixity_ds_layout_settings_info() {
  $export = array();

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
        7 => '_add_existing_field',
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
