<?php

/**
 * @file
 * ma_collaboration_tools.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_collaboration_tools_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'documents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Documents';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no documents in this library yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Content author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_document_doc_lib_section_target_id']['id'] = 'field_document_doc_lib_section_target_id';
  $handler->display->display_options['relationships']['field_document_doc_lib_section_target_id']['table'] = 'field_data_field_document_doc_lib_section';
  $handler->display->display_options['relationships']['field_document_doc_lib_section_target_id']['field'] = 'field_document_doc_lib_section_target_id';
  $handler->display->display_options['relationships']['field_document_doc_lib_section_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save Order';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'documents:mini';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_document_doc_lib_section_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'document_page' => 'document_page',
  );

  /* Display: Full */
  $handler = $view->new_display('panel_pane', 'Full', 'full');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media']['id'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['label'] = '';
  $handler->display->display_options['fields']['field_oa_media']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_oa_media']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_oa_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_oa_media']['settings'] = array(
    'file_view_mode' => 'preview',
  );
  $handler->display->display_options['fields']['field_oa_media']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_oa_media']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'exif';
  $handler->display->display_options['fields']['created']['oa_date'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'By [name] on [created]';
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media_1']['id'] = 'field_oa_media_1';
  $handler->display->display_options['fields']['field_oa_media_1']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media_1']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media_1']['label'] = '';
  $handler->display->display_options['fields']['field_oa_media_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media_1']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'more...';
  $handler->display->display_options['fields']['body']['alter']['more_link_path'] = 'node/[nid]';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:alphabetical_order_definition.cer',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: mini */
  $handler = $view->new_display('panel_pane', 'mini', 'mini');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:alphabetical_order_definition.cer',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $translatables['documents'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('There are no documents in this library yet.'),
    t('author'),
    t('Content entity referenced from field_document_doc_lib_section'),
    t('Content'),
    t('All'),
    t('Full'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Nid'),
    t('By [name] on [created]'),
    t('more...'),
    t('View panes'),
    t('mini'),
  );
  $export['documents'] = $view;

  $view = new view();
  $view->name = 'event_list';
  $view->description = '';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium Event List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Open Atrium iCal Calendar';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['id'] = 'field_event_calendar_section_target_id';
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['table'] = 'field_data_field_event_calendar_section';
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['field'] = 'field_event_calendar_section_target_id';
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['required'] = TRUE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date']['id'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['type'] = 'events_date_formatter';
  $handler->display->display_options['fields']['field_oa_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_oa_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_oa_address']['id'] = 'field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['table'] = 'field_data_field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['field'] = 'field_oa_address';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_1']['id'] = 'field_oa_date_1';
  $handler->display->display_options['fields']['field_oa_date_1']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['label'] = 'Event Time';
  $handler->display->display_options['fields']['field_oa_date_1']['settings'] = array(
    'format_type' => 'panopoly_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_oa_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_1']['delta_offset'] = '0';
  /* Sort criterion: Content: Event Date -  start date (field_oa_date) */
  $handler->display->display_options['sorts']['field_oa_date_value']['id'] = 'field_oa_date_value';
  $handler->display->display_options['sorts']['field_oa_date_value']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['sorts']['field_oa_date_value']['field'] = 'field_oa_date_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_event_calendar_section_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Event Date - end date (field_oa_date:value2) */
  $handler->display->display_options['filters']['field_oa_date_value2']['id'] = 'field_oa_date_value2';
  $handler->display->display_options['filters']['field_oa_date_value2']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['filters']['field_oa_date_value2']['field'] = 'field_oa_date_value2';
  $handler->display->display_options['filters']['field_oa_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_oa_date_value2']['default_date'] = 'today';

  /* Display: iCal Feed */
  $handler = $view->new_display('feed', 'iCal Feed', 'events_ical');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['row_plugin'] = 'date_ical';
  $handler->display->display_options['row_options']['date_field'] = 'field_data_field_oa_date.field_oa_date_value';
  $handler->display->display_options['row_options']['location_field'] = 'none';
  $handler->display->display_options['path'] = 'feeds/ical/%/%';
  $handler->display->display_options['displays'] = array(
    'oa_calendar_month' => 'oa_calendar_month',
    'default' => 0,
    'panel_pane_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Upcoming Events pane */
  $handler = $view->new_display('panel_pane', 'Upcoming Events pane', 'upcoming_events_pane');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date']['id'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['type'] = 'events_date_formatter';
  $handler->display->display_options['fields']['field_oa_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_oa_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['delta_offset'] = '0';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_1']['id'] = 'field_oa_date_1';
  $handler->display->display_options['fields']['field_oa_date_1']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_1']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'g:ia',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_oa_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_1']['delta_offset'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:alphabetical_order_definition.cer',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $translatables['event_list'] = array(
    t('Master'),
    t('Open Atrium iCal Calendar'),
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
    t('Load more'),
    t('Content entity referenced from field_event_calendar_section'),
    t('Event Date'),
    t('Title'),
    t('Body'),
    t('Location'),
    t('Event Time'),
    t('All'),
    t('iCal Feed'),
    t('Upcoming Events pane'),
    t('View panes'),
  );
  $export['event_list'] = $view;

  $view = new view();
  $view->name = 'mukurtu_collab_subscriptions';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Mukurtu Collab Subscriptions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_event_calendar_section' => 'field_event_calendar_section',
    'nothing' => 'nothing',
    'changed' => 'changed',
    'php' => 'php',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
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
    'field_event_calendar_section' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php
