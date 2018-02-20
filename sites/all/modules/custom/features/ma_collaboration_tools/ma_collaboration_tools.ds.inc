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

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_collaboration_tools_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|calendar|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'calendar';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'og_group_ref',
        1 => 'body',
        2 => 'field_item_privacy_setting',
        3 => 'field_community_ref',
        4 => 'field_pre_actions',
      ),
    ),
    'fields' => array(
      'og_group_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_pre_actions' => 'ds_content',
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
  $export['node|calendar|default'] = $ds_layout;

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
        1 => 'body',
        2 => 'calendar_pane',
        3 => 'comments',
      ),
      'right' => array(
        4 => 'field_community_ref',
        5 => 'group_collab_actions',
        6 => 'add_content_to_collab_sect_link',
        7 => 'og_group_ref',
        8 => 'group_access',
        9 => 'edit_collab_section_link',
        10 => 'field_item_privacy_setting',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'calendar_pane' => 'left',
      'comments' => 'left',
      'field_community_ref' => 'right',
      'group_collab_actions' => 'right',
      'add_content_to_collab_sect_link' => 'right',
      'og_group_ref' => 'right',
      'group_access' => 'right',
      'edit_collab_section_link' => 'right',
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
  $ds_layout->id = 'node|discussion_space|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion_space';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'og_group_ref',
        1 => 'body',
        2 => 'field_item_privacy_setting',
        3 => 'field_community_ref',
        4 => 'field_pre_actions',
      ),
    ),
    'fields' => array(
      'og_group_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_pre_actions' => 'ds_content',
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
  $export['node|discussion_space|default'] = $ds_layout;

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
  $ds_layout->id = 'node|document_library|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_library';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'og_group_ref',
        1 => 'body',
        2 => 'field_item_privacy_setting',
        3 => 'field_community_ref',
        4 => 'field_pre_actions',
      ),
    ),
    'fields' => array(
      'og_group_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_community_ref' => 'ds_content',
      'field_pre_actions' => 'ds_content',
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
  $export['node|document_library|default'] = $ds_layout;

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
  $ds_layout->id = 'node|oa_discussion_post|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_discussion_post';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'og_group_ref',
        2 => 'field_item_privacy_setting',
        3 => 'oa_section_ref',
        4 => 'body',
        5 => 'field_oa_media',
        6 => 'redirect',
        7 => 'path',
      ),
      'hidden' => array(
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'oa_section_ref' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
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
  $ds_layout->id = 'node|oa_event|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'oa_event';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_oa_address',
        4 => 'field_oa_media',
        5 => 'field_oa_date',
        6 => 'field_oa_geo_location',
        7 => 'path',
        8 => 'redirect',
      ),
      'hidden' => array(
        3 => 'field_event_calendar_section',
        9 => 'field_community_ref',
        10 => 'og_group_ref',
        11 => 'field_item_privacy_setting',
        12 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_address' => 'ds_content',
      'field_event_calendar_section' => 'hidden',
      'field_oa_media' => 'ds_content',
      'field_oa_date' => 'ds_content',
      'field_oa_geo_location' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
      'field_community_ref' => 'hidden',
      'og_group_ref' => 'hidden',
      'field_item_privacy_setting' => 'hidden',
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
  $export['node|oa_event|form'] = $ds_layout;

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
        0 => 'title',
        1 => 'body',
        2 => 'field_oa_wiki_page_no_redirect',
        3 => 'field_oa_media',
        4 => 'og_group_ref',
        5 => 'oa_section_ref',
        6 => 'field_item_privacy_setting',
        7 => 'path',
        8 => 'redirect',
      ),
      'hidden' => array(
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_oa_wiki_page_no_redirect' => 'ds_content',
      'field_oa_media' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'oa_section_ref' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'path' => 'ds_content',
      'redirect' => 'ds_content',
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
