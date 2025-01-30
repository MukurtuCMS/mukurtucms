<?php

/**
 * @file
 * Preprocess functions for FullCalendar.
 */

/**
 * Builds the FullCalendar structure as a render array.
 */
function template_preprocess_fullcalendar(&$variables) {
  $events = fullcalendar_prepare_events($variables['view'], $variables['rows'], $variables['options']['fields']);

  // If we're using ajax, we're done.
  if (!empty($variables['view']->fullcalendar_ajax)) {
    $variables['element'] = $events;
    return;
  }

  $variables['element'] = array(
    'status' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'fullcalendar-status',
        ),
      ),
    ),
    'fullcalendar' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'fullcalendar',
        ),
      ),
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'fullcalendar-content',
        ),
      ),
    ),
  );


  if ($events) {
    $variables['element']['content']['events'] = $events;
  }

  // Gather options from all modules.
  $settings = array();
  fullcalendar_include_api();
  $fullcalendar_options = module_invoke_all('fullcalendar_options_info');
  uasort($fullcalendar_options, 'drupal_sort_weight');
  foreach (array_intersect(array_keys($fullcalendar_options), module_implements('fullcalendar_options_process')) as $module) {
    $function = $module . '_fullcalendar_options_process';
    $function($variables, $settings);
  }

  // Add settings to Drupal.settings.
  $variables['element']['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(
      'fullcalendar' => array(
        '.view-dom-id-' . $variables['view']->dom_id => $settings,
      ),
    ),
  );
}

/**
 * Render the FullCalendar.
 */
function theme_fullcalendar($variables) {
  return drupal_render($variables['element']);
}

/**
 * Build the render array for an individual event.
 */
function template_preprocess_fullcalendar_event(&$variables) {
  $variables['element'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'fullcalendar-event',
      ),
    ),
    'title' => array(
      '#prefix' => '<h3 class="title">',
      '#suffix' => '</h3>',
      '#markup' => $variables['entity']->title,
    ),
  );
  foreach ($variables['event'] as $instance) {
    $variables['element'][] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'fullcalendar-instance',
        ),
      ),
      array($instance),
    );
  }
}

/**
 * Render the event.
 */
function theme_fullcalendar_event($variables) {
  return drupal_render($variables['element']);
}

/**
 * Build a render array representing the events.
 *
 * @param object $view
 *   The view object.
 * @param array $rows
 *   An array of row objects.
 * @param array $options
 *   An array of options from the style plugin.
 *
 * @return array
 *   A render array of events.
 */
