<?php

/**
 * @file
 * Stub file for bootstrap_file_managed_file().
 */

/**
 * Returns HTML for a managed file element.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: A render element representing the file.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_file_managed_file()
 *
 * @ingroup theme_functions
 */
function bootstrap_file_managed_file(array $variables) {
  $output = '';
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'form-managed-file';
  $attributes['class'][] = 'input-group';

  $element['upload_button']['#attributes']['class'][] = 'btn-primary';
  $element['upload_button']['#prefix'] = '<span class="input-group-btn">';
  $element['upload_button']['#suffix'] = '</span>';
  $element['remove_button']['#prefix'] = '<span class="input-group-btn">';
  $element['remove_button']['#suffix'] = '</span>';
  $element['remove_button']['#attributes']['class'][] = 'btn-danger';

  if (!empty($element['filename'])) {
    $element['filename']['#prefix'] = '<div class="form-control">';
    $element['filename']['#suffix'] = '</div>';
  }

  // This wrapper is required to apply JS behaviors and CSS styling.
  $output .= '<div' . drupal_attributes($attributes) . '>';

  // Immediately render hidden elements before the rest of the output.
  // The uploadprogress extension requires that the hidden identifier input
  // element appears before the file input element. They must also be siblings
  // inside the same parent element.
  // @see https://www.drupal.org/node/2155419
  foreach (element_children($element) as $child) {
    if (isset($element[$child]['#type']) && $element[$child]['#type'] === 'hidden') {
      $output .= drupal_render($element[$child]);
    }
  }

  // Render the rest of the element.
  $output .= drupal_render_children($element);
  $output .= '</div>';
  return $output;
}
