<?php
/**
 * @file
 * oa_sections.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oa_sections_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-oa_section-body'
  $field_instances['node-oa_section-body'] = array(
    'bundle' => 'oa_section',
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
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-oa_section-field_oa_group_ref'
  $field_instances['node-oa_section-field_oa_group_ref'] = array(
    'bundle' => 'oa_section',
    'comment_alter' => 0,
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'Leave empty for public access, otherwise select Groups that can view this Section.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'featured' => array(
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
    'entity_type' => 'node',
    'field_name' => 'field_oa_group_ref',
    'label' => 'Groups',
    'options_limit' => 0,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(
      'body' => 0,
      'og_group_ref' => 0,
    ),
    'required' => 0,
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select2widget',
      'settings' => array(
        'select2widgetajax' => array(
          'match_operator' => 'CONTAINS',
          'min_char' => 1,
          'view_mode' => 'select2widget_labels',
          'width' => '100%',
        ),
      ),
      'type' => 'select2widgetajax',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-oa_section-field_oa_section'
  $field_instances['node-oa_section-field_oa_section'] = array(
    'bundle' => 'oa_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'featured' => array(
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
    'entity_type' => 'node',
    'field_name' => 'field_oa_section',
    'label' => 'Section Type',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(),
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-oa_section-field_oa_section_override'
  $field_instances['node-oa_section-field_oa_section_override'] = array(
    'bundle' => 'oa_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'featured' => array(
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
    'entity_type' => 'node',
    'field_name' => 'field_oa_section_override',
    'label' => 'Override default section options',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-oa_section-field_oa_section_weight'
  $field_instances['node-oa_section-field_oa_section_weight'] = array(
    'bundle' => 'oa_section',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Determines order of Section in lists.  Higher value moves the section later in the list.  Lower value moves section earlier in the list.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 6,
      ),
      'featured' => array(
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
    'entity_type' => 'node',
    'field_name' => 'field_oa_section_weight',
    'label' => 'Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-oa_section-field_oa_team_ref'
  $field_instances['node-oa_section-field_oa_team_ref'] = array(
    'bundle' => 'oa_section',
    'comment_alter' => 0,
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Leave empty for public access, otherwise select Teams that can view this Section.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'featured' => array(
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
    'entity_type' => 'node',
    'field_name' => 'field_oa_team_ref',
    'label' => 'Teams',
    'options_limit' => 0,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(
      'body' => 0,
      'og_group_ref' => 0,
    ),
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select2widget',
      'settings' => array(
        'select2widgetajax' => array(
          'match_operator' => 'CONTAINS',
          'min_char' => 1,
          'view_mode' => 'select2widget_labels',
          'width' => '100%',
        ),
      ),
      'type' => 'select2widgetajax',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-oa_section-field_oa_user_ref'
  $field_instances['node-oa_section-field_oa_user_ref'] = array(
    'bundle' => 'oa_section',
    'comment_alter' => 0,
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Leave empty for public access, otherwise select Space Members that can view this Section.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'featured' => array(
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
    'entity_type' => 'node',
    'field_name' => 'field_oa_user_ref',
    'label' => 'Users',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(),
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select2widget',
      'settings' => array(
        'select2widgetajax' => array(
          'match_operator' => 'CONTAINS',
          'min_char' => 1,
          'view_mode' => 'select2widget_labels',
          'width' => '100%',
        ),
      ),
      'type' => 'select2widgetajax',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-oa_section-og_group_ref'
  $field_instances['node-oa_section-og_group_ref'] = array(
    'bundle' => 'oa_section',
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
        'weight' => 0,
      ),
      'featured' => array(
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
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Space ID',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 1,
          'admin' => array(
            'widget_settings' => array(
              'select2widgetajax' => array(
                'match_operator' => 'CONTAINS',
                'min_char' => 1,
                'view_mode' => 'teaser',
                'width' => '100%',
              ),
            ),
            'widget_type' => 'select2widgetajax',
          ),
          'default' => array(
            'widget_settings' => array(
              'select2widgetajax' => array(
                'match_operator' => 'CONTAINS',
                'min_char' => 1,
                'view_mode' => 'teaser',
                'width' => '100%',
              ),
            ),
            'widget_type' => 'select2widgetajax',
          ),
          'status' => TRUE,
        ),
      ),
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
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-section_type-field_oa_icon_class'
  $field_instances['taxonomy_term-section_type-field_oa_icon_class'] = array(
    'bundle' => 'section_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the optional bootstrap icon class name (e.g. icon-calendar)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_oa_icon_class',
    'label' => 'Icon class',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-section_type-field_oa_icon_image'
  $field_instances['taxonomy_term-section_type-field_oa_icon_image'] = array(
    'bundle' => 'section_type',
    'deleted' => 0,
    'description' => 'Image file to use in place of icon',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 3,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_oa_icon_image',
    'label' => 'Icon image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 0,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => FALSE,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 0,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
      ),
      'type' => 'media_generic',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-section_type-field_oa_section_layout'
  $field_instances['taxonomy_term-section_type-field_oa_section_layout'] = array(
    'bundle' => 'section_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Choose the default layout for this section',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_oa_section_layout',
    'label' => 'Section Layout',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-section_type-field_oa_section_type_menu'
  $field_instances['taxonomy_term-section_type-field_oa_section_type_menu'] = array(
    'bundle' => 'section_type',
    'default_value' => array(
      0 => array(
        'value' => 1,
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
        'weight' => 4,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_oa_section_type_menu',
    'label' => 'Menu Behaviour',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 33,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Choose the default layout for this section');
  t('Determines order of Section in lists.  Higher value moves the section later in the list.  Lower value moves section earlier in the list.');
  t('Enter the optional bootstrap icon class name (e.g. icon-calendar)');
  t('Groups');
  t('Icon class');
  t('Icon image');
  t('Image file to use in place of icon');
  t('Leave empty for public access, otherwise select Groups that can view this Section.');
  t('Leave empty for public access, otherwise select Space Members that can view this Section.');
  t('Leave empty for public access, otherwise select Teams that can view this Section.');
  t('Menu Behaviour');
  t('Override default section options');
  t('Section Layout');
  t('Section Type');
  t('Space ID');
  t('Teams');
  t('Users');
  t('Weight');

  return $field_instances;
}
