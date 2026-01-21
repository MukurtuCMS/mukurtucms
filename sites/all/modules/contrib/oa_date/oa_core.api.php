<?php
/**
 * @file
 * Contains documentation about the Open Atrium Core module's hooks.
 */

/**
 * @defgroup oa_access Open Atrium Core
 * @{
 * Hooks from the Open Atrium Core module.
 */

/**
 * Gets space_type or section_type options from a Taxonomy term.
 *
 * This hook is used to take a Taxonomy term and covert it's data into options
 * about a Space Blueprint, to be used in Javascript on the node edit page.
 *
 * @param object $term
 *   A Taxonomy term object.
 * @param string $vocab_name
 *   The name of the vocabulary that this Taxonomy term comes from.
 *
 * @return array
 *   An associative array representing information about this Taxonomy term to
 *   add to the Javascript options.
 */
function hook_oa_core_space_type_options($term, $vocab_name) {
  // Add a new field to the option data, but only for 'space_type' terms (as
  // opposed to 'section_type' which also uses this hook).
  if ($vocab_name == 'space_type') {
    return array(
      'my_field_value' => $term->field_my_field[LANGUAGE_NONE][0]['value'],
    );
  }
}

/**
 * Alter the space_type or section_type options from other modules.
 *
 * @param array &$optionts
 *   An associative array keyed by the Taxonomy term id containing the option
 *   data returned by all module via hook_oa_core_space_type_options().
 * @param string $vocab_name
 *   The name of the vocabulary that this Taxonomy term comes from.
 */
function hook_oa_core_space_type_options_alter(&$options, $vocab_name) {
  if ($vocab_name == 'space_type') {
    foreach ($options as $tid => &$option) {
      $term = taxonomy_term_load($tid);
      // Modify some data on the option data.
      $option['blah'] = 'arbitrary string';
    }
  }
}

/**
 * @}
 */
