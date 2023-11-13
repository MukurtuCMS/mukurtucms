<?php
/**
 * @file
 * oa_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oa_core_taxonomy_default_vocabularies() {
  return array(
    'space_type' => array(
      'name' => 'Space Blueprint',
      'machine_name' => 'space_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
