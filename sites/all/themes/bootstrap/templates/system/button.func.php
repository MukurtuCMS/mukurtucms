<?php
/**
 * @file
 * Stub file for bootstrap_button().
 */

/**
 * Returns HTML for a button form element.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #attributes, #button_type, #name, #value.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_button()
 *
 * @ingroup theme_functions
 */
function bootstrap_button($variables) {
  $element = $variables['element'];
  $text = $element['#value'];

  // Allow button text to be appear hidden.
  // @see https://www.drupal.org/node/2327437
  if (!empty($element['#hide_text']) || $element['#icon_position'] === 'icon_only') {
    $text = '<span class="sr-only">' . $text . '</span>';
  }

  // Add icons before or after the value.
  // @see https://www.drupal.org/node/2219965
  if (!empty($element['#icon']) && ($icon = render($element['#icon']))) {
    // Add icon position class.
    _bootstrap_add_class('icon-' . drupal_html_class($element['#icon_position'] === 'icon_only' ? 'only' : $element['#icon_position']), $element);

    if ($element['#icon_position'] === 'after') {
      $text .= ' ' . $icon;
    }
    else {
      $text = $icon . ' ' . $text;
    }
  }

  // This line break adds inherent margin between multiple buttons.
  return '<button' . drupal_attributes($element['#attributes']) . '>' . filter_xss_admin($text) . "</button>\n";
}
