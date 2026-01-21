<?php

/**
 * @file
 * Provides views-specific functionality to oa_date.
 */

/**
 * Implements hook_views_handlers().
 */
function oa_date_views_handlers() {
  return array(
    'info' => array('path' => drupal_get_path('module', 'oa_date') . '/views'),
    'handlers' => array(
      'oa_date_handler_field_date' => array('parent' => 'views_handler_field_date'),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter().
 * Replaces default handlers with custom handlers.
 */
function oa_date_views_data_alter(&$data) {
  foreach ($data as $table => $data_table) {
    foreach ($data_table as $field => $data_field) {
      if (!empty($data_field['field']['handler']) && $data_field['field']['handler'] === 'views_handler_field_date') {
        $data[$table][$field]['field']['handler'] = 'oa_date_handler_field_date';
      }
    }
  }
}
