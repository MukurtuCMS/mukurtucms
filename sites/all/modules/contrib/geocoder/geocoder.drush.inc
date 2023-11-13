<?php

/**
 * Implements hook_drush_command().
 */
function geocoder_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['geocoder-backfill'] = array(
    'callback' => 'geocoder_drush_backfill',
    'description' => "Geocodes all nodes that have a geocoder widget but no geodata.",
    'options' => array(
      'force' => 'Force the geocode to run, even if there is already geodata',
      'dry' => 'Collect entity ids, but do not update them.',
      'entity_type' => 'An entity type. If none is specified, entities of all types are processed.',
      'field_name' => 'A field name. If none is specified, all applicable fields are processed.',
      'bundle' => 'A bundle name. If none is specified, entities of all bundles are processed.',
      'entity_ids' => 'A list of entity ids, separated by comma (no space). If none are specified, all entities are processed. This requires that entity_type is defined, too.'
    ),
  );

  return $items;
}

/**
 * Drush command callback for 'geocoder-backfill'.
 */
function geocoder_drush_backfill() {
  // Note:
  // The values from drush_get_option() are not guaranteed to be in a format one
  // might expect, and must be considered unsafe.
  // This does not matter for comparisons with ===, but they should not be
  // passed to other functions as-is.
  $force_reload = drush_get_option('force');
  $dry_run = drush_get_option('dry');
  $expected_entity_type = drush_get_option('entity_type');
  $expected_field_name = drush_get_option('field_name');
  $expected_bundle = drush_get_option('bundle');
  $expected_entity_ids = drush_get_option_list('entity_ids');
  if (!$expected_entity_type) {
    if ($expected_bundle) {
      drush_log('Cannot specify a bundle, if no entity type is specified.', 'error');
      return;
    }
    if ($expected_entity_ids) {
      drush_log('Cannot specify entity ids, if no entity type is specified.', 'error');
      return;
    }
    $expected_bundle = NULL;
    $expected_entity_ids = array();
  }

  foreach (field_info_instances() as $entity_type => $instances_by_bundle) {
    if ($expected_entity_type && $entity_type !== $expected_entity_type) {
      continue;
    }
    $entities_to_save = array();
    foreach ($instances_by_bundle as $bundle => $instances_by_fieldname) {
      if ($expected_bundle && $bundle !== $expected_bundle) {
        continue;
      }
      foreach ($instances_by_fieldname as $dest_field_name => $field_instance) {
        if ($expected_field_name && $dest_field_name !== $expected_field_name) {
          continue;
        }
        if ('geocoder' !== $field_instance['widget']['type']) {
          continue;
        }
        if (empty($field_instance['widget']['settings']['geocoder_field'])) {
          continue;
        }
        $source_field_name = $field_instance['widget']['settings']['geocoder_field'];

        // Find source field items without a destination field item.
        $q = db_select('field_data_' . $source_field_name, 'source');
        $q->condition('source.entity_type', $entity_type);
        $q->condition('source.bundle', $bundle);
        if ($expected_entity_ids) {
          $q->condition('source.entity_id', $expected_entity_ids);
        }
        if (!$force_reload) {
          $q->leftJoin(
            'field_data_' . $dest_field_name,
            'dest',
            "source.entity_type = dest.entity_type and source.entity_id = dest.entity_id");
          $q->isNull('dest.entity_id');
        }
        $q->fields('source', ['entity_id']);
        $q->groupBy('source.entity_id');

        if (NULL === $result = $q->execute()) {
          continue;
        }

        $etids_orig = $result->fetchCol();

        if (array() === $etids_orig) {
          drush_log($entity_type . ': ' . $bundle . ': ' . $dest_field_name . ': -', 'ok');
          continue;
        }

        $entities = entity_load($entity_type, $etids_orig);
        $etids = array_keys($entities);
        $etids_orphan = array_diff($etids, $etids_orig);

        drush_log($entity_type . ': ' . $bundle . ': ' . $dest_field_name . ': ' . implode(', ',$etids), 'ok');

        if (array() !== $etids_orphan) {
          drush_log('Orphan etids: ' . implode(', ',$etids_orphan), 'warning');
        }

        // Make sure to save every entity only once.
        $entities_to_save += $entities;
      }
    }

    if (!$dry_run) {
      foreach ($entities_to_save as $entity) {
        // Saving an entity automatically triggers recalculation.
        entity_save($entity_type, $entity);
      }
    }
  }
}
