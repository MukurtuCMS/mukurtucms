<?php
/**
 * @file
 * ma_file_fixity.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ma_file_fixity_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_fixity_report-field_fixity_check_fails_count'.
  $field_instances['field_collection_item-field_fixity_report-field_fixity_check_fails_count'] = array(
    'bundle' => 'field_fixity_report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fixity_check_fails_count',
    'label' => 'Files failed',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_fixity_report-field_fixity_check_fails_details'.
  $field_instances['field_collection_item-field_fixity_report-field_fixity_check_fails_details'] = array(
    'bundle' => 'field_fixity_report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => TRUE,
            'field_collection_view_mode' => 'full',
            'link_field_display_type' => 'link_default',
            'node_reference_link' => TRUE,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'ul',
        ),
        'type' => 'textformatter_list',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fixity_check_fails_details',
    'label' => 'Check fails details',
    'required' => 0,
    'settings' => array(
      'context' => 'title',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_fixity_report-field_fixity_files_checked'.
  $field_instances['field_collection_item-field_fixity_report-field_fixity_files_checked'] = array(
    'bundle' => 'field_fixity_report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fixity_files_checked',
    'label' => 'Files checked',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_fixity_report-field_fixity_processing_time'.
  $field_instances['field_collection_item-field_fixity_report-field_fixity_processing_time'] = array(
    'bundle' => 'field_fixity_report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fixity_processing_time',
    'label' => 'Processing time',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => ' seconds',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_fixity_report-field_fixity_time_of_check'.
  $field_instances['field_collection_item-field_fixity_report-field_fixity_time_of_check'] = array(
    'bundle' => 'field_fixity_report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fixity_time_of_check',
    'label' => 'Time of check',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'treeable' => 0,
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-fixity_check-field_fixity_cps'.
  $field_instances['node-fixity_check-field_fixity_cps'] = array(
    'bundle' => 'fixity_check',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Select Cultural Protocol(s) to limit which media assets are checked. The media asset must belong to at least one of these Cultural Protocols to be checked (the Cultural Protocol of the Digital Heritage item in which the media file is not considered). If this field is left blank, all media assets are checked. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_fixity_cps',
    'label' => 'Protocols',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
        'treeable' => 0,
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-fixity_check-field_fixity_days_frequency'.
  $field_instances['node-fixity_check-field_fixity_days_frequency'] = array(
    'bundle' => 'fixity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_fixity_days_frequency',
    'label' => 'Frequency in days',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-fixity_check-field_fixity_latest_check_status'.
  $field_instances['node-fixity_check-field_fixity_latest_check_status'] = array(
    'bundle' => 'fixity_check',
    'default_value' => array(
      0 => array(
        'value' => 'not_run',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_fixity_latest_check_status',
    'label' => 'Latest check result',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'treeable' => 0,
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-fixity_check-field_fixity_latest_check_time'.
  $field_instances['node-fixity_check-field_fixity_latest_check_time'] = array(
    'bundle' => 'fixity_check',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_fixity_latest_check_time',
    'label' => 'Latest check time',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'treeable' => 0,
        'year_range' => '-3:+3',
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-fixity_check-field_fixity_report'.
  $field_instances['node-fixity_check-field_fixity_report'] = array(
    'bundle' => 'fixity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_fixity_report',
    'label' => 'Checks',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'field_collection_hidden',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-fixity_check-field_fixity_schedule'.
  $field_instances['node-fixity_check-field_fixity_schedule'] = array(
    'bundle' => 'fixity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If no schedule is selected, this File Fixity Check can still be run manually.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_fixity_schedule',
    'label' => 'Schedule',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-fixity_check-field_pre_actions'.
  $field_instances['node-fixity_check-field_pre_actions'] = array(
    'bundle' => 'fixity_check',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_pre_actions',
    'label' => 'Pre-Actions',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'treeable' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Check fails details');
  t('Checks');
  t('Files checked');
  t('Files failed');
  t('Frequency in days');
  t('If no schedule is selected, this File Fixity Check can still be run manually.');
  t('Latest check result');
  t('Latest check time');
  t('Pre-Actions');
  t('Processing time');
  t('Protocols');
  t('Schedule');
  t('Select Cultural Protocol(s) to limit which media assets are checked. The media asset must belong to at least one of these Cultural Protocols to be checked (the Cultural Protocol of the Digital Heritage item in which the media file is not considered). If this field is left blank, all media assets are checked. ');
  t('Time of check');

  return $field_instances;
}
