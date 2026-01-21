<?php

function ma_import_export_multiple_language_bug_batch_run($options, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query('SELECT COUNT(DISTINCT nid) FROM {node}')->fetchField();
  }

  $limit = 10;

  $result = db_query_range("SELECT nid FROM node ORDER BY nid ASC",
    $context['sandbox']['progress'],
    $limit
  )->fetchAll();

  foreach ($result as $row) {
    $node = node_load($row->nid, NULL, TRUE);
    $node_report = ma_import_export_check_node_for_multiple_language_bug($node);

    // Store fields that have multiple languages.
    if ($node_report) {
      $context['results'][$row->nid] = $node_report[0];
    }

    $context['sandbox']['progress']++;
    $context['sandbox']['current_node'] = $node->nid;
    $context['message'] = t('Searching content for fields with multiple languages', array('Searching item: ' => $node->title));
  }

  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function ma_import_export_multiple_language_bug_batch_run_finished($success, $results, $operations) {
  if ($success) {
    $message = t('Found @count items that have fields with multiple languages:<br>', array('@count' => count($results)));

    $rows = [];
    $max_size = 0;

    foreach ($results as $nid => $result) {
      $size = count($result);
      if ($size > $max_size) {
        $max_size = $size;
      }
    }
    // Add one for the item URL.
    $max_size += 1;

    $headers = ['Item', 'Fields'];
    if (count($headers) != $max_size) {
      while (count($headers) < $max_size) {
        $headers[] = [];
      }
    }

    foreach ($results as $nid => $result) {
      $row = [l("node/$nid", "node/$nid")];

      foreach ($result as $field_name => $field_values) {
        $langs = array_keys($field_values['value']);
        $lang_string = implode(', ', $langs);
        $class = isset($field_values['classes'][0]) ? $field_values['classes'][0] : '';
        $color = $class == 'different' ? 'red' : 'green';
        $row[] = "<span style=\"color:$color\">$field_name ($lang_string)</span>";
      }

      // Pad the row with blanks.
      if (count($row) != $max_size) {
        while (count($row) < $max_size) {
          $row[] = [];
        }
      }
      $rows[] = $row;
    }

    $table = [
      '#header' => $headers,
      '#theme' => 'table',
      '#rows' => $rows,
    ];

    $_SESSION['ma_importexport_multiple_language_field_form_table'] = $table;
  }
}
