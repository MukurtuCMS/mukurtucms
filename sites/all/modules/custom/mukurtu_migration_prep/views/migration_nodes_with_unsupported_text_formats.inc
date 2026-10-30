<?php
$view = new view();
$view->name = 'migration_nodes_with_unsupported_text_formats';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Migration: Nodes with Unsupported Text Formats';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Migration: Nodes with Unsupported Text Formats';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'title' => 'title',
  'type' => 'type',
);
$handler->display->display_options['style_options']['class'] = '';
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = 'Back to Migration Summary Link';
$handler->display->display_options['header']['area']['content'] = '<a href="/admin/reports/migration/summary">Back to Migration Summary</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['label'] = 'Back to Migration Summary Link';
$handler->display->display_options['footer']['area']['content'] = '<a href="/admin/reports/migration/summary">Back to Migration Summary</a>';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_this_page'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'OR',
);
/* Filter criterion: Content: Body (body:format) */
$handler->display->display_options['filters']['body_format']['id'] = 'body_format';
$handler->display->display_options['filters']['body_format']['table'] = 'field_data_body';
$handler->display->display_options['filters']['body_format']['field'] = 'body_format';
$handler->display->display_options['filters']['body_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['body_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['body_format']['group'] = 1;
/* Filter criterion: Content: Additional Media (field_additional_media:format) */
$handler->display->display_options['filters']['field_additional_media_format']['id'] = 'field_additional_media_format';
$handler->display->display_options['filters']['field_additional_media_format']['table'] = 'field_data_field_additional_media';
$handler->display->display_options['filters']['field_additional_media_format']['field'] = 'field_additional_media_format';
$handler->display->display_options['filters']['field_additional_media_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_additional_media_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_additional_media_format']['group'] = 1;
/* Filter criterion: Content: Assessment(s) (field_unit_assessments:format) */
$handler->display->display_options['filters']['field_unit_assessments_format']['id'] = 'field_unit_assessments_format';
$handler->display->display_options['filters']['field_unit_assessments_format']['table'] = 'field_data_field_unit_assessments';
$handler->display->display_options['filters']['field_unit_assessments_format']['field'] = 'field_unit_assessments_format';
$handler->display->display_options['filters']['field_unit_assessments_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_unit_assessments_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_unit_assessments_format']['group'] = 1;
/* Filter criterion: Content: Body (body:format) */
$handler->display->display_options['filters']['body_format_1']['id'] = 'body_format_1';
$handler->display->display_options['filters']['body_format_1']['table'] = 'field_data_body';
$handler->display->display_options['filters']['body_format_1']['field'] = 'body_format';
$handler->display->display_options['filters']['body_format_1']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['body_format_1']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['body_format_1']['group'] = 1;
/* Filter criterion: Content: Conceptual (field_unit_conceptual:format) */
$handler->display->display_options['filters']['field_unit_conceptual_format']['id'] = 'field_unit_conceptual_format';
$handler->display->display_options['filters']['field_unit_conceptual_format']['table'] = 'field_data_field_unit_conceptual';
$handler->display->display_options['filters']['field_unit_conceptual_format']['field'] = 'field_unit_conceptual_format';
$handler->display->display_options['filters']['field_unit_conceptual_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_unit_conceptual_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_unit_conceptual_format']['group'] = 1;
/* Filter criterion: Content: Credit (field_collection_credit:format) */
$handler->display->display_options['filters']['field_collection_credit_format']['id'] = 'field_collection_credit_format';
$handler->display->display_options['filters']['field_collection_credit_format']['table'] = 'field_data_field_collection_credit';
$handler->display->display_options['filters']['field_collection_credit_format']['field'] = 'field_collection_credit_format';
$handler->display->display_options['filters']['field_collection_credit_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_collection_credit_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_collection_credit_format']['group'] = 1;
/* Filter criterion: Content: Description (field_description:format) */
$handler->display->display_options['filters']['field_description_format']['id'] = 'field_description_format';
$handler->display->display_options['filters']['field_description_format']['table'] = 'field_data_field_description';
$handler->display->display_options['filters']['field_description_format']['field'] = 'field_description_format';
$handler->display->display_options['filters']['field_description_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_description_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_description_format']['group'] = 1;
/* Filter criterion: Content: Identifier (field_identifier:format) */
$handler->display->display_options['filters']['field_identifier_format']['id'] = 'field_identifier_format';
$handler->display->display_options['filters']['field_identifier_format']['table'] = 'field_data_field_identifier';
$handler->display->display_options['filters']['field_identifier_format']['field'] = 'field_identifier_format';
$handler->display->display_options['filters']['field_identifier_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_identifier_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_identifier_format']['group'] = 1;
/* Filter criterion: Content: Language learning (field_unit_language_learning:format) */
$handler->display->display_options['filters']['field_unit_language_learning_format']['id'] = 'field_unit_language_learning_format';
$handler->display->display_options['filters']['field_unit_language_learning_format']['table'] = 'field_data_field_unit_language_learning';
$handler->display->display_options['filters']['field_unit_language_learning_format']['field'] = 'field_unit_language_learning_format';
$handler->display->display_options['filters']['field_unit_language_learning_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_unit_language_learning_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_unit_language_learning_format']['group'] = 1;
/* Filter criterion: Content: Location Description (field_coverage_description:format) */
$handler->display->display_options['filters']['field_coverage_description_format']['id'] = 'field_coverage_description_format';
$handler->display->display_options['filters']['field_coverage_description_format']['table'] = 'field_data_field_coverage_description';
$handler->display->display_options['filters']['field_coverage_description_format']['field'] = 'field_coverage_description_format';
$handler->display->display_options['filters']['field_coverage_description_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_coverage_description_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_coverage_description_format']['group'] = 1;
/* Filter criterion: Content: Nature of Science­ (field_unit_nature_of_science:format) */
$handler->display->display_options['filters']['field_unit_nature_of_science_format']['id'] = 'field_unit_nature_of_science_format';
$handler->display->display_options['filters']['field_unit_nature_of_science_format']['table'] = 'field_data_field_unit_nature_of_science';
$handler->display->display_options['filters']['field_unit_nature_of_science_format']['field'] = 'field_unit_nature_of_science_format';
$handler->display->display_options['filters']['field_unit_nature_of_science_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_unit_nature_of_science_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_unit_nature_of_science_format']['group'] = 1;
/* Filter criterion: Content: Original Date Description (field_date:format) */
$handler->display->display_options['filters']['field_date_format']['id'] = 'field_date_format';
$handler->display->display_options['filters']['field_date_format']['table'] = 'field_data_field_date';
$handler->display->display_options['filters']['field_date_format']['field'] = 'field_date_format';
$handler->display->display_options['filters']['field_date_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_date_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_date_format']['group'] = 1;
/* Filter criterion: Content: Overarching (field_unit_overarching:format) */
$handler->display->display_options['filters']['field_unit_overarching_format']['id'] = 'field_unit_overarching_format';
$handler->display->display_options['filters']['field_unit_overarching_format']['table'] = 'field_data_field_unit_overarching';
$handler->display->display_options['filters']['field_unit_overarching_format']['field'] = 'field_unit_overarching_format';
$handler->display->display_options['filters']['field_unit_overarching_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_unit_overarching_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_unit_overarching_format']['group'] = 1;
/* Filter criterion: Content: Resources (field_lesson_resources:format) */
$handler->display->display_options['filters']['field_lesson_resources_format']['id'] = 'field_lesson_resources_format';
$handler->display->display_options['filters']['field_lesson_resources_format']['table'] = 'field_data_field_lesson_resources';
$handler->display->display_options['filters']['field_lesson_resources_format']['field'] = 'field_lesson_resources_format';
$handler->display->display_options['filters']['field_lesson_resources_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_lesson_resources_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_lesson_resources_format']['group'] = 1;
/* Filter criterion: Content: Summary (field_collection_summary:format) */
$handler->display->display_options['filters']['field_collection_summary_format']['id'] = 'field_collection_summary_format';
$handler->display->display_options['filters']['field_collection_summary_format']['table'] = 'field_data_field_collection_summary';
$handler->display->display_options['filters']['field_collection_summary_format']['field'] = 'field_collection_summary_format';
$handler->display->display_options['filters']['field_collection_summary_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_collection_summary_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_collection_summary_format']['group'] = 1;
/* Filter criterion: Content: Summary (field_summary:format) */
$handler->display->display_options['filters']['field_summary_format']['id'] = 'field_summary_format';
$handler->display->display_options['filters']['field_summary_format']['table'] = 'field_data_field_summary';
$handler->display->display_options['filters']['field_summary_format']['field'] = 'field_summary_format';
$handler->display->display_options['filters']['field_summary_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_summary_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_summary_format']['group'] = 1;
/* Filter criterion: Content: Technical (field_unit_technical:format) */
$handler->display->display_options['filters']['field_unit_technical_format']['id'] = 'field_unit_technical_format';
$handler->display->display_options['filters']['field_unit_technical_format']['table'] = 'field_data_field_unit_technical';
$handler->display->display_options['filters']['field_unit_technical_format']['field'] = 'field_unit_technical_format';
$handler->display->display_options['filters']['field_unit_technical_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_unit_technical_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_unit_technical_format']['group'] = 1;
/* Filter criterion: Content: Technology Integration (field_lesson_tech_integration:format) */
$handler->display->display_options['filters']['field_lesson_tech_integration_format']['id'] = 'field_lesson_tech_integration_format';
$handler->display->display_options['filters']['field_lesson_tech_integration_format']['table'] = 'field_data_field_lesson_tech_integration';
$handler->display->display_options['filters']['field_lesson_tech_integration_format']['field'] = 'field_lesson_tech_integration_format';
$handler->display->display_options['filters']['field_lesson_tech_integration_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_lesson_tech_integration_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_lesson_tech_integration_format']['group'] = 1;
/* Filter criterion: Content: Test Assets (field_test_assets:format) */
$handler->display->display_options['filters']['field_test_assets_format']['id'] = 'field_test_assets_format';
$handler->display->display_options['filters']['field_test_assets_format']['table'] = 'field_data_field_test_assets';
$handler->display->display_options['filters']['field_test_assets_format']['field'] = 'field_test_assets_format';
$handler->display->display_options['filters']['field_test_assets_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_test_assets_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_test_assets_format']['group'] = 1;
/* Filter criterion: Content: Traditional Knowledge (field_tk_body:format) */
$handler->display->display_options['filters']['field_tk_body_format']['id'] = 'field_tk_body_format';
$handler->display->display_options['filters']['field_tk_body_format']['table'] = 'field_data_field_tk_body';
$handler->display->display_options['filters']['field_tk_body_format']['field'] = 'field_tk_body_format';
$handler->display->display_options['filters']['field_tk_body_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_tk_body_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_tk_body_format']['group'] = 1;
/* Filter criterion: Content: Transcription (field_transcription:format) */
$handler->display->display_options['filters']['field_transcription_format']['id'] = 'field_transcription_format';
$handler->display->display_options['filters']['field_transcription_format']['table'] = 'field_data_field_transcription';
$handler->display->display_options['filters']['field_transcription_format']['field'] = 'field_transcription_format';
$handler->display->display_options['filters']['field_transcription_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_transcription_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_transcription_format']['group'] = 1;
/* Filter criterion: Field: Rights (field_rights:format) */
$handler->display->display_options['filters']['field_rights_format']['id'] = 'field_rights_format';
$handler->display->display_options['filters']['field_rights_format']['table'] = 'field_data_field_rights';
$handler->display->display_options['filters']['field_rights_format']['field'] = 'field_rights_format';
$handler->display->display_options['filters']['field_rights_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_rights_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_rights_format']['group'] = 1;
/* Filter criterion: Field: Source (field_source:format) */
$handler->display->display_options['filters']['field_source_format']['id'] = 'field_source_format';
$handler->display->display_options['filters']['field_source_format']['table'] = 'field_data_field_source';
$handler->display->display_options['filters']['field_source_format']['field'] = 'field_source_format';
$handler->display->display_options['filters']['field_source_format']['operator'] = 'regular_expression';
$handler->display->display_options['filters']['field_source_format']['value'] = '^(markdown|ds_code)$';
$handler->display->display_options['filters']['field_source_format']['group'] = 1;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/reports/migration/summary/migration-nodes-with-unsupported-text-formats';
$translatables['migration_nodes_with_unsupported_text_formats'] = array(
  t('Master'),
  t('Migration: Nodes with Unsupported Text Formats'),
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
  t('Back to Migration Summary Link'),
  t('<a href="/admin/reports/migration/summary">Back to Migration Summary</a>'),
  t('Content'),
  t('- Choose an operation -'),
  t('Title'),
  t('Type'),
  t('Page'),
);
