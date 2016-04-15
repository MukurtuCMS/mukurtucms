<?php
/**
 * @file
 * ma_community.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ma_community_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_community-comment_body'
  $field_instances['comment-comment_node_community-comment_body'] = array(
    'bundle' => 'comment_node_community',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'context' => '',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-community-body'
  $field_instances['node-community-body'] = array(
    'bundle' => 'community',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'You are allowed to drag items from the media library into this field. For this to work, there must be some content below where you place the item (even just a blank line). The media item will be inserted, along with a line of text showing its title and author (which you may choose to remove). Note, certain media types (eg. audio, Youtube video) do not render well or at all within the edit box, but show correctly within the content view. If you wish to visualize or adjust the placement of such media items, try switching to the plain text editor.',
    'display' => array(
      'browse_teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
      'thumbed' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-community-field_child_communities'
  $field_instances['node-community-field_child_communities'] = array(
    'bundle' => 'community',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 21,
      ),
      'full' => array(
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
          'textformatter_type' => 'ul',
        ),
        'type' => 'textformatter_list',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_child_communities',
    'label' => 'Child Communities',
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
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-community-field_community_image'
  $field_instances['node-community-field_community_image'] = array(
    'bundle' => 'community',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'As this image fills the width of the Community landing page, we recommend your images be at least 1200x480 pixels or larger. Please use a 2.5:1 width to height ratio for your image. We do not crop this image.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
        ),
        'type' => 'mukurtu_scald_banner_image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_community_image',
    'label' => 'Banner Image',
    'required' => 0,
    'settings' => array(
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-community-field_community_image_thumbnail'
  $field_instances['node-community-field_community_image_thumbnail'] = array(
    'bundle' => 'community',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This image is used in the Community listings page. Use a 1:1 width to height ratio.
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'full' => array(
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
      'thumbed' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'mukurtu_scald_thumbnail_image',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_community_image_thumbnail',
    'label' => 'Thumbnail Image',
    'required' => 0,
    'settings' => array(
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-community-field_parent_community'
  $field_instances['node-community-field_parent_community'] = array(
    'bundle' => 'community',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Use this field with caution! If you assign the current Community to a Parent Community, all members of the current Community will be added as members on the Parent Community. If you subsequently unassign the current Community from the Parent Community, the members will remain added to the Parent Community.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 20,
      ),
      'full' => array(
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
          'textformatter_type' => 'ul',
        ),
        'type' => 'textformatter_list',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_parent_community',
    'label' => 'Parent Community',
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
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-community-group_access'
  $field_instances['node-community-group_access'] = array(
    'bundle' => 'community',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Open - Your community page is visible to all visitors of your site. Any items under open protocols are also accessible.<br>
Strict - Your community page is invisible to all site users who are not members or your community. All protocols created within this community are inaccessible to users outside of this community.',
    'display' => array(
      'browse_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'group_access',
    'label' => 'Sharing protocol',
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
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-community-group_group'
  $field_instances['node-community-group_group'] = array(
    'bundle' => 'community',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'browse_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'group_group',
    'label' => 'Group type',
    'required' => TRUE,
    'settings' => array(
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
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
    'widget_type' => 'options_select',
  );

  // Exported field_instance: 'node-community-og_group_ref'
  $field_instances['node-community-og_group_ref'] = array(
    'bundle' => 'community',
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'browse_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'full' => array(
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
      'thumbed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Community Parent',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
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
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('As this image fills the width of the Community landing page, we recommend your images be at least 1200x480 pixels or larger. Please use a 2.5:1 width to height ratio for your image. We do not crop this image.');
  t('Banner Image');
  t('Child Communities');
  t('Comment');
  t('Community Parent');
  t('Description');
  t('Group type');
  t('Open - Your community page is visible to all visitors of your site. Any items under open protocols are also accessible.<br>
Strict - Your community page is invisible to all site users who are not members or your community. All protocols created within this community are inaccessible to users outside of this community.');
  t('Parent Community');
  t('Sharing protocol');
  t('This image is used in the Community listings page. Use a 1:1 width to height ratio.
');
  t('Thumbnail Image');
  t('Use this field with caution! If you assign the current Community to a Parent Community, all members of the current Community will be added as members on the Parent Community. If you subsequently unassign the current Community from the Parent Community, the members will remain added to the Parent Community.');
  t('You are allowed to drag items from the media library into this field. For this to work, there must be some content below where you place the item (even just a blank line). The media item will be inserted, along with a line of text showing its title and author (which you may choose to remove). Note, certain media types (eg. audio, Youtube video) do not render well or at all within the edit box, but show correctly within the content view. If you wish to visualize or adjust the placement of such media items, try switching to the plain text editor.');

  return $field_instances;
}
