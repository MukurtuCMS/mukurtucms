<?php
/**
 * @file
 * oa_layouts.pipelines.inc
 */

/**
 * Implements hook_default_panels_renderer_pipeline().
 */
function oa_layouts_default_panels_renderer_pipeline() {
  $export = array();

  $pipeline = new stdClass();
  $pipeline->disabled = FALSE; /* Edit this to true to make a default pipeline disabled initially */
  $pipeline->api_version = 1;
  $pipeline->name = 'ipe_node_access';
  $pipeline->admin_title = 'In-Place Editor (node access) DEPRECATED';
  $pipeline->admin_description = 'DEPRECATED: Use normal In-Place-Editor pipeline';
  $pipeline->weight = 0;
  $pipeline->settings = array(
    'renderers' => array(
      0 => array(
        'access' => array(
          'plugins' => array(
            0 => array(
              'name' => 'perm',
              'settings' => array(
                'perm' => 'use panels in place editing',
              ),
              'context' => 'logged-in-user',
            ),
          ),
          'logic' => 'and',
        ),
        'renderer' => 'ipe',
        'options' => array(),
      ),
    ),
  );
  $export['ipe_node_access'] = $pipeline;

  return $export;
}
