<?php

/**
 * @file
 * Provide views data and handlers for filehash table.
 */

/**
 * Implements hook_views_data().
 */
function filehash_views_data() {
  $data['filehash']['table']['group'] = t('File');
  $data['filehash']['table']['join'] = array(
    'file_managed' => array(
      'left_field' => 'fid',
      'field' => 'fid',
    ),
  );
  // Use a nice human-readable name for each hash algorithm.
  $names = filehash_names();
  foreach (filehash_columns() as $column) {
    $data['filehash'][$column] = array(
      'title' => t('@algo hash', array('@algo' => $names[$column])),
      'help' => t('The @algo hash of the file.', array('@algo' => $names[$column])),
      'field' => array(
        'click sortable' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );
  }
  $data['filehash']['timestamp'] = array(
    'title' => t('Hash date'),
    'help' => t('The date the file hash was generated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  return $data;
}
