<?php

/**
 * @file
 * ma_digitalheritage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_digitalheritage_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|taxonomy_term|category|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'category';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = '';
  $field_groups['group_advanced|taxonomy_term|category|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|taxonomy_term|category|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'category';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = '';
  $field_groups['group_basic|taxonomy_term|category|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dublin|node|digital_heritage|form';
  $field_group->group_name = 'group_dublin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_dh_type',
      1 => 'field_transcription',
      2 => 'field_coverage',
      3 => 'field_coverage_description',
      4 => 'field_format',
      5 => 'field_identifier',
      6 => 'field_language',
      7 => 'field_source',
      8 => 'field_subject',
      9 => 'field_people',
      10 => 'field_external_links',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 0,
      ),
      'label' => 'Additional Metadata',
    ),
    'format_type' => 'htab',
    'label' => 'Additional Metadata',
    'weight' => '11',
  );
  $field_groups['group_dublin|node|digital_heritage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_essentials|node|digital_heritage|form';
  $field_group->group_name = 'group_essentials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_summary',
      1 => 'field_category',
      2 => 'field_contributor',
      3 => 'field_creator',
      4 => 'field_date',
      5 => 'field_item_privacy_setting',
      6 => 'field_media_asset',
      7 => 'og_group_ref',
      8 => 'field_original_date',
      9 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Mukurtu Essentials',
    ),
    'format_type' => 'htab',
    'label' => 'Mukurtu Essentials',
    'weight' => '8',
  );
  $field_groups['group_essentials|node|digital_heritage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_licensing|node|digital_heritage|form';
  $field_group->group_name = 'group_licensing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_licence_std_cc',
      1 => 'field_licence_trad',
      2 => 'field_publisher',
      3 => 'field_rights',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 0,
      ),
      'label' => 'Rights and Permissions',
    ),
    'format_type' => 'htab',
    'label' => 'Rights and Permissions',
    'weight' => '10',
  );
  $field_groups['group_licensing|node|digital_heritage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_view_fields|node|digital_heritage|search_result';
  $field_group->group_name = 'group_list_view_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_community_ref',
      1 => 'field_summary',
      2 => 'field_category',
      3 => 'digital_heritage_page_number',
      4 => 'featured_content_type',
      5 => 'mukurtu_icon_actions',
      6 => 'mukurtu_mobile_sync',
      7 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'List View Fields',
    ),
    'format_type' => 'div',
    'label' => 'List View Fields',
    'weight' => '1',
  );
  $field_groups['group_list_view_fields|node|digital_heritage|search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_div|node|digital_heritage|taxonomy_record_teaser';
  $field_group->group_name = 'group_location_div';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'taxonomy_record_teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-location-div field-group-div col-md-3',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'none',
      ),
      'label' => 'Location',
    ),
    'format_type' => 'div',
    'label' => 'Location',
    'weight' => '22',
  );
  $field_groups['group_location_div|node|digital_heritage|taxonomy_record_teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_div|node|digital_heritage|taxonomy_record_teaser';
  $field_group->group_name = 'group_media_div';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'taxonomy_record_teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-media-div field-group-div col-md-3',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'none',
      ),
      'label' => 'Media',
    ),
    'format_type' => 'div',
    'label' => 'Media',
    'weight' => '21',
  );
  $field_groups['group_media_div|node|digital_heritage|taxonomy_record_teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_div|node|digital_heritage|taxonomy_record_teaser';
  $field_group->group_name = 'group_metadata_div';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'taxonomy_record_teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-metadata-div field-group-div col-md-6',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'none',
      ),
      'label' => 'Metadata',
    ),
    'format_type' => 'div',
    'label' => 'Metadata',
    'weight' => '23',
  );
  $field_groups['group_metadata_div|node|digital_heritage|taxonomy_record_teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mukurtu_core|node|digital_heritage|form';
  $field_group->group_name = 'group_mukurtu_core';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'body',
      1 => 'field_description',
      2 => 'field_tags',
      3 => 'field_tk_body',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 0,
      ),
      'label' => 'Mukurtu Core',
    ),
    'format_type' => 'htab',
    'label' => 'Mukurtu Core',
    'weight' => '9',
  );
  $field_groups['group_mukurtu_core|node|digital_heritage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relations|node|digital_heritage|form';
  $field_group->group_name = 'group_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_book_children',
      1 => 'field_book_parent',
      2 => 'field_collection',
      3 => 'field_community_record_children',
      4 => 'field_personal_collections',
      5 => 'field_related_content',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 0,
      ),
      'label' => 'Relations',
    ),
    'format_type' => 'htab',
    'label' => 'Relations',
    'weight' => '12',
  );
  $field_groups['group_relations|node|digital_heritage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|digital_heritage|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'group_dublin',
      1 => 'group_essentials',
      2 => 'group_licensing',
      3 => 'group_mukurtu_core',
      4 => 'group_relations',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
    'format_type' => 'htabs',
    'label' => 'Tabs',
    'weight' => '1',
  );
  $field_groups['group_tabs|node|digital_heritage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|taxonomy_term|category|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'category';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = '';
  $field_groups['group_tabs|taxonomy_term|category|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_transcription_cr|node|digital_heritage|community_record';
  $field_group->group_name = 'group_transcription_cr';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'community_record';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_transcription',
    ),
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'classes' => 'group-transcription-cr field-group-div mukurtu-collapsed-fieldset-div',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '1',
        'speed' => 'fast',
      ),
      'label' => 'Transcription:',
    ),
    'format_type' => 'div',
    'label' => 'Transcription:',
    'weight' => '6',
  );
  $field_groups['group_transcription_cr|node|digital_heritage|community_record'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_transcription|node|digital_heritage|full';
  $field_group->group_name = 'group_transcription';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_transcription',
    ),
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'classes' => 'group-transcription field-group-div mukurtu-collapsed-fieldset-div',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '1',
        'speed' => 'fast',
      ),
      'label' => 'Transcription:',
    ),
    'format_type' => 'div',
    'label' => 'Transcription:',
    'weight' => '7',
  );
  $field_groups['group_transcription|node|digital_heritage|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Metadata');
  t('List View Fields');
  t('Location');
  t('Media');
  t('Metadata');
  t('Mukurtu Core');
  t('Mukurtu Essentials');
  t('Relations');
  t('Rights and Permissions');
  t('Tabs');
  t('Transcription:');

  return $field_groups;
}
