<?php

/**
 * @file Documentation about hooks provided by services_views module.
 */

/**
 * Implements hook_services_views_execute_view_alter().
 *
 * Alter results of the view execution. For example we can add total number of
 * results as separate value in response.
 *
 * @param array $output
 *   Results of the view execution. These will be sent to services for rendering.
 * @param object $view
 *   Views object.
 */
function hook_services_views_execute_view_alter(&$output, $view) {
  if ($view->name == 'test') {
    $paged_output = array(
      'results' => $output,
      'total_rows' => $view->total_rows,
    );
    $output = $paged_output;
  }
}
