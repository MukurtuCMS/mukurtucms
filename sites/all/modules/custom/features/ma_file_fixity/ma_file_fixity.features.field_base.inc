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

  // Exported field_base: 'field_fixity_algos_checked'.
  $field_bases['field_fixity_algos_checked'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_algos_checked',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'filehash_algos',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_fixity_check_fails_count'.
  $field_bases['field_fixity_check_fails_count'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_check_fails_count',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_fixity_check_fails_details'.
  $field_bases['field_fixity_check_fails_details'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_check_fails_details',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

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

  // Exported field_base: 'field_fixity_email_all_admins'.
  $field_bases['field_fixity_email_all_admins'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_email_all_admins',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_fixity_files_checked'.
  $field_bases['field_fixity_files_checked'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_files_checked',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_fixity_hashes_to_use'.
  $field_bases['field_fixity_hashes_to_use'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_hashes_to_use',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'filehash_algos',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_fixity_latest_check_status'.
  $field_bases['field_fixity_latest_check_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_latest_check_status',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'not_run' => 'Not yet run',
        'pass' => '<span class="fixity-check-pass-status">Pass</span>',
        'fail' => '<span class="fixity-check-fail-status">Fail</span>',
      ),
      'allowed_values_function' => '',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_fixity_latest_check_time'.
  $field_bases['field_fixity_latest_check_time'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_latest_check_time',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 'second',
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => '',
      'treeable' => 0,
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datestamp',
  );

  // Exported field_base: 'field_fixity_next_check_run_time'.
  $field_bases['field_fixity_next_check_run_time'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_next_check_run_time',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 'second',
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => '',
      'treeable' => 0,
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datestamp',
  );

  // Exported field_base: 'field_fixity_processing_time'.
  $field_bases['field_fixity_processing_time'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_processing_time',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_fixity_report'.
  $field_bases['field_fixity_report'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_report',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'hide_initial_item' => 0,
      'path' => '',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'field_collection',
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
        'Unscheduled' => 'Unscheduled',
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

  // Exported field_base: 'field_fixity_time_of_check'.
  $field_bases['field_fixity_time_of_check'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fixity_time_of_check',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 'second',
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => '',
      'treeable' => 0,
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datestamp',
  );

  return $field_bases;
}
