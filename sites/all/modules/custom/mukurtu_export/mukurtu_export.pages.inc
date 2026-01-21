<?php

/**
 * Form for export
 */
function mukurtu_export_form($form, &$form_state) {
  $export_ids = isset($form_state['mukurtu_export']['export_ids']) ? $form_state['mukurtu_export']['export_ids'] : NULL;
  $formatter = isset($form_state['mukurtu_export']['formatter']) ? $form_state['mukurtu_export']['formatter'] : NULL;
  $formatter_settings = isset($form_state['mukurtu_export']['formatter_settings']) ? $form_state['mukurtu_export']['formatter_settings'] : NULL;
  $field_list = isset($form_state['mukurtu_export']['export_fields']) ? $form_state['mukurtu_export']['export_fields'] : NULL;
  $is_batch = isset($form_state['mukurtu_export']['is_batch']) ? $form_state['mukurtu_export']['is_batch'] : FALSE;
  //$is_batch = (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Execute') ? TRUE : FALSE;

  if(!$is_batch && is_null($export_ids)){
      $current_node = menu_get_object();
      if($current_node) {
          $export_ids = array('node' => array($current_node->type => array($current_node->nid => $current_node)));
      } else {
          $args = arg();
          if($args[0] == 'taxonomy') {
              $item = menu_get_object('taxonomy_term', 2);
              $export_ids = array('taxonomy_term' => array($item->vocabulary_machine_name => array($item->tid => $item)));
          }

          if($args[0] == 'atom') {
              $item = menu_get_object('scald_atom', 1);
              $export_ids = array('scald_atom' => array($item->type => array($item->sid => $item)));
          }
      }
  }

  // No format selected
  $format_handlers = mukurtu_export_format_handlers();
  // Format not specified or specified format isn't available
  if(is_null($formatter) || !in_array($formatter, array_keys($format_handlers))) {
      // Only one available format, default to that
      if(count($format_handlers) == 1) {
        $formatter = array_keys($format_handlers)[0];
        $form_state['mukurtu_export']['formatter'] = $formatter;
      } else {
        // Multiple formats, show selection form
        return mukurtu_export_format_selection_form($form, $form_state, $format_handlers);
      }
  }

  // Load formatter code
  include_once $format_handlers[$formatter]['#file'];

  // Format selected, need formatter settings
  if(is_null($formatter_settings)) {
    // Get settings form for formatter
    if(isset($format_handlers[$formatter]['#settings_callback']) && function_exists($format_handlers[$formatter]['#settings_callback'])) {
      $form['export']['settings'] = call_user_func($format_handlers[$formatter]['#settings_callback'], $form, $form_state);
    }
    if(!$is_batch) {
      $form['export_next_step'] = array(
        '#type' => 'submit',
        '#value' => t('Next'),
      );
      return $form;
    }
  }

  if(is_null($field_list)) {

    if(!$is_batch) {
      $form['download_file_top'] = array(
        '#type' => 'submit',
        '#value' => t('Download'),
      );
    }

    $form = mukurtu_export_fields_selection_form($form, $form_state, $export_ids);

    if(!$is_batch) {
      $form['download_file_bottom'] = array(
        '#type' => 'submit',
        '#value' => t('Download'),
      );
    }
    return $form;
  }

  // Batch run, wait to assemble export file
  if($is_batch) {
    return $form;
  }

  // Non-batch run, export and download exported file
  $download_file = call_user_func($format_handlers[$formatter]['#export_callback'], $export_ids, $field_list, $formatter_settings);
  return mukurtu_export_get_file($download_file);
}

function mukurtu_export_get_file($file) {
  header('Content-type: ' . $file->filemime);
  header('Content-Disposition: attachment; filename="' . $file->filename . '"');
  print(file_get_contents(drupal_realpath($file->uri)));
  file_delete($file);
  module_invoke_all('exit');
  exit;
}


/**
 * Form submit for export
 */
function mukurtu_export_form_submit($form, &$form_state) {
  // Content to export
  $form_state["rebuild"] = TRUE;
  if(isset($form_state['values']['export_ids'])) {
    $form_state['mukurtu_export']['export_ids'] = $form_state['values']['export_ids'];
  }

  // Formatter
  if(isset($form_state['values']['export_format'])) {
    $form_state['mukurtu_export']['formatter'] = $form_state['values']['export_format'];
  }

  // Formatter Settings
  if(isset($form_state['mukurtu_export']['formatter'])) {
    $format = $form_state['mukurtu_export']['formatter'];
    if(isset($form_state['values'][$format])) {
      $form_state['mukurtu_export']['formatter_settings'] = $form_state['values'][$format];
    }
  }

  // Field List
  if(isset($form_state['values']['export_fields'])) {
    $form_state['mukurtu_export']['export_fields'] = $form_state['values']['export_fields'];
    $_SESSION['mukurtu_export']['export_fields'] = $form_state['values']['export_fields'];
  }

}

