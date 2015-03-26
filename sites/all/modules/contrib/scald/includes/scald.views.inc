<?php
/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_data().
 */
function scald_views_data() {
  $data = array();

  $data['scald_atoms']['table']['group'] = t('Atom');

  $data['scald_atoms']['table']['base'] = array(
    'field' => 'sid',
    'title' => t('Atoms'),
    'help' => t("Views related to Scald Atoms."),
  );

  $data['scald_atoms']['table']['entity type'] = 'scald_atom';

  $data['scald_atoms']['sid'] = array(
    'title' => t('Scald ID'),
    'help' => t("The atom's unique identifier"),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['scald_atoms']['representation'] = array(
    'title' => t('Representation'),
    'real field' => 'sid',
    'help' => t("The atom's representation, in a specific context"),
    'field' => array(
      'handler' => 'scald_views_handler_field_representation',
      'click sortable' => FALSE,
    ),
  );

  $data['scald_atoms']['provider'] = array(
    'title' => t('Provider'),
    'help' => t('The module responsible of this atom'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'scald_views_handler_filter_atom_provider',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['scald_atoms']['type'] = array(
    'title' => t('Type'),
    'help' => t('The type of the atom, such as "image", "audio" ...'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'scald_views_handler_filter_atom_type',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['scald_atoms']['base_id'] = array(
    'title' => t('Base ID'),
    'help' => t('The base id, used by the providing module. For example, for atoms based on node, this could be the nid.'),
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

  $data['scald_atoms']['publisher'] = array(
    'title' => t('Publisher'),
    'help' => t('Relate an atom to the user who published it.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('User'),
    ),
  );

  $data['scald_atoms']['title'] = array(
    'title' => t('Title'),
    'help' => t("The atom's title"),
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

  $data['scald_atoms']['actions'] = array(
    'title' => t('Actions'),
    'help' => t("Possible interactions with this atom"),
    'field' => array(
      'handler' => 'scald_views_handler_field_actions',
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'scald_views_handler_filter_actions',
    ),
  );

  $data['scald_atoms']['data'] = array(
    'title' => t('Data'),
    'help' => t("Free-form data associated to this atom. The content will be atom and provider specific."),
    'field' => array(
      'handler' => 'scald_views_handler_field_data',
      'click sortable' => FALSE,
    ),
  );

  $data['scald_atoms']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the Atom was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['scald_atoms']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the Atom was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function scald_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'scald') . '/includes',
    ),
    'handlers' => array(
      'scald_views_handler_filter_atom_type' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'scald_views_handler_filter_atom_provider' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'scald_views_handler_filter_actions' => array(
        'parent' => 'views_handler_filter',
      ),
      'scald_views_handler_field_representation' => array(
        'parent' => 'views_handler_field',
      ),
      'scald_views_handler_field_actions' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
