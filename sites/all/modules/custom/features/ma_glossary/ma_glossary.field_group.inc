<?php
/**
 * @file
 * ma_glossary.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_glossary_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|glossary|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'glossary';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '7',
    'children' => array(
      0 => 'field_description',
      1 => 'field_glossary_image',
      2 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_basic|node|glossary|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_glossary_terms|node|glossary|form';
  $field_group->group_name = 'group_glossary_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'glossary';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Glossary Terms',
    'weight' => '9',
    'children' => array(
      0 => 'field_glossary_terms',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-glossary-terms field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_glossary_terms|node|glossary|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|glossary|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'glossary';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_basic',
      1 => 'group_glossary_terms',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $export['group_tabs|node|glossary|form'] = $field_group;

  return $export;
}
