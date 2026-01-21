<?php

/**
 *@file
 * Page and form callbacks for handling the date format.
 */

/**
 * Implements hook_field_formatter_settings_form().
 */
function _partial_date_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();

  $element['use_override'] = array(
    '#title' => t('Use date descriptions rather than date'),
    '#type' => 'radios',
    '#default_value' => $settings['use_override'],
    '#required' => TRUE,
    '#options' => partial_date_txt_override_options(),
    '#description' => t('This setting allows date values to be replaced with user specified date descriptions, if applicable. This will use the first non-empty value.'),
  );
  $format = empty($settings['format']) ? 'short' : $settings['format'];
  $element['format'] = array(
    '#title' => t('Date format'),
    '#type' => 'select',
    '#default_value' => $format,
    '#required' => TRUE,
    '#options' => partial_date_format_types(TRUE),
    '#id' => 'partial-date-format-selector',
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'partial_date') . '/partial-date-admin.js'),
    ),
    '#description' => t('You can use any of the predefined partial date formats, (!configure), or define the custom settings for this display by choosing %custom.',
        array('%custom' => t('Custom'), '!configure' => l(t('configure'), 'admin/config/regional/date-time/partial-date-formats', array('attributes' => array('target' => '_blank'))))),
  );

  // Defaults to the short partial date format
  if (empty($settings['component_settings'])) {
    $settings['component_settings'] = partial_date_format_settings($format);
  }
  $element['component_settings'] = partial_date_type_format_elements($settings['component_settings'], $field, $instance, $view_mode);
  $element['component_settings']['#tree'] = TRUE;
  $element['component_settings']['#prefix'] = '<div id="partial-date-custom-component-settings" class="' . $format . '">';
  $element['component_settings']['#suffix'] = '</div>';

  return $element;
}

function partial_date_type_format_elements($settings, $field = NULL, $instance = NULL, $view_mode = NULL) {
  $elements['meridiem'] = array(
    '#type' => 'radios',
    '#title' => t('Ante meridiem and Post meridiem format'),
    '#options' => partial_date_meridiem_options(),
    '#default_value' => !isset($settings['meridiem']) ? 'a' : $settings['meridiem'],
  );
  $elements['year_designation'] = array(
    '#type' => 'radios',
    '#title' => t('Year designation format'),
    '#default_value' => !isset($settings['year_designation']) ? 'ce' : $settings['year_designation'],
    '#options' => partial_date_year_designation_options(),
    '#required' => TRUE,
    '#description' => t('This controls how year designation is handled: 1BC = 1BCE = -1 and 1AD = 1CE = 1.'),
  );
  $elements['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Component display'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $elements['separator'] = array(
    '#type' => 'fieldset',
    '#title' => t('Component separators'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $elements['separator']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date component separators'),
    '#maxlength' => 15,
    '#size' => 8,
    '#default_value' => !isset($settings['separator']['date']) ? ' ' : $settings['separator']['date'],
  );
  $elements['separator']['time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time component separators'),
    '#maxlength' => 15,
    '#size' => 8,
    '#default_value' => !isset($settings['separator']['time']) ? ' ' : $settings['separator']['time'],
  );
  $elements['separator']['datetime'] = array(
    '#type' => 'textfield',
    '#title' => t('Date and time separators'),
    '#size' => 8,
    '#maxlength' => 15,
    '#default_value' => !isset($settings['separator']['datetime']) ? ' ' : $settings['separator']['datetime'],
  );
  $elements['separator']['other'] = array(
    '#type' => 'textfield',
    '#title' => t('Other separators'),
    '#size' => 8,
    '#maxlength' => 15,
    '#default_value' => !isset($settings['separator']['other']) ? ' ' : $settings['separator']['other'],
  );
  $elements['separator']['range'] = array(
    '#type' => 'textfield',
    '#title' => t('Range separator'),
    '#size' => 8,
    '#maxlength' => 15,
    '#default_value' => !isset($settings['separator']['range']) ? '' : $settings['separator']['range'],
    '#description' => t('This separator is used to seperate date components in the range element. This defaults to " to " if this field is empty. Add spaces if you need spaces between the separator and the date values.'),
  );

  $custom = array('c1' => t('Custom component 1'), 'c2' => t('Custom component 2'), 'c3' => t('Custom component 3'), 'approx' => t('Approximation text'));

  foreach (partial_date_components() + $custom as $key => $label) {
    $component = $settings['components'][$key];
    $elements['components'][$key] = array(
      '#weight' => $component['weight'],
    );

    $elements['components'][$key]['label'] = array(
      '#markup' => $label,
    );
    if (in_array($key, array('c1', 'c2', 'c3', 'approx'))) {
      $elements['components'][$key]['value'] = array(
        '#type' => 'textfield',
        '#title' => $label,
        '#title_display' => 'invisible',
        '#default_value' => $component['value'],
      );
      if ($key == 'approx') {
        $elements['components'][$key]['value']['#description'] = t('Only shows if the date is flagged as approximate.');
      }
    }
    else {
      $elements['display'][$key] = array(
        '#type' => 'select',
        '#title' => t('Display source for %label', array('%label' => $label)),
        '#options' => partial_date_estimate_handling_options(),
        '#default_value' => $settings['display'][$key],
        '#required' => TRUE,
      );
      if ($key == 'timezone') {
        $options = &$elements['display'][$key]['#options'];
        $options = array_intersect_key($options, array('none' => 1, 'date_only' => 1));
      }
      $elements['components'][$key]['format'] = array(
        '#type' => 'radios',
        '#title' => t('Format for %label', array('%label' => $label)),
        '#title_display' => 'invisible',
        '#options' => partial_date_component_format_options($key),
        '#default_value' => $component['format'],
        '#required' => TRUE,
      );

      $elements['components'][$key]['empty'] = array(
        '#type' => 'textfield',
        '#title' => t('Empty text for %label', array('%label' => $label)),
        '#title_display' => 'invisible',
        '#default_value' => $component['empty'],
        '#size' => 8,
      );
    }
    $elements['components'][$key]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight for %label', array('%label' => $label)),
      '#title_display' => 'invisible',
      '#default_value' => $component['weight'],
      '#required' => TRUE,
    );
  }
  $elements['components']['#theme'] = 'partial_date_format_settings_form';

  return $elements;
}

