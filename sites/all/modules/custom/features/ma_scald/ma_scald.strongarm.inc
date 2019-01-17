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
    'view_modes' => array(
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(
        'atom' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'ma_colorbox' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'ma_scald_search_results' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'mukurtu_scald_related_items' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_dictionary_media' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'mukurtu_scald_recording' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_media_assets_edit_' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_featured_content' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'mukurtu_carousel_thumbnail' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'mukurtu_multi_page_carousel' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__audio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__file';
  $strongarm->value = array(
    'view_modes' => array(
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(
        'atom' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'ma_colorbox' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'ma_scald_search_results' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'mukurtu_scald_related_items' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_dictionary_media' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'mukurtu_featured_content' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'mukurtu_carousel_thumbnail' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'mukurtu_multi_page_carousel' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__image';
  $strongarm->value = array(
    'view_modes' => array(
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ma_dh_assets' => array(
        'custom_settings' => FALSE,
      ),
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => TRUE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '18',
        ),
      ),
      'display' => array(
        'atom' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'ma_dh_assets' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'ma_colorbox' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'ma_scald_search_results' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_banner_image' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'mukurtu_scald_thumbnail_image' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_related_items' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_dictionary_media' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'mukurtu_scald_taxonomy_thumbnail' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'mukurtu_featured_content' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'mukurtu_browse_by_grid' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'mukurtu_browse_by_grid_7_4' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'mukurtu_scald_tiny_thumbnail' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'mukurtu_carousel_thumbnail' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'mukurtu_multi_page_carousel' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__video';
  $strongarm->value = array(
    'view_modes' => array(
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ma_colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ma_scald_search_results' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_banner_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_related_items' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_thumbnail_image' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_media_assets_edit_' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_dictionary_media' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_carousel_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'mukurtu_scald_recording' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_taxonomy_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_featured_content' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_browse_by_grid_7_4' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_scald_tiny_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_record_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'person_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'mukurtu_multi_page_carousel' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(
        'atom' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'ma_colorbox' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'ma_scald_search_results' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_related_items' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_scald_dictionary_media' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'mukurtu_carousel_thumbnail' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'mukurtu_multi_page_carousel' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
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
    'fetch' => 0,
    'edit' => 1,
    'view' => 2,
    'delete' => 3,
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
    'video' => (object) array(
      'actions' => 15,
      'upload_type' => 'plupload',
      'description' => '',
      'thumbnail_source' => 'public://atoms/video.png',
    ),
    'image' => (object) array(
      'thumbnail_source' => 'public://atoms/image.png',
      'description' => '',
      'upload_type' => 'plupload',
      'actions' => 15,
    ),
    'audio' => (object) array(
      'thumbnail_source' => 'public://atoms/audio.png',
      'description' => '',
      'upload_type' => 'plupload',
      'actions' => 15,
    ),
    'file' => (object) array(
      'thumbnail_source' => 'public://atoms/thumbnail_default.png',
      'description' => '',
      'upload_type' => 'plupload',
      'actions' => 15,
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
      'name' => 'ma_colorbox',
      'title' => 'Mukurtu Scald Colorbox',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
      'provider' => 'scald',
    ),
    'ma_scald_search_results' => array(
      'name' => 'ma_scald_search_results',
      'title' => 'Mukurtu Scald Search Results',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_scald_banner_image' => array(
      'name' => 'mukurtu_scald_banner_image',
      'title' => 'Mukurtu Scald Banner Image',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
      'provider' => 'scald',
    ),
    'mukurtu_scald_thumbnail_image' => array(
      'name' => 'mukurtu_scald_thumbnail_image',
      'title' => 'Mukurtu Scald Thumbnail Image',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_scald_media_assets_edit_' => array(
      'name' => 'mukurtu_scald_media_assets_edit_',
      'title' => 'Mukurtu Scald Media Assets Edit Field',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_scald_related_items' => array(
      'name' => 'mukurtu_scald_related_items',
      'title' => 'Mukurtu Scald Related Items',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_scald_dictionary_media' => array(
      'name' => 'mukurtu_scald_dictionary_media',
      'title' => 'Mukurtu Scald Dictionary Media',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_scald_recording' => array(
      'name' => 'mukurtu_scald_recording',
      'title' => 'Mukurtu Scald Recording',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
      'provider' => 'scald',
    ),
    'mukurtu_scald_taxonomy_thumbnail' => array(
      'name' => 'mukurtu_scald_taxonomy_thumbnail',
      'title' => 'Mukurtu Scald Taxonomy Thumbnail',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
      'provider' => 'scald',
    ),
    'mukurtu_featured_content' => array(
      'name' => 'mukurtu_featured_content',
      'title' => 'Mukurtu Featured Content',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_browse_by_grid' => array(
      'name' => 'mukurtu_browse_by_grid',
      'title' => 'Mukurtu Browse By Grid',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_browse_by_grid_7_4' => array(
      'name' => 'mukurtu_browse_by_grid_7_4',
      'title' => 'Mukurtu Browse By Grid 7:4',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_scald_tiny_thumbnail' => array(
      'name' => 'mukurtu_scald_tiny_thumbnail',
      'title' => 'Mukurtu Scald Tiny Thumbnail',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_carousel_thumbnail' => array(
      'name' => 'mukurtu_carousel_thumbnail',
      'title' => 'Mukurtu Carousel Thumbnail',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'mukurtu_multi_page_carousel' => array(
      'name' => 'mukurtu_multi_page_carousel',
      'title' => 'Mukurtu Multi-page Carousel',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
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
