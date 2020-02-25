<?php

/**
 * Settings callback.
 */
function mukurtu_export_collection_builder_settings($form, $form_state) {
  $is_batch = isset($form_state['mukurtu_export']['is_batch']) ? $form_state['mukurtu_export']['is_batch'] : FALSE;
  $format = 'collection_builder';

  $settings[$format] = array(
    '#type' => 'fieldset',
    '#title' => t('Mukurtu CollectionBuilder Export Settings'),
    '#description' => t(
     'This is a placeholder for a future CollectionBuilder config form.
     '
    ),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $settings[$format]['mukurtu_export_csv_is_batch'] = array(
    '#type' => 'hidden',
    '#value' => $is_batch,
  );

  return $settings;
}

/**
 * Export callback.
 */
function mukurtu_export_collection_builder_export($entities, $field_list, $settings) {
  module_load_include('inc', 'mukurtu_export', 'formats/csv');

  // CSV format settings.
  $delimiter = mukurtu_export_csv_string(",");
  $enclosure = mukurtu_export_csv_string("\"");
  $separator = mukurtu_export_csv_string("\r\n");
  $escape_eol = ';';

  // None -> NULL, Some -> array of entity types, All -> 'all' in array.
  $export_referenced = array('paragraphs_item' => 'all', 'scald_atom' => 'all');
  $export_files = FALSE;

  // Content format settings.
  $id_format = 'nid';
  $multivalue_delimiter = ";";

  // Batch settings.
  $batch_current = isset($settings['batch_current']) ? $settings['batch_current'] : NULL;
  $batch_total = isset($settings['batch_total']) ? $settings['batch_total'] : NULL;
  $batch_previous = isset($settings['batch_previous']) ? $settings['batch_previous'] : array();
  $is_batch = isset($settings['batch_current']) ? TRUE : FALSE;

  // If GUIDs are selected for export, don't export the native ID field of the entity.
  if ($id_format == 'guid') {
    foreach ($field_list as $entity_type => $bundle) {
      $id_field = _mukurtu_export_entity_id($entity_type);
      foreach ($bundle as $bundle_name => $bundle_fields) {
        if (isset($field_list[$entity_type][$bundle_name][$id_field])) {
          $field_list[$entity_type][$bundle_name][$id_field] = 0;
        }
      }
    }
  }

  $encoded_export = ($is_batch == TRUE) ? $batch_previous : array();
  foreach ($entities as $entity_type => $bundle) {
    foreach ($bundle as $bundle_name => $bundle_entities) {
      $encoded_export = mukurtu_export_collection_builder_encode($entity_type, $bundle_name, $bundle_entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list, $id_format, $is_batch, $export_referenced, $export_files, $encoded_export);
    }
  }

  if ($is_batch == TRUE) {
    if ($batch_current < $batch_total) {
      // Batch job not complete, return raw data so the next run can modify.
      return $encoded_export;
    } else {
      // Batch job complete, convert raw data to CSV and package files.
      return _mukurtu_export_collection_builder_download_file(_mukurtu_export_collection_builder_encoded_content_to_csv_array($encoded_export, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter));
    }
  }
  return _mukurtu_export_collection_builder_download_file($encoded_export);
}


/**
 * Build the encoded array of fields.
 */
function mukurtu_export_collection_builder_encode($entity_type, $bundle_name, $entities, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter, $field_list, $id_format = 'internal', $is_batch = FALSE, $export_referenced = NULL, $export_files = TRUE, $previous_encoded_content = array()) {
  $encoded_content = $previous_encoded_content;

  foreach (array_keys($entities) as $entity_key) {
    $new_entity_key = "{$entity_type}__{$bundle_name}_{$entity_key}";
    // Check if this entity has already been encoded.
    if (isset($encoded_content['__exported_key_list'][$entity_type][$bundle_name][$new_entity_key])) {
      continue;
    }
    mukurtu_export_csv_encode_entity($encoded_content, $new_entity_key, $entities[$entity_key], $entity_type, $bundle_name, $field_list, $id_format, $export_referenced, $export_files);

    // Handle special cases after initial encode.
    mukurtu_export_csv_post_encode_entity($encoded_content, $new_entity_key, $entities[$entity_key], $entity_type, $bundle_name, $field_list);
  }

  if ($is_batch == TRUE) {
    return $encoded_content;
  }

//  dpm($encoded_content);
  return _mukurtu_export_collection_builder_encoded_content_to_csv_array($encoded_content, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter);
}


/**
 * Converts the encoded entity array into an array that resembles CSV format.
 */
function _mukurtu_export_collection_builder_encoded_content_to_csv_array($encoded_content, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter) {
  $prefix = '!!__cb__!!';

  // Do CollectionBuilder post processing on CSV here.
  if (!empty($encoded_content['__exported_key_list']['node']['digital_heritage'])) {
    $count = count($encoded_content['__exported_key_list']['node']['digital_heritage']);
    $digits = strlen(strval($count));
    $i = 0;

    $direct_mapped_fields = array(
      'mukurtu-id' => 'nid',
      'title' => 'title',
      'creator' => 'field_creator',
      'description' => 'field_description',
      'subject' => 'field_category',
      'location' => 'field_coverage_description',
      'source' => 'field_source',
      'original_identifier' => 'field_identifier',
      'rights' => 'field_rights',
      'rightsstatement' => 'field_licence_std_cc',
    );

    // Process all fields that are basically one-to-one mappings.
    foreach ($direct_mapped_fields as $cb_field => $m_field) {
      if (!empty($encoded_content['node']['digital_heritage'][$m_field])) {
        $encoded_content['node']['digital_heritage']["{$prefix}{$cb_field}"] = $encoded_content['node']['digital_heritage'][$m_field];
      }
    }

    // Process fields that require some logic.
    foreach ($encoded_content['__exported_key_list']['node']['digital_heritage'] as $dh_key => $dh) {
      // objectid.
      $encoded_content['node']['digital_heritage']["{$prefix}objectid"][$dh_key] = "coll" . str_pad(strval($i++), $digits, "0", STR_PAD_LEFT);

      // date.
      if (!empty($encoded_content['node']['digital_heritage']["field_original_date"][$dh_key])) {
        $encoded_content['node']['digital_heritage']["{$prefix}date"][$dh_key] = $encoded_content['node']['digital_heritage']["field_original_date"][$dh_key][0];
      }

      // Media.
      if (!empty($encoded_content['node']['digital_heritage']["field_media_asset"][$dh_key][0])) {
        $sid = $encoded_content['node']['digital_heritage']["field_media_asset"][$dh_key][0];
        $atom = scald_atom_load($sid);

        if ($atom) {
          // mediasource.
          $media_source = $encoded_content['scald_atom'][$atom->type]['file_source']["scald_atom__{$atom->type}_{$sid}"][0];
          $encoded_content['node']['digital_heritage']["{$prefix}mediasource"][$dh_key] = $media_source;

          // thumbnail/small_image.
          if ($atom->type == 'image') {
            $encoded_content['node']['digital_heritage']["{$prefix}thumbnail"][$dh_key] = image_style_url('thumbnail', $atom->file_source);
            $encoded_content['node']['digital_heritage']["{$prefix}small_image"][$dh_key] = image_style_url('medium', $atom->file_source);
          } else {
            $encoded_content['node']['digital_heritage']["{$prefix}thumbnail"][$dh_key] = image_style_url('thumbnail', $atom->thumbnail_source);
            $encoded_content['node']['digital_heritage']["{$prefix}small_image"][$dh_key] = image_style_url('medium', $atom->thumbnail_source);
          }

          // format.
          if (isset($atom->base_entity->filemime)) {
            if ($atom->base_entity->filemime == 'audio/mpeg' && substr_compare(strtolower($atom->file_source), 'mp3', -3) === 0) {
              // CollectionBuilder wants 'audio/mp3' rather than 'audio/mpeg'.
              $encoded_content['node']['digital_heritage']["{$prefix}format"][$dh_key] = 'audio/mp3';
            } else {
              $encoded_content['node']['digital_heritage']["{$prefix}format"][$dh_key] = $atom->base_entity->filemime;
            }
          } else {
            if ($atom->type == 'video' && substr_compare(strtolower($atom->file_source), 'mp4', -3) === 0) {
              $encoded_content['node']['digital_heritage']["{$prefix}format"][$dh_key] = 'video/mp4';
            }
          }
        }
      }

      // Location Lat/Long.
      if (!empty($encoded_content['node']['digital_heritage']["field_coverage"][$dh_key][0])) {
        $point = $encoded_content['node']['digital_heritage']["field_coverage"][$dh_key][0];
        preg_match('/POINT\s*\((-*\d+\.\d+)\s*(-*\d+\.\d+)\)/', $point, $latlng_matches);
        if (count($latlng_matches) == 3) {
          $encoded_content['node']['digital_heritage']["{$prefix}latitude"][$dh_key] = $latlng_matches[1];
          $encoded_content['node']['digital_heritage']["{$prefix}longitude"][$dh_key] = $latlng_matches[2];
        }
      }
    }

    // CollectionBuilder only wants nodes, remove everything else.
    foreach ($encoded_content as $entity_type => $content) {
      if ($entity_type != 'node' && $entity_type != '__exported_key_list') {
        unset($encoded_content[$entity_type]);
      }
    }

    // CollectionBuilder only wants digital heritage, remove everything else.
    foreach ($encoded_content['node'] as $bundle_type => $content) {
      if ($bundle_type != 'digital_heritage') {
        unset($encoded_content['node'][$bundle_type]);
      }
    }

    // Remove all non-CollectionBuilder fields.
    foreach ($encoded_content['node']['digital_heritage'] as $field_name => $field_value) {
      if (strpos($field_name, $prefix) === FALSE) {
        unset($encoded_content['node']['digital_heritage'][$field_name]);
      }
    }
  }

  // Send the result off to the normal CSV export tools to package.
  $csv = _mukurtu_export_csv_encoded_content_to_csv_array($encoded_content, $delimiter, $enclosure, $separator, $escape_eol, $multivalue_delimiter);

  // Remove our CollectionBuilder prefix.
  $csv['node']['digital_heritage'] = str_replace($prefix, '', $csv['node']['digital_heritage']);

  return $csv;
}

/**
 * Save the CSV data to a single CSV file.
 */
function _mukurtu_export_collection_builder_download_file($encoded_export) {
  $filename = "CollectionBuilderExport.csv";
  $destination = 'private://batch_export/';
  file_prepare_directory($destination, FILE_CREATE_DIRECTORY);
  $download_file = file_save_data($encoded_export['node']['digital_heritage'], $destination . $filename, FILE_EXISTS_RENAME);
  return $download_file;
}
