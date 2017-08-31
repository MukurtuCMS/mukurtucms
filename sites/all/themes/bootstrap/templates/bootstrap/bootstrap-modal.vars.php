<?php
/**
 * @file
 * Stub file for "bootstrap_modal" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "bootstrap_modal" theme hook.
 *
 * See template for list of available variables.
 *
 * @see bootstrap-modal.tpl.php
 *
 * @ingroup theme_preprocess
 *
 * @todo: Replace with "bootstrap_effect_fade" theme setting.
 */
function bootstrap_preprocess_bootstrap_modal(&$variables) {
  if (empty($variables['attributes']['id'])) {
    $variables['attributes']['id'] = drupal_html_id(strip_tags($variables['heading']));
  }
  $variables['attributes']['class'][] = 'modal';
  $variables['attributes']['class'][] = 'fade';
  $variables['attributes']['tabindex'] = -1;
  $variables['attributes']['role'] = 'dialog';
  $variables['attributes']['aria-hidden'] = 'true';
  $variables['dialog_attributes']['class'][] = 'modal-dialog';

  if (!empty($variables['size'])) {
    $variables['dialog_attributes']['class'][] = drupal_html_class('modal-' . $variables['size']);
  }
}

/**
 * Processes variables for the "bootstrap_modal" theme hook.
 *
 * See template for list of available variables.
 *
 * @see bootstrap-modal.tpl.php
 *
 * @ingroup theme_process
 */
function bootstrap_process_bootstrap_modal(&$variables) {
  $variables['attributes'] = drupal_attributes($variables['attributes']);
  $variables['dialog_attributes'] = drupal_attributes($variables['dialog_attributes']);

  $html = !empty($variables['html_heading']);
  $heading = $html && is_scalar($variables['heading']) ? filter_xss_admin($variables['heading']) : render($variables['heading']);
  $variables['heading'] = $html ? $heading : check_plain($heading);

  $variables['body'] = render($variables['body']);
  $variables['footer'] = render($variables['footer']);
}
