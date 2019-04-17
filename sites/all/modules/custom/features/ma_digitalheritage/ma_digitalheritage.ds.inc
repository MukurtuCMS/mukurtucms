<?php

/**
 * @file
 * ma_digitalheritage.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_digitalheritage_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|community_record';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'community_record';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '9',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'author' => array(
      'weight' => '27',
      'label' => 'above',
      'format' => 'author',
    ),
    'field_licence_trad' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'clearfix',
        ),
      ),
    ),
  );
  $export['node|digital_heritage|community_record'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|featured_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'featured_content';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'featured_content_view_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '3',
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
  $export['node|digital_heritage|featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'community_record_title' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Title',
        ),
      ),
    ),
    'dh_related_items_teasers' => array(
      'weight' => '12',
      'label' => 'above',
      'format' => 'default',
    ),
    'mukurtu_icon_actions' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '33',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '32',
      'label' => 'above',
      'format' => 'author_linked',
    ),
    'field_collection' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
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
    'field_dh_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_related_dh_items' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related Items',
        ),
      ),
    ),
    'field_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_licence_trad' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'clearfix',
        ),
      ),
    ),
    'field_media_asset' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
  );
  $export['node|digital_heritage|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|map_popup';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'map_popup';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|digital_heritage|map_popup'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'digital_heritage_page_number' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'featured_content_type' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'mukurtu_icon_actions' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
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
    'field_community_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_summary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|digital_heritage|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|taxonomy_record_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'taxonomy_record_teaser';
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
  $export['node|digital_heritage|taxonomy_record_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
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
    'field_community_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_summary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|digital_heritage|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_digitalheritage_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'community_record_title';
  $ds_field->label = 'Community Record Title';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'digital_heritage|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
print _ma_digitalheritage_ds_community_record_title($entity);',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['community_record_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dh_related_items_teasers';
  $ds_field->label = 'Related Items';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'digital_heritage|full';
  $ds_field->properties = array(
    'block' => 'views|dh_related_items_teasers-block',
    'block_render' => '3',
  );
  $export['dh_related_items_teasers'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'digital_heritage_page_number';
  $ds_field->label = 'Digital Heritage Page Number';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'digital_heritage|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  if (!empty($entity->field_book_children[LANGUAGE_NONE])) {
    $pages = count($entity->field_book_children[LANGUAGE_NONE]) + 1;
    print t("@pages pages", array(\'@pages\' => $pages));
    return;
  }

  if (!empty($entity->field_book_parent[LANGUAGE_NONE])) {
    $parent_nid = $entity->field_book_parent[LANGUAGE_NONE][0][\'target_id\'];
    $parent = node_load($parent_nid);
    $pages = count(array_keys($parent->field_book_children[LANGUAGE_NONE])) + 1;
    $page = 1;
    foreach ($parent->field_book_children[LANGUAGE_NONE] as $child_page) {
      $page++;
      if ($child_page[\'target_id\'] == $entity->nid) {
        break;
      }
    }
    print t("Page @page of @pages", array(\'@page\' => $page, \'@pages\' => $pages));
    return;
  }
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['digital_heritage_page_number'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'featured_content_type';
  $ds_field->label = 'Featured Content Type';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$info = entity_get_info(\'node\');
$type = $entity->type;
if(isset($info[\'bundles\'][$type])) {
    print $info[\'bundles\'][$type][\'label\'];
}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['featured_content_type'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'featured_content_view_link';
  $ds_field->label = 'Featured Content View Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="<?php print drupal_get_path_alias(\'node/\' . $entity->nid)?>"><?php print t(\'View Content\');?></a>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['featured_content_view_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'mukurtu_icon_actions';
  $ds_field->label = 'Mukurtu Icon Actions';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'digital_heritage|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  ma_collection_add_to_personal_collection_icon_ds_field($entity);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['mukurtu_icon_actions'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_digitalheritage_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|community_record';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'community_record';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_summary',
        1 => 'field_media_asset',
        2 => 'field_description',
        3 => 'body',
        4 => 'field_tk_body',
        5 => 'field_people',
        6 => 'field_transcription',
        7 => 'group_transcription_cr',
        8 => 'field_coverage',
        9 => 'field_coverage_description',
        10 => 'field_related_dh_items',
        12 => 'field_related_dictionary_words',
      ),
      'right' => array(
        11 => 'title',
        13 => 'field_community_ref',
        14 => 'og_group_ref',
        15 => 'field_category',
        16 => 'field_tags',
        17 => 'field_date',
        18 => 'field_creator',
        19 => 'field_contributor',
        20 => 'field_language',
        21 => 'field_rights',
        22 => 'field_licence_trad',
        23 => 'field_licence_std_cc',
        24 => 'field_source',
        25 => 'field_publisher',
        26 => 'field_identifier',
        27 => 'field_subject',
        28 => 'field_dh_type',
        29 => 'field_format',
        30 => 'author',
      ),
    ),
    'fields' => array(
      'field_summary' => 'left',
      'field_media_asset' => 'left',
      'field_description' => 'left',
      'body' => 'left',
      'field_tk_body' => 'left',
      'field_people' => 'left',
      'field_transcription' => 'left',
      'group_transcription_cr' => 'left',
      'field_coverage' => 'left',
      'field_coverage_description' => 'left',
      'field_related_dh_items' => 'left',
      'title' => 'right',
      'field_related_dictionary_words' => 'left',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_category' => 'right',
      'field_tags' => 'right',
      'field_date' => 'right',
      'field_creator' => 'right',
      'field_contributor' => 'right',
      'field_language' => 'right',
      'field_rights' => 'right',
      'field_licence_trad' => 'right',
      'field_licence_std_cc' => 'right',
      'field_source' => 'right',
      'field_publisher' => 'right',
      'field_identifier' => 'right',
      'field_subject' => 'right',
      'field_dh_type' => 'right',
      'field_format' => 'right',
      'author' => 'right',
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
  $export['node|digital_heritage|community_record'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'featured_content_view_link',
        1 => 'field_media_asset',
        2 => 'featured_content_type',
        3 => 'title',
        4 => 'field_summary',
      ),
    ),
    'fields' => array(
      'featured_content_view_link' => 'central',
      'field_media_asset' => 'central',
      'featured_content_type' => 'central',
      'title' => 'central',
      'field_summary' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|digital_heritage|featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'group_tabs',
        3 => 'title',
        5 => 'field_summary',
        6 => 'field_media_asset',
        8 => 'og_group_ref',
        10 => 'field_item_privacy_setting',
        11 => 'body',
        12 => 'field_category',
        13 => 'field_creator',
        14 => 'group_essentials',
        15 => 'field_tk_body',
        16 => 'group_mukurtu_core',
        17 => 'field_contributor',
        18 => 'group_licensing',
        19 => 'field_description',
        20 => 'field_original_date',
        21 => 'field_date',
        22 => 'field_tags',
        23 => 'group_dublin',
        24 => 'group_relations',
        25 => 'field_format',
        26 => 'field_dh_type',
        27 => 'field_identifier',
        28 => 'field_language',
        29 => 'field_source',
        30 => 'field_subject',
        31 => 'field_people',
        32 => 'field_transcription',
        33 => 'field_coverage',
        34 => 'field_coverage_description',
        35 => 'field_publisher',
        36 => 'field_rights',
        37 => 'field_licence_trad',
        38 => 'field_licence_std_cc',
        39 => 'field_collection',
        40 => 'field_related_dh_items',
        41 => 'field_related_dictionary_words',
        42 => 'field_community_record_children',
        43 => 'field_book_children',
        44 => 'field_book_parent',
        45 => 'field_personal_collections',
      ),
      'hidden' => array(
        2 => 'field_community_record_parent',
        4 => 'path',
        7 => 'field_community_ref',
        9 => 'redirect',
        46 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'group_tabs' => 'ds_content',
      'field_community_record_parent' => 'hidden',
      'title' => 'ds_content',
      'path' => 'hidden',
      'field_summary' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_community_ref' => 'hidden',
      'og_group_ref' => 'ds_content',
      'redirect' => 'hidden',
      'field_item_privacy_setting' => 'ds_content',
      'body' => 'ds_content',
      'field_category' => 'ds_content',
      'field_creator' => 'ds_content',
      'group_essentials' => 'ds_content',
      'field_tk_body' => 'ds_content',
      'group_mukurtu_core' => 'ds_content',
      'field_contributor' => 'ds_content',
      'group_licensing' => 'ds_content',
      'field_description' => 'ds_content',
      'field_original_date' => 'ds_content',
      'field_date' => 'ds_content',
      'field_tags' => 'ds_content',
      'group_dublin' => 'ds_content',
      'group_relations' => 'ds_content',
      'field_format' => 'ds_content',
      'field_dh_type' => 'ds_content',
      'field_identifier' => 'ds_content',
      'field_language' => 'ds_content',
      'field_source' => 'ds_content',
      'field_subject' => 'ds_content',
      'field_people' => 'ds_content',
      'field_transcription' => 'ds_content',
      'field_coverage' => 'ds_content',
      'field_coverage_description' => 'ds_content',
      'field_publisher' => 'ds_content',
      'field_rights' => 'ds_content',
      'field_licence_trad' => 'ds_content',
      'field_licence_std_cc' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_related_dh_items' => 'ds_content',
      'field_related_dictionary_words' => 'ds_content',
      'field_community_record_children' => 'ds_content',
      'field_book_children' => 'ds_content',
      'field_book_parent' => 'ds_content',
      'field_personal_collections' => 'ds_content',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|digital_heritage|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'community_record_title',
        14 => 'dh_related_items_teasers',
        15 => 'field_community_ref',
        16 => 'og_group_ref',
        17 => 'field_category',
        18 => 'field_tags',
        19 => 'field_collection',
        20 => 'field_original_date',
        21 => 'field_date',
        22 => 'field_creator',
        23 => 'field_contributor',
        24 => 'field_language',
        25 => 'field_rights',
        26 => 'field_licence_trad',
        27 => 'field_licence_std_cc',
        28 => 'field_source',
        29 => 'field_publisher',
        30 => 'field_identifier',
        31 => 'field_subject',
        32 => 'field_dh_type',
        33 => 'field_format',
        34 => 'author',
      ),
      'left' => array(
        1 => 'field_media_asset',
        3 => 'field_summary',
        4 => 'field_description',
        5 => 'body',
        6 => 'field_tk_body',
        7 => 'field_people',
        8 => 'group_transcription',
        9 => 'field_coverage',
        10 => 'field_coverage_description',
        11 => 'field_related_dh_items',
        12 => 'field_transcription',
        13 => 'field_related_dictionary_words',
      ),
      'top' => array(
        2 => 'mukurtu_icon_actions',
      ),
      'bottom' => array(
        35 => 'comments',
      ),
    ),
    'fields' => array(
      'community_record_title' => 'right',
      'field_media_asset' => 'left',
      'mukurtu_icon_actions' => 'top',
      'field_summary' => 'left',
      'field_description' => 'left',
      'body' => 'left',
      'field_tk_body' => 'left',
      'field_people' => 'left',
      'group_transcription' => 'left',
      'field_coverage' => 'left',
      'field_coverage_description' => 'left',
      'field_related_dh_items' => 'left',
      'field_transcription' => 'left',
      'field_related_dictionary_words' => 'left',
      'dh_related_items_teasers' => 'right',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_category' => 'right',
      'field_tags' => 'right',
      'field_collection' => 'right',
      'field_original_date' => 'right',
      'field_date' => 'right',
      'field_creator' => 'right',
      'field_contributor' => 'right',
      'field_language' => 'right',
      'field_rights' => 'right',
      'field_licence_trad' => 'right',
      'field_licence_std_cc' => 'right',
      'field_source' => 'right',
      'field_publisher' => 'right',
      'field_identifier' => 'right',
      'field_subject' => 'right',
      'field_dh_type' => 'right',
      'field_format' => 'right',
      'author' => 'right',
      'comments' => 'bottom',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|digital_heritage|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|map_popup';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'map_popup';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_media_asset',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
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
  $export['node|digital_heritage|map_popup'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_media_asset',
      ),
      'right' => array(
        1 => 'group_list_view_fields',
        2 => 'title',
        3 => 'featured_content_type',
        4 => 'mukurtu_icon_actions',
        5 => 'digital_heritage_page_number',
        6 => 'field_community_ref',
        7 => 'field_category',
        8 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'left',
      'group_list_view_fields' => 'right',
      'title' => 'right',
      'featured_content_type' => 'right',
      'mukurtu_icon_actions' => 'right',
      'digital_heritage_page_number' => 'right',
      'field_community_ref' => 'right',
      'field_category' => 'right',
      'field_summary' => 'right',
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
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|digital_heritage|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|taxonomy_record_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'taxonomy_record_teaser';
  $ds_layout->layout = 'bootstrap_3_9';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_media_asset',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_summary',
        3 => 'field_community_ref',
        4 => 'field_category',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'left',
      'title' => 'right',
      'field_summary' => 'right',
      'field_community_ref' => 'right',
      'field_category' => 'right',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|digital_heritage|taxonomy_record_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_media_asset',
      ),
      'right' => array(
        1 => 'title',
        2 => 'featured_content_type',
        3 => 'field_community_ref',
        4 => 'field_category',
        5 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'left',
      'title' => 'right',
      'featured_content_type' => 'right',
      'field_community_ref' => 'right',
      'field_category' => 'right',
      'field_summary' => 'right',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|digital_heritage|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_digitalheritage_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'community_record';
  $ds_view_mode->label = 'Community Record';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['community_record'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'featured_content';
  $ds_view_mode->label = 'Featured Content';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'paragraphs_item' => 'paragraphs_item',
  );
  $export['featured_content'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'map_popup';
  $ds_view_mode->label = 'Map Popup';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['map_popup'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'taxonomy_record_teaser';
  $ds_view_mode->label = 'Taxonomy Record Teaser';
  $ds_view_mode->entities = array(
    'scald_atom' => 'scald_atom',
    'node' => 'node',
  );
  $export['taxonomy_record_teaser'] = $ds_view_mode;

  return $export;
}
