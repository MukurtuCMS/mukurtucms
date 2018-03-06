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
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|discussion_space|full'] = $ds_fieldsetting;

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
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
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
        0 => 'title',
        3 => 'body',
        4 => 'comments',
      ),
      'right' => array(
        1 => 'add_content_to_collab_sect_link',
        2 => 'edit_collab_section_link',
        5 => 'group_collab_actions',
        6 => 'field_community_ref',
        7 => 'group_access',
        8 => 'og_group_ref',
        9 => 'field_item_privacy_setting',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'add_content_to_collab_sect_link' => 'right',
      'edit_collab_section_link' => 'right',
      'body' => 'left',
      'comments' => 'left',
      'group_collab_actions' => 'right',
      'field_community_ref' => 'right',
      'group_access' => 'right',
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
        0 => 'title',
        3 => 'body',
        4 => 'comments',
      ),
      'right' => array(
        1 => 'add_content_to_collab_sect_link',
        2 => 'edit_collab_section_link',
        5 => 'group_collab_actions',
        6 => 'field_community_ref',
        7 => 'group_access',
        8 => 'og_group_ref',
        9 => 'field_item_privacy_setting',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'add_content_to_collab_sect_link' => 'right',
      'edit_collab_section_link' => 'right',
      'body' => 'left',
      'comments' => 'left',
      'group_collab_actions' => 'right',
      'field_community_ref' => 'right',
      'group_access' => 'right',
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
  $export['node|document_library|full'] = $ds_layout;

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
        6 => 'path',
        7 => 'redirect',
        8 => '_add_existing_field',
      ),
      'hidden' => array(
        9 => 'field_oa_geo_location',
        10 => 'field_event_calendar_section',
        11 => 'field_community_ref',
        12 => 'og_group_ref',
        13 => 'field_item_privacy_setting',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'field_oa_date' => 'ds_content',
      'field_oa_address' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
      '_add_existing_field' => 'ds_content',
      'field_oa_geo_location' => 'hidden',
      'field_event_calendar_section' => 'hidden',
      'field_community_ref' => 'hidden',
      'og_group_ref' => 'hidden',
      'field_item_privacy_setting' => 'hidden',
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
        4 => 'field_oa_address',
        5 => 'field_oa_media',
        6 => 'comments',
        7 => 'field_event_calendar_section',
      ),
      'right' => array(
        8 => 'field_oa_geo_location',
      ),
    ),
    'fields' => array(
      'calendar_date' => 'left',
      'group_event_details' => 'left',
      'field_oa_date' => 'left',
      'body' => 'left',
      'field_oa_address' => 'left',
      'field_oa_media' => 'left',
      'comments' => 'left',
      'field_event_calendar_section' => 'left',
      'field_oa_geo_location' => 'right',
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
  $ds_layout->id = 'node|oa_discussion_post|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_discussion_post';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'og_group_ref',
        3 => 'field_item_privacy_setting',
        4 => 'oa_section_ref',
        5 => 'body',
        6 => 'field_oa_media',
        7 => 'redirect',
        8 => 'path',
      ),
      'hidden' => array(
        9 => 'field_community_ref',
        10 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'oa_section_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
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
  $export['node|oa_discussion_post|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|oa_wiki_page|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_wiki_page';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'field_oa_wiki_page_no_redirect',
        4 => 'field_oa_media',
        5 => 'og_group_ref',
        6 => 'oa_section_ref',
        7 => 'field_item_privacy_setting',
        8 => 'path',
        9 => 'redirect',
      ),
      'hidden' => array(
        10 => 'field_community_ref',
        11 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_wiki_page_no_redirect' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'oa_section_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
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
  $export['node|oa_wiki_page|form'] = $ds_layout;

  return $export;
}
