<?php

/**
 * @file
 * ma_culturalprotocol.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_culturalprotocol_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cultural_protocol_group|browse_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cultural_protocol_group';
  $ds_fieldsetting->view_mode = 'browse_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|cultural_protocol_group|browse_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cultural_protocol_group|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cultural_protocol_group';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'admin_actions' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'author',
    ),
  );
  $export['node|cultural_protocol_group|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cultural_protocol_group|featured_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cultural_protocol_group';
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
  $export['node|cultural_protocol_group|featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cultural_protocol_group|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cultural_protocol_group';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'mukurtu_mobile_sync' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dhan_notify' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'group_management_links' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'group_members' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'create_content_block_ds_field' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'protocol_dh_items' => array(
      'weight' => '3',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'og_group_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|cultural_protocol_group|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cultural_protocol_group|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cultural_protocol_group';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'og_group_ref' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_comm_dh_items' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|cultural_protocol_group|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cultural_protocol_group|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cultural_protocol_group';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
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
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|cultural_protocol_group|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_culturalprotocol_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'protocol_dh_items';
  $ds_field->label = 'Recent DH Items';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'cultural_protocol_group|full';
  $ds_field->properties = array(
    'block' => 'views|community_dh_items-block_2',
    'block_render' => '3',
  );
  $export['protocol_dh_items'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_culturalprotocol_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cultural_protocol_group|browse_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cultural_protocol_group';
  $ds_layout->view_mode = 'browse_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_media',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_media' => 'ds_content',
      'title' => 'ds_content',
    ),
    'limit' => array(
      'field_media' => '1',
    ),
    'classes' => array(),
  );
  $export['node|cultural_protocol_group|browse_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cultural_protocol_group|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cultural_protocol_group';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        1 => 'comments',
        2 => 'body',
        5 => 'group_register',
      ),
      'right' => array(
        3 => 'author',
        4 => 'admin_actions',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'comments' => 'left',
      'body' => 'left',
      'author' => 'right',
      'admin_actions' => 'right',
      'group_register' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|cultural_protocol_group|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cultural_protocol_group|featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cultural_protocol_group';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'featured_content_view_link',
        1 => 'field_protocol_image_thumbnail',
        2 => 'featured_content_type',
        3 => 'title',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'featured_content_view_link' => 'central',
      'field_protocol_image_thumbnail' => 'central',
      'featured_content_type' => 'central',
      'title' => 'central',
      'body' => 'central',
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
  $export['node|cultural_protocol_group|featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cultural_protocol_group|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cultural_protocol_group';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'mukurtu_mobile_sync',
        1 => 'field_protocol_image',
      ),
      'left' => array(
        2 => 'body',
        3 => 'group_management_links',
        4 => 'protocol_dh_items',
      ),
      'right' => array(
        5 => 'og_group_ref',
        6 => 'dhan_notify',
        7 => 'create_content_block_ds_field',
        4 => 'group_members',
      ),
    ),
    'fields' => array(
      'mukurtu_mobile_sync' => 'top',
      'field_protocol_image' => 'top',
      'body' => 'left',
      'group_management_links' => 'left',
      'protocol_dh_items' => 'left',
      'group_members' => 'right',
      'og_group_ref' => 'right',
      'dhan_notify' => 'right',
      'create_content_block_ds_field' => 'right',
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
  $export['node|cultural_protocol_group|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cultural_protocol_group|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cultural_protocol_group';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_protocol_image',
        2 => 'body',
        3 => 'og_group_ref',
        4 => 'field_comm_dh_items',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_protocol_image' => 'ds_content',
      'body' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_comm_dh_items' => 'ds_content',
    ),
    'limit' => array(
      'field_comm_dh_items' => '8',
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
  $export['node|cultural_protocol_group|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cultural_protocol_group|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cultural_protocol_group';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'title',
        2 => 'featured_content_type',
        3 => 'body',
      ),
      'left' => array(
        1 => 'field_protocol_image_thumbnail',
      ),
    ),
    'fields' => array(
      'title' => 'right',
      'field_protocol_image_thumbnail' => 'left',
      'featured_content_type' => 'right',
      'body' => 'right',
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
  $export['node|cultural_protocol_group|teaser'] = $ds_layout;

  return $export;
}
