<?php

/**
 * @file
 * Adds views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function search_api_attachments_views_data_alter(&$data) {
  // Add the filter for each Search API's index.
  foreach (search_api_index_load_multiple(FALSE) as $index) {
    $key = 'search_api_index_' . $index->machine_name;
    $table = &$data[$key];
    $name = 'saa_exclude_attachments';
    $table[$name] = array();
    $table[$name]['group'] = t('Search');
    $table[$name]['title'] = t('Exclude attachments');
    $table[$name]['help'] = t('Exclude or include attachments in search query.');
    $table[$name]['filter']['handler'] = 'SearchApiAttachmentsViewsHandlerAttachmentsFilter';
  }
}
