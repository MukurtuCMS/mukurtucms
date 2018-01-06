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
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
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
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 5,
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
    'label' => 'Frequency in Days',
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
      'weight' => 4,
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
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
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
      'weight' => 2,
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
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
  t('Frequency in Days');
  t('If no schedule is selected, this File Fixity Check can still be run manually.');
  t('Pre-Actions');
  t('Protocols');
  t('Schedule');
  t('Select Cultural Protocol(s) to limit which media assets are checked. The media asset must belong to at least one of these Cultural Protocols to be checked (the Cultural Protocol of the Digital Heritage item in which the media file is not considered). If this field is left blank, all media assets are checked. ');

  return $field_instances;
}
