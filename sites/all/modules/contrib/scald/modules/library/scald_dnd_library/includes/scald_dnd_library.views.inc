<?php
/**
 * @file
 * Views plugins implementation.
 */

/**
 * Implements hook_views_plugins().
 */
function scald_dnd_library_views_plugins() {
  return array(
    'style' => array(
      'scald_library' => array(
        'title' => t('Scald Library'),
        'help' => t('Format atoms for use in a DnD Library'),
        'handler' => 'scald_plugin_style_library',
        'path' => drupal_get_path('module', 'scald_dnd_library') . '/includes',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => FALSE,
        'type' => 'normal',
        'help topic' => 'style-library',
        'theme' => 'sdl_library',
        'theme file' => 'scald_dnd_library.module',
      ),
    ),
    'display' => array(
      'dnd_library' => array(
        'title' => t('Scald Library'),
        'help' => t('Format atoms for use as a DnD Library'),
        'handler' => 'scald_plugin_display_library',
        'parent' => 'page',
        'path' => drupal_get_path('module', 'scald_dnd_library') . '/includes',
        'theme' => 'views_view',
        'use ajax' => FALSE,
        'use pager' => TRUE,
        'admin' => t('Library'),
        'help topic' => 'scald-library',
        'uses hook menu' => TRUE,
        'provides dnd library' => TRUE,
      ),
    ),
  );
}
