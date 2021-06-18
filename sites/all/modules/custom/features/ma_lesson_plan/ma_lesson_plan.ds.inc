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
  $ds_fieldsetting->id = 'field_collection_item|field_lesson_micro_tasks|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_lesson_micro_tasks';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'field_related_dh_items' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_word_list' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['field_collection_item|field_lesson_micro_tasks|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|lesson|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'ds_switch_field' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
        'vms' => array(
          'full' => '',
          'search_result' => '',
          'teacher_view' => 'Switch to Teacher View',
          'teaser' => '',
        ),
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|lesson|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'field_lesson_micro_tasks' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_related_dictionary_words' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|lesson|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|lesson|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|teacher_view';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'teacher_view';
  $ds_fieldsetting->settings = array(
    'ds_switch_field' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
        'vms' => array(
          'full' => 'Switch to Student View',
          'search_result' => '',
          'teacher_view' => '',
          'teaser' => '',
        ),
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|lesson|teacher_view'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit_plan|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_plan';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'ds_switch_field' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|unit_plan|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit_plan|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_plan';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'ds_switch_field' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
        'vms' => array(
          'full' => '',
          'search_result' => '',
          'teacher_view' => 'Switch to Teacher View',
          'teaser' => '',
        ),
      ),
      'label' => 'hidden',
      'weight' => '1',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|unit_plan|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit_plan|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_plan';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'field_unit_lessons' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
  );
  $export['node|unit_plan|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit_plan|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_plan';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'field_community_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_unit_grade_level' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_unit_subject' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_unit_teacher' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|unit_plan|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit_plan|teacher_view';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_plan';
  $ds_fieldsetting->view_mode = 'teacher_view';
  $ds_fieldsetting->settings = array(
    'ds_switch_field' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
        'vms' => array(
          'full' => 'Switch to Student View',
          'search_result' => '',
          'teacher_view' => '',
          'teaser' => '',
        ),
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
    'field_tags' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|unit_plan|teacher_view'] = $ds_fieldsetting;

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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_day' => 'central',
      'field_elaborate' => 'central',
      'field_elders' => 'central',
      'field_engage' => 'central',
      'field_evaluate' => 'central',
      'field_explain' => 'central',
      'field_explore_environment' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
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
    'wrappers' => array(
      'central' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_key_student_outcomes' => 'central',
      'field_related_content' => 'central',
      'field_task' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'field_task',
        1 => 'field_key_student_outcomes',
        2 => 'field_related_content',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['field_collection_item|field_lesson_micro_tasks|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_lesson_micro_tasks|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_lesson_micro_tasks';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'hidden',
      'field_key_student_outcomes' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_related_dh_items' => 'hidden',
      'field_task' => 'ds_content',
      'field_word_list' => 'hidden',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_task',
        1 => 'field_key_student_outcomes',
        2 => 'field_related_content',
      ),
      'hidden' => array(
        3 => 'field_related_dh_items',
        4 => 'field_word_list',
        5 => '_add_existing_field',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['field_collection_item|field_lesson_micro_tasks|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_lesson_micro_tasks|mukurtu_mobile';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_lesson_micro_tasks';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_key_student_outcomes' => 'ds_content',
      'field_related_dh_items' => 'ds_content',
      'field_task' => 'ds_content',
      'field_word_list' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_task',
        1 => 'field_key_student_outcomes',
        2 => 'field_related_dh_items',
        3 => 'field_word_list',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['field_collection_item|field_lesson_micro_tasks|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'central' => array(
        'lesson-body' => 'lesson-body',
      ),
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'body' => 'central',
      'field_lesson_days' => 'central',
      'field_lesson_micro_tasks' => 'central',
      'field_lesson_resources' => 'central',
      'field_lesson_tech_integration' => 'central',
      'field_related_content' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_lesson_micro_tasks',
        3 => 'field_lesson_tech_integration',
        4 => 'field_related_content',
        5 => 'field_lesson_days',
        6 => 'field_lesson_resources',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
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
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'ds_content',
      'body' => 'ds_content',
      'field_lesson_days' => 'ds_content',
      'field_lesson_micro_tasks' => 'ds_content',
      'field_lesson_resources' => 'ds_content',
      'field_lesson_tech_integration' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_related_dictionary_words' => 'hidden',
      'group_sorter' => 'ds_content',
      'path' => 'hidden',
      'redirect' => 'hidden',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'group_sorter',
        2 => 'title',
        3 => 'body',
        4 => 'field_lesson_micro_tasks',
        5 => 'field_lesson_tech_integration',
        6 => 'field_related_content',
        7 => 'field_lesson_resources',
        8 => 'field_lesson_days',
        9 => '_add_existing_field',
      ),
      'hidden' => array(
        10 => 'field_related_dictionary_words',
        11 => 'redirect',
        12 => 'path',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|lesson|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'central' => array(
        'lesson-body' => 'lesson-body',
      ),
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'body' => 'central',
      'ds_switch_field' => 'central',
      'field_lesson_micro_tasks' => 'central',
      'field_related_content' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'ds_switch_field',
        1 => 'body',
        2 => 'field_lesson_micro_tasks',
        3 => 'field_related_content',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|lesson|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_lesson_micro_tasks' => 'ds_content',
      'field_related_dictionary_words' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_lesson_micro_tasks',
        3 => 'field_related_dictionary_words',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|lesson|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'body' => 'right',
      'featured_content_type' => 'right',
      'group_list_view_fields' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'right' => array(
        0 => 'title',
        1 => 'featured_content_type',
        2 => 'body',
        3 => 'group_list_view_fields',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|lesson|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|teacher_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'teacher_view';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'central' => array(
        'lesson-body' => 'lesson-body',
      ),
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'body' => 'central',
      'ds_switch_field' => 'central',
      'field_lesson_days' => 'central',
      'field_lesson_micro_tasks' => 'central',
      'field_lesson_resources' => 'central',
      'field_lesson_tech_integration' => 'central',
      'field_related_content' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'ds_switch_field',
        1 => 'body',
        2 => 'field_lesson_micro_tasks',
        3 => 'field_lesson_tech_integration',
        4 => 'field_related_content',
        5 => 'field_lesson_days',
        6 => 'field_lesson_resources',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|lesson|teacher_view'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'bottom' => array(
        'unit-plan-bottom' => 'unit-plan-bottom',
      ),
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'unit-plan-body' => 'unit-plan-body',
      ),
      'right' => array(
        'unit-plan-sidebar' => 'unit-plan-sidebar',
      ),
    ),
    'fields' => array(
      'ds_switch_field' => 'top',
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'field_media_asset' => 'left',
      'field_related_content' => 'left',
      'field_tags' => 'right',
      'field_unit_assessments' => 'left',
      'field_unit_class_period_length' => 'right',
      'field_unit_conceptual' => 'left',
      'field_unit_grade_level' => 'right',
      'field_unit_language_learning' => 'left',
      'field_unit_lessons' => 'bottom',
      'field_unit_nature_of_science' => 'left',
      'field_unit_overarching' => 'left',
      'field_unit_subject' => 'right',
      'field_unit_teacher' => 'right',
      'field_unit_technical' => 'left',
      'field_unit_unit_length' => 'right',
      'field_unit_week_of' => 'right',
      'og_group_ref' => 'right',
      'title' => 'top',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'bottom' => array(
        20 => 'field_unit_lessons',
      ),
      'left' => array(
        2 => 'field_unit_overarching',
        3 => 'field_unit_conceptual',
        4 => 'field_unit_nature_of_science',
        5 => 'field_unit_language_learning',
        6 => 'field_unit_technical',
        7 => 'field_unit_assessments',
        8 => 'field_media_asset',
        9 => 'field_related_content',
      ),
      'right' => array(
        10 => 'field_unit_teacher',
        11 => 'field_unit_subject',
        12 => 'field_unit_grade_level',
        13 => 'field_unit_week_of',
        14 => 'field_unit_unit_length',
        15 => 'field_unit_class_period_length',
        16 => 'field_tags',
        17 => 'field_category',
        18 => 'field_community_ref',
        19 => 'og_group_ref',
      ),
      'top' => array(
        0 => 'title',
        1 => 'ds_switch_field',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['node|unit_plan|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'hidden',
      'field_category' => 'ds_content',
      'field_collection' => 'hidden',
      'field_community_ref' => 'hidden',
      'field_item_privacy_setting' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_related_dh_items' => 'hidden',
      'field_related_dictionary_words' => 'hidden',
      'field_tags' => 'ds_content',
      'field_unit_assessments' => 'ds_content',
      'field_unit_class_period_length' => 'ds_content',
      'field_unit_conceptual' => 'ds_content',
      'field_unit_grade_level' => 'ds_content',
      'field_unit_language_learning' => 'ds_content',
      'field_unit_lessons' => 'ds_content',
      'field_unit_nature_of_science' => 'ds_content',
      'field_unit_overarching' => 'ds_content',
      'field_unit_subject' => 'ds_content',
      'field_unit_teacher' => 'ds_content',
      'field_unit_technical' => 'ds_content',
      'field_unit_unit_length' => 'ds_content',
      'field_unit_week_of' => 'ds_content',
      'field_word_list' => 'hidden',
      'group_base' => 'ds_content',
      'group_lessons' => 'ds_content',
      'group_loa' => 'ds_content',
      'group_tabs' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'path' => 'hidden',
      'redirect' => 'hidden',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'group_tabs',
        5 => 'title',
        7 => 'field_unit_overarching',
        9 => 'field_unit_teacher',
        10 => 'field_unit_conceptual',
        12 => 'field_unit_nature_of_science',
        13 => 'field_unit_subject',
        14 => 'field_unit_grade_level',
        15 => 'field_unit_language_learning',
        16 => 'field_unit_technical',
        17 => 'field_unit_week_of',
        18 => 'field_unit_assessments',
        19 => 'field_unit_unit_length',
        20 => 'field_unit_class_period_length',
        21 => 'field_media_asset',
        22 => 'field_tags',
        23 => 'field_related_content',
        24 => 'group_base',
        25 => 'group_loa',
        26 => 'field_category',
        27 => 'og_group_ref',
        28 => 'group_lessons',
        29 => 'field_item_privacy_setting',
        30 => 'field_unit_lessons',
      ),
      'hidden' => array(
        2 => 'field_collection',
        3 => 'field_word_list',
        4 => 'field_related_dictionary_words',
        6 => 'field_related_dh_items',
        8 => 'path',
        11 => 'redirect',
        31 => 'field_community_ref',
        32 => '_add_existing_field',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|unit_plan|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'central' => array(
        'unit-plan-bottom' => 'unit-plan-bottom',
      ),
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'ds_switch_field' => 'central',
      'field_unit_lessons' => 'central',
      'mukurtu_mobile_sync' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'mukurtu_mobile_sync',
        1 => 'ds_switch_field',
        2 => 'field_unit_lessons',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|unit_plan|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_unit_lessons' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_unit_lessons',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|unit_plan|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_community_ref' => 'right',
      'field_media_asset' => 'left',
      'field_unit_grade_level' => 'right',
      'field_unit_subject' => 'right',
      'field_unit_teacher' => 'right',
      'group_list_view_fields' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        1 => 'field_media_asset',
      ),
      'right' => array(
        0 => 'title',
        2 => 'group_list_view_fields',
        3 => 'featured_content_type',
        4 => 'field_unit_teacher',
        5 => 'field_unit_subject',
        6 => 'field_unit_grade_level',
        7 => 'field_community_ref',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|unit_plan|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|teacher_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'teacher_view';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'bottom' => array(
        'unit-plan-bottom' => 'unit-plan-bottom',
      ),
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'unit-plan-body' => 'unit-plan-body',
      ),
      'right' => array(
        'unit-plan-sidebar' => 'unit-plan-sidebar',
      ),
    ),
    'fields' => array(
      'ds_switch_field' => 'top',
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'field_media_asset' => 'left',
      'field_related_content' => 'left',
      'field_tags' => 'right',
      'field_unit_assessments' => 'left',
      'field_unit_class_period_length' => 'right',
      'field_unit_conceptual' => 'left',
      'field_unit_grade_level' => 'right',
      'field_unit_language_learning' => 'left',
      'field_unit_lessons' => 'bottom',
      'field_unit_nature_of_science' => 'left',
      'field_unit_overarching' => 'left',
      'field_unit_subject' => 'right',
      'field_unit_teacher' => 'right',
      'field_unit_technical' => 'left',
      'field_unit_unit_length' => 'right',
      'field_unit_week_of' => 'right',
      'og_group_ref' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'bottom' => array(
        19 => 'field_unit_lessons',
      ),
      'left' => array(
        1 => 'field_unit_overarching',
        2 => 'field_unit_conceptual',
        3 => 'field_unit_nature_of_science',
        4 => 'field_unit_language_learning',
        5 => 'field_unit_technical',
        6 => 'field_unit_assessments',
        7 => 'field_media_asset',
        8 => 'field_related_content',
      ),
      'right' => array(
        9 => 'field_unit_teacher',
        10 => 'field_unit_subject',
        11 => 'field_unit_grade_level',
        12 => 'field_unit_week_of',
        13 => 'field_unit_unit_length',
        14 => 'field_unit_class_period_length',
        15 => 'field_tags',
        16 => 'field_category',
        17 => 'field_community_ref',
        18 => 'og_group_ref',
      ),
      'top' => array(
        0 => 'ds_switch_field',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['node|unit_plan|teacher_view'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_lesson_plan_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teacher_view';
  $ds_view_mode->label = 'Teacher View';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
  );
  $export['teacher_view'] = $ds_view_mode;

  return $export;
}
