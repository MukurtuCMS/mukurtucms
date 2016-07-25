<?php
/**
 * @file
 * ma_dictionary.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_dictionary_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dictionary_word|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dictionary_word';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'dictionary_word_related_dh_tease' => array(
      'weight' => '7',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related Digital Heritage Items',
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_community_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'og_group_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
  );
  $export['node|dictionary_word|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dictionary_word|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dictionary_word';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|dictionary_word|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_dictionary_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dictionary_word_related_dh_tease';
  $ds_field->label = 'Dictionary Word Related DH Teasers';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dictionary_word|default';
  $ds_field->properties = array(
    'block' => 'views|aac39530523f9b5eb2373230629f0528',
    'block_render' => '3',
  );
  $export['dictionary_word_related_dh_tease'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_dictionary_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_translation',
        2 => 'field_transliteration',
        3 => 'field_dictionary_word_recording',
        4 => 'field_definition',
        5 => 'field_sample_sentence',
      ),
      'right' => array(
        6 => 'field_dictionary_word_language',
        7 => 'dictionary_word_related_dh_tease',
        8 => 'field_dictionary_word_synonyms',
        9 => 'field_community_ref',
        10 => 'og_group_ref',
        11 => 'field_tags',
        13 => 'field_source',
      ),
      'footer' => array(
        12 => 'field_additional_media',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_translation' => 'left',
      'field_transliteration' => 'left',
      'field_dictionary_word_recording' => 'left',
      'field_definition' => 'left',
      'field_sample_sentence' => 'left',
      'field_dictionary_word_language' => 'right',
      'dictionary_word_related_dh_tease' => 'right',
      'field_dictionary_word_synonyms' => 'right',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_tags' => 'right',
      'field_additional_media' => 'footer',
      'field_source' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|dictionary_word|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_tabs',
        1 => 'title',
        2 => 'field_translation',
        3 => 'field_dictionary_word_language',
        4 => 'field_transliteration',
        5 => 'field_dictionary_word_recording',
        6 => 'field_definition',
        7 => 'field_sample_sentence',
        8 => 'field_tags',
        9 => 'field_source',
        10 => 'redirect',
        11 => 'path',
        12 => 'field_additional_media',
        13 => 'group_dictionary_word_basic',
        14 => 'field_dictionary_word_synonyms',
        15 => 'group_dictionary_word_relations',
        16 => 'field_dictionary_word_related_dh',
        17 => 'og_group_ref',
        18 => 'field_item_privacy_setting',
        20 => '_add_existing_field',
      ),
      'hidden' => array(
        19 => 'field_community_ref',
      ),
    ),
    'fields' => array(
      'group_tabs' => 'ds_content',
      'title' => 'ds_content',
      'field_translation' => 'ds_content',
      'field_dictionary_word_language' => 'ds_content',
      'field_transliteration' => 'ds_content',
      'field_dictionary_word_recording' => 'ds_content',
      'field_definition' => 'ds_content',
      'field_sample_sentence' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_source' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'field_additional_media' => 'ds_content',
      'group_dictionary_word_basic' => 'ds_content',
      'field_dictionary_word_synonyms' => 'ds_content',
      'group_dictionary_word_relations' => 'ds_content',
      'field_dictionary_word_related_dh' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
      '_add_existing_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|dictionary_word|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_list_view_fields',
        1 => 'title',
        2 => 'field_dictionary_word_recording',
        3 => 'field_transliteration',
        4 => 'field_translation',
        5 => 'field_definition',
      ),
    ),
    'fields' => array(
      'group_list_view_fields' => 'ds_content',
      'title' => 'ds_content',
      'field_dictionary_word_recording' => 'ds_content',
      'field_transliteration' => 'ds_content',
      'field_translation' => 'ds_content',
      'field_definition' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|dictionary_word|search_result'] = $ds_layout;

  return $export;
}
