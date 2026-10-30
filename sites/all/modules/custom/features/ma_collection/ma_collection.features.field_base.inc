<?php

/**
 * @file
 * ma_collection.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ma_collection_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_collection_credit'.
  $field_bases['field_collection_credit'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_collection_credit',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_collection_image'.
  $field_bases['field_collection_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_collection_image',
    'indexes' => array(
      'sid' => array(
        0 => 'sid',
      ),
    ),
    'locked' => 0,
    'module' => 'atom_reference',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'atom_reference',
  );

  // Exported field_base: 'field_collection_summary'.
  $field_bases['field_collection_summary'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_collection_summary',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_collections_child_coll'.
  $field_bases['field_collections_child_coll'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_collections_child_coll',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'duplicates' => 1,
      'handler' => 'views',
      'handler_settings' => array(
        'behaviors' => array(
          'treeable_behavior' => array(
            'status' => 1,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(
            0 => '[node:nid]',
          ),
          'display_name' => 'entityreference_1',
          'view_name' => 'child_collections_entity_reference',
        ),
      ),
      'target_type' => 'node',
      'treeable' => 1,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_collections_parent_coll'.
  $field_bases['field_collections_parent_coll'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_collections_parent_coll',
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
          'type' => 'none',
        ),
        'target_bundles' => array(
          'collection' => 'collection',
        ),
      ),
      'target_type' => 'node',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_digital_heritage_count'.
  $field_bases['field_digital_heritage_count'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_digital_heritage_count',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_digital_heritage_items'.
  $field_bases['field_digital_heritage_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_digital_heritage_items',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'duplicates' => 1,
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
          'property' => 'type',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'dictionary_word' => 'dictionary_word',
          'digital_heritage' => 'digital_heritage',
          'person' => 'person',
          'word_list' => 'word_list',
        ),
      ),
      'target_type' => 'node',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_personal_coll_privacy'.
  $field_bases['field_personal_coll_privacy'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_personal_coll_privacy',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'private' => 'Private',
        'public' => 'Public',
      ),
      'allowed_values_function' => '',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