function fullcalendar_prepare_events($view, $rows, $options) {
  if (empty($rows)) {
    return;
  }

  $events = array();
  foreach ($rows as $delta => $row) {
    // Collect all fields for the customize options.
    $fields = array();
    // Collect only date fields.
    $date_fields = array();
    foreach ($view->field as $field_name => $field) {
      $fields[$field_name] = $view->style_plugin->get_field($delta, $field_name);
      if (fullcalendar_field_is_date($field)) {
        $date_fields[$field_name] = array(
          'value' => $field->get_items($row),
          'field_alias' => $field->field_alias,
          'field_name' => $field->field_info['field_name'],
          'field_info' => $field->field_info,
        );
      }
    }

    // If using a custom date field, filter the fields to process.
    if (!empty($options['date'])) {
      $date_fields = array_intersect_key($date_fields, $options['date_field']);
    }

    // If there are no date fields (gcal only), return.
    if (empty($date_fields)) {
      return $events;
    }

    // This should never happen, but just in case.
    if (!isset($row->_field_data)) {
      return $events;
    }

    $entities = array();
    $event = array();
    foreach ($date_fields as $field) {
      // If this row doesn't contain this entity, or if this entity has already
      // been processed, skip it.
      if (!isset($row->_field_data[$field['field_alias']])) {
        continue;
      }

      if (!isset($entities[$field['field_alias']])) {
        // Find the field's alias that refers to it's entity.
        $alias = $field['field_alias'];
        $entity = $row->_field_data[$alias]['entity'];
        $entity->entity_type = $row->_field_data[$alias]['entity_type'];

        list(, , $bundle) = entity_extract_ids($entity->entity_type, $entity);
        $entity->bundle = $bundle;
        $entity->eid = $row->{$alias};
        $entity->options = $view->style_options;

        // If the view disallows editing, that's it.
        if (!empty($view->fullcalendar_disallow_editable)) {
          $entity->editable = FALSE;
        }
        // Otherwise, see what other modules think.
        else {
          // Allow resize/drag/drop of an event if user has proper permissions.
          $editable = module_invoke_all('fullcalendar_editable', $entity, $view);
          // If one value is FALSE, return FALSE. The identical operator is needed
          // because of the return value of array_search().
          $editable = array_search(FALSE, $editable, TRUE) === FALSE;
          drupal_alter('fullcalendar_editable', $editable, $entity, $view);
          $entity->editable = $editable;
        }

        // Store the current date field name for later.
        $entity->fullcalendar_date_field = $field['field_name'];

        // Create a string of valid HTML class names and add them to the entity.
        $classes = module_invoke_all('fullcalendar_classes', $entity);
        drupal_alter('fullcalendar_classes', $classes, $entity);
        $classes = array_map('drupal_html_class', $classes);
        $entity->class = implode(' ', array_unique($classes));

        // Default URL.
        $uri = entity_uri($entity->entity_type, $entity);
        $entity->url = isset($uri['path']) ? $uri['path'] : '';
        // Fetch custom URL if needed.
        if (!empty($options['url'])) {
          $field_name = $options['url_field'];
          if (!empty($fields[$field_name])) {
            $entity->url = ltrim($fields[$field_name], '/');
          }
        }

        // Fetch custom title if needed.
        if (!isset($entity->title)) {
          $entity->title = '';
        }
        if (!empty($options['title'])) {
          $field_name = $options['title_field'];
          if (!empty($fields[$field_name])) {
            $entity->title = $fields[$field_name];
          }
        }

        $entities[$alias] = $entity;
      }

      $entity = $entities[$field['field_alias']];
      // Filter fields without value.
      if (!empty($field['value'])) {
        $instance = field_info_instance($entity->entity_type, $field['field_name'], $bundle);
        foreach ($field['value'] as $index => $item) {
          $dates = _fullcalendar_process_dates($instance, $entity, $field['field_info'], $item['raw']);
          if (empty($dates)) {
            continue;
          }

          list($start, $end, $all_day) = $dates;
          $event[] = array(
            '#theme' => 'link',
            '#text' => $item['rendered']['#markup'],
            '#path' => $entity->url,
            '#options' => array(
              'attributes' => array(
                'allDay' => $all_day,
                'start' => $start,
                'end' => $end,
                'editable' => $entity->editable,
                'field' => $field['field_name'],
                'index' => $index,
                'eid' => $entity->eid,
                'entity_type' => $entity->entity_type,
                'cn' => $entity->class,
                'title' => strip_tags(htmlspecialchars_decode($entity->title, ENT_QUOTES)),
                'class' => array('fullcalendar-event-details'),
              ),
              'html' => TRUE,
            ),
          );
        }
      }
    }

    if (!empty($event)) {
      $events[$delta] = array(
        '#theme' => 'fullcalendar_event',
        '#event' => $event,
        '#entity' => isset($entities[$view->base_field]) ? $entities[$view->base_field] : reset($entities),
      );
    }
  }
  return $events;
}

/**
 * Process the dates, format them, and determine if it is all day.
 *
 * @param array $instance
 *   The field instance.
 * @param object $entity
 *   The entity object
 * @param array $field
 *   The field info.
 * @param array $item
 *   The date item.
 *
 * @return array
 *   A numerically indexed array containing these elements:
 *   - 0: The start date object.
 *   - 1: The end date object.
 *   - 2: A Boolean representing whether the date is all day.
 */
function _fullcalendar_process_dates($instance, $entity, $field, $item) {
  if (isset($item['db']['value'])) {
    $date1 = $item['db']['value'];
    date_timezone_set($date1, timezone_open($item['timezone']));
    $date2 = $item['db']['value2'];
    date_timezone_set($date2, timezone_open($item['timezone']));
  }
  else {
    $date = date_formatter_process($instance['display']['default']['type'], $entity->entity_type, $entity, $field, $instance, LANGUAGE_NONE, $item, $instance['display']['default']);
    if (empty($date['value']['local']['object'])) {
      return;
    }

    $date1 = $date['value']['local']['object'];
    $date2 = $date['value2']['local']['object'];
  }

  // Allow modules to alter the date objects.
  $context = array('instance' => $instance, 'entity' => $entity, 'field' => $field);
  drupal_alter('fullcalendar_process_dates', $date1, $date2, $context);

  $start = $date1->format(DATE_FORMAT_DATETIME);
  $end = $date2->format(DATE_FORMAT_DATETIME);
  $all_day = _fullcalendar_date_all_day_field($field, $instance, $date1, $date2);
  return array($start, $end, $all_day);
}

/**
 * Provide a wrapper around the deprecated date_field_all_day().
 *
 * @see date_all_day_field()
 * @see date_field_all_day().
 */
function _fullcalendar_date_all_day_field($field, $instance, $date1, $date2 = NULL) {
  // Try the old function first since it is more likely to be available.
  if (function_exists('date_field_all_day')) {
    return date_field_all_day($field, $instance, $date1, $date2);
  }

  // Now try the new function.
  if (function_exists('date_all_day_field')) {
    return date_all_day_field($field, $instance, $date1, $date2);
  }

  // This means the old function has been removed, and they haven't enabled the
  // new module yet. All day events will be displayed as not all day.
  watchdog('fullcalendar', 'All day events will not function correctly until the Date All Day module is enabled.', array(), WATCHDOG_NOTICE);
  return FALSE;
}
