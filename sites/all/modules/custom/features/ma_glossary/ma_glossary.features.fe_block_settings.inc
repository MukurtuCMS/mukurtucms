<?php
/**
 * @file
 * ma_glossary.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ma_glossary_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-mukurtu_glossary-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'mukurtu_glossary-block',
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
