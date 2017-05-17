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
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
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
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'group_person_media',
        1 => 'group_metadata',
        2 => 'field_date_born',
        3 => 'table_of_contents',
        4 => 'field_date_died',
        5 => 'field_related_people',
        6 => 'body',
        7 => 'field_sections',
        8 => 'field_media_asset',
        9 => 'field_node_aggregate',
        10 => 'field_media_aggregate',
      ),
    ),
    'fields' => array(
      'group_person_media' => 'central',
      'group_metadata' => 'central',
      'field_date_born' => 'central',
      'table_of_contents' => 'central',
      'field_date_died' => 'central',
      'field_related_people' => 'central',
      'body' => 'central',
      'field_sections' => 'central',
      'field_media_asset' => 'central',
      'field_node_aggregate' => 'central',
      'field_media_aggregate' => 'central',
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
        0 => 'group_tabs',
        1 => 'field_node_aggregate',
        2 => 'title',
        3 => 'field_media_asset',
        4 => 'body',
        7 => 'field_sections',
        8 => 'field_date_born',
        11 => 'field_date_died',
        12 => 'field_deceased',
        14 => 'field_related_people',
        16 => 'group_biographic',
        17 => 'group_relations',
      ),
      'hidden' => array(
        5 => 'og_group_ref',
        6 => 'redirect',
        9 => 'path',
        10 => 'field_media_aggregate',
        13 => 'field_mukurtu_terms',
        15 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_tabs' => 'ds_content',
      'field_node_aggregate' => 'ds_content',
      'title' => 'ds_content',
      'field_media_asset' => 'ds_content',
      'body' => 'ds_content',
      'og_group_ref' => 'hidden',
      'redirect' => 'hidden',
      'field_sections' => 'ds_content',
      'field_date_born' => 'ds_content',
      'path' => 'hidden',
      'field_media_aggregate' => 'hidden',
      'field_date_died' => 'ds_content',
      'field_deceased' => 'ds_content',
      'field_mukurtu_terms' => 'hidden',
      'field_related_people' => 'ds_content',
      '_add_existing_field' => 'hidden',
      'group_biographic' => 'ds_content',
      'group_relations' => 'ds_content',
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
  $ds_layout->id = 'paragraphs_item|text_section|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'text_section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_3col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_section_title',
      ),
      'left' => array(
        1 => 'field_left_media',
      ),
      'middle' => array(
        2 => 'field_section_body',
      ),
      'right' => array(
        3 => 'field_right_media',
      ),
    ),
    'fields' => array(
      'field_section_title' => 'header',
      'field_left_media' => 'left',
      'field_section_body' => 'middle',
      'field_right_media' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['paragraphs_item|text_section|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|text_section|form';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'text_section';
  $ds_layout->view_mode = 'form';
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
      'hidden' => array(
        4 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_section_title' => 'top',
      'field_left_media' => 'left',
      'field_section_body' => 'central',
      'field_right_media' => 'right',
      '_add_existing_field' => 'hidden',
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

  return $export;
}
