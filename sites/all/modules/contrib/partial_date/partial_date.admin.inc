<?php

/**
 * @file
 * Less freq. functions for field administration.
 */

/**
 * Internal callback for hook_field_info().
 */
function _partial_date_field_info() {
  $base = array(
    'default_widget' => 'partial_date',
    'default_formatter' => 'partial_date_default',
    'settings' => array(
      'estimates' => partial_date_field_estimates_default_settings(),
      // Minimal set of components before considered incomplete.
      // Includes each component and any, any_form, and any_to.
      'minimum_components' => array(),
    ),
    'property_callbacks' => array(
      'partial_date_property_info_callback',
    ),
  );
  return array(
    'partial_date' => $base + array(
      'label' => t('Partial date and time'),
      'description' => t('This field stores and renders partial dates.'),
      'property_type' => 'partial_date',
    ),
    'partial_date_range' => $base + array(
      'label' => t('Partial date and time range'),
      'description' => t('This field stores and renders partial dates.'),
      'property_type' => 'partial_date_range',
    ),
  );
}

/**
 * Helper function to define the default estimate settings.
 */
function partial_date_field_estimates_default_settings($clean = FALSE) {
  $defaults = array(
    'year' => array(
      '-60000|1600' => t('Pre-colonial'),
      '1500|1599' => t('16th century'),
      '1600|1699' => t('17th century'),
      '1700|1799' => t('18th century'),
      '1800|1899' => t('19th century'),
      '1900|1999' => t('20th century'),
      '2000|2099' => t('21st century'),
    ),
    'month' => array(
      '11|1' => t('Winter'),
      '2|4' => t('Spring'),
      '5|7' => t('Summer'),
      '8|10' => t('Autumn'),
    ),
    'day' => array(
      '0|12' => t('The start of the month'),
      '10|20' => t('The middle of the month'),
      '18|31' => t('The end of the month'),
    ),
    'hour' => array(
      '6|18' => t('Day time'),
      '6|12' => t('Morning'),
      '12|13' => t('Noon'),
      '12|18' => t('Afternoon'),
      '18|22' => t('Evening'),
      '0|1' => t('Midnight'),
      '18|6' => t('Night'),
    ),
    # wtf, why not
    'minute' => '',
    'second' => '',
  );
  // The instance settings are blank so that they use the field settings
  // by default.
  if ($clean) {
    foreach ($defaults as $key => $options) {
      $defaults[$key] = '';
    }
  }
  return $defaults;
}

/**
 * Helper function to duplicate the same settings on both the instance and field
 * settings.
 */
