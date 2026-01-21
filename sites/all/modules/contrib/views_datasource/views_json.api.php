<?php

/**
 * @file
 * Describe hooks provided by the Views datasource module.
 */

/**
 * Alter rendered json row.
 *
 * @param $field_output array
 *   The output rendered by _views_json_render_fields().
 * @param $view view
 *   The view that is being rendered.
 * @param $row stdClass
 *   Raw data collected by views_plugin_json_style().
 *
 * @see _views_json_render_fields().
 * @see views_plugin_json_style().
 */
function hook_views_json_render_row_alter(&$field_output, $view, $row) {
  if (isset($row->field_entity_reference[0]['raw']['entity'])) {
    $entity = $row->field_entity_reference[0]['raw']['entity'];
    $field_output['field_entity_reference']->content = array(
      'type' => $entity->type,
      'title' => $entity->title,
      'entity_id' => $entity->entity_id,
    );
  }

  // Note that the $field_output array is not returned – it is modified by reference.
}
