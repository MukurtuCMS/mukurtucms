<?php

/**
 * @file
 * ma_shared_notification_components.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_shared_notification_components_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_notification_email|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_notification_email';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_notification_date_gene',
        1 => 'field_notification_author',
        2 => 'field_notification_action',
        3 => 'field_notification_subject',
        4 => 'field_notification_body',
        5 => 'field_notification_comment',
      ),
    ),
    'fields' => array(
      'field_notification_date_gene' => 'ds_content',
      'field_notification_author' => 'ds_content',
      'field_notification_action' => 'ds_content',
      'field_notification_subject' => 'ds_content',
      'field_notification_body' => 'ds_content',
      'field_notification_comment' => 'ds_content',
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
  $export['field_collection_item|field_notification_email|default'] = $ds_layout;

  return $export;
}
