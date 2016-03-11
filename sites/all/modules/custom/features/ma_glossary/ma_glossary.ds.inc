<?php
/**
 * @file
 * ma_glossary.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_glossary_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|glossary_term|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'glossary_term';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|glossary_term|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|glossary_term|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'glossary_term';
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
    'field_media_asset' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|glossary_term|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_glossary_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|glossary_term|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'glossary_term';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_translation',
        2 => 'field_glossary_term_language',
        3 => 'field_transliteration',
        4 => 'field_glossary_recording',
        5 => 'field_definition',
        6 => 'field_sample_sentence',
        7 => 'field_media_asset',
      ),
      'right' => array(
        8 => 'field_glossary_synonyms',
        9 => 'field_glossary_related_dh',
        10 => 'og_group_ref',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_translation' => 'left',
      'field_glossary_term_language' => 'left',
      'field_transliteration' => 'left',
      'field_glossary_recording' => 'left',
      'field_definition' => 'left',
      'field_sample_sentence' => 'left',
      'field_media_asset' => 'left',
      'field_glossary_synonyms' => 'right',
      'field_glossary_related_dh' => 'right',
      'og_group_ref' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|glossary_term|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|glossary_term|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'glossary_term';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_tabs',
        1 => 'title',
        2 => 'field_translation',
        3 => 'field_glossary_term_language',
        4 => 'field_transliteration',
        5 => 'field_glossary_recording',
        6 => 'field_definition',
        7 => 'field_sample_sentence',
        8 => 'field_media_asset',
        9 => 'redirect',
        10 => 'path',
        11 => 'group_glossary_basic',
        12 => 'group_glossary_relations',
        13 => 'field_glossary_synonyms',
        14 => 'field_glossary_related_dh',
        15 => 'og_group_ref',
      ),
      'hidden' => array(
        16 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_tabs' => 'ds_content',
      'title' => 'ds_content',
      'field_translation' => 'ds_content',
      'field_glossary_term_language' => 'ds_content',
      'field_transliteration' => 'ds_content',
      'field_glossary_recording' => 'ds_content',
      'field_definition' => 'ds_content',
      'field_sample_sentence' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'group_glossary_basic' => 'ds_content',
      'group_glossary_relations' => 'ds_content',
      'field_glossary_synonyms' => 'ds_content',
      'field_glossary_related_dh' => 'ds_content',
      'og_group_ref' => 'ds_content',
      '_add_existing_field' => 'hidden',
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
  $export['node|glossary_term|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|glossary_term|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'glossary_term';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_translation',
        2 => 'field_media_asset',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_translation' => 'ds_content',
      'field_media_asset' => 'ds_content',
    ),
    'limit' => array(
      'field_media_asset' => '1',
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
  $export['node|glossary_term|search_result'] = $ds_layout;

  return $export;
}
