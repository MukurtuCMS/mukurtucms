<?php

/**
 * @file
 * owlcarousel_views.views.inc
 */

/*
 * Implements hook_views_plugins().
 */
function owlcarousel_views_views_plugins() {
  return array(
    'style' => array(
      'owlcarousel' => array(
        'title' => t('Owl Carousel'),
        'help' => t('Displays the view output in an Owl Carousel'),
        'help topic' => '',
        'handler' => 'owlcarousel_views_plugin_style_owlcarousel',
        'theme' => 'owlcarousel_views',
        'theme file' => 'owlcarousel_views.theme.inc',
        'theme path' => drupal_get_path('module', 'owlcarousel_views') . '/theme',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'even empty' => FALSE,
      ),
    )
  );
}
