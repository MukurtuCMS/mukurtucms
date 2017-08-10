<?php
/**
 * @file
 * Stub file for bootstrap_filter_tips_more_info().
 */

/**
 * Returns HTML for a link to the more extensive filter tips.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_filter_tips_more_info()
 *
 * @ingroup theme_functions
 */
function bootstrap_filter_tips_more_info() {
  $attributes = array(
    'target' => '_blank',
    'title' => t('Opens in new window'),
  );
  if (bootstrap_setting('tooltip_enabled')) {
    $attributes['data-toggle'] = 'tooltip';
  }
  return l(_bootstrap_icon('question-sign') . t('More information about text formats'), 'filter/tips', array(
    'html' => TRUE,
    'attributes' => $attributes,
  ));
}
