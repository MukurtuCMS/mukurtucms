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
  $view->name = 'event_detail';
  $view->description = '';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium Event Detail';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_1']['id'] = 'field_oa_date_1';
  $handler->display->display_options['fields']['field_oa_date_1']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_1']['type'] = 'events_date_formatter';
  $handler->display->display_options['fields']['field_oa_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date_1']['delta_offset'] = '0';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date']['id'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_oa_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['type'] = 'events_upcoming_date';
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
  $handler->display->display_options['fields']['field_oa_address']['label'] = '';
  $handler->display->display_options['fields']['field_oa_address']['alter']['text'] = '[field_oa_address]
[field_event_link]';
  $handler->display->display_options['fields']['field_oa_address']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_2']['id'] = 'field_oa_date_2';
  $handler->display->display_options['fields']['field_oa_date_2']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_2']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_2']['type'] = 'events_addthis';
  $handler->display->display_options['fields']['field_oa_date_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date_2']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media']['id'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['label'] = '';
  $handler->display->display_options['fields']['field_oa_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_oa_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media']['type'] = 'oa_media_formatter';
  $handler->display->display_options['fields']['field_oa_media']['settings'] = array(
    'image_style' => 'thumbnail',
  );
  $handler->display->display_options['fields']['field_oa_media']['delta_offset'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media_1']['id'] = 'field_oa_media_1';
  $handler->display->display_options['fields']['field_oa_media_1']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media_1']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media_1']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_oa_media_1']['delta_offset'] = '0';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['type'] = 'ul';
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'announcementtype' => 0,
    'barrier' => 0,
    'bicompendium' => 0,
    'panopoly_categories' => 0,
    'eventtype' => 0,
    'focusarea' => 0,
    'keywords' => 0,
    'meaningfuluse' => 0,
    'publicationtype' => 0,
    'settings' => 0,
    'targetaudience' => 0,
    'tooltype' => 0,
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Event Date -  start date (field_oa_date) */
  $handler->display->display_options['filters']['field_oa_date_value']['id'] = 'field_oa_date_value';
  $handler->display->display_options['filters']['field_oa_date_value']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['filters']['field_oa_date_value']['field'] = 'field_oa_date_value';
  $handler->display->display_options['filters']['field_oa_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_oa_date_value']['default_date'] = 'now';

  /* Display: Event Details */
  $handler = $view->new_display('panel_pane', 'Event Details', 'event_details');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_1']['id'] = 'field_oa_date_1';
  $handler->display->display_options['fields']['field_oa_date_1']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_1']['type'] = 'events_date_formatter';
  $handler->display->display_options['fields']['field_oa_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date_1']['delta_offset'] = '0';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date']['id'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_oa_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['type'] = 'events_upcoming_date';
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
  $handler->display->display_options['fields']['field_oa_address']['label'] = 'Where';
  $handler->display->display_options['fields']['field_oa_address']['alter']['text'] = '[field_oa_address]
