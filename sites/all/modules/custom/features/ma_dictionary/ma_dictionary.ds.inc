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
    'extracted_dh_from_relationships' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related Digital Heritage Items',
        ),
      ),
      'label' => 'above',
      'weight' => '3',
    ),
    'extracted_dw_from_relationships' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related Dictionary Words',
        ),
      ),
      'label' => 'above',
      'weight' => '3',
    ),
    'extracted_wl_from_relationships' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Word List',
        ),
      ),
      'label' => 'above',
      'weight' => '8',
    ),
    'field_additional_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
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
  $ds_fieldsetting->id = 'node|dictionary_word|featured_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dictionary_word';
  $ds_fieldsetting->view_mode = 'featured_content';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'featured_content_view_link' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '2',
    ),
  );
  $export['node|dictionary_word|featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dictionary_word|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dictionary_word';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'extracted_dh_from_relationships' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related Digital Heritage Items',
        ),
      ),
      'label' => 'above',
      'weight' => '3',
    ),
    'extracted_dw_from_relationships' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => '  Related Dictionary Words',
        ),
      ),
      'label' => 'above',
      'weight' => '4',
    ),
    'extracted_wl_from_relationships' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Word List',
        ),
      ),
      'label' => 'above',
      'weight' => '9',
    ),
    'field_collection' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|dictionary_word|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dictionary_word|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dictionary_word';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'dictionary_word_one_media_asset' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '4',
    ),
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '3',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
  );
  $export['node|dictionary_word|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dictionary_word|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dictionary_word';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'field_word_entry' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|dictionary_word|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|word_list|featured_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'word_list';
  $ds_fieldsetting->view_mode = 'featured_content';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'featured_content_view_link' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '3',
    ),
  );
  $export['node|word_list|featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|word_list|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'word_list';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '7',
    ),
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'mukurtu_mobile_sync_white' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
  );
  $export['node|word_list|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|word_list|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'word_list';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'field_words' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|word_list|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|word_list|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'word_list';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
      'label' => 'hidden',
      'weight' => '4',
    ),
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '3',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
    'word_list_count' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '5',
    ),
  );
  $export['node|word_list|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|word_list|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'word_list';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'field_collection_credit' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_collection_summary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
  );
  $export['node|word_list|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|dictionary_word_bundle|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'dictionary_word_bundle';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_alternate_spelling' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_definition' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_dictionary_word_recording' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Recording(s)',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_part_of_speech' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_pronunciation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_sample_sentence' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_source' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_translation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|dictionary_word_bundle|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'dictionary_word_bundle';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'field_alternate_spelling' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|dictionary_word_bundle|word_entry_search_results';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'dictionary_word_bundle';
  $ds_fieldsetting->view_mode = 'word_entry_search_results';
  $ds_fieldsetting->settings = array(
    'field_alternate_spelling' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Term',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_translation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|word_entry_search_results'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_dictionary_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dictionary_word_one_media_asset';
  $ds_field->label = 'Dictionary Word First Media Asset';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dictionary_word|*';
  $ds_field->properties = array(
    'code' => array(
      'format' => 'ds_code',
      'value' => '<?php
if (!empty($entity->field_word_entry[LANGUAGE_NONE][0][\'value\'])) {
  $id = $entity->field_word_entry[LANGUAGE_NONE][0][\'value\'];
  $p = entity_load(\'paragraphs_item\', array($id));
  if (isset($p[$id]->field_dictionary_word_recording[LANGUAGE_NONE][0][\'sid\'])) {
    $sid = $p[$id]->field_dictionary_word_recording[LANGUAGE_NONE][0][\'sid\'];
    $html = scald_render($sid, "ma_scald_search_results");
    $host = $p[$id]->hostEntity();
    if (isset($host->nid)) {
      $path = drupal_get_path_alias(\'node/\' . $host->nid);
      $html = str_replace(\'<a href="/">\', "<a href=\\"$path\\">", $html);
      print $html;
    }
  }
}

?>',
    ),
    'use_token' => 0,
  );
  $export['dictionary_word_one_media_asset'] = $ds_field;

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

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'word_list_count';
  $ds_field->label = 'Word List Count';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'word_list|*';
  $ds_field->properties = array(
    'code' => array(
      'format' => 'ds_code',
      'value' => '<?php 
$count = ma_dictionary_get_word_count($entity);
if($count == 1) {
   print t(\'@count word\', array( \'@count\' => $count)); 
} else {
   print t(\'@count words\', array( \'@count\' => $count)); 
}

?>',
    ),
    'use_token' => 0,
  );
  $export['word_list_count'] = $ds_field;

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
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'extracted_dh_from_relationships' => 'right',
      'extracted_dw_from_relationships' => 'right',
      'extracted_wl_from_relationships' => 'right',
      'field_additional_media' => 'bottom',
      'field_additional_media_assets' => 'bottom',
      'field_collection' => 'right',
      'field_community_ref' => 'right',
      'field_dictionary_word_language' => 'right',
      'field_media_asset' => 'right',
      'field_related_content' => 'bottom',
      'field_tags' => 'right',
      'field_thumbnail_image' => 'right',
      'field_word_entry' => 'left',
      'field_word_list' => 'right',
      'og_group_ref' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'bottom' => array(
        9 => 'field_additional_media',
        10 => 'field_related_content',
        13 => 'field_additional_media_assets',
      ),
      'left' => array(
        0 => 'field_word_entry',
      ),
      'right' => array(
        1 => 'field_dictionary_word_language',
        2 => 'extracted_dh_from_relationships',
        3 => 'extracted_dw_from_relationships',
        4 => 'field_community_ref',
        5 => 'og_group_ref',
        6 => 'field_tags',
        7 => 'field_collection',
        8 => 'extracted_wl_from_relationships',
        11 => 'field_media_asset',
        12 => 'field_word_list',
        14 => 'field_thumbnail_image',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['node|dictionary_word|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|dictionary_word_summary';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'dictionary_word_summary';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_word_entry' => 'central',
      'mukurtu_mobile_sync_white' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'mukurtu_mobile_sync_white',
        1 => 'field_word_entry',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|dictionary_word|dictionary_word_summary'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'central',
      'featured_content_view_link' => 'central',
      'field_word_entry' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'featured_content_view_link',
        1 => 'featured_content_type',
        2 => 'title',
        3 => 'field_word_entry',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|dictionary_word|featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'hidden',
      'field_additional_media' => 'ds_content',
      'field_additional_media_assets' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_community_ref' => 'hidden',
      'field_dictionary_word_language' => 'ds_content',
      'field_dictionary_word_related_dh' => 'hidden',
      'field_item_privacy_setting' => 'ds_content',
      'field_language_community' => 'hidden',
      'field_media_asset' => 'hidden',
      'field_personal_collections' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_related_dictionary_words' => 'hidden',
      'field_tags' => 'ds_content',
      'field_word_entry' => 'ds_content',
      'field_word_list' => 'ds_content',
      'group_dictionary_word_basic' => 'ds_content',
      'group_dictionary_word_relations' => 'ds_content',
      'group_tabs' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'group_tabs',
        2 => 'redirect',
        3 => 'path',
        9 => 'group_dictionary_word_basic',
        10 => 'group_dictionary_word_relations',
        11 => 'title',
        12 => 'field_dictionary_word_language',
        13 => 'field_word_entry',
        14 => 'field_tags',
        15 => 'field_additional_media',
        16 => 'field_additional_media_assets',
        17 => 'field_related_content',
        18 => 'field_word_list',
        19 => 'field_collection',
        20 => 'field_personal_collections',
        21 => 'og_group_ref',
        22 => 'field_item_privacy_setting',
      ),
      'hidden' => array(
        4 => 'field_community_ref',
        5 => 'field_dictionary_word_related_dh',
        6 => 'field_related_dictionary_words',
        7 => 'field_language_community',
        8 => 'field_media_asset',
        23 => '_add_existing_field',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|dictionary_word|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'extracted_dh_from_relationships' => 'ds_content',
      'extracted_dw_from_relationships' => 'ds_content',
      'extracted_wl_from_relationships' => 'ds_content',
      'field_additional_media' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_dictionary_word_language' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_word_entry' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_word_entry',
        2 => 'field_dictionary_word_language',
        3 => 'extracted_dh_from_relationships',
        4 => 'extracted_dw_from_relationships',
        5 => 'field_community_ref',
        6 => 'og_group_ref',
        7 => 'field_tags',
        8 => 'field_collection',
        9 => 'extracted_wl_from_relationships',
        10 => 'field_additional_media',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|dictionary_word|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'dictionary_word_one_media_asset' => 'left',
      'featured_content_type' => 'right',
      'field_word_entry' => 'right',
      'mukurtu_icon_actions' => 'right',
      'mukurtu_mobile_sync' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'dictionary_word_one_media_asset',
      ),
      'right' => array(
        1 => 'title',
        2 => 'mukurtu_mobile_sync',
        3 => 'mukurtu_icon_actions',
        4 => 'featured_content_type',
        5 => 'field_word_entry',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|dictionary_word|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dictionary_word|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dictionary_word';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'central',
      'field_word_entry' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'featured_content_type',
        2 => 'field_word_entry',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|dictionary_word|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|word_list|featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'word_list';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'central',
      'featured_content_view_link' => 'central',
      'field_collection_image' => 'central',
      'field_collection_summary' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'featured_content_view_link',
        1 => 'field_collection_image',
        2 => 'featured_content_type',
        3 => 'title',
        4 => 'field_collection_summary',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|word_list|featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|word_list|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'word_list';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'comments' => 'bottom',
      'field_collection' => 'top',
      'field_collection_credit' => 'top',
      'field_collection_image' => 'top',
      'field_collection_summary' => 'top',
      'field_description' => 'top',
      'field_related_content' => 'bottom',
      'field_words' => 'bottom',
      'mukurtu_icon_actions' => 'top',
      'mukurtu_mobile_sync_white' => 'top',
      'title' => 'top',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'bottom' => array(
        9 => 'field_words',
        10 => 'field_related_content',
        11 => 'comments',
      ),
      'top' => array(
        0 => 'field_collection_image',
        1 => 'mukurtu_icon_actions',
        2 => 'field_collection',
        3 => 'mukurtu_mobile_sync_white',
        4 => 'title',
        6 => 'field_collection_summary',
        7 => 'field_collection_credit',
        8 => 'field_description',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['node|word_list|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|word_list|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'word_list';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_collection_credit' => 'ds_content',
      'field_collection_image' => 'ds_content',
      'field_collection_summary' => 'ds_content',
      'field_description' => 'ds_content',
      'field_words' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_collection_image',
        2 => 'field_collection_summary',
        3 => 'field_collection_credit',
        4 => 'field_description',
        5 => 'field_words',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|word_list|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|word_list|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'word_list';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_collection_image' => 'left',
      'field_collection_summary' => 'right',
      'mukurtu_icon_actions' => 'right',
      'mukurtu_mobile_sync' => 'right',
      'title' => 'right',
      'word_list_count' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'mukurtu_mobile_sync',
        3 => 'mukurtu_icon_actions',
        4 => 'featured_content_type',
        5 => 'word_list_count',
        6 => 'field_collection_summary',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|word_list|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|word_list|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'word_list';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_collection_credit' => 'right',
      'field_collection_image' => 'left',
      'field_collection_summary' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'field_collection_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'featured_content_type',
        3 => 'field_collection_summary',
        4 => 'field_collection_credit',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|word_list|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|dictionary_word_bundle|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'dictionary_word_bundle';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6_bricks';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_alternate_spelling' => 'top',
      'field_definition' => 'central',
      'field_dictionary_word_recording' => 'central',
      'field_part_of_speech' => 'topright',
      'field_pronunciation' => 'topleft',
      'field_sample_sentence' => 'central',
      'field_source' => 'central',
      'field_translation' => 'top',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        4 => 'field_definition',
        5 => 'field_dictionary_word_recording',
        6 => 'field_sample_sentence',
        7 => 'field_source',
      ),
      'top' => array(
        0 => 'field_alternate_spelling',
        1 => 'field_translation',
      ),
      'topleft' => array(
        2 => 'field_pronunciation',
      ),
      'topright' => array(
        3 => 'field_part_of_speech',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'bottomleft' => 'div',
      'bottomright' => 'div',
      'central' => 'div',
      'top' => 'div',
      'topleft' => 'div',
      'topright' => 'div',
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|dictionary_word_bundle|featured_content';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'dictionary_word_bundle';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_alternate_spelling' => 'left',
      'field_definition' => 'bottom',
      'field_dictionary_word_recording' => 'bottom',
      'field_translation' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'bottom' => array(
        2 => 'field_dictionary_word_recording',
        3 => 'field_definition',
      ),
      'left' => array(
        0 => 'field_alternate_spelling',
      ),
      'right' => array(
        1 => 'field_translation',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|dictionary_word_bundle|mukurtu_mobile';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'dictionary_word_bundle';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_alternate_spelling' => 'ds_content',
      'field_definition' => 'ds_content',
      'field_dictionary_word_recording' => 'ds_content',
      'field_part_of_speech' => 'ds_content',
      'field_pronunciation' => 'ds_content',
      'field_sample_sentence' => 'ds_content',
      'field_source' => 'ds_content',
      'field_translation' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_alternate_spelling',
        1 => 'field_translation',
        2 => 'field_pronunciation',
        3 => 'field_part_of_speech',
        4 => 'field_definition',
        5 => 'field_dictionary_word_recording',
        6 => 'field_sample_sentence',
        7 => 'field_source',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|dictionary_word_bundle|word_entry_search_results';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'dictionary_word_bundle';
  $ds_layout->view_mode = 'word_entry_search_results';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_alternate_spelling' => 'central',
      'field_translation' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'field_alternate_spelling',
        1 => 'field_translation',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['paragraphs_item|dictionary_word_bundle|word_entry_search_results'] = $ds_layout;

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

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'dictionary_word_summary';
  $ds_view_mode->label = 'Dictionary Word Summary';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['dictionary_word_summary'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'word_entry_search_results';
  $ds_view_mode->label = 'Word Entry Search Results';
  $ds_view_mode->entities = array(
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['word_entry_search_results'] = $ds_view_mode;

  return $export;
}
