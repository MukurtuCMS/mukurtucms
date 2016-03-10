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
  $field_group->identifier = 'group_glossary_basic|node|glossary_term|form';
  $field_group->group_name = 'group_glossary_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'glossary_term';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '14',
    'children' => array(
      0 => 'field_definition',
      1 => 'field_media_asset',
      2 => 'field_sample_sentence',
      3 => 'field_translation',
      4 => 'field_glossary_term_language',
      5 => 'field_transliteration',
      6 => 'field_glossary_recording',
      7 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-glossary-basic field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_glossary_basic|node|glossary_term|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_glossary_relations|node|glossary_term|form';
  $field_group->group_name = 'group_glossary_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'glossary_term';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Relations',
    'weight' => '15',
    'children' => array(
      0 => 'field_related_digital_heritage',
      1 => 'og_group_ref',
      2 => 'field_glossary_related_dh',
      3 => 'field_glossary_synonyms',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-glossary-relations field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_glossary_relations|node|glossary_term|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|glossary_term|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'glossary_term';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_glossary_basic',
      1 => 'group_glossary_relations',
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
  $export['group_tabs|node|glossary_term|form'] = $field_group;

  return $export;
}
