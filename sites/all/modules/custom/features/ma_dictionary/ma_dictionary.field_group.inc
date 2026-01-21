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
    'children' => array(
      0 => 'field_collection_credit',
      1 => 'field_collection_image',
      2 => 'field_collection_summary',
      3 => 'field_description',
      4 => 'field_tags',
      5 => 'field_item_privacy_setting',
      6 => 'og_group_ref',
      7 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-basic field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Basic',
    ),
    'format_type' => 'htab',
    'label' => 'Basic',
    'weight' => '6',
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
    'children' => array(
      0 => 'field_additional_media',
      1 => 'field_additional_media_assets',
      2 => 'field_dictionary_word_language',
      3 => 'field_tags',
      4 => 'field_word_entry',
      5 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-dictionary_word-basic field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Basic',
    ),
    'format_type' => 'htab',
    'label' => 'Basic',
    'weight' => '14',
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
    'children' => array(
      0 => 'field_item_privacy_setting',
      1 => 'field_related_content',
      2 => 'field_word_list',
      3 => 'og_group_ref',
      4 => 'field_collection',
      5 => 'field_personal_collections',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-dictionary_word-relations field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Relations',
    ),
    'format_type' => 'htab',
    'label' => 'Relations',
    'weight' => '16',
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
    'children' => array(),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'dictionary-list-fields',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'List View Fields',
    ),
    'format_type' => 'div',
    'label' => 'List View Fields',
    'weight' => '40',
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
    'children' => array(
      0 => 'group_dictionary_word_basic',
      1 => 'group_dictionary_word_relations',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
        'id' => '',
      ),
    ),
    'format_type' => 'htabs',
    'label' => 'Tabs',
    'weight' => '1',
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
    'children' => array(
      0 => 'group_basic',
      1 => 'group_word_list_relations',
      2 => 'group_words',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
        'id' => '',
      ),
    ),
    'format_type' => 'htabs',
    'label' => 'Tabs',
    'weight' => '1',
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
    'children' => array(
      0 => 'field_translation',
      1 => 'field_dictionary_word_recording',
      2 => 'field_definition',
      3 => 'field_sample_sentence',
      4 => 'field_part_of_speech',
      5 => 'field_source',
      6 => 'field_pronunciation',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-teaser field-group-accordion-item',
      ),
      'label' => 'Term Teaser',
    ),
    'format_type' => 'accordion-item',
    'label' => 'Term Teaser',
    'weight' => '1',
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
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-word-bundle field-group-accordion-item',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'New Word Entry',
    ),
    'format_type' => 'accordion-item',
    'label' => 'New Word Entry',
    'weight' => '1',
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
    'children' => array(
      0 => 'group_word_bundle',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-word-group field-group-accordion',
        'effect' => 'none',
        'id' => '',
      ),
    ),
    'format_type' => 'accordion',
    'label' => 'Word Group',
    'weight' => '0',
  );
  $field_groups['group_word_group|paragraphs_item|dictionary_word_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_word_list_relations|node|word_list|form';
  $field_group->group_name = 'group_word_list_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'word_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_related_content',
      1 => 'field_collection',
      2 => 'field_personal_collections',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-word-list-relations field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Relations',
    ),
    'format_type' => 'htab',
    'label' => 'Relations',
    'weight' => '8',
  );
  $field_groups['group_word_list_relations|node|word_list|form'] = $field_group;

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
    'children' => array(
      0 => 'group_teaser',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-word-teasers field-group-accordion',
        'description' => '',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
    'format_type' => 'accordion',
    'label' => 'Word Entry Teasers',
    'weight' => '0',
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
    'children' => array(
      0 => 'field_words',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-words field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Words',
    ),
    'format_type' => 'htab',
    'label' => 'Words',
    'weight' => '7',
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
