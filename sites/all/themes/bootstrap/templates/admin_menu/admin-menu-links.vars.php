<?php
/**
 * @file
 * Stub file for "admin_menu_links" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "admin_menu_links" theme hook.
 *
 * @param array $variables
 *   - elements: A renderable array of links using the following keys:
 *     - #attributes: Optional array of attributes for the list item, processed
 *       via drupal_attributes().
 *     - #title: Title of the link, passed to l().
 *     - #href: Optional path of the link, passed to l(). When omitted, the
 *       element's '#title' is rendered without link.
 *     - #description: Optional alternative text for the link, passed to l().
 *     - #options: Optional alternative text for the link, passed to l().
 *     The array key of each child element itself is passed as path for l().
 *
 * @see theme_admin_menu_links()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_admin_menu_links(&$variables) {
  $elements = &$variables['elements'];
  foreach (element_children($elements) as $child) {
    $elements[$child]['#bootstrap_ignore_pre_render'] = TRUE;
    $elements[$child]['#bootstrap_ignore_process'] = TRUE;
  }
}
