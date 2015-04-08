<?php
/**
 * @file
 * ma_frontpage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ma_frontpage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ma_site_header' => array(
          'module' => 'boxes',
          'delta' => 'ma_site_header',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-communities_content-block_1' => array(
          'module' => 'views',
          'delta' => 'communities_content-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['frontpage'] = $context;

  return $export;
}
