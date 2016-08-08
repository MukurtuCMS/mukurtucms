<?php
/**
 * @file
 * Default theme functions for paragraphs.
 */

/**
 * Process variables for paragraphs-items.tpl.php
 */
function template_preprocess_paragraphs_items(&$variables, $hook) {
  $variables['view_mode'] = $variables['element']['#view_mode'];
  $variables['field_name'] = $variables['element']['#field_name'];

  $variables['content'] = $variables['element']['#children'];

  $variables['classes_array'][] = drupal_html_class('paragraphs-items-' . $variables['element']['#field_name']);
  $variables['classes_array'][] = drupal_html_class('paragraphs-items-' . $variables['element']['#field_name'] . '-' . $variables['view_mode']);
  $variables['classes_array'][] = drupal_html_class('paragraphs-items-' . $variables['view_mode']);

  $variables['theme_hook_suggestions'][] = 'paragraphs_items__' . $variables['element']['#field_name'];
  $variables['theme_hook_suggestions'][] = 'paragraphs_items__' . $variables['element']['#field_name'] . '__' . $variables['view_mode'];
}
