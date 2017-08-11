<?php
/**
 * @file
 * Stub file for "breadcrumb" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "breadcrumb" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @see bootstrap_breadcrumb()
 * @see theme_breadcrumb()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_breadcrumb(&$variables) {
  // Do not modify breadcrumbs if the Path Breadcrumbs module should be used.
  if (_bootstrap_use_path_breadcrumbs()) {
    return;
  }

  $breadcrumb = &$variables['breadcrumb'];

  // Optionally get rid of the homepage link.
  $show_breadcrumb_home = bootstrap_setting('breadcrumb_home');
  if (!$show_breadcrumb_home) {
    array_shift($breadcrumb);
  }

  if (bootstrap_setting('breadcrumb_title') && !empty($breadcrumb)) {
    $item = menu_get_item();

    $page_title = !empty($item['tab_parent']) ? check_plain($item['title']) : drupal_get_title();
    if (!empty($page_title)) {
      $breadcrumb[] = array(
        // If we are on a non-default tab, use the tab's title.
        'data' => $page_title,
        'class' => array('active'),
      );
    }
  }
}
