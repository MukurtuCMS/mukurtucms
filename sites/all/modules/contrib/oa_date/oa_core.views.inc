<?php

/**
 * @file
 * Code for the OpenAtrium Core views alterations.
 */


/**
 * Implements hook_views_data().
 */
function oa_core_views_data() {
  $data = array();

  $data['field_data_oa_parent']['is_parent'] = array(
    'title' => t('Is Parent'),
    'help' => t('Content is a parent'),
    'filter' => array(
      'handler' => 'views_handler_filter_is_parent',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter
 */
function oa_core_views_data_alter(&$data) {
  if (isset($data['og_membership']['og_group_ref_target_id']['filter']['handler'])) {
    $data['og_membership']['og_group_ref_target_id']['filter']['handler'] = 'oa_core_og_group_ref_views_handler_filter_entityreference_autocomplete';
  }
  if (isset($data['field_data_field_oa_message_space']['field_oa_message_space_target_id']['filter']['handler'])) {
    $data['field_data_field_oa_message_space']['field_oa_message_space_target_id']['filter']['handler'] = 'oa_core_og_group_ref_views_handler_filter_entityreference_autocomplete';
  }
  if (isset($data['og_membership']['oa_parent_space_target_id']['filter']['handler'])) {
    $data['og_membership']['oa_parent_space_target_id']['filter']['handler'] = 'oa_core_og_group_ref_views_handler_filter_in_operator';
  }

  // Add option to expand to parent GIDs.
  if (isset($data['og_membership']['gid']) && module_exists('oa_subspaces')) {
    $data['og_membership']['gid']['argument']['handler'] = 'oa_core_views_handler_argument_numeric_og_membership_gid';
  }

  if (isset($data['field_data_oa_section_ref']['oa_section_ref_target_id']['filter']['handler'])) {
    $data['field_data_oa_section_ref']['oa_section_ref_target_id']['filter']['handler'] = 'oa_core_oa_section_ref_views_handler_filter_in_operator';
  }
}

/**
 * Implements hook_views_plugins().
 */
function oa_core_views_plugins() {
  return array(
    'exposed_form' => array(
      'oa_form' => array(
        'title' => t('Open Atrium'),
        'help' => t('Open Atrium exposed filter form adds some options that integrate with Bootstrap.'),
        'handler' => 'oa_views_plugin_exposed_form',
        'uses options' => TRUE,
      ),
    ),
  );
}
