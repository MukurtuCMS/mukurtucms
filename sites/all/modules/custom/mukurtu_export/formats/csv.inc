<?php

/**
 * @file
 * The Mukurtu export csv format handler.
 *
 * Adds configurable csv format to Mukurtu export.
 * This module is based on the 'dsv' format module from Node Export.
 *
 */

/**
 * Settings callback.
 */
function mukurtu_export_csv_settings($form, $form_state) {
  $is_batch = isset($form_state['mukurtu_export']['is_batch']) ? $form_state['mukurtu_export']['is_batch'] : FALSE;

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

  $settings['csv']['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('File Format Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );

  $settings['csv']['advanced']['mukurtu_export_csv_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('Field delimiter'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_delimiter', ','),
    '#description' => t(
    'This delimiter will be used to separate fields. Mukurtu uses comma separated values by default.'),
    '#required' => TRUE,
  );

  $settings['csv']['advanced']['mukurtu_export_csv_enclosure'] = array(
    '#type' => 'textfield',
      //    '#type' => 'hidden',
    '#title' => t('Escape enclosure'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_enclosure', '"'),
    '#required' => TRUE,
  );

  $settings['csv']['advanced']['mukurtu_export_csv_separator'] = array(
    '#type' => 'textfield',
    '#title' => t('Record separator'),
    '#size' => 5,
    '#maxlength' => 255,
    '#default_value' => variable_get('mukurtu_export_csv_separator', '\r\n'),
    '#required' => TRUE,
  );

  $settings['csv']['advanced']['mukurtu_export_csv_multivalue_delimiter'] = array(
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

  $settings['csv']['advanced']['mukurtu_export_csv_escape_eol'] = array(
    '#type' => 'checkbox',
    '#title' => t('Always escape values containing line breaks'),
    '#default_value' => variable_get('mukurtu_export_csv_escape_eol', 1),
    '#description' => t('This is to overcome problems where Windows injects CRLF line breaks.'),
  );

  $settings['csv']['mukurtu_export_csv_id_format'] = array(
    '#type' => 'radios',
    '#title' => t('Content identifier format'),
    '#options' => array(
      'internal' => 'Export internal content identifiers for re-import',
      'guid' => 'Export GUIDs for import into a different site'
    ),
    '#default_value' => 'internal',
    '#description' => t('Select the identifier format for export.'),
    '#required' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_referenced_content'] = array(
    '#type' => 'radios',
    '#title' => t('Export related content'),
    '#options' => array(
      'all' => 'Export the selected content and all related content (communities, cultural protocols, related items, scald atoms, etc)',
      'scald_atom' => 'Export the selected content and included referenced scald atoms only',
      'none' => 'Export only the selected content',
    ),
    '#default_value' => 'scald_atom',
    '#description' => t('Select if related content should be exported. Exporting all related content may be necessary if importing to a new site, but can result in very large exports. If you are exporting content for re-import on the same site, exporting the selected content only or with referenced scald atoms is usually sufficient.'),
    '#required' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_binary_files'] = array(
    '#type' => 'radios',
    '#title' => t('Export files'),
    '#options' => array(
      'yes' => 'Package binary files (images, video, etc)',
      'no' => 'Export metadata only'
    ),
    '#default_value' => 'no',
    '#description' => t('Select if binary files (e.g., jpg, mp4, pdf, png) should be downloaded.'),
    '#required' => TRUE,
  );

  $settings['csv']['mukurtu_export_csv_is_batch'] = array(
    '#type' => 'hidden',
    '#value' => $is_batch,
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
  // CSV format settings
  $delimiter = mukurtu_export_csv_string($settings['advanced']['mukurtu_export_csv_delimiter']);
  $enclosure = mukurtu_export_csv_string($settings['advanced']['mukurtu_export_csv_enclosure']);
  $separator = mukurtu_export_csv_string($settings['advanced']['mukurtu_export_csv_separator']);
  $escape_eol = $settings['advanced']['mukurtu_export_csv_escape_eol'];

  // None -> NULL, Some -> array of entity types, All -> 'all' in array.
  $export_referenced = array('paragraphs_item' => 'all');
  $export_files = TRUE;

  if (isset($settings['mukurtu_export_csv_referenced_content'])) {
    if ($settings['mukurtu_export_csv_referenced_content'] == 'all') {
      $export_referenced = array('all' => 'all');
    }

    if ($settings['mukurtu_export_csv_referenced_content'] == 'scald_atom') {
      $export_referenced = array('paragraphs_item' => 'all', 'scald_atom' => 'all');
    }
  }

  if(isset($settings['mukurtu_export_csv_binary_files'])) {
    if($settings['mukurtu_export_csv_binary_files'] == 'no') {
      $export_files = FALSE;
    }
  }

  // Content format settings
  $id_format = $settings['mukurtu_export_csv_id_format'];
  $multivalue_delimiter = $settings['advanced']['mukurtu_export_csv_multivalue_delimiter'];

  // Batch settings
  $is_batch = mukurtu_export_csv_string($settings['mukurtu_export_csv_is_batch']);
  $batch_current = isset($settings['batch_current']) ? $settings['batch_current'] : NULL;
  $batch_total = isset($settings['batch_total']) ? $settings['batch_total'] : NULL;
  $batch_previous = isset($settings['batch_previous']) ? $settings['batch_previous'] : array();

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

  // If any scald atoms initiated the export, we need to load them with scald_atom_load
  // because Drupal used entity_load which doesn't pull in some of the special scald fields
  // like base_entity which we need for the binary file info.
  if (!empty($entities['scald_atom'])) {
    foreach ($entities['scald_atom'] as $scald_type) {
      foreach ($scald_type as &$atom) {
        $atom = scald_atom_load($atom->sid);
      }
    }
  }

  $encoded_export = ($is_batch == TRUE) ? $batch_previous : array();
  foreach ($entities as $entity_type => $bundle) {
    foreach ($bundle as $bundle_name => $bundle_entities) {
        $encoded_export = mukurtu_export_csv_encode($entity_type, $bundle_name, $bundle_entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list, $id_format, $is_batch, $export_referenced, $export_files, $encoded_export);
    }
  }

  if($is_batch == TRUE) {
    if($batch_current < $batch_total) {
      // Batch job not complete, return raw data so the next run can modify
      return $encoded_export;
    } else {
      // Batch job complete, convert raw data to CSV and package files
      return mukurtu_export_csv_export_to_zip(_mukurtu_export_csv_encoded_content_to_csv_array($encoded_export, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter));
    }
  }
  return mukurtu_export_csv_export_to_zip($encoded_export);
}

/**
 * Packages a CSV array into a Zip archive containing exported CSV files and media
 */
function mukurtu_export_csv_export_to_zip($encoded_export) {
  $csv_files = array();

  $zip = new ZipArchive();
  $tempfile = drupal_tempnam('temporary://', 'MUKURTUZIP');
  $tempfile .= ".zip";
  $zip->open(drupal_realpath($tempfile), ZipArchive::CREATE);

  // These are raw files that we want to include in the Zip
  if(isset($encoded_export['__files'])) {
    foreach($encoded_export['__files'] as $binary_file) {
      if (!empty(drupal_realpath($binary_file['uri']))) {
        $zip->addFile(drupal_realpath($binary_file['uri']), $binary_file['filename']);
      }
    }

    // Unset this, so we don't try to further process them
    unset($encoded_export['__files']);
  }

  // Write all the CSV files and add them to the Zip archive
  foreach ($encoded_export as $entity_type => $bundle) {
    foreach ($bundle as $bundle_name => $bundle_entities) {
      $temp = file_save_data($encoded_export[$entity_type][$bundle_name]);
      $csv_files[] = $temp;
      $filename_variants = mukurtu_batch_import_get_name_variants($entity_type, $bundle_name);
      $zip->addFile(drupal_realpath($temp->uri), "{$filename_variants[0]}.csv");
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

  return $download_file;
}

/**
 * Build the encoded array of fields.
 */
function mukurtu_export_csv_encode($entity_type, $bundle_name, $entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list, $id_format = 'internal', $is_batch = FALSE, $export_referenced = NULL, $export_files = TRUE, $previous_encoded_content = array()) {
  $encoded_content = $previous_encoded_content;

  foreach (array_keys($entities) as $entity_key) {
    $new_entity_key = "{$entity_type}__{$bundle_name}_{$entity_key}";
    // Check if this entity has already been encoded
    if(isset($encoded_content['__exported_key_list'][$entity_type][$bundle_name][$new_entity_key])) {
      continue;
    }
    mukurtu_export_csv_encode_entity($encoded_content, $new_entity_key, $entities[$entity_key], $entity_type, $bundle_name, $field_list, $id_format, $export_referenced, $export_files);

    // Handle special cases after initial encode
    mukurtu_export_csv_post_encode_entity($encoded_content, $new_entity_key, $entities[$entity_key], $entity_type, $bundle_name, $field_list);
  }

  if($is_batch == TRUE) {
    return $encoded_content;
  }
  return _mukurtu_export_csv_encoded_content_to_csv_array($encoded_content, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter);
}

/**
 * Post entity encode step to handle special case scenarios
 */
function mukurtu_export_csv_post_encode_entity(&$encoded_content, $entity_key, $entity, $entity_type, $bundle_name, $field_list, $id_format = 'internal') {
  if($entity_type == 'scald_atom') {
    // Youtube/Vimeo fix
    switch($entity->provider) {
      case 'scald_dailymotion':
      case 'scald_youtube':
      case 'scald_vimeo':
        // If exporting the media source
        if($field_list[$entity_type][$bundle_name]['file_source']) {
          // Media source is kept in the base_id for scald_youtube/scald_vimeo
          $encoded_content[$entity_type][$bundle_name]['file_source'][$entity_key][0] = $entity->base_id;
        }
        break;
    }
  }

  // Need to keep track of paragraph's host entity so we can keep references
  // intact on import.
  if ($entity_type == 'paragraphs_item') {
    if ($field_list[$entity_type][$bundle_name]['host_entity']) {
      $host_entity = $entity->hostEntity();
      $host_entity_id = ($id_format == 'guid') ? _mukurtu_export_entity_get_guid('node', $host_entity->nid) : $host_entity->nid;
      $encoded_content[$entity_type][$bundle_name]['host_entity'][$entity_key][0] = $host_entity_id;
    }
  }

  // User name.
  if (isset($entity->uid) && $field_list[$entity_type][$bundle_name]['user_name']) {
    $author = user_load($entity->uid);
    if ($author && isset($author->name)) {
      $encoded_content[$entity_type][$bundle_name]['user_name'][$entity_key][0] = $author->name;
    }
  }
}

/**
 * Converts the encoded entity array into an array that resembles CSV format
 */
function _mukurtu_export_csv_encoded_content_to_csv_array($encoded_content, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter) {
  $csv_lines = array();
  $csv_output = array();

  // Remove bookkeeping info
  $encoded_list = $encoded_content['__exported_key_list'];
  unset($encoded_content['__exported_key_list']);

  // Binary files to be handled
  if(isset($encoded_content['__files'])) {
    $csv_output['__files'] = $encoded_content['__files'];
    unset($encoded_content['__files']);
  }

  foreach(array_keys($encoded_content) as $encoded_entity_type) {
    foreach(array_keys($encoded_content[$encoded_entity_type]) as $encoded_bundle_name) {
      $csv_lines[$encoded_entity_type][$encoded_bundle_name]['mukurtu_export_csv_header'] = array_keys($encoded_content[$encoded_entity_type][$encoded_bundle_name]);

      // Convert header field names to friendly labels
      foreach($csv_lines[$encoded_entity_type][$encoded_bundle_name]['mukurtu_export_csv_header'] as $k => $v) {
          $csv_lines[$encoded_entity_type][$encoded_bundle_name]['mukurtu_export_csv_header'][$k] = _mukurtu_export_csv_get_header_label($encoded_entity_type, $encoded_bundle_name, $v);
      }

      foreach (array_keys($encoded_content[$encoded_entity_type][$encoded_bundle_name]) as $header_value) {
        foreach (array_keys($encoded_list[$encoded_entity_type][$encoded_bundle_name]) as $encoded_entity_key) {
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
 * Return the header label for a field name in a particular entity/bundle
 */
function _mukurtu_export_csv_get_header_label($entity_type, $bundle_name, $field_name) {
    // Check for a feeds importer for this type/bundle
    $importer = variable_get("mukurtu_export_feeds_{$entity_type}_{$bundle_name}", "mukurtu_import_{$entity_type}_{$bundle_name}");
    $mapping = array();

    if ($config = ctools_export_load_object('feeds_importer', 'conditions', array('id' => $importer))) {
        $config = array_shift($config);
        foreach($config->config['processor']['config']['mappings'] as $map) {
            $mapping[$map['target']] = $map['source'];
        }
    }

    // If we have a feeds importer setup, try to use the expected import headers as the export headers
    if(!empty($mapping)) {
        foreach($mapping as $import_field_name => $import_field_label) {
            if(strpos($import_field_name, $field_name) !== FALSE) {
                return $import_field_label;
            }
        }
    }

    // Otherwise, default to using the label of the field
    if($field_name == 'title') {
        $extra_fields = field_info_extra_fields($entity_type, $bundle_name, 'form');
        $title_label = $extra_fields['title']['label'];
        return $title_label;
    }

    $info = field_info_instance($entity_type, $field_name, $bundle_name);
    if(!$info) {
        return $field_name;
    }

    $label = $info['label'];
    return $label;
}

/**
 * Process an entity and update $header and $encoded_content accordingly.
 */
function mukurtu_export_csv_encode_entity(&$encoded_content, $entity_key, $var, $entity_type = NULL, $bundle_name = NULL, $field_list = NULL, $id_format = 'internal', $export_referenced = NULL, $export_files = TRUE, $parent = NULL, $parent_index = 0) {

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
      mukurtu_export_csv_encode_entity($encoded_content, $entity_key, $v, $entity_type, $bundle_name, $field_list, $id_format, $export_referenced, $export_files, $header_value, $header_index);
    }
    else {
      // Create a safe text version of this value and store it against the header using a safe key.
      $options = array(
        'id_format' => $id_format,
        'export_files' => $export_files,
      );

      // Get exportable value from field
      //      if(is_null($parent)) {
      //          list($value, $referenced_entities_to_encode, $files) = mukurtu_export_extract_value($entity_type, $header_value, $v, $options);
      //      } else {
          list($value, $referenced_entities_to_encode, $files) = mukurtu_export_extract_value($entity_type, $parent, $v, $options);
          //      }

      // Add any raw files we want to include
      if($export_files && !empty($files)) {
        foreach($files as $fid => $fileinfo) {
          $encoded_content['__files'][$fid] = $fileinfo;
        }
      }

      // Run through all the content referenced by this field and decide if we should export it.
      if ($export_referenced) {
        $all = isset($export_referenced['all']) ? TRUE : FALSE;
        foreach ($referenced_entities_to_encode as $referenced_entity_type => $referenced_entity) {
          // Is this referenced entity type selected for export?
          if (!$all && !isset($export_referenced[$referenced_entity_type])) {
            continue;
          }

          foreach ($referenced_entity as $r_id => $r_entity) {
            // Check permission?

            // Load entity.
            $referenced_entity_object = mukurtu_export_entity_load_wrapper($referenced_entity_type, array($r_id));
            if (empty($referenced_entity_object) OR !$referenced_entity_object[$r_id]) {
              continue;
            }

            // Get referenced content bundle type.
            $referenced_entity_object_wrapper = entity_metadata_wrapper($referenced_entity_type, $referenced_entity_object[$r_id]);
            $ref_bundle_type = $referenced_entity_object_wrapper->getBundle();
            $new_entity_key = "{$referenced_entity_type}__{$ref_bundle_type}_{$r_id}";

            // Check if already exported, prevent infinite recursion.
            if (isset($encoded_content['__exported_key_list'][$referenced_entity_type][$ref_bundle_type][$new_entity_key])) {
              continue;
            }

            // If that bundle type is selected for export, encode referenced content.
            if ($all || $export_referenced[$referenced_entity_type] == 'all' || in_array($ref_bundle_type, $export_referenced[$referenced_entity_type])) {
              mukurtu_export_csv_encode_entity($encoded_content, $new_entity_key, $referenced_entity_object[$r_id], $referenced_entity_type, $ref_bundle_type, $field_list, $id_format, $export_referenced, $export_files);
              mukurtu_export_csv_post_encode_entity($encoded_content, $new_entity_key, $referenced_entity_object[$r_id], $referenced_entity_type, $ref_bundle_type, $field_list, $id_format);
            }
          }
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

  foreach ($array as $line) {
    $out_item = array();
    foreach ($line as $line_key => $item) {
      if(!is_array($item)) {
        $item = array($item);
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
