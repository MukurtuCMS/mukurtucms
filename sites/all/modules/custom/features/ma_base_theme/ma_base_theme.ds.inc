<?php

/**
 * @file
 * ma_base_theme.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_base_theme_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|hero_image_two_columns|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'hero_image_two_columns';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_welcome_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
          'lbw' => 1,
        ),
      ),
    ),
  );
  $export['bean|hero_image_two_columns|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_base_theme_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'admin_actions';
  $ds_field->label = 'Admin Actions';
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
  $export['admin_actions'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'component_media_items';
  $ds_field->label = 'More Media Items';
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
  $export['component_media_items'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'extracted_dh_from_relationships';
  $ds_field->label = 'Extracted DH from relationships';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
return ma_base_theme_extracted_relationship_custom_ds_field ($entity, \'digital_heritage\');
?> ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['extracted_dh_from_relationships'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'extracted_dw_from_relationships';
  $ds_field->label = 'Extracted DW from relationships';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
return ma_base_theme_extracted_relationship_custom_ds_field ($entity, \'dictionary_word\');
?> ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['extracted_dw_from_relationships'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'extracted_wl_from_relationships';
  $ds_field->label = 'Extracted WL from relationships';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
return ma_base_theme_extracted_relationship_custom_ds_field ($entity, \'word_list\');
?> ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['extracted_wl_from_relationships'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_base_theme_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|front_page_hero_image|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'front_page_hero_image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_hero_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_welcome_message',
      ),
    ),
    'fields' => array(
      'field_hero_image' => 'left',
      'title' => 'right',
      'field_welcome_message' => 'right',
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
    'layout_disable_css' => FALSE,
  );
  $export['bean|front_page_hero_image|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|front_page_hero_image|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'front_page_hero_image';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'label',
      ),
      'left' => array(
        1 => 'field_hero_image',
      ),
      'right' => array(
        2 => 'title',
        3 => 'field_welcome_message',
      ),
      'hidden' => array(
        4 => 'view_mode',
        5 => 'revision',
        6 => 'redirect',
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'top',
      'field_hero_image' => 'left',
      'title' => 'right',
      'field_welcome_message' => 'right',
      'view_mode' => 'hidden',
      'revision' => 'hidden',
      'redirect' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|front_page_hero_image|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|hero_image_one_column|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'hero_image_one_column';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'label',
        1 => 'field_hero_image',
        2 => 'field_hero_image_caption',
      ),
      'hidden' => array(
        3 => 'title',
        4 => 'view_mode',
        5 => 'revision',
        6 => 'redirect',
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'central',
      'field_hero_image' => 'central',
      'field_hero_image_caption' => 'central',
      'title' => 'hidden',
      'view_mode' => 'hidden',
      'revision' => 'hidden',
      'redirect' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|hero_image_one_column|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|hero_image_two_columns|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'hero_image_two_columns';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_hero_image',
      ),
      'right' => array(
        1 => 'field_welcome_title',
        2 => 'field_welcome_message',
      ),
    ),
    'fields' => array(
      'field_hero_image' => 'left',
      'field_welcome_title' => 'right',
      'field_welcome_message' => 'right',
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
    'layout_disable_css' => FALSE,
  );
  $export['bean|hero_image_two_columns|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|hero_image_two_columns|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'hero_image_two_columns';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'label',
      ),
      'left' => array(
        1 => 'field_hero_image',
      ),
      'right' => array(
        2 => 'field_welcome_title',
        3 => 'field_welcome_message',
      ),
      'hidden' => array(
        4 => 'title',
        5 => 'view_mode',
        6 => 'revision',
        7 => 'redirect',
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'top',
      'field_hero_image' => 'left',
      'field_welcome_title' => 'right',
      'field_welcome_message' => 'right',
      'title' => 'hidden',
      'view_mode' => 'hidden',
      'revision' => 'hidden',
      'redirect' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['bean|hero_image_two_columns|form'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_base_theme_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'component_media_item';
  $ds_view_mode->label = 'Component Media Item';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['component_media_item'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'full_content';
  $ds_view_mode->label = 'Full content';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['full_content'] = $ds_view_mode;

  return $export;
}
