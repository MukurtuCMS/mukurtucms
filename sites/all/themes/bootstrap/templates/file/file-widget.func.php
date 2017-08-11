<?php
/**
 * @file
 * Stub file for bootstrap_file_widget().
 */

/**
 * Returns HTML for an individual file upload widget.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: A render element representing the widget.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_file_widget()
 *
 * @ingroup theme_functions
 */
function bootstrap_file_widget($variables) {
  $output = '';
  $element = $variables['element'];
  $element['upload_button']['#attributes']['class'][] = 'btn-primary';
  $element['upload_button']['#prefix'] = '<span class="input-group-btn">';
  $element['upload_button']['#suffix'] = '</span>';

  // The "form-managed-file" class is required for proper Ajax functionality.
  if (!empty($element['filename'])) {
    $output .= '<div class="file-widget form-managed-file clearfix">';
    // Add the file size after the file name.
    $element['filename']['#markup'] .= ' <span class="file-size badge">' . format_size($element['#file']->filesize) . '</span>';
  }
  else {
    $output .= '<div class="file-widget form-managed-file clearfix input-group">';
  }

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
