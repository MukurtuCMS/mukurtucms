<?php
/**
 * @file
 * ma_dictionary.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_dictionary_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dictionary_word_basic|node|dictionary_word|form';
  $field_group->group_name = 'group_dictionary_word_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dictionary_word';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '14',
    'children' => array(
      0 => 'field_additional_media',
      1 => 'field_dictionary_word_language',
      2 => 'field_tags',
      3 => 'field_word_entry',
      4 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dictionary_word-basic field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dictionary_word_basic|node|dictionary_word|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dictionary_word_relations|node|dictionary_word|form';
  $field_group->group_name = 'group_dictionary_word_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dictionary_word';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Relations',
    'weight' => '16',
    'children' => array(
      0 => 'field_dictionary_word_related_dh',
      1 => 'field_dictionary_word_synonyms',
      2 => 'field_item_privacy_setting',
      3 => 'og_group_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dictionary_word-relations field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dictionary_word_relations|node|dictionary_word|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_view_fields|node|dictionary_word|search_result';
  $field_group->group_name = 'group_list_view_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dictionary_word';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'List View Fields',
    'weight' => '18',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'List View Fields',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'dictionary-list-fields',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_list_view_fields|node|dictionary_word|search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|dictionary_word|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dictionary_word';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_dictionary_word_basic',
      1 => 'group_dictionary_word_relations',
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
  $export['group_tabs|node|dictionary_word|form'] = $field_group;

  return $export;
}
