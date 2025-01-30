<?php
/**
 * @file
 * This file is used by views to install default views for
 * this module.
 */

/**
 * Implements hook_views_default_views().
 */
function entity_delete_log_views_default_views() {

  $view = new view();
  $view->name = 'entity_delete_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entity_delete_log';
  $view->human_name = 'Entity Delete Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Entity Delete Log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access site reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entity_id' => 'entity_id',
    'entity_type' => 'entity_type',
    'entity_bundle' => 'entity_bundle',
    'entity_title' => 'entity_title',
    'name_1' => 'name_1',
    'revisions' => 'revisions',
    'created' => 'created',
    'deleted' => 'deleted',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'entity_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_bundle' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'revisions' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'deleted' => array(
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
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'A listing of deleted Entities.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no records of entities being deleted. Visit the <a href="/admin/config/system/entity-delete-log">Entity Delete Log Settings</a> to select which entity types will be logged when deleted.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Delete Log: Acting User Account */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'entity_delete_log';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Delete Log: Author User Account */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'entity_delete_log';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  /* Field: Entity Delete Log: Entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'entity_delete_log';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['separator'] = '';
  /* Field: Entity Delete Log: Entity Title */
  $handler->display->display_options['fields']['entity_title']['id'] = 'entity_title';
  $handler->display->display_options['fields']['entity_title']['table'] = 'entity_delete_log';
  $handler->display->display_options['fields']['entity_title']['field'] = 'entity_title';
  /* Field: Entity Delete Log: Entity Type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'entity_delete_log';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  /* Field: Entity Delete Log: Entity Bundle */
  $handler->display->display_options['fields']['entity_bundle']['id'] = 'entity_bundle';
  $handler->display->display_options['fields']['entity_bundle']['table'] = 'entity_delete_log';
  $handler->display->display_options['fields']['entity_bundle']['field'] = 'entity_bundle';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'author';
  $handler->display->display_options['fields']['name_1']['label'] = 'Author';
  /* Field: Entity Delete Log: Revisions */
  $handler->display->display_options['fields']['revisions']['id'] = 'revisions';
  $handler->display->display_options['fields']['revisions']['table'] = 'entity_delete_log';
  $handler->display->display_options['fields']['revisions']['field'] = 'revisions';
  $handler->display->display_options['fields']['revisions']['separator'] = '';
  /* Field: Entity Delete Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entity_delete_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Field: Entity Delete Log: Deleted */
  $handler->display->display_options['fields']['deleted']['id'] = 'deleted';
  $handler->display->display_options['fields']['deleted']['table'] = 'entity_delete_log';
  $handler->display->display_options['fields']['deleted']['field'] = 'deleted';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Acting User';
  /* Sort criterion: Entity Delete Log: Deleted */
  $handler->display->display_options['sorts']['deleted']['id'] = 'deleted';
  $handler->display->display_options['sorts']['deleted']['table'] = 'entity_delete_log';
  $handler->display->display_options['sorts']['deleted']['field'] = 'deleted';
  $handler->display->display_options['sorts']['deleted']['order'] = 'DESC';
  /* Filter criterion: Entity Delete Log: Entity Type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'entity_delete_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['group'] = 1;
  $handler->display->display_options['filters']['entity_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_type']['expose']['operator_id'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['label'] = 'Entity Type';
  $handler->display->display_options['filters']['entity_type']['expose']['operator'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['identifier'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    27 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    31 => 0,
    19 => 0,
    33 => 0,
    35 => 0,
    21 => 0,
    22 => 0,
    26 => 0,
  );
  /* Filter criterion: Entity Delete Log: Entity Bundle */
  $handler->display->display_options['filters']['entity_bundle']['id'] = 'entity_bundle';
  $handler->display->display_options['filters']['entity_bundle']['table'] = 'entity_delete_log';
  $handler->display->display_options['filters']['entity_bundle']['field'] = 'entity_bundle';
  $handler->display->display_options['filters']['entity_bundle']['group'] = 1;
  $handler->display->display_options['filters']['entity_bundle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_bundle']['expose']['operator_id'] = 'entity_bundle_op';
  $handler->display->display_options['filters']['entity_bundle']['expose']['label'] = 'Entity Bundle';
  $handler->display->display_options['filters']['entity_bundle']['expose']['operator'] = 'entity_bundle_op';
  $handler->display->display_options['filters']['entity_bundle']['expose']['identifier'] = 'entity_bundle';
  $handler->display->display_options['filters']['entity_bundle']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    27 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    31 => 0,
    19 => 0,
    33 => 0,
    35 => 0,
    21 => 0,
    22 => 0,
    26 => 0,
  );
  $handler->display->display_options['filters']['entity_bundle']['group_info']['label'] = 'Entity Bundle';
  $handler->display->display_options['filters']['entity_bundle']['group_info']['identifier'] = 'entity_bundle';
  $handler->display->display_options['filters']['entity_bundle']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['entity_bundle']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/reports/entity-delete-log';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Entity Delete Log';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  return $views;
}

