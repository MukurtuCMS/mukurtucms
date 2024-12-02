<?php


/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @ingroup themeable
 */
function theme_search_api_glossary_facetapi_link_inactive_v2($variables) {
  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Adds count to link if one was passed.
  if ($variables['display_count'] == 1) {
    $variables['text'] .= ' ' . theme('facetapi_count', $variables);
  }

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  

  if ($variables['count'] != 0) {
    // we have some results, hyperlink
    $output =  theme_link($variables);    
  }
  else {
    // do not hyperlink if there are zero results  
    $output = $variables['text'];
  }
  
  return $output;
  
}



/**
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function theme_search_api_glossary_facetapi_link_active_v2($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  return theme_link($variables) . $link_text;
}
