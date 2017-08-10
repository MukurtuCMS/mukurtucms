<?php

/**
 * @file
 * Feeds hooks.
 */

/**
 * Implements hook_feeds_plugins().
 */
function feeds_entity_processor_feeds_plugins() {
  $path = drupal_get_path('module', 'feeds_entity_processor') . '/src';

  $info = array();

  foreach (entity_get_info() as $type => $entity_info) {
    // Don't support entity type bundles.
    if (!empty($entity_info['bundle of'])) {
      continue;
    }

    if (!entity_type_supports($type, 'create') || !entity_type_supports($type, 'save')) {
      continue;
    }

    $plural_label = !empty($entity_info['plural label']) ? $entity_info['plural label'] : $entity_info['label'] . ' entities';

    $info['FeedsEntityProcessor' . drupal_ucfirst($type)] = array(
      'name' => $entity_info['label'] . ' entity processor - EXPERIMENTAL',
      'description' => 'Create and update ' . drupal_strtolower($plural_label),
      'help' => 'Create and update ' . drupal_strtolower($plural_label) . ' from parsed content.',
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

/**
 * Implements hook_feeds_entity_processor_properties().
 */
function feeds_entity_processor_feeds_entity_processor_properties() {
  $path = drupal_get_path('module', 'feeds_entity_processor') . '/src/Property';

  $info = array();

  // Default handler. Used when there is no specific handler for the given
  // property.
  $info['default'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyDefault',
      'file' => 'FeedsEntityProcessorPropertyDefault.php',
      'path' => $path,
    ),
  );

  $info['boolean'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyBoolean',
      'file' => 'FeedsEntityProcessorPropertyBoolean.php',
      'path' => $path,
    ),
  );
  $info['date'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyDate',
      'file' => 'FeedsEntityProcessorPropertyDate.php',
      'path' => $path,
    ),
  );
  $info['entity'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyEntity',
      'file' => 'FeedsEntityProcessorPropertyEntity.php',
      'path' => $path,
    ),
  );

  // Create handler for each entity type.
  $entity_info = entity_get_info();
  foreach ($entity_info as $entity_type => $entity_type_info) {
    $info[$entity_type] = array(
      'handler' => array(
        'class' => 'FeedsEntityProcessorPropertyEntityType',
        'file' => 'FeedsEntityProcessorPropertyEntityType.php',
        'path' => $path,
      ),
    );
  }

  return $info;
}
