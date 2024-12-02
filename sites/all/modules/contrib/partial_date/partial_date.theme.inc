<?php

/**
 * @file
 * The theme callbacks for date formatters and element.
 */

/**
 * Workaround for theming the range elements inline.
 */
function theme_partial_date_inline_form_element($variables) {
  $element = &$variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'][] = 'form-item';
  $attributes['class'][] = 'clearfix';
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  if ($css = variable_get('partial_date_component_field_inline_range_styles', _partial_date_inline_float_css())) {
    $attributes['style'] = $css;
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

function theme_partial_date_range_inline_element($variables) {
  $element = &$variables['element'];
  $output = '<div class="clearfix partial-date-inline-range">';
  if (isset($element['from']) && isset($element['to'])) {
    $output .= '<div class="clearfix">';
    $output .= drupal_render($element['from']);
    $output .= drupal_render($element['_separator']);
    $output .= drupal_render($element['to']);
    $output .= '</div>';
    if (!empty($element['#component_help'])) {
      $output .= '<div class="description">' . $element['#component_help'] . '</div>';
    }


  }
  $output .= drupal_render_children($element);
  $output .= '</div>';
  return $output;
}
