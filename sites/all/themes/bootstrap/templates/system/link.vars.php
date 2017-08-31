<?php

/**
 * @file
 * Stub file for "link" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "link" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @see bootstrap_process_link()
 * @see theme_link()
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_link(&$variables) {
  // Fill in missing defaults not provided by drupal_common_theme().
  $variables['options'] += array(
    'attributes' => array(),
    'html' => FALSE,
  );
  
  // Core is so backwards on this theme hook. It does not provide a proper
  // preprocess function or attributes array. Merge any passed attributes
  // (which take precedence over passed option attributes) into the options
  // attributes array.
  if (!empty($variables['attributes'])) {
    $variables['options']['attributes'] = drupal_array_merge_deep($variables['options']['attributes'], $variables['attributes']);
  }

  // Standardize "attributes" by referencing the attributes in options.
  $variables['attributes'] = &$variables['options']['attributes'];

  // Add the icon position class.
  if (!empty($variables['icon'])) {
    _bootstrap_add_class('icon-' . drupal_html_class($variables['icon_position'] === 'icon_only' ? 'only' : $variables['icon_position']), $variables);
  }

  // Remove any "href" attribute since it's manually added in theme_link().
  unset($variables['attributes']['href']);
}

/**
 * Processes variables for the "link" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @see bootstrap_preprocess_link()
 * @see theme_link()
 *
 * @ingroup theme_process
 */
function bootstrap_process_link(&$variables) {
  // Render #icon and trim it (so it doesn't add underlines in whitespace).
  if (!empty($variables['icon']) && ($icon = trim(render($variables['icon'])))) {
    // Sanitize text, if necessary.
    $variables['text'] = !empty($variables['options']['html']) ? $variables['text'] : check_plain($variables['text']);

    // Override the HTML option so icon is printed.
    $variables['options']['html'] = TRUE;

    // Hide the link text, if necessary.
    if ($variables['icon_position'] === 'icon_only') {
      $variables['text'] = '<span class="sr-only">' . $variables['text'] . '</span>';
    }
    if ($variables['icon_position'] === 'after') {
      $variables['text'] .= $icon;
    }
    else {
      $variables['text'] = $icon . $variables['text'];
    }
  }
}
