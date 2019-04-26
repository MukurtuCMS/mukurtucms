<?php

/**
 * @file
 * ma_lesson_plan.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_lesson_plan_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|lesson|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_lesson_plan_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_lesson_days|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_lesson_days';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_day',
        1 => 'field_engage',
        2 => 'field_explore_environment',
        3 => 'field_elders',
        4 => 'field_explain',
        5 => 'field_elaborate',
        6 => 'field_evaluate',
      ),
    ),
    'fields' => array(
      'field_day' => 'central',
      'field_engage' => 'central',
      'field_explore_environment' => 'central',
      'field_elders' => 'central',
      'field_explain' => 'central',
      'field_elaborate' => 'central',
      'field_evaluate' => 'central',
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
  $export['field_collection_item|field_lesson_days|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_lesson_micro_tasks|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_lesson_micro_tasks';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_task',
        1 => 'field_key_student_outcomes',
      ),
    ),
    'fields' => array(
      'field_task' => 'central',
      'field_key_student_outcomes' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_lesson_micro_tasks|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_lesson_micro_tasks',
        3 => 'field_lesson_tech_integration',
        4 => 'field_related_dictionary_words',
        5 => 'field_lesson_days',
        6 => 'field_lesson_resources',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'body' => 'central',
      'field_lesson_micro_tasks' => 'central',
      'field_lesson_tech_integration' => 'central',
      'field_related_dictionary_words' => 'central',
      'field_lesson_days' => 'central',
      'field_lesson_resources' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'central' => array(
        'lesson-body' => 'lesson-body',
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
  $export['node|lesson|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'body',
        3 => 'field_lesson_micro_tasks',
        4 => 'field_lesson_tech_integration',
        5 => 'field_related_dictionary_words',
        6 => 'field_lesson_reources',
        7 => 'field_lesson_resources',
        8 => 'field_lesson_days',
        9 => '_add_existing_field',
      ),
      'hidden' => array(
        10 => 'redirect',
        11 => 'path',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_lesson_micro_tasks' => 'ds_content',
      'field_lesson_tech_integration' => 'ds_content',
      'field_related_dictionary_words' => 'ds_content',
      'field_lesson_reources' => 'ds_content',
      'field_lesson_resources' => 'ds_content',
      'field_lesson_days' => 'ds_content',
      '_add_existing_field' => 'ds_content',
      'redirect' => 'hidden',
      'path' => 'hidden',
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
  $export['node|lesson|form'] = $ds_layout;

  return $export;
}
