<?php

/**
 * @file
 * ma_scald.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_scald_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'export_scald_atoms';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'scald_atoms';
  $view->human_name = 'Export Scald Atoms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Export Media';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = '$admin = user_role_load_by_name(\'administrator\');
$mukurtuadmin = user_role_load_by_name(\'Mukurtu Administrator\');

if(user_has_role($admin->rid) || user_has_role($mukurtuadmin->rid)) {
     return TRUE;
}
return FALSE;';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sid' => 'sid',
    'scald_thumbnail' => 'scald_thumbnail',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'scald_tags' => 'scald_tags',
    'field_scald_protocol' => 'field_scald_protocol',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'sid' => array(
      'alter' => array(
        'make_link' => TRUE,
        'path' => '/atom/[sid]',
      ),
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'scald_thumbnail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'scald_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_scald_protocol' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Field: Bulk operations: Atom */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_scald_atom';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::mukurtu_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Atom: Scald ID */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['sid']['alter']['path'] = '/atom/[sid]';
  /* Field: Atoms: Thumbnail */
  $handler->display->display_options['fields']['scald_thumbnail']['id'] = 'scald_thumbnail';
  $handler->display->display_options['fields']['scald_thumbnail']['table'] = 'field_data_scald_thumbnail';
  $handler->display->display_options['fields']['scald_thumbnail']['field'] = 'scald_thumbnail';
  $handler->display->display_options['fields']['scald_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['scald_thumbnail']['settings'] = array(
    'image_style' => 'library',
    'image_link' => '',
  );
  /* Field: Atom: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Atom: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Atoms: Tags */
  $handler->display->display_options['fields']['scald_tags']['id'] = 'scald_tags';
  $handler->display->display_options['fields']['scald_tags']['table'] = 'field_data_scald_tags';
  $handler->display->display_options['fields']['scald_tags']['field'] = 'scald_tags';
  $handler->display->display_options['fields']['scald_tags']['delta_offset'] = '0';
  /* Field: Atoms: Protocol */
  $handler->display->display_options['fields']['field_scald_protocol']['id'] = 'field_scald_protocol';
  $handler->display->display_options['fields']['field_scald_protocol']['table'] = 'field_data_field_scald_protocol';
  $handler->display->display_options['fields']['field_scald_protocol']['field'] = 'field_scald_protocol';
  $handler->display->display_options['fields']['field_scald_protocol']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_scald_protocol']['delta_offset'] = '0';
  /* Field: Atom: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'scald_atoms';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'exif';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'exif';
  /* Filter criterion: Atom: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'scald_atoms';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Atom: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'scald_atoms';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Atoms: Protocol (field_scald_protocol) */
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['id'] = 'field_scald_protocol_target_id';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['table'] = 'field_data_field_scald_protocol';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['field'] = 'field_scald_protocol_target_id';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['expose']['operator_id'] = 'field_scald_protocol_target_id_op';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['expose']['label'] = 'Protocol';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['expose']['operator'] = 'field_scald_protocol_target_id_op';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['expose']['identifier'] = 'field_scald_protocol_target_id';
  $handler->display->display_options['filters']['field_scald_protocol_target_id']['expose']['remember_roles'] = array(
    2 => '2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'manage/scald-atoms';
  $translatables['export_scald_atoms'] = array(
    t('Master'),
    t('Export Media'),
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
    t('Atom'),
    t('- Choose an operation -'),
    t('Scald ID'),
    t('Thumbnail'),
    t('Title'),
    t('Type'),
    t('Tags'),
    t('Protocol'),
    t('Updated date'),
    t('Page'),
  );
  $export['export_scald_atoms'] = $view;

  return $export;
}