function partial_date_field_estimates_settings_form($settings, $field, $instance, $has_data) {
  $form = array();
  $form['estimates'] = array(
    '#type' => 'fieldset',
    '#title' => t('Base estimate values'),
    '#description' => t('These fields provide options for additional fields that can be used to represent corresponding date / time components. They define time periods where an event occured when exact details are unknown. All of these fields have the format "start|end|label", one per line, where start marks when this period started, end marks the end of the period and the label is shown to the user. Instance settings will be used whenever possible on forms, but views integration (once completed) will use the field values. Note that if used, the formatters will replace any corresponding date / time component with the options label value.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  foreach (partial_date_components() as $key => $label) {
    if ($key == 'timezone') {
      continue;
    }
    $value = array();
    if (is_array($settings['estimates'][$key])) {
      foreach($settings['estimates'][$key] as $range => $option_label) {
        $value[] = $range . '|' . $option_label;
      }
    }
    $form['estimates'][$key] = array(
      '#type' => 'textarea',
      '#title' => t('%label range options', array('%label' => $label), array('context' => 'datetime settings')),
      '#default_value' => implode("\n", $value),
      '#description' => t('Provide relative approximations for this date / time component.'),
      '#element_validate' => array('partial_date_field_estimates_validate_parse_options'),
      '#date_component' => $key,
    );
  }

  $widget_settings = $instance['widget']['settings'];

  $form['minimum_components'] = array(
    '#type' => 'fieldset',
    '#title' => t('Minimum components'),
    '#description' => t('These are used to determine if the field is incomplete during validation. All possible fields are listed here, but these are only checked if enabled in the instance settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $has_range = strpos($field['type'], '_range');
  $options = array();
  foreach (partial_date_components() as $key => $label) {
    $form['minimum_components']['from_granularity_' . $key] = array(
      '#type' => 'checkbox',
      '#title' => $has_range ? t('From @date_component', array('@date_component' => $label)) : $label,
      '#default_value' => !empty($settings['minimum_components']['from_granularity_' . $key]),
    );
  }
  foreach (partial_date_components(array('timezone')) as $key => $label) {
    $form['minimum_components']['from_estimates_' . $key] = array(
      '#type' => 'checkbox',
      '#title' => $has_range
          ? t('From Estimate @date_component', array('@date_component' => $label))
          : t('Estimate @date_component', array('@date_component' => $label)),
      '#default_value' => !empty($settings['minimum_components']['from_estimates_' . $key]),
    );
  }
  if ($field['type'] == 'partial_date_range') {
    foreach (partial_date_components() as $key => $label) {
      $form['minimum_components']['to_granularity_' . $key] = array(
        '#type' => 'checkbox',
        '#title' => t('To @date_component', array('@date_component' => $label)),
        '#default_value' => !empty($settings['minimum_components']['to_granularity_' . $key]),
      );
    }
    foreach (partial_date_components(array('timezone')) as $key => $label) {
      $form['minimum_components']['to_estimates_' . $key] = array(
        '#type' => 'checkbox',
        '#title' => t('To Estimate @date_component', array('@date_component' => $label)),
        '#default_value' => !empty($settings['minimum_components']['to_estimates_' . $key]),
      );
    }
  }
  $form['minimum_components']['txt_short'] = array(
    '#type' => 'checkbox',
    '#title' => t('Short date text'),
    '#default_value' => !empty($settings['minimum_components']['txt_short']),
  );
  $form['minimum_components']['txt_long'] = array(
    '#type' => 'checkbox',
    '#title' => t('Long date text'),
    '#default_value' => !empty($settings['minimum_components']['txt_long']),
  );
  return $form;
}

/**
 * Validate and parse the options. This is fairly loose validation, empty values
 * will be cast to 0.
 */
function partial_date_field_estimates_validate_parse_options(&$element, &$form_state) {
  $items = array();
  foreach (explode("\n", $element['#value']) as $line) {
    $line = trim($line);
    if (!empty($line)) {
      list($from, $to, $label) = explode('|', $line . '||');
      if (!strlen($from) && !strlen($to)) {
        continue;
      }
      $label = trim($label);
      if (empty($label)) {
        form_error($element, t('The label for the keys %keys is required.', array('%keys' => $from . '|' . $to)));
      }
      elseif (!is_numeric($from) || !is_numeric($to)) {
        form_error($element, t('The keys %from and %to must both be numeric.', array('%from' => $from, '%to' => $to)));
      }
      else {
        // We need to preserve empty strings, so cast to temp variables.
        $_from = (int) $from;
        $_to = (int) $to;
        $out_of_range = FALSE;
        $limits = array(
          'month' => 12,
          'day' => 31,
          'hour' => 23,
          'minute' => 59,
          'second' => 59,
        );
        if (isset($limits[$element['#date_component']])) {
          $limit = $limits[$element['#date_component']];
          if ($_to > $limit || $_to < 0 || $_from > $limit || $_from < 0) {
            form_error($element, t('The keys %from and %to must be within the range 0 to !max.', array('%from' => $_from, '%to' => $_to, '!max' => $limit)));
            continue;
          }
        }
        $items[$from . '|' . $to] = $label;
      }
    }
  }
  // Do we need to check?
  if (!form_get_error($element)) {
    form_set_value($element, $items, $form_state);
  }
}

/**
 * This generates the best estimate for the date components based on the
 * submitted values.
 */
function partial_date_field_populate_components($item, $start_date = TRUE) {
  $base = array(
    'year' => $start_date ? PD2_YEAR_MIN : PD2_YEAR_MAX,
    'month' => $start_date ? 1 : 12,
    'day' => 0, // Calculate last as this is variable
    'hour' => $start_date ? 0 : 23,
    'minute' => $start_date ? 0 : 59,
    'second' => $start_date ? 0 : 59,
    'timezone' => '',
  );

  foreach (partial_date_components() as $key => $label) {
    $value_key = $start_date ? $key : $key . '_to';
    if (isset($item[$value_key]) && strlen($item[$value_key])) {
      $base[$key] = $item[$value_key];
    }
  }

  if (empty($base['day'])) {
    if ($start_date) {
      $base['day'] = 1;
    }
    else {
      $month_table = partial_date_month_matrix($base['year']);
      if (isset($month_table[$base['month'] - 1])) {
        $base['day'] = $month_table[$base['month'] - 1];
      }
      else {
        $base['day'] = 31;
      }
    }
  }
  return $base;
}

/**
 * Implements hook_field_presave().
 *
 * This assumes data in the format:
 * from
 *   year
 *   year_estimate
 *   month
 *   month_estimate
 *   etc
 * to
 *   year
 *   year_estimate
 *   month
 *   month_estimate
 *   etc
 */
function _partial_date_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  $has_range = strpos($field['type'], '_range');
  foreach ($items as $delta => $item) {
    $items[$delta] = array();
    $items[$delta]['txt_short'] = isset($item['txt_short']) ? $item['txt_short'] : NULL;
    $items[$delta]['txt_long'] = isset($item['txt_long']) ? $item['txt_long'] : NULL;
    $items[$delta] += partial_date_field_presave_generate_storage_date($item['from']);

    if ($has_range) {
      $item['to'] = empty($item['to']) ? array() : $item['to'];
      $items[$delta] += partial_date_field_presave_generate_storage_date($item['to'], TRUE);
    }

    // Populate empty components with the estimate components. On load, these
    // should be cleared.
    $items[$delta]['data'] = array(
      'check_approximate' => empty($item['check_approximate']) ? 0 : 1,
    );

    foreach (partial_date_components(array('timezone')) as $key => $label) {
      $items[$delta]['data'][$key . '_estimate'] = '';
      $items[$delta]['data'][$key . '_estimate_from_used'] = 0;
      $items[$delta]['data'][$key . '_estimate_to_used'] = 0;
      $from = NULL;
      $to = NULL;
      if (!empty($item['from'][$key . '_estimate'])) {
        $items[$delta]['data'][$key . '_estimate'] = $item['from'][$key . '_estimate'];
        list ($from, $to) = explode('|', $item['from'][$key . '_estimate']);
        if (!isset($item['from'][$key]) || !strlen($item['from'][$key])) {
          $items[$delta][$key] = $from;
          $items[$delta]['data'][$key . '_estimate_from_used'] = 1;
        }
        if ($has_range && (!isset($item['to'][$key]) || !strlen($item['to'][$key]))) {
          $items[$delta][$key . '_to'] = $to;
          $items[$delta]['data'][$key . '_estimate_to_used'] = 1;
        }
      }
      if ($has_range) {
        $items[$delta]['data'][$key . '_to_estimate'] = '';
        if (!empty($item['to'][$key . '_estimate'])) {
          // We use the to estimate if not set
          $items[$delta]['data'][$key . '_to_estimate'] = $item['to'][$key . '_estimate'];
          list ($from_to, $to_to) = explode('|', $item['to'][$key . '_estimate']);
          if (!isset($item['from'][$key]) || !strlen($item['from'][$key]) || $items[$delta]['data'][$key . '_estimate_from_used']) {
            $items[$delta][$key] = is_numeric($from) ? min(array($from_to, $from)) : $from_to;
            $items[$delta]['data'][$key . '_estimate_from_used'] = 1;
          }
          if (!isset($item['to'][$key]) || !strlen($item['to'][$key]) || $items[$delta]['data'][$key . '_estimate_to_used']) {
            $items[$delta][$key . '_to'] = is_numeric($to) ? max(array($to_to, $to)) : $to_to;;
            $items[$delta]['data'][$key . '_estimate_to_used'] = 1;
          }
        }
      }
    }

    // This is done after the estimates are expanded out.
    $items[$delta]['timestamp'] = partial_date_float(partial_date_field_populate_components($items[$delta]));
    if ($has_range) {
      $items[$delta]['timestamp_to'] = partial_date_float(partial_date_field_populate_components($items[$delta], 0));
    }

    $items[$delta]['data'] = serialize($items[$delta]['data']);
  }
}

/**
 * Wrapper to set the storage column.
 */
function partial_date_field_presave_generate_storage_date($item, $end_date = FALSE) {
  $components = array();
  foreach (partial_date_components() as $key => $label) {
    $empty = $key == 'timezone' ? '' : NULL;
    $components[$key . ($end_date ? '_to' : '')] = isset($item[$key]) && strlen($item[$key]) ? $item[$key] : $empty;
  }
  return $components;
}

/**
 * Implements hook_field_validate().
 *
 * Possible error codes:
 * - 'xxxx': The partial_date year is not valid
 *
 * @see partial_date_field_widget_error().
 */
function _partial_date_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  $has_range = strpos($field['type'], 'range');
  $date_components = partial_date_components();

  $has_data = FALSE;
  $minimum_components = FALSE;
  if (!empty($field['settings']['minimum_components'])) {
    $minimum_components = array_filter($field['settings']['minimum_components']);
    $widget_settings = $instance['widget']['settings'];
    $widget_components = array();
    foreach (array_filter($widget_settings['granularity']['from']) as $key) {
      $widget_components['from_granularity_' . $key] = $has_range ? t('From @component', array('@component' => $date_components[$key])) : $date_components[$key];
    }
    foreach (array_filter($widget_settings['estimates']['from']) as $key) {
      $widget_components['from_estimates_' . $key] = $has_range ? t('From @component Estimate', array('@component' => $date_components[$key])) : $date_components[$key];
    }
    if ($has_range) {
      foreach (array_filter($widget_settings['granularity']['to']) as $key) {
        $widget_components['to_granularity_' . $key] = t('To @component', array('@component' => $date_components[$key]));
      }
      foreach (array_filter($widget_settings['estimates']['to']) as $key) {
        $widget_components['to_estimates_' . $key] = t('To @component Estimate', array('@component' => $date_components[$key]));
      }
    }
    if (!empty($widget_settings['theme_overrides']['txt_short'])) {
      $widget_components['txt_short'] = t('Short date description');
    }
    if (!empty($widget_settings['theme_overrides']['txt_long'])) {
      $widget_components['txt_long'] = t('Long date description');
    }
    $minimum_components = array_intersect_key($widget_components, $minimum_components);
  }

  foreach ($items as $delta => $item) {
    if (!partial_date_field_is_empty($item, $field)) {
      $has_data = TRUE;
      $incomplete = array();
      if ($minimum_components) {
        foreach ($minimum_components as $key => $label) {
          if (strpos($key, 'from_granularity_') === 0) {
            $component = str_replace('from_granularity_', '', $key);
            if (empty($item['from'][$component])) {
              $errors[$field['field_name']][$langcode][$delta][] = array(
                'error' => 'partial_date_incomplete_from',
                'partial_date_component' => $component,
                'message' => t('@component is required', array('@component' => $label)),
              );
            }
          }
          elseif (strpos($key, 'from_estimates_') === 0) {
            $component = str_replace('from_estimates_', '', $key) . '_estimate';
            if (empty($item['from'][$component])) {
              $errors[$field['field_name']][$langcode][$delta][] = array(
                'error' => 'partial_date_incomplete_from',
                'partial_date_component' => $component,
                'message' => t('@component is required', array('@component' => $label)),
              );
            }
          }
          elseif (strpos($key, 'to_granularity_') === 0) {
            $component = str_replace('to_granularity_', '', $key);
            if (empty($item['to'][$component])) {
              $errors[$field['field_name']][$langcode][$delta][] = array(
                'error' => 'partial_date_incomplete_to',
                'partial_date_component' => $component,
                'message' => t('@component is required', array('@component' => $label)),
              );
            }
          }
          elseif (strpos($key, 'to_estimates_') === 0) {
            $component = str_replace('to_estimates_', '', $key) . '_estimate';
            if (empty($item['to'][$component])) {
              $errors[$field['field_name']][$langcode][$delta][] = array(
                'error' => 'partial_date_incomplete_to',
                'partial_date_component' => $component,
                'message' => t('@component is required', array('@component' => $label)),
              );
            }
          }
          else {
            if (empty($item[$key])) {
              $errors[$field['field_name']][$langcode][$delta][] = array(
                'error' => 'partial_date_incomplete_' . $key,
                'partial_date_component' => $component,
                'message' => t('@component is required', array('@component' => $label)),
              );
            }
          }
        }
      }
    }
  }

  if ($entity_type && $entity && !$has_data && $instance['required']) {
    if (!empty($minimum_components)) {
      $errors[$field['field_name']][$langcode][0][] = array(
        'error' => 'partial_date_is_required',
        'message' => t('@label requires at least one item to be completed. The following components are required: @components', array(
            '@label' => $instance['label'],
            '@components' => implode(', ', $minimum_components),
        )),
      );
    }
    else {
      $errors[$field['field_name']][$langcode][0][] = array(
        'error' => 'partial_date_is_required',
        'message' => t('@label requires at least one item to be completed.', array('@label' => $instance['label'])),
      );
    }
  }
  // @todo - ensure that the estimates match the date.
  $estimate_options = partial_date_field_estimates($field);
return;
// TODO
  foreach ($items as $delta => $item) {
    foreach (array('from', 'to') as $position) {
      if (!$has_range && $position == 'to') {
        break;
      }

      $item = $item[$position];
      foreach (partial_date_components() as $key => $label) {
        $value = strlen($item[$key]) ? $item[$key] : FALSE;
        $estimate = strlen($item[$key . '_estimate']) ? $item[$key . '_estimate'] : FALSE;
        if ($value && $estimate) {
          list($start, $end) = explode('|', $estimate);
          $empty_start = FALSE;
          $empty_end = FALSE;
          if (!strlen($start)) {
            $start = $value;
            $empty_start = TRUE;
          }
          if (!strlen($end)) {
            $empty_end = TRUE;
            $end = $value;
          }
/**
 * Helper function to determine the best error message given that we are
 * validating against a range that may or may not have a start or ending value.
 */
function _estimates_error_message($label, $estimate_label, $start, $end) {
  $e = max(array($start, $end));

  if ($start !== FALSE && $end !== FALSE) {
    return t('%label fields do not match. %label must be greater than %start and less than %end if you select %estimate',
        array('%start' => $start, '%end' => $end, '%estimate' => $estimate_label, '%label' => $label));
  }
  elseif ($start !== FALSE) {
    return t('%label fields do not match. %label must be greater than %start if you select %estimate',
        array('%start' => $start, '%estimate' => $estimate_label, '%label' => $label));
  }
  elseif ($end !== FALSE) {
    return t('%label fields do not match. %label must be less than %end if you select %estimate',
        array('%end' => $end, '%estimate' => $estimate_label, '%label' => $label));
  }
}

          $message = FALSE;
          switch ($key) {
            case 'year':
              if ($value < $start) {
                $message = _estimates_error_message($label, $estimate_options[$key][$estimate], $start, $end);
                $message = t('%label fields do not match. %label must be greater than %start if you select %estimate',
                    array('%start' => $start, '%estimate' => $estimate_options[$key][$estimate], '%label' => $label));
              }
              elseif ($value > $end) {
                $message = t('%label fields do not match. %label must be less than %end if you select %estimate',
                    array('%end' => $end, '%estimate' => $estimate_options[$key][$estimate], '%label' => $label));
              }
              break;

            default:
              // If range is x to y && x < y, value must be between x and y
              if ($end > $start) {
                if (!($value >= $start && $value <= $end)) {
                  $message = t('%label fields do not match. %label must be between %start and %end if you select %estimate',
                      array('%start' => $start, '%estimate' => $estimate_options[$key][$estimate], '%label' => $label));
                }
              }
              // If range is x to y && x > y, value must be between be <= x and  >= y
              elseif ($end > $start) {
                if (!($value >= $start || $value <= $end)) {

                }
              }
              // For the use-case where $start == $end
              elseif ($value != $start) {

              }

              if (!($internal_match || $external_match)) {
                $message = t('%label fields do not match. %label must be greater than %start if you select %estimate',
                    array('%start' => $start, '%estimate' => $estimate_options[$key][$estimate], '%label' => $label));
              }
              elseif ($value > $end) {
                $message = t('%label fields do not match. %label must be less than %end if you select %estimate',
                    array('%end' => $end, '%estimate' => $estimate_options[$key][$estimate], '%label' => $label));
              }
          }

          if ($message) {
            $errors[$field['field_name']][$langcode][$delta][] = array(
              'error' => 'partial_date_invalid_' . $key,
              'message' => $message,
            );
          }

        }
      }
      $year;
    }
  }


  foreach ($items as $delta => $item) {
    // Validate we actually have valid year as an integer value.
    if ($message = partial_date_field_validate_year($item, 'year')) {
      $errors[$field['field_name']][$langcode][$delta][] = array(
        'error' => 'partial_date_invalid_year_estimate',
        'message' => $message,
      );
    }
    if (!empty($item['year_estimate']) && !empty($item['year'])) {
      // Search and validate the first match.
      foreach ($year_estimates as $line) {
        if ($line[0] == $item['year_estimate']) {
          break;
        }
      }
      if ($item['year'] < $line[0] || $item['year'] > $line[1]) {
        $message = t('Year fields do not match. Year must be between %start and %end if you select %label', array('%start' => $line[0], '%end' => $line[1], '%label' => $line[2]));
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'partial_date_invalid_year_estimate',
          'message' => $message,
        );
      }
    }
    if (!empty($item['year_estimate_to']) && !empty($item['year_to'])) {
      // Search and validate the first match.
      foreach ($year_estimates as $line) {
        if ($line[1] == $item['year_estimate_to']) {
          break;
        }
      }
      if ($item['year_to'] < $line[0] || $item['year_to'] > $line[1]) {
        $message = t('Year fields do not match. Year must be between %start and %end if you select %label', array('%start' => $line[0], '%end' => $line[1], '%label' => $line[2]));
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'partial_date_invalid_year_estimate_to',
          'message' => $message,
        );
      }
    }

    if (!empty($item['month_estimate']) && !empty($item['month'])) {
      // Search and validate the first match.
      foreach ($month_estimates as $line) {
        if ($line[0] == $item['month_estimate']) {
          break;
        }
      }
      if (0) {
        $message = t('Month fields do not match. Year must be between %start and %end if you select %label', array('%start' => $line[0], '%end' => $line[1], '%label' => $line[2]));
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'partial_date_invalid_year_estimate',
          'message' => $message,
        );
      }
    }
    if (!empty($item['year_estimate_to']) && !empty($item['year_to'])) {
      // Search and validate the first match.
      foreach ($year_estimates as $line) {
        if ($line[1] == $item['year_estimate_to']) {
          break;
        }
      }
      if ($item['year_to'] < $line[0] || $item['year_to'] > $line[1]) {
        $message = t('Year fields do not match. Year must be between %start and %end if you select %label', array('%start' => $line[0], '%end' => $line[1], '%label' => $line[2]));
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'partial_date_invalid_year_estimate_to',
          'message' => $message,
        );
      }
    }

    /*
    if ($item['partial_date'] != '' && !valid_partial_date_address(trim($item['partial_date']))) {
    }
    */
  }
}

