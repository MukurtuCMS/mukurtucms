<?php
/**
 * @file
 * ma_scald.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_scald_field_group_info() {
  $export = array();

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
    'weight' => '2',
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'og_group_ref',
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
  $export['group_scald_atom_metadata|scald_atom|audio|ma_colorbox'] = $field_group;

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
    'weight' => '1',
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'og_group_ref',
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
  $export['group_scald_atom_metadata|scald_atom|file|ma_colorbox'] = $field_group;

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
      7 => 'field_scald_geo_location',
      8 => 'field_scald_headline',
      9 => 'field_scald_identifier',
      10 => 'field_scald_location',
      11 => 'field_category',
      12 => 'field_licence_std_cc',
      13 => 'field_rights',
      14 => 'og_group_ref',
      15 => 'field_scald_description',
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
  $export['group_scald_atom_metadata|scald_atom|image|ma_colorbox'] = $field_group;

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
      2 => 'og_group_ref',
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
  $export['group_scald_atom_metadata|scald_atom|video|ma_colorbox'] = $field_group;

  return $export;
}
