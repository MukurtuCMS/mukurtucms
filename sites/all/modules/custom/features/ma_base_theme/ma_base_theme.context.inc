<?php
/**
 * @file
 * ma_base_theme.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ma_base_theme_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'browse';
  $context->description = 'Browse Archive';
  $context->tag = 'mukurtu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'browse' => 'browse',
        'collection/*/build' => 'collection/*/build',
        'group-list' => 'group-list',
        'home' => 'home',
        'featured' => 'featured',
        'my-collection' => 'my-collection',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'browse',
    ),
    'theme_html' => array(
      'class' => 'browse-context',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Browse Archive');
  t('mukurtu');
  $export['browse'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'digital_heritage_node';
  $context->description = 'Digital Heritage Node view';
  $context->tag = 'mukurtu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'digital_heritage' => 'digital_heritage',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'browse',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Heritage Node view');
  t('mukurtu');
  $export['digital_heritage_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = 'mukurtu';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'user_first',
          'weight' => '-10',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'user_first',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'boxes-ma_footer' => array(
          'module' => 'boxes',
          'delta' => 'ma_footer',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('mukurtu');
  $export['sitewide'] = $context;

  return $export;
}
