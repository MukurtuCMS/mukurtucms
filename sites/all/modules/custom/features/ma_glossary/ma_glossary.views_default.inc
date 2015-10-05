<?php
/**
 * @file
 * ma_glossary.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_glossary_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mukurtu_glossary';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mukurtu Glossary';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '36';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_translation' => 'field_translation',
    'field_definition' => 'field_definition',
    'field_sample_sentence' => 'field_sample_sentence',
    'field_media_asset' => 'field_media_asset',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_translation' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_definition' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_sample_sentence' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_media_asset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_glossary_terms_node']['id'] = 'reverse_field_glossary_terms_node';
  $handler->display->display_options['relationships']['reverse_field_glossary_terms_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_glossary_terms_node']['field'] = 'reverse_field_glossary_terms_node';
  $handler->display->display_options['relationships']['reverse_field_glossary_terms_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Term';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Translation */
  $handler->display->display_options['fields']['field_translation']['id'] = 'field_translation';
  $handler->display->display_options['fields']['field_translation']['table'] = 'field_data_field_translation';
  $handler->display->display_options['fields']['field_translation']['field'] = 'field_translation';
  /* Field: Content: Definition */
  $handler->display->display_options['fields']['field_definition']['id'] = 'field_definition';
  $handler->display->display_options['fields']['field_definition']['table'] = 'field_data_field_definition';
  $handler->display->display_options['fields']['field_definition']['field'] = 'field_definition';
  /* Field: Content: Sample Sentences */
  $handler->display->display_options['fields']['field_sample_sentence']['id'] = 'field_sample_sentence';
  $handler->display->display_options['fields']['field_sample_sentence']['table'] = 'field_data_field_sample_sentence';
  $handler->display->display_options['fields']['field_sample_sentence']['field'] = 'field_sample_sentence';
  $handler->display->display_options['fields']['field_sample_sentence']['type'] = 'textformatter_list';
  $handler->display->display_options['fields']['field_sample_sentence']['settings'] = array(
    'textformatter_type' => 'ul',
    'textformatter_comma_and' => 0,
    'textformatter_comma_full_stop' => 0,
    'textformatter_comma_override' => 0,
    'textformatter_separator_custom' => '',
    'textformatter_separator_custom_tag' => 'span',
    'textformatter_separator_custom_class' => 'textformatter-separator',
    'textformatter_comma_tag' => 'div',
    'textformatter_class' => 'textformatter-list',
  );
  $handler->display->display_options['fields']['field_sample_sentence']['delta_offset'] = '0';
  /* Field: Content: Media Assets */
  $handler->display->display_options['fields']['field_media_asset']['id'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['table'] = 'field_data_field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['field'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['label'] = 'Media';
  $handler->display->display_options['fields']['field_media_asset']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_asset']['type'] = 'mukurtu_glossary_table';
  $handler->display->display_options['fields']['field_media_asset']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_media_asset']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_asset']['multi_type'] = 'ul';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Translation (field_translation) */
  $handler->display->display_options['sorts']['field_translation_value']['id'] = 'field_translation_value';
  $handler->display->display_options['sorts']['field_translation_value']['table'] = 'field_data_field_translation';
  $handler->display->display_options['sorts']['field_translation_value']['field'] = 'field_translation_value';
  $handler->display->display_options['sorts']['field_translation_value']['expose']['label'] = 'Translation (field_translation)';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_glossary_terms_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = 'a';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary_options']['separator'] = '|';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
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
    'glossary_term' => 'glossary_term',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'term';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Translation (field_translation) */
  $handler->display->display_options['filters']['field_translation_value']['id'] = 'field_translation_value';
  $handler->display->display_options['filters']['field_translation_value']['table'] = 'field_data_field_translation';
  $handler->display->display_options['filters']['field_translation_value']['field'] = 'field_translation_value';
  $handler->display->display_options['filters']['field_translation_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_translation_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_translation_value']['expose']['operator_id'] = 'field_translation_value_op';
  $handler->display->display_options['filters']['field_translation_value']['expose']['label'] = 'Translation';
  $handler->display->display_options['filters']['field_translation_value']['expose']['operator'] = 'field_translation_value_op';
  $handler->display->display_options['filters']['field_translation_value']['expose']['identifier'] = 'translation';
  $handler->display->display_options['filters']['field_translation_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_glossary_terms_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_mukurtu_glossaries');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_glossary_terms_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['path'] = 'glossaries';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_mukurtu_glossary');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_glossary_terms_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary_options']['separator'] = '|';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['validate']['fail'] = 'summary';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['displays'] = array(
    'page_mukurtu_glossaries' => 'page_mukurtu_glossaries',
    'default' => 0,
    'block' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $translatables['mukurtu_glossary'] = array(
    t('Master'),
    t('more'),
    t('Search'),
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
    t('Content referencing Content from field_glossary_terms'),
    t('Term'),
    t('Translation'),
    t('Definition'),
    t('Sample Sentences'),
    t('Media'),
    t('Title'),
    t('Translation (field_translation)'),
    t('All'),
    t('Block'),
    t('Page'),
    t('Attachment'),
  );
  $export['mukurtu_glossary'] = $view;

  return $export;
}
