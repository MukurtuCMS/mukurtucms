<?php

/**
 * @file
 * ma_collaboration_tools.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_collaboration_tools_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|calendar|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'calendar';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'add_content_to_collab_sect_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'calendar_pane' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:9:"arguments";a:1:{s:3:"nid";s:9:"%node:nid";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:29:"oa_fullcalendar-calendar_pane";}',
        'load_terms' => 0,
        'ft' => array(),
      ),
    ),
    'edit_collab_section_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'upcoming_events' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:9:"arguments";a:1:{s:3:"nid";s:9:"%node:nid";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:34:"oa_event_list-upcoming_events_pane";}',
        'load_terms' => 0,
        'ft' => array(
          'classes' => 'right-col-block',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|calendar|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|discussion_space|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'discussion_space';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'add_content_to_collab_sect_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'edit_collab_section_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'generic_dynamic_field' => array(
      'weight' => '1',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:7:{s:9:"use_pager";i:0;s:8:"pager_id";s:1:"1";s:14:"items_per_page";s:1:"0";s:9:"arguments";a:1:{s:3:"nid";s:9:"%node:nid";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:11:"views_panes";s:7:"subtype";s:32:"oa_comment_topics-comment_topics";}',
        'load_terms' => 0,
        'ft' => array(
          'lb' => 'Topics',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|discussion_space|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|discussion_topic|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'discussion_topic';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'discussion_topic_intro_field' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'follow_unfollow' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|discussion_topic|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document_library|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document_library';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'add_content_to_collab_sect_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'edit_collab_section_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'generic_dynamic_field' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:9:"arguments";a:1:{s:3:"nid";s:9:"%node:nid";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:14:"documents-full";}',
        'load_terms' => 0,
        'ft' => array(
          'lb' => 'Documents',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'generic_dynamic_field_2' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:9:"arguments";a:1:{s:3:"nid";s:9:"%node:nid";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:14:"documents-mini";}',
        'load_terms' => 0,
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document_library|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document_page|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document_page';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'follow_unfollow' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document_page|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'calendar_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:21:"events_date_formatter";s:11:"delta_limit";s:1:"0";s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";i:0;s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:18:"node:field_oa_date";}',
        'load_terms' => 0,
        'ft' => array(),
        'field_formatter_label' => '',
      ),
    ),
    'follow_unfollow' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'clearfix',
        ),
      ),
    ),
    'field_oa_geo_location' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'right-col-block',
          'lb' => 'Location',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|event|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|following_notification|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'following_notification';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_notify_all' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|following_notification|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_collaboration_tools_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'add_content_to_collab_sect_link';
  $ds_field->label = 'Add Content to Collab Section Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
return ma_collaboration_tools_add_content_to_section_link($entity);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['add_content_to_collab_sect_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'calendar_date';
  $ds_field->label = 'Calendar Date';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'event|*';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['calendar_date'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'calendar_pane';
  $ds_field->label = 'Calendar';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['calendar_pane'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'discussion_space_topics_list';
  $ds_field->label = 'Discussion Space Topics List';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['discussion_space_topics_list'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'discussion_topic_intro_field';
  $ds_field->label = 'Discussion Topic intro field';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'discussion_topic|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php return ma_collaboration_tools_discussion_topic_intro($entity); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['discussion_topic_intro_field'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'edit_collab_section_link';
  $ds_field->label = 'Edit Collab Section Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
return ma_collaboration_tools_edit_collab_section_link($entity);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['edit_collab_section_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'follow_unfollow';
  $ds_field->label = 'Follow / UnFollow';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php return ma_culturalprotocol_follow_unfollow($entity); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['follow_unfollow'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'generic_dynamic_field';
  $ds_field->label = 'Generic Dynamic Field';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['generic_dynamic_field'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'generic_dynamic_field_2';
  $ds_field->label = 'Generic Dynamic Field 2';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['generic_dynamic_field_2'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'upcoming_events';
  $ds_field->label = 'Upcoming Events';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['upcoming_events'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_collaboration_tools_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|calendar|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'calendar';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'group_access',
        4 => 'path',
        5 => 'og_group_ref',
        6 => 'redirect',
        7 => 'field_item_privacy_setting',
      ),
      'hidden' => array(
        8 => 'field_community_ref',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'group_access' => 'ds_content',
      'path' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'redirect' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|calendar|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|calendar|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'calendar';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        2 => 'body',
        3 => 'calendar_pane',
        5 => 'comments',
      ),
      'right' => array(
        1 => 'upcoming_events',
        4 => 'field_community_ref',
        6 => 'og_group_ref',
        7 => 'group_collab_actions',
        8 => 'add_content_to_collab_sect_link',
        9 => 'edit_collab_section_link',
        10 => 'group_access',
        11 => 'field_item_privacy_setting',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'upcoming_events' => 'right',
      'body' => 'left',
      'calendar_pane' => 'left',
      'field_community_ref' => 'right',
      'comments' => 'left',
      'og_group_ref' => 'right',
      'group_collab_actions' => 'right',
      'add_content_to_collab_sect_link' => 'right',
      'edit_collab_section_link' => 'right',
      'group_access' => 'right',
      'field_item_privacy_setting' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|calendar|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion_space|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_space';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'group_access',
        4 => 'path',
        5 => 'og_group_ref',
        6 => 'redirect',
        7 => 'field_item_privacy_setting',
      ),
      'hidden' => array(
        8 => 'field_community_ref',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'group_access' => 'ds_content',
      'path' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'redirect' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|discussion_space|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion_space|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_space';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        2 => 'generic_dynamic_field',
      ),
      'right' => array(
        1 => 'add_content_to_collab_sect_link',
        3 => 'edit_collab_section_link',
        4 => 'group_collab_actions',
        5 => 'group_access',
        6 => 'field_community_ref',
        7 => 'og_group_ref',
        8 => 'field_item_privacy_setting',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'add_content_to_collab_sect_link' => 'right',
      'generic_dynamic_field' => 'left',
      'edit_collab_section_link' => 'right',
      'group_collab_actions' => 'right',
      'group_access' => 'right',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_item_privacy_setting' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|discussion_space|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion_topic|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_topic';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'field_oa_media',
        4 => 'group_following',
        5 => 'redirect',
        6 => 'path',
        13 => 'field_following_protocols',
        14 => 'field_following_users',
        15 => 'field_un_following_users',
      ),
      'hidden' => array(
        7 => 'og_group_ref',
        8 => 'field_item_privacy_setting',
        9 => 'field_community_ref',
        10 => 'field_custom_notification_freq',
        11 => 'field_discussion_disc_space',
        12 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'group_following' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'og_group_ref' => 'hidden',
      'field_item_privacy_setting' => 'hidden',
      'field_community_ref' => 'hidden',
      'field_custom_notification_freq' => 'hidden',
      'field_discussion_disc_space' => 'hidden',
      '_add_existing_field' => 'hidden',
      'field_following_protocols' => 'ds_content',
      'field_following_users' => 'ds_content',
      'field_un_following_users' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|discussion_topic|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion_topic|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_topic';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'discussion_topic_intro_field',
        2 => 'body',
        3 => 'field_oa_media',
        4 => 'comments',
      ),
      'right' => array(
        1 => 'follow_unfollow',
        5 => 'group_following',
        6 => 'field_following_protocols',
        7 => 'field_following_users',
        8 => 'field_un_following_users',
      ),
    ),
    'fields' => array(
      'discussion_topic_intro_field' => 'left',
      'follow_unfollow' => 'right',
      'body' => 'left',
      'field_oa_media' => 'left',
      'comments' => 'left',
      'group_following' => 'right',
      'field_following_protocols' => 'right',
      'field_following_users' => 'right',
      'field_un_following_users' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|discussion_topic|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_library|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_library';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'group_access',
        4 => 'path',
        5 => 'og_group_ref',
        6 => 'redirect',
        7 => 'field_item_privacy_setting',
      ),
      'hidden' => array(
        8 => 'field_community_ref',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'group_access' => 'ds_content',
      'path' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'redirect' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|document_library|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_library|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_library';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        3 => 'generic_dynamic_field',
        4 => 'comments',
      ),
      'right' => array(
        1 => 'add_content_to_collab_sect_link',
        2 => 'edit_collab_section_link',
        5 => 'group_documents',
        6 => 'field_community_ref',
        7 => 'generic_dynamic_field_2',
        8 => 'og_group_ref',
        9 => 'field_item_privacy_setting',
        10 => 'group_collab_actions',
        11 => 'group_access',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'add_content_to_collab_sect_link' => 'right',
      'edit_collab_section_link' => 'right',
      'generic_dynamic_field' => 'left',
      'comments' => 'left',
      'group_documents' => 'right',
      'field_community_ref' => 'right',
      'generic_dynamic_field_2' => 'right',
      'og_group_ref' => 'right',
      'field_item_privacy_setting' => 'right',
      'group_collab_actions' => 'right',
      'group_access' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|document_library|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_page|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_page';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'field_oa_media',
        4 => 'group_following',
        5 => 'path',
        6 => 'redirect',
        11 => 'field_following_protocols',
        13 => 'field_following_users',
        14 => 'field_un_following_users',
      ),
      'hidden' => array(
        7 => 'field_item_privacy_setting',
        8 => 'og_group_ref',
        9 => 'field_community_ref',
        10 => 'field_custom_notification_freq',
        12 => 'field_document_doc_lib_section',
        15 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'group_following' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
      'field_item_privacy_setting' => 'hidden',
      'og_group_ref' => 'hidden',
      'field_community_ref' => 'hidden',
      'field_custom_notification_freq' => 'hidden',
      'field_following_protocols' => 'ds_content',
      'field_document_doc_lib_section' => 'hidden',
      'field_following_users' => 'ds_content',
      'field_un_following_users' => 'ds_content',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|document_page|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_document_doc_lib_section',
        1 => 'body',
        2 => 'field_oa_media',
        3 => 'comments',
      ),
      'right' => array(
        4 => 'group_following',
        5 => 'follow_unfollow',
        6 => 'field_following_protocols',
        7 => 'field_following_users',
        8 => 'field_un_following_users',
      ),
    ),
    'fields' => array(
      'field_document_doc_lib_section' => 'left',
      'body' => 'left',
      'field_oa_media' => 'left',
      'comments' => 'left',
      'group_following' => 'right',
      'follow_unfollow' => 'right',
      'field_following_protocols' => 'right',
      'field_following_users' => 'right',
      'field_un_following_users' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|document_page|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'field_oa_date',
        3 => 'field_oa_address',
        4 => 'body',
        5 => 'field_oa_media',
        6 => 'group_following',
        7 => 'path',
        8 => 'redirect',
        12 => 'field_following_protocols',
        15 => 'field_following_users',
        16 => 'field_un_following_users',
        18 => '_add_existing_field',
      ),
      'hidden' => array(
        9 => 'field_oa_geo_location',
        10 => 'field_event_calendar_section',
        11 => 'field_community_ref',
        13 => 'og_group_ref',
        14 => 'field_item_privacy_setting',
        17 => 'field_custom_notification_freq',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'field_oa_date' => 'ds_content',
      'field_oa_address' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'group_following' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
      'field_oa_geo_location' => 'hidden',
      'field_event_calendar_section' => 'hidden',
      'field_community_ref' => 'hidden',
      'field_following_protocols' => 'ds_content',
      'og_group_ref' => 'hidden',
      'field_item_privacy_setting' => 'hidden',
      'field_following_users' => 'ds_content',
      'field_un_following_users' => 'ds_content',
      'field_custom_notification_freq' => 'hidden',
      '_add_existing_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|event|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'calendar_date',
        1 => 'group_event_details',
        2 => 'field_oa_date',
        3 => 'body',
        4 => 'field_oa_media',
        5 => 'field_oa_address',
        6 => 'comments',
        7 => 'field_event_calendar_section',
      ),
      'right' => array(
        8 => 'field_oa_geo_location',
        9 => 'group_following',
        10 => 'follow_unfollow',
        11 => 'field_following_protocols',
        12 => 'field_following_users',
        13 => 'field_un_following_users',
      ),
    ),
    'fields' => array(
      'calendar_date' => 'left',
      'group_event_details' => 'left',
      'field_oa_date' => 'left',
      'body' => 'left',
      'field_oa_media' => 'left',
      'field_oa_address' => 'left',
      'comments' => 'left',
      'field_event_calendar_section' => 'left',
      'field_oa_geo_location' => 'right',
      'group_following' => 'right',
      'follow_unfollow' => 'right',
      'field_following_protocols' => 'right',
      'field_following_users' => 'right',
      'field_un_following_users' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|event|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|following_notification|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'following_notification';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_following_content',
        1 => 'field_notify_immediately',
        2 => 'field_notify_day',
        3 => 'field_notify_week',
        4 => 'field_notify_all',
        5 => 'field_users_notified',
        6 => 'field_all_users_notified',
        7 => 'field_notification_email',
      ),
    ),
    'fields' => array(
      'field_following_content' => 'ds_content',
      'field_notify_immediately' => 'ds_content',
      'field_notify_day' => 'ds_content',
      'field_notify_week' => 'ds_content',
      'field_notify_all' => 'ds_content',
      'field_users_notified' => 'ds_content',
      'field_all_users_notified' => 'ds_content',
      'field_notification_email' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|following_notification|full'] = $ds_layout;

  return $export;
}
