<?php

/**
 * @file
 * Stub file for bootstrap_fieldset().
 */

/* @noinspection PhpDocMissingThrowsInspection */

/**
 * Returns HTML for a fieldset form element and its children.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #attributes, #children, #collapsed, #collapsible,
 *     #description, #id, #title, #value.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_fieldset()
 *
 * @ingroup theme_functions
 */
function bootstrap_fieldset(array $variables) {
  /* @noinspection PhpUnhandledExceptionInspection */
  return theme('bootstrap_panel', $variables);
}
