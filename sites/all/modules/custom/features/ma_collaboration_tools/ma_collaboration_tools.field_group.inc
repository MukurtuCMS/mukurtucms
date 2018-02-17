<?php
/**
 * @file
 * ma_collaboration_tools.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_collaboration_tools_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|calendar|form';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '3',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_item_privacy_setting',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-access field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_access|node|calendar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|calendar|full';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Visibility',
    'weight' => '6',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_item_privacy_setting',
      2 => 'field_community_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Visibility',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-access field-group-div block-title',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_access|node|calendar|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|discussion_space|form';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion_space';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '3',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_item_privacy_setting',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-access field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_access|node|discussion_space|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|discussion_space|full';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion_space';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Visibility',
    'weight' => '4',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_item_privacy_setting',
      2 => 'field_community_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Visibility',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-access field-group-div block-title',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_access|node|discussion_space|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|document_library|form';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_library';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '3',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_item_privacy_setting',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-access field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_access|node|document_library|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|document_library|full';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_library';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Visibility',
    'weight' => '4',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_item_privacy_setting',
      2 => 'field_community_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Visibility',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-access field-group-div block-title',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_access|node|document_library|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collab_actions|node|calendar|full';
  $field_group->group_name = 'group_collab_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '3',
    'children' => array(
      0 => 'add_content_to_collab_sect_link',
      1 => 'edit_collab_section_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-collab-actions field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_collab_actions|node|calendar|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collab_actions|node|discussion_space|full';
  $field_group->group_name = 'group_collab_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion_space';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '3',
    'children' => array(
      0 => 'add_content_to_collab_sect_link',
      1 => 'edit_collab_section_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-collab-actions field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_collab_actions|node|discussion_space|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collab_actions|node|document_library|full';
  $field_group->group_name = 'group_collab_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_library';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '3',
    'children' => array(
      0 => 'add_content_to_collab_sect_link',
      1 => 'edit_collab_section_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Actions',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-collab-actions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_collab_actions|node|document_library|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access');
  t('Actions');
  t('Visibility');

  return $field_groups;
}
