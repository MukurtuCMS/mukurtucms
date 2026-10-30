<?php

/**
 * @file
 * Stub file for bootstrap_webform_managed_file().
 */

/**
 * Returns HTML for a Webform managed file element.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: A render element representing the file.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_webform_managed_file()
 * @see bootstrap_file_managed_file()
 *
 * @ingroup theme_functions
 */
function bootstrap_webform_managed_file(array $variables) {
  // Render with Bootstrap's managed file theme function.
  bootstrap_include('bootstrap', 'templates/file/file-managed-file.func.php');
  return bootstrap_file_managed_file($variables);
}
