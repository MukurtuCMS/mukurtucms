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
    'author' => array(
      'format' => 'author',
      'label' => 'above',
      'weight' => '30',
    ),
    'field_licence_trad' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'clearfix',
        ),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '0',
        'wrapper' => '',
      ),
      'label' => 'above',
      'weight' => '12',
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
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'featured_content_view_link' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'field_media_asset' => array(
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
      'weight' => '3',
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
    'author' => array(
      'format' => 'author_linked',
      'label' => 'above',
      'weight' => '34',
    ),
    'comments' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '35',
    ),
    'community_record_title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Title',
        ),
      ),
      'label' => 'above',
      'weight' => '12',
    ),
    'dh_related_items_teasers' => array(
      'format' => 'default',
      'label' => 'above',
      'weight' => '13',
    ),
    'field_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
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
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
      'label' => 'hidden',
      'weight' => '1',
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
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h3',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|digital_heritage|map_popup'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'format' => 'author',
      'label' => 'above',
      'weight' => '32',
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|digital_heritage|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'digital_heritage_page_number' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '5',
    ),
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'field_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
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
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '4',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '3',
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
  $export['node|digital_heritage|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|taxonomy_record_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'taxonomy_record_teaser';
  $ds_fieldsetting->settings = array(
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
  $export['node|digital_heritage|taxonomy_record_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_heritage|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_heritage';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'field_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
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
      'format' => 'ds_code',
      'value' => '<?php
print _ma_digitalheritage_ds_community_record_title($entity);',
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
      'format' => 'ds_code',
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
      'format' => 'ds_code',
      'value' => '<?php
$info = entity_get_info(\'node\');
$type = $entity->type;
if(isset($info[\'bundles\'][$type])) {
    print $info[\'bundles\'][$type][\'label\'];
}
?>',
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
      'format' => 'ds_code',
      'value' => '<a href="<?php print drupal_get_path_alias(\'node/\' . $entity->nid)?>"><?php print t(\'View Content\');?></a>',
    ),
    'use_token' => 0,
  );
  $export['featured_content_view_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'mukurtu_icon_actions';
  $ds_field->label = 'Add to Personal Collection';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'format' => 'ds_code',
      'value' => '<?php
  ma_collection_add_to_personal_collection_icon_ds_field($entity);
?>',
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'author' => 'right',
      'body' => 'left',
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'field_contributor' => 'right',
      'field_coverage' => 'left',
      'field_coverage_description' => 'left',
      'field_creator' => 'right',
      'field_date' => 'right',
      'field_description' => 'left',
      'field_dh_type' => 'right',
      'field_format' => 'right',
      'field_identifier' => 'right',
      'field_language' => 'right',
      'field_licence_std_cc' => 'right',
      'field_licence_trad' => 'right',
      'field_media_asset' => 'left',
      'field_people' => 'left',
      'field_publisher' => 'right',
      'field_related_content' => 'left',
      'field_rights' => 'right',
      'field_source' => 'right',
      'field_subject' => 'right',
      'field_summary' => 'left',
      'field_tags' => 'right',
      'field_tk_body' => 'left',
      'field_transcription' => 'left',
      'group_transcription_cr' => 'left',
      'og_group_ref' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'field_summary',
        1 => 'field_media_asset',
        2 => 'field_description',
        3 => 'body',
        4 => 'field_tk_body',
        5 => 'field_people',
        6 => 'group_transcription_cr',
        7 => 'field_transcription',
        8 => 'field_coverage',
        9 => 'field_coverage_description',
        10 => 'field_related_content',
      ),
      'right' => array(
        11 => 'title',
        12 => 'field_community_ref',
        13 => 'og_group_ref',
        14 => 'field_category',
        15 => 'field_tags',
        16 => 'field_date',
        17 => 'field_creator',
        18 => 'field_contributor',
        19 => 'field_language',
        20 => 'field_rights',
        21 => 'field_licence_trad',
        22 => 'field_licence_std_cc',
        23 => 'field_source',
        24 => 'field_publisher',
        25 => 'field_identifier',
        26 => 'field_subject',
        27 => 'field_dh_type',
        28 => 'field_format',
        29 => 'author',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'central',
      'featured_content_view_link' => 'central',
      'field_media_asset' => 'central',
      'field_summary' => 'central',
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
        1 => 'field_media_asset',
        2 => 'featured_content_type',
        3 => 'title',
        4 => 'field_summary',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'hidden',
      'body' => 'ds_content',
      'field_book_children' => 'ds_content',
      'field_book_parent' => 'ds_content',
      'field_category' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_comm_records_mm' => 'hidden',
      'field_community_record_children' => 'ds_content',
      'field_community_record_parent' => 'hidden',
      'field_community_ref' => 'hidden',
      'field_contributor' => 'ds_content',
      'field_coverage' => 'ds_content',
      'field_coverage_description' => 'ds_content',
      'field_creator' => 'ds_content',
      'field_date' => 'ds_content',
      'field_description' => 'ds_content',
      'field_dh_type' => 'ds_content',
      'field_external_links' => 'ds_content',
      'field_format' => 'ds_content',
      'field_identifier' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_language' => 'ds_content',
      'field_licence_std_cc' => 'ds_content',
      'field_licence_trad' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_original_date' => 'ds_content',
      'field_people' => 'ds_content',
      'field_personal_collections' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'field_publisher' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_related_dh_items' => 'hidden',
      'field_related_dictionary_words' => 'hidden',
      'field_rights' => 'ds_content',
      'field_source' => 'ds_content',
      'field_subject' => 'ds_content',
      'field_summary' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_tk_body' => 'ds_content',
      'field_transcription' => 'ds_content',
      'group_dublin' => 'ds_content',
      'group_essentials' => 'ds_content',
      'group_licensing' => 'ds_content',
      'group_mukurtu_core' => 'ds_content',
      'group_relations' => 'ds_content',
      'group_tabs' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'path' => 'hidden',
      'redirect' => 'hidden',
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
        2 => 'title',
        5 => 'field_summary',
        7 => 'field_media_asset',
        9 => 'og_group_ref',
        10 => 'field_item_privacy_setting',
        11 => 'body',
        12 => 'field_creator',
        13 => 'field_category',
        14 => 'group_essentials',
        15 => 'field_tk_body',
        16 => 'field_contributor',
        17 => 'group_mukurtu_core',
        18 => 'field_description',
        19 => 'field_original_date',
        20 => 'group_licensing',
        21 => 'field_tags',
        22 => 'field_date',
        23 => 'group_dublin',
        24 => 'group_relations',
        25 => 'field_format',
        26 => 'field_dh_type',
        27 => 'field_identifier',
        28 => 'field_language',
        29 => 'field_source',
        30 => 'field_subject',
        31 => 'field_transcription',
        32 => 'field_people',
        33 => 'field_coverage',
        34 => 'field_coverage_description',
        35 => 'field_external_links',
        36 => 'field_publisher',
        37 => 'field_rights',
        38 => 'field_licence_trad',
        39 => 'field_licence_std_cc',
        40 => 'field_community_record_children',
        41 => 'field_book_children',
        42 => 'field_book_parent',
        43 => 'field_related_content',
        44 => 'field_collection',
        45 => 'field_personal_collections',
      ),
      'hidden' => array(
        3 => 'field_community_record_parent',
        4 => 'path',
        6 => 'field_community_ref',
        8 => 'redirect',
        46 => 'field_related_dh_items',
        47 => 'field_related_dictionary_words',
        48 => 'field_comm_records_mm',
        49 => '_add_existing_field',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'author' => 'right',
      'body' => 'left',
      'comments' => 'bottom',
      'community_record_title' => 'right',
      'dh_related_items_teasers' => 'right',
      'field_category' => 'right',
      'field_collection' => 'right',
      'field_community_ref' => 'right',
      'field_contributor' => 'right',
      'field_coverage' => 'left',
      'field_coverage_description' => 'left',
      'field_creator' => 'right',
      'field_date' => 'right',
      'field_description' => 'left',
      'field_dh_type' => 'right',
      'field_external_links' => 'right',
      'field_format' => 'right',
      'field_identifier' => 'right',
      'field_language' => 'right',
      'field_licence_std_cc' => 'right',
      'field_licence_trad' => 'right',
      'field_media_asset' => 'left',
      'field_original_date' => 'right',
      'field_people' => 'left',
      'field_publisher' => 'right',
      'field_related_content' => 'left',
      'field_rights' => 'right',
      'field_source' => 'right',
      'field_subject' => 'right',
      'field_summary' => 'left',
      'field_tags' => 'right',
      'field_tk_body' => 'left',
      'field_transcription' => 'left',
      'group_transcription' => 'left',
      'mukurtu_icon_actions' => 'top',
      'mukurtu_mobile_sync' => 'top',
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
        36 => 'comments',
      ),
      'left' => array(
        2 => 'field_media_asset',
        3 => 'field_summary',
        4 => 'field_description',
        5 => 'body',
        6 => 'field_tk_body',
        7 => 'group_transcription',
        8 => 'field_people',
        9 => 'field_coverage',
        10 => 'field_transcription',
        11 => 'field_coverage_description',
        12 => 'field_related_content',
      ),
      'right' => array(
        13 => 'community_record_title',
        14 => 'dh_related_items_teasers',
        15 => 'og_group_ref',
        16 => 'field_community_ref',
        17 => 'field_category',
        18 => 'field_tags',
        19 => 'field_collection',
        20 => 'field_date',
        21 => 'field_original_date',
        22 => 'field_creator',
        23 => 'field_contributor',
        24 => 'field_language',
        25 => 'field_rights',
        26 => 'field_licence_trad',
        27 => 'field_licence_std_cc',
        28 => 'field_source',
        29 => 'field_external_links',
        30 => 'field_publisher',
        31 => 'field_identifier',
        32 => 'field_subject',
        33 => 'field_dh_type',
        34 => 'field_format',
        35 => 'author',
      ),
      'top' => array(
        0 => 'mukurtu_icon_actions',
        1 => 'mukurtu_mobile_sync',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'limit' => array(
      'field_media_asset' => '1',
    ),
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_media_asset',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|digital_heritage|map_popup'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'author' => 'ds_content',
      'body' => 'ds_content',
      'field_category' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_comm_records_mm' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_contributor' => 'ds_content',
      'field_coverage' => 'ds_content',
      'field_coverage_description' => 'ds_content',
      'field_creator' => 'ds_content',
      'field_date' => 'ds_content',
      'field_description' => 'ds_content',
      'field_dh_type' => 'ds_content',
      'field_format' => 'ds_content',
      'field_identifier' => 'ds_content',
      'field_language' => 'ds_content',
      'field_licence_std_cc' => 'ds_content',
      'field_licence_trad' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_original_date' => 'ds_content',
      'field_people' => 'ds_content',
      'field_publisher' => 'ds_content',
      'field_related_dh_items' => 'ds_content',
      'field_related_dictionary_words' => 'ds_content',
      'field_rights' => 'ds_content',
      'field_source' => 'ds_content',
      'field_subject' => 'ds_content',
      'field_summary' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_tk_body' => 'ds_content',
      'field_transcription' => 'ds_content',
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
        1 => 'field_media_asset',
        2 => 'field_community_ref',
        3 => 'og_group_ref',
        4 => 'field_comm_records_mm',
        5 => 'field_summary',
        6 => 'field_description',
        7 => 'body',
        8 => 'field_tk_body',
        9 => 'field_tags',
        10 => 'field_category',
        11 => 'field_original_date',
        12 => 'field_date',
        13 => 'field_people',
        14 => 'field_transcription',
        15 => 'field_coverage',
        16 => 'field_coverage_description',
        17 => 'field_related_dh_items',
        18 => 'field_related_dictionary_words',
        19 => 'field_collection',
        20 => 'field_creator',
        21 => 'field_contributor',
        22 => 'field_language',
        23 => 'field_rights',
        24 => 'field_licence_trad',
        25 => 'field_licence_std_cc',
        26 => 'field_source',
        27 => 'field_publisher',
        28 => 'field_identifier',
        29 => 'field_subject',
        30 => 'field_dh_type',
        31 => 'field_format',
        32 => 'author',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|digital_heritage|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_heritage|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_heritage';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'digital_heritage_page_number' => 'right',
      'featured_content_type' => 'right',
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'field_media_asset' => 'left',
      'field_summary' => 'right',
      'group_list_view_fields' => 'right',
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
    'limit' => array(
      'field_media_asset' => '1',
    ),
    'regions' => array(
      'left' => array(
        0 => 'field_media_asset',
      ),
      'right' => array(
        1 => 'group_list_view_fields',
        2 => 'title',
        3 => 'featured_content_type',
        4 => 'mukurtu_mobile_sync',
        5 => 'mukurtu_icon_actions',
        6 => 'digital_heritage_page_number',
        7 => 'field_community_ref',
        8 => 'field_category',
        9 => 'field_summary',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'field_media_asset' => 'left',
      'field_summary' => 'right',
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
        0 => 'field_media_asset',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_summary',
        3 => 'field_community_ref',
        4 => 'field_category',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'field_media_asset' => 'left',
      'field_summary' => 'right',
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
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
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
    'node' => 'node',
    'scald_atom' => 'scald_atom',
  );
  $export['taxonomy_record_teaser'] = $ds_view_mode;

  return $export;
}
