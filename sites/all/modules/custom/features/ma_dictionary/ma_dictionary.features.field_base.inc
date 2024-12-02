<?php

/**
 * @file
 * ma_dictionary.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ma_dictionary_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_additional_media'.
  $field_bases['field_additional_media'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_additional_media',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_additional_media_assets'.
  $field_bases['field_additional_media_assets'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_id_type' => NULL,
    'entity_types' => array(),
    'field_name' => 'field_additional_media_assets',
    'indexes' => array(
      'sid' => array(
        0 => 'sid',
      ),
    ),
    'locked' => 0,
    'module' => 'atom_reference',
    'settings' => array(
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'atom_reference',
  );

  // Exported field_base: 'field_alternate_spelling'.
  $field_bases['field_alternate_spelling'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_alternate_spelling',
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

  // Exported field_base: 'field_aod_active'.
  $field_bases['field_aod_active'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aod_active',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Default sort',
        1 => 'User-defined sort',
      ),
      'allowed_values_function' => '',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_aod_character'.
  $field_bases['field_aod_character'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aod_character',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 1,
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_aod_language'.
  $field_bases['field_aod_language'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aod_language',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'ma_dictionary_collation_locale_options',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_aod_letter_padding'.
  $field_bases['field_aod_letter_padding'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aod_letter_padding',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_community_language'.
  $field_bases['field_community_language'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_community_language',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'language',
          'parent' => 0,
        ),
      ),
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_definition'.
  $field_bases['field_definition'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_definition',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_dictionary_word_language'.
  $field_bases['field_dictionary_word_language'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dictionary_word_language',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'language',
          'parent' => 0,
        ),
      ),
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_dictionary_word_recording'.
  $field_bases['field_dictionary_word_recording'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dictionary_word_recording',
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

  // Exported field_base: 'field_dictionary_word_related_dh'.
  $field_bases['field_dictionary_word_related_dh'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dictionary_word_related_dh',
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
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'entityreference_1',
          'view_name' => 'dh_nodes_available_to_dictionary_word',
        ),
      ),
      'target_type' => 'node',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_language_community'.
  $field_bases['field_language_community'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_language_community',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'duplicates' => 0,
      'handler' => 'og',
      'handler_settings' => array(
        'behaviors' => array(
          'og_behavior' => array(
            'status' => TRUE,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'membership_type' => 'og_membership_type_default',
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'language_community' => 'language_community',
        ),
      ),
      'target_type' => 'node',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_part_of_speech'.
  $field_bases['field_part_of_speech'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_part_of_speech',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'part_of_speech',
          'parent' => 0,
        ),
      ),
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_pronunciation'.
  $field_bases['field_pronunciation'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pronunciation',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_sample_sentence'.
  $field_bases['field_sample_sentence'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sample_sentence',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 510,
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_translation'.
  $field_bases['field_translation'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_translation',
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

  // Exported field_base: 'field_word_entry'.
  $field_bases['field_word_entry'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_word_entry',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  // Exported field_base: 'field_word_list'.
  $field_bases['field_word_list'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_word_list',
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
          'property' => 'title',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'word_list' => 'word_list',
        ),
      ),
      'target_type' => 'node',
      'treeable' => 0,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_words'.
  $field_bases['field_words'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_words',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'duplicates' => 0,
      'handler' => 'views',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'entityreference_1',
          'view_name' => 'words_available_to_collection',
        ),
      ),
      'target_type' => 'node',
      'treeable' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
