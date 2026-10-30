<?php

/**
 * @file
 * Stub file for bootstrap_filter_tips().
 */

/**
 * Returns HTML for a set of filter tips.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tips: An array containing descriptions and a CSS ID in the form of
 *     'module-name/filter-id' (only used when $long is TRUE) for each
 *     filter in one or more text formats. Example:.
 *
 * @code
 *       array(
 *         'Full HTML' => array(
 *           0 => array(
 *             'tip' => 'Web page addresses and e-mail addresses turn into links automatically.',
 *             'id' => 'filter/2',
 *           ),
 *         ),
 *       );
 * @endcode
 *   - long: (optional) Whether the passed-in filter tips contain extended
 *     explanations, i.e. intended to be output on the path 'filter/tips'
 *     (TRUE), or are in a short format, i.e. suitable to be displayed below a
 *     form element. Defaults to FALSE.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_filter_tips()
 * @see _filter_tips()
 *
 * @ingroup theme_functions
 */
function bootstrap_filter_tips(array $variables) {
  $format_id = arg(2);
  $current_path = current_path();
  $tips = _filter_tips(-1, TRUE);

  // Create a place holder for the tabs.
  $build['tabs'] = array(
    '#theme' => 'item_list',
    '#items' => array(),
    '#attributes' => array(
      'class' => array(
        'nav',
        'nav-tabs',
      ),
      'role' => 'tablist',
    ),
  );

  // Create a placeholder for the panes.
  $build['panes'] = array(
    '#theme_wrappers' => array('container'),
    '#attributes' => array(
      'class' => array(
        'tab-content',
      ),
    ),
  );

  foreach ($tips as $name => $list) {
    $machine_name = str_replace('-', '_', drupal_html_class($name));
    $tab = array(
      'data' => array(
        '#type' => 'link',
        '#title' => check_plain($name),
        '#href' => $current_path,
        '#attributes' => array(
          'role' => 'tab',
          'data-toggle' => 'tab',
        ),
        '#options' => array(
          'fragment' => $machine_name,
        ),
      ),
    );
    if (!$format_id || $format_id === $machine_name) {
      $tab['class'][] = 'active';
      $format_id = $machine_name;
    }
    $build['tabs']['#items'][] = $tab;

    // Extract the actual tip.
    $tiplist = array();
    foreach ($list as $tip) {
      $tiplist[] = $tip['tip'];
    }

    // Construct the pane.
    $pane = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array(
        'class' => array(
          'tab-pane',
          'fade',
        ),
        'id' => $machine_name,
      ),
      'list' => array(
        '#theme' => 'item_list',
        '#items' => $tiplist,
      ),
    );
    if ($format_id === $machine_name) {
      $pane['#attributes']['class'][] = 'active';
      $pane['#attributes']['class'][] = 'in';
      $format_id = $machine_name;
    }
    $build['panes'][] = $pane;
  }

  return drupal_render($build);
}
