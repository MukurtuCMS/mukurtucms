<?php

/**
 * @file
 * Views theme to render view fields as JSON.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by _views_json_render_fields
 * - $attachment: Not used currently
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see views_json.views.inc
 */


function template_preprocess_views_views_autocomplete(&$vars) {
  $rows = $vars["rows"];
  $options = $vars["options"];
  $plaintext_output = $options["plaintext_output"];
  $objects = array();
  foreach ($rows as $row) {

    $object = array();
    $label = FALSE;
    /* Convert the $rows into a hierachial key=>value array */
    foreach ($row as $field) {
      if ($options["field_output"] == "normal") {
        if (!$field->is_multiple) {
          $content = $plaintext_output ? strip_tags($field->content) : $field->content;
        }
        else {
          $content = array();
          foreach ($field->content as $n => $oc) $content[$n] = ($plaintext_output ? strip_tags($oc) : $oc);
        }
      }
      elseif ($options["field_output"] == "raw") {
        $label = $plaintext_output ? strip_tags($field->id) : $field->id;
        if (!$field->is_multiple) {
          $content = $plaintext_output ? strip_tags($field->raw) : $field->raw;
        }
        else {
          $content = array();
          foreach ($field->raw as $n => $oc) $content[$n] = $plaintext_output ? strip_tags($oc) : $oc;
        }
      }
      // The first field is the key, the subsequent fields are the value,
      // unless there is only one field in which case it is both.
      if (!$label) {
        $label = $content;
      }
      else {
        $object[] = $content;
      }
    }
    if (empty($object)) {
      $object = array($label);
    }
    $objects[$label] = implode(', ', $object);
  }

  // check if user wants nested arrays
  $vars["rows"] = $objects;
}
