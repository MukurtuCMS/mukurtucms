<?php

/**
 * @file
 * ma_lesson_plan.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_lesson_plan_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_base|node|unit_plan|form';
  $field_group->group_name = 'group_base';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'unit_plan';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_category',
      1 => 'field_tags',
      2 => 'field_unit_class_period_length',
      3 => 'field_unit_grade_level',
      4 => 'field_unit_subject',
      5 => 'field_unit_teacher',
      6 => 'field_unit_unit_length',
      7 => 'field_unit_week_of',
      8 => 'og_group_ref',
      9 => 'field_item_privacy_setting',
      10 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-base field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Core',
    ),
    'format_type' => 'htab',
    'label' => 'Core',
    'weight' => '12',
  );
  $field_groups['group_base|node|unit_plan|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lessons|node|unit_plan|form';
  $field_group->group_name = 'group_lessons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'unit_plan';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_unit_lessons',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-lessons field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Lessons',
    ),
    'format_type' => 'htab',
    'label' => 'Lessons',
    'weight' => '14',
  );
  $field_groups['group_lessons|node|unit_plan|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_view_fields|node|lesson|search_result';
  $field_group->group_name = 'group_list_view_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lesson';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'body',
      1 => 'featured_content_type',
      2 => 'title',
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
    'weight' => '10',
  );
  $field_groups['group_list_view_fields|node|lesson|search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_view_fields|node|unit_plan|search_result';
  $field_group->group_name = 'group_list_view_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'unit_plan';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_unit_teacher',
      1 => 'field_unit_subject',
      2 => 'field_unit_grade_level',
      3 => 'field_community_ref',
      4 => 'featured_content_type',
      5 => 'title',
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
  $field_groups['group_list_view_fields|node|unit_plan|search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_loa|node|unit_plan|form';
  $field_group->group_name = 'group_loa';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'unit_plan';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_media_asset',
      1 => 'field_related_content',
      2 => 'field_unit_assessments',
      3 => 'field_unit_conceptual',
      4 => 'field_unit_language_learning',
      5 => 'field_unit_nature_of_science',
      6 => 'field_unit_overarching',
      7 => 'field_unit_technical',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-loa field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Learning Outcomes and Assessments',
    ),
    'format_type' => 'htab',
    'label' => 'Learning Outcomes and Assessments',
    'weight' => '13',
  );
  $field_groups['group_loa|node|unit_plan|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|unit_plan|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'unit_plan';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'group_base',
      1 => 'group_lessons',
      2 => 'group_loa',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
        'id' => '',
      ),
    ),
    'format_type' => 'htabs',
    'label' => 'Tabs',
    'weight' => '1',
  );
  $field_groups['group_tabs|node|unit_plan|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Core');
  t('Learning Outcomes and Assessments');
  t('Lessons');
  t('List View Fields');
  t('Tabs');

  return $field_groups;
}
