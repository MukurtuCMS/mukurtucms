<?php
/**
 * @file
 * Stub file for bootstrap_item_list().
 */

/**
 * Returns HTML for a list or nested list of items.
 *
 * - Uses an early D8 version of the theme function, which fixes bugs (and was
 *   refused for commit because it was "too late to change theme output)".
 * - Removes first/last, even/odd classes.
 * - Removes useless div.item-list wrapper, allows optional #wrapper_attributes.
 * - Removes hard-coded #title as <h3>, introduce support for #title as an array
 *   containing, text, tag and optional attributes.
 *
 * @param array $variables
 *   An associative array containing:
 *   - items: An array of items to be displayed in the list. If an item is a
 *     string, then it is used as is. If an item is an array, then the "data"
 *     element of the array is used as the contents of the list item. If an item
 *     is an array with a "children" element, those children are displayed in a
 *     nested list. All other elements are treated as attributes of the list
 *     item element.
 *   - title: The title of the list.
 *   - type: The type of list to return (e.g. "ul", "ol").
 *   - attributes: The attributes applied to the list element.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_item_list()
 *
 * @ingroup theme_functions
 */
function bootstrap_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $list_attributes = $variables['attributes'];

  // Drupal core only supports #title as a string. This implementation supports
  // heading level, and attributes as well.
  $heading = '';
  if (!empty($title)) {
    // If it's a string, normalize into an array.
    if (is_string($title)) {
      $title = array(
        'text' => $title,
        'html' => TRUE,
      );
    }
    // Set defaults.
    $title += array(
      'level' => 'h3',
      'attributes' => array(),
    );
    // Heading outputs only when it has text.
    if (!empty($title['text'])) {
      $heading .= '<' . $title['level'] . drupal_attributes($title['attributes']) . '>';
      $heading .= empty($title['html']) ? check_plain($title['text']) : $title['text'];
      $heading .= '</' . $title['level'] . '>';
    }
  }

  $output = '';
  if ($items) {
    $output .= '<' . $type . drupal_attributes($list_attributes) . '>';
    foreach ($items as $key => $item) {
      $attributes = array();

      if (is_array($item)) {
        $value = '';
        if (isset($item['data'])) {
          // Allow data to be renderable.
          if (is_array($item['data']) && (!empty($item['data']['#type']) || !empty($item['data']['#theme']))) {
            $value .= drupal_render($item['data']);
          }
          else {
            $value .= $item['data'];
          }
        }
        $attributes = array_diff_key($item, array('data' => 0, 'children' => 0));

        // Append nested child list, if any.
        if (isset($item['children'])) {
          // HTML attributes for the outer list are defined in the 'attributes'
          // theme variable, but not inherited by children. For nested lists,
          // all non-numeric keys in 'children' are used as list attributes.
          $child_list_attributes = array();
          foreach ($item['children'] as $child_key => $child_item) {
            if (is_string($child_key)) {
              $child_list_attributes[$child_key] = $child_item;
              unset($item['children'][$child_key]);
            }
          }
          $value .= theme('item_list', array(
            'items' => $item['children'],
            'type' => $type,
            'attributes' => $child_list_attributes,
          ));
        }
      }
      else {
        $value = $item;
      }

      $output .= '<li' . drupal_attributes($attributes) . '>' . $value . "</li>\n";
    }
    $output .= "</$type>";
  }

  // Output the list and title only if there are any list items.
  if (!empty($output)) {
    $output = $heading . $output;
  }

  return $output;
}
