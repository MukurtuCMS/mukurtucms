<?php
/**
 * @file
 * ma_collaboration_tools.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_collaboration_tools_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|calendar|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'calendar';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|calendar|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|discussion_space|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'discussion_space';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|discussion_space|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document_library|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document_library';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document_library|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_collaboration_tools_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|calendar|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'calendar';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'og_group_ref',
        1 => 'body',
        2 => 'field_item_privacy_setting',
        3 => 'field_community_ref',
        4 => 'field_pre_actions',
      ),
    ),
    'fields' => array(
      'og_group_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_pre_actions' => 'ds_content',
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
  $export['node|calendar|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|calendar|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'calendar';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'group_access',
        4 => 'path',
        5 => 'og_group_ref',
        6 => 'redirect',
        7 => 'field_item_privacy_setting',
      ),
      'hidden' => array(
        8 => 'field_community_ref',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'group_access' => 'ds_content',
      'path' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'redirect' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
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
  $export['node|calendar|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|calendar|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'calendar';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
        2 => 'comments',
      ),
      'right' => array(
        3 => 'field_community_ref',
        4 => 'og_group_ref',
        5 => 'field_item_privacy_setting',
        6 => 'group_access',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'comments' => 'left',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_item_privacy_setting' => 'right',
      'group_access' => 'right',
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
    'layout_disable_css' => 0,
  );
  $export['node|calendar|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion_space|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_space';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'og_group_ref',
        1 => 'body',
        2 => 'field_item_privacy_setting',
        3 => 'field_community_ref',
        4 => 'field_pre_actions',
      ),
    ),
    'fields' => array(
      'og_group_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_pre_actions' => 'ds_content',
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
  $export['node|discussion_space|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion_space|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_space';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'group_access',
        4 => 'path',
        5 => 'og_group_ref',
        6 => 'redirect',
        7 => 'field_item_privacy_setting',
      ),
      'hidden' => array(
        8 => 'field_community_ref',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'group_access' => 'ds_content',
      'path' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'redirect' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
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
  $export['node|discussion_space|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion_space|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_space';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
        2 => 'comments',
      ),
      'right' => array(
        3 => 'field_community_ref',
        4 => 'og_group_ref',
        5 => 'field_item_privacy_setting',
        6 => 'group_access',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'comments' => 'left',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_item_privacy_setting' => 'right',
      'group_access' => 'right',
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
    'layout_disable_css' => 0,
  );
  $export['node|discussion_space|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_library|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_library';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'og_group_ref',
        1 => 'body',
        2 => 'field_item_privacy_setting',
        3 => 'field_community_ref',
        4 => 'field_pre_actions',
      ),
    ),
    'fields' => array(
      'og_group_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_pre_actions' => 'ds_content',
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
  $export['node|document_library|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_library|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_library';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'group_access',
        4 => 'path',
        5 => 'og_group_ref',
        6 => 'redirect',
        7 => 'field_item_privacy_setting',
      ),
      'hidden' => array(
        8 => 'field_community_ref',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'group_access' => 'ds_content',
      'path' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'redirect' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
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
  $export['node|document_library|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_library|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_library';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
        2 => 'comments',
      ),
      'right' => array(
        3 => 'field_community_ref',
        4 => 'og_group_ref',
        5 => 'field_item_privacy_setting',
        6 => 'group_access',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'comments' => 'left',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_item_privacy_setting' => 'right',
      'group_access' => 'right',
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
    'layout_disable_css' => 0,
  );
  $export['node|document_library|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|oa_discussion_post|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_discussion_post';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'og_group_ref',
        2 => 'field_item_privacy_setting',
        3 => 'oa_section_ref',
        4 => 'body',
        5 => 'field_oa_media',
        6 => 'redirect',
        7 => 'path',
      ),
      'hidden' => array(
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'oa_section_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
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
  $export['node|oa_discussion_post|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|oa_event|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_event';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'og_group_ref',
        3 => 'field_item_privacy_setting',
        4 => 'field_oa_address',
        5 => 'field_oa_media',
        6 => 'oa_section_ref',
        7 => 'field_oa_date',
        8 => 'field_oa_geo_location',
        9 => 'path',
        10 => 'redirect',
      ),
      'hidden' => array(
        11 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_oa_address' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'oa_section_ref' => 'ds_content',
      'field_oa_date' => 'ds_content',
      'field_oa_geo_location' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
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
  $export['node|oa_event|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|oa_wiki_page|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_wiki_page';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_oa_wiki_page_no_redirect',
        3 => 'field_oa_media',
        4 => 'og_group_ref',
        5 => 'oa_section_ref',
        6 => 'field_item_privacy_setting',
        7 => 'path',
        8 => 'redirect',
      ),
      'hidden' => array(
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_wiki_page_no_redirect' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'oa_section_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
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
  $export['node|oa_wiki_page|form'] = $ds_layout;

  return $export;
}
