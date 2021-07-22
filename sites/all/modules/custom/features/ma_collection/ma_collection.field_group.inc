<?php

/**
 * @file
 * ma_collection.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ma_collection_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|collection|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_collection_credit',
      1 => 'field_collection_image',
      2 => 'field_collection_summary',
      3 => 'field_description',
      4 => 'field_tags',
      5 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Basic',
    ),
    'format_type' => 'htab',
    'label' => 'Basic',
    'weight' => '1',
  );
  $field_groups['group_basic|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|personal_collection|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'personal_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_collection_image',
      1 => 'field_collection_summary',
      2 => 'field_personal_coll_privacy',
      3 => 'field_description',
      4 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-basic field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Basic',
    ),
    'format_type' => 'htab',
    'label' => 'Basic',
    'weight' => '14',
  );
  $field_groups['group_basic|node|personal_collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collections_related|node|collection|form';
  $field_group->group_name = 'group_collections_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_collections_child_coll',
      1 => 'field_collections_parent_coll',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-collections-related field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Collections Tree',
    ),
    'format_type' => 'htab',
    'label' => 'Collections Tree',
    'weight' => '3',
  );
  $field_groups['group_collections_related|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_digital_heritage_items|node|collection|form';
  $field_group->group_name = 'group_digital_heritage_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_digital_heritage_items',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 0,
      ),
      'label' => 'Digital Heritage Items',
    ),
    'format_type' => 'htab',
    'label' => 'Digital Heritage Items',
    'weight' => '2',
  );
  $field_groups['group_digital_heritage_items|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_items|node|collection|form';
  $field_group->group_name = 'group_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_digital_heritage_items',
      1 => 'field_item_privacy_setting',
      2 => 'og_group_ref',
      3 => 'field_related_content',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-items field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Relations',
    ),
    'format_type' => 'htab',
    'label' => 'Relations',
    'weight' => '2',
  );
  $field_groups['group_items|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_items|node|personal_collection|form';
  $field_group->group_name = 'group_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'personal_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_digital_heritage_items',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-items field-group-htab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Items',
    ),
    'format_type' => 'htab',
    'label' => 'Items',
    'weight' => '15',
  );
  $field_groups['group_items|node|personal_collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_view_fields|node|collection|search_result';
  $field_group->group_name = 'group_list_view_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_collection_credit',
      1 => 'field_collection_summary',
      2 => 'featured_content_type',
      3 => 'mukurtu_icon_actions',
      4 => 'mukurtu_mobile_sync',
      5 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'List View Fields',
    ),
    'format_type' => 'div',
    'label' => 'List View Fields',
    'weight' => '1',
  );
  $field_groups['group_list_view_fields|node|collection|search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_view_fields|node|personal_collection|search_result';
  $field_group->group_name = 'group_list_view_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'personal_collection';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_collection_summary',
      1 => 'featured_content_type',
      2 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'List View Fields',
    ),
    'format_type' => 'div',
    'label' => 'List View Fields',
    'weight' => '27',
  );
  $field_groups['group_list_view_fields|node|personal_collection|search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relations|node|personal_collection|form';
  $field_group->group_name = 'group_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'personal_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'children' => array(
      0 => 'field_digital_heritage_items',
      1 => 'field_related_content',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-relations field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Relations',
    'weight' => '15',
  );
  $field_groups['group_relations|node|personal_collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|collection|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'group_basic',
      1 => 'group_collections_related',
      2 => 'group_items',
    ),
    'format_settings' => array(
      'instance_settings' => array(
        'classes' => '',
      ),
      'label' => 'Tabs',
    ),
    'format_type' => 'htabs',
    'label' => 'Tabs',
    'weight' => '1',
  );
  $field_groups['group_tabs|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|personal_collection|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'personal_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'group_relations',
      1 => 'group_basic',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
        'id' => '',
      ),
    ),
    'format_type' => 'htabs',
    'label' => 'Tabs',
    'weight' => '1',
  );
  $field_groups['group_tabs|node|personal_collection|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic');
  t('Collections Tree');
  t('Digital Heritage Items');
  t('Items');
  t('List View Fields');
  t('Relations');
  t('Tabs');

  return $field_groups;
}
