<?php
/**
 * @file
 * Stub file for bootstrap_mark().
 */

/**
 * Returns HTML for a marker for new or updated content.
 *
 * @param array $variables
 *   An associative array containing:
 *   - type: Number representing the marker type to display. See MARK_NEW,
 *     MARK_UPDATED, MARK_READ.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_mark()
 *
 * @ingroup theme_functions
 */
function bootstrap_mark($variables) {
  global $user;
  if ($user->uid) {
    if ($variables['type'] == MARK_NEW) {
      return ' <span class="marker label label-primary">' . t('new') . '</span>';
    }
    elseif ($variables['type'] == MARK_UPDATED) {
      return ' <span class="marker label label-info">' . t('updated') . '</span>';
    }
  }
}
