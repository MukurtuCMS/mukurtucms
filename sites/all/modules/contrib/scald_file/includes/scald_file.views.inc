<?php
/**
 * @file
 * Adds filesize field to views.
 */

/**
 * Implements hook_views_data().
 */
function scald_file_views_data() {
  $data = array();

  $data['scald_atoms']['filesize'] = array(
    'real field' => 'base_id',
    'title' => t('Filesize'),
    'help' => t("Formatted filesize of the file in the atom. This will only work with atoms that use the base id for storing file id."),
    'field' => array(
      'handler' => 'scald_file_views_handler_field_filesize',
      'click sortable' => FALSE,
    ),
  );

  return $data;
}
