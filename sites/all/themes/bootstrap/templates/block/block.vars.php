<?php

/**
 * @file
 * Stub file for "block" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "block" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see block.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_block(array &$variables) {
  // Use a bare template for the page's main content.
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'][] = 'block__no_wrapper';
  }
  $variables['title_attributes_array']['class'][] = 'block-title';
}

/**
 * Processes variables for the "block" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see block.tpl.php
 *
 * @ingroup theme_process
 */
function bootstrap_process_block(array &$variables) {
  // Drupal 7 should use a $title variable instead of $block->subject.
  // Don't override an existing "title" variable, some modules may already it.
  if (!isset($variables['title'])) {
    $variables['title'] = $variables['block']->subject;
  }
  $variables['title'] = filter_xss_admin($variables['title']);
}
