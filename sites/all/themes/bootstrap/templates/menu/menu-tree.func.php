<?php

/**
 * @file
 * Stub file for bootstrap_menu_tree() and suggestion(s).
 */

/**
 * Returns HTML for a wrapper for a menu sub-tree.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see template_preprocess_menu_tree()
 * @see theme_menu_tree()
 *
 * @ingroup theme_functions
 */
function bootstrap_menu_tree(array &$variables) {
  return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @return string
 *   The constructed HTML.
 */
function bootstrap_menu_tree__primary(array &$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Bootstrap theme wrapper function for the secondary menu links.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @return string
 *   The constructed HTML.
 */
function bootstrap_menu_tree__secondary(array &$variables) {
  return '<ul class="menu nav navbar-nav secondary">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_tree() for book module.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @return string
 *   The constructed HTML.
 */
function bootstrap_menu_tree__book_toc(array &$variables) {
  $output = '<div class="book-toc btn-group pull-right">';
  $output .= '  <button type="button" class="btn btn-link dropdown-toggle" data-toggle="dropdown">';
  $output .= t('!icon Outline !caret', array(
    '!icon' => _bootstrap_icon('list'),
    '!caret' => '<span class="caret"></span>',
  ));
  $output .= '</button>';
  $output .= '<ul class="dropdown-menu" role="menu">' . $variables['tree'] . '</ul>';
  $output .= '</div>';
  return $output;
}

/**
 * Overrides theme_menu_tree() for book module.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @return string
 *   The constructed HTML.
 */
function bootstrap_menu_tree__book_toc__sub_menu(array &$variables) {
  return '<ul class="dropdown-menu" role="menu">' . $variables['tree'] . '</ul>';
}
