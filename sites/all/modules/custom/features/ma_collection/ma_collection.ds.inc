<?php
/**
 * @file
 * ma_collection.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_collection_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|collection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'collections_title_with_count' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_collection_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|collection|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_collection_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'collections_title_with_count';
  $ds_field->label = 'Collections title with count';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'collection|search_result';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php print ma_collection_collections_title_with_count ($entity); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['collections_title_with_count'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_collection_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_collection_image',
        2 => 'field_collection_summary',
        3 => 'field_description',
        4 => 'field_collection_credit',
        5 => 'field_digital_heritage_items',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_collection_credit' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|collection|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_tabs',
        2 => 'title',
        3 => 'group_basic',
        4 => 'field_collection_summary',
        5 => 'group_digital_heritage_items',
        6 => 'path',
        7 => 'field_description',
        8 => 'field_collection_image',
        9 => 'redirect',
        11 => 'field_digital_heritage_items',
        12 => 'field_collection_credit',
      ),
      'hidden' => array(
        1 => 'group_digital_heritage',
        10 => 'field_digital_heritage_count',
        13 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_tabs' => 'ds_content',
      'group_digital_heritage' => 'hidden',
      'title' => 'ds_content',
      'group_basic' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'group_digital_heritage_items' => 'ds_content',
      'path' => 'ds_content',
      'field_description' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'redirect' => 'ds_content',
      'field_digital_heritage_count' => 'hidden',
      'field_digital_heritage_items' => 'ds_content',
      'field_collection_credit' => 'ds_content',
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
  );
  $export['node|collection|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_collection_image',
        1 => 'collections_title_with_count',
        2 => 'group_list_view_fields',
        3 => 'field_collection_summary',
        4 => 'field_collection_credit',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'ds_content',
      'collections_title_with_count' => 'ds_content',
      'group_list_view_fields' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_collection_credit' => 'ds_content',
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
  );
  $export['node|collection|search_result'] = $ds_layout;

  return $export;
}