/**
 * Helper for hook_field_validate() to test that the year in within range.
 */
function partial_date_field_validate_year($item, $key) {
  if (isset($item[$key]) && strlen($item[$key])) {
    $year = $item[$key];
    // Validate that it is a real integer.
    if ((string) $year === (string) (int) $year) {
      if ($year > PD2_YEAR_MIN || $year < PD2_YEAR_MAX) {
        return;
      }
    }
    return t('Year must be an integer value between %start and %end.', array('%start' => PD2_YEAR_MIN, '%end' => PD2_YEAR_MAX));
  }
}

/**
 * Implements hook_field_widget_settings_form().
 */
function _partial_date_field_widget_settings_form($field, $instance) {
  $settings = $instance['widget']['settings'];
  $has_range = strpos($field['type'], 'range');

  $form = array();

  $options = partial_date_components();

  $form['granularity'] = array('#tree' => TRUE);
  $form['granularity']['from'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Date components'),
    '#default_value' => $settings['granularity']['from'],
    '#options' => $options,
    '#attributes' => array('class' => array('container-inline')),
    '#description' => t('Select the date attributes to collect and store.'),
    '#weight' => -10,
  );
  $form['estimates'] = array('#tree' => TRUE);
  $form['estimates']['from'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Date component estimates'),
    '#default_value' => $settings['estimates']['from'],
    '#options' => $options,
    '#attributes' => array('class' => array('container-inline')),
    '#description' => t('Select the date component estimate attributes that you want to expose.'),
    '#weight' => -9,
  );
  unset($form['estimates']['from']['#options']['timezone']);

  if ($has_range) {
    $form['granularity']['to'] = $form['granularity']['from'];
    $form['granularity']['to']['#title'] = t('Date components (to date)');
    $form['granularity']['to']['#default_value'] = $settings['granularity']['to'];
    $form['granularity']['to']['#weight'] = -8;
    $form['granularity']['from']['#title'] = t('Date components (from date)');

    $form['estimates']['to'] = $form['estimates']['from'];
    $form['estimates']['to']['#title'] = t('Date component estimates (to date)');
    $form['estimates']['to']['#default_value'] = $settings['estimates']['to'];
    $form['estimates']['to']['#weight'] = -7;
    $form['estimates']['from']['#title'] = t('Date component estimates (from date)');
  }

  $tz_options = partial_date_timezone_handling_options();
  $form['tz_handling'] = array(
    '#type' => 'select',
    '#title' => t('Time zone handling'),
    '#default_value' => $settings['tz_handling'],
    '#options' => $tz_options,
    '#required' => TRUE,
    '#weight' => -6,
    '#description' => t('Select the timezone handling method for this field. Currently, this is only used to calculate the timestamp that is store in the database. This determines the sorting order when using views integration. Only %none and %date handling options will render the timezone selector to users.',
        array('%none' => $tz_options['none'], '%date' => $tz_options['date'])),
  );
  $form['increments'] = array();
  $form['increments']['minute'] = array(
    '#type' => 'select',
    '#title' => t('Minute increments'),
    '#default_value' => empty($settings['increments']['minute']) ? 1 : $settings['increments']['minute'],
    '#options' => drupal_map_assoc(array(1, 2, 5, 10, 15, 30)),
    '#required' => TRUE,
    '#weight' => -7,
  );
  $form['increments']['second'] = array(
    '#type' => 'select',
    '#title' => t('Second increments'),
    '#default_value' => empty($settings['increments']['second']) ? 1 : $settings['increments']['second'],
    '#options' => drupal_map_assoc(array(1, 2, 5, 10, 15, 30)),
    '#required' => TRUE,
    '#weight' => -7,
  );

  $form['theme_overrides'] = array('#tree' => TRUE);
  $form['theme_overrides']['txt_short'] = array(
    '#type' => 'checkbox',
    '#title' => t('Provide a textfield for collection of a short description of the date'),
    '#default_value' => $settings['theme_overrides']['txt_short'],
    '#weight' => -5,
  );
  $form['theme_overrides']['txt_long'] = array(
    '#type' => 'checkbox',
    '#title' => t('Provide a textfield for collection of a long description of the date'),
    '#default_value' => $settings['theme_overrides']['txt_long'],
    '#weight' => -4,
  );
  $form['theme_overrides']['check_approximate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Provide a checkbox to specify that the date is approximate'),
    '#default_value' => !empty($settings['theme_overrides']['check_approximate']),
    '#weight' => -3,
  );
  $form['theme_overrides']['range_inline'] = array(
    '#type' => 'checkbox',
    '#title' => t('Theme range widgets to be rendered inline.'),
    '#default_value' => $has_range ? !empty($settings['theme_overrides']['range_inline']) : 0,
    '#weight' => 0,
    '#access' => $has_range,
  );

  $form['hide_remove'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide the %remove checkbox', array('%remove' => t('Remove date', array(), array('context' => 'datetime')))),
    '#default_value' => !empty($settings['hide_remove']),
  );

  $form['help_txt'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Inline help'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('This provides additional help per component, or a way to override the default description text.<br/>Allowed HTML tags: @tags',
      array('@tags' => _field_filter_xss_display_allowed_tags())),
  );

  // Hide all bar current language.
  $current_langcode = LANGUAGE_NONE;
  if (!isset($settings['help_txt'])) {
    $settings['help_txt'] = array();
  }
  foreach ($settings['help_txt'] as $langcode => $values) {
    if ($current_langcode == $langcode) {
      continue;
    }
    foreach ($values as $index => $value) {
      $settings['help_txt'][$langcode][$index] = array(
        '#type' => 'value',
        '#value' => $value,
      );
    }
  }

  $help_txt = _partial_date_widget_help_text($instance, $current_langcode);
  $form['help_txt'][$current_langcode]['components'] = array(
    '#type' => 'textarea',
    '#title' => t('Date components'),
    '#default_value' => $help_txt['components'],
    '#rows' => 3,
    '#description' => t('Instructions to present under the date or date range components. No help shown by default.'),
  );
  $form['help_txt'][$current_langcode]['check_approximate'] = array(
    '#type' => 'textarea',
    '#title' => t('Date approximate checkbox'),
    '#default_value' => $help_txt['check_approximate'],
    '#rows' => 3,
    '#description' => t('Instructions to present under the approximate checkbox if used. No help shown by default.'),
  );

  $form['help_txt'][$current_langcode]['txt_short'] = array(
    '#type' => 'textarea',
    '#title' => t('Short date description'),
    '#default_value' => $help_txt['txt_short'],
    '#rows' => 3,
    '#description' => t('Instructions to present under the short date description if used. Default is %default', array('%default' => t('Short date description'))),
  );
  $form['help_txt'][$current_langcode]['txt_long'] = array(
    '#type' => 'textarea',
    '#title' => t('Long date description'),
    '#default_value' => $help_txt['txt_long'],
    '#rows' => 3,
    '#description' => t('Instructions to present under the long date description if used. Default is %default', array('%default' => t('Longer description of date'))),
  );
  $form['help_txt'][$current_langcode]['_remove'] = array(
    '#type' => 'textarea',
    '#title' => t('Remove checkbox'),
    '#default_value' => $help_txt['_remove'],
    '#rows' => 3,
    '#description' => t('Instructions to present under the remove checkbox if shown. No help shown by default.'),
  );
  return $form;
}

