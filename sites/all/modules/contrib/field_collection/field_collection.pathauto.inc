<?php

/**
 * Implements hook_pathauto().
 */
function field_collection_pathauto($op) {
  if ('settings' === $op) {
    $settings = array();
    $settings['module'] = 'field_collection';
    $settings['token_type'] = 'field_collection_item';
    $settings['groupheader'] = t('Field collection item paths');
    $settings['patterndescr'] = t('Default path pattern (applies to all field collections with blank patterns below)');
    $settings['patterndefault'] = '';
    // @todo Implement bulk update:
    // $settings['batch_update_callback'] = 'field_collection_pathauto_bulk_update_batch_process';
    // $settings['batch_file'] = drupal_get_path('module', 'field_collection') . '/field_collection.pathauto.inc';

    $settings['patternitems'] = array();
    $instances = field_info_instances();
    foreach ($instances as $entity_type => $type_bundles) {
      foreach ($type_bundles as $bundle => $bundle_instances) {
        foreach ($bundle_instances as $field_name => $instance) {
          $field = field_info_field($field_name);
          if ($field['type'] === 'field_collection') {
            // @todo We may need different patterns depending on the.
            // host entity type or the host bundle. If so we need to prefix
            // field-name with $entity_type . '_' . $bundle . '_' and also need
            // to implement our own version of pathauto_pattern_load_by_entity()
            // searching for the best matching pattern.
            $settings['patternitems'][$field_name] = t('Pattern for all field collection @field-collection paths', array('@field-collection' => $field_name));
          }
        }
      }
    }

    return (object) $settings;
  }
}

/**
 * Create a path alias for a field collection item.
 *
 * @param object $host_entity
 *   Entity to which the field collection item belongs.
 * @param object $entity
 *   Field collection item.
 * @param string $op
 *   Operation to perform for pathauto_create_alias(). Can be 'insert', 'update', 'return', or 'bulkupdate'.
 *
 * @see field_collection_field_update()
 */
function field_collection_pathauto_create_alias($host_entity, $entity, $op, $options = array()) {
  module_load_include('inc', 'pathauto');

  pathauto_create_alias('field_collection', $op, 'field-collection/' . str_replace('_', '-', $entity->field_name) . '/' . $entity->item_id, array('field_collection_item' => $entity), $entity->field_name);
}
