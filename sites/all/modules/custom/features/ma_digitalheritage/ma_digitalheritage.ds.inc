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
    'edit_community_record' => array(
      'weight' => '26',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '23',
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
      'format' => 'author',
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
    'field_community_record_children' => array(
      'formatter_settings' => array(
        'ft' => array(),
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
 * Implements hook_ds_custom_fields_info().
 */
function ma_digitalheritage_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'edit_community_record';
  $ds_field->label = 'Edit Community Record';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'digital_heritage|community_record';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
if (node_access (\'update\', $entity)) print l(\'<br/><b>EDIT COMMUNITY RECORD</b>\', \'node/\' . $entity->nid . \'/edit\', array (\'html\' => TRUE));
?>
',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['edit_community_record'] = $ds_field;

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
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_community_record_accordion',
        1 => 'group_community_record',
        2 => 'field_summary',
        3 => 'field_community_ref',
        4 => 'og_group_ref',
        5 => 'field_category',
        6 => 'field_description',
        7 => 'body',
        8 => 'field_tk_body',
        9 => 'field_tags',
        10 => 'field_date',
        11 => 'field_creator',
        12 => 'field_contributor',
        13 => 'field_language',
        14 => 'field_rights',
        15 => 'field_licence_trad',
        16 => 'field_licence_std_cc',
        17 => 'field_source',
        18 => 'field_publisher',
        19 => 'field_identifier',
        20 => 'field_subject',
        21 => 'field_dh_type',
        22 => 'field_format',
        23 => 'author',
        24 => 'field_coverage',
        25 => 'field_coverage_description',
        26 => 'edit_community_record',
      ),
    ),
    'fields' => array(
      'group_community_record_accordion' => 'ds_content',
      'group_community_record' => 'ds_content',
      'field_summary' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_category' => 'ds_content',
      'field_description' => 'ds_content',
      'body' => 'ds_content',
      'field_tk_body' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_date' => 'ds_content',
      'field_creator' => 'ds_content',
      'field_contributor' => 'ds_content',
      'field_language' => 'ds_content',
      'field_rights' => 'ds_content',
      'field_licence_trad' => 'ds_content',
      'field_licence_std_cc' => 'ds_content',
      'field_source' => 'ds_content',
      'field_publisher' => 'ds_content',
      'field_identifier' => 'ds_content',
      'field_subject' => 'ds_content',
      'field_dh_type' => 'ds_content',
      'field_format' => 'ds_content',
      'author' => 'ds_content',
      'field_coverage' => 'ds_content',
      'field_coverage_description' => 'ds_content',
      'edit_community_record' => 'ds_content',
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
        2 => 'group_essentials',
        3 => 'group_mukurtu_core',
        5 => 'title',
        7 => 'group_licensing',
        9 => 'group_dublin',
        10 => 'group_relations',
        11 => 'field_tk_body',
        12 => 'body',
        13 => 'field_description',
        14 => 'field_tags',
        15 => 'field_format',
        16 => 'field_collection',
        17 => 'field_dh_type',
        18 => 'field_identifier',
        19 => 'field_related_dh_items',
        20 => 'field_community_record_children',
        21 => 'field_language',
        22 => 'field_source',
        23 => 'field_subject',
        24 => 'field_coverage',
        25 => 'field_coverage_description',
        26 => 'field_publisher',
        27 => 'field_rights',
        28 => 'field_licence_trad',
        29 => 'field_licence_std_cc',
        30 => 'field_summary',
        31 => 'field_media_asset',
        32 => 'og_group_ref',
        33 => 'field_item_privacy_setting',
        34 => 'field_category',
        35 => 'field_creator',
        36 => 'field_contributor',
        37 => 'field_date',
      ),
      'hidden' => array(
        1 => 'field_community_record_parent',
        4 => 'path',
        6 => 'field_community_ref',
        8 => 'redirect',
        38 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_tabs' => 'ds_content',
      'field_community_record_parent' => 'hidden',
      'group_essentials' => 'ds_content',
      'group_mukurtu_core' => 'ds_content',
      'path' => 'hidden',
      'title' => 'ds_content',
      'field_community_ref' => 'hidden',
      'group_licensing' => 'ds_content',
      'redirect' => 'hidden',
      'group_dublin' => 'ds_content',
      'group_relations' => 'ds_content',
      'field_tk_body' => 'ds_content',
      'body' => 'ds_content',
      'field_description' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_format' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_dh_type' => 'ds_content',
      'field_identifier' => 'ds_content',
      'field_related_dh_items' => 'ds_content',
      'field_community_record_children' => 'ds_content',
      'field_language' => 'ds_content',
      'field_source' => 'ds_content',
      'field_subject' => 'ds_content',
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
        5 => 'field_related_dh_items',
        6 => 'field_coverage',
        7 => 'field_coverage_description',
        8 => 'comments',
      ),
      'right' => array(
        9 => 'group_digital_heritage_accordion',
        10 => 'field_community_record_children',
        11 => 'group_digital_heritage_metadata',
        12 => 'field_community_ref',
        13 => 'og_group_ref',
        14 => 'field_category',
        15 => 'field_tags',
        16 => 'field_collection',
        17 => 'field_date',
        18 => 'field_creator',
        19 => 'field_contributor',
        20 => 'field_language',
        21 => 'field_rights',
        22 => 'field_licence_trad',
        23 => 'field_licence_std_cc',
        24 => 'field_source',
        25 => 'field_publisher',
        26 => 'field_identifier',
        27 => 'field_subject',
        28 => 'field_dh_type',
        29 => 'field_format',
        30 => 'author',
      ),
    ),
    'fields' => array(
      'field_summary' => 'left',
      'field_media_asset' => 'left',
      'field_description' => 'left',
      'body' => 'left',
      'field_tk_body' => 'left',
      'field_related_dh_items' => 'left',
      'field_coverage' => 'left',
      'field_coverage_description' => 'left',
      'comments' => 'left',
      'group_digital_heritage_accordion' => 'right',
      'field_community_record_children' => 'right',
      'group_digital_heritage_metadata' => 'right',
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
