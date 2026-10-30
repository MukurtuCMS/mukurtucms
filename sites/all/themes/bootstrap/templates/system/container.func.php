<?php

/**
 * @file
 * Stub file for bootstrap_container().
 */

/**
 * Returns HTML to wrap child elements in a container.
 *
 * Used for grouped form items. Can also be used as a #theme_wrapper for any
 * renderable element, to surround it with a <div> and add attributes such as
 * classes or an HTML id.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #attributes, #children.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_container()
 *
 * @ingroup theme_functions
 */
function bootstrap_container(array $variables) {
  $element = $variables['element'];

  // Ensure #attributes is set.
  $element += array('#attributes' => array());

  // Special handling for form elements.
  if (isset($element['#array_parents'])) {
    // Assign an html ID.
    if (!isset($element['#attributes']['id'])) {
      $element['#attributes']['id'] = $element['#id'];
    }

    // Core's "form-wrapper" class is required for states.js to function.
    $element['#attributes']['class'][] = 'form-wrapper';

    // Add Bootstrap "form-group" class.
    if (!isset($element['#form_group']) || !!$element['#form_group']) {
      $element['#attributes']['class'][] = 'form-group';
    }
  }

  return '<div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}
