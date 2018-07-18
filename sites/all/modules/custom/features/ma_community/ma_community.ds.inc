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
    'create_content_block_ds_field' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'featured_collections' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'community_browse_all_dh_link' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'community_dh_items' => array(
      'weight' => '3',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'community_protocol_items' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
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
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_child_communities' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_parent_community' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
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
 * Implements hook_ds_custom_fields_info().
 */
function ma_community_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'community_browse_all_dh_link';
  $ds_field->label = 'Community Browse All DH Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'community|full';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<h2 class="block-title">Digital Heritage</h2><div class="view-content"><a href="/digital-heritage/community/[node:nid]">Browse All Digital Heritage in [node:title]</a></div>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['community_browse_all_dh_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'community_dh_items';
  $ds_field->label = 'Recent DH Items';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'community|full';
  $ds_field->properties = array(
    'block' => 'views|community_dh_items-block_1',
    'block_render' => '3',
  );
  $export['community_dh_items'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'community_protocol_items';
  $ds_field->label = 'Community Protocol Items';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'community|full';
  $ds_field->properties = array(
    'block' => 'views|bef69c525c1512e210af0dfe32448806',
    'block_render' => '1',
  );
  $export['community_protocol_items'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'featured_collections';
  $ds_field->label = 'Featured Collections';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'community|full';
  $ds_field->properties = array(
    'block' => 'views|afbb1e221e4d23e4297e4855a7f3b89f',
    'block_render' => '2',
  );
  $export['featured_collections'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'group_management_links';
  $ds_field->label = 'Group Management Links';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'community|full
cultural_protocol_group|full';
  $ds_field->properties = array(
    'block' => 'mukurtu_splash|mukurtu_group_management',
    'block_render' => '3',
  );
  $export['group_management_links'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'group_members';
  $ds_field->label = 'Group Members';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|group_members-block_1',
    'block_render' => '1',
  );
  $export['group_members'] = $ds_field;

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
        2 => 'field_pre_actions',
        3 => 'body',
        4 => 'group_tabs',
        5 => 'group_advanced',
        6 => 'field_community_image',
        7 => 'redirect',
        8 => 'group_access',
        9 => 'path',
        10 => 'field_community_image_thumbnail',
        11 => 'field_parent_community',
        12 => 'og_roles_permissions',
        14 => 'field_child_communities',
        15 => 'group_register',
        17 => 'field_community_featured_colls',
        18 => 'field_membership_list_options',
        19 => 'group_custom_tk_label_text',
      ),
      'hidden' => array(
        13 => 'group_group',
        16 => 'og_group_ref',
        20 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_basic' => 'ds_content',
      'title' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'body' => 'ds_content',
      'group_tabs' => 'ds_content',
      'group_advanced' => 'ds_content',
      'field_community_image' => 'ds_content',
      'redirect' => 'ds_content',
      'group_access' => 'ds_content',
      'path' => 'ds_content',
      'field_community_image_thumbnail' => 'ds_content',
      'field_parent_community' => 'ds_content',
      'og_roles_permissions' => 'ds_content',
      'group_group' => 'hidden',
      'field_child_communities' => 'ds_content',
      'group_register' => 'ds_content',
      'og_group_ref' => 'hidden',
      'field_community_featured_colls' => 'ds_content',
      'field_membership_list_options' => 'ds_content',
      'group_custom_tk_label_text' => 'ds_content',
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
        0 => 'field_community_image',
        1 => 'title',
      ),
      'left' => array(
        2 => 'body',
        3 => 'group_management_links',
        4 => 'community_dh_items',
      ),
      'right' => array(
        5 => 'group_members',
        6 => 'community_protocol_items',
        7 => 'field_parent_community',
        8 => 'field_child_communities',
        9 => 'community_browse_all_dh_link',
        10 => 'featured_collections',
        11 => 'create_content_block_ds_field',
      ),
    ),
    'fields' => array(
      'field_community_image' => 'header',
      'title' => 'header',
      'body' => 'left',
      'group_management_links' => 'left',
      'community_dh_items' => 'left',
      'group_members' => 'right',
      'community_protocol_items' => 'right',
      'field_parent_community' => 'right',
      'field_child_communities' => 'right',
      'community_browse_all_dh_link' => 'right',
      'featured_collections' => 'right',
      'create_content_block_ds_field' => 'right',
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
