<?php

/**
 * @file
 * ma_profile.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ma_profile_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'og_membership-og_membership_type_default-og_membership_request'.
  $field_instances['og_membership-og_membership_type_default-og_membership_request'] = array(
    'bundle' => 'og_membership_type_default',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the text a user may send to the group administrators.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'og_membership',
    'field_name' => 'og_membership_request',
    'label' => 'Request message',
    'required' => FALSE,
    'settings' => array(
      'context' => '',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'user-user-field_mm_sync'.
  $field_instances['user-user-field_mm_sync'] = array(
    'bundle' => 'user',
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_mm_sync',
    'label' => 'Synced to Mukurtu Mobile',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'user-user-field_dhan_frequency'.
  $field_instances['user-user-field_dhan_frequency'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'display_label' => '',
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_dhan_frequency',
    'label' => 'DHAN Frequency',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );
  
  // Exported field_instance: 'user-user-field_notifications_freq_def'.
  $field_instances['user-user-field_notifications_freq_def'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 'right away',
      ),
    ),
    'deleted' => 0,
    'description' => 'This can be overridden per content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'display_label' => '',
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_notifications_freq_def',
    'label' => 'Notifications Email Frequency Default',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-og_user_node'.
  $field_instances['user-user-og_user_node'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'use_content_language' => 1,
          'view_mode' => 'teaser',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'og_user_node',
    'label' => 'Communities',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'select2_integration' => array(
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 1,
      ),
      'user_register_form' => 1,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_list_default',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_list_default',
      ),
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Communities');
  t('DHAN Frequency');
  t('Notifications Email Frequency Default');
  t('Request message');
  t('Synced to Mukurtu Mobile');
  t('This can be overridden per content.');
  t('This is the text a user may send to the group administrators.');

  return $field_instances;
}
