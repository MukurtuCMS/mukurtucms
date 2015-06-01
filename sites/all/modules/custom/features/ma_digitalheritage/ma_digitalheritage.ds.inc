<?php
/**
 * @file
 * ma_digitalheritage.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_digitalheritage_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|community_record';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'community_record';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '7',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'author' => array(
      'weight' => '26',
      'label' => 'above',
      'format' => 'author',
    ),
  );
  $export['node|digital_heritage|community_record'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '28',
      'label' => 'above',
      'format' => 'author_linked',
    ),
    'field_collection' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_community_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_dh_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
  );
  $export['node|digital_heritage|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
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
    'field_media_asset' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'col-md-4 col-md-push-8',
        ),
      ),
    ),
  );
  $export['node|digital_heritage|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_digitalheritage_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|community_record';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'community_record';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_summary',
        1 => 'field_media_asset',
        2 => 'field_description',
        3 => 'body',
        4 => 'field_tk_body',
        5 => 'field_coverage',
        6 => 'field_coverage_description',
      ),
      'right' => array(
        7 => 'title',
        8 => 'field_community_ref',
        9 => 'og_group_ref',
        10 => 'field_category',
        11 => 'field_tags',
        12 => 'field_date',
        13 => 'field_creator',
        14 => 'field_contributor',
        15 => 'field_language',
        16 => 'field_rights',
        17 => 'field_licence_trad',
        18 => 'field_licence_std_cc',
        19 => 'field_source',
        20 => 'field_publisher',
        21 => 'field_identifier',
        22 => 'field_subject',
        23 => 'field_transcription',
        24 => 'field_dh_type',
        25 => 'field_format',
        26 => 'author',
      ),
    ),
    'fields' => array(
      'field_summary' => 'left',
      'field_media_asset' => 'left',
      'field_description' => 'left',
      'body' => 'left',
      'field_tk_body' => 'left',
      'field_coverage' => 'left',
      'field_coverage_description' => 'left',
      'title' => 'right',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_category' => 'right',
      'field_tags' => 'right',
      'field_date' => 'right',
      'field_creator' => 'right',
      'field_contributor' => 'right',
      'field_language' => 'right',
      'field_rights' => 'right',
      'field_licence_trad' => 'right',
      'field_licence_std_cc' => 'right',
      'field_source' => 'right',
      'field_publisher' => 'right',
      'field_identifier' => 'right',
      'field_subject' => 'right',
      'field_transcription' => 'right',
      'field_dh_type' => 'right',
      'field_format' => 'right',
      'author' => 'right',
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
  $export['node|digital_heritage|community_record'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_tabs',
        1 => 'group_essentials',
        4 => 'title',
        5 => 'group_mukurtu_core',
        7 => 'group_licensing',
        8 => 'group_dublin',
        10 => 'group_relations',
        11 => 'field_tk_body',
        12 => 'body',
        13 => 'field_description',
        14 => 'field_tags',
        15 => 'field_format',
        16 => 'field_collection',
        17 => 'field_dh_type',
        18 => 'field_related_dh_items',
        19 => 'field_identifier',
        20 => 'field_community_record_children',
        21 => 'field_language',
        22 => 'field_source',
        23 => 'field_subject',
        24 => 'field_transcription',
        25 => 'field_coverage',
        26 => 'field_coverage_description',
        27 => 'field_publisher',
        28 => 'field_rights',
        29 => 'field_licence_trad',
        30 => 'field_licence_std_cc',
        31 => 'field_summary',
        32 => 'field_media_asset',
        33 => 'og_group_ref',
        34 => 'field_item_privacy_setting',
        35 => 'field_category',
        36 => 'field_creator',
        37 => 'field_contributor',
        38 => 'field_date',
      ),
      'hidden' => array(
        2 => 'field_community_record_parent',
        3 => 'path',
        6 => 'field_community_ref',
        9 => 'redirect',
        39 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_tabs' => 'ds_content',
      'group_essentials' => 'ds_content',
      'field_community_record_parent' => 'hidden',
      'path' => 'hidden',
      'title' => 'ds_content',
      'group_mukurtu_core' => 'ds_content',
      'field_community_ref' => 'hidden',
      'group_licensing' => 'ds_content',
      'group_dublin' => 'ds_content',
      'redirect' => 'hidden',
      'group_relations' => 'ds_content',
      'field_tk_body' => 'ds_content',
      'body' => 'ds_content',
      'field_description' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_format' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_dh_type' => 'ds_content',
      'field_related_dh_items' => 'ds_content',
      'field_identifier' => 'ds_content',
      'field_community_record_children' => 'ds_content',
      'field_language' => 'ds_content',
      'field_source' => 'ds_content',
      'field_subject' => 'ds_content',
      'field_transcription' => 'ds_content',
      'field_coverage' => 'ds_content',
      'field_coverage_description' => 'ds_content',
      'field_publisher' => 'ds_content',
      'field_rights' => 'ds_content',
      'field_licence_trad' => 'ds_content',
      'field_licence_std_cc' => 'ds_content',
      'field_summary' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_category' => 'ds_content',
      'field_creator' => 'ds_content',
      'field_contributor' => 'ds_content',
      'field_date' => 'ds_content',
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
  $export['node|digital_heritage|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_summary',
        1 => 'field_media_asset',
        2 => 'field_description',
        3 => 'body',
        4 => 'field_tk_body',
        5 => 'field_coverage',
        6 => 'field_coverage_description',
        7 => 'field_related_dh_items',
        8 => 'comments',
      ),
      'right' => array(
        9 => 'field_community_ref',
        10 => 'og_group_ref',
        11 => 'field_category',
        12 => 'field_tags',
        13 => 'field_collection',
        14 => 'field_date',
        15 => 'field_creator',
        16 => 'field_contributor',
        17 => 'field_language',
        18 => 'field_rights',
        19 => 'field_licence_trad',
        20 => 'field_licence_std_cc',
        21 => 'field_source',
        22 => 'field_publisher',
        23 => 'field_identifier',
        24 => 'field_subject',
        25 => 'field_transcription',
        26 => 'field_dh_type',
        27 => 'field_format',
        28 => 'author',
      ),
    ),
    'fields' => array(
      'field_summary' => 'left',
      'field_media_asset' => 'left',
      'field_description' => 'left',
      'body' => 'left',
      'field_tk_body' => 'left',
      'field_coverage' => 'left',
      'field_coverage_description' => 'left',
      'field_related_dh_items' => 'left',
      'comments' => 'left',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_category' => 'right',
      'field_tags' => 'right',
      'field_collection' => 'right',
      'field_date' => 'right',
      'field_creator' => 'right',
      'field_contributor' => 'right',
      'field_language' => 'right',
      'field_rights' => 'right',
      'field_licence_trad' => 'right',
      'field_licence_std_cc' => 'right',
      'field_source' => 'right',
      'field_publisher' => 'right',
      'field_identifier' => 'right',
      'field_subject' => 'right',
      'field_transcription' => 'right',
      'field_dh_type' => 'right',
      'field_format' => 'right',
      'author' => 'right',
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
  $export['node|digital_heritage|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_media_asset',
        1 => 'title',
        2 => 'field_community_ref',
        3 => 'group_list_view_fields',
        4 => 'field_category',
        5 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'ds_content',
      'title' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'group_list_view_fields' => 'ds_content',
      'field_category' => 'ds_content',
      'field_summary' => 'ds_content',
    ),
    'limit' => array(
      'field_media_asset' => '1',
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
  $export['node|digital_heritage|search_result'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_digitalheritage_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'community_record';
  $ds_view_mode->label = 'Community Record';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['community_record'] = $ds_view_mode;

  return $export;
}
