<?php
/**
 * @file
 * ma_community.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_community_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|community|browse_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'community';
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
  $export['node|community|browse_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|community|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'community';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'admin_actions' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|community|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|community|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'community';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'admin_actions' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|community|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|community|thumbed';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'community';
  $ds_fieldsetting->view_mode = 'thumbed';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
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
  $export['node|community|thumbed'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_community_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|community|browse_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'community';
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
  $export['node|community|browse_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|community|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'community';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'comments',
      ),
      'right' => array(
        2 => 'links',
        3 => 'admin_actions',
        4 => 'group_register',
        5 => 'group_group',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'comments' => 'left',
      'links' => 'right',
      'admin_actions' => 'right',
      'group_register' => 'right',
      'group_group' => 'right',
    ),
    'classes' => array(),
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
  );
  $export['node|community|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|community|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'community';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_basic',
        1 => 'title',
        2 => 'group_tabs',
        3 => 'body',
        4 => 'redirect',
        5 => 'group_advanced',
        6 => 'field_community_image',
        7 => 'path',
        9 => 'field_community_image_thumbnail',
        10 => 'field_parent_community',
        11 => 'group_access',
        13 => 'group_register',
        14 => 'og_roles_permissions',
      ),
      'hidden' => array(
        8 => 'group_group',
        12 => 'og_group_ref',
        15 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_basic' => 'ds_content',
      'title' => 'ds_content',
      'group_tabs' => 'ds_content',
      'body' => 'ds_content',
      'redirect' => 'ds_content',
      'group_advanced' => 'ds_content',
      'field_community_image' => 'ds_content',
      'path' => 'ds_content',
      'group_group' => 'hidden',
      'field_community_image_thumbnail' => 'ds_content',
      'field_parent_community' => 'ds_content',
      'group_access' => 'ds_content',
      'og_group_ref' => 'hidden',
      'group_register' => 'ds_content',
      'og_roles_permissions' => 'ds_content',
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
  $export['node|community|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|community|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'community';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'links',
      ),
      'left' => array(
        1 => 'body',
      ),
      'right' => array(
        2 => 'group_group',
        3 => 'admin_actions',
        4 => 'group_register',
      ),
    ),
    'fields' => array(
      'links' => 'header',
      'body' => 'left',
      'group_group' => 'right',
      'admin_actions' => 'right',
      'group_register' => 'right',
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
  );
  $export['node|community|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|community|thumbed';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'community';
  $ds_layout->view_mode = 'thumbed';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_community_image_thumbnail',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_community_image_thumbnail' => 'ds_content',
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
  $export['node|community|thumbed'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_community_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'thumbed';
  $ds_view_mode->label = 'Thumbed';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['thumbed'] = $ds_view_mode;

  return $export;
}