function _partial_date_widget_help_text($instance, $langcode = NULL) {
  if (!isset($langcode)) {
    $langcode = LANGUAGE_NONE;
  }
  $settings = $instance['widget']['settings'];
  $help_txt = array();
  if (empty($settings['help_txt'][$langcode])) {
    $help_txt = array();
  }
  else {
    $help_txt += $settings['help_txt'][$langcode];
  }
  $help_txt += array(
    'components' => '',
    'check_approximate' => '',
    'txt_short' => t('Short description of date'),
    'txt_long' => t('Longer description of date'),
    '_remove' => '',
  );

  return $help_txt;
}

function _partial_date_inline_float_css($component = TRUE) {
  global $language;
  // Language will be LANGUAGE_LTR (0) or LANGUAGE_RTL (1).
  $margin = $component ? '0.5' : '1';
  if ($language->direction) {
    return "float: right; margin-left: {$margin}em;";
  }
  else {
    return "float: left; margin-right: {$margin}em;";
  }
}
/**
 * Implements hook_field_widget_form().
 */
function _partial_date_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $base) {
  $current_langcode = LANGUAGE_NONE;
  $help_txt = _partial_date_widget_help_text($instance, $current_langcode);

  $settings = $instance['widget']['settings'];
  $has_range = strpos($field['type'], 'range');

  $inline_range_style = FALSE;
  if ($has_range && !empty($settings['theme_overrides']['range_inline'])) {
    $inline_range_style = ' style="' . _partial_date_inline_float_css(FALSE) . '"';
  }
  // Fix the title on multi-value fields.
  if (empty($base['#title'])) {
    $base['#title_display'] = 'invisible';
  }
  elseif ($field['cardinality'] == 1) {
    $base['#type'] = 'item';
  }

  if (isset($items[$delta])) {
    $value = $items[$delta];
  }
  else {
    $value = $delta == 0 && !empty($instance['default_value'][0]) ? $instance['default_value'][0] : NULL;
  }

  $estimate_options = partial_date_field_estimates($field);

  // General styles to nicely format the element inline without having to load
  // external style sheets.
  $css = variable_get('partial_date_component_field_inline_styles', _partial_date_inline_float_css());
  $css_txt = variable_get('partial_date_component_field_txt_inline_styles', 'float: left; clear: left;');

  // Correct the timezone based on the widget values.
  $tz_from = empty($value) || empty($value['from']) || empty($value['from']['timezone']) ? NULL : $value['from']['timezone'];
  $value['from']['timezone'] = partial_date_timezone_handling_correlation($tz_from, $settings['tz_handling']);

  if (!partial_date_timezone_option_is_selectable($settings['tz_handling'])) {
    unset($settings['granularity']['from']['timezone']);
    if ($has_range) {
      unset($settings['granularity']['to']['timezone']);
    }
  }

  $increments = empty($settings['increments']) ? array() : $settings['increments'];
  $base['from'] = array(
    '#type' => 'partial_datetime_element',
    '#title' => $has_range ? t('Start date') : t('Date'),
    '#title_display' => 'invisible',
    '#default_value' => $value['from'],
    '#granularity' => $settings['granularity']['from'],
    '#estimates' => $settings['estimates']['from'],
    '#estimate_options' => $estimate_options,
    '#component_styles' => $css,
    '#increments' => $increments,
  );
  if ($inline_range_style) {
    $base['from']['#attributes']['style'] = $inline_range_style;
    $base['from']['#theme_wrappers'] = array('partial_date_inline_form_element');
    $base['#theme'] = 'partial_date_range_inline_element';
  }

  if ($has_range) {
    $base['_separator'] = array(
      '#type' => 'markup',
      '#markup' => t('<div class="partial-date-separator"' . $inline_range_style . '>to</div>', array(), array('context' => 'datetime')),
    );
    // Correct the timezone based on the widget values.
    $tz_to = empty($value) || empty($value['to']) || empty($value['to']['timezone']) ? NULL : $value['to']['timezone'];
    $value['to']['timezone'] = partial_date_timezone_handling_correlation($tz_to, $settings['tz_handling']);
    $base['to'] = array(
      '#type' => 'partial_datetime_element',
      '#title' => $has_range ? t('Start date') : t('Date'),
      '#title_display' => 'invisible',
      '#default_value' => $value['to'],
      '#granularity' => $settings['granularity']['to'],
      '#estimates' => $settings['estimates']['to'],
      '#estimate_options' => $estimate_options,
      '#component_styles' => $css,
      '#increments' => $increments,
    );
    if ($inline_range_style) {
      $base['to']['#attributes']['style'] = $inline_range_style;
      $base['to']['#theme_wrappers'] = array('partial_date_inline_form_element');
    }
  }

  $base['#component_help'] = field_filter_xss($help_txt['components']);
  if (!empty($settings['theme_overrides']['check_approximate'])) {
    $base['check_approximate'] = array(
      '#type' => 'checkbox',
      '#title' => t('Approximation only', array(), array('context' => 'datetime')),
      '#default_value' => empty($value['check_approximate']) ? 0 : $value['check_approximate'],
    );
    if (!empty($help_txt['check_approximate'])) {
      $base['check_approximate']['#description'] = field_filter_xss($help_txt['check_approximate']);
    }
  }

  // Calculate these for any JScript states.
  $parents = array();
  if (!empty($base['#field_parents'])) {
    $parents = $base['#field_parents'];
  }
  elseif (!empty($base['#parents'])) {
    $parents = $base['#parents'];
  }
  // field_partial_dates[und][0][check_approximate]
  $parents[] = $field['field_name'];
  $parents[] = $langcode;

  foreach (array('txt_short', 'txt_long') as $key) {
    if (!empty($settings['theme_overrides'][$key])) {
      $description = NULL;
      if (!empty($help_txt[$key])) {
        $description = field_filter_xss($help_txt[$key]);
      }

      $base[$key] = array(
        '#type' => 'textfield',
        '#title' => $description,
        '#description' => $description,
        '#title_display' => 'invisible',
        '#default_value' => empty($value[$key]) ? '' : $value[$key],
        '#prefix' => '<div class="partial-date-' . $key . '"' . ($css_txt ? ' style="' . $css_txt . '"' : '') . '>',
        '#suffix' => '</div>',
        '#maxlength' => 255,
      );
    }
  }

  // TODO
  // Inject a couple of extra timezone options if this is the default widget.
  if (FALSE) {
    //    case '--user--':
    //    case '--site--':
  }

  $base['_remove'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove date', array(), array('context' => 'datetime')),
    '#default_value' => 0,
    '#access' => empty($settings['hide_remove']),
    '#prefix' => '<div class="partial-date-remove" ' . ($css_txt ? ' style="' . $css_txt . '"' : '') . '>',
    '#suffix' => '</div>',
  );
  if (!empty($help_txt['_remove'])) {
    $base['_remove']['#description'] = field_filter_xss($help_txt['_remove']);
  }

  $base['#prefix'] = '<div class="clearfix">';
  $base['#suffix'] = '</div>';
  return $base;
}

