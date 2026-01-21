<?php
/**
 * @file
 * ma_importexport_media.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_importexport_media_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'export_media';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'export_media';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_media';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = 'filename';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: File: Altitude */
  $handler->display->display_options['fields']['field_gps_altitude']['id'] = 'field_gps_altitude';
  $handler->display->display_options['fields']['field_gps_altitude']['table'] = 'field_data_field_gps_altitude';
  $handler->display->display_options['fields']['field_gps_altitude']['field'] = 'field_gps_altitude';
  $handler->display->display_options['fields']['field_gps_altitude']['label'] = 'altitude';
  $handler->display->display_options['fields']['field_gps_altitude']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gps_altitude']['type'] = 'text_plain';
  /* Field: File: Aperture */
  $handler->display->display_options['fields']['field_aperturevalue']['id'] = 'field_aperturevalue';
  $handler->display->display_options['fields']['field_aperturevalue']['table'] = 'field_data_field_aperturevalue';
  $handler->display->display_options['fields']['field_aperturevalue']['field'] = 'field_aperturevalue';
  $handler->display->display_options['fields']['field_aperturevalue']['label'] = 'aperture';
  $handler->display->display_options['fields']['field_aperturevalue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aperturevalue']['type'] = 'text_plain';
  /* Field: File: Artist */
  $handler->display->display_options['fields']['field_exif_artist']['id'] = 'field_exif_artist';
  $handler->display->display_options['fields']['field_exif_artist']['table'] = 'field_data_field_exif_artist';
  $handler->display->display_options['fields']['field_exif_artist']['field'] = 'field_exif_artist';
  $handler->display->display_options['fields']['field_exif_artist']['label'] = 'artist';
  $handler->display->display_options['fields']['field_exif_artist']['element_label_colon'] = FALSE;
  /* Field: File: Caption */
  $handler->display->display_options['fields']['field_caption']['id'] = 'field_caption';
  $handler->display->display_options['fields']['field_caption']['table'] = 'field_data_field_caption';
  $handler->display->display_options['fields']['field_caption']['field'] = 'field_caption';
  $handler->display->display_options['fields']['field_caption']['label'] = 'caption';
  $handler->display->display_options['fields']['field_caption']['element_label_colon'] = FALSE;
  /* Field: File: Date / Time */
  $handler->display->display_options['fields']['field_exif_datetime']['id'] = 'field_exif_datetime';
  $handler->display->display_options['fields']['field_exif_datetime']['table'] = 'field_data_field_exif_datetime';
  $handler->display->display_options['fields']['field_exif_datetime']['field'] = 'field_exif_datetime';
  $handler->display->display_options['fields']['field_exif_datetime']['label'] = 'date_time';
  $handler->display->display_options['fields']['field_exif_datetime']['element_label_colon'] = FALSE;
  /* Field: File: Description */
  $handler->display->display_options['fields']['field_text_description']['id'] = 'field_text_description';
  $handler->display->display_options['fields']['field_text_description']['table'] = 'field_data_field_text_description';
  $handler->display->display_options['fields']['field_text_description']['field'] = 'field_text_description';
  $handler->display->display_options['fields']['field_text_description']['label'] = 'description';
  $handler->display->display_options['fields']['field_text_description']['element_label_colon'] = FALSE;
  /* Field: File: Exposure */
  $handler->display->display_options['fields']['field_exif_exposuretime']['id'] = 'field_exif_exposuretime';
  $handler->display->display_options['fields']['field_exif_exposuretime']['table'] = 'field_data_field_exif_exposuretime';
  $handler->display->display_options['fields']['field_exif_exposuretime']['field'] = 'field_exif_exposuretime';
  $handler->display->display_options['fields']['field_exif_exposuretime']['label'] = 'exposure';
  $handler->display->display_options['fields']['field_exif_exposuretime']['element_label_colon'] = FALSE;
  /* Field: File: Extension */
  $handler->display->display_options['fields']['extension']['id'] = 'extension';
  $handler->display->display_options['fields']['extension']['table'] = 'file_managed';
  $handler->display->display_options['fields']['extension']['field'] = 'extension';
  $handler->display->display_options['fields']['extension']['label'] = 'extension';
  $handler->display->display_options['fields']['extension']['element_label_colon'] = FALSE;
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = 'file_id';
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: File: Headline */
  $handler->display->display_options['fields']['field_iptc_headline']['id'] = 'field_iptc_headline';
  $handler->display->display_options['fields']['field_iptc_headline']['table'] = 'field_data_field_iptc_headline';
  $handler->display->display_options['fields']['field_iptc_headline']['field'] = 'field_iptc_headline';
  $handler->display->display_options['fields']['field_iptc_headline']['label'] = 'headline';
  $handler->display->display_options['fields']['field_iptc_headline']['element_label_colon'] = FALSE;
  /* Field: File: Latitude */
  $handler->display->display_options['fields']['field_gps_latitude']['id'] = 'field_gps_latitude';
  $handler->display->display_options['fields']['field_gps_latitude']['table'] = 'field_data_field_gps_latitude';
  $handler->display->display_options['fields']['field_gps_latitude']['field'] = 'field_gps_latitude';
  $handler->display->display_options['fields']['field_gps_latitude']['label'] = 'latitude';
  $handler->display->display_options['fields']['field_gps_latitude']['element_label_colon'] = FALSE;
  /* Field: File: Longitude */
  $handler->display->display_options['fields']['field_gps_longitude']['id'] = 'field_gps_longitude';
  $handler->display->display_options['fields']['field_gps_longitude']['table'] = 'field_data_field_gps_longitude';
  $handler->display->display_options['fields']['field_gps_longitude']['field'] = 'field_gps_longitude';
  $handler->display->display_options['fields']['field_gps_longitude']['label'] = 'longitude';
  $handler->display->display_options['fields']['field_gps_longitude']['element_label_colon'] = FALSE;
  /* Field: File: Media Folder */
  $handler->display->display_options['fields']['field_folder']['id'] = 'field_folder';
  $handler->display->display_options['fields']['field_folder']['table'] = 'field_data_field_folder';
  $handler->display->display_options['fields']['field_folder']['field'] = 'field_folder';
  $handler->display->display_options['fields']['field_folder']['label'] = 'media_folder';
  $handler->display->display_options['fields']['field_folder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_folder']['type'] = 'taxonomy_term_reference_plain';
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['label'] = 'mime_type';
  $handler->display->display_options['fields']['filemime']['element_label_colon'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename_1']['id'] = 'filename_1';
  $handler->display->display_options['fields']['filename_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename_1']['field'] = 'filename';
  $handler->display->display_options['fields']['filename_1']['label'] = 'name';
  $handler->display->display_options['fields']['filename_1']['element_label_colon'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['label'] = 'path';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['label'] = 'size';
  $handler->display->display_options['fields']['filesize']['element_label_colon'] = FALSE;
  /* Field: File: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'file_managed';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  /* Field: File: Title */
  $handler->display->display_options['fields']['field_text_title']['id'] = 'field_text_title';
  $handler->display->display_options['fields']['field_text_title']['table'] = 'field_data_field_text_title';
  $handler->display->display_options['fields']['field_text_title']['field'] = 'field_text_title';
  $handler->display->display_options['fields']['field_text_title']['label'] = 'title';
  $handler->display->display_options['fields']['field_text_title']['element_label_colon'] = FALSE;
  /* Field: File: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'file_managed';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'upload_date';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'exif';
  /* Field: File Usage: Entity ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'file_usage';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'entity_id';
  /* Field: File Usage: Entity type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'file_usage';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = 'entity_type';
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'export-media';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'export-media/csv/images';
  $translatables['export_media'] = array(
    t('Master'),
    t('export_media'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('filename'),
    t('tags'),
    t('altitude'),
    t('aperture'),
    t('artist'),
    t('caption'),
    t('date_time'),
    t('description'),
    t('exposure'),
    t('extension'),
    t('file_id'),
    t('headline'),
    t('latitude'),
    t('longitude'),
    t('media_folder'),
    t('mime_type'),
    t('name'),
    t('path'),
    t('size'),
    t('status'),
    t('title'),
    t('type'),
    t('upload_date'),
    t('entity_id'),
    t('.'),
    t(','),
    t('entity_type'),
    t('Page'),
    t('Data export'),
  );
  $export['export_media'] = $view;

  return $export;
}
