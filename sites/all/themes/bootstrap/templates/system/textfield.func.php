<?php
/**
 * @file
 * Stub file for bootstrap_textfield().
 */

/**
 * Returns HTML for a textfield form element.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #value, #description, #size, #maxlength,
 *     #required, #attributes, #autocomplete_path.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_textfield()
 *
 * @ingroup theme_functions
 */
function bootstrap_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array(
    'id',
    'name',
    'value',
    'size',
    'maxlength',
  ));
  _form_set_class($element, array('form-text'));

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  if ($element['#autocomplete_path'] && !empty($element['#autocomplete_input'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    // Append a hidden autocomplete element.
    $autocomplete = array(
      '#type' => 'hidden',
      '#value' => $element['#autocomplete_input']['#url_value'],
      '#attributes' => array(
        'class' => array('autocomplete'),
        'disabled' => 'disabled',
        'id' => $element['#autocomplete_input']['#id'],
      ),
    );
    $output .= drupal_render($autocomplete);

    // Append icon for autocomplete "throbber" or use core's default throbber
    // whose background image must be set here because sites may not be
    // at the root of the domain (ie: /) and this value cannot be set via CSS.
    if (!isset($element['#autocomplete_icon'])) {
      $element['#autocomplete_icon'] = _bootstrap_icon('refresh', '<span class="autocomplete-throbber" style="background-image:url(' . file_create_url('misc/throbber.gif') . ')"></span>');
    }

    // Only add an icon if there is one.
    if ($element['#autocomplete_icon']) {
      $output .= '<span class="input-group-addon">' . $element['#autocomplete_icon'] . '</span>';

      // Wrap entire element in a input group if not already in one.
      if (!isset($element['#input_group']) && !isset($element['#input_group_button'])) {
        $input_group_attributes = isset($element['#input_group_attributes']) ? $element['#input_group_attributes'] : array();
        if (!isset($input_group_attributes['class'])) {
          $input_group_attributes['class'] = array();
        }
        if (!in_array('input-group', $input_group_attributes['class'])) {
          $input_group_attributes['class'][] = 'input-group';
        }
        $output = '<div' . drupal_attributes($input_group_attributes) . '>' . $output . '</div>';
      }
    }
  }

  return $output;
}
