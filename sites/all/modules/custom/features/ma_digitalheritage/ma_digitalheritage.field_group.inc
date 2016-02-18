<?php
/**
 * @file
 * ma_digitalheritage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_digitalheritage_field_group_info() {
  $export = array();

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
  $export['group_advanced|taxonomy_term|category|form'] = $field_group;

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
  $export['group_basic|taxonomy_term|category|form'] = $field_group;

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
    'label' => 'Additional Metadata',
    'weight' => '4',
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
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Additional Metadata',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_dublin|node|digital_heritage|form'] = $field_group;

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
    'label' => 'Mukurtu Essentials',
    'weight' => '1',
    'children' => array(
      0 => 'field_summary',
      1 => 'field_category',
      2 => 'field_contributor',
      3 => 'field_creator',
      4 => 'field_date',
      5 => 'field_item_privacy_setting',
      6 => 'field_media_asset',
      7 => 'og_group_ref',
      8 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Mukurtu Essentials',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_essentials|node|digital_heritage|form'] = $field_group;

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
    'label' => 'Rights and Permissions',
    'weight' => '3',
    'children' => array(
      0 => 'field_licence_std_cc',
      1 => 'field_licence_trad',
      2 => 'field_publisher',
      3 => 'field_rights',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Rights and Permissions',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_licensing|node|digital_heritage|form'] = $field_group;

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
    'label' => 'List View Fields',
    'weight' => '2',
    'children' => array(
      0 => 'field_community_ref',
      1 => 'field_summary',
      2 => 'field_category',
      3 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'List View Fields',
      'instance_settings' => array(
        'classes' => 'col-md-8 col-md-pull-4',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_list_view_fields|node|digital_heritage|search_result'] = $field_group;

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
    'label' => 'Mukurtu Core',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_description',
      2 => 'field_tags',
      3 => 'field_tk_body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Mukurtu Core',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mukurtu_core|node|digital_heritage|form'] = $field_group;

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
    'label' => 'Relations',
    'weight' => '5',
    'children' => array(
      0 => 'field_book_children',
      1 => 'field_book_parent',
      2 => 'field_collection',
      3 => 'field_community_record_children',
      4 => 'field_related_dh_items',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Relations',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_relations|node|digital_heritage|form'] = $field_group;

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
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_dublin',
      1 => 'group_essentials',
      2 => 'group_licensing',
      3 => 'group_mukurtu_core',
      4 => 'group_relations',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs|node|digital_heritage|form'] = $field_group;

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
  $export['group_tabs|taxonomy_term|category|form'] = $field_group;

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
    'label' => 'Transcription:',
    'weight' => '5',
    'children' => array(
      0 => 'field_transcription',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Transcription:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-transcription-cr field-group-div mukurtu-collapsed-fieldset-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_transcription_cr|node|digital_heritage|community_record'] = $field_group;

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
    'label' => 'Transcription:',
    'weight' => '6',
    'children' => array(
      0 => 'field_transcription',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Transcription:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-transcription field-group-div mukurtu-collapsed-fieldset-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_transcription|node|digital_heritage|full'] = $field_group;

  return $export;
}
