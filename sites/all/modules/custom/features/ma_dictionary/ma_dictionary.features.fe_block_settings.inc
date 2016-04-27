<?php
/**
 * @file
 * ma_dictionary.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ma_dictionary_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-mukurtu_dictionary_word-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'mukurtu_dictionary_word-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'mukurtu_starter' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mukurtu_starter',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
