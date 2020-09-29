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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'ds_switch_field' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'vms' => array(
          'full' => '',
          'teaser' => '',
          'search_result' => '',
          'teacher_view' => 'Switch to Teacher View',
        ),
        'ft' => array(),
      ),
    ),
  );
  $export['node|lesson|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
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
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'vms' => array(
          'full' => 'Switch to Student View',
          'teaser' => '',
          'search_result' => '',
          'teacher_view' => '',
        ),
        'ft' => array(),
      ),
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
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
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
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'vms' => array(
          'full' => '',
          'teaser' => '',
          'search_result' => '',
          'teacher_view' => 'Switch to Teacher View',
        ),
        'ft' => array(),
      ),
    ),
  );
  $export['node|unit_plan|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|unit_plan|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_plan';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_unit_teacher' => array(
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
    'field_unit_grade_level' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_community_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
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
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'vms' => array(
          'full' => 'Switch to Student View',
          'teaser' => '',
          'search_result' => '',
          'teacher_view' => '',
        ),
        'ft' => array(),
      ),
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
        2 => 'field_related_content',
      ),
    ),
    'fields' => array(
      'field_task' => 'central',
      'field_key_student_outcomes' => 'central',
      'field_related_content' => 'central',
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
  $export['field_collection_item|field_lesson_micro_tasks|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_lesson_micro_tasks|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_lesson_micro_tasks';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
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
    'fields' => array(
      'field_task' => 'ds_content',
      'field_key_student_outcomes' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_related_dh_items' => 'hidden',
      'field_word_list' => 'hidden',
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
  $export['field_collection_item|field_lesson_micro_tasks|form'] = $ds_layout;

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
        4 => 'field_related_content',
        5 => 'field_lesson_days',
        6 => 'field_lesson_resources',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'body' => 'central',
      'field_lesson_micro_tasks' => 'central',
      'field_lesson_tech_integration' => 'central',
      'field_related_content' => 'central',
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
        5 => 'field_related_content',
        6 => 'field_lesson_resources',
        7 => 'field_lesson_days',
        11 => '_add_existing_field',
      ),
      'hidden' => array(
        8 => 'field_related_dictionary_words',
        9 => 'redirect',
        10 => 'path',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_lesson_micro_tasks' => 'ds_content',
      'field_lesson_tech_integration' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_lesson_resources' => 'ds_content',
      'field_lesson_days' => 'ds_content',
      'field_related_dictionary_words' => 'hidden',
      'redirect' => 'hidden',
      'path' => 'hidden',
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
  $export['node|lesson|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'ds_switch_field',
        1 => 'body',
        2 => 'field_lesson_micro_tasks',
        3 => 'field_related_content',
      ),
    ),
    'fields' => array(
      'ds_switch_field' => 'central',
      'body' => 'central',
      'field_lesson_micro_tasks' => 'central',
      'field_related_content' => 'central',
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
  $export['node|lesson|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'title',
        1 => 'featured_content_type',
        2 => 'body',
        3 => 'group_list_view_fields',
      ),
    ),
    'fields' => array(
      'title' => 'right',
      'featured_content_type' => 'right',
      'body' => 'right',
      'group_list_view_fields' => 'right',
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
  $export['node|lesson|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|teacher_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'teacher_view';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
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
    'fields' => array(
      'ds_switch_field' => 'central',
      'body' => 'central',
      'field_lesson_micro_tasks' => 'central',
      'field_lesson_tech_integration' => 'central',
      'field_related_content' => 'central',
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
  $export['node|lesson|teacher_view'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'title',
        1 => 'ds_switch_field',
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
      'bottom' => array(
        20 => 'field_unit_lessons',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'ds_switch_field' => 'top',
      'field_unit_overarching' => 'left',
      'field_unit_conceptual' => 'left',
      'field_unit_nature_of_science' => 'left',
      'field_unit_language_learning' => 'left',
      'field_unit_technical' => 'left',
      'field_unit_assessments' => 'left',
      'field_media_asset' => 'left',
      'field_related_content' => 'left',
      'field_unit_teacher' => 'right',
      'field_unit_subject' => 'right',
      'field_unit_grade_level' => 'right',
      'field_unit_week_of' => 'right',
      'field_unit_unit_length' => 'right',
      'field_unit_class_period_length' => 'right',
      'field_tags' => 'right',
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_unit_lessons' => 'bottom',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'unit-plan-body' => 'unit-plan-body',
      ),
      'right' => array(
        'unit-plan-sidebar' => 'unit-plan-sidebar',
      ),
      'bottom' => array(
        'unit-plan-bottom' => 'unit-plan-bottom',
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
  $export['node|unit_plan|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'group_tabs',
        5 => 'field_unit_overarching',
        7 => 'title',
        8 => 'field_unit_conceptual',
        10 => 'field_unit_teacher',
        11 => 'field_unit_nature_of_science',
        12 => 'field_unit_subject',
        14 => 'field_unit_language_learning',
        15 => 'field_unit_grade_level',
        17 => 'field_unit_technical',
        18 => 'field_unit_week_of',
        19 => 'field_unit_assessments',
        20 => 'field_unit_unit_length',
        21 => 'field_unit_class_period_length',
        22 => 'field_media_asset',
        23 => 'field_related_content',
        24 => 'field_tags',
        25 => 'group_base',
        26 => 'field_category',
        27 => 'group_loa',
        28 => 'og_group_ref',
        29 => 'group_lessons',
        30 => 'field_unit_lessons',
      ),
      'hidden' => array(
        2 => 'field_collection',
        3 => 'field_word_list',
        4 => 'field_related_dictionary_words',
        6 => 'field_related_dh_items',
        9 => 'path',
        13 => 'redirect',
        16 => 'field_community_ref',
        31 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'group_tabs' => 'ds_content',
      'field_collection' => 'hidden',
      'field_word_list' => 'hidden',
      'field_related_dictionary_words' => 'hidden',
      'field_unit_overarching' => 'ds_content',
      'field_related_dh_items' => 'hidden',
      'title' => 'ds_content',
      'field_unit_conceptual' => 'ds_content',
      'path' => 'hidden',
      'field_unit_teacher' => 'ds_content',
      'field_unit_nature_of_science' => 'ds_content',
      'field_unit_subject' => 'ds_content',
      'redirect' => 'hidden',
      'field_unit_language_learning' => 'ds_content',
      'field_unit_grade_level' => 'ds_content',
      'field_community_ref' => 'hidden',
      'field_unit_technical' => 'ds_content',
      'field_unit_week_of' => 'ds_content',
      'field_unit_assessments' => 'ds_content',
      'field_unit_unit_length' => 'ds_content',
      'field_unit_class_period_length' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_tags' => 'ds_content',
      'group_base' => 'ds_content',
      'field_category' => 'ds_content',
      'group_loa' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'group_lessons' => 'ds_content',
      'field_unit_lessons' => 'ds_content',
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
  $export['node|unit_plan|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'ds_switch_field',
        1 => 'field_unit_lessons',
      ),
    ),
    'fields' => array(
      'ds_switch_field' => 'central',
      'field_unit_lessons' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'central' => array(
        'unit-plan-bottom' => 'unit-plan-bottom',
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
  $export['node|unit_plan|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'title',
        2 => 'group_list_view_fields',
        3 => 'featured_content_type',
        4 => 'field_unit_teacher',
        5 => 'field_unit_subject',
        6 => 'field_unit_grade_level',
        7 => 'field_community_ref',
      ),
      'left' => array(
        1 => 'field_media_asset',
      ),
    ),
    'fields' => array(
      'title' => 'right',
      'field_media_asset' => 'left',
      'group_list_view_fields' => 'right',
      'featured_content_type' => 'right',
      'field_unit_teacher' => 'right',
      'field_unit_subject' => 'right',
      'field_unit_grade_level' => 'right',
      'field_community_ref' => 'right',
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
  $export['node|unit_plan|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|unit_plan|teacher_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'unit_plan';
  $ds_layout->view_mode = 'teacher_view';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'ds_switch_field',
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
      'bottom' => array(
        19 => 'field_unit_lessons',
      ),
    ),
    'fields' => array(
      'ds_switch_field' => 'top',
      'field_unit_overarching' => 'left',
      'field_unit_conceptual' => 'left',
      'field_unit_nature_of_science' => 'left',
      'field_unit_language_learning' => 'left',
      'field_unit_technical' => 'left',
      'field_unit_assessments' => 'left',
      'field_media_asset' => 'left',
      'field_related_content' => 'left',
      'field_unit_teacher' => 'right',
      'field_unit_subject' => 'right',
      'field_unit_grade_level' => 'right',
      'field_unit_week_of' => 'right',
      'field_unit_unit_length' => 'right',
      'field_unit_class_period_length' => 'right',
      'field_tags' => 'right',
      'field_category' => 'right',
      'field_community_ref' => 'right',
      'og_group_ref' => 'right',
      'field_unit_lessons' => 'bottom',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'unit-plan-body' => 'unit-plan-body',
      ),
      'right' => array(
        'unit-plan-sidebar' => 'unit-plan-sidebar',
      ),
      'bottom' => array(
        'unit-plan-bottom' => 'unit-plan-bottom',
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
