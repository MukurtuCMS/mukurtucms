<?php
/**
 * @file
 * Stub file for bootstrap_bootstrap_search_form_wrapper().
 */

/**
 * Returns HTML for the Bootstrap search form wrapper.
 *
 * @ingroup theme_functions
 */
function bootstrap_bootstrap_search_form_wrapper($variables) {
  $output = '<div class="input-group">';
  $output .= $variables['element']['#children'];
  $output .= '<span class="input-group-btn">';
  $output .= '<button type="submit" class="btn btn-primary">' . _bootstrap_icon('search', t('Search')) . '</button>';
  $output .= '</span>';
  $output .= '</div>';
  return $output;
}
