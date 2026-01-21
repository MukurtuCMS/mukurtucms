<?php

/**
 * @file
 * Documentation of Feeds entity processor hooks.
 */

/**
 * Declare handlers for entity properties.
 */
function hook_feeds_entity_processor_properties() {
  $info = array();

  $info['my_property_type'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyMyPropertyType',
      'file' => 'FeedsEntityProcessorPropertyMyPropertyType.php',
      // Feeds entity processor will look for
      // FeedsEntityProcessorPropertyMyPropertyType.php in the my_module
      // directory.
      'path' => drupal_get_path('module', 'my_module'),
    ),
  );

  return $info;
}
