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
  foreach (filehash_algos() as $algo) {
    $data['filehash'][$algo] = array(
      'title' => t('@algo hash', array('@algo' => $names[$algo])),
      'help' => t('The @algo hash of the file.', array('@algo' => $names[$algo])),
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
  return $data;
}
