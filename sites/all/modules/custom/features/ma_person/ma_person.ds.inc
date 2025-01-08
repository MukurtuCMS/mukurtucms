<?php

/**
 * @file
 * ma_person.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_person_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_date_born' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_date_died' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_media_asset' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_node_aggregate' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Referenced Content',
          'lb-at' => 'name="found-in"',
          'lb-cl' => 'field-name-field-node-aggregate',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h3',
        ),
      ),
    ),
    'field_related_people' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_tags' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'table_of_contents' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
  );
  $export['node|person|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|featured_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'featured_content';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'featured_content_view_link' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '16',
    ),
  );
  $export['node|person|featured_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|person|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|person_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'person_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h3',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|person|person_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|related_person_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'related_person_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h4',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|person|related_person_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '1',
    ),
    'mukurtu_icon_actions' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '3',
    ),
    'mukurtu_mobile_sync' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '2',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|person|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|taxonomy_record_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'taxonomy_record_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|person|taxonomy_record_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'featured_content_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'ft' => array(),
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|person|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|person_relationship_bundle|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'person_relationship_bundle';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_related_person' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['paragraphs_item|person_relationship_bundle|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|person_relationship_bundle|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'person_relationship_bundle';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'field_related_person' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['paragraphs_item|person_relationship_bundle|mukurtu_mobile'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|text_section|default';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'text_section';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_section_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<h3>',
          'suffix' => '</h3>',
        ),
      ),
    ),
  );
  $export['paragraphs_item|text_section|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'paragraphs_item|text_section|mukurtu_mobile';
  $ds_fieldsetting->entity_type = 'paragraphs_item';
  $ds_fieldsetting->bundle = 'text_section';
  $ds_fieldsetting->view_mode = 'mukurtu_mobile';
  $ds_fieldsetting->settings = array(
    'field_left_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_right_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['paragraphs_item|text_section|mukurtu_mobile'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_person_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'table_of_contents';
  $ds_field->label = 'Contents';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'person|default';
  $ds_field->properties = array(
    'code' => array(
      'format' => 'ds_code',
      'value' => '<?php
         // We want to build a table of contents for the following:
        // 1. Related People
        // 2. Each paragraph section
        // 3. Content the person is found in
        $items = array();

        // Related People
        if(isset($entity->field_related_people[LANGUAGE_NONE]) && !empty($entity->field_related_people[LANGUAGE_NONE])) {
            $items[] = t("<a href=\'@url\'>Related People</a>", array(\'@url\' => \'#related-people\'));
        }

        // Paragraph Sections
        if(!empty($entity->field_sections[LANGUAGE_NONE])) {
            foreach($entity->field_sections[LANGUAGE_NONE] as $index => $section) {
                $paragraphs = entity_load(\'paragraphs_item\', array($section[\'value\']));
                $paragraph = $paragraphs[key($paragraphs)];
                $title = isset($paragraph->field_section_title[\'und\'][0][\'safe_value\']) ? $paragraph->field_section_title[\'und\'][0][\'safe_value\'] : t(\'Section \') . ($index + 1);
                $items[] = t("<a href=\'#section-@num\'>@title</a>", array(\'@num\' => $index + 1, \'@title\' => $title));
            }
        }

        // Found in
        if(!empty($entity->field_node_aggregate[LANGUAGE_NONE])) {
            $items[] = t("<a href=\'@url\'>Referenced Content</a>", array(\'@url\' => \'#found-in\'));
        }
        

        if(count($items) > 1) {
            $toc = array(
                \'#title\' => t(\'Contents\'),
                \'#prefix\' => \'<div class="tableofcontents">\',
                \'#items\' => $items,
                \'#theme\' => \'item_list\',
                \'#suffix\' => \'</div>\'
            );
            
            print drupal_render($toc);
        }
?>',
    ),
    'use_token' => 0,
  );
  $export['table_of_contents'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_person_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_collection' => 'right',
      'field_date_born' => 'right',
      'field_date_died' => 'right',
      'field_media_aggregate' => 'bottom',
      'field_media_asset' => 'left',
      'field_node_aggregate' => 'bottom',
      'field_related_content' => 'bottom',
      'field_related_people' => 'right',
      'field_sections' => 'bottom',
      'field_tags' => 'right',
      'mukurtu_icon_actions' => 'top',
      'mukurtu_mobile_sync' => 'top',
      'table_of_contents' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'bottom' => array(
        9 => 'field_sections',
        10 => 'field_node_aggregate',
        11 => 'field_related_content',
        12 => 'field_media_aggregate',
      ),
      'left' => array(
        1 => 'field_media_asset',
      ),
      'right' => array(
        3 => 'table_of_contents',
        4 => 'field_date_born',
        5 => 'field_date_died',
        6 => 'field_tags',
        7 => 'field_collection',
        8 => 'field_related_people',
      ),
      'top' => array(
        0 => 'mukurtu_icon_actions',
        2 => 'mukurtu_mobile_sync',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['node|person|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|featured_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'featured_content';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'central',
      'featured_content_view_link' => 'central',
      'field_media_asset' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'featured_content_view_link',
        1 => 'field_media_asset',
        2 => 'featured_content_type',
        3 => 'title',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|person|featured_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'ds_content',
      'field_collection' => 'ds_content',
      'field_community_ref' => 'hidden',
      'field_date_born' => 'ds_content',
      'field_date_died' => 'ds_content',
      'field_deceased' => 'ds_content',
      'field_item_privacy_setting' => 'ds_content',
      'field_media_aggregate' => 'hidden',
      'field_media_asset' => 'ds_content',
      'field_mukurtu_terms' => 'ds_content',
      'field_node_aggregate' => 'ds_content',
      'field_personal_collections' => 'ds_content',
      'field_pre_actions' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_related_people' => 'ds_content',
      'field_sections' => 'ds_content',
      'field_tags' => 'ds_content',
      'group_biographic' => 'ds_content',
      'group_record_connections' => 'ds_content',
      'group_relations' => 'ds_content',
      'group_tabs' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'path' => 'hidden',
      'redirect' => 'hidden',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'group_tabs',
        3 => 'field_node_aggregate',
        4 => 'og_group_ref',
        5 => 'field_item_privacy_setting',
        6 => '_add_existing_field',
        8 => 'field_media_asset',
        10 => 'field_tags',
        12 => 'field_sections',
        13 => 'field_date_born',
        15 => 'field_mukurtu_terms',
        16 => 'field_date_died',
        17 => 'field_deceased',
        18 => 'field_related_people',
        19 => 'field_related_content',
        20 => 'group_biographic',
        21 => 'field_collection',
        22 => 'field_personal_collections',
        23 => 'group_relations',
        24 => 'group_record_connections',
      ),
      'hidden' => array(
        7 => 'redirect',
        9 => 'path',
        11 => 'field_community_ref',
        14 => 'field_media_aggregate',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|person|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|mukurtu_mobile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_collection' => 'ds_content',
      'field_date_born' => 'ds_content',
      'field_date_died' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_related_people' => 'ds_content',
      'field_sections' => 'ds_content',
      'field_tags' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_media_asset',
        2 => 'field_date_born',
        3 => 'field_date_died',
        4 => 'field_tags',
        5 => 'field_sections',
        6 => 'field_collection',
        7 => 'field_related_people',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|person|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|person_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'person_teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_media_asset',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|person|person_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|related_person_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'related_person_teaser';
  $ds_layout->layout = 'bootstrap_9_3';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'right',
      'title' => 'left',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        0 => 'title',
      ),
      'right' => array(
        1 => 'field_media_asset',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|person|related_person_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_media_asset' => 'left',
      'group_list_view_fields' => 'right',
      'mukurtu_icon_actions' => 'right',
      'mukurtu_mobile_sync' => 'right',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        1 => 'field_media_asset',
      ),
      'right' => array(
        0 => 'title',
        2 => 'featured_content_type',
        3 => 'mukurtu_mobile_sync',
        4 => 'mukurtu_icon_actions',
        5 => 'group_list_view_fields',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|person|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|taxonomy_record_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'taxonomy_record_teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'body' => 'central',
      'field_date_born' => 'central',
      'field_date_died' => 'central',
      'field_media_asset' => 'central',
      'group_metadata_div' => 'central',
      'title' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_media_asset',
        2 => 'group_metadata_div',
        3 => 'body',
        4 => 'field_date_born',
        5 => 'field_date_died',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['node|person|taxonomy_record_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'featured_content_type' => 'right',
      'field_media_asset' => 'left',
      'title' => 'right',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'left' => array(
        1 => 'field_media_asset',
      ),
      'right' => array(
        0 => 'title',
        2 => 'featured_content_type',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
  );
  $export['node|person|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|person_relationship_bundle|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'person_relationship_bundle';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_related_person' => 'central',
      'field_relationship_type' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'field_related_person',
        1 => 'field_relationship_type',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['paragraphs_item|person_relationship_bundle|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|person_relationship_bundle|mukurtu_mobile';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'person_relationship_bundle';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_related_person' => 'ds_content',
      'field_relationship_type' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_related_person',
        1 => 'field_relationship_type',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['paragraphs_item|person_relationship_bundle|mukurtu_mobile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|text_section|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'text_section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_4_4_4_stacked';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_left_media' => 'left',
      'field_right_media' => 'right',
      'field_section_body' => 'central',
      'field_section_title' => 'top',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        2 => 'field_section_body',
      ),
      'left' => array(
        1 => 'field_left_media',
      ),
      'right' => array(
        3 => 'field_right_media',
      ),
      'top' => array(
        0 => 'field_section_title',
      ),
    ),
    'wrappers' => array(
      'bottom' => 'div',
      'central' => 'div',
      'left' => 'div',
      'right' => 'div',
      'top' => 'div',
    ),
  );
  $export['paragraphs_item|text_section|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|text_section|form';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'text_section';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      '_add_existing_field' => 'hidden',
      'field_left_media' => 'central',
      'field_right_media' => 'central',
      'field_section_body' => 'central',
      'field_section_title' => 'central',
      'group_section' => 'central',
      'group_section_group' => 'central',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'central' => array(
        0 => 'group_section_group',
        1 => 'field_section_title',
        2 => 'field_left_media',
        3 => 'field_section_body',
        4 => 'field_right_media',
        6 => 'group_section',
      ),
      'hidden' => array(
        5 => '_add_existing_field',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
  );
  $export['paragraphs_item|text_section|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|text_section|mukurtu_mobile';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'text_section';
  $ds_layout->view_mode = 'mukurtu_mobile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'fields' => array(
      'field_left_media' => 'ds_content',
      'field_right_media' => 'ds_content',
      'field_section_body' => 'ds_content',
      'field_section_title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_section_title',
        1 => 'field_left_media',
        2 => 'field_section_body',
        3 => 'field_right_media',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['paragraphs_item|text_section|mukurtu_mobile'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_person_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'person_teaser';
  $ds_view_mode->label = 'Person Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'scald_atom' => 'scald_atom',
  );
  $export['person_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'related_person_teaser';
  $ds_view_mode->label = 'Related Person Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['related_person_teaser'] = $ds_view_mode;

  return $export;
}
