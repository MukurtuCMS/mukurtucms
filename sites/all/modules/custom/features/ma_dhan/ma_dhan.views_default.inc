<?php

/**
 * @file
 * ma_dhan.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_dhan_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dhan';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DHAN Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = 'return ma_dhan_dhan_report_access();';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_notification_date_gene' => 'field_notification_date_gene',
    'field_notification_author' => 'field_notification_author',
    'field_notification_action' => 'field_notification_action',
    'field_notification_subject' => 'field_notification_subject',
    'field_notification_body' => 'field_notification_body',
  );
  $handler->display->display_options['style_options']['default'] = 'field_notification_date_gene';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_notification_date_gene' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_notification_author' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_notification_action' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_notification_subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_notification_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php print ma_dhan_show_default_dhan_frequency_form($view); ?>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Email(s) (field_notification_email) */
  $handler->display->display_options['relationships']['field_notification_email_value']['id'] = 'field_notification_email_value';
  $handler->display->display_options['relationships']['field_notification_email_value']['table'] = 'field_data_field_notification_email';
  $handler->display->display_options['relationships']['field_notification_email_value']['field'] = 'field_notification_email_value';
  $handler->display->display_options['relationships']['field_notification_email_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_notification_email_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_following_content_target_id']['id'] = 'field_following_content_target_id';
  $handler->display->display_options['relationships']['field_following_content_target_id']['table'] = 'field_data_field_following_content';
  $handler->display->display_options['relationships']['field_following_content_target_id']['field'] = 'field_following_content_target_id';
  $handler->display->display_options['relationships']['field_following_content_target_id']['label'] = 'DH Node';
  $handler->display->display_options['relationships']['field_following_content_target_id']['required'] = TRUE;
  /* Field: Field collection item: Date Generated */
  $handler->display->display_options['fields']['field_notification_date_gene']['id'] = 'field_notification_date_gene';
  $handler->display->display_options['fields']['field_notification_date_gene']['table'] = 'field_data_field_notification_date_gene';
  $handler->display->display_options['fields']['field_notification_date_gene']['field'] = 'field_notification_date_gene';
  $handler->display->display_options['fields']['field_notification_date_gene']['relationship'] = 'field_notification_email_value';
  $handler->display->display_options['fields']['field_notification_date_gene']['label'] = 'Date';
  $handler->display->display_options['fields']['field_notification_date_gene']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_following_content_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Digital Heritage Item';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Author (of node insert/update or comment) */
  $handler->display->display_options['fields']['field_notification_author']['id'] = 'field_notification_author';
  $handler->display->display_options['fields']['field_notification_author']['table'] = 'field_data_field_notification_author';
  $handler->display->display_options['fields']['field_notification_author']['field'] = 'field_notification_author';
  $handler->display->display_options['fields']['field_notification_author']['relationship'] = 'field_notification_email_value';
  $handler->display->display_options['fields']['field_notification_author']['label'] = 'User';
  $handler->display->display_options['fields']['field_notification_author']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  /* Field: Field collection item: Action */
  $handler->display->display_options['fields']['field_notification_action']['id'] = 'field_notification_action';
  $handler->display->display_options['fields']['field_notification_action']['table'] = 'field_data_field_notification_action';
  $handler->display->display_options['fields']['field_notification_action']['field'] = 'field_notification_action';
  $handler->display->display_options['fields']['field_notification_action']['relationship'] = 'field_notification_email_value';
  /* Field: Field collection item: Subject */
  $handler->display->display_options['fields']['field_notification_subject']['id'] = 'field_notification_subject';
  $handler->display->display_options['fields']['field_notification_subject']['table'] = 'field_data_field_notification_subject';
  $handler->display->display_options['fields']['field_notification_subject']['field'] = 'field_notification_subject';
  $handler->display->display_options['fields']['field_notification_subject']['relationship'] = 'field_notification_email_value';
  $handler->display->display_options['fields']['field_notification_subject']['label'] = 'Email Subject';
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_notification_body']['id'] = 'field_notification_body';
  $handler->display->display_options['fields']['field_notification_body']['table'] = 'field_data_field_notification_body';
  $handler->display->display_options['fields']['field_notification_body']['field'] = 'field_notification_body';
  $handler->display->display_options['fields']['field_notification_body']['relationship'] = 'field_notification_email_value';
  $handler->display->display_options['fields']['field_notification_body']['label'] = 'Email Body';
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
    'dhan' => 'dhan',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field collection item: Date Generated (field_notification_date_gene) */
  $handler->display->display_options['filters']['field_notification_date_gene_value']['id'] = 'field_notification_date_gene_value';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['table'] = 'field_data_field_notification_date_gene';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['field'] = 'field_notification_date_gene_value';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['relationship'] = 'field_notification_email_value';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['group'] = 1;
  $handler->display->display_options['filters']['field_notification_date_gene_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_notification_date_gene_value']['expose']['operator_id'] = 'field_notification_date_gene_value_op';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['expose']['operator'] = 'field_notification_date_gene_value_op';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['expose']['identifier'] = 'date';
  $handler->display->display_options['filters']['field_notification_date_gene_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_notification_date_gene_value']['form_type'] = 'date_popup';
  /* Filter criterion: Field collection item: Author (of node insert/update or comment) (field_notification_author) */
  $handler->display->display_options['filters']['field_notification_author_target_id']['id'] = 'field_notification_author_target_id';
  $handler->display->display_options['filters']['field_notification_author_target_id']['table'] = 'field_data_field_notification_author';
  $handler->display->display_options['filters']['field_notification_author_target_id']['field'] = 'field_notification_author_target_id';
  $handler->display->display_options['filters']['field_notification_author_target_id']['relationship'] = 'field_notification_email_value';
  $handler->display->display_options['filters']['field_notification_author_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_notification_author_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_notification_author_target_id']['expose']['operator_id'] = 'field_notification_author_target_id_op';
  $handler->display->display_options['filters']['field_notification_author_target_id']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['field_notification_author_target_id']['expose']['operator'] = 'field_notification_author_target_id_op';
  $handler->display->display_options['filters']['field_notification_author_target_id']['expose']['identifier'] = 'user';
  $handler->display->display_options['filters']['field_notification_author_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Field collection item: Action (field_notification_action) */
  $handler->display->display_options['filters']['field_notification_action_value']['id'] = 'field_notification_action_value';
  $handler->display->display_options['filters']['field_notification_action_value']['table'] = 'field_data_field_notification_action';
  $handler->display->display_options['filters']['field_notification_action_value']['field'] = 'field_notification_action_value';
  $handler->display->display_options['filters']['field_notification_action_value']['relationship'] = 'field_notification_email_value';
  $handler->display->display_options['filters']['field_notification_action_value']['group'] = 1;
  $handler->display->display_options['filters']['field_notification_action_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_notification_action_value']['expose']['operator_id'] = 'field_notification_action_value_op';
  $handler->display->display_options['filters']['field_notification_action_value']['expose']['label'] = 'Action';
  $handler->display->display_options['filters']['field_notification_action_value']['expose']['operator'] = 'field_notification_action_value_op';
  $handler->display->display_options['filters']['field_notification_action_value']['expose']['identifier'] = 'action';
  $handler->display->display_options['filters']['field_notification_action_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/digital-heritage-notifications';
  $handler->display->display_options['menu']['title'] = 'DH Notifications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'digital-heritage-notifications_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'user/%/digital-heritage-notifications-csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['dhan'] = array(
    t('Master'),
    t('<none>'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('There are no results.'),
    t('field collection item from field_notification_email'),
    t('DH Node'),
    t('Date'),
    t('Digital Heritage Item'),
    t('User'),
    t('Action'),
    t('Email Subject'),
    t('Email Body'),
    t('Page'),
    t('Data export'),
  );
  $export['dhan'] = $view;

  return $export;
}
