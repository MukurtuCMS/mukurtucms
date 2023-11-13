<?php

/**
 * @file
 * List of available hook and alter APIs for use in your sub-theme.
 */

/**
 * @defgroup api APIs
 *
 * List of available hook and alter APIs for use in your sub-theme.
 *
 * @{
 */

/**
 * Allows sub-themes to alter the array used for colorizing text.
 *
 * @param array $texts
 *   An associative array containing the text and classes to be matched, passed
 *   by reference.
 *
 * @see _bootstrap_colorize_text()
 */
function hook_bootstrap_colorize_text_alter(array &$texts) {
  // This matches the exact string: "My Unique Button Text".
  $texts['matches'][t('My Unique Button Text')] = 'primary';

  // This would also match the string above, however the class returned would
  // also be the one above; "matches" takes precedence over "contains".
  $texts['contains'][t('Unique')] = 'notice';

  // Remove matching for strings that contain "apply":
  unset($texts['contains'][t('Apply')]);

  // Change the class that matches "Rebuild" (originally "warning"):
  $texts['contains'][t('Rebuild')] = 'success';
}

/**
 * Allows sub-themes to alter the array used for associating an icon with text.
 *
 * @param array $texts
 *   An associative array containing the text and icons to be matched, passed
 *   by reference.
 *
 * @see _bootstrap_iconize_text()
 */
function hook_bootstrap_iconize_text_alter(array &$texts) {
  // This matches the exact string: "My Unique Button Text".
  $texts['matches'][t('My Unique Button Text')] = 'heart';

  // This would also match the string above, however the class returned would
  // also be the one above; "matches" takes precedence over "contains".
  $texts['contains'][t('Unique')] = 'bullhorn';

  // Remove matching for strings that contain "filter":
  unset($texts['contains'][t('Filter')]);

  // Change the icon that matches "Upload" (originally "upload"):
  $texts['contains'][t('Upload')] = 'ok';
}

/**
 * This hook allows sub-themes to process all form elements.
 *
 * For this hook to be recognized, it must reside directly inside the
 * template.php file or via a file that is directly included into template.php.
 *
 * Any time a hook is added or removed, the Drupal cache must be completely
 * cleared and rebuilt for the changes to take effect.
 *
 * Implementations of this hook should check to see if the element has a
 * property named #bootstrap_ignore_process and check if it is set to TRUE.
 * If it is, the hook should immediately return with the unaltered element.
 *
 * @param array $element
 *   The element array, this is NOT passed by reference and must return the
 *   altered element instead.
 * @param array $form_state
 *   The form state array, passed by reference.
 * @param array $form
 *   The complete form array, passed by reference.
 *
 * @return array
 *   The altered element array.
 *
 * @see bootstrap_element_info_alter()
 * @see form_builder()
 * @see drupal_process_form()
 */
function hook_form_process(array $element, array &$form_state, array &$form) {
  return $element;
}

/**
 * This hook allows sub-themes to process a specific form element type.
 *
 * For this hook to be recognized, it must reside directly inside the
 * template.php file or via a file that is directly included into template.php.
 *
 * Any time a hook is added or removed, the Drupal cache must be completely
 * cleared and rebuilt for the changes to take effect.
 *
 * If there is a matching "form_process_HOOK" function already defined
 * (provided by core), it will be replaced. The theme replacing it will be
 * responsible for fully processing the element as it was prior.
 *
 * Implementations of this hook should check to see if the element has a
 * property named #bootstrap_ignore_process and check if it is set to TRUE.
 * If it is, the hook should immediately return with the unaltered element.
 *
 * @param array $element
 *   The element array, this is NOT passed by reference and must return the
 *   altered element instead.
 * @param array $form_state
 *   The form state array, passed by reference.
 * @param array $form
 *   The complete form array, passed by reference.
 *
 * @return array
 *   The altered element array.
 *
 * @see bootstrap_element_info_alter()
 * @see form_builder()
 * @see drupal_process_form()
 */
function hook_form_process_HOOK(array $element, array &$form_state, array &$form) {
  return $element;
}

/**
 * This hook allows sub-themes to alter all elements before it's rendered.
 *
 * For this hook to be recognized, it must reside directly inside the
 * template.php file or via a file that is directly included into template.php.
 *
 * Any time a hook is added or removed, the Drupal cache must be completely
 * cleared and rebuilt for the changes to take effect.
 *
 * Implementations of this hook should check to see if the element has a
 * property named #bootstrap_ignore_pre_render and check if it is set to TRUE.
 * If it is, the hook should immediately return with the unaltered element.
 *
 * @param array $element
 *   The element array, this is NOT passed by reference and must return the
 *   altered element instead.
 *
 * @return array
 *   The altered element array.
 *
 * @see bootstrap_element_info_alter()
 */
function hook_pre_render(array $element) {
  return $element;
}

/**
 * This hook allows sub-themes to alter a specific element before it's rendered.
 *
 * For this hook to be recognized, it must reside directly inside the
 * template.php file or via a file that is directly included into template.php.
 *
 * Any time a hook is added or removed, the Drupal cache must be completely
 * cleared and rebuilt for the changes to take effect.
 *
 * If there is a matching "form_pre_render_HOOK" function already defined
 * (provided by core), it will be replaced. The theme replacing it will be
 * responsible for fully processing the element as it was prior.
 *
 * Implementations of this hook should check to see if the element has a
 * property named #bootstrap_ignore_pre_render and check if it is set to TRUE.
 * If it is, the hook should immediately return with the unaltered element.
 *
 * @param array $element
 *   The element array, this is NOT passed by reference and must return the
 *   altered element instead.
 *
 * @return array
 *   The altered element array.
 *
 * @see bootstrap_element_info_alter()
 */
function hook_pre_render_HOOK(array $element) {
  return $element;
}

/**
 * @} End of "defgroup subtheme_api".
 */
