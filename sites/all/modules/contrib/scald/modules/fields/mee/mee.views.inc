<?php

/**
 * @file
 * Provide views data and handlers for mee.module.
 *
 * @ingroup views_module_handlers
 */

/**
 * Implements hook_views_data().
 */
function mee_views_data() {
  // Define a custom relationship handler for the mee_resource table.
  $data['mee_resource']['table']['group'] = t('Resource Manager');

  $data['mee_resource']['table']['base'] = array(
    'field' => 'atom_sid', // This is the identifier field for the view.
    'title' => t('Resource Manager'),
    'help' => t('Contains embedded atoms and can be related to nodes.'),
    'weight' => -10,
  );

  $data['mee_resource']['table']['join'] = array(
    'scald_atoms' => array(
      'left_field' => 'sid',
      'field' => 'atom_sid',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'entity_id',
    ),
  );

  $data['mee_resource']['entity_id'] = array(
    'title' => t('Content ID'),
    'help' => t('Relate content with an atom element.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('node id'),
      'skip base' => 'node',
    ),
  );

  $data['mee_resource']['revision_id'] = array(
    'title' => t('Content Revision ID'),
    'help' => t('Relate content revision with an atom element.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'vid',
      'label' => t('node rev id'),
      'skip base' => 'node',
    ),
  );

  $data['mee_resource']['atom_sid'] = array(
    'title' => t('Atom ID'),
    'help' => t('Relate atom with the atom element.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'scald_atoms',
      'base field' => 'sid',
      'label' => t('atom'),
      'skip base' => 'scald_atoms',
    ),
  );

  $data['mee_resource']['field'] = array(
    'title' => t('Embedding field'),
    'help' => t('Embedding text field id.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['mee_resource']['copyright'] = array(
    'title' => t('Caption'),
    'help' => t('Atom caption.'),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => 'full_html',
    ),
  );

  return $data;
}