################################################################################
#  Field API Hooks & Helpers: Formatter                                        #
################################################################################

/**
 * Implements hook_field_formatter_info().
 */
function _partial_date_field_formatter_info() {
  $formats = array(
    'partial_date_default' => array(
      'label' => t('Default'),
      'description' => t('Display the partial date.'),
      'field types' => array('partial_date', 'partial_date_range'),
      'settings' => array(
        'format' => 'medium',
        'use_override' => 'none',
        'component_settings' => array(),
      ),
    ),
  );

  return $formats;
}

/**
 * This generates a date component based on the specified timestamp and
 * timezone. This is used for deminstrational purposes only, and may fall back
 * to the request timestamp and site timezone.
 *
 * This could throw errors if outside PHP's native date range.
 */
function partial_date_generate_date($timestamp = REQUEST_TIME, $timezone = NULL) {
  // PHP Date should handle any integer, but outside of the int range, 0 is
  // returned by intval(). On 32 bit systems this is Fri, 13 Dec 1901 20:45:54
  // and Tue, 19 Jan 2038 03:14:07 GMT
  $timestamp = intval($timestamp);
  if (!$timestamp) {
    $timestamp = REQUEST_TIME;
  }
  if (!$timezone) {
    //$timezones = partial_date_granularity_field_options('timezone');
    //$timezone = $timezones[rand(0, count($timezones) - 1)];
    $timezone = partial_date_timezone_handling_correlation('UTC', 'site');
  }
  try {
    $tz = new DateTimeZone($timezone);
    $date = new DateTime('@' . $timestamp, $tz);
    if ($date) {
      return array(
        'year' => $date->format('Y'),
        'month' => $date->format('n'),
        'day' => $date->format('j'),
        'hour' => $date->format('G'),
        'minute' => $date->format('i'),
        'second' => $date->format('s'),
        'timezone' => $timezone,
      );
    }
  }
  catch (Exception $e) {}

  return FALSE;
}

