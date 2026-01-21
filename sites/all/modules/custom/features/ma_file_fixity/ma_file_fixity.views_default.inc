<?php

/**
 * @file
 * ma_file_fixity.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_file_fixity_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fixity_checks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Fixity Checks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fixity Checks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create fixity_check content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 0,
      ),
    ),
    'field_fixity_schedule_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_fixity_latest_check_status_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_fixity_latest_check_time' => 'field_fixity_latest_check_time',
    'field_fixity_latest_check_status' => 'field_fixity_latest_check_status',
    'view_node' => 'view_node',
    'nothing' => 'nothing',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fixity_latest_check_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fixity_latest_check_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<a href=\'/node/add/fixity-check\'>Add a Fixity Check</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Latest check run time */
  $handler->display->display_options['fields']['field_fixity_latest_check_time']['id'] = 'field_fixity_latest_check_time';
  $handler->display->display_options['fields']['field_fixity_latest_check_time']['table'] = 'field_data_field_fixity_latest_check_time';
  $handler->display->display_options['fields']['field_fixity_latest_check_time']['field'] = 'field_fixity_latest_check_time';
  $handler->display->display_options['fields']['field_fixity_latest_check_time']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Latest check run result */
  $handler->display->display_options['fields']['field_fixity_latest_check_status']['id'] = 'field_fixity_latest_check_status';
  $handler->display->display_options['fields']['field_fixity_latest_check_status']['table'] = 'field_data_field_fixity_latest_check_status';
  $handler->display->display_options['fields']['field_fixity_latest_check_status']['field'] = 'field_fixity_latest_check_status';
  $handler->display->display_options['fields']['field_fixity_latest_check_status']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_fixity_latest_check_status']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_fixity_latest_check_status']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Details';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Run this check now.';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'run-fixity-check/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Next check run time */
  $handler->display->display_options['fields']['field_fixity_next_check_run_time']['id'] = 'field_fixity_next_check_run_time';
  $handler->display->display_options['fields']['field_fixity_next_check_run_time']['table'] = 'field_data_field_fixity_next_check_run_time';
  $handler->display->display_options['fields']['field_fixity_next_check_run_time']['field'] = 'field_fixity_next_check_run_time';
  $handler->display->display_options['fields']['field_fixity_next_check_run_time']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Fixity Check created';
  /* Sort criterion: Content: Latest check run time (field_fixity_latest_check_time) */
  $handler->display->display_options['sorts']['field_fixity_latest_check_time_value']['id'] = 'field_fixity_latest_check_time_value';
  $handler->display->display_options['sorts']['field_fixity_latest_check_time_value']['table'] = 'field_data_field_fixity_latest_check_time';
  $handler->display->display_options['sorts']['field_fixity_latest_check_time_value']['field'] = 'field_fixity_latest_check_time_value';
  $handler->display->display_options['sorts']['field_fixity_latest_check_time_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_fixity_latest_check_time_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_fixity_latest_check_time_value']['expose']['label'] = 'Latest check run time';
  /* Sort criterion: Content: Latest check run result (field_fixity_latest_check_status) */
  $handler->display->display_options['sorts']['field_fixity_latest_check_status_value']['id'] = 'field_fixity_latest_check_status_value';
  $handler->display->display_options['sorts']['field_fixity_latest_check_status_value']['table'] = 'field_data_field_fixity_latest_check_status';
  $handler->display->display_options['sorts']['field_fixity_latest_check_status_value']['field'] = 'field_fixity_latest_check_status_value';
  $handler->display->display_options['sorts']['field_fixity_latest_check_status_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_fixity_latest_check_status_value']['expose']['label'] = 'Latest check run result';
  /* Sort criterion: Content: Next check run time (field_fixity_next_check_run_time) */
  $handler->display->display_options['sorts']['field_fixity_next_check_run_time_value']['id'] = 'field_fixity_next_check_run_time_value';
  $handler->display->display_options['sorts']['field_fixity_next_check_run_time_value']['table'] = 'field_data_field_fixity_next_check_run_time';
  $handler->display->display_options['sorts']['field_fixity_next_check_run_time_value']['field'] = 'field_fixity_next_check_run_time_value';
  $handler->display->display_options['sorts']['field_fixity_next_check_run_time_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_fixity_next_check_run_time_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_fixity_next_check_run_time_value']['expose']['label'] = 'Next check run time';
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
    'fixity_check' => 'fixity_check',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Schedule (field_fixity_schedule) */
  $handler->display->display_options['filters']['field_fixity_schedule_value']['id'] = 'field_fixity_schedule_value';
  $handler->display->display_options['filters']['field_fixity_schedule_value']['table'] = 'field_data_field_fixity_schedule';
  $handler->display->display_options['filters']['field_fixity_schedule_value']['field'] = 'field_fixity_schedule_value';
  $handler->display->display_options['filters']['field_fixity_schedule_value']['group'] = 1;
  $handler->display->display_options['filters']['field_fixity_schedule_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fixity_schedule_value']['expose']['operator_id'] = 'field_fixity_schedule_value_op';
  $handler->display->display_options['filters']['field_fixity_schedule_value']['expose']['label'] = 'Schedule';
  $handler->display->display_options['filters']['field_fixity_schedule_value']['expose']['operator'] = 'field_fixity_schedule_value_op';
  $handler->display->display_options['filters']['field_fixity_schedule_value']['expose']['identifier'] = 'field_fixity_schedule_value';
  $handler->display->display_options['filters']['field_fixity_schedule_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Latest check run result (field_fixity_latest_check_status) */
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['id'] = 'field_fixity_latest_check_status_value';
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['table'] = 'field_data_field_fixity_latest_check_status';
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['field'] = 'field_fixity_latest_check_status_value';
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['expose']['operator_id'] = 'field_fixity_latest_check_status_value_op';
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['expose']['label'] = 'Latest check run result';
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['expose']['operator'] = 'field_fixity_latest_check_status_value_op';
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['expose']['identifier'] = 'field_fixity_latest_check_status_value';
  $handler->display->display_options['filters']['field_fixity_latest_check_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'fixity-checks';
  $translatables['fixity_checks'] = array(
    t('Master'),
    t('Fixity Checks'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Advanced options'),
    t('Sort options'),
    t('<a href=\'/node/add/fixity-check\'>Add a Fixity Check</a>'),
    t('Latest check run time'),
    t('Latest check run result'),
    t('Details'),
    t('Run this check now.'),
    t('Next check run time'),
    t('Edit'),
    t('Delete'),
    t('Fixity Check created'),
    t('Schedule'),
    t('Page'),
  );
  $export['fixity_checks'] = $view;

  $view = new view();
  $view->name = 'fixity_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'fixity_reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Relationship: Field collection item: Entity with the Check runs (field_fixity_report) */
  $handler->display->display_options['relationships']['field_fixity_report_node']['id'] = 'field_fixity_report_node';
  $handler->display->display_options['relationships']['field_fixity_report_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_fixity_report_node']['field'] = 'field_fixity_report_node';
  $handler->display->display_options['relationships']['field_fixity_report_node']['required'] = TRUE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Sort criterion: Field collection item: Time of check run (field_fixity_time_of_check) */
  $handler->display->display_options['sorts']['field_fixity_time_of_check_value']['id'] = 'field_fixity_time_of_check_value';
  $handler->display->display_options['sorts']['field_fixity_time_of_check_value']['table'] = 'field_data_field_fixity_time_of_check';
  $handler->display->display_options['sorts']['field_fixity_time_of_check_value']['field'] = 'field_fixity_time_of_check_value';
  $handler->display->display_options['sorts']['field_fixity_time_of_check_value']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_fixity_report_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['fixity_reports'] = array(
    t('Master'),
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
    t('field_fixity_report'),
    t('Field collection item ID'),
    t('.'),
    t(','),
    t('All'),
    t('Block'),
  );
  $export['fixity_reports'] = $view;

  return $export;
}
