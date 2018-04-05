<?php
/**
 * @file
 * Provides app info for oa comment.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_comment_apps_app_info() {
  return array(
    'configure form' => 'oa_core_app_configure_form',
  );
}

