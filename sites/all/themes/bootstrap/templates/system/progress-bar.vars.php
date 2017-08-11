<?php
/**
 * @file
 * Stub file for "progress_bar" theme hook [pre]process functions.
 */

/**
 * Processes variables for the "progress_bar" theme hook.
 *
 * See template for list of available variables.
 *
 * @see progress-bar.tpl.php
 *
 * @ingroup theme_process
 */
function bootstrap_process_progress_bar(&$variables) {
  $variables['percent'] = check_plain($variables['percent']);
  $variables['message'] = filter_xss_admin($variables['message']);
}
