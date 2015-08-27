<?php

/**
 * @file
 * Feeds hooks.
 */

/**
 * Implements hook_feeds_plugins().
 */
function feeds_entity_processor_feeds_plugins() {
  $path = drupal_get_path('module', 'feeds_entity_processor');

  $info = array();

  foreach (entity_get_info() as $type => $entity_info) {
    // Don't support entity type bundles.
    if (!empty($entity_info['bundle of'])) {
      continue;
    }

    if (!entity_type_supports($type, 'create') || !entity_type_supports($type, 'save')) {
      continue;
    }

    $info['FeedsEntityProcessor' . drupal_ucfirst($type)] = array(
      'name' => $entity_info['label'] . ' entity processor - EXPERIMENTAL',
      // @todo: Use plural label if there.
      'description' => 'Create and update ' . drupal_strtolower($entity_info['label']) . 's.',
      'help' => 'Create and update ' . drupal_strtolower($entity_info['label']) . 's from parsed content.',
      'plugin_key' => 'FeedsEntityProcessor',
      'handler' => array(
        'parent' => 'FeedsProcessor',
        'class' => 'FeedsEntityProcessor',
        'file' => 'FeedsEntityProcessor.inc',
        'path' => $path,
      ),
      // Add in the entity type used.
      // @see FeedsEntityProcessor::entityType()
     'type' => $type,
    );
  }

  return $info;
}
