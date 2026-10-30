<?php

/**
 * @file
 * Theme callbacks for feeds_ex.
 */

/**
 * Themes the parser configuration table.
 */
function theme_feeds_ex_configuration_table(array $variables) {
  $element = $variables['element'];

  $rows = array();

  // Render the context at the top. Context is optional.
  if (!empty($element['context'])) {
    $context_row = array();
    foreach (array_keys($element['#header']) as $column) {
      $context_row[] = drupal_render($element['context'][$column]);
    }
    $rows[] = $context_row;
  }

  // Render the sources.
  foreach (element_children($element['sources']) as $source_key) {
    $source = $element['sources'][$source_key];
    $row = array();
    foreach (array_keys($element['#header']) as $column) {
      $row[] = drupal_render($element['sources'][$source_key][$column]);
    }
    $rows[] = array('data' => $row, 'class' => array('draggable'));
  }

  // Render the add row.
  $add_row = array();
  foreach (array_keys($element['#header']) as $column) {
    $add_row[] = array(
      'data' => drupal_render($element['add'][$column]),
      'class' => array('feeds-ex-add-' . $column),
    );
  }

  $rows[] = array('data' => $add_row, 'class' => array('draggable'));

  $output = theme('table', array(
    'header' => $element['#header'],
    'rows' => $rows,
    'attributes' => array('id' => $element['sources']['#id']),
  ));
  $output .= drupal_render_children($element);

  return $output;
}
