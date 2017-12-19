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
    'collections_tree' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'default',
    ),
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
  );
  $export['node|collection|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|personal_collection|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'personal_collection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_digital_heritage_items' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|personal_collection|default'] = $ds_fieldsetting;

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
      'value' => '<?php print ma_collection_collections_title_with_count_and_tree_popup ($entity); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['collections_title_with_count'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'collections_tree';
  $ds_field->label = 'Collections Tree';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php return ma_collection_collections_tree($entity); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['collections_tree'] = $ds_field;

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
        6 => 'collections_tree',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_collection_credit' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
      'collections_tree' => 'ds_content',
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
        0 => 'field_pre_actions',
        1 => 'group_basic',
        2 => 'group_tabs',
        3 => 'path',
        4 => 'group_items',
        5 => 'group_collections_related',
        6 => 'redirect',
        7 => 'title',
        8 => 'field_digital_heritage_items',
        9 => 'field_collection_summary',
        10 => 'field_description',
        11 => 'field_collection_image',
        14 => 'field_collection_credit',
        15 => 'field_collections_parent_coll',
        16 => 'field_collections_child_coll',
      ),
      'hidden' => array(
        12 => 'field_digital_heritage_count',
        13 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'group_basic' => 'ds_content',
      'group_tabs' => 'ds_content',
      'path' => 'ds_content',
      'group_items' => 'ds_content',
      'group_collections_related' => 'ds_content',
      'redirect' => 'ds_content',
      'title' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_digital_heritage_count' => 'hidden',
      '_add_existing_field' => 'hidden',
      'field_collection_credit' => 'ds_content',
      'field_collections_parent_coll' => 'ds_content',
      'field_collections_child_coll' => 'ds_content',
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
        0 => 'collections_title_with_count',
        1 => 'field_collection_image',
        2 => 'group_list_view_fields',
        3 => 'field_collection_summary',
        4 => 'field_collection_credit',
      ),
    ),
    'fields' => array(
      'collections_title_with_count' => 'ds_content',
      'field_collection_image' => 'ds_content',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|collection|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personal_collection|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personal_collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_collection_image',
        1 => 'field_personal_coll_privacy',
        2 => 'field_collection_summary',
        3 => 'field_description',
        4 => 'field_digital_heritage_items',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'ds_content',
      'field_personal_coll_privacy' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
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
  $export['node|personal_collection|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personal_collection|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personal_collection';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'field_personal_coll_privacy',
        3 => 'group_tabs',
        4 => 'field_collection_summary',
        5 => 'redirect',
        6 => 'field_description',
        7 => 'path',
        8 => 'field_collection_image',
        9 => 'field_digital_heritage_items',
        12 => 'group_basic',
        13 => 'group_items',
      ),
      'hidden' => array(
        10 => 'field_digital_heritage_count',
        11 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'field_personal_coll_privacy' => 'ds_content',
      'group_tabs' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'redirect' => 'ds_content',
      'field_description' => 'ds_content',
      'path' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
      'field_digital_heritage_count' => 'hidden',
      '_add_existing_field' => 'hidden',
      'group_basic' => 'ds_content',
      'group_items' => 'ds_content',
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
  $export['node|personal_collection|form'] = $ds_layout;

  return $export;
}
