<?php
/**
 * @file
 * ma_importexport_dc.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_importexport_dc_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dh_xml_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Export Digital Heritage Metadata as XML';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Export Digital Heritage Metadata as XML';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_media_asset' => 'field_media_asset',
    'changed' => 'changed',
    'field_summary' => 'field_summary',
    'field_community_ref' => 'field_community_ref',
    'field_category' => 'field_category',
    'field_creator' => 'field_creator',
    'field_contributor' => 'field_contributor',
    'field_date' => 'field_date',
    'field_collection' => 'field_collection',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_media_asset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_summary' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_community_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_creator' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contributor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collection' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'dc:title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Creator */
  $handler->display->display_options['fields']['field_creator']['id'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['table'] = 'field_data_field_creator';
  $handler->display->display_options['fields']['field_creator']['field'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['label'] = 'dc:creator';
  $handler->display->display_options['fields']['field_creator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_creator']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_creator']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_creator']['separator'] = ';;;';
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['label'] = 'dc:subject';
  $handler->display->display_options['fields']['field_subject']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_subject']['separator'] = ';;;';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'dc:description';
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_publisher']['id'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['table'] = 'field_data_field_publisher';
  $handler->display->display_options['fields']['field_publisher']['field'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['label'] = 'dc:publisher';
  $handler->display->display_options['fields']['field_publisher']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_publisher']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_publisher']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publisher']['separator'] = ';;;';
  /* Field: Field: Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['label'] = 'dc:contributor';
  $handler->display->display_options['fields']['field_contributor']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_contributor']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_contributor']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contributor']['separator'] = ';;;';
  /* Field: Content: Original Date Description */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'dc:date';
  $handler->display->display_options['fields']['field_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date']['type'] = 'text_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_dh_type']['id'] = 'field_dh_type';
  $handler->display->display_options['fields']['field_dh_type']['table'] = 'field_data_field_dh_type';
  $handler->display->display_options['fields']['field_dh_type']['field'] = 'field_dh_type';
  $handler->display->display_options['fields']['field_dh_type']['label'] = 'dc:type';
  $handler->display->display_options['fields']['field_dh_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_dh_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_dh_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_dh_type']['separator'] = ';;;';
  /* Field: Content: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['label'] = 'dc:format';
  $handler->display->display_options['fields']['field_format']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_format']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_format']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_format']['separator'] = ';;;';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['label'] = 'dc:identifier';
  $handler->display->display_options['fields']['field_identifier']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_identifier']['type'] = 'text_plain';
  /* Field: Field: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['label'] = 'dc:source';
  $handler->display->display_options['fields']['field_source']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['label'] = 'dc:language';
  $handler->display->display_options['fields']['field_language']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_language']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_language']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_language']['separator'] = ';;;';
  /* Field: Content: Location Description */
  $handler->display->display_options['fields']['field_coverage_description']['id'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['table'] = 'field_data_field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['field'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['label'] = 'dc:coverage';
  $handler->display->display_options['fields']['field_coverage_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_coverage_description']['type'] = 'text_plain';
  /* Field: Field: Rights */
  $handler->display->display_options['fields']['field_rights']['id'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['table'] = 'field_data_field_rights';
  $handler->display->display_options['fields']['field_rights']['field'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['label'] = 'dc:rights';
  $handler->display->display_options['fields']['field_rights']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_rights']['type'] = 'text_plain';
  /* Field: Content: Media Assets */
  $handler->display->display_options['fields']['field_media_asset']['id'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['table'] = 'field_data_field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['field'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['label'] = 'dc:hasformat';
  $handler->display->display_options['fields']['field_media_asset']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_media_asset']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_media_asset']['type'] = 'file_representation';
  $handler->display->display_options['fields']['field_media_asset']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_media_asset']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_asset']['separator'] = ';;;';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_heritage' => 'digital_heritage',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Community (field_community_ref) */
  $handler->display->display_options['filters']['field_community_ref_nid']['id'] = 'field_community_ref_nid';
  $handler->display->display_options['filters']['field_community_ref_nid']['table'] = 'field_data_field_community_ref';
  $handler->display->display_options['filters']['field_community_ref_nid']['field'] = 'field_community_ref_nid';
  $handler->display->display_options['filters']['field_community_ref_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_community_ref_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['operator_id'] = 'field_community_ref_nid_op';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['label'] = 'Community';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['operator'] = 'field_community_ref_nid_op';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['identifier'] = 'field_community_ref_nid';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Field: Category (field_category) */
  $handler->display->display_options['filters']['field_category_tid']['id'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_tid']['field'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category_tid']['expose']['operator_id'] = 'field_category_tid_op';
  $handler->display->display_options['filters']['field_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_category_tid']['expose']['operator'] = 'field_category_tid_op';
  $handler->display->display_options['filters']['field_category_tid']['expose']['identifier'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_category_tid']['vocabulary'] = 'category';
  /* Filter criterion: Content: Creator (field_creator) */
  $handler->display->display_options['filters']['field_creator_tid']['id'] = 'field_creator_tid';
  $handler->display->display_options['filters']['field_creator_tid']['table'] = 'field_data_field_creator';
  $handler->display->display_options['filters']['field_creator_tid']['field'] = 'field_creator_tid';
  $handler->display->display_options['filters']['field_creator_tid']['value'] = '';
  $handler->display->display_options['filters']['field_creator_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_creator_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_creator_tid']['expose']['operator_id'] = 'field_creator_tid_op';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['label'] = 'Creator';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['operator'] = 'field_creator_tid_op';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['identifier'] = 'field_creator_tid';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_creator_tid']['vocabulary'] = 'creator';
  /* Filter criterion: Content: Community Record Parent (field_community_record_parent) */
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['id'] = 'field_community_record_parent_target_id';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['table'] = 'field_data_field_community_record_parent';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['field'] = 'field_community_record_parent_target_id';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['operator_id'] = 'field_community_record_parent_target_id_op';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['label'] = 'Community Record Parent (field_community_record_parent)';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['operator'] = 'field_community_record_parent_target_id_op';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['identifier'] = 'field_community_record_parent_target_id';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['group_info']['label'] = 'Is Community Record';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['group_info']['identifier'] = 'field_community_record_parent_target_id';
  /* Filter criterion: Content: Book Parent (field_book_parent) */
  $handler->display->display_options['filters']['field_book_parent_target_id']['id'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['table'] = 'field_data_field_book_parent';
  $handler->display->display_options['filters']['field_book_parent_target_id']['field'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_book_parent_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['operator_id'] = 'field_book_parent_target_id_op';
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['label'] = 'Book Parent (field_book_parent)';
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['operator'] = 'field_book_parent_target_id_op';
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['identifier'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_book_parent_target_id']['group_info']['label'] = 'Is Community Record';
  $handler->display->display_options['filters']['field_book_parent_target_id']['group_info']['identifier'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Dublin Core XML */
  $handler = $view->new_display('views_data_export', 'Dublin Core XML', 'dc_xml');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['attach_text'] = 'Export as Dublin Core';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'digital-heritage-export-dc.xml';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'rdf:RDF';
  $handler->display->display_options['style_options']['item_node'] = 'rdf:Description';
  $handler->display->display_options['path'] = 'export/digital-heritage-dc-xml';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'manage/digital-heritage';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: MODS XML */
  $handler = $view->new_display('views_data_export', 'MODS XML', 'mods_xml');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['attach_text'] = 'Export as MODS';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'digital-heritage-export-mods.xml';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'modsCollection';
  $handler->display->display_options['style_options']['item_node'] = 'mods';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'titleInfo/title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Creator */
  $handler->display->display_options['fields']['field_creator']['id'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['table'] = 'field_data_field_creator';
  $handler->display->display_options['fields']['field_creator']['field'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['label'] = 'name/namePart';
  $handler->display->display_options['fields']['field_creator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_creator']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_creator']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_creator']['separator'] = ';;;';
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['label'] = 'classification';
  $handler->display->display_options['fields']['field_subject']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_subject']['separator'] = ';;;';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'note';
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_publisher']['id'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['table'] = 'field_data_field_publisher';
  $handler->display->display_options['fields']['field_publisher']['field'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['label'] = 'originInfo/publisher';
  $handler->display->display_options['fields']['field_publisher']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_publisher']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_publisher']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publisher']['separator'] = ';;;';
  /* Field: Field: Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['label'] = 'name/namePart';
  $handler->display->display_options['fields']['field_contributor']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_contributor']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_contributor']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contributor']['separator'] = ';;;';
  /* Field: Content: Original Date Description */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'originInfo/dateCreated';
  $handler->display->display_options['fields']['field_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date']['type'] = 'text_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_dh_type']['id'] = 'field_dh_type';
  $handler->display->display_options['fields']['field_dh_type']['table'] = 'field_data_field_dh_type';
  $handler->display->display_options['fields']['field_dh_type']['field'] = 'field_dh_type';
  $handler->display->display_options['fields']['field_dh_type']['label'] = 'typeOfResource';
  $handler->display->display_options['fields']['field_dh_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_dh_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_dh_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_dh_type']['separator'] = ';;;';
  /* Field: Content: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['label'] = 'physicalDescription/extent';
  $handler->display->display_options['fields']['field_format']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_format']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_format']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_format']['separator'] = ';;;';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['label'] = 'identifier';
  $handler->display->display_options['fields']['field_identifier']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_identifier']['type'] = 'text_plain';
  /* Field: Field: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['label'] = 'relatedItem';
  $handler->display->display_options['fields']['field_source']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['label'] = 'language/languageTerm';
  $handler->display->display_options['fields']['field_language']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_language']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_language']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_language']['separator'] = ';;;';
  /* Field: Content: Location Description */
  $handler->display->display_options['fields']['field_coverage_description']['id'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['table'] = 'field_data_field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['field'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['label'] = 'originInfo/place/placeTerm';
  $handler->display->display_options['fields']['field_coverage_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_coverage_description']['type'] = 'text_plain';
  /* Field: Field: Rights */
  $handler->display->display_options['fields']['field_rights']['id'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['table'] = 'field_data_field_rights';
  $handler->display->display_options['fields']['field_rights']['field'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['label'] = 'accessCondition';
  $handler->display->display_options['fields']['field_rights']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_rights']['type'] = 'text_plain';
  /* Field: Content: Media Assets */
  $handler->display->display_options['fields']['field_media_asset']['id'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['table'] = 'field_data_field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['field'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['label'] = 'location/url';
  $handler->display->display_options['fields']['field_media_asset']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_media_asset']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_media_asset']['type'] = 'file_representation';
  $handler->display->display_options['fields']['field_media_asset']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_media_asset']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_asset']['separator'] = ';;;';
  $handler->display->display_options['path'] = 'export/digital-heritage-mods-xml';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'manage/digital-heritage';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['dh_xml_export'] = array(
    t('Master'),
    t('Export Digital Heritage Metadata as XML'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('dc:title'),
    t('dc:creator'),
    t('dc:subject'),
    t('dc:description'),
    t('dc:publisher'),
    t('dc:contributor'),
    t('dc:date'),
    t('dc:type'),
    t('dc:format'),
    t('dc:identifier'),
    t('dc:source'),
    t('dc:language'),
    t('dc:coverage'),
    t('dc:rights'),
    t('dc:hasformat'),
    t('Title'),
    t('Community'),
    t('Category'),
    t('Creator'),
    t('Community Record Parent (field_community_record_parent)'),
    t('Is Community Record'),
    t('Book Parent (field_book_parent)'),
    t('Dublin Core XML'),
    t('MODS XML'),
    t('titleInfo/title'),
    t('name/namePart'),
    t('classification'),
    t('note'),
    t('originInfo/publisher'),
    t('originInfo/dateCreated'),
    t('typeOfResource'),
    t('physicalDescription/extent'),
    t('identifier'),
    t('relatedItem'),
    t('language/languageTerm'),
    t('originInfo/place/placeTerm'),
    t('accessCondition'),
    t('location/url'),
  );
  $export['dh_xml_export'] = $view;

  return $export;
}
