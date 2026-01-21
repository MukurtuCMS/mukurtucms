<?php

$view = new view();
$view->name = 'migration_dictionary_words_with_additional_media';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Migration: Dictionary Words with Additional Media';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Migration: Dictionary Words with Additional Media';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'field_additional_media' => 'field_additional_media',
  'field_dictionary_word_language' => 'field_dictionary_word_language',
);
$handler->display->display_options['style_options']['class'] = '';
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_additional_media' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_dictionary_word_language' => array(
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
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Additional Media */
$handler->display->display_options['fields']['field_additional_media']['id'] = 'field_additional_media';
$handler->display->display_options['fields']['field_additional_media']['table'] = 'field_data_field_additional_media';
$handler->display->display_options['fields']['field_additional_media']['field'] = 'field_additional_media';
$handler->display->display_options['fields']['field_additional_media']['exclude'] = TRUE;
/* Field: Content: Language */
$handler->display->display_options['fields']['field_dictionary_word_language']['id'] = 'field_dictionary_word_language';
$handler->display->display_options['fields']['field_dictionary_word_language']['table'] = 'field_data_field_dictionary_word_language';
$handler->display->display_options['fields']['field_dictionary_word_language']['field'] = 'field_dictionary_word_language';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published status */
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
  'dictionary_word' => 'dictionary_word',
);
/* Filter criterion: Content: Additional Media (field_additional_media) */
$handler->display->display_options['filters']['field_additional_media_value']['id'] = 'field_additional_media_value';
$handler->display->display_options['filters']['field_additional_media_value']['table'] = 'field_data_field_additional_media';
$handler->display->display_options['filters']['field_additional_media_value']['field'] = 'field_additional_media_value';
$handler->display->display_options['filters']['field_additional_media_value']['operator'] = 'not empty';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/reports/migration/migration-dictionary-words-with-additional-media';
$translatables['migration_dictionary_words_with_additional_media'] = array(
  t('Master'),
  t('Migration: Dictionary Words with Additional Media'),
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
  t('Title'),
  t('Additional Media'),
  t('Language'),
  t('Page'),
);
