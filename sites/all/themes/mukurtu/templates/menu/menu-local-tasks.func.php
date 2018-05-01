<?php

/**
 * @file
 * Stub file for bootstrap_menu_local_tasks().
 */

/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @param array $variables
 *   An associative array containing:
 *     - primary: (optional) An array of local tasks (tabs).
 *     - secondary: (optional) An array of local tasks (tabs).
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_menu_local_tasks()
 * @see menu_local_tasks()
 *
 * @ingroup theme_functions
 */
function mukurtu_menu_local_tasks(array &$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
      if($variables['primary'][0]['#link']['path'] != 'user/register') {
          $variables['primary']['#prefix'] = '<div id="mukurtu-local-tasks-dropdown" class="btn-group"><button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">' . t('Page Menu ') . '<span class="caret"></span></button>';

          $variables['primary']['#prefix'] .= '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
          $variables['primary']['#prefix'] .= '<ul class="dropdown-menu tabs--primary nav nav-tabs">';
          $variables['primary']['#suffix'] = '</ul></div>';
      } else {
          $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
          $variables['primary']['#prefix'] .= '<ul class="tabs--primary nav nav-tabs">';
          $variables['primary']['#suffix'] = '</ul>';
      }
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}
