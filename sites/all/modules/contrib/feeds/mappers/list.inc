<?php

/**
 * @file
 * On behalf implementation of Feeds mapping API for list.module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsProcessor::getMappingTargets()
 */
function list_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);

    switch ($info['type']) {

      case 'list_integer':
      case 'list_float':
        $targets[$name] = array(
          'name' => check_plain($instance['label']),
          'callback' => 'number_feeds_set_target',
          'description' => t('The @label field of the entity.', array('@label' => $instance['label'])),
        );
        break;

      case 'list_boolean':
        $targets[$name] = array(
          'name' => check_plain($instance['label']),
          'callback' => 'list_feeds_set_boolean_target',
          'description' => t('The @label field of the entity.', array('@label' => $instance['label'])),
        );
        break;

      case 'list_text':
        $targets[$name] = array(
          'name' => check_plain($instance['label']),
          'callback' => 'text_feeds_set_target',
          'description' => t('The @label field of the entity.', array('@label' => $instance['label'])),
        );
        break;
    }
  }
}

/**
 * Callback for setting list_boolean fields.
 */
function list_feeds_set_boolean_target(FeedsSource $source, $entity, $target, array $values, array $mapping = array()) {
  $field = isset($entity->$target) ? $entity->$target : array(LANGUAGE_NONE => array());

  foreach ($values as $value) {

    if (is_object($value) && ($value instanceof FeedsElement)) {
      $value = $value->getValue();
    }

    $field[LANGUAGE_NONE][] = array('value' => (int) (bool) $value);
  }

  $entity->$target = $field;
}
