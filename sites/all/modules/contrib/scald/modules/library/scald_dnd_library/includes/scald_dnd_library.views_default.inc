<?php
/**
 * @file
 * Provides default views for the Scald DnD Library module.
 */

/**
 * Implements hook_views_default_views().
 */
function scald_dnd_library_views_default_views() {
  $views = array();

  // Library view.
  $view = new view();
  $view->name = 'scald_library';
  $view->description = 'Library view provided by Scald to access atoms.';
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
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['style_plugin'] = 'table';
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
  /* Field: Atom: Representation */
  $handler->display->display_options['fields']['representation']['id'] = 'representation';
  $handler->display->display_options['fields']['representation']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['representation']['field'] = 'representation';
  $handler->display->display_options['fields']['representation']['label'] = '';
  /* Sort criterion: Atom: Scald ID */
  $handler->display->display_options['sorts']['sid']['id'] = 'sid';
  $handler->display->display_options['sorts']['sid']['table'] = 'scald_atoms';
  $handler->display->display_options['sorts']['sid']['field'] = 'sid';
  $handler->display->display_options['sorts']['sid']['order'] = 'DESC';
  $handler->display->display_options['sorts']['sid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['sid']['expose']['label'] = 'Scald ID';
  /* Sort criterion: Atom: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'scald_atoms';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Filter criterion: Atom: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'scald_atoms';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = '0';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'publisher';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = '0';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Publisher';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
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
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
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
  $handler->display->display_options['filters']['actions']['group'] = '0';
  $handler->display->display_options['filters']['actions']['expose']['operator'] = FALSE;

  /* Display: Scald Library */
  $handler = $view->new_display('dnd_library', 'Scald Library', 'dnd_library_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access scald dnd library';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'scald_library';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'scald/library_dnd';
  $translatables['scald_library'] = array(
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
    t('.'),
    t(','),
    t('Title'),
    t('Authors'),
    t('Type'),
    t('Tags'),
    t('Scald Library'),
  );

  $views[$view->name] = $view;
  return $views;
}
