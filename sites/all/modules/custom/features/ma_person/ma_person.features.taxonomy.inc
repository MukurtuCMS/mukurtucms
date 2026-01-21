<?php

/**
 * @file
 * ma_person.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ma_person_taxonomy_default_vocabularies() {
  return array(
    'interpersonal_relationship' => array(
      'name' => 'Interpersonal Relationship',
      'machine_name' => 'interpersonal_relationship',
      'description' => 'Terms that describe a relation between two people',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
