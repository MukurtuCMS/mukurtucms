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
    'weight' => '5',
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
    'weight' => '3',
    'children' => array(
      0 => 'field_community_ref',
      1 => 'field_item_privacy_setting',
      2 => 'og_group_ref',
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
    'weight' => '6',
    'children' => array(
      0 => 'field_community_ref',
      1 => 'field_item_privacy_setting',
      2 => 'og_group_ref',
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
    'weight' => '4',
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
    'weight' => '2',
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
    'weight' => '5',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|document_library|full';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_library';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '3',
    'children' => array(
      0 => 'generic_dynamic_field_2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-documents field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_documents|node|document_library|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_details|node|event|full';
  $field_group->group_name = 'group_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_event_calendar_section',
      1 => 'field_oa_address',
      2 => 'field_oa_date',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-event-details field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_event_details|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_following|node|discussion_topic|form';
  $field_group->group_name = 'group_following';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion_topic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Following',
    'weight' => '4',
    'children' => array(
      0 => 'field_following_protocols',
      1 => 'field_following_users',
      2 => 'field_un_following_users',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Following',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-following field-group-fieldset',
        'description' => '<p>Users that are following a discussion topic are emailed updates when there are any comments on the discussion topic.</p>
<p>Protocol Stewards may add their protocol(s) here if this discussion topic is within that protocol, and all members of that protocol will then be following the discussion topic. Individual users may also follow the discussion topic independently of their protocol memberships. They can also unfollow an discussion topic even if they would otherwise be following it due to protocol membership.</p>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_following|node|discussion_topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_following|node|discussion_topic|full';
  $field_group->group_name = 'group_following';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion_topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Following',
    'weight' => '4',
    'children' => array(
      0 => 'field_following_protocols',
      1 => 'field_following_users',
      2 => 'field_un_following_users',
      3 => 'follow_unfollow',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-following field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_following|node|discussion_topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_following|node|document_page|default';
  $field_group->group_name = 'group_following';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Following',
    'weight' => '4',
    'children' => array(
      0 => 'field_following_protocols',
      1 => 'field_following_users',
      2 => 'field_un_following_users',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-following field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_following|node|document_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_following|node|document_page|form';
  $field_group->group_name = 'group_following';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Following',
    'weight' => '6',
    'children' => array(
      0 => 'field_following_protocols',
      1 => 'field_following_users',
      2 => 'field_un_following_users',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Following',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-following field-group-fieldset',
        'description' => '<p>Users that are following an document are emailed updates when there are any changes to the document, or comments on the document.</p>
<p>Protocol Stewards may add their protocol(s) here if this document is within that protocol, and all members of that protocol will then be following the document. Individual users may also follow the document independently of their protocol memberships. They can also unfollow an document even if they would otherwise be following it due to protocol membership.</p>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_following|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_following|node|document_page|full';
  $field_group->group_name = 'group_following';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Following',
    'weight' => '4',
    'children' => array(
      0 => 'field_following_protocols',
      1 => 'field_following_users',
      2 => 'field_un_following_users',
      3 => 'follow_unfollow',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-following field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_following|node|document_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_following|node|event|form';
  $field_group->group_name = 'group_following';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Following',
    'weight' => '6',
    'children' => array(
      0 => 'field_following_protocols',
      1 => 'field_following_users',
      2 => 'field_un_following_users',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Following',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-following field-group-fieldset',
        'description' => '<p>Users that are following an event are emailed updates when there are any changes to the event, or comments on the event.</p>
<p>Protocol Stewards may add their protocol(s) here if this event is within that protocol, and all members of that protocol will then be following the event. Individual users may also follow the event independently of their protocol memberships. They can also unfollow an event even if they would otherwise be following it due to protocol membership.</p>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_following|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_following|node|event|full';
  $field_group->group_name = 'group_following';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Following',
    'weight' => '6',
    'children' => array(
      0 => 'field_following_protocols',
      1 => 'field_following_users',
      2 => 'field_un_following_users',
      3 => 'follow_unfollow',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-following field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_following|node|event|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access');
  t('Actions');
  t('Documents');
  t('Event Details');
  t('Following');
  t('Visibility');

  return $field_groups;
}
