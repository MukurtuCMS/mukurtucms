<?php

/**
 * @file
 * ma_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_person_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_biographic|node|person|form';
  $field_group->group_name = 'group_biographic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Biographic Information',
    'weight' => '13',
    'children' => array(
      0 => 'field_date_born',
      1 => 'field_date_died',
      2 => 'field_deceased',
      3 => 'field_media_asset',
      4 => 'field_sections',
      5 => 'field_tags',
      6 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Biographic Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-biographic field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_biographic|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_div|node|person|taxonomy_record_teaser';
  $field_group->group_name = 'group_metadata_div';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'taxonomy_record_teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_date_born',
      2 => 'field_date_died',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-metadata-div field-group-div col-md-8',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_metadata_div|node|person|taxonomy_record_teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|person|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'field_date_born',
      1 => 'field_date_died',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'person metadata col-md-4',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_metadata|node|person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_media|node|person|default';
  $field_group->group_name = 'group_person_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_media_asset',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-person-media field-group-div col-md-8',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_person_media|node|person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_connections|node|person|form';
  $field_group->group_name = 'group_record_connections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Record Management',
    'weight' => '16',
    'children' => array(
      0 => 'field_mukurtu_terms',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Record Management',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-record-connections field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_record_connections|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relations|node|person|form';
  $field_group->group_name = 'group_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Relations',
    'weight' => '14',
    'children' => array(
      0 => 'field_related_people',
      1 => 'field_related_content',
      2 => 'field_collection',
      3 => 'field_personal_collections',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Relations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-relations field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_relations|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_group|paragraphs_item|text_section|form';
  $field_group->group_name = 'group_section_group';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_section',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-section-group field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_section_group|paragraphs_item|text_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section|paragraphs_item|text_section|form';
  $field_group->group_name = 'group_section';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_section_group';
  $field_group->data = array(
    'label' => 'Section',
    'weight' => '7',
    'children' => array(
      0 => 'field_section_title',
      1 => 'field_left_media',
      2 => 'field_right_media',
      3 => 'field_section_body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Section',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-section field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_section|paragraphs_item|text_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|person|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_biographic',
      1 => 'group_record_connections',
      2 => 'group_relations',
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
  $field_groups['group_tabs|node|person|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Biographic Information');
  t('Metadata');
  t('Record Management');
  t('Relations');
  t('Section');
  t('Section Group');
  t('Tabs');

  return $field_groups;
}
