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
      'weight' => '2',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related Digital Heritage Items',
        ),
      ),
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
      'weight' => '0',
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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|dictionary_word_bundle|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'dictionary_word_bundle';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_alternate_spelling' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_definition' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'col-md-12',
        ),
      ),
    ),
    'field_dictionary_word_recording' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'col-md-12',
          'lb' => 'Recording(s)',
        ),
      ),
    ),
    'field_part_of_speech' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'col-md-4',
        ),
      ),
    ),
    'field_pronunciation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'col-md-4',
        ),
      ),
    ),
    'field_sample_sentence' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'col-md-12',
        ),
      ),
    ),
    'field_source' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_translation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'col-md-4',
        ),
      ),
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|default'] = $ds_fieldsetting;

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
        0 => 'field_word_entry',
      ),
      'right' => array(
        1 => 'field_dictionary_word_language',
        2 => 'dictionary_word_related_dh_tease',
        3 => 'field_related_dictionary_words',
        4 => 'field_community_ref',
        5 => 'og_group_ref',
        6 => 'field_tags',
        7 => 'field_word_list',
      ),
      'footer' => array(
        8 => 'field_additional_media',
      ),
    ),
    'fields' => array(
      'field_word_entry' => 'left',
      'field_dictionary_word_language' => 'right',
      'dictionary_word_related_dh_tease' => 'right',
      'field_related_dictionary_words' => 'right',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_tags' => 'right',
      'field_word_list' => 'right',
      'field_additional_media' => 'footer',
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
        1 => 'redirect',
        2 => 'path',
        3 => 'field_related_dictionary_words',
        4 => 'group_dictionary_word_basic',
        5 => 'field_dictionary_word_related_dh',
        6 => 'field_word_list',
        7 => 'group_dictionary_word_relations',
        9 => 'og_group_ref',
        10 => 'field_item_privacy_setting',
        12 => 'title',
        13 => 'field_dictionary_word_language',
        14 => 'field_word_entry',
        15 => 'field_tags',
        16 => 'field_additional_media',
        17 => '_add_existing_field',
      ),
      'hidden' => array(
        8 => 'field_language_community',
        11 => 'field_community_ref',
      ),
    ),
    'fields' => array(
      'group_tabs' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'field_related_dictionary_words' => 'ds_content',
      'group_dictionary_word_basic' => 'ds_content',
      'field_dictionary_word_related_dh' => 'ds_content',
      'field_word_list' => 'ds_content',
      'group_dictionary_word_relations' => 'ds_content',
      'field_language_community' => 'hidden',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
      'title' => 'ds_content',
      'field_dictionary_word_language' => 'ds_content',
      'field_word_entry' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_additional_media' => 'ds_content',
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
        0 => 'title',
        1 => 'field_word_entry',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_word_entry' => 'ds_content',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|dictionary_word_bundle|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'dictionary_word_bundle';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_alternate_spelling',
        1 => 'field_source',
        2 => 'field_translation',
        3 => 'field_pronunciation',
        4 => 'field_part_of_speech',
        5 => 'field_dictionary_word_recording',
        6 => 'field_definition',
        7 => 'field_sample_sentence',
      ),
    ),
    'fields' => array(
      'field_alternate_spelling' => 'ds_content',
      'field_source' => 'ds_content',
      'field_translation' => 'ds_content',
      'field_pronunciation' => 'ds_content',
      'field_part_of_speech' => 'ds_content',
      'field_dictionary_word_recording' => 'ds_content',
      'field_definition' => 'ds_content',
      'field_sample_sentence' => 'ds_content',
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
  $export['paragraphs_item|dictionary_word_bundle|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_dictionary_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'dictionary_teaser';
  $ds_view_mode->label = 'Dictionary Teaser';
  $ds_view_mode->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['dictionary_teaser'] = $ds_view_mode;

  return $export;
}
