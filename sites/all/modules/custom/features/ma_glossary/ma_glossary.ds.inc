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
      'weight' => '1',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_sample_sentence' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
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
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'glossary_navigation',
      ),
      'left' => array(
        1 => 'title',
        2 => 'field_definition',
        3 => 'field_sample_sentence',
      ),
      'right' => array(
        4 => 'field_translation',
        5 => 'found_in_glossary',
        6 => 'og_group_ref',
      ),
      'footer' => array(
        7 => 'field_media_asset',
        8 => 'field_related_digital_heritage',
      ),
    ),
    'fields' => array(
      'glossary_navigation' => 'header',
      'title' => 'left',
      'field_definition' => 'left',
      'field_sample_sentence' => 'left',
      'field_translation' => 'right',
      'found_in_glossary' => 'right',
      'og_group_ref' => 'right',
      'field_media_asset' => 'footer',
      'field_related_digital_heritage' => 'footer',
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
  $export['node|glossary_term|default'] = $ds_layout;

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
        2 => 'field_definition',
        3 => 'field_sample_sentence',
        4 => 'field_media_asset',
        5 => 'og_group_ref',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_translation' => 'ds_content',
      'field_definition' => 'ds_content',
      'field_sample_sentence' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'og_group_ref' => 'ds_content',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|glossary|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'glossary';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_glossary_image',
        1 => 'field_description',
        2 => 'field_glossary_terms',
      ),
    ),
    'fields' => array(
      'field_glossary_image' => 'ds_content',
      'field_description' => 'ds_content',
      'field_glossary_terms' => 'ds_content',
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
  $export['node|glossary|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|audio|mukurtu_glossary_table';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'mukurtu_glossary_table';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
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
  $export['scald_atom|audio|mukurtu_glossary_table'] = $ds_layout;

  return $export;
}