/*
Time
a  Lowercase Ante meridiem and Post meridiem  am or pm
A  Uppercase Ante meridiem and Post meridiem  AM or PM
 */

/**
 * Implements hook_field_formatter_settings_summary().
 */
function _partial_date_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $types = partial_date_format_types(TRUE);
  $txt = partial_date_txt_override_options();


  $item = partial_date_generate_date();

  $example = partial_date_render($item, $settings);

  return t('User text: %text<br />Format: %format<br /><strong>Examples:</strong><br/>%example', array(
    '%format' => $types[$settings['format']],
    '%text' => $txt[$settings['use_override']],
    '%example' => $example,
  ));
/*
            'long' => array(
      'display' => array(
        'year' => 'estimate_label',
        'month' => 'estimate_label',
        'day' => 'estimate_label',
        'hour' => 'estimate_label',
        'minute' => 'estimate_label',
        'second' => 'estimate_label',
        'timezone' => 'date_only',
      ),
      'components' => array(
        'year' => array('format' => 'Y-ce', 'weight' => 0, 'empty' => ''),
        'month' => array('format' => 'F', 'weight' => 1, 'empty' => ''),
        'day' => array('format' => 'j-S', 'weight' => 2, 'empty' => ''),
        'hour' => array('format' => 'h', 'weight' => 3, 'empty' => ''),
        'minute' => array('format' => 'i', 'weight' => 4, 'empty' => ''),
        'second' => array('format' => 's', 'weight' => 5, 'empty' => ''),
        'timezone' => array('format' => 'e', 'weight' => 6, 'empty' => ''),
        'c1' => array('value' => '', 'weight' => 7),
        'c2' => array('value' => '', 'weight' => 8),
        'c3' => array('value' => '', 'weight' => 9),
      ),
      'separator' => array(
        'date' => ' ',
        'time' => ':',
        'datetime' => ', ',
        'other' => ' ',
        'range' => '',
      ),
      'meridiem' => 1,
      'year_designation' => 'ce',
    ),


 */
}

