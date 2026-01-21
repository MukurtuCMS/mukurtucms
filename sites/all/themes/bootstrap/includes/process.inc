<?php

/**
 * @file
 * process.inc
 *
 * Contains various implementations for #process callbacks on elements.
 */

/**
 * Implements hook_form_process().
 */
function bootstrap_form_process($element, &$form_state, &$form) {
  if (!empty($element['#bootstrap_ignore_process'])) {
    return $element;
  }

  if (!empty($element['#attributes']['class']) && is_array($element['#attributes']['class'])) {
    $key = array_search('container-inline', $element['#attributes']['class']);
    if ($key !== FALSE) {
      $element['#attributes']['class'][$key] = 'form-inline';
    }

    if (in_array('form-wrapper', $element['#attributes']['class'])) {
      $element['#attributes']['class'][] = 'form-group';
    }
  }

  // Automatically inject the nearest button found after this element if
  // #input_group_button exists.
  if (!empty($element['#input_group_button'])) {
    // Obtain the parent array to limit search.
    $array_parents = array();
    if (!empty($element['#array_parents'])) {
      $array_parents += $element['#array_parents'];
      // Remove the current element from the array.
      array_pop($array_parents);
    }

    // If element is nested, return the referenced parent from the form.
    if (!empty($array_parents)) {
      $parent = &drupal_array_get_nested_value($form, $array_parents);
    }
    // Otherwise return the complete form.
    else {
      $parent = &$form;
    }

    // Ignore buttons before we find the element in the form.
    $found_current_element = FALSE;
    foreach (element_children($parent, TRUE) as $child) {
      if ($parent[$child] === $element) {
        $found_current_element = TRUE;
        continue;
      }

      if ($found_current_element && _bootstrap_is_button($parent[$child]) && (!isset($parent[$child]['#access']) || !!$parent[$child]['#access'])) {
        $element['#field_suffix'] = drupal_render($parent[$child]);
        break;
      }
    }
  }

  return $element;
}

/**
 * Implements hook_form_process_HOOK().
 */
function bootstrap_form_process_actions($element, &$form_state, &$form) {
  $element['#attributes']['class'][] = 'form-actions';

  if (!empty($element['#bootstrap_ignore_process'])) {
    return $element;
  }

  foreach (element_children($element) as $child) {
    _bootstrap_iconize_button($element[$child]);
  }
  return $element;
}

/**
 * Implements hook_form_process_HOOK().
 */
function bootstrap_form_process_text_format($element, &$form_state, &$form) {
  if (!empty($element['#bootstrap_ignore_process'])) {
    return $element;
  }

  // Provide smart description on the value text area.
  bootstrap_element_smart_description($element, $element['value']);

  // Allow the elements inside to be displayed inline.
  $element['format']['#attributes']['class'][] = 'form-inline';

  // Remove the cluttering guidelines; they can be viewed on a separate page.
  $element['format']['guidelines']['#access'] = FALSE;

  // Hide the select label.
  $element['format']['format']['#title_display'] = 'none';

  // Make the select element smaller using a Bootstrap class.
  $element['format']['format']['#attributes']['class'][] = 'input-sm';

  // Support the Bootstrap Select plugin if it is used.
  $element['format']['format']['#attributes']['data-style'] = 'btn-sm btn-default';

  return $element;
}
