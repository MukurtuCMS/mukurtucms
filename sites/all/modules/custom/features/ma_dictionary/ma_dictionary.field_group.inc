<?php

/**
 * @file
 * ma_dictionary.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_dictionary_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|word_list|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'word_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '6',
    'children' => array(
      0 => 'field_collection_credit',
      1 => 'field_collection_image',
      2 => 'field_collection_summary',
      3 => 'field_description',
      4 => 'field_tags',
      5 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-basic field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_basic|node|word_list|form'] = $field_group;

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
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-dictionary_word-basic field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_dictionary_word_basic|node|dictionary_word|form'] = $field_group;

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
      1 => 'field_item_privacy_setting',
      2 => 'field_related_dictionary_words',
      3 => 'field_word_list',
      4 => 'og_group_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Relations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-dictionary_word-relations field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_dictionary_word_relations|node|dictionary_word|form'] = $field_group;

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
    'weight' => '36',
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
  $field_groups['group_list_view_fields|node|dictionary_word|search_result'] = $field_group;

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
    'weight' => '1',
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
  $field_groups['group_tabs|node|dictionary_word|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|word_list|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'word_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_basic',
      1 => 'group_words',
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
  $field_groups['group_tabs|node|word_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser|paragraphs_item|dictionary_word_bundle|word_entry_in_word_list';
  $field_group->group_name = 'group_teaser';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'dictionary_word_bundle';
  $field_group->mode = 'word_entry_in_word_list';
  $field_group->parent_name = 'group_word_teasers';
  $field_group->data = array(
    'label' => 'Term Teaser',
    'weight' => '1',
    'children' => array(
      0 => 'field_translation',
      1 => 'field_dictionary_word_recording',
      2 => 'field_definition',
      3 => 'field_sample_sentence',
      4 => 'field_part_of_speech',
      5 => 'field_source',
      6 => 'field_pronunciation',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Term Teaser',
      'instance_settings' => array(
        'classes' => 'group-teaser field-group-accordion-item',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_teaser|paragraphs_item|dictionary_word_bundle|word_entry_in_word_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_word_bundle|paragraphs_item|dictionary_word_bundle|form';
  $field_group->group_name = 'group_word_bundle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'dictionary_word_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_word_group';
  $field_group->data = array(
    'label' => 'New Word Entry',
    'weight' => '1',
    'children' => array(
      0 => 'field_translation',
      1 => 'field_transliteration',
      2 => 'field_dictionary_word_recording',
      3 => 'field_definition',
      4 => 'field_sample_sentence',
      5 => 'field_part_of_speech',
      6 => 'field_source',
      7 => 'field_alternate_spelling',
      8 => 'field_pronunciation',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'New Word Entry',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-word-bundle field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_word_bundle|paragraphs_item|dictionary_word_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_word_group|paragraphs_item|dictionary_word_bundle|form';
  $field_group->group_name = 'group_word_group';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'dictionary_word_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Word Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_word_bundle',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-word-group field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_word_group|paragraphs_item|dictionary_word_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_word_teasers|paragraphs_item|dictionary_word_bundle|word_entry_in_word_list';
  $field_group->group_name = 'group_word_teasers';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'dictionary_word_bundle';
  $field_group->mode = 'word_entry_in_word_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Word Entry Teasers',
    'weight' => '0',
    'children' => array(
      0 => 'group_teaser',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-word-teasers field-group-accordion',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_word_teasers|paragraphs_item|dictionary_word_bundle|word_entry_in_word_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_words|node|word_list|form';
  $field_group->group_name = 'group_words';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'word_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Words',
    'weight' => '8',
    'children' => array(
      0 => 'field_words',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Words',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-words field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_words|node|word_list|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic');
  t('List View Fields');
  t('New Word Entry');
  t('Relations');
  t('Tabs');
  t('Term Teaser');
  t('Word Entry Teasers');
  t('Word Group');
  t('Words');

  return $field_groups;
}
