<?php
/**
 * @file
 * ma_file_fixity.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ma_file_fixity_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_fixity_cps'.
  $field_bases['field_fixity_cps'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_cps',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'duplicates' => 0,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'treeable_behavior' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'title',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'cultural_protocol_group' => 'cultural_protocol_group',
        ),
      ),
      'target_type' => 'node',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_fixity_days_frequency'.
  $field_bases['field_fixity_days_frequency'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_days_frequency',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_fixity_schedule'.
  $field_bases['field_fixity_schedule'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_schedule',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Weekly' => 'Weekly',
        'Monthly' => 'Monthly',
        'Every x days' => 'Every x days',
      ),
      'allowed_values_function' => '',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
