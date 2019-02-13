<?php

/**
 * @file
 * ma_scald.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_scald_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_accordion|scald_atom|audio|form';
  $field_group->group_name = 'group_scald_accordion';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'audio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scald_addtional_fields';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '9',
    'children' => array(
      0 => 'scald_authors',
      1 => 'redirect',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_scald_accordion|scald_atom|audio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_accordion|scald_atom|file|form';
  $field_group->group_name = 'group_scald_accordion';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'file';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scald_addtional_fields';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '11',
    'children' => array(
      0 => 'scald_thumbnail',
      1 => 'scald_authors',
      2 => 'redirect',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_scald_accordion|scald_atom|file|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_accordion|scald_atom|image|form';
  $field_group->group_name = 'group_scald_accordion';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scald_addtional_fields';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '23',
    'children' => array(
      0 => 'scald_authors',
      1 => 'field_archival_tiff',
      2 => 'field_full_size_jpeg',
      3 => 'field_original_dng',
      4 => 'field_scald_created',
      5 => 'field_scald_creator',
      6 => 'field_scald_description',
      7 => 'field_scald_geo_location',
      8 => 'field_scald_headline',
      9 => 'field_scald_identifier',
      10 => 'field_scald_location',
      11 => 'field_category',
      12 => 'field_licence_std_cc',
      13 => 'field_rights',
      14 => 'redirect',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Additional Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_scald_accordion|scald_atom|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_accordion|scald_atom|video|form';
  $field_group->group_name = 'group_scald_accordion';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scald_addtional_fields';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '9',
    'children' => array(
      0 => 'scald_thumbnail',
      1 => 'scald_authors',
      2 => 'redirect',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_scald_accordion|scald_atom|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_addtional_fields|scald_atom|audio|form';
  $field_group->group_name = 'group_scald_addtional_fields';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'audio';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '7',
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_scald_addtional_fields|scald_atom|audio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_addtional_fields|scald_atom|file|form';
  $field_group->group_name = 'group_scald_addtional_fields';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'file';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '8',
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_scald_addtional_fields|scald_atom|file|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_addtional_fields|scald_atom|image|form';
  $field_group->group_name = 'group_scald_addtional_fields';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '6',
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_scald_addtional_fields|scald_atom|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_addtional_fields|scald_atom|video|form';
  $field_group->group_name = 'group_scald_addtional_fields';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Fields',
    'weight' => '8',
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_scald_addtional_fields|scald_atom|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_atom_metadata|scald_atom|audio|ma_colorbox';
  $field_group->group_name = 'group_scald_atom_metadata';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'audio';
  $field_group->mode = 'ma_colorbox';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '3',
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'field_scald_protocol',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_scald_atom_metadata|scald_atom|audio|ma_colorbox'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_atom_metadata|scald_atom|file|ma_colorbox';
  $field_group->group_name = 'group_scald_atom_metadata';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'file';
  $field_group->mode = 'ma_colorbox';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'field_scald_protocol',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_scald_atom_metadata|scald_atom|file|ma_colorbox'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_atom_metadata|scald_atom|image|ma_colorbox';
  $field_group->group_name = 'group_scald_atom_metadata';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'image';
  $field_group->mode = 'ma_colorbox';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '3',
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'field_archival_tiff',
      3 => 'field_full_size_jpeg',
      4 => 'field_original_dng',
      5 => 'field_scald_created',
      6 => 'field_scald_creator',
      7 => 'field_scald_description',
      8 => 'field_scald_geo_location',
      9 => 'field_scald_headline',
      10 => 'field_scald_identifier',
      11 => 'field_scald_location',
      12 => 'field_category',
      13 => 'field_licence_std_cc',
      14 => 'field_rights',
      15 => 'field_scald_protocol',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_scald_atom_metadata|scald_atom|image|ma_colorbox'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scald_atom_metadata|scald_atom|video|ma_colorbox';
  $field_group->group_name = 'group_scald_atom_metadata';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'video';
  $field_group->mode = 'ma_colorbox';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'field_scald_protocol',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_scald_atom_metadata|scald_atom|video|ma_colorbox'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Fields');
  t('Metadata');

  return $field_groups;
}
