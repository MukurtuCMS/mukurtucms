<?php

/**
 * @file
 * ma_base_theme.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ma_base_theme_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-hero_image_one_column-field_hero_image'.
  $field_instances['bean-hero_image_one_column-field_hero_image'] = array(
    'bundle' => 'hero_image_one_column',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_banner_image',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_hero_image',
    'label' => 'Hero Image',
    'required' => 1,
    'settings' => array(
      'allow_override' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'referencable_types' => array(
        'audio' => 0,
        'file' => 0,
        'gallery' => 0,
        'image' => 'image',
        'video' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'atom_reference',
      'settings' => array(
        'context' => 'sdl_editor_representation',
        'treeable' => 0,
      ),
      'type' => 'atom_reference_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'bean-hero_image_one_column-field_hero_image_caption'.
  $field_instances['bean-hero_image_one_column-field_hero_image_caption'] = array(
    'bundle' => 'hero_image_one_column',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_hero_image_caption',
    'label' => 'Hero Image Caption',
    'required' => 0,
    'settings' => array(
      'context' => 'title',
      'context_default' => 'sdl_editor_representation',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
        'treeable' => 0,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bean-hero_image_two_columns-field_hero_image'.
  $field_instances['bean-hero_image_two_columns-field_hero_image'] = array(
    'bundle' => 'hero_image_two_columns',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_banner_image',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_hero_image',
    'label' => 'Hero Image',
    'required' => 1,
    'settings' => array(
      'allow_override' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'referencable_types' => array(
        'audio' => 0,
        'file' => 0,
        'gallery' => 0,
        'image' => 'image',
        'video' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'atom_reference',
      'settings' => array(
        'context' => 'mukurtu_scald_banner_image',
        'treeable' => 0,
      ),
      'type' => 'atom_reference_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'bean-hero_image_two_columns-field_welcome_message'.
  $field_instances['bean-hero_image_two_columns-field_welcome_message'] = array(
    'bundle' => 'hero_image_two_columns',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_welcome_message',
    'label' => 'Welcome Message',
    'required' => 0,
    'settings' => array(
      'context' => 'mukurtu_scald_taxonomy_thumbnail',
      'context_default' => 'mukurtu_featured_content',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 1,
      'mee_enabled' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 10,
        'treeable' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-hero_image_two_columns-field_welcome_title'.
  $field_instances['bean-hero_image_two_columns-field_welcome_title'] = array(
    'bundle' => 'hero_image_two_columns',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_welcome_title',
    'label' => 'Welcome Title',
    'required' => 0,
    'settings' => array(
      'context' => 'title',
      'context_default' => 'sdl_editor_representation',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
        'treeable' => 0,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Hero Image');
  t('Hero Image Caption');
  t('Welcome Message');
  t('Welcome Title');

  return $field_instances;
}
