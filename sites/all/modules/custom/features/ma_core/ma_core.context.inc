<?php
/**
 * @file
 * ma_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ma_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mukurtu_splash-manage_community' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'manage_community',
          'region' => 'dashboard_main',
          'weight' => '-22',
        ),
        'mukurtu_splash-manage_content' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'manage_content',
          'region' => 'dashboard_main',
          'weight' => '-21',
        ),
        'mukurtu_splash-demo_config' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'demo_config',
          'region' => 'dashboard_main',
          'weight' => '-10',
        ),
        'mukurtu_splash-user' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'user',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
        'mukurtu_splash-support' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'support',
          'region' => 'dashboard_sidebar',
          'weight' => '-9',
        ),
        'mukurtu_splash-site_start' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'site_start',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
        'mukurtu_splash-site_config' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'site_config',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['dashboard'] = $context;

  return $export;
}
