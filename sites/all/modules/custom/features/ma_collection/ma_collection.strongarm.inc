<?php

/**
 * @file
 * ma_collection.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_collection_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_collection';
  $strongarm->value = 0;
  $export['comment_anonymous_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_personal_collection';
  $strongarm->value = 0;
  $export['comment_anonymous_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_collection';
  $strongarm->value = '2';
  $export['comment_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_collection';
  $strongarm->value = 1;
  $export['comment_default_mode_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_personal_collection';
  $strongarm->value = 1;
  $export['comment_default_mode_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_collection';
  $strongarm->value = '50';
  $export['comment_default_per_page_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_personal_collection';
  $strongarm->value = '50';
  $export['comment_default_per_page_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_collection';
  $strongarm->value = 1;
  $export['comment_form_location_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_personal_collection';
  $strongarm->value = 1;
  $export['comment_form_location_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_personal_collection';
  $strongarm->value = '2';
  $export['comment_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_collection';
  $strongarm->value = '1';
  $export['comment_preview_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_personal_collection';
  $strongarm->value = '1';
  $export['comment_preview_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_collection';
  $strongarm->value = 1;
  $export['comment_subject_field_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_personal_collection';
  $strongarm->value = 1;
  $export['comment_subject_field_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_collection';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_personal_collection';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_collection';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_personal_collection';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_collection';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_personal_collection';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__collection';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'path' => array(
          'weight' => '2',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'title' => array(
          'weight' => '3',
        ),
      ),
    ),
    'view_modes' => array(
      'collections_browse' => array(
        'custom_settings' => TRUE,
      ),
      'community_record' => array(
        'custom_settings' => FALSE,
      ),
      'dictionary_word_summary' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'featured_content' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'map_popup' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_mobile' => array(
        'custom_settings' => TRUE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'related_person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'teacher_view' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'thumbed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__personal_collection';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(
      'collections_browse' => array(
        'custom_settings' => FALSE,
      ),
      'community_record' => array(
        'custom_settings' => FALSE,
      ),
      'dictionary_word_summary' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'featured_content' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'map_popup' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_mobile' => array(
        'custom_settings' => TRUE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'related_person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'teacher_view' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'thumbed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_collection';
  $strongarm->value = '0';
  $export['language_content_type_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_personal_collection';
  $strongarm->value = '0';
  $export['language_content_type_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_collection';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_personal_collection';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_collection';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_personal_collection';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_collection';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_personal_collection';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_collection';
  $strongarm->value = '1';
  $export['node_preview_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_personal_collection';
  $strongarm->value = '1';
  $export['node_preview_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_collection';
  $strongarm->value = 1;
  $export['node_submitted_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_personal_collection';
  $strongarm->value = 1;
  $export['node_submitted_personal_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_collection_pattern';
  $strongarm->value = 'collection/[node:title]';
  $export['pathauto_node_collection_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_personal_collection_pattern';
  $strongarm->value = 'personal-collection/[node:title]';
  $export['pathauto_node_personal_collection_pattern'] = $strongarm;

  return $export;
}
