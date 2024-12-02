<?php

/**
 * @file
 * ma_base_theme.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_base_theme_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sorter|node|lesson|form';
  $field_group->group_name = 'group_sorter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lesson';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sorter',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_lesson_days',
      2 => 'field_lesson_micro_tasks',
      3 => 'field_lesson_resources',
      4 => 'field_lesson_tech_integration',
      5 => 'field_related_content',
      6 => 'title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-sorter field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_sorter|node|lesson|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sorter');

  return $field_groups;
}
