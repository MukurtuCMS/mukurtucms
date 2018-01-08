<?php

/**
 *  Export GUI function.
 *
 *  @param $entities
 *    A node, an array of nodes, or an array of nids.
 *  @param $format
 *    The node export format.
 *  @param $delivery
 *    The code delivery format, if NULL will use settings.
 *  @return
 *    The node export form or nothing if calling function to serve file.
 */

 function mukurtu_export_gui($entities = NULL, $format = NULL, $delivery = NULL, $field_list = NULL) {
  // Determine which content we are exporting
  if(is_object($entities)) {
    // Single item, from node/entity page
    $entity_type = _mukurtu_export_entity_type($entities);
    $entity_id = _mukurtu_export_entity_id($entity_type);
    $export_ids = array($entity_type =>
      array($entities->type =>
        array(
          $entities->{$entity_id} => $entities
        )
      )
    );
    drupal_set_title(t('Exporting @title', array('@title' => $entities->title)));
  }

  // Get the current format, either previous or default
  if(is_null($format)) {
    if(isset($_SESSION['mukurtu_export']['format'])) {
      $format = $_SESSION['mukurtu_export']['format'];
    } else {
      $format = 'csv';
    }
  }

  if(is_null($field_list)) {
    if(isset($_SESSION['mukurtu_export']['field_list'])) {
      $field_list = $_SESSION['mukurtu_export']['field_list'];
    }
  }

  $code_string = NULL;
  return drupal_get_form('mukurtu_export_form', $export_ids, $code_string, $format, $field_list);
}

function mukurtu_export_form($form, &$form_state, $export_ids, $code_string, $format, $field_list = NULL) {
  include_once "formats/csv.inc";

  if(is_null($field_list)) {
    $form = mukurtu_export_fields_selection_form($form, $form_state, $export_ids);
    $form['download_file'] = array(
      '#type' => 'submit',
      '#value' => t('Download file'),
    );
    $form_state['rebuild'] = TRUE;
  } else {
    //$code_string = mukurtu_export_csv_export(array(55 => node_load(55)));
    $code_string = mukurtu_export_csv_export($export_ids, $format, $field_list);
kpr($code_string);
    $form['export'] = array(
      '#type' => 'textarea',
      '#title' => t('Mukurtu export code'),
      '#default_value' => print_r($code_string, TRUE),
      '#rows' => 30,
      '#description' => t('Copy this code and then on the site you want to import to, go to the <em>Node export: import</em> link under <em>Add content</em>, and paste it in there.'),
      '#attributes' => array(
        'wrap' => 'off',
      ),
      '#wysiwyg' => FALSE,
    );
  }

  unset($_SESSION['mukurtu_export']['field_list']);
  return $form;
}

function mukurtu_export_form_submit($form, &$form_state) {
  $export_ids = NULL;
  $code_string = NULL;
  $field_list = isset($form_state['values']['export_fields']) ? $form_state['values']['export_fields'] : 1;
  $_SESSION['mukurtu_export']['field_list'] = $field_list;

  //return drupal_get_form('mukurtu_export_form', $export_ids, $code_string, 'csv', $field_list);
}

function mukurtu_export_fields_selection_form($form, &$form_state, $export_ids = NULL) {
  if(!is_null($export_ids)) {
    $form['export_fields'] = array(
      '#type' => 'fieldset',
      '#title' => t('Select Fields for Export'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
    );

    foreach($export_ids as $entity_type => $bundles) {
      $entity_info = entity_get_info($entity_type);
      $id = _mukurtu_export_entity_id($entity_type);
      foreach($bundles as $bundle_name => $ids) {
        $form['export_fields'][$entity_type][$bundle_name] = array(
          '#type' => 'fieldset',
          '#title' => $entity_info['bundles'][$bundle_name]['label'],
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
        );

        $fields_info = field_info_instances($entity_type, $bundle_name);

        // Default fields
        // ID
        $id_label = t('ID');

        $form['export_fields'][$entity_type][$bundle_name][$id] = array(
          '#type' => 'checkbox',
          '#title' => $id_label,
          '#default_value' => TRUE,
          '#weight' => -2
        );

        // Title
        $form['export_fields'][$entity_type][$bundle_name]['title'] = array(
          '#type' => 'checkbox',
          '#title' => t('Title'),
          '#default_value' => TRUE,
          '#weight' => -1
        );

        foreach($fields_info as $field_name => $field) {
          $form['export_fields'][$entity_type][$bundle_name][$field_name] = array(
            '#type' => 'checkbox',
            '#title' => $field['label'],
            '#default_value' => TRUE,
            '#weight' => $field['widget']['weight']
          );
        }
      }
    }
  }
  return $form;
}