<?php
/**
 * @file
 * oa_buttons.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oa_buttons_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_oa_node_types'
  $field_bases['field_oa_node_types'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_node_types',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'oa_buttons_get_command_buttons_options',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
