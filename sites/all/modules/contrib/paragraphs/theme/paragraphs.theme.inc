<?php

/**
 * @file
 * Default theme functions for paragraphs.
 */

/**
 * Process variables for paragraphs-items.tpl.php.
 */
function template_preprocess_paragraphs_items(&$variables, $hook) {
  $view_mode = isset($variables['element']['#paragraphs_items_view_mode']) ? $variables['element']['#paragraphs_items_view_mode'] : isset($variables['element']['#view_mode']);
  $field_name = $variables['element']['#field_name'];

  $variables['view_mode'] = $view_mode;
  $variables['field_name'] = $field_name;

  $variables['content'] = $variables['element']['#children'];

  $variables['classes_array'][] = drupal_html_class('paragraphs-items-' . $field_name);
  $variables['classes_array'][] = drupal_html_class('paragraphs-items-' . $field_name . '-' . $view_mode);
  $variables['classes_array'][] = drupal_html_class('paragraphs-items-' . $view_mode);

  $variables['theme_hook_suggestions'][] = 'paragraphs_items__' . $field_name;
  $variables['theme_hook_suggestions'][] = 'paragraphs_items__' . $field_name . '__' . $view_mode;
}
