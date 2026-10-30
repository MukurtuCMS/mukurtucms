<?php
$view = new view();
$view->name = 'migration_scald_atoms_with_missing_cultural_protocols';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'scald_atoms';
$view->human_name = 'Migration: Scald Atoms with missing cultural protocols';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Migration: Scald Atoms with missing cultural protocols';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'edit own atom';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'sid' => 'sid',
  'title' => 'title',
  'type' => 'type',
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
/* Field: Bulk operations: Atom */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_scald_atom';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_this_page'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::ma_scald_duplicate_content_protocol_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'skip_permission_check' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::ma_culturalprotocol_set_atom_protocol_action' => array(
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
/* Field: Atom: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'scald_atoms';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '/atom/[sid]';
/* Field: Atom: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'scald_atoms';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Atoms: Protocol */
$handler->display->display_options['fields']['field_scald_protocol']['id'] = 'field_scald_protocol';
$handler->display->display_options['fields']['field_scald_protocol']['table'] = 'field_data_field_scald_protocol';
$handler->display->display_options['fields']['field_scald_protocol']['field'] = 'field_scald_protocol';
$handler->display->display_options['fields']['field_scald_protocol']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_scald_protocol']['settings'] = array(
  'bypass_access' => 0,
  'link' => 0,
);
$handler->display->display_options['fields']['field_scald_protocol']['delta_offset'] = '0';
/* Filter criterion: Atoms: Protocol (field_scald_protocol) */
$handler->display->display_options['filters']['field_scald_protocol_target_id']['id'] = 'field_scald_protocol_target_id';
$handler->display->display_options['filters']['field_scald_protocol_target_id']['table'] = 'field_data_field_scald_protocol';
$handler->display->display_options['filters']['field_scald_protocol_target_id']['field'] = 'field_scald_protocol_target_id';
$handler->display->display_options['filters']['field_scald_protocol_target_id']['operator'] = 'empty';
/* Filter criterion: Atom: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'scald_atoms';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/reports/migration/summary/scald-atoms-with-missing-cultural-protocols';
$translatables['migration_scald_atoms_with_missing_cultural_protocols'] = array(
  t('Master'),
  t('Migration: Scald Atoms with missing cultural protocols'),
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
  t('Atom'),
  t('- Choose an operation -'),
  t('Scald ID'),
  t('Title'),
  t('Type'),
  t('Protocol'),
  t('Page'),
);
