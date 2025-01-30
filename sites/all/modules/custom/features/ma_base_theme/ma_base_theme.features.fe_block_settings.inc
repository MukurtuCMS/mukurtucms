<?php
/**
 * @file
 * ma_base_theme.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ma_base_theme_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-frontpage-hero-image-one-column'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'frontpage-hero-image-one-column',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'mukurtu' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mukurtu',
        'weight' => 0,
      ),
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

  $export['bean-frontpage-hero-image-two-columns'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'frontpage-hero-image-two-columns',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'mukurtu' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mukurtu',
        'weight' => 0,
      ),
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