/**
 * Form for selecting export format
 */
function mukurtu_export_format_selection_form($form, &$form_state, $format_handlers, $default_format = 'csv') {
  $formatter_options = array();
  foreach($format_handlers as $format => $format_info) {
    $formatter_options[$format] = $format_info['#title'];
  }

  $form['export_format'] = array(
    '#type' => 'radios',
    '#title' => t('Export Format'),
    '#options' => $formatter_options,
    '#default_value' => $default_format,
    '#description' => t('Select the format for export.'),
    '#tree' => TRUE,
  );

  $form['export_next_step'] = array(
    '#type' => 'submit',
    '#value' => t('Next'),
  );

  return $form;
}

/**
 * Form submit for export format
 */
function mukurtu_export_format_selection_form_submit($form, &$form_state) {
  $_SESSION['mukurtu_export']['format'] = $form_state['values']['export_format'];
}

/**
 * Form for selecting which fields to export
 */
function mukurtu_export_fields_selection_form($form, &$form_state, $export_ids = NULL, $reset = FALSE) {
  // Blacklist any Mukurtu specific book-keeping fields that definitely don't need to be exported
  $field_blacklist = array(
      'all' => array(
        'field_pre_actions',
        'field_personal_collections',
        'field_digital_heritage_count',
        'field_media_aggregate',
        'field_node_aggregate',
      ),
      'node' => array(
          'dictionary_word' => array('field_media_asset'),
          //'digital_heritage' => array('field_community_record_parent'),
      ),
      'scald_atom' => array(
          'audio' => array('og_group_ref'),
          'file' => array('og_group_ref'),
          'image' => array('og_group_ref'),
          'video' => array('og_group_ref'),
      )
  );

  $is_batch = isset($form_state['mukurtu_export']['is_batch']) ? $form_state['mukurtu_export']['is_batch'] : FALSE;

  $form['export_fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select Fields for Export'),
    '#collapsible' => TRUE,
    '#collapsed' => $is_batch,
    '#tree' => TRUE,
  );

  // Load defaults
  $defaults = NULL;
  if(!$reset && isset($_SESSION['mukurtu_export']['export_fields'])) {
    $defaults = $_SESSION['mukurtu_export']['export_fields'];
  }
  $defaults = mukurtu_export_filter_bidirectional_reference_fields($defaults);

  foreach(array_keys(entity_get_info()) as $entity_type) {

    // Currently only show node/scald_atom fields
    if(!in_array($entity_type, array('paragraphs_item', 'node', 'scald_atom', 'taxonomy_term'))) {
      continue;
    }

    $entity_info = entity_get_info($entity_type);
    $id = _mukurtu_export_entity_id($entity_type);

    foreach($entity_info['bundles'] as $bundle_name => $ids) {
      $form['export_fields'][$entity_type][$bundle_name] = array(
        '#type' => 'fieldset',
        '#title' => $entity_info['label'] . ' - ' . $entity_info['bundles'][$bundle_name]['label'],
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#weight' => 0,
      );

      $fields_info = field_info_instances($entity_type, $bundle_name);

      // Default fields
      // ID
      $id_label = t(strtoupper($id));

      $form['export_fields'][$entity_type][$bundle_name][$id] = array(
        '#type' => 'checkbox',
        '#title' => $id_label,
        '#default_value' => isset($defaults[$entity_type][$bundle_name][$id]) ? $defaults[$entity_type][$bundle_name][$id] : TRUE,
        '#weight' => -2,
      );

      // Username
      $form['export_fields'][$entity_type][$bundle_name]['user_name'] = array(
          '#type' => 'checkbox',
          '#title' => 'Username',
          '#default_value' => isset($defaults[$entity_type][$bundle_name]['user_name']) ? $defaults[$entity_type][$bundle_name]['user_name'] : TRUE,
          '#weight' => 1000,
      );

      // Extra Fields (title, etc)
      $extra_fields = field_info_extra_fields($entity_type, $bundle_name, 'form');
      if(!empty($extra_fields)) {
          foreach($extra_fields as $extra_field_name => $extra_field) {
              // Skip path/redirect fields
              if(in_array($extra_field_name, array('path', 'redirect'))) {
                  continue;
              }

              $form['export_fields'][$entity_type][$bundle_name][$extra_field_name] = array(
                  '#type' => 'checkbox',
                  '#title' => $extra_field['label'],
                  '#default_value' => isset($defaults[$entity_type][$bundle_name][$extra_field_name]) ? $defaults[$entity_type][$bundle_name][$extra_field_name] : TRUE,
                  '#weight' => -1,
              );
          }
      }

      // TEST
      if($entity_type == 'scald_atom') {
          $form['export_fields'][$entity_type][$bundle_name]['provider'] = array(
              '#type' => 'checkbox',
              '#title' => 'Scald Provider',
              '#default_value' => isset($defaults[$entity_type][$bundle_name]['data']) ? $defaults[$entity_type][$bundle_name]['data'] : TRUE,
              '#weight' => -1,
          );
          $form['export_fields'][$entity_type][$bundle_name]['file_source'] = array(
              '#type' => 'checkbox',
              '#title' => 'Media Source',
              '#default_value' => isset($defaults[$entity_type][$bundle_name]['data']) ? $defaults[$entity_type][$bundle_name]['data'] : TRUE,
              '#weight' => -1,
          );
      }

      if ($entity_type == 'paragraphs_item') {
        switch ($bundle_name) {
          case 'dictionary_word_bundle':
            $title = "Dictionary Word";
            break;

          default:
            $title = "Host Entity";
        }
        $form['export_fields'][$entity_type][$bundle_name]['host_entity'] = array(
            '#type' => 'checkbox',
            '#title' => $title,
            '#default_value' => isset($defaults[$entity_type][$bundle_name]['host_entity']) ? $defaults[$entity_type][$bundle_name]['host_entity'] : TRUE,
            '#weight' => -1,
        );
      }

      foreach($fields_info as $field_name => $field) {
        // Check global blacklist
        if(in_array($field_name, $field_blacklist['all'])) {
            continue;
        }

        // Check specific blacklist
        if(!empty($field_blacklist[$entity_type][$bundle_name]) && in_array($field_name, $field_blacklist[$entity_type][$bundle_name])) {
            continue;
        }

        $form['export_fields'][$entity_type][$bundle_name][$field_name] = array(
          '#type' => 'checkbox',
          '#title' => $field['label'],
          '#default_value' => isset($defaults[$entity_type][$bundle_name][$field_name]) ? $defaults[$entity_type][$bundle_name][$field_name] : TRUE,
          '#weight' => $field['widget']['weight'],
        );
      }
    }
  }

  if(!is_null($export_ids)) {
    // Re-order form based on content types we are exporting
    $entity_weight = -1000;
    $bundle_weight = -1000;
    foreach($export_ids as $entity_type => $bundles) {
      $form['export_fields'][$entity_type]['#weight'] = $entity_weight++;
      foreach($bundles as $bundle_name => $ids) {
        $form['export_fields'][$entity_type][$bundle_name]['#weight'] = $bundle_weight++;
        $form['export_fields'][$entity_type][$bundle_name]['#collapsed'] = FALSE;
      }
    }
  }
  return $form;
}