print ma_collaboration_tools_show_default_notification_frequency_form($view);
?>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Not following any items.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Parent';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php ma_collaboration_tools_show_parent($data->nid); ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'exif';
  $handler->display->display_options['fields']['changed']['oa_date'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Reason Following';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print ma_collaboration_tools_show_following_reasons($view, $data);
?>

';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Unfollow';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print ma_collaboration_tools_show_unfollow_button_in_view($view, $data) 
?>
';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Notification Frequency';
  $handler->display->display_options['fields']['php_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
print ma_collaboration_tools_generate_notication_frequency_form($view, $data);
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $translatables['mukurtu_collab_subscriptions'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Not following any items.'),
    t('Title'),
    t('Type'),
    t('Parent'),
    t('Updated date'),
    t('Reason Following'),
    t('Unfollow'),
    t('Notification Frequency'),
  );
  $export['mukurtu_collab_subscriptions'] = $view;

  $view = new view();
  $view->name = 'oa_fullcalendar';
  $view->description = '';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium Calendar';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['left'] = 'month agendaWeek agendaDay';
  $handler->display->display_options['style_options']['right'] = 'today prev,next';
  $handler->display->display_options['style_options']['advanced'] = TRUE;
  $handler->display->display_options['style_options']['timeformatMonth'] = 'h(:mm)t';
  $handler->display->display_options['style_options']['theme'] = FALSE;
  $handler->display->display_options['style_options']['fullcalendar_create']['select'] = TRUE;
  $handler->display->display_options['style_options']['fullcalendar_create']['method'] = 'link';
  $handler->display->display_options['style_options']['fullcalendar_create']['node_type'] = 'event';
  $handler->display->display_options['style_options']['fullcalendar_create']['date_field'] = array(
    'field_oa_date' => 'field_oa_date',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['id'] = 'field_event_calendar_section_target_id';
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['table'] = 'field_data_field_event_calendar_section';
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['field'] = 'field_event_calendar_section_target_id';
  $handler->display->display_options['relationships']['field_event_calendar_section_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br><em>[title]</em>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date']['id'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_oa_address']['id'] = 'field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['table'] = 'field_data_field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['field'] = 'field_oa_address';
  /* Field: Content: Calendar */
  $handler->display->display_options['fields']['field_event_calendar_section']['id'] = 'field_event_calendar_section';
  $handler->display->display_options['fields']['field_event_calendar_section']['table'] = 'field_data_field_event_calendar_section';
  $handler->display->display_options['fields']['field_event_calendar_section']['field'] = 'field_event_calendar_section';
  $handler->display->display_options['fields']['field_event_calendar_section']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_event_calendar_section_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'event' => 'event',
  );

  /* Display: iCal */
  $handler = $view->new_display('feed', 'iCal', 'oa_calendar_ical');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = '';
  $handler->display->display_options['style_options']['disable_webcal'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'date_ical_fields';
  $handler->display->display_options['row_options']['date_field'] = 'field_oa_date';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['location_field'] = 'field_oa_address';
  $handler->display->display_options['row_options']['additional_settings'] = array(
    'skip_blank_dates' => 1,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br><em>[title]</em>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date']['id'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_oa_address']['id'] = 'field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['table'] = 'field_data_field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['field'] = 'field_oa_address';
  /* Field: Global: Base url */
  $handler->display->display_options['fields']['base_url']['id'] = 'base_url';
  $handler->display->display_options['fields']['base_url']['table'] = 'views';
  $handler->display->display_options['fields']['base_url']['field'] = 'base_url';
  $handler->display->display_options['fields']['base_url']['show_link'] = 0;
  $handler->display->display_options['fields']['base_url']['show_link_options'] = array(
    'link_path' => '',
    'link_text' => '',
    'link_class' => '',
    'link_title' => '',
    'link_rel' => '',
    'link_fragment' => '',
    'link_query' => '',
    'link_target' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path_1']['id'] = 'path_1';
  $handler->display->display_options['fields']['path_1']['table'] = 'node';
  $handler->display->display_options['fields']['path_1']['field'] = 'path';
  $handler->display->display_options['fields']['path_1']['label'] = 'event path';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_event_calendar_section_target_id';
  $handler->display->display_options['fields']['path']['label'] = 'calendar path';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]
Event link: [base_url][path_1]
Calendar link: [base_url][path]

';
  $handler->display->display_options['path'] = 'calendar/%/export.ics';
  $handler->display->display_options['displays'] = array(
    'calendar_pane' => 'calendar_pane',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Calendar pane */
  $handler = $view->new_display('panel_pane', 'Calendar pane', 'calendar_pane');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:alphabetical_order_definition.cer',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $translatables['oa_fullcalendar'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_event_calendar_section'),
    t('<br><em>[title]</em>'),
    t('Location'),
    t('Calendar'),
    t('Body'),
    t('All'),
    t('iCal'),
    t('%1'),
    t('Base url'),
    t('event path'),
    t('calendar path'),
    t('[body]
Event link: [base_url][path_1]
Calendar link: [base_url][path]

'),
    t('Calendar pane'),
    t('View panes'),
  );
  $export['oa_fullcalendar'] = $view;

  return $export;
}
