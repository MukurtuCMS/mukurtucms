<?php
/**
 * @file
 * deprecated.inc
 *
 * This contains all the currently deprecated functions that will be removed
 * in the next minor or major release.
 */

/**
 * Pre-render input elements.
 *
 * @deprecated Use proper hooks instead. Will be removed in 7.x-3.2.
 *
 * @see hook_pre_render()
 *
 * @todo Remove in 7.x-3.2.
 */
function _bootstrap_pre_render_input($element) {
  return bootstrap_pre_render($element);
}

/**
 * Pre-render fieldset element.
 *
 * @deprecated Use proper hooks instead. Will be removed in 7.x-3.2.
 *
 * @see hook_pre_render_HOOK()
 *
 * @todo Remove in 7.x-3.2.
 */
function _bootstrap_pre_render_fieldset($element) {
  return bootstrap_pre_render_fieldset($element);
}

/**
 * Internal function used to process all elements.
 *
 * @deprecated Use proper hooks instead. Will be removed in 7.x-3.2.
 *
 * @see hook_form_process()
 *
 * @todo Remove in 7.x-3.2.
 */
function _bootstrap_process_element($element, &$form_state, &$form) {
  $element = bootstrap_form_process($element, $form_state, $form);

  // Process form actions.
  if (!empty($element['#type']) && $element['#type'] === 'actions') {
    $element = bootstrap_form_process_actions($element, $form_state, $form);
  }

  // Process text_format elements.
  if (isset($element['#type']) && $element['#type'] === 'text_format') {
    $element = bootstrap_form_process_text_format($element, $form_state, $form);
  }

  return $element;
}

/**
 * Internal function used to process the fieldset element.
 *
 * @deprecated Use proper hooks instead. Will be removed in 7.x-3.2.
 *
 * @see hook_form_process_HOOK()
 *
 * @todo Remove in 7.x-3.2.
 */
function _bootstrap_process_fieldset($element, &$form_state, &$form) {
  // Purposefully left empty, there's nothing to process (just pre-render now).
}

/**
 * Helper function for determining if a tooltip can be used for a description.
 *
 * @param string $description
 *   The string of text to process.
 *
 * @deprecated Will be removed in 7.x-3.2.
 *
 * @see _bootstrap_simple_string()
 * @see bootstrap_element_smart_description()
 *
 * @todo Remove in 7.x-3.2.
 */
function _bootstrap_tooltip_description($description) {
  // Determine if tooltips are enabled.
  static $enabled;
  if (!isset($enabled)) {
    $enabled = bootstrap_setting('tooltip_enabled') && bootstrap_setting('forms_smart_descriptions');
  }
  // Immediately return if "simple" tooltip descriptions are not enabled.
  if (!$enabled) {
    return FALSE;
  }
  $allowed_tags = array('b', 'code', 'em', 'i', 'kbd', 'span', 'strong');
  $length = (int) bootstrap_setting('forms_smart_descriptions_length');
  if (empty($length)) {
    $length = FALSE;
  }
  return _bootstrap_is_simple_string($description, $length, $allowed_tags);
}
