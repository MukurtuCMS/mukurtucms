<?php

/**
 * @file
 * Stub file for bootstrap_tablesort_indicator().
 */

/**
 * Returns HTML for a tablesort indicator.
 *
 * @param array $variables
 *   An associative array containing:
 *   - style: Set to either 'asc' or 'desc', this determines which icon to
 *     show.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_tablesort_indicator()
 *
 * @ingroup theme_functions
 */
function bootstrap_tablesort_indicator(array $variables) {
  if ($variables['style'] === 'asc') {
    return _bootstrap_icon('chevron-down', t('(asc)'), array(
      'class' => array('icon-after'),
      'data-toggle' => 'tooltip',
      'data-placement' => 'bottom',
      'title' => t('sort ascending'),
    ));
  }
  else {
    return _bootstrap_icon('chevron-up', t('(desc)'), array(
      'class' => array('icon-after'),
      'data-toggle' => 'tooltip',
      'data-placement' => 'bottom',
      'title' => t('sort descending'),
    ));
  }
}
