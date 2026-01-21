<?php
/**
 * @file
 * Default views for the Scald module.
 */

/**
 * Implements hook_views_default_views().
 */
function scald_views_default_views() {
  $views = array();

  // Atoms listing view.
  $view = new view();
  $view->name = 'scald_atoms';
  $view->description = 'Atoms listing view provided by Scald to access atoms.';
  $view->tag = '';
  $view->base_table = 'scald_atoms';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Atoms Library';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer scald atoms';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sid' => 'sid',
    'type' => 'type',
    'provider' => 'provider',
    'base_id' => 'base_id',
    'title' => 'title',
    'name' => 'name',
    'representation' => 'representation',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sid' => array(
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
    'provider' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'base_id' => array(
      'sortable' => 1,
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'representation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'No atom found.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Relationship: Atom: Publisher */
  $handler->display->display_options['relationships']['publisher']['id'] = 'publisher';
  $handler->display->display_options['relationships']['publisher']['table'] = 'scald_atoms';
  $handler->display->display_options['relationships']['publisher']['field'] = 'publisher';
  $handler->display->display_options['relationships']['publisher']['label'] = 'Publisher';
  /* Field: Atom: Scald ID */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sid']['separator'] = '';
  /* Field: Atom: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Atom: Provider */
  $handler->display->display_options['fields']['provider']['id'] = 'provider';
  $handler->display->display_options['fields']['provider']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['provider']['field'] = 'provider';
  $handler->display->display_options['fields']['provider']['element_label_colon'] = FALSE;
  /* Field: Atom: Base ID */
  $handler->display->display_options['fields']['base_id']['id'] = 'base_id';
  $handler->display->display_options['fields']['base_id']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['base_id']['field'] = 'base_id';
  $handler->display->display_options['fields']['base_id']['element_label_colon'] = FALSE;
  /* Field: Atom: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'publisher';
  $handler->display->display_options['fields']['name']['label'] = 'Publisher';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Atom: Representation */
  $handler->display->display_options['fields']['representation']['id'] = 'representation';
  $handler->display->display_options['fields']['representation']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['representation']['field'] = 'representation';
  $handler->display->display_options['fields']['representation']['element_label_colon'] = FALSE;
  /* Sort criterion: Atom: Scald ID */
  $handler->display->display_options['sorts']['sid']['id'] = 'sid';
  $handler->display->display_options['sorts']['sid']['table'] = 'scald_atoms';
  $handler->display->display_options['sorts']['sid']['field'] = 'sid';
  $handler->display->display_options['sorts']['sid']['order'] = 'DESC';
  /* Filter criterion: Atom: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'scald_atoms';
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
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'publisher';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Publishers';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Atoms: Authors (scald_authors) */
  $handler->display->display_options['filters']['scald_authors_tid']['id'] = 'scald_authors_tid';
  $handler->display->display_options['filters']['scald_authors_tid']['table'] = 'field_data_scald_authors';
  $handler->display->display_options['filters']['scald_authors_tid']['field'] = 'scald_authors_tid';
  $handler->display->display_options['filters']['scald_authors_tid']['value'] = '';
  $handler->display->display_options['filters']['scald_authors_tid']['group'] = 1;
  $handler->display->display_options['filters']['scald_authors_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['scald_authors_tid']['expose']['operator_id'] = 'scald_authors_tid_op';
  $handler->display->display_options['filters']['scald_authors_tid']['expose']['label'] = 'Authors';
  $handler->display->display_options['filters']['scald_authors_tid']['expose']['operator'] = 'scald_authors_tid_op';
  $handler->display->display_options['filters']['scald_authors_tid']['expose']['identifier'] = 'scald_authors_tid';
  $handler->display->display_options['filters']['scald_authors_tid']['vocabulary'] = 'scald_authors';
  /* Filter criterion: Atom: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'scald_atoms';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Types';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Atom: Provider */
  $handler->display->display_options['filters']['provider']['id'] = 'provider';
  $handler->display->display_options['filters']['provider']['table'] = 'scald_atoms';
  $handler->display->display_options['filters']['provider']['field'] = 'provider';
  $handler->display->display_options['filters']['provider']['group'] = 1;
  $handler->display->display_options['filters']['provider']['exposed'] = TRUE;
  $handler->display->display_options['filters']['provider']['expose']['operator_id'] = 'provider_op';
  $handler->display->display_options['filters']['provider']['expose']['label'] = 'Providers';
  $handler->display->display_options['filters']['provider']['expose']['operator'] = 'provider_op';
  $handler->display->display_options['filters']['provider']['expose']['identifier'] = 'provider';
  $handler->display->display_options['filters']['provider']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['provider']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Atoms: Tags (scald_tags) */
  $handler->display->display_options['filters']['scald_tags_tid']['id'] = 'scald_tags_tid';
  $handler->display->display_options['filters']['scald_tags_tid']['table'] = 'field_data_scald_tags';
  $handler->display->display_options['filters']['scald_tags_tid']['field'] = 'scald_tags_tid';
  $handler->display->display_options['filters']['scald_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['scald_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['scald_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['scald_tags_tid']['expose']['operator_id'] = 'scald_tags_tid_op';
  $handler->display->display_options['filters']['scald_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['scald_tags_tid']['expose']['operator'] = 'scald_tags_tid_op';
  $handler->display->display_options['filters']['scald_tags_tid']['expose']['identifier'] = 'scald_tags_tid';
  $handler->display->display_options['filters']['scald_tags_tid']['vocabulary'] = 'scald_tags';
  /* Filter criterion: Atom: Actions */
  $handler->display->display_options['filters']['actions']['id'] = 'actions';
  $handler->display->display_options['filters']['actions']['table'] = 'scald_atoms';
  $handler->display->display_options['filters']['actions']['field'] = 'actions';
  $handler->display->display_options['filters']['actions']['operator'] = '&';
  $handler->display->display_options['filters']['actions']['value'] = array(
    'fetch' => 'fetch',
    'view' => 'view',
  );
  $handler->display->display_options['filters']['actions']['group'] = 1;
  $handler->display->display_options['filters']['actions']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li>' . l(t('Add atom'), 'atom/add') . '</li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['path'] = 'admin/content/atoms';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Atoms';
  $handler->display->display_options['menu']['weight'] = '-60';
  $translatables['scald_atoms'] = array(
    t('Master'),
    t('Atoms Library'),
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
    t('No atom found.'),
    t('Publisher'),
    t('Scald ID'),
    t('Type'),
    t('Provider'),
    t('Base ID'),
    t('Title'),
    t('Representation'),
    t('Publishers'),
    t('Authors'),
    t('Types'),
    t('Providers'),
    t('Tags'),
    t('Page'),
    t('Add atom'),
  );

  $views[$view->name] = $view;
  return $views;
}
