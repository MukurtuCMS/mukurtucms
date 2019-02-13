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
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'View Collection',
        'link class' => '',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
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
      'weight' => '8',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'In this collection',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_digital_heritage_items' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
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
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'featured_content_view_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|collection|featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collection|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collection';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_collection_summary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
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
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
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
  );
  $export['node|collection|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|personal_collection|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'personal_collection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|personal_collection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|personal_collection|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'personal_collection';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'collection_item_count' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'featured_content_type' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
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
      'value' => '<?php 
$count = ma_collection_get_item_count($entity);
if($count == 1) {
   print t(\'@count item\', array( \'@count\' => $count)); 
} else {
   print t(\'@count items\', array( \'@count\' => $count)); 
}

?>',
      'format' => 'ds_code',
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
  $ds_layout->id = 'node|collection|collections_browse';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'collections_browse';
  $ds_layout->layout = 'bootstrap_6_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'collection_item_count',
        3 => 'field_collection_summary',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'left',
      'title' => 'right',
      'collection_item_count' => 'right',
      'field_collection_summary' => 'right',
      'node_link' => 'right',
    ),
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
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
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
    'regions' => array(
      'top' => array(
        0 => 'field_collection_image',
        1 => 'title',
        2 => 'field_collection_summary',
        3 => 'field_collection_credit',
        4 => 'field_description',
      ),
      'left' => array(
        5 => 'field_digital_heritage_items',
      ),
      'right' => array(
        6 => 'collections_tree',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'top',
      'title' => 'top',
      'field_collection_summary' => 'top',
      'field_collection_credit' => 'top',
      'field_description' => 'top',
      'field_digital_heritage_items' => 'left',
      'collections_tree' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
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
  $ds_layout->id = 'node|collection|featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'featured_content_view_link',
        1 => 'field_collection_image',
        2 => 'featured_content_type',
        3 => 'title',
        4 => 'field_collection_summary',
      ),
    ),
    'fields' => array(
      'featured_content_view_link' => 'central',
      'field_collection_image' => 'central',
      'featured_content_type' => 'central',
      'title' => 'central',
      'field_collection_summary' => 'central',
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
  $export['node|collection|featured_content'] = $ds_layout;

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
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'group_basic' => 'ds_content',
      'group_tabs' => 'ds_content',
      'group_items' => 'ds_content',
      'path' => 'ds_content',
      'group_collections_related' => 'ds_content',
      'title' => 'ds_content',
      'redirect' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_community_ref' => 'hidden',
      'field_digital_heritage_items' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_description' => 'ds_content',
      'field_digital_heritage_count' => 'hidden',
      'field_item_privacy_setting' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_collection_credit' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_collections_parent_coll' => 'ds_content',
      'field_collections_child_coll' => 'ds_content',
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
  $export['node|collection|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'title',
        2 => 'featured_content_type',
        3 => 'group_list_view_fields',
        4 => 'field_collection_summary',
        5 => 'field_collection_credit',
      ),
      'left' => array(
        1 => 'field_collection_image',
      ),
    ),
    'fields' => array(
      'title' => 'right',
      'field_collection_image' => 'left',
      'featured_content_type' => 'right',
      'group_list_view_fields' => 'right',
      'field_collection_summary' => 'right',
      'field_collection_credit' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
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
  $ds_layout->id = 'node|collection|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
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
    'fields' => array(
      'field_collection_image' => 'left',
      'title' => 'right',
      'featured_content_type' => 'right',
      'field_collection_summary' => 'right',
      'field_collection_credit' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
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
    'regions' => array(
      'top' => array(
        0 => 'field_collection_image',
        1 => 'title',
        2 => 'field_personal_coll_privacy',
        3 => 'field_collection_summary',
        4 => 'field_description',
      ),
      'bottom' => array(
        5 => 'field_digital_heritage_items',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'top',
      'title' => 'top',
      'field_personal_coll_privacy' => 'top',
      'field_collection_summary' => 'top',
      'field_description' => 'top',
      'field_digital_heritage_items' => 'bottom',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
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
        2 => 'group_tabs',
        3 => 'field_personal_coll_privacy',
        4 => 'redirect',
        5 => 'field_collection_summary',
        6 => 'path',
        7 => 'field_description',
        9 => 'field_collection_image',
        10 => 'field_digital_heritage_items',
        12 => 'group_basic',
        13 => 'group_items',
      ),
      'hidden' => array(
        8 => 'field_digital_heritage_count',
        11 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'group_tabs' => 'ds_content',
      'field_personal_coll_privacy' => 'ds_content',
      'redirect' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'path' => 'ds_content',
      'field_description' => 'ds_content',
      'field_digital_heritage_count' => 'hidden',
      'field_collection_image' => 'ds_content',
      'field_digital_heritage_items' => 'ds_content',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personal_collection|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personal_collection';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'featured_content_type',
        3 => 'collection_item_count',
        4 => 'field_collection_summary',
        5 => 'field_personal_coll_privacy',
      ),
    ),
    'fields' => array(
      'field_collection_image' => 'left',
      'title' => 'right',
      'featured_content_type' => 'right',
      'collection_item_count' => 'right',
      'field_collection_summary' => 'right',
      'field_personal_coll_privacy' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
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