function partial_date_format_settings_form($form, $form_state, $type, $settings = array()) {
  $types = partial_date_format_types();
  if (!isset($types[$type])) {
    drupal_access_denied();
  }

  drupal_set_title(t('Edit partial date format %format', array('%format' => $types[$type])), PASS_THROUGH);

  $settings += partial_date_format_settings($type);
  $form['partial_date_format_' . $type] = partial_date_type_format_elements($settings);
  $form['partial_date_format_' . $type]['#tree'] = TRUE;
  return system_settings_form($form);
}

function theme_partial_date_format_settings_form($variables) {
  $form = $variables['form'];

  $rows = array();
  foreach (element_children($form, TRUE) as $key) {

    $form[$key]['weight']['#attributes']['class'] = array('partial-date-format-order-weight');
    $row = array();
    $row[] = drupal_render($form[$key]['label']);
    if (in_array($key, array('c1', 'c2', 'c3', 'approx'))) {
      $row[] = array('data' => drupal_render($form[$key]['value']), 'colspan' => 2);
    }
    else {
      $row[] = drupal_render($form[$key]['format']);
      $row[] = drupal_render($form[$key]['empty']);
    }
    $row[] = drupal_render($form[$key]['weight']);

    $rows[] = array(
      'data' => $row,
      'class' => array('draggable'),
    );

  }

  $header = array(
    t('Component'),
    t('Value format'),
    t('Value empty text'),
    t('Weight'),
  );

  drupal_add_tabledrag('partial-date-format-order', 'order', 'sibling', 'partial-date-format-order-weight');
  return theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'partial-date-format-order')));
}



function partial_date_meridiem_options() {
  return array(
    'a' => t('Lowercase (am or pm)'),
    'A' => t('Uppercase (AM or PM)')
  );
}

/**
 * Returns a translated option list of supported year designations.
 */
function partial_date_year_designation_options() {
  return array(
    'sign' => t('Negative sign (-)', array(), array('context' => 'datetime')),
    'ad' => t('Anno Domini (BC/AD)', array(), array('context' => 'datetime')),
    'bc' => t('Anno Domini (BC only)', array(), array('context' => 'datetime')),
    'ce' => t('Common Era (BCE/CE)', array(), array('context' => 'datetime')),
    'bce' => t('Common Era (BCE only)', array(), array('context' => 'datetime'))
  );
}

