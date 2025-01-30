<?php

/**
 * @file
 * owlcarousel_views.theme.inc
 */

/**
 * Template process Owl Carousel Views variables.
 */
function template_process_owlcarousel_views(&$variables) {
  if (!empty($variables['view'])) {
    $settings = $variables['options'];
    $view = $variables['view'];

    $items = array();
    $row_plugin = $view->style_plugin->row_plugin;

    foreach ($variables['rows'] as $id => $row) {
      $view->row_index = $id;

      if ($item['row'] = $row_plugin->render($row)) {
        $items[] = $item;
      }
    }

    // Attribute id.
    $settings['attributes']['id'] = $variables['options']['id'];

    // Disable caching for views, view handles caching itself, concerning all required cache keys.
    // Otherwise caching returns wrong results for views with arguments / filters.
    // https://www.drupal.org/project/owlcarousel/issues/2985532
    $settings['cache_disable'] = TRUE;

    // Row items & instance settings.
    $variables['settings'] = $settings;
    $variables['items'] = $items;
  }
}

/**
 * Theme declaration for Owl Carousel View output.
 */
function theme_owlcarousel_views($variables) {
  $output = array(
    '#theme' => 'owlcarousel',
    '#items' => $variables['items'],
    '#settings' => $variables['settings'],
  );

  return drupal_render($output);
}
