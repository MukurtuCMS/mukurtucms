<?php

/**
 * @file
 * The Node export csv format handler.
 *
 * Adds configurable csv format to Node export.
 */

/**
 * Settings callback.
 */
function mukurtu_export_csv_settings($form, $form_state) {
  $settings['csv'] = array(
    '#type' => 'fieldset',
    '#title' => t('csv format settings'),
    '#description' => t(
     'Select how your csv output will be formatted - this must be configured the
     same on both sites.  By default this is configured to RFC4180 CSV format
     where the delimiter is a comma (,), the enclosure is a double-quote ("),
     and the separator is CRLF (\r\n).  Not all configurations may be possible,
     use wisely.  Enclosure will only be used to escape values that contain any
     of the configured strings.  Additionally single-quotes will be used to
     escape values that are equivalent to reserved words (NULL, TRUE, FALSE).'
    ),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('Value delimiter'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_delimiter', ','),
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

  $settings['csv']['mukurtu_export_csv_escape_eol'] = array(
    '#type' => 'checkbox',
    '#title' => t('Always escape values containing line breaks'),
    '#default_value' => variable_get('mukurtu_export_csv_escape_eol', 1),
    '#description' => t('This is to overcome problems where Windows injects CRLF line breaks.'),
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
function mukurtu_export_csv_export($entities, $format, $field_list = NULL) {
  $delimiter = mukurtu_export_csv_string(variable_get('mukurtu_export_csv_delimiter', ','));
  $enclosure = mukurtu_export_csv_string(variable_get('mukurtu_export_csv_enclosure', '"'));
  $separator = mukurtu_export_csv_string(variable_get('mukurtu_export_csv_separator', '\r\n'));
  $escape_eol = variable_get('mukurtu_export_csv_escape_eol', 1);
  $multivalue_delimiter = variable_get('mukurtu_export_csv_multivalue_delimiter', ';');

  $encoded_export = array();
  foreach ($entities as $entity_type => $bundle) {
    foreach ($bundle as $bundle_name => $bundle_entities) {
      //$encoded_export[$entity_type][$bundle_name] = mukurtu_export_csv_encode($entity_type, $bundle_name, $bundle_entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list[$entity_type][$bundle_name]);
        $encoded_export = array_merge_recursive($encoded_export, mukurtu_export_csv_encode($entity_type, $bundle_name, $bundle_entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list[$entity_type][$bundle_name]));
    }
  }
  return $encoded_export;
}

/**
 * Build csv string.
 */
function mukurtu_export_csv_encode($entity_type, $bundle_name, $entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list) {
  $encoded_nodes = array();
  $csv_lines = array();
  $csv_output = array();

  $node_keys = array();

  foreach (array_keys($entities) as $node_key) {
    $new_node_key = "{$entity_type}__{$bundle_name}_{$node_key}";
    $node_keys[] = $new_node_key;
    mukurtu_export_csv_encode_node($encoded_nodes, $new_node_key, $entities[$node_key], $entity_type, $bundle_name, $field_list);
  }

  // Remove bookkeeping info
  unset($encoded_nodes['__exported_key_list']);

  foreach(array_keys($encoded_nodes) as $encoded_entity_type) {
    foreach(array_keys($encoded_nodes[$encoded_entity_type]) as $encoded_bundle_name) {
      $csv_lines[$encoded_entity_type][$encoded_bundle_name]['mukurtu_export_csv_header'] = array_keys($encoded_nodes[$encoded_entity_type][$encoded_bundle_name]);
      foreach (array_keys($encoded_nodes[$encoded_entity_type][$encoded_bundle_name]) as $header_value) {
        foreach (array_keys($encoded_nodes[$encoded_entity_type][$encoded_bundle_name][$header_value]) as $encoded_node_key) {
          $csv_lines[$encoded_entity_type][$encoded_bundle_name][$encoded_node_key][$header_value] = $encoded_nodes[$encoded_entity_type][$encoded_bundle_name][$header_value][$encoded_node_key];
        }
      }
      $csv_output[$encoded_entity_type][$encoded_bundle_name] = mukurtu_export_csv_array_to_csv($csv_lines[$encoded_entity_type][$encoded_bundle_name], $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter);
    }
  }

  return $csv_output;
}

/**
 * Process a node and update $header and $encoded_nodes accordingly.
 */
function mukurtu_export_csv_encode_node(&$encoded_nodes, $node_key, $var, $entity_type = NULL, $bundle_name = NULL, $header_list = NULL, $parent = NULL, $parent_index = 0) {
  foreach ($var as $k => &$v) {
    // Get the new header value.
    list($header_value, $header_index) = mukurtu_export_csv_encode_header_value($parent, $parent_index, $var, $k);

    // Skip export for fields that have been selected for exclusion.
    // Skip export for fields that aren't present in the list, if given a non-null list.
    // For a null list, assume we want to export everything.
    if((!is_null($header_list) && isset($header_list[$header_value]) && $header_list[$header_value] == 0)
        ||
        (!is_null($header_list) && !isset($header_list[$header_value]))) {
      continue;
    }

    //if (is_object($v) || is_array($v)) {
    if (is_array($v) && !is_numeric($k)) {
      // Recurse through the structure.
      mukurtu_export_csv_encode_node($encoded_nodes, $node_key, $v, $entity_type, $bundle_name, $header_list, $header_value, $header_index);
    }
    else {
      // Create a safe text version of this value and store it against the header using a safe key.
      list($value, $referenced_entities_to_encode) = mukurtu_export_extract_value($entity_type, $parent, $v);
      foreach($referenced_entities_to_encode as $referenced_entity_type => $referenced_entity) {
        foreach($referenced_entity as $r_id => $r_entity) {
          // Check permission?

          // Load entity
          $referenced_entity_object = entity_load($referenced_entity_type, array($r_id));
          if(empty($referenced_entity_object)) {
            continue;
          }
          $new_node_key = "{$referenced_entity_type}__{$referenced_entity_object[$r_id]->type}_{$r_id}";

          // Check if already exported, prevent infinite recursion
          if(isset($encoded_nodes['__exported_key_list'][$new_node_key])) {
            return;
          }
          mukurtu_export_csv_encode_node($encoded_nodes, $new_node_key, $referenced_entity_object[$r_id], $referenced_entity_type, $referenced_entity_object[$r_id]->type);
        }
      }
      $encoded_nodes[$entity_type][$bundle_name][$header_value][$node_key][$header_index] = mukurtu_export_csv_encode_sanitize_value($value);
      $encoded_nodes['__exported_key_list'][$node_key] = TRUE;
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
 *  Interpret a csv string.
 */
function mukurtu_export_csv_decode($code_string, $delimiter, $enclosure, $separator) {
  // Get array data from csv.
  $array = @mukurtu_export_csv_csv_to_array($code_string, $delimiter, $enclosure, $separator);

  // If the first two rows are of equal length, we can assume this is a csv.
  // Also checks there are a decent number of fields.
  if (!empty($array[0]) && !empty($array[1]) && count($array[0]) > 10 && count($array[0]) == count($array[1])) {
    $nodes = array();

    // Assume row 0 is the header, and the rest of the rows are the nodes.
    $header = array_shift($array);

    // Build the nodes.
    foreach ($array as &$row) {
      $node = (object)array();
      foreach ($row as $key => $item) {
        $item = mukurtu_export_csv_decode_sanitize_value($item);
        eval('$node->' . $header[$key] . ' = ' . $item . ';');
      }
      $nodes[] = $node;
    }

    return $nodes;
  }
}

/**
 *  Encode csv.
 */
function mukurtu_export_csv_array_to_csv($array, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter) {
  $lines = array();
  foreach ($array as $line) {
    $out_item = array();
    foreach ($line as $line_key => $item) {
      if(!is_array($item)) {
        $item = array($item);
      }

      //$item = mukurtu_export_extract_value('node', $line_key, $item);

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
    $lines[] = implode($delimiter, $out_item);
  }
  return implode($separator, $lines);
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