/**
 * Take an export field list and disable one side of any circular references.
 */
function mukurtu_export_filter_bidirectional_reference_fields($fields, $export_ids = NULL) {
  // Get all enabled, bidirectional CERs.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'cer')
    ->fieldCondition('cer_enabled', 'value', '1')
    ->fieldCondition('cer_bidirectional', 'value', '1')
    ->addMetaData('account', user_load(1));

  $result = $query->execute();

  if (isset($result['cer'])) {
    foreach($result['cer'] as $cer) {
      $entity = entity_load_single('cer', $cer->pid);
      if ($entity) {
        $left = explode(':', $entity->cer_left[LANGUAGE_NONE][0]['path']);
        $right = explode(':', $entity->cer_right[LANGUAGE_NONE][0]['path']);

        if (count($left) == 3 && count($right) == 3) {
          if (!isset($fields[$left[0]][$left[1]][$left[2]]) || !isset($fields[$right[0]][$right[1]][$right[2]])) {
            // No defaults set.
            if ($left[0] == 'taxonomy_term') {
              $fields[$left[0]][$left[1]][$left[2]] = FALSE;
              $fields[$right[0]][$right[1]][$right[2]] = TRUE;
            } else {
              // Select the left side, disable right.
              $fields[$left[0]][$left[1]][$left[2]] = TRUE;
              $fields[$right[0]][$right[1]][$right[2]] = FALSE;
            }
          } else {
            if ($fields[$left[0]][$left[1]][$left[2]] && $fields[$right[0]][$right[1]][$right[2]]) {
              // Both left and right are selected to export.
              if ($left[0] == 'taxonomy_term') {
                // Disable left.
                $fields[$left[0]][$left[1]][$left[2]] = FALSE;
              } else {
                // Disable right.
                $fields[$right[0]][$right[1]][$right[2]] = FALSE;
              }
            }
            // If we get here, left and right both are set, but only one (or neither) is enabled.
            // We don't need to do anything in that case.
          }
        }
      }
    }
  }

  return $fields;
}
