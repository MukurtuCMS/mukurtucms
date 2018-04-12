<?php
/**
 * @file
 * ma_taxonomy.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_taxonomy_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|category|taxonomy_browse_by';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'category';
  $ds_fieldsetting->view_mode = 'taxonomy_browse_by';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['taxonomy_term|category|taxonomy_browse_by'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_taxonomy_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|category|taxonomy_browse_by';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'category';
  $ds_layout->view_mode = 'taxonomy_browse_by';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_thumbnail_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_thumbnail_image' => 'central',
      'title' => 'central',
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
  $export['taxonomy_term|category|taxonomy_browse_by'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_taxonomy_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'taxonomy_browse_by';
  $ds_view_mode->label = 'Taxonomy Browse By';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['taxonomy_browse_by'] = $ds_view_mode;

  return $export;
}
