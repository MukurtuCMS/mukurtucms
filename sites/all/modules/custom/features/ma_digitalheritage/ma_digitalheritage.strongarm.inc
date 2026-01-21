<?php

/**
 * @file
 * ma_digitalheritage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_digitalheritage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_digital_heritage';
  $strongarm->value = 'edit-workflow';
  $export['additional_settings__active_tab_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_digital_heritage';
  $strongarm->value = '0';
  $export['comment_anonymous_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_digital_heritage';
  $strongarm->value = 1;
  $export['comment_default_mode_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_digital_heritage';
  $strongarm->value = '50';
  $export['comment_default_per_page_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_digital_heritage';
  $strongarm->value = '2';
  $export['comment_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_digital_heritage';
  $strongarm->value = 1;
  $export['comment_form_location_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_digital_heritage';
  $strongarm->value = '1';
  $export['comment_preview_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_digital_heritage';
  $strongarm->value = 1;
  $export['comment_subject_field_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'community_tags_display_digital_heritage';
  $strongarm->value = '0';
  $export['community_tags_display_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'community_tags_vocabularies';
  $strongarm->value = array(
    'tags' => array(
      'is_enabled' => 1,
      'types' => array(
        'article' => array(
          'display_handler' => 'links',
          'is_valid' => TRUE,
          'opmode' => 1,
        ),
        'dictionary_word' => array(
          'display_handler' => 'none',
          'is_valid' => TRUE,
          'opmode' => 0,
        ),
        'digital_heritage' => array(
          'display_handler' => 'links',
          'is_valid' => TRUE,
          'opmode' => 2,
        ),
      ),
    ),
  );
  $export['community_tags_vocabularies'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_digital_heritage';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_digital_heritage';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_digital_heritage';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_digital_heritage';
  $strongarm->value = 1;
  $export['enable_revisions_page_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__digital_heritage';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '2',
        ),
      ),
    ),
    'view_modes' => array(
      'browse_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'collections_browse' => array(
        'custom_settings' => FALSE,
      ),
      'community_record' => array(
        'custom_settings' => TRUE,
      ),
      'dictionary_word_summary' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
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
        'custom_settings' => TRUE,
      ),
      'mukurtu_mobile' => array(
        'custom_settings' => TRUE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'related_items_teaser_map_popup' => array(
        'custom_settings' => TRUE,
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
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => TRUE,
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
  $export['field_bundle_settings_node__digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ft-default';
  $strongarm->value = 'theme_ds_field_minimal';
  $export['ft-default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ft-kill-colon';
  $strongarm->value = 0;
  $export['ft-kill-colon'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_digital_heritage';
  $strongarm->value = '0';
  $export['language_content_type_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_digital_heritage';
  $strongarm->value = array();
  $export['menu_options_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_digital_heritage';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_digital_heritage';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_digital_heritage';
  $strongarm->value = '1';
  $export['node_preview_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_digital_heritage';
  $strongarm->value = 1;
  $export['node_submitted_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_animate_in_owlcarousel_settings_multipage';
  $strongarm->value = '';
  $export['owlcarousel_animate_in_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_animate_out_owlcarousel_settings_multipage';
  $strongarm->value = '';
  $export['owlcarousel_animate_out_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_autoplay_hover_pause_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_autoplay_hover_pause_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_autoplay_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_autoplay_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_autoplay_speed_owlcarousel_settings_multipage';
  $strongarm->value = '0';
  $export['owlcarousel_autoplay_speed_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_autoplay_timeout_owlcarousel_settings_multipage';
  $strongarm->value = '5000';
  $export['owlcarousel_autoplay_timeout_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_auto_width_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_auto_width_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_callbacks_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_callbacks_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_center_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_center_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_dots_container_owlcarousel_settings_multipage';
  $strongarm->value = '';
  $export['owlcarousel_dots_container_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_dots_each_owlcarousel_settings_multipage';
  $strongarm->value = '0';
  $export['owlcarousel_dots_each_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_dots_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_dots_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_dots_speed_owlcarousel_settings_multipage';
  $strongarm->value = '0';
  $export['owlcarousel_dots_speed_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_dot_data_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_dot_data_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_drag_end_speed_owlcarousel_settings_multipage';
  $strongarm->value = '0';
  $export['owlcarousel_drag_end_speed_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_fallback_easing_owlcarousel_settings_multipage';
  $strongarm->value = 'swing';
  $export['owlcarousel_fallback_easing_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_fluid_speed_owlcarousel_settings_multipage';
  $strongarm->value = '250';
  $export['owlcarousel_fluid_speed_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_free_drag_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_free_drag_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_info_owlcarousel_settings_multipage';
  $strongarm->value = '';
  $export['owlcarousel_info_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_owlcarousel_settings_multipage';
  $strongarm->value = '7';
  $export['owlcarousel_items_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_item_element_owlcarousel_settings_multipage';
  $strongarm->value = 'div';
  $export['owlcarousel_item_element_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_lazy_content_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_lazy_content_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_lazy_load_owlcarousel_settings_multipage';
  $strongarm->value = 1;
  $export['owlcarousel_lazy_load_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_loop_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_loop_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_margin_owlcarousel_settings_multipage';
  $strongarm->value = '10';
  $export['owlcarousel_margin_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_merge_fit_owlcarousel_settings_multipage';
  $strongarm->value = 1;
  $export['owlcarousel_merge_fit_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_merge_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_merge_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_mouse_drag_owlcarousel_settings_multipage';
  $strongarm->value = 1;
  $export['owlcarousel_mouse_drag_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_nav_container_owlcarousel_settings_multipage';
  $strongarm->value = '';
  $export['owlcarousel_nav_container_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_nav_owlcarousel_settings_multipage';
  $strongarm->value = 1;
  $export['owlcarousel_nav_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_nav_rewind_owlcarousel_settings_multipage';
  $strongarm->value = 1;
  $export['owlcarousel_nav_rewind_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_nav_speed_owlcarousel_settings_multipage';
  $strongarm->value = '0';
  $export['owlcarousel_nav_speed_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_nav_text_owlcarousel_settings_multipage';
  $strongarm->value = array(
    0 => '< previous',
    1 => 'next >',
  );
  $export['owlcarousel_nav_text_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_nested_item_selector_owlcarousel_settings_multipage';
  $strongarm->value = '';
  $export['owlcarousel_nested_item_selector_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_pull_drag_owlcarousel_settings_multipage';
  $strongarm->value = 1;
  $export['owlcarousel_pull_drag_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_responsive_base_element_owlcarousel_settings_multipage';
  $strongarm->value = 'window';
  $export['owlcarousel_responsive_base_element_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_responsive_class_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_responsive_class_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_responsive_refresh_rate_owlcarousel_settings_multipage';
  $strongarm->value = '200';
  $export['owlcarousel_responsive_refresh_rate_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_settings_multipage';
  $strongarm->value = 'multipage';
  $export['owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_slide_by_owlcarousel_settings_multipage';
  $strongarm->value = '1';
  $export['owlcarousel_slide_by_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_smart_speed_owlcarousel_settings_multipage';
  $strongarm->value = '250';
  $export['owlcarousel_smart_speed_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_stage_element_owlcarousel_settings_multipage';
  $strongarm->value = 'div';
  $export['owlcarousel_stage_element_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_stage_padding_owlcarousel_settings_multipage';
  $strongarm->value = '0';
  $export['owlcarousel_stage_padding_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_start_position_owlcarousel_settings_multipage';
  $strongarm->value = '0';
  $export['owlcarousel_start_position_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_touch_drag_owlcarousel_settings_multipage';
  $strongarm->value = 1;
  $export['owlcarousel_touch_drag_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_url_hash_listener_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_url_hash_listener_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_video_height_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_video_height_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_video_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_video_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_video_width_owlcarousel_settings_multipage';
  $strongarm->value = 0;
  $export['owlcarousel_video_width_owlcarousel_settings_multipage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_digital_heritage_pattern';
  $strongarm->value = 'digital-heritage/[node:title]';
  $export['pathauto_node_digital_heritage_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_digital_heritage';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_digital_heritage';
  $strongarm->value = 0;
  $export['show_diff_inline_digital_heritage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_digital_heritage';
  $strongarm->value = 1;
  $export['show_preview_changes_digital_heritage'] = $strongarm;

  return $export;
}
