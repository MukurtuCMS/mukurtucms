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
  $ds_fieldsetting->id = 'node|unit_plan|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'unit_plan';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|unit_plan|default'] = $ds_fieldsetting;

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
      ),
      'left' => array(
        1 => 'field_unit_overarching',
        2 => 'field_unit_conceptual',
        3 => 'field_unit_nature_of_science',
        4 => 'field_unit_language_learning',
        5 => 'field_unit_technical',
        6 => 'field_unit_assessments',
        7 => 'field_media_asset',
        8 => 'field_collection',
        9 => 'field_dictionary_word_related_dh',
        10 => 'field_related_dictionary_words',
        11 => 'field_word_list',
      ),
      'right' => array(
        12 => 'field_unit_teacher',
        13 => 'field_unit_subject',
        14 => 'field_unit_grade_level',
        15 => 'field_unit_week_of',
        16 => 'field_unit_unit_length',
        17 => 'field_unit_class_period_length',
        18 => 'field_community_ref',
        19 => 'og_group_ref',
      ),
      'bottom' => array(
        20 => 'field_unit_lessons',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_unit_overarching' => 'left',
      'field_unit_conceptual' => 'left',
      'field_unit_nature_of_science' => 'left',
      'field_unit_language_learning' => 'left',
      'field_unit_technical' => 'left',
      'field_unit_assessments' => 'left',
      'field_media_asset' => 'left',
      'field_collection' => 'left',
      'field_dictionary_word_related_dh' => 'left',
      'field_related_dictionary_words' => 'left',
      'field_word_list' => 'left',
      'field_unit_teacher' => 'right',
      'field_unit_subject' => 'right',
      'field_unit_grade_level' => 'right',
      'field_unit_week_of' => 'right',
      'field_unit_unit_length' => 'right',
      'field_unit_class_period_length' => 'right',
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
        4 => 'title',
        5 => 'field_unit_overarching',
        6 => 'field_unit_conceptual',
        7 => 'field_unit_teacher',
        8 => 'field_unit_nature_of_science',
        9 => 'field_unit_subject',
        10 => 'field_unit_grade_level',
        11 => 'field_unit_language_learning',
        12 => 'field_unit_week_of',
        13 => 'field_unit_technical',
        14 => 'field_unit_assessments',
        15 => 'field_unit_unit_length',
        16 => 'field_unit_class_period_length',
        17 => 'field_media_asset',
        18 => 'og_group_ref',
        19 => 'field_collection',
        20 => 'group_base',
        21 => 'group_loa',
        22 => 'field_dictionary_word_related_dh',
        23 => 'field_related_dictionary_words',
        24 => 'group_lessons',
        25 => 'field_word_list',
        26 => 'field_unit_lessons',
      ),
      'hidden' => array(
        2 => 'path',
        3 => 'redirect',
        27 => 'field_community_ref',
        28 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'group_tabs' => 'ds_content',
      'path' => 'hidden',
      'redirect' => 'hidden',
      'title' => 'ds_content',
      'field_unit_overarching' => 'ds_content',
      'field_unit_conceptual' => 'ds_content',
      'field_unit_teacher' => 'ds_content',
      'field_unit_nature_of_science' => 'ds_content',
      'field_unit_subject' => 'ds_content',
      'field_unit_grade_level' => 'ds_content',
      'field_unit_language_learning' => 'ds_content',
      'field_unit_week_of' => 'ds_content',
      'field_unit_technical' => 'ds_content',
      'field_unit_assessments' => 'ds_content',
      'field_unit_unit_length' => 'ds_content',
      'field_unit_class_period_length' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'field_collection' => 'ds_content',
      'group_base' => 'ds_content',
      'group_loa' => 'ds_content',
      'field_dictionary_word_related_dh' => 'ds_content',
      'field_related_dictionary_words' => 'ds_content',
      'group_lessons' => 'ds_content',
      'field_word_list' => 'ds_content',
      'field_unit_lessons' => 'ds_content',
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
  $export['node|unit_plan|form'] = $ds_layout;

  return $export;
}
