<?php
/**
 * @file
 * Code for Theme functions for OpenAtrium widgets
 */


/**
 * Implements hook_theme()
 */
function oa_widgets_theme() {
  return array(
    'oa_widgets_content_visibility' => array(
      'template'  => 'oa-widgets-content-visibility',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => drupal_get_path('module', 'oa_widgets') . '/templates',
    ),
    'oa_widgets_user_profile' => array(
      'template'  => 'oa-widgets-user-profile',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => drupal_get_path('module', 'oa_widgets') . '/templates',
    ),
    'oa_widgets_visibility_toolbar' => array(
      'template'  => 'oa-widgets-visibility-toolbar',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => drupal_get_path('module', 'oa_widgets') . '/templates',
    ),
  );
}
