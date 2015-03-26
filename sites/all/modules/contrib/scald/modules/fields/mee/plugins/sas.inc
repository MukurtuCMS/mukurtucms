<?php
/**
 * @file
 * MEE wysiwyg plugins definitions.
 */

/**
 * Implements hook_wysiwyg_plugin().
 */
function mee_sas_plugin() {
  $plugins['sas'] = array(
    'title' => t('Scald SAS conversion'),
    'vendor url' => 'http://drupal.org/project/scald',
    'icon title' => t('Convert from HTML to SAS, and vice-versa'),
    'settings' => array(),
  );
  return $plugins;
}
