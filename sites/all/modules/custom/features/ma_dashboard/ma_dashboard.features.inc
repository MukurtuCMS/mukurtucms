<?php

/**
 * @file
 * ma_dashboard.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ma_dashboard_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function ma_dashboard_homebox() {
  $homeboxes = array();

  $homeboxes['mukurtu_dashboard'] = array(
    'regions' => 5,
    'cache' => 0,
    'color' => 0,
    'colors' => array(
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => array(
      'mukurtu_splash_manage_dictionary' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'manage_dictionary',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -39,
      ),
      'mukurtu_splash_batch_import' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'batch_import',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -38,
      ),
      'mukurtu_splash_manage_community' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'manage_community',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -38,
      ),
      'node_recent' => array(
        'module' => 'views',
        'delta' => 'mukurtu_recent_content-block',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -42,
      ),
      'views_ma_recent_comments-block' => array(
        'module' => 'views',
        'delta' => 'ma_recent_comments-block',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -37,
      ),
      'mukurtu_splash_site_config' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'site_config',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -36,
      ),
      'mukurtu_splash_site_start' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'site_start',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -42,
      ),
      'mukurtu_splash_user' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'user',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -41,
      ),
      'mukurtu_splash_manage_content' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'manage_content',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -41,
      ),
      'mukurtu_splash_support' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'support',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -39,
      ),
      'mukurtu_splash_manage_taxonomy' => array(
        'module' => 'mukurtu_splash',
        'delta' => 'manage_taxonomy',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -40,
      ),
      'mukurtu_splash_manage_records' => array(
        'module' => 'mukurtu_taxonomy_records',
        'delta' => 'mukurtu_records',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -38,
      ),
    ),
    'widths' => array(
      1 => 100,
      2 => 33,
      3 => 34,
      4 => 33,
      5 => 100,
    ),
    'title' => 'Mukurtu Dashboard',
    'path' => 'dashboard',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 1,
    'roles' => array(
      0 => 'administrator',
      1 => 'Curator',
      2 => 'Mukurtu Administrator',
    ),
  );


  return $homeboxes;
}
