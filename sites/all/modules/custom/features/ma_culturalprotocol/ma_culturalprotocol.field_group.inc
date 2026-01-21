<?php

/**
 * @file
 * ma_culturalprotocol.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_culturalprotocol_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|node|cultural_protocol_group|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cultural_protocol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '2',
    'children' => array(
      0 => 'field_membership_list_options',
      1 => 'field_protocol_auto_join',
      2 => 'group_group',
      3 => 'group_register',
      4 => 'og_roles_permissions',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_advanced|node|cultural_protocol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|cultural_protocol_group|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cultural_protocol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_protocl_signup_permissions',
      2 => 'field_protocol_image',
      3 => 'field_protocol_image_thumbnail',
      4 => 'group_access',
      5 => 'og_group_ref',
      6 => 'field_dhan_notified_users',
      7 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_basic|node|cultural_protocol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|cultural_protocol_group|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cultural_protocol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_advanced',
      1 => 'group_basic',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_tabs|node|cultural_protocol_group|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');
  t('Basic');
  t('Tabs');

  return $field_groups;
}
