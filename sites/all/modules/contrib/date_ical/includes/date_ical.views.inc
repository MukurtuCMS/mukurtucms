<?php

/**
 * @file
 * Declares our plugins to Views.
 */

/**
 * Implements hook_views_plugins().
 */
function date_ical_views_plugins() {
  $includes_path = drupal_get_path('module', 'date_ical') . '/includes';

  $data = array(
    'module' => 'date_ical',
    'style' => array(
      'date_ical' => array(
        'type' => 'feed',
        'title' => t('iCal Feed'),
        'help' => t('Generates an iCal feed from a View.'),
        'handler' => 'date_ical_plugin_style_ical_feed',
        'path' => $includes_path,
        'uses fields' => FALSE,
        'uses grouping' => FALSE,
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'even empty' => TRUE,
      ),
    ),
    'row' => array(
      'date_ical' => array(
        'type' => 'feed',
        'title' => t('iCal Entity'),
        'help' => t('Render each entity in the view as an iCal VEVENT item.'),
        'handler' => 'date_ical_plugin_row_ical_entity',
        'path' => $includes_path,
        'uses options' => TRUE,
        'uses fields' => FALSE,
      ),
      'date_ical_fields' => array(
        'type' => 'feed',
        'title' => t('iCal Fields'),
        'help' => t('Builds an iCal VEVENT from inidividual Views fields.'),
        'handler' => 'date_ical_plugin_row_ical_fields',
        'path' => $includes_path,
        'uses options' => TRUE,
        'uses fields' => TRUE,
      ),
    ),
  );

  return $data;
}
