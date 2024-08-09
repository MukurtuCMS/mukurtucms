<?php

/**
 * @file
 * ma_dictionary.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ma_dictionary_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'alphabetical_order_definition-alphabetical_order_definition-field_aod_active'.
  $field_instances['alphabetical_order_definition-alphabetical_order_definition-field_aod_active'] = array(
    'bundle' => 'alphabetical_order_definition',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'alphabetical_order_definition',
    'field_name' => 'field_aod_active',
    'label' => 'Sort Method',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'alphabetical_order_definition-alphabetical_order_definition-field_aod_character'.
  $field_instances['alphabetical_order_definition-alphabetical_order_definition-field_aod_character'] = array(
    'bundle' => 'alphabetical_order_definition',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter <b>all</b> the characters of the language(s) on the site, then drag and drop them into their correct alphabetical order.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'alphabetical_order_definition',
    'field_name' => 'field_aod_character',
    'label' => 'Characters',
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
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'alphabetical_order_definition-alphabetical_order_definition-field_aod_language'.
  $field_instances['alphabetical_order_definition-alphabetical_order_definition-field_aod_language'] = array(
    'bundle' => 'alphabetical_order_definition',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
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
    'entity_type' => 'alphabetical_order_definition',
    'field_name' => 'field_aod_language',
    'label' => 'Sort Language',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'select2_integration' => array(
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 1,
      ),
      'user_register_form' => FALSE,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'alphabetical_order_definition-alphabetical_order_definition-field_aod_letter_padding'.
  $field_instances['alphabetical_order_definition-alphabetical_order_definition-field_aod_letter_padding'] = array(
    'bundle' => 'alphabetical_order_definition',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Normally, the glossary title letter filter will "pad" itself with all letters from A-Z for which there are no words in the site\'s glossary that start with that letter. Unlike the other letters, they are unlinked. Their purpose is to provide a complete-looking alphabet in the filter. However, if the language(s) of the glossary does not include all the letters from A-Z, it would be preferable to leave out the letters which do not exist in the language. Click this checkbox to disable padding of the glossary with all the letters from A-Z. Only the first letter of words in the glossary will remain in the filter.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'alphabetical_order_definition',
    'field_name' => 'field_aod_letter_padding',
    'label' => 'Do not pad the glossary letter filter',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_additional_media'.
  $field_instances['node-dictionary_word-field_additional_media'] = array(
    'bundle' => 'dictionary_word',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Include any media or additional information that does not fit in the other fields here. You are allowed to drag items from the media library into this field. For this to work, there must be some content below where you place the item (even just a blank line). The media item will be inserted, along with a line of text showing its title and author (which you may choose to remove). Note, certain media types (e.g., audio, YouTube video) do not render well or at all within the edit box, but show correctly within the content view. If you wish to visualize or adjust the placement of such media items, try switching to the plain text editor.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_additional_media',
    'label' => 'Additional Media',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
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
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 28,
    ),
  );

  // Exported field_instance:
  // 'node-dictionary_word-field_additional_media_assets'.
  $field_instances['node-dictionary_word-field_additional_media_assets'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'In Mukurtu CMS v4, the "Additional Media" field is no longer included and will not be migrated. This field will be migrated to the "Media Assets" field. It is recommended to move media asset references from the "Additional Media" field to this field.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_dictionary_media',
        'weight' => 40,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'field_additional_media_assets',
    'label' => 'Additional Media Assets',
    'required' => 0,
    'settings' => array(
      'allow_override' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'referencable_types' => array(
        'audio' => 'audio',
        'file' => 'file',
        'image' => 'image',
        'video' => 'video',
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
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_collection'.
  $field_instances['node-dictionary_word-field_collection'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Collections are curated, narrated groups of content within a site. Collections can contain content from more than one Community, and content can belong to multiple Collections. You can search for Collections by typing in this text box, then selecting the Collection. You can drag the Collections within this text box to change the order in which they will appear when viewing this Dictionary Word.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => 1,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 7,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => 0,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
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
    'field_name' => 'field_collection',
    'label' => 'Collections',
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
      'user_register_form' => FALSE,
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
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_community_ref'.
  $field_instances['node-dictionary_word-field_community_ref'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'node_reference_link' => 1,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 4,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'display_label' => '',
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_community_ref',
    'label' => 'Community',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'select2_integration' => array(
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 1,
      ),
      'user_register_form' => FALSE,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'node-dictionary_word-field_dictionary_word_language'.
  $field_instances['node-dictionary_word-field_dictionary_word_language'] = array(
    'bundle' => 'dictionary_word',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A dictionary word must be associated with a single language on the site.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_dictionary_word_language',
    'label' => 'Language',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 25,
    ),
  );

  // Exported field_instance:
  // 'node-dictionary_word-field_dictionary_word_related_dh'.
  $field_instances['node-dictionary_word-field_dictionary_word_related_dh'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'A reference to one or many related digital heritage items.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_dictionary_word_related_dh',
    'label' => 'Related Digital Heritage Items',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_item_privacy_setting'.
  $field_instances['node-dictionary_word-field_item_privacy_setting'] = array(
    'bundle' => 'dictionary_word',
    'default_value' => array(
      0 => array(
        'value' => 'all',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_item_privacy_setting',
    'label' => 'Item Sharing Settings',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_language_community'.
  $field_instances['node-dictionary_word-field_language_community'] = array(
    'bundle' => 'dictionary_word',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_language_community',
    'label' => 'Language Community',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_media_asset'.
  $field_instances['node-dictionary_word-field_media_asset'] = array(
    'bundle' => 'dictionary_word',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'title',
        'weight' => 26,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_media_asset',
    'label' => 'Media Assets',
    'required' => 0,
    'settings' => array(
      'allow_override' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'referencable_types' => array(
        'audio' => 'audio',
        'file' => 'file',
        'image' => 'image',
        'video' => 'video',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_personal_collections'.
  $field_instances['node-dictionary_word-field_personal_collections'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
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
    'field_name' => 'field_personal_collections',
    'label' => 'Personal Collections',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_pre_actions'.
  $field_instances['node-dictionary_word-field_pre_actions'] = array(
    'bundle' => 'dictionary_word',
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
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_pre_actions',
    'label' => 'Pre-Actions',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_related_content'.
  $field_instances['node-dictionary_word-field_related_content'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'You can search for related content by typing in this text box, then selecting the content. You can drag the selected content within this text box to change the order in which they will appear when viewing this Dictionary Word.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'mukurtu_related_items_formatter',
        'settings' => array(
          'items_per_page' => 5,
        ),
        'type' => 'mukurtu_related_items_formatter',
        'weight' => 10,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
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
    'field_name' => 'field_related_content',
    'label' => 'Related Content',
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
      'user_register_form' => FALSE,
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
      'weight' => 30,
    ),
  );

  // Exported field_instance:
  // 'node-dictionary_word-field_related_dictionary_words'.
  $field_instances['node-dictionary_word-field_related_dictionary_words'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'A reference to one or many related dictionary words.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_related_dictionary_words',
    'label' => 'Related Dictionary Words',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_tags'.
  $field_instances['node-dictionary_word-field_tags'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'Keywords provide added ways to group your content. They make it easier for users to search and retrieve content. Separate multiple keywords with semicolons.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 6,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Keywords',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'select2_integration' => array(
        'allow_add_onfly' => 0,
        'show_voc_terms_page_link' => 0,
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 1,
      ),
      'user_register_form' => FALSE,
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
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_thumbnail_image'.
  $field_instances['node-dictionary_word-field_thumbnail_image'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_thumbnail_image',
        'weight' => 41,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'field_thumbnail_image',
    'label' => 'Thumbnail Image',
    'required' => 0,
    'settings' => array(
      'allow_override' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'referencable_types' => array(
        'audio' => 0,
        'file' => 0,
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
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_word_entry'.
  $field_instances['node-dictionary_word-field_word_entry'] = array(
    'bundle' => 'dictionary_word',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'dictionary_word_summary' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'dictionary_word_summary',
        ),
        'type' => 'paragraphs_view',
        'weight' => 2,
      ),
      'featured_content' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'featured_content',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'mukurtu_mobile' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'word_entry_search_results',
        ),
        'type' => 'paragraphs_view',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'featured_content',
        ),
        'type' => 'paragraphs_view',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_word_entry',
    'label' => 'Word Entry',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'dictionary_word_bundle' => 'dictionary_word_bundle',
      ),
      'bundle_weights' => array(
        'dictionary_word_bundle' => 2,
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_edit_mode' => 'open',
      'default_edit_mode_override' => 1,
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-field_word_list'.
  $field_instances['node-dictionary_word-field_word_list'] = array(
    'bundle' => 'dictionary_word',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'A word list is an collection of dictionary words.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => 1,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 33,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_word_list',
    'label' => 'Word List',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-dictionary_word-og_group_ref'.
  $field_instances['node-dictionary_word-og_group_ref'] = array(
    'bundle' => 'dictionary_word',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => 1,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 5,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => 0,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Protocol',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
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
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'node-language_community-field_community_language'.
  $field_instances['node-language_community-field_community_language'] = array(
    'bundle' => 'language_community',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
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
    'field_name' => 'field_community_language',
    'label' => 'Community Language',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-language_community-group_group'.
  $field_instances['node-language_community-group_group'] = array(
    'bundle' => 'language_community',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Determine if this is an OG group.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(
          'field_name' => FALSE,
        ),
        'type' => 'og_group_subscribe',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => 1,
    'entity_type' => 'node',
    'field_name' => 'group_group',
    'label' => 'Group',
    'required' => FALSE,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_group_subscribe',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_group_subscribe',
      ),
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'og_hide' => TRUE,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-language_community-og_group_ref'.
  $field_instances['node-language_community-og_group_ref'] = array(
    'bundle' => 'language_community',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(),
        'type' => 'og_list_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Groups audience',
    'required' => FALSE,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
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
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-word_list-field_collection'.
  $field_instances['node-word_list-field_collection'] = array(
    'bundle' => 'word_list',
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
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 8,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => 1,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 6,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
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
    'field_name' => 'field_collection',
    'label' => 'Collections',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-word_list-field_collection_credit'.
  $field_instances['node-word_list-field_collection_credit'] = array(
    'bundle' => 'word_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_collection_credit',
    'label' => 'Credit',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
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
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-word_list-field_collection_image'.
  $field_instances['node-word_list-field_collection_image'] = array(
    'bundle' => 'word_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'ma_colorbox',
        'weight' => 0,
      ),
      'featured_content' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_featured_content',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_featured_content',
        'weight' => 1,
      ),
      'mukurtu_mobile' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'ma_colorbox',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 1,
          'override' => 0,
        ),
        'type' => 'ma_scald_search_results',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'ma_scald_search_results',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_collection_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'referencable_types' => array(
        'audio' => 0,
        'file' => 0,
        'image' => 'image',
        'video' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'atom_reference',
      'settings' => array(
        'context' => 'mukurtu_scald_media_assets_edit_',
      ),
      'type' => 'atom_reference_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-word_list-field_collection_summary'.
  $field_instances['node-word_list-field_collection_summary'] = array(
    'bundle' => 'word_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'featured_content' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_collection_summary',
    'label' => 'Summary',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
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
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-word_list-field_community_ref'.
  $field_instances['node-word_list-field_community_ref'] = array(
    'bundle' => 'word_list',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 12,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'field_community_ref',
    'label' => 'Community',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'select2_integration' => array(
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-word_list-field_description'.
  $field_instances['node-word_list-field_description'] = array(
    'bundle' => 'word_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'You are allowed to drag items from the media library into this field. For this to work, there must be some content below where you place the item (even just a blank line). The media item will be inserted, along with a line of text showing its title and author (which you may choose to remove). Note, certain media types (eg. audio, Youtube video) do not render well or at all within the edit box, but show correctly within the content view. If you wish to visualize or adjust the placement of such media items, try switching to the plain text editor.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'custom_add_another' => '',
      'custom_remove' => '',
      'display_summary' => 0,
      'dnd_enabled' => 1,
      'mee_enabled' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-word_list-field_item_privacy_setting'.
  $field_instances['node-word_list-field_item_privacy_setting'] = array(
    'bundle' => 'word_list',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 'all',
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
        'weight' => 10,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'field_item_privacy_setting',
    'label' => 'Item Sharing Settings',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-word_list-field_personal_collections'.
  $field_instances['node-word_list-field_personal_collections'] = array(
    'bundle' => 'word_list',
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
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 9,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
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
    'field_name' => 'field_personal_collections',
    'label' => 'Personal Collections',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-word_list-field_pre_actions'.
  $field_instances['node-word_list-field_pre_actions'] = array(
    'bundle' => 'word_list',
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
        'weight' => 5,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_pre_actions',
    'label' => 'Pre-Actions',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-word_list-field_related_content'.
  $field_instances['node-word_list-field_related_content'] = array(
    'bundle' => 'word_list',
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
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 7,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'mukurtu_related_items_formatter',
        'settings' => array(
          'items_per_page' => 5,
        ),
        'type' => 'mukurtu_related_items_formatter',
        'weight' => 8,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
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
    'field_name' => 'field_related_content',
    'label' => 'Related Content',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'treeable' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-word_list-field_tags'.
  $field_instances['node-word_list-field_tags'] = array(
    'bundle' => 'word_list',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'Keywords provide added ways to group your content. They make it easier for users to search and retrieve content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Keywords',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'select2_integration' => array(
        'allow_add_onfly' => 1,
        'show_voc_terms_page_link' => 0,
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 1,
      ),
      'user_register_form' => FALSE,
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-word_list-field_words'.
  $field_instances['node-word_list-field_words'] = array(
    'bundle' => 'word_list',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => ' The display order of the Words can be changed by dragging and dropping them into the preferred order.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'use_content_language' => TRUE,
          'view_mode' => 'teaser',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 4,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'mukurtu_display_formatters_paged_node',
        'settings' => array(
          'item_view_mode' => 'dictionary_word_summary',
          'items_per_page' => 10,
        ),
        'type' => 'mukurtu_paged_node_formatter',
        'weight' => 6,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => 0,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'display_label' => '',
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_words',
    'label' => 'Words',
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
      'user_register_form' => FALSE,
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

  // Exported field_instance: 'node-word_list-og_group_ref'.
  $field_instances['node-word_list-og_group_ref'] = array(
    'bundle' => 'word_list',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(),
        'type' => 'og_list_default',
        'weight' => 11,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'og_group_ref',
    'label' => 'Protocol',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
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
      'active' => 0,
      'module' => 'og',
      'settings' => array(
        'treeable' => 0,
      ),
      'type' => 'og_complex',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_alternate_spelling'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_alternate_spelling'] = array(
    'bundle' => 'dictionary_word_bundle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If the spelling of an entry differs from the term, enter it here. Leave blank otherwise.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'dictionary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'dictionary_word_summary' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'featured_content' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'mukurtu_mobile' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'word_entry_search_results' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_alternate_spelling',
    'label' => 'Alternate Spelling',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
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
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_definition'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_definition'] = array(
    'bundle' => 'dictionary_word_bundle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'dictionary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'featured_content' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'word_entry_search_results' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_definition',
    'label' => 'Definition',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 1,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_dictionary_word_recording'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_dictionary_word_recording'] = array(
    'bundle' => 'dictionary_word_bundle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_recording',
        'weight' => 5,
      ),
      'dictionary_teaser' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_dictionary_media',
        'weight' => 5,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_recording',
        'weight' => 2,
      ),
      'featured_content' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_recording',
        'weight' => 2,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_recording',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'above',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'override' => 0,
        ),
        'type' => 'mukurtu_scald_dictionary_media',
        'weight' => 17,
      ),
      'word_entry_search_results' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_dictionary_word_recording',
    'label' => 'Recording',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'referencable_types' => array(
        'audio' => 'audio',
        'file' => 0,
        'image' => 0,
        'video' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'atom_reference',
      'settings' => array(
        'context' => 'sdl_editor_representation',
      ),
      'type' => 'atom_reference_textfield',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_part_of_speech'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_part_of_speech'] = array(
    'bundle' => 'dictionary_word_bundle',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'Choose one or more parts of speech that best matches your word entry. This field can be used for content browsing. Separate multiple entries with a semi-colon.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => TRUE,
            'field_collection_view_mode' => 'full',
            'link_field_display_type' => 'link_default',
            'node_reference_link' => TRUE,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 3,
      ),
      'dictionary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(
            'entityreference_link' => TRUE,
            'field_collection_view_mode' => 'full',
            'link_field_display_type' => 'link_default',
            'node_reference_link' => TRUE,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'inline',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 'div',
          'textformatter_contrib' => array(),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 16,
      ),
      'word_entry_search_results' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_part_of_speech',
    'label' => 'Part of Speech',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'select2_integration' => array(
        'allow_add_onfly' => 1,
        'show_voc_terms_page_link' => 0,
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 1,
      ),
      'user_register_form' => FALSE,
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
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_pronunciation'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_pronunciation'] = array(
    'bundle' => 'dictionary_word_bundle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field is for making pronunciation guides for word entries. By default this field supports some HTML tags such as "<strong>" and "<em>" if bold or italics are desired.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'dictionary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'word_entry_search_results' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_pronunciation',
    'label' => 'Pronunciation',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'apply_chosen' => '',
        'rows' => 1,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_sample_sentence'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_sample_sentence'] = array(
    'bundle' => 'dictionary_word_bundle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'One or more example sentences that demonstrate use of the word entry.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'dictionary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'dictionary_word_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'word_entry_search_results' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_sample_sentence',
    'label' => 'Sample Sentences',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 1,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_source'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_source'] = array(
    'bundle' => 'dictionary_word_bundle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Reference to a resource from which the dictionary entry is derived, for example if the entry comes from specific reference material, a regional dialect, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'dictionary_teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'dictionary_word_summary' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'featured_content' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'mukurtu_mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'word_entry_search_results' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_source',
    'label' => 'Source',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
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
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-dictionary_word_bundle-field_translation'.
  $field_instances['paragraphs_item-dictionary_word_bundle-field_translation'] = array(
    'bundle' => 'dictionary_word_bundle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The word entry term translated (if appropriate) to the primary language of the site.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'dictionary_teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'dictionary_word_summary' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'featured_content' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'mukurtu_mobile' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'word_entry_in_word_list' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'word_entry_search_results' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_translation',
    'label' => 'Translation',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'custom_add_another' => '',
      'custom_remove' => '',
      'dnd_enabled' => 1,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' The display order of the Words can be changed by dragging and dropping them into the preferred order.');
  t('A dictionary word must be associated with a single language on the site.');
  t('A reference to one or many related dictionary words.');
  t('A reference to one or many related digital heritage items.');
  t('A word list is an collection of dictionary words.');
  t('Additional Media');
  t('Additional Media Assets');
  t('Alternate Spelling');
  t('Characters');
  t('Choose one or more parts of speech that best matches your word entry. This field can be used for content browsing. Separate multiple entries with a semi-colon.');
  t('Collections');
  t('Collections are curated, narrated groups of content within a site. Collections can contain content from more than one Community, and content can belong to multiple Collections. You can search for Collections by typing in this text box, then selecting the Collection. You can drag the Collections within this text box to change the order in which they will appear when viewing this Dictionary Word.');
  t('Community');
  t('Community Language');
  t('Credit');
  t('Definition');
  t('Description');
  t('Determine if this is an OG group.');
  t('Do not pad the glossary letter filter');
  t('Enter <b>all</b> the characters of the language(s) on the site, then drag and drop them into their correct alphabetical order.');
  t('Group');
  t('Groups audience');
  t('If the spelling of an entry differs from the term, enter it here. Leave blank otherwise.');
  t('Image');
  t('In Mukurtu CMS v4, the "Additional Media" field is no longer included and will not be migrated. This field will be migrated to the "Media Assets" field. It is recommended to move media asset references from the "Additional Media" field to this field.');
  t('Include any media or additional information that does not fit in the other fields here. You are allowed to drag items from the media library into this field. For this to work, there must be some content below where you place the item (even just a blank line). The media item will be inserted, along with a line of text showing its title and author (which you may choose to remove). Note, certain media types (e.g., audio, YouTube video) do not render well or at all within the edit box, but show correctly within the content view. If you wish to visualize or adjust the placement of such media items, try switching to the plain text editor.');
  t('Item Sharing Settings');
  t('Keywords');
  t('Keywords provide added ways to group your content. They make it easier for users to search and retrieve content.');
  t('Keywords provide added ways to group your content. They make it easier for users to search and retrieve content. Separate multiple keywords with semicolons.');
  t('Language');
  t('Language Community');
  t('Media Assets');
  t('Normally, the glossary title letter filter will "pad" itself with all letters from A-Z for which there are no words in the site\'s glossary that start with that letter. Unlike the other letters, they are unlinked. Their purpose is to provide a complete-looking alphabet in the filter. However, if the language(s) of the glossary does not include all the letters from A-Z, it would be preferable to leave out the letters which do not exist in the language. Click this checkbox to disable padding of the glossary with all the letters from A-Z. Only the first letter of words in the glossary will remain in the filter.');
  t('One or more example sentences that demonstrate use of the word entry.');
  t('Part of Speech');
  t('Personal Collections');
  t('Pre-Actions');
  t('Pronunciation');
  t('Protocol');
  t('Recording');
  t('Reference to a resource from which the dictionary entry is derived, for example if the entry comes from specific reference material, a regional dialect, etc.');
  t('Related Content');
  t('Related Dictionary Words');
  t('Related Digital Heritage Items');
  t('Sample Sentences');
  t('Sort Language');
  t('Sort Method');
  t('Source');
  t('Summary');
  t('The word entry term translated (if appropriate) to the primary language of the site.');
  t('This field is for making pronunciation guides for word entries. By default this field supports some HTML tags such as "<strong>" and "<em>" if bold or italics are desired.');
  t('Thumbnail Image');
  t('Translation');
  t('Word Entry');
  t('Word List');
  t('Words');
  t('You are allowed to drag items from the media library into this field. For this to work, there must be some content below where you place the item (even just a blank line). The media item will be inserted, along with a line of text showing its title and author (which you may choose to remove). Note, certain media types (eg. audio, Youtube video) do not render well or at all within the edit box, but show correctly within the content view. If you wish to visualize or adjust the placement of such media items, try switching to the plain text editor.');
  t('You can search for related content by typing in this text box, then selecting the content. You can drag the selected content within this text box to change the order in which they will appear when viewing this Dictionary Word.');

  return $field_instances;
}