################################################################################
#  Element Related Functions:                                                  #
################################################################################

/**
 * TODO: Validates the date type to stop dates like February 30, 2006.
 */
function _partial_date_element_validate($element) {
  if (!empty($element['#required']) && partial_date_field_is_empty($element['#value'], array('type' => $element['#type']))) {
    form_error($element, t('The %label field is required.', array('%label' => $element['#title'])));
  }

  $day = empty($element['#value']['day']) ? 1 : $element['#value']['day'];
  $month = empty($element['#value']['month']) ? 1 : $element['#value']['month'];
  $year = empty($element['#value']['year']) ? NULL : $element['#value']['year'];

  $months = partial_date_month_matrix($year);
  if (!isset($months[$month - 1])) {
    form_error($element, t('The specified month is invalid.'));
  }
  elseif ($day < 1 || $day > $months[$month - 1]) {
    form_error($element, t('The specified month is invalid.'));
  }

  if (!empty($element['#value']['hour'])) {
    if (!is_numeric($element['#value']['hour']) || $element['#value']['hour'] < 0 || $element['#value']['hour'] > 23) {
      form_error($element, t('The specified time is invalid. Hours must be a number between 0 and 23'));
    }
  }

  if (!empty($element['#value']['minute'])) {
    if (!is_numeric($element['#value']['minute']) || $element['#value']['minute'] < 0 || $element['#value']['minute'] > 59) {
      form_error($element, t('The specified time is invalid. Minutes must be a number between 0 and 59'));
    }
  }

  if (!empty($element['#value']['second'])) {
    if (!is_numeric($element['#value']['second']) || $element['#value']['second'] < 0 || $element['#value']['second'] > 59) {
      form_error($element, t('The specified time is invalid. Seconds must be a number between 0 and 59'));
    }
  }

  // Testing what removing the additional elements does...
  // Getting strange submission values.
  foreach (element_children($element) as $child) {
    unset($element[$child]);
  }

  // We could validate a time according to the daylight savings rules....
  // But this is probably overkill.
}

