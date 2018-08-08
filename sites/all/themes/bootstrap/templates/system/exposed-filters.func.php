<?php

/**
 * @file
 * Stub file for bootstrap_exposed_filters().
 */

/**
 * Returns HTML for an exposed filter form.
 *
 * @param array $variables
 *   An associative array containing:
 *   - form: An associative array containing the structure of the form.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_exposed_filters()
 *
 * @ingroup theme_functions
 */
function bootstrap_exposed_filters(array $variables) {
  $form = $variables['form'];
  $output = '';

  foreach (element_children($form['status']['filters']) as $key) {
    $form['status']['filters'][$key]['#field_prefix'] = '<div class="col-sm-10">';
    $form['status']['filters'][$key]['#field_suffix'] = '</div>';
  }
  $form['status']['actions']['#attributes']['class'][] = 'col-sm-offset-2';
  $form['status']['actions']['#attributes']['class'][] = 'col-sm-10';

  if (isset($form['current'])) {
    $items = array();
    foreach (element_children($form['current']) as $key) {
      $items[] = drupal_render($form['current'][$key]);
    }
    $build = array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#attributes' => array('class' => array('clearfix', 'current-filters')),
    );
    $output .= drupal_render($build);
  }
  $output .= drupal_render_children($form);
  return '<div class="form-horizontal">' . $output . '</div>';
}
