<?php

/**
 * @file
 * The Mukurtu export csv format handler.
 *
 * Adds configurable csv format to Mukurtu export.
 */

/**
 * Settings callback.
 */
function mukurtu_export_csv_settings($form, $form_state) {
  $settings['csv'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mukurtu CSV Export Settings'),
    '#description' => t(
     'Select how your csv output will be formatted.
     By default this is configured to output files compatible with the Mukurtu importers.
     '
    ),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('Field delimiter'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_delimiter', ','),
    '#description' => t(
    'This delimiter will be used to separate fields. Mukurtu uses comma separated values by default.'),
    '#required' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_enclosure'] = array(
    '#type' => 'textfield',
    '#title' => t('Escape enclosure'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_enclosure', '"'),
    '#required' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_separator'] = array(
    '#type' => 'textfield',
    '#title' => t('Record separator'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_separator', '\r\n'),
    '#required' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_multivalue_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('Multiple value delimiter'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_multivalue_delimiter', ';'),
    '#description' => t(
    'This delimiter will be used to separate mulitple values for a single field.
    Mukurtu uses a single semicolon by default.'),
    '#required' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_escape_eol'] = array(
    '#type' => 'checkbox',
    '#title' => t('Always escape values containing line breaks'),
    '#default_value' => variable_get('mukurtu_export_csv_escape_eol', 1),
    '#description' => t('This is to overcome problems where Windows injects CRLF line breaks.'),
  );

  $settings['csv']['mukurtu_export_csv_id_format'] = array(
    '#type' => 'radios',
    '#title' => t('Content Identifier Format'),
    '#options' => array(
      'internal' => 'Export internal content identifiers for re-import',
      'guid' => 'Export GUIDs for import into a different site'
    ),
    '#default_value' => 'internal',
    '#description' => t('Select the identifier format for export.'),
    '#required' => TRUE,
  );

  return $settings;
}

function mukurtu_export_csv_string($string) {
  $replace = array(
   '\n' => "\n",
   '\r' => "\r",
   '\t' => "\t",
   '\v' => "\v",
   '\e' => "\e",
   '\f' => "\f",
  );
  return str_replace(array_keys($replace), array_values($replace), $string);
}

/**
 * Export callback.
 */
function mukurtu_export_csv_export($entities, $field_list, $settings) {
  $delimiter = mukurtu_export_csv_string($settings['mukurtu_export_csv_delimiter']);
  $enclosure = mukurtu_export_csv_string($settings['mukurtu_export_csv_enclosure']);
  $separator = mukurtu_export_csv_string($settings['mukurtu_export_csv_separator']);
  $escape_eol = $settings['mukurtu_export_csv_escape_eol'];
  $multivalue_delimiter = $settings['mukurtu_export_csv_multivalue_delimiter'];
  $id_format = $settings['mukurtu_export_csv_id_format'];

  // If GUIDs are selected for export, don't export the native ID field of the entity
  if($id_format == 'guid') {
    foreach($field_list as $entity_type => $bundle) {
      $id_field = _mukurtu_export_entity_id($entity_type);
      foreach($bundle as $bundle_name => $bundle_fields){
        if(isset($field_list[$entity_type][$bundle_name][$id_field])) {
          $field_list[$entity_type][$bundle_name][$id_field] = 0;
        }
      }
    }
  }

  $encoded_export = array();
  foreach ($entities as $entity_type => $bundle) {
    foreach ($bundle as $bundle_name => $bundle_entities) {
        $encoded_export = array_merge_recursive($encoded_export, mukurtu_export_csv_encode($entity_type, $bundle_name, $bundle_entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list, $id_format));
    }
  }
  return mukurtu_export_csv_export_to_zip($encoded_export);
}

function mukurtu_export_csv_export_to_zip($encoded_export) {
  $csv_files = array();

  $zip = new ZipArchive();
  $tempfile = drupal_tempnam('temporary://', 'MUKURTUZIP');
  $zip->open(drupal_realpath($tempfile), ZipArchive::CREATE);

  foreach ($encoded_export as $entity_type => $bundle) {
    foreach ($bundle as $bundle_name => $bundle_entities) {
      $temp = file_save_data($encoded_export[$entity_type][$bundle_name]);
      $csv_files[] = $temp;
      $zip->addFile(drupal_realpath($temp->uri), "{$entity_type}_{$bundle_name}.csv");
    }
  }
  $zip->close();

  $destination = 'private://batch_export/';
  file_prepare_directory($destination, FILE_CREATE_DIRECTORY);
  $filename = 'export.zip';

  $zip_handle = fopen($tempfile, 'r');
  $download_file = file_save_data($zip_handle, $destination . $filename, FILE_EXISTS_RENAME);

  // Delete temp files
  foreach($csv_files as $csv_file) {
    file_delete($csv_file);
  }

  unlink(drupal_realpath($tempfile));
//kpr($download_file);
  return $download_file;
}

/**
 * Build csv string.
 */
function mukurtu_export_csv_encode($entity_type, $bundle_name, $entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list, $id_format = 'internal') {
  $encoded_content = array();
  $csv_lines = array();
  $csv_output = array();

  $entity_keys = array();

  foreach (array_keys($entities) as $entity_key) {
    $new_entity_key = "{$entity_type}__{$bundle_name}_{$entity_key}";
    $entity_keys[] = $new_entity_key;
    mukurtu_export_csv_encode_entity($encoded_content, $new_entity_key, $entities[$entity_key], $entity_type, $bundle_name, $field_list, $id_format);
  }

  // Remove bookkeeping info
  $encoded_list = $encoded_content['__exported_key_list'];
  unset($encoded_content['__exported_key_list']);

  foreach(array_keys($encoded_content) as $encoded_entity_type) {
    foreach(array_keys($encoded_content[$encoded_entity_type]) as $encoded_bundle_name) {
      $csv_lines[$encoded_entity_type][$encoded_bundle_name]['mukurtu_export_csv_header'] = array_keys($encoded_content[$encoded_entity_type][$encoded_bundle_name]);

      foreach (array_keys($encoded_content[$encoded_entity_type][$encoded_bundle_name]) as $header_value) {
        foreach (array_keys($encoded_list[$encoded_entity_type][$encoded_bundle_name]) as $encoded_entity_key) {
        //foreach (array_keys($encoded_content[$encoded_entity_type][$encoded_bundle_name][$header_value]) as $encoded_entity_key) {
          $field_value = isset($encoded_content[$encoded_entity_type][$encoded_bundle_name][$header_value][$encoded_entity_key]) ? $encoded_content[$encoded_entity_type][$encoded_bundle_name][$header_value][$encoded_entity_key] : NULL;
          $csv_lines[$encoded_entity_type][$encoded_bundle_name][$encoded_entity_key][$header_value] = $field_value;
        }
      }
      $csv_output[$encoded_entity_type][$encoded_bundle_name] = mukurtu_export_csv_array_to_csv($csv_lines[$encoded_entity_type][$encoded_bundle_name], $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter);
    }
  }

  return $csv_output;
}

/**
 * Process an entity and update $header and $encoded_content accordingly.
 */
function mukurtu_export_csv_encode_entity(&$encoded_content, $entity_key, $var, $entity_type = NULL, $bundle_name = NULL, $field_list = NULL, $id_format = 'internal', $parent = NULL, $parent_index = 0) {
  // GUID is a special case
  if(is_null($parent) && $id_format == 'guid') {
    $encoded_content[$entity_type][$bundle_name]['guid'][$entity_key][0] = _mukurtu_export_entity_get_guid($entity_type, $var->{_mukurtu_export_entity_id($entity_type, $var)});
  }

  foreach ($var as $k => &$v) {
    // Get the new header value.
    list($header_value, $header_index) = mukurtu_export_csv_encode_header_value($parent, $parent_index, $var, $k);

    // Skip export for fields that have been selected for exclusion.
    // Skip export for fields that aren't present in the list, if given a non-null list.
    // For a null list, assume we want to export everything.
    $header_list = isset($field_list[$entity_type][$bundle_name]) ? $field_list[$entity_type][$bundle_name] : NULL;
    if((!empty($header_list) && isset($header_list[$header_value]) && $header_list[$header_value] == 0)
        ||
        (!empty($header_list) && !isset($header_list[$header_value]))) {
      continue;
    }

    //if (is_object($v) || is_array($v)) {
    if (is_array($v) && !is_numeric($k)) {
      // Recurse through the structure.
      mukurtu_export_csv_encode_entity($encoded_content, $entity_key, $v, $entity_type, $bundle_name, $field_list, $id_format, $header_value, $header_index);
    }
    else {
      // Create a safe text version of this value and store it against the header using a safe key.
      $options = array('id_format' => $id_format);

      list($value, $referenced_entities_to_encode) = mukurtu_export_extract_value($entity_type, $parent, $v, $options);
      foreach($referenced_entities_to_encode as $referenced_entity_type => $referenced_entity) {
        foreach($referenced_entity as $r_id => $r_entity) {
          // Check permission?

          // Load entity
          $referenced_entity_object = entity_load($referenced_entity_type, array($r_id));
          if(empty($referenced_entity_object)) {
            continue;
          }
          $new_entity_key = "{$referenced_entity_type}__{$referenced_entity_object[$r_id]->type}_{$r_id}";

          // Check if already exported, prevent infinite recursion
          if(isset($encoded_content['__exported_key_list'][$referenced_entity_type][$referenced_entity_object[$r_id]->type][$new_entity_key])) {
            return;
          }
          mukurtu_export_csv_encode_entity($encoded_content, $new_entity_key, $referenced_entity_object[$r_id], $referenced_entity_type, $referenced_entity_object[$r_id]->type, $field_list, $id_format);
        }
      }
      $encoded_content[$entity_type][$bundle_name][$header_value][$entity_key][$header_index] = mukurtu_export_csv_encode_sanitize_value($value);
      $encoded_content['__exported_key_list'][$entity_type][$bundle_name][$entity_key] = TRUE;
    }
  }
}

/**
 * Encode a value.
 */
function mukurtu_export_csv_encode_sanitize_value($var) {
    if (is_numeric($var)) {
      return $var;
    }
    elseif (is_bool($var)) {
      return ($var ? 'TRUE' : 'FALSE');
    }
    elseif (is_null($var)) {
      return 'NULL';
    }
    elseif (is_string($var) && !empty($var)) {
      // Single-quote strings that could be confused for null or boolean.
      if (in_array(strtoupper($var), array('TRUE', 'FALSE', 'NULL'))) {
        $var = "'" . $var . "'";
      }

      return $var;
    }
    else {
      return '';
    }
}

/**
 * Decode a value.
 */
function mukurtu_export_csv_decode_sanitize_value($var) {
  // Allow numeric, bool, and null values to pass right back as is.
  if (is_numeric($var) || is_bool($var) || is_null($var)) {
    return $var;
  }
  // Allow the special case strings back as is.
  elseif (in_array(strtoupper($var), array("'TRUE'", "'FALSE'", "'NULL'"))) {
    return $var;
  }
  // Assume this is a string.
  return "'" . str_replace("'", "\'", $var) . "'";
}

/**
 * Create header value from $parents, $var, and $k.
 */
function mukurtu_export_csv_encode_header_value($parents, $parents_index, $var, $k) {
  if (is_null($parents)) {
    // Special case; on the first level do not prefix the key.
    $header_value = $k;
    $header_index = 0;
  }
  elseif (is_object($var)) {
    $header_value = $parents;
    $header_index = $parents_index;
  }
  elseif (is_array($var)) {
    $header_value = $parents;
    if(is_numeric($k)) {
      $header_index = $k;
    } else {
      $header_index = $parents_index;
    }
  }

  return array($header_value, $header_index);
}

/**
 * Import callback.
 */
function mukurtu_export_csv_import($code_string) {
  $delimiter = mukurtu_export_csv_string(variable_get('mukurtu_export_csv_delimiter', ','));
  $enclosure = mukurtu_export_csv_string(variable_get('mukurtu_export_csv_enclosure', '"'));
  $separator = mukurtu_export_csv_string(variable_get('mukurtu_export_csv_separator', '\r\n'));
  return mukurtu_export_csv_decode($code_string, $delimiter, $enclosure, $separator);
}

/**
 *  Encode csv.
 */
function mukurtu_export_csv_array_to_csv($array, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter) {
  $csv_output = fopen('php://output', 'w');
  ob_start();

  $lines = array();
  foreach ($array as $line) {
    $out_item = array();
    foreach ($line as $line_key => $item) {
      if(!is_array($item)) {
        $item = array($item);
      }

      foreach($item as $item_key => $item_value) {

        if (stripos($item_value, $enclosure) !== FALSE) {
          $item[$item_key] = str_replace($enclosure, $enclosure . $enclosure, $item_value);
        }
        if (
          (stripos($item_value, $delimiter) !== FALSE)
          || (stripos($item_value, $enclosure) !== FALSE)
          || (stripos($item_value, $separator) !== FALSE)
          || ($escape_eol && stripos($item_value, "\n") !== FALSE)
        ) {
          $item[$item_key] = $enclosure . $item_value . $enclosure;
        }
      }
      $out_item[] = implode($multivalue_delimiter, $item);
    }
    fputcsv($csv_output, $out_item, $delimiter, $enclosure);
  }

  fclose($csv_output);
  $csv = ob_get_clean();
  return $csv;
}

/**
 *  Decode csv.
 */
function mukurtu_export_csv_csv_to_array($string, $delimiter, $enclosure, $separator) {
  $lines = array();
  $out_item = array();
  $count = strlen($string);
  $escape = FALSE;
  $double_escape = FALSE;
  $position = 0;
  $i = 0;
  $separators = str_split($separator);

  while ($i < $count) {
    $c = $string[$i];

    // Determine whether this is an EOL.
    $is_eol = TRUE;
    for ($j = 0; $j < count($separators); $j++) {
      if (!isset($string[$i + $j]) || $string[$i + $j] != $separators[$j]) {
        $is_eol = FALSE;
        break;
      }
    }

    if ($is_eol) {
      if ($escape) {
        $out_item[$position] .= $c;
      }
      else {
        $i += count($separators);
        $lines[] = $out_item;
        $out_item = array();
        $position = 0;
        continue;
      }
    }
    elseif ($c == $delimiter) {
      if ($escape) {
        $out_item[$position] .= $c;
      }
      else {
        if ($string[$i - 1] == $delimiter) {
          $out_item[$position] .= '';
        }
        $position++;
        $escape = FALSE;
        $double_escape = FALSE;
      }
    }
    elseif ($c == $enclosure) {
      if ($double_escape) {
        $out_item[$position] .= $enclosure;
        $double_escape = FALSE;
      }
      if ($escape) {
        $escape = FALSE;
        $double_escape = TRUE;
      }
      else {
        $escape = TRUE;
        $double_escape = FALSE;
      }
    }
    else {
      if ($double_escape) {
        $out_item[$position] .= $enclosure;
        $double_escape = FALSE;
      }
      $out_item[$position] .= $c;
    }
    $i++;
  }
  if (!empty($out_item)) {
    $lines[] = $out_item;
  }
  return $lines;
}

/**
 * Callback for actions.
 */
function mukurtu_export_csv_action_form($context, &$form_state) {
  return mukurtu_export_action_form($context, $form_state, 'csv');
}