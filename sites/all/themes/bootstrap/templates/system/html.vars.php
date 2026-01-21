<?php

/**
 * @file
 * Stub file for "html" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "html" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see html.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_html(array &$variables) {
  // Backport from Drupal 8 RDFa/HTML5 implementation.
  // @see https://www.drupal.org/node/1077566
  // @see https://www.drupal.org/node/1164926

  // Create a dedicated attributes array for the HTML element.
  // By default, core does not provide a way to target the HTML element.
  // The only arrays currently available technically belong to the BODY element.
  $variables['html_attributes_array'] = array(
    'lang' => $variables['language']->language,
    'dir' => $variables['language']->dir,
  );

  // Override existing RDF namespaces to use RDFa 1.1 namespace prefix bindings.
  if (function_exists('rdf_get_namespaces')) {
    $rdf = array('prefix' => array());
    foreach (rdf_get_namespaces() as $prefix => $uri) {
      $rdf['prefix'][] = $prefix . ': ' . $uri;
    }
    if (!$rdf['prefix']) {
      $rdf = array();
    }
    $variables['rdf_namespaces'] = drupal_attributes($rdf);
  }

  // Create a dedicated attributes array for the BODY element.
  if (!isset($variables['body_attributes_array'])) {
    $variables['body_attributes_array'] = array();
  }

  // Ensure there is at least a class array.
  if (!isset($variables['body_attributes_array']['class'])) {
    $variables['body_attributes_array']['class'] = array();
  }

  // Navbar position.
  switch (bootstrap_setting('navbar_position')) {
    case 'fixed-top':
      $variables['body_attributes_array']['class'][] = 'navbar-is-fixed-top';
      break;

    case 'fixed-bottom':
      $variables['body_attributes_array']['class'][] = 'navbar-is-fixed-bottom';
      break;

    case 'static-top':
      $variables['body_attributes_array']['class'][] = 'navbar-is-static-top';
      break;
  }
}

/**
 * Processes variables for the "html" theme hook.
 *
 * See template for list of available variables.
 *
 * **WARNING**: It is not recommended that this function be copied to a
 * sub-theme. There is rarely any need to process the same variables twice.
 *
 * If you need to add something to the "html_attributes_array" or
 * "body_attributes_array" arrays, you should do so in a hook_preprocess_html()
 * function since process functions will always run after all preprocess
 * functions have been executed.
 *
 * If there is a need to implement a hook_process_html() function in your
 * sub-theme (to process your own custom variables), ensure that it doesn't
 * add this base theme's logic and risk introducing breakage and performance
 * issues.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see html.tpl.php
 *
 * @ingroup theme_process
 */
function bootstrap_process_html(array &$variables) {
  // Merge in (not reference!) core's ambiguous and separate "attribute" and
  // "class" arrays. These arrays are meant for the BODY element, but it must
  // be done at the process level in case sub-themes wish to add classes to
  // core's non-standard arrays (which are for the BODY element only).
  // @see https://www.drupal.org/node/2868426
  $variables['body_attributes_array'] = drupal_array_merge_deep($variables['body_attributes_array'], $variables['attributes_array']);

  // Use this project's class helper (to eliminate any duplicate classes).
  _bootstrap_add_class($variables['classes_array'], $variables, 'body_attributes_array');

  // Finally, convert the arrays into proper attribute strings.
  $variables['html_attributes'] = drupal_attributes($variables['html_attributes_array']);
  $variables['body_attributes'] = drupal_attributes($variables['body_attributes_array']);
}
