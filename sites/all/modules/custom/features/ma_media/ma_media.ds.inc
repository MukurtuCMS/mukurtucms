<?php
/**
 * @file
 * ma_media.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_media_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|audio|collab_doc_attachments';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'collab_doc_attachments';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_media_title',
        1 => 'field_media_description',
        2 => 'field_folder',
        3 => 'field_tags',
        4 => 'file',
      ),
    ),
    'fields' => array(
      'field_media_title' => 'ds_content',
      'field_media_description' => 'ds_content',
      'field_folder' => 'ds_content',
      'field_tags' => 'ds_content',
      'file' => 'ds_content',
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
  $export['file|audio|collab_doc_attachments'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|document|collab_doc_attachments';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'collab_doc_attachments';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
      ),
    ),
    'fields' => array(
      'file' => 'ds_content',
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
  $export['file|document|collab_doc_attachments'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|collab_doc_attachments';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'collab_doc_attachments';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_media_title',
        1 => 'field_media_description',
        2 => 'field_folder',
        3 => 'field_tags',
        4 => 'field_exif_datetime',
        5 => 'field_exif_artist',
        6 => 'field_exif_exposuretime',
        7 => 'field_aperturevalue',
        8 => 'field_iptc_headline',
        9 => 'field_gps_latitude',
        10 => 'field_gps_longitude',
        11 => 'field_gps_altitude',
        12 => 'field_caption',
        13 => 'field_iptc_copyright',
        14 => 'field_xmp_rights',
        15 => 'field_iptc_sublocation',
        16 => 'field_xmp_creator',
        17 => 'field_iptc_keywords',
        18 => 'file',
      ),
    ),
    'fields' => array(
      'field_media_title' => 'ds_content',
      'field_media_description' => 'ds_content',
      'field_folder' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_exif_datetime' => 'ds_content',
      'field_exif_artist' => 'ds_content',
      'field_exif_exposuretime' => 'ds_content',
      'field_aperturevalue' => 'ds_content',
      'field_iptc_headline' => 'ds_content',
      'field_gps_latitude' => 'ds_content',
      'field_gps_longitude' => 'ds_content',
      'field_gps_altitude' => 'ds_content',
      'field_caption' => 'ds_content',
      'field_iptc_copyright' => 'ds_content',
      'field_xmp_rights' => 'ds_content',
      'field_iptc_sublocation' => 'ds_content',
      'field_xmp_creator' => 'ds_content',
      'field_iptc_keywords' => 'ds_content',
      'file' => 'ds_content',
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
  $export['file|image|collab_doc_attachments'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|video|collab_doc_attachments';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'collab_doc_attachments';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_media_title',
        1 => 'field_media_description',
        2 => 'field_folder',
        3 => 'field_tags',
        4 => 'file',
      ),
    ),
    'fields' => array(
      'field_media_title' => 'ds_content',
      'field_media_description' => 'ds_content',
      'field_folder' => 'ds_content',
      'field_tags' => 'ds_content',
      'file' => 'ds_content',
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
  $export['file|video|collab_doc_attachments'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_media_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'collab_doc_attachments';
  $ds_view_mode->label = 'Collab Doc Attachments';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['collab_doc_attachments'] = $ds_view_mode;

  return $export;
}
