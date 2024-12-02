<?php

/**
 * @file
 * Integration with Views.
 */

/**
 * Implementation of hook_views_plugins().
 */
function zip_export_media_views_plugins() {
  $module_path = drupal_get_path('module', 'views');
  return array(
    'module' => 'zip_export_media', // This just tells our themes are elsewhere.
    'style' => array(
      'zip_export_media' => array(
        'title' => t('Zip export of Media files'),
        'help' => t('Builds a zip archive of all media items associated with the view.'),
        'handler' => 'zip_export_media_plugin_style',
        'path' => $module_path .'/views',
//        'theme path' => $module_path .'/theme',
//        'theme file' => 'theme.inc',
        'theme' => 'views_view_unformatted',
        'uses row plugin' => FALSE,
        'uses fields'     => TRUE,
        'uses options'    => TRUE,
        'type'            => 'normal',
        'even empty'      => TRUE,
      ),
    ),
  );
}