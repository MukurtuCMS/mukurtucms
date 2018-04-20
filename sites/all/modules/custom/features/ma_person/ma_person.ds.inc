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
    'table_of_contents' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_node_aggregate' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Referenced Content',
          'lb-cl' => 'field-name-field-node-aggregate',
          'lb-at' => 'name="found-in"',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h3',
        ),
      ),
    ),
  );
  $export['node|person|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|person_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'person_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
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
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|person|related_person_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|person|taxonomy_record_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'person';
  $ds_fieldsetting->view_mode = 'taxonomy_record_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|person|taxonomy_record_teaser'] = $ds_fieldsetting;

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
      'format' => 'ds_code',
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
    'regions' => array(
      'left' => array(
        0 => 'field_media_asset',
      ),
      'right' => array(
        1 => 'table_of_contents',
        2 => 'field_date_born',
        3 => 'field_date_died',
        4 => 'field_related_people',
      ),
      'bottom' => array(
        5 => 'field_sections',
        6 => 'field_node_aggregate',
        7 => 'field_media_aggregate',
      ),
    ),
    'fields' => array(
      'field_media_asset' => 'left',
      'table_of_contents' => 'right',
      'field_date_born' => 'right',
      'field_date_died' => 'right',
      'field_related_people' => 'right',
      'field_sections' => 'bottom',
      'field_node_aggregate' => 'bottom',
      'field_media_aggregate' => 'bottom',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'right' => array(
        'metadata-sidebar' => 'metadata-sidebar',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|person|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pre_actions',
        1 => 'title',
        2 => 'group_tabs',
        3 => 'field_media_asset',
        4 => 'field_node_aggregate',
        6 => 'field_sections',
        9 => 'field_date_born',
        11 => 'field_date_died',
        12 => 'field_mukurtu_terms',
        13 => 'field_deceased',
        14 => 'field_related_people',
        15 => 'group_biographic',
        17 => 'group_relations',
        18 => 'group_record_connections',
      ),
      'hidden' => array(
        5 => 'og_group_ref',
        7 => 'redirect',
        8 => 'path',
        10 => 'field_media_aggregate',
        16 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_pre_actions' => 'ds_content',
      'title' => 'ds_content',
      'group_tabs' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'field_node_aggregate' => 'ds_content',
      'og_group_ref' => 'hidden',
      'field_sections' => 'ds_content',
      'redirect' => 'hidden',
      'path' => 'hidden',
      'field_date_born' => 'ds_content',
      'field_media_aggregate' => 'hidden',
      'field_date_died' => 'ds_content',
      'field_mukurtu_terms' => 'ds_content',
      'field_deceased' => 'ds_content',
      'field_related_people' => 'ds_content',
      'group_biographic' => 'ds_content',
      '_add_existing_field' => 'hidden',
      'group_relations' => 'ds_content',
      'group_record_connections' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|person|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|person_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'person_teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_media_asset',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_media_asset' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
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
    'regions' => array(
      'left' => array(
        0 => 'title',
      ),
      'right' => array(
        1 => 'field_media_asset',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_media_asset' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|person|related_person_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|taxonomy_record_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'taxonomy_record_teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
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
    'fields' => array(
      'title' => 'central',
      'field_media_asset' => 'central',
      'group_metadata_div' => 'central',
      'body' => 'central',
      'field_date_born' => 'central',
      'field_date_died' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|person|taxonomy_record_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|person_relationship_bundle|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'person_relationship_bundle';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_related_person',
        1 => 'field_relationship_type',
      ),
    ),
    'fields' => array(
      'field_related_person' => 'central',
      'field_relationship_type' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|person_relationship_bundle|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|text_section|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'text_section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_4_4_4_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_section_title',
      ),
      'left' => array(
        1 => 'field_left_media',
      ),
      'central' => array(
        2 => 'field_section_body',
      ),
      'right' => array(
        3 => 'field_right_media',
      ),
    ),
    'fields' => array(
      'field_section_title' => 'top',
      'field_left_media' => 'left',
      'field_section_body' => 'central',
      'field_right_media' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
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
    'fields' => array(
      'group_section_group' => 'central',
      'field_section_title' => 'central',
      'field_left_media' => 'central',
      'field_section_body' => 'central',
      'field_right_media' => 'central',
      '_add_existing_field' => 'hidden',
      'group_section' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|text_section|form'] = $ds_layout;

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
    'scald_atom' => 'scald_atom',
    'node' => 'node',
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
