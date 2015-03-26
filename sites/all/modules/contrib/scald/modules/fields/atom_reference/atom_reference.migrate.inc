<?php

/**
 * @file
 * Support for processing atom reference fields in Migrate.
 */

/**
 * Implements hook_migrate_api().
 */
function atom_reference_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array('MigrateAtomReferenceFieldHandler'),
  );
}

class MigrateAtomReferenceFieldHandler extends MigrateSimpleFieldHandler {
  /**
   * Constructor.
   */
  public function __construct() {
    parent::__construct(array(
      'value_key' => 'sid',
      'skip_empty' => TRUE,
    ));

    $this->registerTypes(array('atom_reference'));
  }
}
