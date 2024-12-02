<?php

/**
 * @file
 * ma_importexport.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_importexport_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'export';
  $view->description = 'A filtering CSV exporter inspired by Browse.';
  $view->tag = 'custom';
  $view->base_table = 'node';
  $view->human_name = 'Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Export Digital Heritage items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    7 => '7',
    4 => '4',
    5 => '5',
    3 => '3',
    8 => '8',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_media']['id'] = 'field_media';
  $handler->display->display_options['fields']['field_media']['table'] = 'field_data_field_media';
  $handler->display->display_options['fields']['field_media']['field'] = 'field_media';
  $handler->display->display_options['fields']['field_media']['label'] = '';
  $handler->display->display_options['fields']['field_media']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media']['hide_alter_empty'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_heritage' => 'digital_heritage',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Published status or admin user */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Export as CSV */
  $handler = $view->new_display('views_data_export', 'Export as CSV', 'views_data_export');
  $handler->display->display_options['display_description'] = 'Export Digital Heritage items';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_digital_heritage_%view_%exposed.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['encoding'] = 'ASCII';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Feeds item: Item GUID */
  $handler->display->display_options['fields']['guid']['id'] = 'guid';
  $handler->display->display_options['fields']['guid']['table'] = 'feeds_item';
  $handler->display->display_options['fields']['guid']['field'] = 'guid';
  $handler->display->display_options['fields']['guid']['label'] = 'guid';
  $handler->display->display_options['fields']['guid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['guid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['guid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['guid']['empty'] = '[nid]';
  $handler->display->display_options['fields']['guid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_category']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_description']['hide_alter_empty'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Cultural Narrative';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Traditional Knowledge */
  $handler->display->display_options['fields']['field_tk_body']['id'] = 'field_tk_body';
  $handler->display->display_options['fields']['field_tk_body']['table'] = 'field_data_field_tk_body';
  $handler->display->display_options['fields']['field_tk_body']['field'] = 'field_tk_body';
  $handler->display->display_options['fields']['field_tk_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tk_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tk_body']['hide_alter_empty'] = FALSE;
  /* Field: Field: Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributor']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_contributor']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_contributor']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_contributor']['delta_offset'] = '0';
  /* Field: Content: Creator */
  $handler->display->display_options['fields']['field_creator']['id'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['table'] = 'field_data_field_creator';
  $handler->display->display_options['fields']['field_creator']['field'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_creator']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_creator']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_creator']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_creator']['delta_offset'] = '0';
  /* Field: Content: Original Date Description */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_date']['group_column'] = 'entity_id';
  /* Field: Content: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_format']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_format']['group_column'] = 'entity_id';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['type'] = 'text_plain';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_language']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_language']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_language']['delta_offset'] = '0';
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_publisher']['id'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['table'] = 'field_data_field_publisher';
  $handler->display->display_options['fields']['field_publisher']['field'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['delta_offset'] = '0';
  /* Field: Field: Rights */
  $handler->display->display_options['fields']['field_rights']['id'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['table'] = 'field_data_field_rights';
  $handler->display->display_options['fields']['field_rights']['field'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rights']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rights']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_rights']['type'] = 'text_plain';
  /* Field: Field: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_source']['hide_alter_empty'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_coverage']['id'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['table'] = 'field_data_field_coverage';
  $handler->display->display_options['fields']['field_coverage']['field'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['label'] = 'Latitude';
  $handler->display->display_options['fields']['field_coverage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coverage']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coverage']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_coverage']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_coverage_1']['id'] = 'field_coverage_1';
  $handler->display->display_options['fields']['field_coverage_1']['table'] = 'field_data_field_coverage';
  $handler->display->display_options['fields']['field_coverage_1']['field'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage_1']['label'] = 'Longitude';
  $handler->display->display_options['fields']['field_coverage_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coverage_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coverage_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_coverage_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Location Description */
  $handler->display->display_options['fields']['field_coverage_description']['id'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['table'] = 'field_data_field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['field'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['element_label_colon'] = FALSE;
  /* Field: Content: Traditional Knowledge Labels */
  $handler->display->display_options['fields']['field_licence_trad']['id'] = 'field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad']['table'] = 'field_data_field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad']['field'] = 'field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad']['label'] = 'Traditional Licensing URL';
  $handler->display->display_options['fields']['field_licence_trad']['alter']['text'] = '[field_licence_trad-value]';
  $handler->display->display_options['fields']['field_licence_trad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_licence_trad']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_licence_trad']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_licence_trad']['type'] = 'license_formatter_export';
  /* Field: Content: Traditional Knowledge Labels */
  $handler->display->display_options['fields']['field_licence_trad_1']['id'] = 'field_licence_trad_1';
  $handler->display->display_options['fields']['field_licence_trad_1']['table'] = 'field_data_field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad_1']['field'] = 'field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad_1']['element_label_colon'] = FALSE;
  /* Field: Field: Standard and Creative Commons Licensing */
  $handler->display->display_options['fields']['field_licence_std_cc_1']['id'] = 'field_licence_std_cc_1';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['table'] = 'field_data_field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['field'] = 'field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['label'] = 'Standard and Creative Commons Licensing URL';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['type'] = 'license_formatter_export';
  /* Field: Field: Standard and Creative Commons Licensing */
  $handler->display->display_options['fields']['field_licence_std_cc']['id'] = 'field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc']['table'] = 'field_data_field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc']['field'] = 'field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_licence_std_cc']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_licence_std_cc']['hide_alter_empty'] = FALSE;
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Collections */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_collection']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_collection']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_collection']['delta_offset'] = '0';
  /* Field: Content: Sharing protocol */
  $handler->display->display_options['fields']['group_access']['id'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['table'] = 'field_data_group_access';
  $handler->display->display_options['fields']['group_access']['field'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_access']['type'] = 'list_key';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'export';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Export as zip */
  $handler = $view->new_display('page', 'Export as zip', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'zip_export_media';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_media']['id'] = 'field_media';
  $handler->display->display_options['fields']['field_media']['table'] = 'field_data_field_media';
  $handler->display->display_options['fields']['field_media']['field'] = 'field_media';
  $handler->display->display_options['fields']['field_media']['label'] = '';
  $handler->display->display_options['fields']['field_media']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_heritage' => 'digital_heritage',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Published status or admin user */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['path'] = 'zip';

  /* Display: Export as XML */
  $handler = $view->new_display('views_data_export', 'Export as XML', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'Export Digital Heritage items';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'nodes';
  $handler->display->display_options['style_options']['item_node'] = 'node';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Feeds item: Item GUID */
  $handler->display->display_options['fields']['guid']['id'] = 'guid';
  $handler->display->display_options['fields']['guid']['table'] = 'feeds_item';
  $handler->display->display_options['fields']['guid']['field'] = 'guid';
  $handler->display->display_options['fields']['guid']['label'] = 'guid';
  $handler->display->display_options['fields']['guid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['guid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['guid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['guid']['empty'] = '[nid]';
  $handler->display->display_options['fields']['guid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Media';
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$node = node_load($row->nid);
$media_items = array();
foreach($node->field_media[\'und\'] as $media) {
$fid = $media[\'fid\'];
array_push($media_items, file_load($fid)->filename);
}
$output = implode(",", $media_items);
print $output;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Media Internet (Off)';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$node = node_load($row->nid);
$media_items = array();
foreach($node->field_media[\'und\'] as $media) {
$fid = $media[\'fid\'];
$path = file_load($fid)->uri;
$path_root = explode(\'//\', $path);

if(!empty($path_root[0])){
switch($path_root[0]){

case \'oembed:\':
array_push($media_items, \'http://\' . $path_root[2]);
break;

}
}

}
$output = implode(",", $media_items);
print $output;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_communities']['id'] = 'field_communities';
  $handler->display->display_options['fields']['field_communities']['table'] = 'field_data_field_communities';
  $handler->display->display_options['fields']['field_communities']['field'] = 'field_communities';
  $handler->display->display_options['fields']['field_communities']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_culturalprotocol']['id'] = 'field_culturalprotocol';
  $handler->display->display_options['fields']['field_culturalprotocol']['table'] = 'field_data_field_culturalprotocol';
  $handler->display->display_options['fields']['field_culturalprotocol']['field'] = 'field_culturalprotocol';
  $handler->display->display_options['fields']['field_culturalprotocol']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_culturalprotocol']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_relation']['id'] = 'field_relation';
  $handler->display->display_options['fields']['field_relation']['table'] = 'field_data_field_relation';
  $handler->display->display_options['fields']['field_relation']['field'] = 'field_relation';
  $handler->display->display_options['fields']['field_relation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_relation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_relation']['hide_alter_empty'] = FALSE;
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_category']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_description']['hide_alter_empty'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Cultural Narrative';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Traditional Knowledge */
  $handler->display->display_options['fields']['field_tk_body']['id'] = 'field_tk_body';
  $handler->display->display_options['fields']['field_tk_body']['table'] = 'field_data_field_tk_body';
  $handler->display->display_options['fields']['field_tk_body']['field'] = 'field_tk_body';
  $handler->display->display_options['fields']['field_tk_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tk_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tk_body']['hide_alter_empty'] = FALSE;
  /* Field: Field: Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributor']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_contributor']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_contributor']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_contributor']['delta_offset'] = '0';
  /* Field: Content: Creator */
  $handler->display->display_options['fields']['field_creator']['id'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['table'] = 'field_data_field_creator';
  $handler->display->display_options['fields']['field_creator']['field'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_creator']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_creator']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_creator']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_creator']['delta_offset'] = '0';
  /* Field: Content: Original Date Description */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_date']['group_column'] = 'entity_id';
  /* Field: Content: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_format']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_format']['group_column'] = 'entity_id';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['type'] = 'text_plain';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_language']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_language']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_language']['delta_offset'] = '0';
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_publisher']['id'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['table'] = 'field_data_field_publisher';
  $handler->display->display_options['fields']['field_publisher']['field'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_publisher']['delta_offset'] = '0';
  /* Field: Field: Rights */
  $handler->display->display_options['fields']['field_rights']['id'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['table'] = 'field_data_field_rights';
  $handler->display->display_options['fields']['field_rights']['field'] = 'field_rights';
  $handler->display->display_options['fields']['field_rights']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rights']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rights']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_rights']['type'] = 'text_plain';
  /* Field: Field: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_source']['hide_alter_empty'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['group_content_access']['id'] = 'group_content_access';
  $handler->display->display_options['fields']['group_content_access']['table'] = 'field_data_group_content_access';
  $handler->display->display_options['fields']['group_content_access']['field'] = 'group_content_access';
  $handler->display->display_options['fields']['group_content_access']['label'] = 'Sharing Protocols';
  $handler->display->display_options['fields']['group_content_access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_content_access']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['group_content_access']['hide_alter_empty'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_coverage']['id'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['table'] = 'field_data_field_coverage';
  $handler->display->display_options['fields']['field_coverage']['field'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['label'] = 'Latitude';
  $handler->display->display_options['fields']['field_coverage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coverage']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coverage']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_coverage']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_coverage_1']['id'] = 'field_coverage_1';
  $handler->display->display_options['fields']['field_coverage_1']['table'] = 'field_data_field_coverage';
  $handler->display->display_options['fields']['field_coverage_1']['field'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage_1']['label'] = 'Longitude';
  $handler->display->display_options['fields']['field_coverage_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coverage_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coverage_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_coverage_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Location Description */
  $handler->display->display_options['fields']['field_coverage_description']['id'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['table'] = 'field_data_field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['field'] = 'field_coverage_description';
  $handler->display->display_options['fields']['field_coverage_description']['element_label_colon'] = FALSE;
  /* Field: Content: Traditional Knowledge Labels */
  $handler->display->display_options['fields']['field_licence_trad']['id'] = 'field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad']['table'] = 'field_data_field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad']['field'] = 'field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad']['label'] = 'Traditional Licensing URL';
  $handler->display->display_options['fields']['field_licence_trad']['alter']['text'] = '[field_licence_trad-value]';
  $handler->display->display_options['fields']['field_licence_trad']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_licence_trad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_licence_trad']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_licence_trad']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_licence_trad']['type'] = 'license_formatter_export';
  /* Field: Content: Traditional Knowledge Labels */
  $handler->display->display_options['fields']['field_licence_trad_1']['id'] = 'field_licence_trad_1';
  $handler->display->display_options['fields']['field_licence_trad_1']['table'] = 'field_data_field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad_1']['field'] = 'field_licence_trad';
  $handler->display->display_options['fields']['field_licence_trad_1']['element_label_colon'] = FALSE;
  /* Field: Field: Standard and Creative Commons Licensing */
  $handler->display->display_options['fields']['field_licence_std_cc_1']['id'] = 'field_licence_std_cc_1';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['table'] = 'field_data_field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['field'] = 'field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['label'] = 'Standard and Creative Commons Licensing URL';
  $handler->display->display_options['fields']['field_licence_std_cc_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_licence_std_cc_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_licence_std_cc_1']['type'] = 'license_formatter_export';
  /* Field: Field: Standard and Creative Commons Licensing */
  $handler->display->display_options['fields']['field_licence_std_cc']['id'] = 'field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc']['table'] = 'field_data_field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc']['field'] = 'field_licence_std_cc';
  $handler->display->display_options['fields']['field_licence_std_cc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_licence_std_cc']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_licence_std_cc']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'export/xml';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = '1';
  $translatables['export'] = array(
    t('Master'),
    t('Export Digital Heritage items'),
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
    t('No results'),
    t('No results found'),
    t('OG membership from node'),
    t('group'),
    t('Path'),
    t('All'),
    t('Export as CSV'),
    t('nid'),
    t('guid'),
    t('[nid]'),
    t('Title'),
    t('Category'),
    t('Keywords'),
    t('Description'),
    t('Cultural Narrative'),
    t('Traditional Knowledge'),
    t('Contributor'),
    t('Creator'),
    t('Date'),
    t('Format'),
    t('Identifier'),
    t('Language'),
    t('Publisher'),
    t('Rights'),
    t('Source'),
    t('Subject'),
    t('Latitude'),
    t('Longitude'),
    t('Location Description'),
    t('Traditional Licensing URL'),
    t('[field_licence_trad-value]'),
    t('Traditional Knowledge Labels'),
    t('Standard and Creative Commons Licensing URL'),
    t('Standard and Creative Commons Licensing'),
    t('Published status'),
    t('Collections'),
    t('Sharing protocol'),
    t('Export as zip'),
    t('Export as XML'),
    t('title'),
    t('Media'),
    t('Media Internet (Off)'),
    t('Broken handler field_data_field_communities.field_communities'),
    t('Broken handler field_data_field_culturalprotocol.field_culturalprotocol'),
    t('Broken handler field_data_field_relation.field_relation'),
    t('Original Date Description'),
    t('Sharing Protocols'),
  );
  $export['export'] = $view;

  return $export;
}
