<?php

/**
 * @file
 * ma_scald.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_scald_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|audio|ma_colorbox';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'ma_colorbox';
  $ds_fieldsetting->settings = array(
    'download_atom' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
  );
  $export['scald_atom|audio|ma_colorbox'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|audio|mukurtu_scald_dictionary_media';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'mukurtu_scald_dictionary_media';
  $ds_fieldsetting->settings = array(
    'scald_thumbnail' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['scald_atom|audio|mukurtu_scald_dictionary_media'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|audio|mukurtu_scald_recording';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'mukurtu_scald_recording';
  $ds_fieldsetting->settings = array(
    'scald_authors' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['scald_atom|audio|mukurtu_scald_recording'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|file|ma_scald_search_results';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'file';
  $ds_fieldsetting->view_mode = 'ma_scald_search_results';
  $ds_fieldsetting->settings = array(
    'scald_thumbnail' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['scald_atom|file|ma_scald_search_results'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|file|mukurtu_scald_dictionary_media';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'file';
  $ds_fieldsetting->view_mode = 'mukurtu_scald_dictionary_media';
  $ds_fieldsetting->settings = array(
    'scald_thumbnail' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['scald_atom|file|mukurtu_scald_dictionary_media'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|image|default';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'scald_thumbnail' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['scald_atom|image|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|image|ma_colorbox';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'ma_colorbox';
  $ds_fieldsetting->settings = array(
    'download_atom' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
  );
  $export['scald_atom|image|ma_colorbox'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|image|mukurtu_scald_dictionary_media';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'mukurtu_scald_dictionary_media';
  $ds_fieldsetting->settings = array(
    'scald_thumbnail' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['scald_atom|image|mukurtu_scald_dictionary_media'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'scald_atom|video|ma_colorbox';
  $ds_fieldsetting->entity_type = 'scald_atom';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'ma_colorbox';
  $ds_fieldsetting->settings = array(
    'download_atom' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
  );
  $export['scald_atom|video|ma_colorbox'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_scald_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|audio|ma_colorbox';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'ma_colorbox';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
      'download_atom' => 'ds_content',
      'field_scald_protocol' => 'ds_content',
      'group_scald_atom_metadata' => 'ds_content',
      'scald_authors' => 'ds_content',
      'scald_tags' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'scald_thumbnail',
        1 => 'field_scald_protocol',
        2 => 'atom',
        3 => 'download_atom',
        4 => 'scald_authors',
        5 => 'group_scald_atom_metadata',
        6 => 'scald_tags',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|audio|ma_colorbox'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|audio|ma_scald_search_results';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'ma_scald_search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'scald_thumbnail',
        1 => 'atom',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|audio|ma_scald_search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|audio|mukurtu_scald_dictionary_media';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'mukurtu_scald_dictionary_media';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'scald_thumbnail',
        1 => 'atom',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|audio|mukurtu_scald_dictionary_media'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|audio|mukurtu_scald_recording';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'mukurtu_scald_recording';
  $ds_layout->layout = 'bootstrap_8_4';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'left',
      'field_contributor' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'atom',
      ),
      'right' => array(
        0 => 'field_contributor',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['scald_atom|audio|mukurtu_scald_recording'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|audio|mukurtu_scald_related_items';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'mukurtu_scald_related_items';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'atom' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'wrappers' => array(),
  );
  $export['scald_atom|audio|mukurtu_scald_related_items'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|file|ma_colorbox';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'file';
  $ds_layout->view_mode = 'ma_colorbox';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
      'field_scald_protocol' => 'ds_content',
      'group_scald_atom_metadata' => 'ds_content',
      'scald_authors' => 'ds_content',
      'scald_tags' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_scald_protocol',
        1 => 'scald_thumbnail',
        2 => 'atom',
        3 => 'group_scald_atom_metadata',
        4 => 'scald_authors',
        5 => 'scald_tags',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|file|ma_colorbox'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|file|ma_scald_search_results';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'file';
  $ds_layout->view_mode = 'ma_scald_search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'scald_thumbnail',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|file|ma_scald_search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|file|mukurtu_scald_dictionary_media';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'file';
  $ds_layout->view_mode = 'mukurtu_scald_dictionary_media';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'scald_thumbnail',
        1 => 'atom',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|file|mukurtu_scald_dictionary_media'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|file|mukurtu_scald_related_items';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'file';
  $ds_layout->view_mode = 'mukurtu_scald_related_items';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'atom' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
        1 => 'scald_thumbnail',
      ),
    ),
    'wrappers' => array(),
  );
  $export['scald_atom|file|mukurtu_scald_related_items'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|image|default';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'scald_authors' => 'ds_content',
      'scald_tags' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'scald_thumbnail',
        1 => 'scald_authors',
        2 => 'scald_tags',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|image|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|image|ma_colorbox';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'ma_colorbox';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'download_atom' => 'ds_content',
      'field_archival_tiff' => 'ds_content',
      'field_category' => 'ds_content',
      'field_full_size_jpeg' => 'ds_content',
      'field_licence_std_cc' => 'ds_content',
      'field_original_dng' => 'ds_content',
      'field_rights' => 'ds_content',
      'field_scald_created' => 'ds_content',
      'field_scald_creator' => 'ds_content',
      'field_scald_description' => 'ds_content',
      'field_scald_geo_location' => 'ds_content',
      'field_scald_headline' => 'ds_content',
      'field_scald_identifier' => 'ds_content',
      'field_scald_location' => 'ds_content',
      'field_scald_protocol' => 'ds_content',
      'group_480_thumbnail_and_link' => 'ds_content',
      'group_scald_atom_metadata' => 'ds_content',
      'scald_authors' => 'ds_content',
      'scald_tags' => 'ds_content',
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_scald_protocol',
        1 => 'group_480_thumbnail_and_link',
        2 => 'scald_thumbnail',
        3 => 'field_scald_identifier',
        4 => 'download_atom',
        5 => 'field_original_dng',
        6 => 'group_scald_atom_metadata',
        7 => 'field_archival_tiff',
        8 => 'field_full_size_jpeg',
        9 => 'field_scald_created',
        10 => 'field_scald_creator',
        11 => 'scald_authors',
        12 => 'field_scald_headline',
        13 => 'field_scald_description',
        14 => 'scald_tags',
        15 => 'field_scald_geo_location',
        16 => 'field_scald_location',
        17 => 'field_rights',
        18 => 'field_licence_std_cc',
        19 => 'field_category',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|image|ma_colorbox'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|image|ma_scald_search_results';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'ma_scald_search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'atom' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'wrappers' => array(),
  );
  $export['scald_atom|image|ma_scald_search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|image|mukurtu_scald_dictionary_media';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'mukurtu_scald_dictionary_media';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'scald_thumbnail' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'scald_thumbnail',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|image|mukurtu_scald_dictionary_media'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|image|mukurtu_scald_related_items';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'mukurtu_scald_related_items';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'atom' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'wrappers' => array(),
  );
  $export['scald_atom|image|mukurtu_scald_related_items'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|video|default';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|video|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|video|ma_colorbox';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'ma_colorbox';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
      'download_atom' => 'ds_content',
      'field_scald_protocol' => 'ds_content',
      'group_scald_atom_metadata' => 'ds_content',
      'scald_authors' => 'ds_content',
      'scald_tags' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
        1 => 'field_scald_protocol',
        2 => 'download_atom',
        3 => 'group_scald_atom_metadata',
        4 => 'scald_authors',
        5 => 'scald_tags',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|video|ma_colorbox'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|video|ma_scald_search_results';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'ma_scald_search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|video|ma_scald_search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|video|mukurtu_scald_dictionary_media';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'mukurtu_scald_dictionary_media';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'atom' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['scald_atom|video|mukurtu_scald_dictionary_media'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'scald_atom|video|mukurtu_scald_related_items';
  $ds_layout->entity_type = 'scald_atom';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'mukurtu_scald_related_items';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'atom' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'atom',
      ),
    ),
    'wrappers' => array(),
  );
  $export['scald_atom|video|mukurtu_scald_related_items'] = $ds_layout;

  return $export;
}
