<?php
/**
 * @file
 * ma_media.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function ma_media_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_file_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'autoplay' => 0,
    'loop' => 0,
    'preload' => '',
    'multiple_file_behavior' => 'tags',
  );
  $export['audio__collab_doc_attachments__file_field_file_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__collab_doc_attachments__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['audio__collab_doc_attachments__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__collab_doc_attachments__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__collab_doc_attachments__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_filehash_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'algo' => 'sha256',
  );
  $export['audio__collab_doc_attachments__file_field_filehash_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['audio__collab_doc_attachments__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '30',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['audio__collab_doc_attachments__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__collab_doc_attachments__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__file_field_services';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'data_element_key' => '',
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  $export['audio__collab_doc_attachments__file_field_services'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => '',
  );
  $export['audio__collab_doc_attachments__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__oembed_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
    'alt' => '[file:field-file-image-alt-text]',
    'title' => '[file:field-file-image-title-text]',
  );
  $export['audio__collab_doc_attachments__oembed_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__collab_doc_attachments__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '',
  );
  $export['audio__collab_doc_attachments__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_field_file_default';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_field_file_rendered';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['audio__default__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_field_file_url_plain';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_field_mediaelement_audio';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '580',
    'height' => '30',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['audio__default__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_field_mediaelement_video';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__default__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['audio__default__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__media_large__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_field_file_rendered';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['audio__media_large__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_large__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_large__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_field_media_large_icon';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_large__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_field_mediaelement_audio';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '560',
    'height' => '30',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['audio__media_large__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_field_mediaelement_video';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_large__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_large__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['audio__media_large__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__media_link__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_link__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_link__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_link__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_link__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_link__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['audio__media_link__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['audio__media_link__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_link__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
  );
  $export['audio__media_link__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_field_file_default';
  $file_display->weight = 20;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['audio__media_original__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_field_file_url_plain';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_field_media_large_icon';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_field_mediaelement_audio';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '560',
    'height' => '30',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['audio__media_original__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_field_mediaelement_video';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_original__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_original__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['audio__media_original__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_field_file_default';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__media_preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_field_file_rendered';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['audio__media_preview__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_field_file_table';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_field_file_url_plain';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_field_media_large_icon';
  $file_display->weight = 20;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__media_preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_field_mediaelement_audio';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_preview__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_field_mediaelement_video';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_preview__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__file_image';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['audio__media_preview__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_preview__media_oembed';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '50',
    'wmode' => 'opaque',
  );
  $export['audio__media_preview__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_field_file_default';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__media_small__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_field_file_rendered';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['audio__media_small__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_small__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_field_file_url_plain';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['audio__media_small__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_field_media_large_icon';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['audio__media_small__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_small__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_field_mediaelement_video';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['audio__media_small__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__file_image';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['audio__media_small__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__media_oembed';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['audio__media_small__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__media_small__media_oembed_thumbnail';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '180',
  );
  $export['audio__media_small__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__default__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__default__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['default__default__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['default__media_original__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__media_original__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__media_original__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['default__media_original__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'file_view_mode' => 'media_preview',
  );
  $export['default__media_preview__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__media_preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__media_preview__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__media_preview__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_preview__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['default__media_preview__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_small__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['default__media_small__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_small__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_small__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__media_small__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__media_small__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['default__media_small__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'default__media_small__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['default__media_small__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['document__collab_doc_attachments__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['document__collab_doc_attachments__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__collab_doc_attachments__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__collab_doc_attachments__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_filehash_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'algo' => 'sha256',
  );
  $export['document__collab_doc_attachments__file_field_filehash_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__collab_doc_attachments__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['document__collab_doc_attachments__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['document__collab_doc_attachments__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__file_field_services';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'data_element_key' => '',
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  $export['document__collab_doc_attachments__file_field_services'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '340',
    'wmode' => '',
  );
  $export['document__collab_doc_attachments__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__oembed_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
    'alt' => '[file:field-file-image-alt-text]',
    'title' => '[file:field-file-image-title-text]',
  );
  $export['document__collab_doc_attachments__oembed_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__collab_doc_attachments__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '',
  );
  $export['document__collab_doc_attachments__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_colorbox';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'colorbox_node_style' => 'full',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'none',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $export['image__collab_doc_attachments__file_field_colorbox'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__collab_doc_attachments__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__collab_doc_attachments__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__collab_doc_attachments__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__collab_doc_attachments__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_filehash_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'algo' => 'sha256',
  );
  $export['image__collab_doc_attachments__file_field_filehash_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'full',
    'image_link' => '',
  );
  $export['image__collab_doc_attachments__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__collab_doc_attachments__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__collab_doc_attachments__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__collab_doc_attachments__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__file_field_services';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'data_element_key' => '',
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  $export['image__collab_doc_attachments__file_field_services'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => '',
  );
  $export['image__collab_doc_attachments__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__oembed_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
    'alt' => '[file:field-file-image-alt-text]',
    'title' => '[file:field-file-image-title-text]',
  );
  $export['image__collab_doc_attachments__oembed_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__collab_doc_attachments__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '',
  );
  $export['image__collab_doc_attachments__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_default';
  $file_display->weight = 20;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['image__default__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_table';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_url_plain';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_mediaelement_audio';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__default__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_mediaelement_video';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__default__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_image';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'full',
  );
  $export['image__default__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_file_default';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_file_rendered';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['image__media_large__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_media_large_icon';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_mediaelement_audio';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_large__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_large__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_field_file_default';
  $file_display->weight = 20;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['image__media_original__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_field_file_url_plain';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_field_media_large_icon';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_field_mediaelement_audio';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_original__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_field_mediaelement_video';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_original__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__file_field_file_default';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__media_preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__file_field_file_rendered';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['image__media_preview__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__file_field_file_url_plain';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__file_field_media_large_icon';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__media_preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__file_field_mediaelement_audio';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_preview__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__file_field_mediaelement_video';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_preview__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_preview__media_oembed';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
    'wmode' => 'opaque',
  );
  $export['image__media_preview__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_file_default';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__media_small__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_file_rendered';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['image__media_small__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_file_table';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_file_url_plain';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_media_large_icon';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__media_small__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_mediaelement_audio';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_small__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_mediaelement_video';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['image__media_small__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_image';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['image__media_small__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_field_file_default';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['text__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_field_file_rendered';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'media_preview',
  );
  $export['text__default__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_field_file_url_plain';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_field_media_large_icon';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['text__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_field_mediaelement_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__default__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_field_mediaelement_video';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__default__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__file_image';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['text__default__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__media_oembed';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => 'opaque',
  );
  $export['text__default__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__default__media_oembed_thumbnail';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
  );
  $export['text__default__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'file_view_mode' => 'media_original',
  );
  $export['text__media_original__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'display_settings' => array(
      'displays__file_field_mediaelement_audio__settings__display_settings__active_tab' => '',
    ),
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__media_original__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'display_settings' => array(
      'displays__file_field_mediaelement_video__settings__display_settings__active_tab' => '',
    ),
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__media_original__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_original__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['text__media_original__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'file_view_mode' => 'media_preview',
  );
  $export['text__media_preview__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'display_settings' => array(
      'displays__file_field_mediaelement_audio__settings__display_settings__active_tab' => '',
    ),
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__media_preview__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'display_settings' => array(
      'displays__file_field_mediaelement_video__settings__display_settings__active_tab' => '',
    ),
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__media_preview__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_preview__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['text__media_preview__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_field_file_default';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['text__media_small__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_field_file_rendered';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['text__media_small__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_field_file_table';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_small__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_field_file_url_plain';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['text__media_small__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_field_media_large_icon';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['text__media_small__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_field_mediaelement_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__media_small__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_field_mediaelement_video';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['text__media_small__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'text__media_small__file_image';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['text__media_small__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__collab_doc_attachments__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['video__collab_doc_attachments__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__collab_doc_attachments__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__collab_doc_attachments__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_file_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'autoplay' => 0,
    'loop' => 0,
    'muted' => 0,
    'width' => '',
    'height' => '',
    'preload' => '',
    'multiple_file_behavior' => 'tags',
  );
  $export['video__collab_doc_attachments__file_field_file_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_filehash_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'algo' => 'sha256',
  );
  $export['video__collab_doc_attachments__file_field_filehash_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__collab_doc_attachments__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_mediaelement_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__collab_doc_attachments__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_mediaelement_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '480',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['video__collab_doc_attachments__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__file_field_services';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'data_element_key' => '',
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  $export['video__collab_doc_attachments__file_field_services'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => '',
  );
  $export['video__collab_doc_attachments__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__oembed_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
    'alt' => '[file:field-file-image-alt-text]',
    'title' => '[file:field-file-image-title-text]',
  );
  $export['video__collab_doc_attachments__oembed_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__collab_doc_attachments__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '180',
    'height' => '',
  );
  $export['video__collab_doc_attachments__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_default';
  $file_display->weight = -44;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_rendered';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['video__default__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_table';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_url_plain';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_media_large_icon';
  $file_display->weight = -43;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_mediaelement_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__default__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_mediaelement_video';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '460',
    'height' => '460',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['video__default__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_image';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__default__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_default';
  $file_display->weight = 20;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_rendered';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['video__media_original__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_table';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_url_plain';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_media_large_icon';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_mediaelement_audio';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__media_original__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_mediaelement_video';
  $file_display->weight = -44;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 1,
    'download_text' => 'Download',
  );
  $export['video__media_original__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__media_original__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_field_file_default';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__media_preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_field_file_rendered';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['video__media_preview__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_field_file_table';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_field_file_url_plain';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_field_media_large_icon';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__media_preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_field_mediaelement_audio';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__media_preview__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_field_mediaelement_video';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '140',
    'height' => '140',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__media_preview__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__file_image';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['video__media_preview__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_preview__media_oembed';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '140',
    'height' => '140',
    'wmode' => 'opaque',
  );
  $export['video__media_preview__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_field_file_default';
  $file_display->weight = -42;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__media_small__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_field_file_rendered';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'file_view_mode' => 'default',
  );
  $export['video__media_small__file_field_file_rendered'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_field_file_table';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_small__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_small__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_field_media_large_icon';
  $file_display->weight = -41;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__media_small__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_field_mediaelement_audio';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '300',
    'height' => '30',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__media_small__file_field_mediaelement_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_field_mediaelement_video';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'width' => '640',
    'height' => '385',
    'download_link' => 0,
    'download_text' => 'Download',
  );
  $export['video__media_small__file_field_mediaelement_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__file_image';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['video__media_small__file_image'] = $file_display;

  return $export;
}
