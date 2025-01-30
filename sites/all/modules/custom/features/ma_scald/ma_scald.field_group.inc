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
  $field_group->identifier = 'group_480_thumbnail_and_link|scald_atom|image|ma_colorbox';
  $field_group->group_name = 'group_480_thumbnail_and_link';
  $field_group->entity_type = 'scald_atom';
  $field_group->bundle = 'image';
  $field_group->mode = 'ma_colorbox';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'scald_thumbnail',
      1 => 'download_atom',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-480-thumbnail-and-link field-group-div',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => '480 thumbnail and link',
    ),
    'format_type' => 'div',
    'label' => '480 thumbnail and link',
    'weight' => '0',
  );
  $field_groups['group_480_thumbnail_and_link|scald_atom|image|ma_colorbox'] = $field_group;

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
    'children' => array(
      0 => 'scald_authors',
      1 => 'redirect',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'accordion-item',
    'label' => 'Additional Fields',
    'weight' => '9',
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
    'children' => array(
      0 => 'scald_thumbnail',
      1 => 'scald_authors',
      2 => 'redirect',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'accordion-item',
    'label' => 'Additional Fields',
    'weight' => '11',
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
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Additional Fields',
    ),
    'format_type' => 'accordion-item',
    'label' => 'Additional Fields',
    'weight' => '23',
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
    'children' => array(
      0 => 'scald_thumbnail',
      1 => 'scald_authors',
      2 => 'redirect',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-scald-accordion field-group-accordion-item',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'accordion-item',
    'label' => 'Additional Fields',
    'weight' => '9',
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
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'effect' => 'none',
        'id' => '',
      ),
    ),
    'format_type' => 'accordion',
    'label' => 'Additional Fields',
    'weight' => '8',
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
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'effect' => 'none',
        'id' => '',
      ),
    ),
    'format_type' => 'accordion',
    'label' => 'Additional Fields',
    'weight' => '7',
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
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'effect' => 'none',
        'id' => '',
      ),
    ),
    'format_type' => 'accordion',
    'label' => 'Additional Fields',
    'weight' => '7',
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
    'children' => array(
      0 => 'group_scald_accordion',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-scald-addtional-fields field-group-accordion',
        'effect' => 'none',
        'id' => '',
      ),
    ),
    'format_type' => 'accordion',
    'label' => 'Additional Fields',
    'weight' => '6',
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
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'field_scald_protocol',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'Metadata',
    ),
    'format_type' => 'div',
    'label' => 'Metadata',
    'weight' => '3',
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
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'field_scald_protocol',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'Metadata',
    ),
    'format_type' => 'div',
    'label' => 'Metadata',
    'weight' => '2',
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
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'Metadata',
    ),
    'format_type' => 'div',
    'label' => 'Metadata',
    'weight' => '3',
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
    'children' => array(
      0 => 'scald_authors',
      1 => 'scald_tags',
      2 => 'field_scald_protocol',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'Metadata',
    ),
    'format_type' => 'div',
    'label' => 'Metadata',
    'weight' => '2',
  );
  $field_groups['group_scald_atom_metadata|scald_atom|video|ma_colorbox'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('480 thumbnail and link');
  t('Additional Fields');
  t('Metadata');

  return $field_groups;
}
