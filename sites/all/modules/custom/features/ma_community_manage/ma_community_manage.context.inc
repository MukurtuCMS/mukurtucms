<?php
/**
 * @file
 * ma_community_manage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ma_community_manage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'groups';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'community' => 'community',
        'cultural_protocol_group' => 'cultural_protocol_group',
      ),
      'options' => array(
        'node_form' => '0',
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
          'weight' => '-28',
        ),
        'views-communities_content-block_1' => array(
          'module' => 'views',
          'delta' => 'communities_content-block_1',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-communities_members-block_1' => array(
          'module' => 'views',
          'delta' => 'communities_members-block_1',
          'region' => 'content',
          'weight' => '12',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'browse',
    ),
  );
  $context->condition_mode = 0;
  $export['groups'] = $context;

  return $export;
}