[field_event_link]';
  $handler->display->display_options['fields']['field_oa_address']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_2']['id'] = 'field_oa_date_2';
  $handler->display->display_options['fields']['field_oa_date_2']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_2']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_2']['type'] = 'events_addthis';
  $handler->display->display_options['fields']['field_oa_date_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date_2']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium Events';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Event Detail List */
  $handler = $view->new_display('panel_pane', 'Event Detail List', 'event_details_list');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'archived';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_1']['id'] = 'field_oa_date_1';
  $handler->display->display_options['fields']['field_oa_date_1']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_1']['type'] = 'events_date_formatter';
  $handler->display->display_options['fields']['field_oa_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_1']['delta_offset'] = '0';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date']['id'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_oa_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date']['type'] = 'events_upcoming_date';
  $handler->display->display_options['fields']['field_oa_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['type'] = 'ul';
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'announcementtype' => 0,
    'barrier' => 0,
    'bicompendium' => 0,
    'panopoly_categories' => 0,
    'eventtype' => 0,
    'focusarea' => 0,
    'keywords' => 0,
    'meaningfuluse' => 0,
    'publicationtype' => 0,
    'settings' => 0,
    'targetaudience' => 0,
    'tooltype' => 0,
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_oa_address']['id'] = 'field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['table'] = 'field_data_field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['field'] = 'field_oa_address';
  $handler->display->display_options['fields']['field_oa_address']['label'] = '';
  $handler->display->display_options['fields']['field_oa_address']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [timestamp]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_oa_date_2']['id'] = 'field_oa_date_2';
  $handler->display->display_options['fields']['field_oa_date_2']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_2']['field'] = 'field_oa_date';
  $handler->display->display_options['fields']['field_oa_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_oa_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_date_2']['type'] = 'events_addthis';
  $handler->display->display_options['fields']['field_oa_date_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_oa_date_2']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event Date -  start date (field_oa_date) */
  $handler->display->display_options['sorts']['field_oa_date_value']['id'] = 'field_oa_date_value';
  $handler->display->display_options['sorts']['field_oa_date_value']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['sorts']['field_oa_date_value']['field'] = 'field_oa_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Protocol (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Section (oa_section_ref) */
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Event Date -  start date (field_oa_date) */
  $handler->display->display_options['filters']['field_oa_date_value']['id'] = 'field_oa_date_value';
  $handler->display->display_options['filters']['field_oa_date_value']['table'] = 'field_data_field_oa_date';
  $handler->display->display_options['filters']['field_oa_date_value']['field'] = 'field_oa_date_value';
  $handler->display->display_options['filters']['field_oa_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_oa_date_value']['default_date'] = 'now';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['exposed'] = TRUE;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Include archived content';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium Events';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'og_group_ref_target_id' => array(
      'type' => 'none',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Groups audience (og_group_ref)',
    ),
    'oa_section_ref_target_id' => array(
      'type' => 'none',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Open Atrium Section (oa_section_ref)',
    ),
  );
  $translatables['event_detail'] = array(
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
    t('flag_content_rel'),
    t('Date'),
    t('[field_oa_address]
[field_event_link]'),
    t('Body'),
    t('Attachments'),
    t('All'),
    t('Event Details'),
    t('Where'),
    t('Open Atrium Events'),
    t('Event Detail List'),
    t('archived'),
    t('[title] [timestamp]'),
    t('Include archived content'),
  );
  $export['event_detail'] = $view;

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
    'og_group_ref' => 'og_group_ref',
    'field_event_calendar_section' => 'field_event_calendar_section',
    'type' => 'type',
    'title' => 'title',
    'timestamp' => 'timestamp',
    'changed' => 'changed',
    'body' => 'body',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'og_group_ref' => array(
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
    'type' => array(
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
    'timestamp' => array(
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
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$form = drupal_get_form(\'ma_collaboration_tools_notification_frequency_default\');
print drupal_render($form);
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
  /* Field: Content: Calendar */
  $handler->display->display_options['fields']['field_event_calendar_section']['id'] = 'field_event_calendar_section';
  $handler->display->display_options['fields']['field_event_calendar_section']['table'] = 'field_data_field_event_calendar_section';
  $handler->display->display_options['fields']['field_event_calendar_section']['field'] = 'field_event_calendar_section';
  $handler->display->display_options['fields']['field_event_calendar_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_calendar_section']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_calendar_section']['alter']['text'] = 'Calendar: [title]';
  $handler->display->display_options['fields']['field_event_calendar_section']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_event_calendar_section']['group_columns'] = array(
    'target_id' => 'target_id',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Parent';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_event_calendar_section] ';
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
list ($following, $reasons) = ma_collaboration_tools_get_following_status_and_reasons($data->_field_data[\'nid\'][\'entity\'], $view->args[0]);
print $reasons;
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
print l(\'<button class="btn btn-default">UnFollow</button>\', \'node/\' . $data->nid . \'/unfollow\', [\'html\' => TRUE, \'query\' => drupal_get_destination()]);
?>
';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Notification Frequency';
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
  /* Filter criterion: Content: Published */
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
    t('Calendar'),
    t('Calendar: [title]'),
    t('Parent'),
    t('[field_event_calendar_section] '),
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

  $view = new view();
  $view->name = 'open_atrium_news';
  $view->description = '';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent News';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'archived';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = 'aoeu';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = 'span';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'panopoly_day';
  $handler->display->display_options['fields']['created']['oa_date'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'panopoly_categories' => 0,
    'wilson_vocab' => 0,
  );
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media']['id'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['label'] = '';
  $handler->display->display_options['fields']['field_oa_media']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media']['type'] = 'media_colorbox';
  $handler->display->display_options['fields']['field_oa_media']['settings'] = array(
    'file_view_mode' => 'preview',
    'colorbox_view_mode' => 'default',
    'fixed_width' => '',
    'fixed_height' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'title',
    'audio_playlist' => 0,
  );
  $handler->display->display_options['fields']['field_oa_media']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_oa_media']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<i class="icon-pencil"></i><span>&nbsp;edit</span>';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field: Protocol (og_group_ref) */
  $handler->display->display_options['filters']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator_id'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['label'] = 'Space';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['identifier'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Section (oa_section_ref) */
  $handler->display->display_options['filters']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['operator_id'] = 'oa_section_ref_target_id_op';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['operator'] = 'oa_section_ref_target_id_op';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['identifier'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['exposed'] = TRUE;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Include archived content';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Recent News */
  $handler = $view->new_display('panel_pane', 'Recent News', 'oa_recent_news');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $translatables['open_atrium_news'] = array(
    t('Master'),
    t('Recent News'),
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
    t('author'),
    t('archived'),
    t('aoeu'),
    t('<i class="icon-pencil"></i><span>&nbsp;edit</span>'),
    t('Type'),
    t('Space'),
    t('Section'),
    t('Include archived content'),
    t('Open Atrium'),
  );
  $export['open_atrium_news'] = $view;

  return $export;
}
