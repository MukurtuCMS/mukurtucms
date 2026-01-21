<?php
/**
 * @file
 * ma_taxonomy.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ma_taxonomy_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|category|taxonomy_browse_by';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'category';
  $ds_fieldsetting->view_mode = 'taxonomy_browse_by';
  $ds_fieldsetting->settings = array(
    'taxonomy_image_browse_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_title_browse_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['taxonomy_term|category|taxonomy_browse_by'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ma_taxonomy_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'taxonomy_image_browse_link';
  $ds_field->label = 'Taxonomy Image Browse Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$browse_url = ma_taxonomy_get_browse_url($entity);
if(isset($entity->field_thumbnail_image[\'und\'][0][\'sid\'])) {
    $sid = $entity->field_thumbnail_image[\'und\'][0][\'sid\'];
    $atom_url = "href=\\"/atom/{$sid}\\"";
    $markup = scald_render($sid, \'mukurtu_browse_by_grid_7_4\');
    $markup = str_replace($atom_url, "href=\\"{$browse_url}\\"", $markup);
    print $markup;
}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['taxonomy_image_browse_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'taxonomy_title_browse_link';
  $ds_field->label = 'Taxonomy Title Browse Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$browse_url = ma_taxonomy_get_browse_url($entity);
print l("<h3>{$entity->name}</h3>", $browse_url, array(\'html\' => TRUE));
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['taxonomy_title_browse_link'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ma_taxonomy_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|category|taxonomy_browse_by';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'category';
  $ds_layout->view_mode = 'taxonomy_browse_by';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'taxonomy_image_browse_link',
        1 => 'taxonomy_title_browse_link',
      ),
    ),
    'fields' => array(
      'taxonomy_image_browse_link' => 'central',
      'taxonomy_title_browse_link' => 'central',
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
  $export['taxonomy_term|category|taxonomy_browse_by'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ma_taxonomy_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'taxonomy_browse_by';
  $ds_view_mode->label = 'Taxonomy Browse By';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['taxonomy_browse_by'] = $ds_view_mode;

  return $export;
}
