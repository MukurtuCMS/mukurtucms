<?php
/**
 * @file
 * Stub file for "webform_element" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "webform_element" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @see theme_webform_element()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_webform_element(&$variables) {
  $element = $variables['element'];
  $wrapper_attributes = array();
  if (isset($element['#wrapper_attributes'])) {
    $wrapper_attributes = $element['#wrapper_attributes'];
  }

  // See http://getbootstrap.com/css/#forms-controls.
  if (isset($element['#type'])) {
    if ($element['#type'] === 'radio') {
      $wrapper_attributes['class'][] = 'radio';
    }
    elseif ($element['#type'] === 'checkbox') {
      $wrapper_attributes['class'][] = 'checkbox';
    }
    elseif ($element['#type'] !== 'hidden') {
      $wrapper_attributes['class'][] = 'form-group';
    }
  }

  $variables['element']['#wrapper_attributes'] = $wrapper_attributes;
}