function partial_date_estimate_handling_options() {
  return array(
    'none' => t('Hide', array(), array('context' => 'datetime')),
    'estimate_label' => t('Estimate label', array(), array('context' => 'datetime')),
    'estimate_range' => t('Estimate range', array(), array('context' => 'datetime')),
    'estimate_component' => t('Start (single or from dates) or End (to dates) of estimate range', array(), array('context' => 'datetime')),
    'date_only' => t('Date component if set', array(), array('context' => 'datetime')),
    'date_or' => t('Date component with fallback to estimate component', array(), array('context' => 'datetime')),
  );
}


// TODO: Doco in main module
function partial_date_component_format_options($component, array $additional_values = array()) {
  static $options = NULL;
  if (!isset($options)) {
    $options = array(
      'year' => array(
        'Y' => t('A full numeric representation of a year. Eg: -125, 2003', array(), array('context' => 'datetime')),
        'y' => t('A two digit representation of a year. Eg: -25, 03', array(), array('context' => 'datetime')),
        'Y-ce' => t('A full numeric representation of a year with year designation. Eg: 125BC, 125BCE or -125', array(), array('context' => 'datetime')),
        'y-ce' => t('A two digit representation of a year with year designation. Eg: 25BC, 25BCE or -25', array(), array('context' => 'datetime')),
    //        'o' => t('ISO-8601 year number.', array(), array('context' => 'datetime')),
      ),
      'month' => array(
        'F' => t('A full textual representation of a month, January through December.', array(), array('context' => 'datetime')),
        'm' => t('Numeric representation of a month, with leading zeros, 01 through 12', array(), array('context' => 'datetime')),
        'M' => t('A short textual representation of a month, three letters, Jan through Dec.', array(), array('context' => 'datetime')),
        'n' => t('Numeric representation of a month, without leading zeros, 1 through 12', array(), array('context' => 'datetime')),
      ),
      'day' => array(
        'd' => t('Day of the month, 2 digits with leading zeros, 01 through 31', array(), array('context' => 'datetime')),
        'j' => t('Day of the month without leading zeros, 1 through 31.', array(), array('context' => 'datetime')),
        'd-S' => t('Day of the month, 2 digits with leading zeros with English ordinal suffix.', array(), array('context' => 'datetime')),
        'j-S' => t('Day of the month without leading zeros with English ordinal suffix.', array(), array('context' => 'datetime')),
        // 'z' => t('The day of the year (starting from 0).', array(), array('context' => 'datetime')),
        'l' => t('A full textual representation of the day of the week.', array(), array('context' => 'datetime')),
        'D' => t('A textual representation of a day, three letters.', array(), array('context' => 'datetime')),
        // 'N' => t('ISO-8601 numeric representation of the day of the week.', array(), array('context' => 'datetime')),
        // 'S' => t('English ordinal suffix for the day of the month.', array(), array('context' => 'datetime')),
        'w' => t('Numeric representation of the day of the week  0 (for Sunday) through 6 (for Saturday).', array(), array('context' => 'datetime')),
      ),
      'hour' => array(
        'g' => t('12-hour format of an hour without leading zeros, 1 through 12.', array(), array('context' => 'datetime')),
        'G' => t('24-hour format of an hour without leading zeros, 0 through 23.', array(), array('context' => 'datetime')),
        'h' => t('12-hour format of an hour with leading zeros, 01 through 12.', array(), array('context' => 'datetime')),
        'H' => t('24-hour format of an hour with leading zeros, 00 through 23.', array(), array('context' => 'datetime')),
      ),
      'minute' => array(
        'i' => t('Minutes with leading zeros, 00 through 59.', array(), array('context' => 'datetime')),
      ),
      'second' => array(
        's' => t('Seconds, with leading zeros, 00 through 59.', array(), array('context' => 'datetime')),
        //'B' => t('Swatch Internet time.', array(), array('context' => 'datetime')),
      ),
      'timezone' => array(
        'e' => t('Timezone identifier. Eg: UTC, GMT, Atlantic/Azores.', array(), array('context' => 'datetime')),
        'T' => t('Timezone abbreviation. Eg: EST, MDT', array(), array('context' => 'datetime')),
        // 'I' => t('Whether or not the date is in daylight saving time.', array(), array('context' => 'datetime')),
        // 'O' => t('Difference to Greenwich time (GMT) in hours. Eg: +0200', array(), array('context' => 'datetime')),
        // 'P' => t('Difference to Greenwich time (GMT) with colon between hours and minutes. Eg: +02:00', array(), array('context' => 'datetime')),
        // 'Z' => t('Timezone offset in seconds, -43200 through 50400.', array(), array('context' => 'datetime')),
      ),
    );
  }
  return $additional_values + $options[$component];
}
