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
  $ds_fieldsetting->id = 'node|collection|collections_browse';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'collections_browse';
  $ds_fieldsetting->settings = array(
    'collection_item_count' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '3',
    ),
    'mukurtu_mobile_sync_white' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'node_link' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link class' => '',
        'link text' => 'View Collection',
        'wrapper' => '',
      ),
      'label' => 'hidden',
      'weight' => '5',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
  );
  $export['node|collection|collections_browse'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'collections_tree' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'In this collection',
          'lb-col' => TRUE,
        ),
      ),
      'label' => 'above',
      'weight' => '7',
    ),
    'field_digital_heritage_items' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_related_content' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'mukurtu_mobile_sync_white' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
  );
  $export['node|collection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|featured_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'featured_content';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'featured_content_view_link' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '3',
    ),
  );
  $export['node|collection|featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|collection|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '3',
    ),
    'field_collection_summary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|collection|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
      'label' => 'hidden',
      'weight' => '2',
    ),
    'field_collection_credit' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_collection_summary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
  );
  $export['node|collection|teaser'] = $ds_fieldsetting;

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
    'field_related_content' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'mukurtu_mobile_sync_white' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
  );
  $export['node|personal_collection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|personal_collection|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'personal_collection';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|personal_collection|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|personal_collection|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'personal_collection';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|personal_collection|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|personal_collection|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'personal_collection';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'collection_item_count' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '4',
    ),
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '3',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
  );
  $export['node|personal_collection|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_collection_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'collection_item_count';
  $ds_field->label = 'Collection Item Count';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'collection|*
personal_collection|*';
  $ds_field->properties = array(
    'code' => array(
      'format' => 'ds_code',
      'value' => '<?php 
$count = ma_collection_get_item_count($entity);
if($count == 1) {
   print t(\'@count item\', array( \'@count\' => $count)); 
} else {
   print t(\'@count items\', array( \'@count\' => $count)); 
}

?>',
    ),
    'use_token' => 0,
  );
  $export['collection_item_count'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'collections_title_with_count';
  $ds_field->label = 'Collections title with count';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'format' => 'ds_code',
      'value' => '<?php print ma_collection_collections_title_with_count_and_tree_popup ($entity); ?>',
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
      'format' => 'ds_code',
      'value' => '<?php return ma_collection_collections_tree($entity); ?>',
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
  $ds_layout->id = 'node|collection|collections_browse';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'collections_browse';
  $ds_layout->layout = 'bootstrap_6_6';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'large-teaser-image' => 'large-teaser-image',
      ),
      'right' => array(
        'large-teaser-box' => 'large-teaser-box',
      ),
    ),
    'fields' => array(
      'collection_item_count' => 'right',
      'field_collection_image' => 'left',
      'field_collection_summary' => 'right',
      'mukurtu_mobile_sync_white' => 'right',
      'node_link' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'mukurtu_mobile_sync_white',
        3 => 'collection_item_count',
        4 => 'field_collection_summary',
        5 => 'node_link',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|collection|collections_browse'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'collections_tree' => 'right',
      'field_collection_credit' => 'top',
      'field_collection_image' => 'top',
      'field_collection_summary' => 'top',
      'field_description' => 'top',
      'field_digital_heritage_items' => 'left',
      'field_related_content' => 'left',
      'mukurtu_mobile_sync_white' => 'top',
      'title' => 'top',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        6 => 'field_digital_heritage_items',
        7 => 'field_related_content',
      ),
      'right' => array(
        8 => 'collections_tree',
      ),
      'top' => array(
        0 => 'mukurtu_mobile_sync_white',
        1 => 'field_collection_image',
        2 => 'title',
        3 => 'field_collection_summary',
        4 => 'field_collection_credit',
        5 => 'field_description',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['node|collection|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'central',
      'featured_content_view_link' => 'central',
      'field_collection_image' => 'central',
      'field_collection_summary' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'featured_content_view_link',
        1 => 'field_collection_image',
        2 => 'featured_content_type',
        3 => 'title',
        4 => 'field_collection_summary',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|collection|featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'hidden',
      'field_collection_credit' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_collections_child_coll' => 'ds_content',
      'field_collections_parent_coll' => 'ds_content',
      'field_community_ref' => 'hidden',
      'field_description' => 'ds_content',
      'field_digital_heritage_count' => 'hidden',
      'field_digital_heritage_items' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_tags' => 'ds_content',
      'group_basic' => 'ds_content',
      'group_collections_related' => 'ds_content',
      'group_items' => 'ds_content',
      'group_tabs' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'group_basic',
        2 => 'group_tabs',
        3 => 'group_items',
        4 => 'path',
        5 => 'group_collections_related',
        6 => 'title',
        7 => 'redirect',
        8 => 'field_collection_summary',
        10 => 'field_digital_heritage_items',
        11 => 'og_group_ref',
        12 => 'field_description',
        14 => 'field_item_privacy_setting',
        15 => 'field_collection_image',
        16 => 'field_collection_credit',
        17 => 'field_tags',
        18 => 'field_collections_parent_coll',
        19 => 'field_collections_child_coll',
      ),
      'hidden' => array(
        9 => 'field_community_ref',
        13 => 'field_digital_heritage_count',
        20 => '_add_existing_field',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|collection|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_collection_credit' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_collection_image',
        2 => 'field_collection_summary',
        3 => 'field_collection_credit',
        4 => 'field_description',
        5 => 'field_digital_heritage_items',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|collection|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_collection_credit' => 'right',
      'field_collection_image' => 'left',
      'field_collection_summary' => 'right',
      'group_list_view_fields' => 'right',
      'mukurtu_icon_actions' => 'right',
      'mukurtu_mobile_sync' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        1 => 'field_collection_image',
      ),
      'right' => array(
        0 => 'title',
        2 => 'mukurtu_mobile_sync',
        3 => 'group_list_view_fields',
        4 => 'mukurtu_icon_actions',
        5 => 'featured_content_type',
        6 => 'field_collection_summary',
        7 => 'field_collection_credit',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|collection|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_collection_credit' => 'right',
      'field_collection_image' => 'left',
      'field_collection_summary' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'featured_content_type',
        3 => 'field_collection_summary',
        4 => 'field_collection_credit',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|collection|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personal_collection|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personal_collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'top',
      'field_collection_summary' => 'top',
      'field_description' => 'top',
      'field_digital_heritage_items' => 'bottom',
      'field_personal_coll_privacy' => 'top',
      'field_related_content' => 'bottom',
      'mukurtu_mobile_sync_white' => 'top',
      'title' => 'top',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'bottom' => array(
        6 => 'field_digital_heritage_items',
        7 => 'field_related_content',
      ),
      'top' => array(
        0 => 'mukurtu_mobile_sync_white',
        1 => 'field_collection_image',
        2 => 'title',
        3 => 'field_personal_coll_privacy',
        4 => 'field_collection_summary',
        5 => 'field_description',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'hidden',
      'field_collection_image' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_digital_heritage_count' => 'hidden',
      'field_digital_heritage_items' => 'ds_content',
      'field_personal_coll_privacy' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'group_basic' => 'ds_content',
      'group_items' => 'ds_content',
      'group_tabs' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'group_tabs',
        3 => 'field_personal_coll_privacy',
        4 => 'redirect',
        5 => 'path',
        6 => 'field_collection_summary',
        7 => 'field_digital_heritage_items',
        8 => 'field_description',
        9 => 'field_collection_image',
        10 => 'field_related_content',
        13 => 'group_basic',
        14 => 'group_relations',
      ),
      'hidden' => array(
        11 => 'field_digital_heritage_count',
        12 => '_add_existing_field',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|personal_collection|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personal_collection|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personal_collection';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_collection_image',
        2 => 'field_collection_summary',
        3 => 'field_description',
        4 => 'field_digital_heritage_items',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|personal_collection|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personal_collection|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personal_collection';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_collection_image' => 'left',
      'field_collection_summary' => 'right',
      'group_list_view_fields' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'featured_content_type',
        3 => 'field_collection_summary',
        4 => 'group_list_view_fields',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|personal_collection|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personal_collection|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personal_collection';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'collection_item_count' => 'right',
      'featured_content_type' => 'right',
      'field_collection_image' => 'left',
      'field_collection_summary' => 'right',
      'field_personal_coll_privacy' => 'right',
      'mukurtu_mobile_sync' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'mukurtu_mobile_sync',
        3 => 'featured_content_type',
        4 => 'collection_item_count',
        5 => 'field_collection_summary',
        6 => 'field_personal_coll_privacy',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|personal_collection|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_collection_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'collections_browse';
  $ds_view_mode->label = 'Collections Browse';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['collections_browse'] = $ds_view_mode;

  return $export;
}
