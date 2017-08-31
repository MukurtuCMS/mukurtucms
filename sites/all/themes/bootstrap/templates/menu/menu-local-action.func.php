<?php
/**
 * @file
 * Stub file for bootstrap_menu_local_action().
 */

/**
 * Returns HTML for a single local action link.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: A render element containing:
 *     - #link: A menu link array with 'title', 'href', and 'localized_options'
 *       keys.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_menu_local_action()
 *
 * @ingroup theme_functions
 */
function bootstrap_menu_local_action($variables) {
  $link = $variables['element']['#link'];

  $options = isset($link['localized_options']) ? $link['localized_options'] : array();

  // Filter the title if the "html" is set, otherwise l() will automatically
  // sanitize using check_plain(), so no need to call that here.
  $title = empty($options['html']) ? filter_xss_admin($link['title']) : $link['title'];

  $icon = _bootstrap_iconize_text($title);
  $href = !empty($link['href']) ? $link['href'] : FALSE;

  // Format the action link.
  if ($href) {
    // Turn link into a mini-button and colorize based on title.
    if ($class = _bootstrap_colorize_text($title)) {
      if (!isset($options['attributes']['class'])) {
        $options['attributes']['class'] = array();
      }
      $string = is_string($options['attributes']['class']);
      if ($string) {
        $options['attributes']['class'] = explode(' ', $options['attributes']['class']);
      }
      $options['attributes']['class'][] = 'btn';
      $options['attributes']['class'][] = 'btn-xs';
      $options['attributes']['class'][] = 'btn-' . $class;
      if ($string) {
        $options['attributes']['class'] = implode(' ', $options['attributes']['class']);
      }
    }
    // Force HTML so we can render any icon that may have been added.
    $options['html'] = !empty($options['html']) || !empty($icon) ? TRUE : FALSE;
  }

  return $href ? l($icon . $title, $href, $options) : $icon . $title;
}
