<?php
/**
 * @file
 * ma_collaboration_tools.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_collaboration_tools_ds_layout_settings_info() {
  $export = array();

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
  $ds_layout->id = 'node|oa_section|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_section';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'og_group_ref',
        3 => 'field_item_privacy_setting',
        4 => 'field_collab_section_type',
        5 => 'redirect',
        6 => 'path',
      ),
      'hidden' => array(
        7 => 'field_community_ref',
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_collab_section_type' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
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
  $export['node|oa_section|form'] = $ds_layout;

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
