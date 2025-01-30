<?php

$view = new view();
$view->name = 'migration_dailymotion_atoms';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'scald_atoms';
$view->human_name = 'Migration: Dailymotion Atoms';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Migration: Dailymotion Atoms';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'edit own atom';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'sid' => 'sid',
  'title' => 'title',
);
$handler->display->display_options['style_options']['class'] = '';
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'sid' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
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
/* Field: Atom: Scald ID */
$handler->display->display_options['fields']['sid']['id'] = 'sid';
$handler->display->display_options['fields']['sid']['table'] = 'scald_atoms';
$handler->display->display_options['fields']['sid']['field'] = 'sid';
$handler->display->display_options['fields']['sid']['exclude'] = TRUE;
$handler->display->display_options['fields']['sid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['sid']['alter']['path'] = '/atom/[sid]';
/* Field: Atom: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'scald_atoms';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '/atom/[sid]';
/* Filter criterion: Atom: Provider */
$handler->display->display_options['filters']['provider']['id'] = 'provider';
$handler->display->display_options['filters']['provider']['table'] = 'scald_atoms';
$handler->display->display_options['filters']['provider']['field'] = 'provider';
$handler->display->display_options['filters']['provider']['value'] = array(
  'scald_dailymotion' => 'scald_dailymotion',
);
/* Filter criterion: Atom: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'scald_atoms';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'video' => 'video',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/reports/migration/dailymotion-atoms';
$translatables['migration_dailymotion_atoms'] = array(
  t('Master'),
  t('Migration: Dailymotion Atoms'),
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
  t('Scald ID'),
  t('Title'),
  t('Page'),
);
