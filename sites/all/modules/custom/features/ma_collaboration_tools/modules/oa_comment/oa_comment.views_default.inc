<?php
/**
 * @file
 * oa_comment.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oa_comment_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'oa_comment_media';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Open Atrium Comment Media';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Documents/Media';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_oa_media_paragraphs_item']['id'] = 'reverse_field_oa_media_paragraphs_item';
  $handler->display->display_options['relationships']['reverse_field_oa_media_paragraphs_item']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['reverse_field_oa_media_paragraphs_item']['field'] = 'reverse_field_oa_media_paragraphs_item';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_oa_related_node']['id'] = 'field_oa_related_node';
  $handler->display->display_options['relationships']['field_oa_related_node']['table'] = 'paragraphs_item';
  $handler->display->display_options['relationships']['field_oa_related_node']['field'] = 'field_oa_related_node';
  $handler->display->display_options['relationships']['field_oa_related_node']['relationship'] = 'reverse_field_oa_media_paragraphs_item';
  $handler->display->display_options['relationships']['field_oa_related_node']['ui_name'] = 'field_oa_related_node';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_oa_related_comment']['id'] = 'field_oa_related_comment';
  $handler->display->display_options['relationships']['field_oa_related_comment']['table'] = 'paragraphs_item';
  $handler->display->display_options['relationships']['field_oa_related_comment']['field'] = 'field_oa_related_comment';
  $handler->display->display_options['relationships']['field_oa_related_comment']['relationship'] = 'reverse_field_oa_media_paragraphs_item';
  $handler->display->display_options['relationships']['field_oa_related_comment']['ui_name'] = 'field_oa_related_comment';
  /* Relationship: field_oa_media_node */
  $handler->display->display_options['relationships']['reverse_field_oa_media_node']['id'] = 'reverse_field_oa_media_node';
  $handler->display->display_options['relationships']['reverse_field_oa_media_node']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['reverse_field_oa_media_node']['field'] = 'reverse_field_oa_media_node';
  $handler->display->display_options['relationships']['reverse_field_oa_media_node']['ui_name'] = 'field_oa_media_node';
  $handler->display->display_options['relationships']['reverse_field_oa_media_node']['label'] = 'field_oa_media_node';
  /* Relationship: Comment: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'comment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'field_oa_related_comment';
  /* Relationship: author_paragraph */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['relationship'] = 'field_oa_related_node';
  $handler->display->display_options['relationships']['uid_1']['ui_name'] = 'author_paragraph';
  $handler->display->display_options['relationships']['uid_1']['label'] = 'author_paragraph';
  /* Relationship: author_media */
  $handler->display->display_options['relationships']['uid_2']['id'] = 'uid_2';
  $handler->display->display_options['relationships']['uid_2']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_2']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_2']['relationship'] = 'reverse_field_oa_media_node';
  $handler->display->display_options['relationships']['uid_2']['ui_name'] = 'author_media';
  $handler->display->display_options['relationships']['uid_2']['label'] = 'author_media';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid_3']['id'] = 'uid_3';
  $handler->display->display_options['relationships']['uid_3']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_3']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_3']['relationship'] = 'reverse_field_oa_media_node';
  $handler->display->display_options['relationships']['uid_3']['label'] = 'author_node';
  /* Relationship: File: User who uploaded */
  $handler->display->display_options['relationships']['uid_4']['id'] = 'uid_4';
  $handler->display->display_options['relationships']['uid_4']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid_4']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_4']['required'] = TRUE;
  /* Field: Comment: ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'comment';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['relationship'] = 'field_oa_related_comment';
  $handler->display->display_options['fields']['cid']['label'] = '';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['element_label_colon'] = FALSE;
  /* Field: File: Rendered */
  $handler->display->display_options['fields']['rendered']['id'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['table'] = 'file_managed';
  $handler->display->display_options['fields']['rendered']['field'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['label'] = '';
  $handler->display->display_options['fields']['rendered']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered']['file_view_mode'] = 'colorbox';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_oa_media_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_oa_related_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = '[title_1]';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'users';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'uid_2';
  $handler->display->display_options['fields']['name_2']['element_type'] = '0';
  $handler->display->display_options['fields']['name_2']['overwrite_anonymous'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['element_type'] = '0';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['empty'] = '[name_2]';
  $handler->display->display_options['fields']['name_1']['overwrite_anonymous'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['empty'] = '[name_1]';
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = TRUE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture_2']['id'] = 'picture_2';
  $handler->display->display_options['fields']['picture_2']['table'] = 'users';
  $handler->display->display_options['fields']['picture_2']['field'] = 'picture';
  $handler->display->display_options['fields']['picture_2']['relationship'] = 'uid_2';
  $handler->display->display_options['fields']['picture_2']['label'] = '';
  $handler->display->display_options['fields']['picture_2']['element_type'] = '0';
  $handler->display->display_options['fields']['picture_2']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture_1']['id'] = 'picture_1';
  $handler->display->display_options['fields']['picture_1']['table'] = 'users';
  $handler->display->display_options['fields']['picture_1']['field'] = 'picture';
  $handler->display->display_options['fields']['picture_1']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['picture_1']['label'] = '';
  $handler->display->display_options['fields']['picture_1']['element_type'] = '0';
  $handler->display->display_options['fields']['picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture_1']['empty'] = '[picture_2]';
  $handler->display->display_options['fields']['picture_1']['image_style'] = 'oa_small_thumbnail';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_type'] = '0';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '[picture_1]';
  $handler->display->display_options['fields']['picture']['image_style'] = 'oa_small_thumbnail';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'users';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['relationship'] = 'uid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_4']['id'] = 'name_4';
  $handler->display->display_options['fields']['name_4']['table'] = 'users';
  $handler->display->display_options['fields']['name_4']['field'] = 'name';
  $handler->display->display_options['fields']['name_4']['relationship'] = 'uid_4';
  $handler->display->display_options['fields']['name_4']['label'] = '';
  $handler->display->display_options['fields']['name_4']['element_label_colon'] = FALSE;
  /* Sort criterion: Comment: ID */
  $handler->display->display_options['sorts']['cid']['id'] = 'cid';
  $handler->display->display_options['sorts']['cid']['table'] = 'comment';
  $handler->display->display_options['sorts']['cid']['field'] = 'cid';
  $handler->display->display_options['sorts']['cid']['relationship'] = 'field_oa_related_comment';
  /* Contextual filter: File Usage: All IDs in usage with this content */
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['id'] = 'paragraph_and_current_ids';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['table'] = 'file_usage';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['field'] = 'paragraph_and_current_ids';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['default_action'] = 'default';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['exception']['value'] = '';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['paragraph_and_current_ids']['summary_options']['items_per_page'] = '25';

  /* Display: Media attached to content & comments */
  $handler = $view->new_display('panel_pane', 'Media attached to content & comments', 'commentnode_attachments');
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'paragraph_and_current_ids' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'File Usage: All IDs in usage with this content',
    ),
  );
  $translatables['oa_comment_media'] = array(
    t('Master'),
    t('Documents/Media'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('reverse_field_oa_media_paragraphs_item'),
    t('field_oa_related_node'),
    t('field_oa_related_comment'),
    t('field_oa_media_node'),
    t('author'),
    t('author_paragraph'),
    t('author_media'),
    t('author_node'),
    t('User who uploaded'),
    t('[title_1]'),
    t('Name'),
    t('[name_2]'),
    t('[name_1]'),
    t('[picture_2]'),
    t('[picture_1]'),
    t('All'),
    t('Media attached to content & comments'),
    t('Open Atrium'),
  );
  $export['oa_comment_media'] = $view;

  $view = new view();
  $view->name = 'oa_comment_topics';
  $view->description = '';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium Comment Topic List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Topics';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'last_date_1',
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
    'counter' => 'counter',
    'field_oa_media' => 'field_oa_media',
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'NoTopics';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are not yet any discussion topics in this space.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Comment: Comments of the node */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'node';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  /* Relationship: Comment: Author */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'comment';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['relationship'] = 'cid';
  $handler->display->display_options['relationships']['uid_1']['label'] = 'commentuid';
  /* Relationship: Comment: Last Comment */
  $handler->display->display_options['relationships']['cid_1']['id'] = 'cid_1';
  $handler->display->display_options['relationships']['cid_1']['table'] = 'node_comment_statistics';
  $handler->display->display_options['relationships']['cid_1']['field'] = 'cid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_discussion_disc_space_target_id']['id'] = 'field_discussion_disc_space_target_id';
  $handler->display->display_options['relationships']['field_discussion_disc_space_target_id']['table'] = 'field_data_field_discussion_disc_space';
  $handler->display->display_options['relationships']['field_discussion_disc_space_target_id']['field'] = 'field_discussion_disc_space_target_id';
  $handler->display->display_options['relationships']['field_discussion_disc_space_target_id']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: COUNT(Comment Counts) */
  $handler->display->display_options['fields']['cid_1']['id'] = 'cid_1';
  $handler->display->display_options['fields']['cid_1']['table'] = 'comment';
  $handler->display->display_options['fields']['cid_1']['field'] = 'cid';
  $handler->display->display_options['fields']['cid_1']['relationship'] = 'cid';
  $handler->display->display_options['fields']['cid_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['cid_1']['ui_name'] = 'Comment Counts';
  $handler->display->display_options['fields']['cid_1']['label'] = '';
  $handler->display->display_options['fields']['cid_1']['element_type'] = '0';
  $handler->display->display_options['fields']['cid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cid_1']['element_wrapper_type'] = '0';
  /* Field: SUM(Comments new count since user last viewed node) */
  $handler->display->display_options['fields']['timestamp_new_comments']['id'] = 'timestamp_new_comments';
  $handler->display->display_options['fields']['timestamp_new_comments']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_new_comments']['field'] = 'timestamp_new_comments';
  $handler->display->display_options['fields']['timestamp_new_comments']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_new_comments']['ui_name'] = 'Comments new count since user last viewed node';
  $handler->display->display_options['fields']['timestamp_new_comments']['label'] = '';
  $handler->display->display_options['fields']['timestamp_new_comments']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_new_comments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_new_comments']['element_wrapper_type'] = '0';
  /* Field: SUM(Comments updated count since user last viewed node) */
  $handler->display->display_options['fields']['timestamp_updated_comments']['id'] = 'timestamp_updated_comments';
  $handler->display->display_options['fields']['timestamp_updated_comments']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_updated_comments']['field'] = 'timestamp_updated_comments';
  $handler->display->display_options['fields']['timestamp_updated_comments']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_updated_comments']['ui_name'] = 'Comments updated count since user last viewed node';
  $handler->display->display_options['fields']['timestamp_updated_comments']['label'] = '';
  $handler->display->display_options['fields']['timestamp_updated_comments']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_updated_comments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_updated_comments']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['timestamp_updated_comments']['element_default_classes'] = FALSE;
  /* Field: MAX(Latest Comment CID) */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'comment';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['relationship'] = 'cid';
  $handler->display->display_options['fields']['cid']['group_type'] = 'max';
  $handler->display->display_options['fields']['cid']['ui_name'] = 'Latest Comment CID';
  $handler->display->display_options['fields']['cid']['label'] = '';
  $handler->display->display_options['fields']['cid']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'oa_date';
  $handler->display->display_options['fields']['changed']['oa_date'] = '0';
  /* Field: MAX(Comment: Last updated date) */
  $handler->display->display_options['fields']['last_date']['id'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['table'] = 'comment';
  $handler->display->display_options['fields']['last_date']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['relationship'] = 'cid';
  $handler->display->display_options['fields']['last_date']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date']['label'] = '';
  $handler->display->display_options['fields']['last_date']['element_type'] = '0';
  $handler->display->display_options['fields']['last_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['last_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['last_date']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date']['second_date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date']['oa_date'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: MAX(Comment: Last updated date) */
  $handler->display->display_options['fields']['last_date_1']['id'] = 'last_date_1';
  $handler->display->display_options['fields']['last_date_1']['table'] = 'comment';
  $handler->display->display_options['fields']['last_date_1']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date_1']['relationship'] = 'cid';
  $handler->display->display_options['fields']['last_date_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date_1']['label'] = '';
  $handler->display->display_options['fields']['last_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['last_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date_1']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date_1']['second_date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date_1']['oa_date'] = 'oa_date';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y - g:ia';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'oa_date';
  $handler->display->display_options['fields']['created']['oa_date'] = '0';
  /* Field: Comment: Author */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'comment';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'cid_1';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Sort criterion: MAX(Comment: Last updated date) */
  $handler->display->display_options['sorts']['last_date']['id'] = 'last_date';
  $handler->display->display_options['sorts']['last_date']['table'] = 'comment';
  $handler->display->display_options['sorts']['last_date']['field'] = 'last_date';
  $handler->display->display_options['sorts']['last_date']['relationship'] = 'cid';
  $handler->display->display_options['sorts']['last_date']['group_type'] = 'max';
  $handler->display->display_options['sorts']['last_date']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_discussion_disc_space_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  /* Filter criterion: Comment: ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'comment';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['relationship'] = 'cid';
  $handler->display->display_options['filters']['cid']['operator'] = 'empty';
  $handler->display->display_options['filters']['cid']['group'] = 2;
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'cid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'discussion_topic' => 'discussion_topic',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 3;
  /* Filter criterion: Comment: ID */
  $handler->display->display_options['filters']['cid_1']['id'] = 'cid_1';
  $handler->display->display_options['filters']['cid_1']['table'] = 'comment';
  $handler->display->display_options['filters']['cid_1']['field'] = 'cid';
  $handler->display->display_options['filters']['cid_1']['relationship'] = 'cid';
  $handler->display->display_options['filters']['cid_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['cid_1']['group'] = 3;

  /* Display: Topics */
  $handler = $view->new_display('panel_pane', 'Topics', 'comment_topics');
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
  $handler->display->display_options['allow']['fields_override'] = 0;
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
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['oa_comment_topics'] = array(
    t('Master'),
    t('Topics'),
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
    t('NoTopics'),
    t('There are not yet any discussion topics in this space.'),
    t('author'),
    t('Comments'),
    t('commentuid'),
    t('Last Comment'),
    t('Content entity referenced from field_discussion_disc_space'),
    t('.'),
    t(','),
    t('All'),
    t('Open Atrium'),
  );
  $export['oa_comment_topics'] = $view;

  return $export;
}
