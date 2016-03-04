<?php
/**
 * @file
 * ma_core.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ma_core_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu_block-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'module' => 'menu_block',
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
      'ppp' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ppp',
        'weight' => 0,
      ),
      'ppp2016' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ppp2016',
        'weight' => 0,
      ),
    ),
    'title' => 'Footer Menu',
    'visibility' => 0,
  );

  return $export;
}
