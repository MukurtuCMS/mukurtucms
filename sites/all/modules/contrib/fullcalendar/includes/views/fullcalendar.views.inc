<?php

/**
 * @file
 * Contains Views module hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function fullcalendar_views_plugins() {
  $path = drupal_get_path('module', 'fullcalendar');
  return array(
    'module' => 'fullcalendar',
    'style' => array(
      'fullcalendar' => array(
        'title' => t('FullCalendar'),
        'help' => t('Displays items on a calendar.'),
        'handler' => 'fullcalendar_plugin_style_fullcalendar',
        'path' => $path . '/includes/views/plugins',
        'theme' => 'fullcalendar',
        'theme file' => 'theme.inc',
        'theme path' => $path . '/theme',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => TRUE,
        'even empty' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}

/**
 * Implements hook_views_plugins_alter().
 */
function fullcalendar_views_plugins_alter(&$plugins) {
  $plugins['display']['fullcalendar'] = array(
    'title' => t('FullCalendar - Deprecated, use page display instead!'),
    'help' => t('Stop using this display, use page instead'),
    'no ui' => TRUE,
  ) + $plugins['display']['page'];
}

/**
 * Implements hook_views_data().
 */
function fullcalendar_views_data() {
  $data = array();

  $data['fullcalendar'] = array(
    'table' => array(
      'group' => t('FullCalendar'),
      'join' => array('#global' => array()),
    ),
    'gcal' => array(
      'title' => t('Google Calendar'),
      'help' => t('Display events from a Google Calendar.'),
      'field' => array(
        'handler' => 'fullcalendar_handler_field_gcal',
      ),
    ),
  );

  return $data;
}

/**
 * Implements hook_views_pre_view().
 *
 * Add an argument that provides the current date for each date field present.
 */
function fullcalendar_views_pre_view(&$view, &$display_id, &$args) {
  if ($view->display_handler->get_option('style_plugin') != 'fullcalendar') {
    return;
  }

  // Get the current view settings.
  $view->init_style();
  $settings = $view->style_plugin->options;

  fullcalendar_include_api();
  $fullcalendar_options = module_invoke_all('fullcalendar_options_info');
  uasort($fullcalendar_options, 'drupal_sort_weight');
  foreach (array_intersect(array_keys($fullcalendar_options), module_implements('fullcalendar_options_pre_view')) as $module) {
    $function = $module . '_fullcalendar_options_pre_view';
    $function($settings, $view);
  }

  $settings['ajax'] = FALSE;

  // If we're not using ajax, we're done.
  if (!$view->display_handler->get_option('use_ajax')) {
    // Set the new view settings.
    $view->style_plugin->options = $settings;
    return;
  }

  $settings['fullcalendar_fields_count'] = 0;
  $exposed_input = $view->get_exposed_input();
  // Loop through each date field and provide an argument for it.
  foreach ($view->display_handler->get_handlers('field') as $field_id => $field) {
    if (!fullcalendar_field_is_date($field)) {
      continue;
    }

    $settings['ajax'] = TRUE;
    // Add an exposed filter for the date field.
    $field_value_id = $field->real_field . str_replace($field->field, '', $field_id);
    if (isset($exposed_input[$field_value_id])) {
      $timestamp = (strtotime($exposed_input[$field_value_id]['min']['date']) + strtotime($exposed_input[$field_value_id]['max']['date'])) / 2;
      $min = date('Y-m', $timestamp);
      $max = date('Y-m', strtotime($min . ' +1 month'));
    }
    else {
      $min = $settings['date']['year'] . '-' . ($settings['date']['month'] + 1);
      $max = $settings['date']['year'] . '-' . ($settings['date']['month'] + 2);
    }
    $min = date('Y-m-d', strtotime($min . ' -2 weeks'));
    $max = date('Y-m-d', strtotime($max . ' +2 weeks'));
    $options = array(
      'exposed' => TRUE,
      'form_type' => 'date_text',
      'operator' => 'between',
      'default_date' => $min,
      'default_to_date' => $max,
      'group' => 0,
    );
    if (!empty($field->options['relationship'])) {
      $options['relationship'] = $field->options['relationship'];
    }
    $option_id = $view->add_item($display_id, 'filter', 'field_data_' . $field->field, $field->field . '_value', $options);
    $settings['fullcalendar_fields'][$option_id] = drupal_html_class($option_id);
    $settings['fullcalendar_fields_count']++;
    $view->set_item_option($display_id, 'filter', $option_id, 'expose', array('identifier' => $option_id, 'operator' => $option_id . '_op'));

  }

  if (isset($timestamp)) {
    $settings['date']['date'] = date('d', $timestamp);
    $settings['date']['month'] = date('n', $timestamp) - 1;
    $settings['date']['year'] = date('Y', $timestamp);
  }

  $view->style_plugin->options = $settings;
}

/**
 * Implements hook_views_query_alter().
 *
 * Force the query to be distinct.
 */
function fullcalendar_views_query_alter(&$view, &$query) {
  if ($view->display_handler->get_option('style_plugin') != 'fullcalendar') {
    return;
  }

  $query->distinct = TRUE;
}

/**
 * Implements hook_views_ajax_data_alter().
 */
function fullcalendar_views_ajax_data_alter(&$commands, &$view) {
  if ($view->display_handler->get_option('style_plugin') == 'fullcalendar') {
    $commands = array();
  }
}
