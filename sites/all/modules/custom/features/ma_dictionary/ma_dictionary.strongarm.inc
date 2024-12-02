<?php

/**
 * @file
 * ma_dictionary.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_dictionary_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_dictionary_word';
  $strongarm->value = 0;
  $export['comment_anonymous_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_language_community';
  $strongarm->value = 0;
  $export['comment_anonymous_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_word_list';
  $strongarm->value = 0;
  $export['comment_anonymous_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_dictionary_word';
  $strongarm->value = 1;
  $export['comment_default_mode_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_language_community';
  $strongarm->value = 1;
  $export['comment_default_mode_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_word_list';
  $strongarm->value = 1;
  $export['comment_default_mode_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_dictionary_word';
  $strongarm->value = '50';
  $export['comment_default_per_page_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_language_community';
  $strongarm->value = '50';
  $export['comment_default_per_page_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_word_list';
  $strongarm->value = '50';
  $export['comment_default_per_page_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_dictionary_word';
  $strongarm->value = '0';
  $export['comment_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_dictionary_word';
  $strongarm->value = 1;
  $export['comment_form_location_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_language_community';
  $strongarm->value = 1;
  $export['comment_form_location_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_word_list';
  $strongarm->value = 1;
  $export['comment_form_location_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_language_community';
  $strongarm->value = '1';
  $export['comment_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_dictionary_word';
  $strongarm->value = '1';
  $export['comment_preview_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_language_community';
  $strongarm->value = '1';
  $export['comment_preview_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_word_list';
  $strongarm->value = '1';
  $export['comment_preview_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_dictionary_word';
  $strongarm->value = 1;
  $export['comment_subject_field_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_language_community';
  $strongarm->value = 1;
  $export['comment_subject_field_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_word_list';
  $strongarm->value = 1;
  $export['comment_subject_field_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_word_list';
  $strongarm->value = '2';
  $export['comment_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'community_tags_display_dictionary_word';
  $strongarm->value = '0';
  $export['community_tags_display_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__dictionary_word';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'dictionary_word_navigation' => array(
          'default' => array(
            'visible' => FALSE,
            'weight' => '18',
          ),
          'dictionary_word_summary' => array(
            'visible' => FALSE,
            'weight' => '18',
          ),
          'featured_content' => array(
            'visible' => FALSE,
            'weight' => '18',
          ),
          'mukurtu_mobile' => array(
            'visible' => FALSE,
            'weight' => '18',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '6',
          ),
        ),
        'found_in_dictionary_word' => array(
          'default' => array(
            'visible' => FALSE,
            'weight' => '23',
          ),
          'dictionary_word_summary' => array(
            'visible' => FALSE,
            'weight' => '23',
          ),
          'featured_content' => array(
            'visible' => FALSE,
            'weight' => '23',
          ),
          'mukurtu_mobile' => array(
            'visible' => FALSE,
            'weight' => '23',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '7',
          ),
        ),
      ),
      'form' => array(
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '24',
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
        'custom_settings' => TRUE,
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
  $export['field_bundle_settings_node__dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__language_community';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '2',
        ),
      ),
    ),
    'view_modes' => array(),
  );
  $export['field_bundle_settings_node__language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__word_list';
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
          'weight' => '1',
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
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
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
  $export['field_bundle_settings_node__word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_paragraphs_item__dictionary_word_bundle';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'redirect' => array(
          'weight' => '2',
        ),
      ),
    ),
    'view_modes' => array(
      'dictionary_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'dictionary_word_summary' => array(
        'custom_settings' => TRUE,
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
      'mukurtu_mobile' => array(
        'custom_settings' => TRUE,
      ),
      'paragraphs_editor_preview' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'word_entry_in_word_list' => array(
        'custom_settings' => TRUE,
      ),
      'word_entry_search_results' => array(
        'custom_settings' => TRUE,
      ),
    ),
  );
  $export['field_bundle_settings_paragraphs_item__dictionary_word_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_dictionary_word';
  $strongarm->value = '0';
  $export['language_content_type_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_language_community';
  $strongarm->value = '0';
  $export['language_content_type_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_word_list';
  $strongarm->value = '0';
  $export['language_content_type_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_dictionary_word';
  $strongarm->value = array();
  $export['menu_options_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_language_community';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_word_list';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_dictionary_word';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_language_community';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_word_list';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_dictionary_word';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_language_community';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_word_list';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_dictionary_word';
  $strongarm->value = '1';
  $export['node_preview_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_language_community';
  $strongarm->value = '1';
  $export['node_preview_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_word_list';
  $strongarm->value = '1';
  $export['node_preview_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_dictionary_word';
  $strongarm->value = 0;
  $export['node_submitted_dictionary_word'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_language_community';
  $strongarm->value = 1;
  $export['node_submitted_language_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_word_list';
  $strongarm->value = 1;
  $export['node_submitted_word_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_dictionary_word_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_dictionary_word_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_dictionary_word_pattern';
  $strongarm->value = 'dictionary-word/[node:title]';
  $export['pathauto_node_dictionary_word_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_dictionary_word_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_dictionary_word_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_language_community_pattern';
  $strongarm->value = 'language-community/[node:title]';
  $export['pathauto_node_language_community_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_word_list_pattern';
  $strongarm->value = 'word-list/[node:title]';
  $export['pathauto_node_word_list_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_language_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_language_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_part_of_speech_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_part_of_speech_pattern'] = $strongarm;

  return $export;
}
