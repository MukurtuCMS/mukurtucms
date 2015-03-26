<?php
/**
 * @file
 * ma_digitalheritage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ma_digitalheritage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sapi_dh';
  $context->description = 'Browse Digital Heritage SAPI';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'digital_heritage_grid_list' => 'digital_heritage_grid_list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Browse Digital Heritage SAPI');
  $export['sapi_dh'] = $context;

  return $export;
}
