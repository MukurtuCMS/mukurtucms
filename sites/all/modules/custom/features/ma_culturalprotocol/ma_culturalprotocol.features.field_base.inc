<?php

/**
 * @file
 * ma_culturalprotocol.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ma_culturalprotocol_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_protocl_signup_permissions'.
  $field_bases['field_protocl_signup_permissions'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_protocl_signup_permissions',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'default' => 'Use defaults set for all Protocols',
        'private' => 'Private group, no signup allowed',
        'moderated' => 'Joining requires approval',
        'open' => 'Open group, anyone can join',
      ),
      'allowed_values_function' => '',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_protocol_auto_join'.
  $field_bases['field_protocol_auto_join'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_protocol_auto_join',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_protocol_image'.
  $field_bases['field_protocol_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_protocol_image',
    'indexes' => array(
      'sid' => array(
        0 => 'sid',
      ),
    ),
    'locked' => 0,
    'module' => 'atom_reference',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'atom_reference',
  );

  // Exported field_base: 'field_protocol_image_thumbnail'.
  $field_bases['field_protocol_image_thumbnail'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_protocol_image_thumbnail',
    'indexes' => array(
      'sid' => array(
        0 => 'sid',
      ),
    ),
    'locked' => 0,
    'module' => 'atom_reference',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'atom_reference',
  );

  return $field_bases;
}
