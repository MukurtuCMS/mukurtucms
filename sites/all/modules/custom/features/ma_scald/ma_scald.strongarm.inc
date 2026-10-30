<?php

/**
 * @file
 * ma_scald.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_scald_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimages_generate';
  $strongarm->value = '2';
  $export['dummyimages_generate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimages_service';
  $strongarm->value = 'dummyimage';
  $export['dummyimages_service'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimage_background';
  $strongarm->value = 'cccccc';
  $export['dummyimage_background'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimage_color';
  $strongarm->value = '000000';
  $export['dummyimage_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimage_default_height';
  $strongarm->value = '146';
  $export['dummyimage_default_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimage_default_width';
  $strongarm->value = '220';
  $export['dummyimage_default_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__audio';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'atom' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'ma_colorbox' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
          'ma_scald_search_results' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
          'mukurtu_carousel_thumbnail' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_featured_content' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
          'mukurtu_multi_page_carousel' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_scald_dictionary_media' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
          'mukurtu_scald_media_assets_edit_' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'mukurtu_scald_recording' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'mukurtu_scald_related_items' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
      ),
      'form' => array(
        'redirect' => array(
          'weight' => '8',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__audio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__file';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'atom' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'ma_colorbox' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
          'ma_scald_search_results' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_carousel_thumbnail' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_featured_content' => array(
            'visible' => FALSE,
            'weight' => '2',
          ),
          'mukurtu_multi_page_carousel' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_scald_dictionary_media' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
          'mukurtu_scald_related_items' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
      ),
      'form' => array(
        'redirect' => array(
          'weight' => '9',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__image';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'atom' => array(
          'default' => array(
            'visible' => FALSE,
            'weight' => '3',
          ),
          'ma_colorbox' => array(
            'visible' => FALSE,
            'weight' => '6',
          ),
          'ma_dh_assets' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'ma_scald_search_results' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'mukurtu_browse_by_grid' => array(
            'visible' => FALSE,
            'weight' => '3',
          ),
          'mukurtu_browse_by_grid_7_4' => array(
            'visible' => FALSE,
            'weight' => '3',
          ),
          'mukurtu_carousel_thumbnail' => array(
            'visible' => FALSE,
            'weight' => '3',
          ),
          'mukurtu_featured_content' => array(
            'visible' => FALSE,
            'weight' => '3',
          ),
          'mukurtu_multi_page_carousel' => array(
            'visible' => FALSE,
            'weight' => '3',
          ),
          'mukurtu_scald_banner_image' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_scald_dictionary_media' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_scald_related_items' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'mukurtu_scald_taxonomy_thumbnail' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'mukurtu_scald_thumbnail_image' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'mukurtu_scald_tiny_thumbnail' => array(
            'visible' => FALSE,
            'weight' => '3',
          ),
        ),
      ),
      'form' => array(
        'redirect' => array(
          'weight' => '18',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'ma_dh_assets' => array(
        'custom_settings' => FALSE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__video';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'atom' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'ma_colorbox' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'ma_scald_search_results' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'mukurtu_carousel_thumbnail' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_multi_page_carousel' => array(
            'visible' => FALSE,
            'weight' => '1',
          ),
          'mukurtu_scald_dictionary_media' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'mukurtu_scald_related_items' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
      ),
      'form' => array(
        'redirect' => array(
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__video'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_default_scheme';
  $strongarm->value = 'private';
  $export['file_default_scheme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_public_path';
  $strongarm->value = 'sites/default/files';
  $export['file_public_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_temporary_path';
  $strongarm->value = '/tmp';
  $export['file_temporary_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_scald_authors_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_scald_authors_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_scald_tags_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_scald_tags_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_actions_powers';
  $strongarm->value = array(
    'delete' => 3,
    'edit' => 1,
    'fetch' => 0,
    'view' => 2,
  );
  $export['scald_actions_powers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_always_rebuild';
  $strongarm->value = '1';
  $export['scald_always_rebuild'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_atom_defaults';
  $strongarm->value = array(
    'audio' => (object) array(
      'actions' => 15,
      'description' => '',
      'thumbnail_source' => 'public://atoms/audio.png',
      'upload_type' => 'plupload',
    ),
    'file' => (object) array(
      'actions' => 15,
      'description' => '',
      'thumbnail_source' => 'public://atoms/thumbnail_default.png',
      'upload_type' => 'plupload',
    ),
    'image' => (object) array(
      'actions' => 15,
      'description' => '',
      'thumbnail_source' => 'public://atoms/image.png',
      'upload_type' => 'plupload',
    ),
    'video' => (object) array(
      'actions' => 15,
      'description' => '',
      'thumbnail_source' => 'public://atoms/video.png',
      'upload_type' => 'plupload',
    ),
  );
  $export['scald_atom_defaults'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_author_vocabulary';
  $strongarm->value = 'scald_authors';
  $export['scald_author_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_context_fallbacks';
  $strongarm->value = array(
    '@default' => array(
      0 => 'title',
    ),
  );
  $export['scald_context_fallbacks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_custom_contexts';
  $strongarm->value = array(
    'ma_colorbox' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'ma_colorbox',
      'parseable' => TRUE,
      'provider' => 'scald',
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Colorbox',
    ),
    'ma_scald_search_results' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'ma_scald_search_results',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Search Results',
    ),
    'mukurtu_browse_by_grid' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_browse_by_grid',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Browse By Grid',
    ),
    'mukurtu_browse_by_grid_7_4' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_browse_by_grid_7_4',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Browse By Grid 7:4',
    ),
    'mukurtu_carousel_thumbnail' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_carousel_thumbnail',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Carousel Thumbnail',
    ),
    'mukurtu_featured_content' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_featured_content',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Featured Content',
    ),
    'mukurtu_multi_page_carousel' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_multi_page_carousel',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Multi-page Carousel',
    ),
    'mukurtu_scald_banner_image' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_banner_image',
      'parseable' => TRUE,
      'provider' => 'scald',
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Banner Image',
    ),
    'mukurtu_scald_dictionary_media' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_dictionary_media',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Dictionary Media',
    ),
    'mukurtu_scald_media_assets_edit_' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_media_assets_edit_',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Media Assets Edit Field',
    ),
    'mukurtu_scald_recording' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_recording',
      'parseable' => TRUE,
      'provider' => 'scald',
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Recording',
    ),
    'mukurtu_scald_related_items' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_related_items',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Related Items',
    ),
    'mukurtu_scald_taxonomy_thumbnail' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_taxonomy_thumbnail',
      'parseable' => TRUE,
      'provider' => 'scald',
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Taxonomy Thumbnail',
    ),
    'mukurtu_scald_thumbnail_image' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_thumbnail_image',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Thumbnail Image',
    ),
    'mukurtu_scald_tiny_thumbnail' => array(
      'description' => '',
      'formats' => array(),
      'name' => 'mukurtu_scald_tiny_thumbnail',
      'parseable' => TRUE,
      'render_language' => 'XHTML',
      'title' => 'Mukurtu Scald Tiny Thumbnail',
    ),
  );
  $export['scald_custom_contexts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_tags_vocabulary';
  $strongarm->value = 'scald_tags';
  $export['scald_tags_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_video_upload_location';
  $strongarm->value = 'public://atoms/video/';
  $export['scald_video_upload_location'] = $strongarm;

  return $export;
}
