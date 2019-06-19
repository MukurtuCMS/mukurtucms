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
    'label' => 'Basic',
    'weight' => '1',
    'children' => array(
      0 => 'field_collection_credit',
      1 => 'field_collection_image',
      2 => 'field_collection_summary',
      3 => 'field_description',
      4 => 'field_tags',
      5 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'Basic',
    'weight' => '14',
    'children' => array(
      0 => 'field_collection_image',
      1 => 'field_collection_summary',
      2 => 'field_personal_coll_privacy',
      3 => 'field_description',
      4 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-basic field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'Collections Tree',
    'weight' => '3',
    'children' => array(
      0 => 'field_collections_child_coll',
      1 => 'field_collections_parent_coll',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Collections Tree',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-collections-related field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'Digital Heritage Items',
    'weight' => '2',
    'children' => array(
      0 => 'field_digital_heritage_items',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Digital Heritage Items',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'Relations',
    'weight' => '2',
    'children' => array(
      0 => 'field_digital_heritage_items',
      1 => 'field_item_privacy_setting',
      2 => 'og_group_ref',
      3 => 'field_related_content',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Relations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-items field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'Items',
    'weight' => '15',
    'children' => array(
      0 => 'field_digital_heritage_items',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Items',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-items field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'List View Fields',
    'weight' => '1',
    'children' => array(
      0 => 'field_collection_credit',
      1 => 'field_collection_summary',
      2 => 'featured_content_type',
      3 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'List View Fields',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'List View Fields',
    'weight' => '27',
    'children' => array(
      0 => 'field_collection_summary',
      1 => 'featured_content_type',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'List View Fields',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
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
    'label' => 'Relations',
    'weight' => '15',
    'children' => array(
      0 => 'field_digital_heritage_items',
      1 => 'field_related_content',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-relations field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
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
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_basic',
      1 => 'group_collections_related',
      2 => 'group_items',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Tabs',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
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
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_relations',
      1 => 'group_basic',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
        'id' => '',
      ),
    ),
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
