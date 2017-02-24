<?php

/**
 * @file
 * Provide views data and handlers for scald_index.module.
 *
 * @ingroup views_module_handlers
 */

/**
 * Implements hook_views_data().
 */
function scald_index_views_data() {
  // Define a custom relationship handler for the scald_index table.

  $data['scald_index']['table']['group'] = t('Atoms');

  $data['scald_index']['table']['join'] = array(
    'scald_atoms' => array(
      'left_field' => 'sid',
      'field' => 'sid',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['scald_index']['nid'] = array(
    'title' => t('Content with atom'),
    'help' => t('Relate all content referenced with an atom.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('node'),
      'skip base' => 'node',
    ),
  );

  return $data;
}