/**
 * Roll out a single date element.
 */
function _partial_date_element_process($element) {
  $granularity = $element['#granularity'];
  $estimates = $element['#estimates'];
  $options = $element['#estimate_options'];
  $increments = empty($element['#increments']) ? array() : $element['#increments'];
  $increments += array(
    'second' => 1,
    'minute' => 1,
  );
  $blank_option = array('' => t('N/A'));
  foreach (partial_date_components() as $key => $label) {
    if (!empty($estimates[$key]) && !empty($options[$key])) {
      $estimate_label = t('@component estimate', array('@component' => $label));
      $element[$key . '_estimate'] = array(
        '#type' => 'select',
        '#title' => $estimate_label,
        '#description' => $estimate_label,
        '#title_display' => 'invisible',
        '#value' => empty($element['#value'][$key . '_estimate']) ? '' : $element['#value'][$key . '_estimate'],
        '#attributes' => $element['#attributes'],
        '#options' => $blank_option + $options[$key],
      );
    }
    if (!empty($granularity[$key])) {
      if ($key == 'year') {
        $element[$key] = array(
          '#type' => 'textfield',
          '#title' => $label,
          '#description' => $label,
          '#title_display' => 'invisible',
          '#value' => empty($element['#value'][$key]) ? '' : $element['#value'][$key],
          '#attributes' => $element['#attributes'],
          '#required' => TRUE,
        );
        $element[$key]['#attributes']['size'] = 5;
      }
      else {
        $inc = empty($increments[$key]) ? 1 : $increments[$key];
        $element[$key] = array(
          '#type' => 'select',
          '#title' => $label,
          '#description' => $label,
          '#title_display' => 'invisible',
          '#value' => isset($element['#value'][$key]) && strlen($element['#value'][$key]) ? $element['#value'][$key] : '',
          '#attributes' => $element['#attributes'],
          '#options' => partial_date_granularity_field_options($key, $blank_option, $inc),
        );
      }
    }
  }

  $css = $element['#component_styles'];
  foreach (element_children($element) as $child) {
    if ($element[$child]['#type'] != 'value') {
      $element[$child]['#prefix'] = '<div class="partial-date-' . (str_replace('_', '-', $child)) . '" style="' . $css . '">';
      $element[$child]['#suffix'] = '</div>';
    }
  }
  return $element;
}
