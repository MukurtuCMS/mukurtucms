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
  $field_group->identifier = 'group_col_left|node|digital_heritage|content_spotlight';
  $field_group->group_name = 'group_col_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'content_spotlight';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Column',
    'weight' => '0',
    'children' => array(
      0 => 'field_coverage',
      1 => 'field_media_asset',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-xs-12 col-md-4',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_col_left|node|digital_heritage|content_spotlight'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_col_right|node|digital_heritage|content_spotlight';
  $field_group->group_name = 'group_col_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_heritage';
  $field_group->mode = 'content_spotlight';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Column',
    'weight' => '3',
    'children' => array(
      0 => 'field_collection',
      1 => 'field_dh_type',
      2 => 'field_related_dh_items',
      3 => 'field_summary',
      4 => 'field_description',
      5 => 'component_media_items',
      6 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-xs-12 col-md-8',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_col_right|node|digital_heritage|content_spotlight'] = $field_group;

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
      7 => 'field_scald_description',
      8 => 'field_scald_geo_location',
      9 => 'field_scald_headline',
      10 => 'field_scald_identifier',
      11 => 'field_scald_location',
      12 => 'field_scald_protocol',
      13 => 'field_category',
      14 => 'field_licence_std_cc',
      15 => 'field_rights',
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
  $export['group_scald_atom_metadata|scald_atom|video|ma_colorbox'] = $field_group;

  return $export;
}
