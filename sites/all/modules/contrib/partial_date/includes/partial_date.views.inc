<?php

/**
 * Implements hook_field_views_data().
 */
function partial_date_field_views_data($field) {
  $data = field_views_field_default_views_data($field);

  foreach ($data as $table_name => $table_data) {
    foreach ($table_data as $field_name => $field_data) {
      if ($field_name == $field['field_name']) {
        if (!isset($field_data['filter'])) {
          $data[$table_name][$field_name]['filter'] = $data[$table_name][$field_name . '_timestamp']['filter'];
        }
        if (!isset($field_data['argument'])) {
          $data[$table_name][$field_name]['argument'] = $data[$table_name][$field_name . '_timestamp']['argument'];
        }
        if (!isset($field_data['sort'])) {
          $data[$table_name][$field_name]['sort'] = $data[$table_name][$field_name . '_timestamp']['sort'];
        }
        $data[$table_name][$field_name]['filter']['handler'] = 'views_handler_filter_field_partial_date_year';
      }
    }
  }

  foreach ($data as $table_name => $table_data) {
    if (isset($data[$table_name][$field['field_name'] . '_timestamp'])) {
      unset($data[$table_name][$field['field_name'] . '_timestamp']);
    }
  }

  return $data;
}
