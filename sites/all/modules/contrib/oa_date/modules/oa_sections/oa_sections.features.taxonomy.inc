<?php
/**
 * @file
 * oa_sections.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oa_sections_taxonomy_default_vocabularies() {
  return array(
    'section_type' => array(
      'name' => 'Section Type',
      'machine_name' => 'section_type',
      'description' => 'Allow selection of Open Atrium sections',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
