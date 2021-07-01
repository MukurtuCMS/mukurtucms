<?php

/**
 * @file
 * ma_dhan.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_dhan_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dhan_notify';
  $ds_field->label = 'Digital Heritage Notifications';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php return ma_dhan_notification_field($entity); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['dhan_notify'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_dhan_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dhan|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dhan';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_following_content',
        1 => 'field_notify_immediately',
        2 => 'field_notify_day',
        3 => 'field_notify_week',
        4 => 'field_notify_all',
        5 => 'field_users_notified',
        6 => 'field_all_users_notified',
        7 => 'field_notification_email',
      ),
    ),
    'fields' => array(
      'field_following_content' => 'ds_content',
      'field_notify_immediately' => 'ds_content',
      'field_notify_day' => 'ds_content',
      'field_notify_week' => 'ds_content',
      'field_notify_all' => 'ds_content',
      'field_users_notified' => 'ds_content',
      'field_all_users_notified' => 'ds_content',
      'field_notification_email' => 'ds_content',
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
  $export['node|dhan|full'] = $ds_layout;

  return $export;
}
