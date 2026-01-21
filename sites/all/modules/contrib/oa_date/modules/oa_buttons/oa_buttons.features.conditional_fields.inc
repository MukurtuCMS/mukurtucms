<?php
/**
 * @file
 * oa_buttons.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function oa_buttons_conditional_fields_default_fields() {
  $items = array();

  $items["node:oa_section:0"] = array(
    'entity' => 'node',
    'bundle' => 'oa_section',
    'dependent' => 'field_oa_node_types',
    'dependee' => 'field_oa_section_override',
    'options' => array(
      'state' => 'visible',
      'condition' => 'checked',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(),
      'element_edit' => array(
        1 => 1,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(),
      'selector' => '',
      'values_set' => 1,
      'value' => array(),
      'values' => array(),
      'value_form' => array(),
    ),
  );

  $items["node:oa_space:0"] = array(
    'entity' => 'node',
    'bundle' => 'oa_space',
    'dependent' => 'field_oa_node_types',
    'dependee' => 'field_oa_section_override',
    'options' => array(
      'state' => 'visible',
      'condition' => 'checked',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(),
      'element_edit' => array(
        1 => 1,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(),
      'selector' => '',
      'values_set' => 1,
      'value' => array(),
      'values' => array(),
      'value_form' => array(),
    ),
  );

  return $items;
}
