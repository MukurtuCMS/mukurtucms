<?php

/**
 * @file
 * ma_base_theme.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function ma_base_theme_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__component_media_item__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['application__component_media_item__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__component_media_item__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__component_media_item__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__component_media_item__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__component_media_item__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__component_media_item__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['application__component_media_item__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['application__component_media_item__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__component_media_item__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['application__component_media_item__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_field_file_default';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_field_file_rendered';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['application__default__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_field_mediaelement_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__default__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__default__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['application__default__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__media_oembed';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['application__default__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__default__media_oembed_thumbnail';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['application__default__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_field_file_default';
  $file_display->weight = -45;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__full_content__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_field_file_rendered';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'media_original',
  );
  $export['application__full_content__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_field_file_table';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__full_content__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_field_file_url_plain';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__full_content__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_field_media_large_icon';
  $file_display->weight = -44;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__full_content__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__full_content__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_field_mediaelement_video';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '460',
    'height' => '460',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['application__full_content__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'large',
  );
  $export['application__full_content__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__media_oembed';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
    'wmode' => 'opaque',
  );
  $export['application__full_content__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__full_content__media_oembed_thumbnail';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
  );
  $export['application__full_content__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_field_file_default';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__media_large__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_field_file_rendered';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['application__media_large__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_large__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_field_file_url_plain';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_large__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__media_large__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_field_mediaelement_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_large__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_field_mediaelement_video';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_large__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['application__media_large__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__media_oembed';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['application__media_large__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_large__media_oembed_thumbnail';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
  );
  $export['application__media_large__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['application__media_original__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_original__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_original__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['application__media_original__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['application__media_original__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_original__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
  );
  $export['application__media_original__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_field_file_default';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__media_preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_field_file_rendered';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['application__media_preview__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_field_file_table';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_field_file_url_plain';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__media_preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_field_mediaelement_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_preview__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_preview__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['application__media_preview__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__media_oembed';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['application__media_preview__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_preview__media_oembed_thumbnail';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
  );
  $export['application__media_preview__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_field_file_default';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__media_small__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_field_file_rendered';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'media_original',
  );
  $export['application__media_small__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_field_file_table';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_small__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_field_file_url_plain';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['application__media_small__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['application__media_small__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_field_mediaelement_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_small__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['application__media_small__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['application__media_small__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__media_oembed';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['application__media_small__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'application__media_small__media_oembed_thumbnail';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['application__media_small__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__component_media_item__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_field_file_rendered';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['audio__component_media_item__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__component_media_item__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__component_media_item__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__component_media_item__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__component_media_item__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_field_mediaelement_video';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__component_media_item__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__file_image';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['audio__component_media_item__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__media_oembed';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['audio__component_media_item__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__component_media_item__media_oembed_thumbnail';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['audio__component_media_item__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__full_content__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_field_file_rendered';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'file_view_mode' => 'media_original',
  );
  $export['audio__full_content__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_field_file_table';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__full_content__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_field_file_url_plain';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__full_content__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__full_content__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_field_mediaelement_audio';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '580',
    'height' => '30',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['audio__full_content__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__full_content__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['audio__full_content__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__media_oembed';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '580',
    'height' => '50',
    'wmode' => 'transparent',
  );
  $export['audio__full_content__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__full_content__media_oembed_thumbnail';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
  );
  $export['audio__full_content__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__component_media_item__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['default__component_media_item__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__component_media_item__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__component_media_item__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__component_media_item__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__component_media_item__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__component_media_item__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['default__component_media_item__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['default__component_media_item__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__component_media_item__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
  );
  $export['default__component_media_item__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['default__default__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__full_content__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__full_content__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__full_content__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__full_content__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__full_content__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__full_content__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['default__full_content__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__media_oembed';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
    'wmode' => 'transparent',
  );
  $export['default__full_content__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__full_content__media_oembed_thumbnail';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
  );
  $export['default__full_content__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['default__media_small__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['default__media_small__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__component_media_item__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_field_file_rendered';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['image__component_media_item__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__component_media_item__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__component_media_item__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__component_media_item__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__component_media_item__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_field_mediaelement_video';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__component_media_item__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__file_image';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['image__component_media_item__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__media_oembed';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['image__component_media_item__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__component_media_item__media_oembed_thumbnail';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['image__component_media_item__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_field_file_default';
  $file_display->weight = -44;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__full_content__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_field_file_rendered';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['image__full_content__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__full_content__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__full_content__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__full_content__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__full_content__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__full_content__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__file_image';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'digital_heritage_full_content',
  );
  $export['image__full_content__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__media_oembed';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '',
    'wmode' => 'transparent',
  );
  $export['image__full_content__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full_content__media_oembed_thumbnail';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '',
    'height' => '',
  );
  $export['image__full_content__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__media_oembed';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '',
    'wmode' => 'opaque',
  );
  $export['image__media_small__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__media_oembed_thumbnail';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['image__media_small__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__component_media_item__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['text__component_media_item__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__component_media_item__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__component_media_item__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['text__component_media_item__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__component_media_item__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__component_media_item__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['text__component_media_item__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['text__component_media_item__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__component_media_item__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
  );
  $export['text__component_media_item__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_field_file_default';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['text__full_content__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_field_file_rendered';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['text__full_content__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__full_content__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__full_content__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['text__full_content__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_field_mediaelement_audio';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__full_content__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__full_content__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['text__full_content__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__media_oembed';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['text__full_content__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__full_content__media_oembed_thumbnail';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '460',
    'height' => '460',
  );
  $export['text__full_content__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__media_oembed';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['text__media_small__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__media_oembed_thumbnail';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['text__media_small__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__component_media_item__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_field_file_rendered';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['video__component_media_item__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__component_media_item__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_field_file_url_plain';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__component_media_item__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__component_media_item__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__component_media_item__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_field_mediaelement_video';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__component_media_item__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['video__component_media_item__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__media_oembed';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['video__component_media_item__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__component_media_item__media_oembed_thumbnail';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
  );
  $export['video__component_media_item__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__full_content__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'file_view_mode' => 'media_original',
  );
  $export['video__full_content__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__full_content__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_field_file_url_plain';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__full_content__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__full_content__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__full_content__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_field_mediaelement_video';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '580',
    'height' => '580',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['video__full_content__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__full_content__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__media_oembed';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '580',
    'height' => '580',
    'wmode' => 'transparent',
  );
  $export['video__full_content__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__full_content__media_oembed_thumbnail';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '580',
    'height' => '580',
  );
  $export['video__full_content__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__media_oembed';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['video__media_small__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__media_oembed_thumbnail';
  $file_display->weight = -44;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['video__media_small__media_oembed_thumbnail'] = $file_display;

  return $export;
}
