<?php

/**
 * @file
 * Plugin to provide access control based on arg(0, drupal_static('colorbox_original_q')) == 'colorbox'.
 */

$plugin = array(
  'title' => t('Colorbox Node'),
  'description' => t('Is this node displayed in a Colorbox.'),
  'callback' => 'colorbox_node_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'colorbox_node_ctools_access_settings',
  'summary' => 'colorbox_node_ctools_access_summary',
);

/**
 * Settings form for the 'by parent term' access plugin
 */
function colorbox_node_ctools_access_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  return $form;
}

/**
 * Check for access.
 */
function colorbox_node_ctools_access_check($conf, $context) {
  if ( arg(0, drupal_static('colorbox_original_q')) == 'colorbox' ) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Provide a summary description based upon the checked terms.
 */
function colorbox_node_ctools_access_summary($conf, $context) {
  return t('Node displayed in a Colorbox');
}
