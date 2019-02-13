<?php

/**
 * @file
 * Theme functions for FullCalendar Legend.
 */

/**
 * Build the legend as a render array.
 */
function template_preprocess_fullcalendar_legend(&$variables) {
  $element = array(
    '#attached' => array(
      'css' => array(
        ctools_attach_css('fullcalendar_legend.theme', 'fullcalendar_legend'),
      ),
    ),
  );
  foreach ($variables['types'] as $type_name => $type) {
    $element[$type_name] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => _fullcalendar_legend_get_classes($type),
        'entity_type' => $type['entity_type'],
        'bundle' => $type['bundle'],
        'field' => $type['field_name'],
      ),
    );
    // Sanitize the label.
    $type['label'] = check_plain($type['label']);
    if (isset($type['uri'])) {
      $element[$type_name]['type'] = array(
        '#type' => 'link',
        '#href' => $type['uri']['path'],
        '#options' => isset($type['uri']['options']) ? $type['uri']['options'] : array(),
        '#title' => $type['label'],
      );
    }
    else {
      $element[$type_name]['type'] = array(
        '#markup' => $type['label'],
      );
    }
  }

  $variables['element'] = $element;
}

/**
 * Render the legend.
 */
function theme_fullcalendar_legend($variables) {
  return drupal_render($variables['element']);
}

/**
 * Spoofs an entity to get its classes.
 *
 * @param array $type
 *   An array containing the following keys:
 *    - "entity_type": The entity type; e.g. 'node' or 'user'.
 *    - "bundle": The bundle name.
 *
 * @return array
 *   An array of CSS classes.
 */
function _fullcalendar_legend_get_classes($type) {
  $values['type'] = $type['bundle'];
  if (isset($type['taxonomy_field']) && isset($type['tid'])) {
    $values[$type['taxonomy_field']] = array(array(array('tid' => $type['tid'])));
  }
  $entity = (module_exists('entity')) ? entity_create($type['entity_type'], $values) : new stdClass();
  $entity->bundle = $entity->type = $type['bundle'];
  $entity->entity_type = $type['entity_type'];

  $classes = module_invoke_all('fullcalendar_classes', $entity);
  drupal_alter('fullcalendar_classes', $classes, $entity);

  return $classes;
}
