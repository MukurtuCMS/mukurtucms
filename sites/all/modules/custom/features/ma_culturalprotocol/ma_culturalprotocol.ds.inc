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
  $ds_fieldsetting->id = 'node|cultural_protocol_group|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cultural_protocol_group';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'group_management_links' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'og_members' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'protocol_dh_items' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cultural_protocol_group|full'] = $ds_fieldsetting;

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
  $ds_field->label = 'Protocol DH Items';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'cultural_protocol_group|full';
  $ds_field->properties = array(
    'block' => 'views|community_dh_items-block_2',
    'block_render' => '1',
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
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        0 => 'comments',
        1 => 'field_media',
        2 => 'body',
        3 => 'group_register',
      ),
      'right' => array(
        0 => 'author',
        1 => 'admin_actions',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'comments' => 'left',
      'field_media' => 'left',
      'body' => 'left',
      'group_register' => 'left',
      'author' => 'right',
      'admin_actions' => 'right',
    ),
    'classes' => array(
      'header' => array(
        'grid-6' => 'grid-6',
      ),
      'left' => array(
        'grid-6' => 'grid-6',
      ),
      'right' => array(
        'grid-4' => 'grid-4',
      ),
    ),
  );
  $export['node|cultural_protocol_group|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cultural_protocol_group|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cultural_protocol_group';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_protocol_image',
        1 => 'group_management_links',
        2 => 'body',
        3 => 'protocol_dh_items',
      ),
      'right' => array(
        4 => 'og_members',
        5 => 'og_group_ref',
      ),
    ),
    'fields' => array(
      'field_protocol_image' => 'left',
      'group_management_links' => 'left',
      'body' => 'left',
      'protocol_dh_items' => 'left',
      'og_members' => 'right',
      'og_group_ref' => 'right',
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
  );
  $export['node|cultural_protocol_group|full'] = $ds_layout;

  return $export;
}
