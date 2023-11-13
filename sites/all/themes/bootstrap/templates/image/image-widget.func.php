<?php

/**
 * @file
 * Stub file for bootstrap_image_widget().
 */

/**
 * Returns HTML for an image field widget.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: A render element representing the image field widget.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_image_widget()
 *
 * @ingroup theme_functions
 */
function bootstrap_image_widget(array $variables) {
  $element = $variables['element'];
  $output = '';
  $output .= '<div class="image-widget form-managed-file clearfix">';

  if (isset($element['preview'])) {
    $output .= '<div class="image-preview">';
    $output .= drupal_render($element['preview']);
    $output .= '</div>';
  }

  $output .= '<div class="image-widget-data">';
  if (!empty($element['fid']['#value'])) {
    $element['filename']['#markup'] = '<div class="form-group">' . $element['filename']['#markup'] . ' <span class="file-size badge">' . format_size($element['#file']->filesize) . '</span></div>';
  }

  $output .= drupal_render_children($element);
  $output .= '</div>';
  $output .= '</div>';

  return $output;
}
