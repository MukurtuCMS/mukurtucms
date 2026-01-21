<?php
/**
 * @file
 * oa_river.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oa_river_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'oa_recent_activity';
  $view->description = 'Recent activity within a space or user';
  $view->tag = 'OA';
  $view->base_table = 'message';
  $view->human_name = 'Open Atrium Recent Activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent Activity';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'oa_form';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['collapsed_filter'] = 1;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'timestamp_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'group-content';
  $handler->display->display_options['style_options']['wrapper_class'] = 'group-header';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'timestamp' => 'timestamp',
    'name' => 'name',
    'type' => 'type',
    'type_1' => 'type_1',
    'title' => 'title',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['id'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['table'] = 'field_data_field_oa_node_ref';
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['field'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['label'] = 'Referenced Node';
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_1']['date_format'] = 'panopoly_day';
  $handler->display->display_options['fields']['timestamp_1']['oa_date'] = 'oa_date';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['label'] = '';
  $handler->display->display_options['fields']['mid']['element_label_colon'] = FALSE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'panopoly_time';
  $handler->display->display_options['fields']['timestamp']['oa_date'] = '0';
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Message: Space */
  $handler->display->display_options['fields']['field_oa_message_space']['id'] = 'field_oa_message_space';
  $handler->display->display_options['fields']['field_oa_message_space']['table'] = 'field_data_field_oa_message_space';
  $handler->display->display_options['fields']['field_oa_message_space']['field'] = 'field_oa_message_space';
  $handler->display->display_options['fields']['field_oa_message_space']['label'] = '';
  $handler->display->display_options['fields']['field_oa_message_space']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_oa_message_space']['element_class'] = 'label';
  $handler->display->display_options['fields']['field_oa_message_space']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_space']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_space']['settings'] = array(
    'link' => 1,
  );
  /* Field: Message: Section */
  $handler->display->display_options['fields']['field_oa_message_section']['id'] = 'field_oa_message_section';
  $handler->display->display_options['fields']['field_oa_message_section']['table'] = 'field_data_field_oa_message_section';
  $handler->display->display_options['fields']['field_oa_message_section']['field'] = 'field_oa_message_section';
  $handler->display->display_options['fields']['field_oa_message_section']['label'] = '';
  $handler->display->display_options['fields']['field_oa_message_section']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_message_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_section']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_section']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'user';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Message River Header */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['ui_name'] = 'Message River Header';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['preserve_tags'] = '<b> <i> <strong> <em> <a> <span> <img>';
  $handler->display->display_options['fields']['rendered_entity']['element_type'] = 'span';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'oa_river_header';
  /* Field: Message River Accordian */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['ui_name'] = 'Message River Accordian';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['preserve_tags'] = '<b> <i> <strong> <em> <a> <img>';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'oa_river_accordian';
  $handler->display->display_options['fields']['rendered_entity_1']['bypass_access'] = 0;
  /* Field: Message River Body */
  $handler->display->display_options['fields']['rendered_entity_2']['id'] = 'rendered_entity_2';
  $handler->display->display_options['fields']['rendered_entity_2']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['rendered_entity_2']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_2']['ui_name'] = 'Message River Body';
  $handler->display->display_options['fields']['rendered_entity_2']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['max_length'] = '3000';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['more_link_text'] = 'Read more';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['more_link_path'] = '/node/[nid]';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_2']['element_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_2']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_2']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity_2']['view_mode'] = 'oa_river_body';
  /* Field: Message: Custom Text */
  $handler->display->display_options['fields']['field_oa_message_text']['id'] = 'field_oa_message_text';
  $handler->display->display_options['fields']['field_oa_message_text']['table'] = 'field_data_field_oa_message_text';
  $handler->display->display_options['fields']['field_oa_message_text']['field'] = 'field_oa_message_text';
  $handler->display->display_options['fields']['field_oa_message_text']['label'] = '';
  $handler->display->display_options['fields']['field_oa_message_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_message_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_text']['element_default_classes'] = FALSE;
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: Message: Message ID */
  $handler->display->display_options['sorts']['mid']['id'] = 'mid';
  $handler->display->display_options['sorts']['mid']['table'] = 'message';
  $handler->display->display_options['sorts']['mid']['field'] = 'mid';
  $handler->display->display_options['sorts']['mid']['order'] = 'DESC';
  /* Contextual filter: Message: Space (field_oa_message_space:target_id) */
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['id'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['table'] = 'field_data_field_oa_message_space';
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['field'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_oa_message_space_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Message: Space (field_oa_message_space:target_id) */
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['id'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['table'] = 'field_data_field_oa_message_space';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['field'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['operator_id'] = 'field_oa_message_space_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['label'] = 'Space';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['operator'] = 'field_oa_message_space_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['identifier'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Message: Section (field_oa_message_section:target_id) */
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['id'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['table'] = 'field_data_field_oa_message_section';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['field'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['operator_id'] = 'field_oa_message_section_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['operator'] = 'field_oa_message_section_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['identifier'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'user';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['group'] = 1;
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_field'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content access: Access */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_oa_node_ref_target_id';

  /* Display: User Activity */
  $handler = $view->new_display('panel_pane', 'User Activity', 'user_activity');
  $handler->display->display_options['display_description'] = 'Recent activity for a user';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Message: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'message';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['user']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Space (field_oa_message_space:target_id) */
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['id'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['table'] = 'field_data_field_oa_message_space';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['field'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['value'] = 'All';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['operator_id'] = 'field_oa_message_space_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['label'] = 'Space';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['operator'] = 'field_oa_message_space_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['identifier'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Message: Section (field_oa_message_section:target_id) */
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['id'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['table'] = 'field_data_field_oa_message_section';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['field'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['operator_id'] = 'field_oa_message_section_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['operator'] = 'field_oa_message_section_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['identifier'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  /* Filter criterion: Content access: Access */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_oa_node_ref_target_id';
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
  $handler->display->display_options['allow']['exposed_form_configure'] = 'exposed_form_configure';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'field_oa_message_space_target_id' => 'pane_and_exposed',
      'field_oa_message_section_target_id' => 'pane_and_exposed',
      'type' => 'pane_and_exposed',
    ),
  );
  $handler->display->display_options['argument_input'] = array(
    'user' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Message: User uid',
    ),
  );

  /* Display: Content Activity */
  $handler = $view->new_display('panel_pane', 'Content Activity', 'section_activity');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'user';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['group'] = 1;
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'User Name';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_field'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content access: Access */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_oa_node_ref_target_id';
  /* Filter criterion: Content: Groups audience (og_group_ref:target_id) */
  $handler->display->display_options['filters']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator_id'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['label'] = 'Space';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['identifier'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Section (oa_section_ref:target_id) */
  $handler->display->display_options['filters']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['operator_id'] = 'oa_section_ref_target_id_op';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['operator'] = 'oa_section_ref_target_id_op';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['identifier'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 'exposed_form_configure';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'type' => 'pane_and_exposed',
      'realname' => 'pane_and_exposed',
      'og_group_ref_target_id' => 'pane_and_exposed',
      'oa_section_ref_target_id' => 'pane_and_exposed',
    ),
  );
  $handler->display->display_options['argument_input'] = array(
    'field_oa_message_space_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.group_group',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Message: Space (field_oa_message_space)',
    ),
    'field_oa_message_section_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Message: Section (field_oa_message_section)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Subscribed Activity */
  $handler = $view->new_display('panel_pane', 'Subscribed Activity', 'panel_pane_subscribed');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['id'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['table'] = 'field_data_field_oa_node_ref';
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['field'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['relationships']['field_oa_node_ref_target_id']['label'] = 'Referenced Node';
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Flags: subscribe_section_content */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'subscribe_section_content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_1']['date_format'] = 'panopoly_day';
  $handler->display->display_options['fields']['timestamp_1']['oa_date'] = 'oa_date';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['label'] = '';
  $handler->display->display_options['fields']['mid']['element_label_colon'] = FALSE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'panopoly_time';
  $handler->display->display_options['fields']['timestamp']['oa_date'] = '0';
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Message: Space */
  $handler->display->display_options['fields']['field_oa_message_space']['id'] = 'field_oa_message_space';
  $handler->display->display_options['fields']['field_oa_message_space']['table'] = 'field_data_field_oa_message_space';
  $handler->display->display_options['fields']['field_oa_message_space']['field'] = 'field_oa_message_space';
  $handler->display->display_options['fields']['field_oa_message_space']['label'] = '';
  $handler->display->display_options['fields']['field_oa_message_space']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_oa_message_space']['element_class'] = 'label';
  $handler->display->display_options['fields']['field_oa_message_space']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_space']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_space']['settings'] = array(
    'link' => 1,
  );
  /* Field: Message: Section */
  $handler->display->display_options['fields']['field_oa_message_section']['id'] = 'field_oa_message_section';
  $handler->display->display_options['fields']['field_oa_message_section']['table'] = 'field_data_field_oa_message_section';
  $handler->display->display_options['fields']['field_oa_message_section']['field'] = 'field_oa_message_section';
  $handler->display->display_options['fields']['field_oa_message_section']['label'] = '';
  $handler->display->display_options['fields']['field_oa_message_section']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_message_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_section']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_section']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'user';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Message River Header */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['ui_name'] = 'Message River Header';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['preserve_tags'] = '<b> <i> <strong> <em> <a> <span> <img>';
  $handler->display->display_options['fields']['rendered_entity']['element_type'] = 'span';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'oa_river_header';
  /* Field: Message River Accordian */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['ui_name'] = 'Message River Accordian';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['preserve_tags'] = '<b> <i> <strong> <em> <a> <img>';
  $handler->display->display_options['fields']['rendered_entity_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'oa_river_accordian';
  /* Field: Message River Body */
  $handler->display->display_options['fields']['rendered_entity_2']['id'] = 'rendered_entity_2';
  $handler->display->display_options['fields']['rendered_entity_2']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['rendered_entity_2']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_2']['ui_name'] = 'Message River Body';
  $handler->display->display_options['fields']['rendered_entity_2']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['max_length'] = '3000';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['more_link_text'] = 'Read more';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['more_link_path'] = '/node/[nid]';
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_2']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_2']['element_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_2']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_2']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity_2']['view_mode'] = 'oa_river_body';
  /* Field: Message: Custom Text */
  $handler->display->display_options['fields']['field_oa_message_text']['id'] = 'field_oa_message_text';
  $handler->display->display_options['fields']['field_oa_message_text']['table'] = 'field_data_field_oa_message_text';
  $handler->display->display_options['fields']['field_oa_message_text']['field'] = 'field_oa_message_text';
  $handler->display->display_options['fields']['field_oa_message_text']['label'] = '';
  $handler->display->display_options['fields']['field_oa_message_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_message_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_message_text']['element_default_classes'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: Message: Message ID */
  $handler->display->display_options['sorts']['mid']['id'] = 'mid';
  $handler->display->display_options['sorts']['mid']['table'] = 'message';
  $handler->display->display_options['sorts']['mid']['field'] = 'mid';
  $handler->display->display_options['sorts']['mid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Space (field_oa_message_space:target_id) */
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['id'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['table'] = 'field_data_field_oa_message_space';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['field'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['value'] = 'All';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['operator_id'] = 'field_oa_message_space_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['label'] = 'Space';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['operator'] = 'field_oa_message_space_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['identifier'] = 'field_oa_message_space_target_id';
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_space_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Message: Section (field_oa_message_section:target_id) */
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['id'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['table'] = 'field_data_field_oa_message_section';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['field'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['operator_id'] = 'field_oa_message_section_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['operator'] = 'field_oa_message_section_target_id_op';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['identifier'] = 'field_oa_message_section_target_id';
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_message_section_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'user';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['group'] = 1;
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_field'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content access: Access */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_oa_node_ref_target_id';
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 'exposed_form_configure';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'field_oa_message_space_target_id' => 'pane_and_exposed',
      'field_oa_message_section_target_id' => 'pane_and_exposed',
      'type' => 'pane_and_exposed',
      'realname' => 'pane_and_exposed',
    ),
  );
  $export['oa_recent_activity'] = $view;

  return $export;
}
