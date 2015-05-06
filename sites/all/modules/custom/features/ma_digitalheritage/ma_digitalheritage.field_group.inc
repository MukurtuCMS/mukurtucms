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
  $field_group->identifier = 'group_community_record_accordion|node|digital_heritage|community_record';
  $field_group->group_name = 'group_community_record_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'community_record';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community Record Accordion',
    'weight' => '0',
    'children' => array(
      0 => 'group_community_record',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-community-record-accordion field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_community_record_accordion|node|digital_heritage|community_record'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_community_record|node|digital_heritage|community_record';
  $field_group->group_name = 'group_community_record';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'community_record';
  $field_group->parent_name = 'group_community_record_accordion';
  $field_group->data = array(
    'label' => 'Community Record',
    'weight' => '1',
    'children' => array(
      0 => 'field_community_ref',
      1 => 'field_dh_type',
      2 => 'field_summary',
      3 => 'body',
      4 => 'field_category',
      5 => 'field_contributor',
      6 => 'field_coverage',
      7 => 'field_coverage_description',
      8 => 'field_creator',
      9 => 'field_date',
      10 => 'field_description',
      11 => 'field_format',
      12 => 'field_identifier',
      13 => 'field_language',
      14 => 'field_licence_std_cc',
      15 => 'field_licence_trad',
      16 => 'field_publisher',
      17 => 'field_rights',
      18 => 'field_source',
      19 => 'field_subject',
      20 => 'field_tags',
      21 => 'field_tk_body',
      22 => 'og_group_ref',
      23 => 'edit_community_record',
      24 => 'author',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Community Record',
      'instance_settings' => array(
        'classes' => 'group-community-record field-group-div',
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_community_record|node|digital_heritage|community_record'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_digital_heritage_accordion|node|digital_heritage|full';
  $field_group->group_name = 'group_digital_heritage_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Digital Heritage Accordion',
    'weight' => '9',
    'children' => array(
      0 => 'group_digital_heritage_metadata',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-digital-heritage-accordion field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_digital_heritage_accordion|node|digital_heritage|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_digital_heritage_metadata|node|digital_heritage|full';
  $field_group->group_name = 'group_digital_heritage_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_digital_heritage_accordion';
  $field_group->data = array(
    'label' => 'DIGITAL HERITAGE METADATA',
    'weight' => '10',
    'children' => array(
      0 => 'field_collection',
      1 => 'field_community_ref',
      2 => 'field_dh_type',
      3 => 'field_category',
      4 => 'field_contributor',
      5 => 'field_creator',
      6 => 'field_date',
      7 => 'field_format',
      8 => 'field_identifier',
      9 => 'field_language',
      10 => 'field_licence_std_cc',
      11 => 'field_licence_trad',
      12 => 'field_publisher',
      13 => 'field_rights',
      14 => 'field_source',
      15 => 'field_subject',
      16 => 'field_tags',
      17 => 'og_group_ref',
      18 => 'author',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'DIGITAL HERITAGE METADATA',
      'instance_settings' => array(
        'classes' => 'group-digital-heritage-metadata field-group-div',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_digital_heritage_metadata|node|digital_heritage|full'] = $field_group;

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
      1 => 'field_coverage',
      2 => 'field_coverage_description',
      3 => 'field_format',
      4 => 'field_identifier',
      5 => 'field_language',
      6 => 'field_source',
      7 => 'field_subject',
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
      0 => 'field_collection',
      1 => 'field_related_dh_items',
      2 => 'field_community_record_children',
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

  return $export;
}
