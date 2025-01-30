<?php

/**
 * @file
 * Stub file for "views_view_table" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "views_view_table" theme hook.
 *
 * See template for list of available variables.
 *
 * @param array $variables
 *   An associative array of variables, passed by reference.
 *
 * @see views-view-table.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_views_view_table(array &$variables) {
  bootstrap_include('bootstrap', 'templates/system/table.vars.php');
  _bootstrap_table_add_classes($variables['classes_array'], $variables);
}
