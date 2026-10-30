<?php

/**
 * @file
 * On behalf implementation of Feeds mapping API for og.module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 */
function og_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'group') {    // Groups audience field
      $targets[$name] = array(
        'name' => check_plain($instance['label']),
        'callback' => 'og_feeds_set_target',
        'description' => t('The @label field of the node.', array('@label' => $instance['label'])),
      );
    }
  }
}

/**
 * Callback for mapping. Here is where the actual mapping happens.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 */
function og_feeds_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = is_string($value) ? drupal_explode_tags($value) : array($value);
  }

  $info = field_info_field($target);

  // Iterate over all values.
  $i = 0;
  $field = isset($entity->$target) ? $entity->$target : array();
  foreach ($value as $v) {
    if (!is_array($v) && !is_object($v)) {
      if ($groups = og_field_audience_potential_groups($v, 'equals', NULL, 1)) {
        $gid = key($groups);
        $field[LANGUAGE_NONE][$i]['gid'] = $gid;
      }
    }
    if ($info['cardinality'] == 1) {
      break;
    }
    $i++;
  }
  $entity->{$target} = $field;
}
