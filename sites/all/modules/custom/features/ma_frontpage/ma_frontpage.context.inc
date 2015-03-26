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
  $context->name = 'custom_site';
  $context->description = 'Custom Site Homepage - Sitewide';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom Site Homepage - Sitewide');
  $export['custom_site'] = $context;

  return $export;
}
