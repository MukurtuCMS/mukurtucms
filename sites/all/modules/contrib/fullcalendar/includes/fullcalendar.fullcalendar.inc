<?php

/**
 * @file
 * Provides default FullCalendar configuration options.
 */

/**
 * Implements hook_fullcalendar_options_info().
 */
function fullcalendar_fullcalendar_options_info() {
  return array(
    'fullcalendar' => array(
      'name' => t('FullCalendar'),
      'no_fieldset' => TRUE,
      'weight' => '-20',
      'js' => TRUE,
    ),
  );
}

/**
 * Implements hook_fullcalendar_options_definition().
 */
function fullcalendar_fullcalendar_options_definition() {
  $formats = array(
    '12' => array(
      'time' => 'h:mm{ - h:mm}',
      'axis' => 'h(:mm)t',
    ),
    '24' => array(
      'time' => 'HH:mm{ - HH:mm}',
      'axis' => 'HH(:mm)',
    ),
    'mdy' => array(
      'title' => array(
        'month' => 'MMMM yyyy',
        'week' => 'MMM d[ yyyy]{ - [ MMM] d yyyy}',
        'day' => 'dddd, MMM d, yyyy',
      ),
      'column' => array(
        'month' => 'ddd',
        'week' => 'ddd M/d',
        'day' => 'dddd M/d',
      ),
    ),
    'dmy' => array(
      'title' => array(
        'month' => 'MMMM yyyy',
        'week' => 'd [ MMM][ yyyy]{ - d MMM yyyy}',
        'day' => 'dddd, d MMM, yyyy',
      ),
      'column' => array(
        'month' => 'ddd',
        'week' => 'ddd d/M',
        'day' => 'dddd d/M',
      ),
    ),
    'ymd' => array(
      'title' => array(
        'month' => 'yyyy MMMM',
        'week' => 'yyyy MMM d{ - [ yyyy][ MMM] d}',
        'day' => 'yyyy MMM d, dddd ',
      ),
      'column' => array(
        'month' => 'ddd',
        'week' => 'ddd M/d',
        'day' => 'dddd M/d',
      ),
    ),
  );

  $time = '12';
  $date = 'mdy';
  $time_format = $formats[$time];
  $date_format = $formats[$date];

  $options = array(
    'defaultView' => array('default' => 'month'),
    'firstDay' => array('default' => '0'),
    'weekMode' => array('default' => 'fixed'),
    'left' => array('default' => 'today prev,next'),
    'center' => array('default' => 'title'),
    'right' => array('default' => 'month agendaWeek agendaDay'),
    'timeformat' => array('default' => $time_format['time']),
    'advanced' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
    'axisFormat' => array('default' => $time_format['axis']),
    'timeformatMonth' => array('default' => $time_format['time']),
    'titleformatMonth' => array('default' => $date_format['title']['month']),
    'columnformatMonth' => array('default' => $date_format['column']['month']),
    'timeformatWeek' => array('default' => $time_format['time']),
    'titleformatWeek' => array('default' => $date_format['title']['week']),
    'columnformatWeek' => array('default' => $date_format['column']['week']),
    'timeformatDay' => array('default' => $time_format['time']),
    'titleformatDay' => array('default' => $date_format['title']['day']),
    'columnformatDay' => array('default' => $date_format['column']['day']),
    'theme' => array(
      'default' => TRUE,
      'bool' => TRUE,
    ),
    'sameWindow' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
    'contentHeight' => array('default' => 0),
    'droppable' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
    'editable' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
  );

  // Nest these explicitly so that they can be more easily found later.
  $options['times'] = array(
    'contains' => array(
      'default_date' => array(
        'default' => FALSE,
        'bool' => TRUE,
      ),
      'date' => array(
        'default' => array(
          'year' => '1900',
          'month' => '1',
          'day' => '1',
        ),
      ),
    ),
  );
  $options['fields'] = array(
    'contains' => array(
      'title_field' => array('default' => 'title'),
      'url_field' => array('default' => 'title'),
      'date_field' => array('default' => array()),
      'title' => array(
        'default' => FALSE,
        'bool' => TRUE,
      ),
      'url' => array(
        'default' => FALSE,
        'bool' => TRUE,
      ),
      'date' => array(
        'default' => FALSE,
        'bool' => TRUE,
      ),
    ),
  );
  return $options;
}

/**
 * Implements hook_fullcalendar_options_form().
 */
function fullcalendar_fullcalendar_options_form(&$form, &$form_state, &$view) {
  $form['#pre_render'][] = 'views_ui_pre_render_add_fieldset_markup';

  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display settings'),
    '#collapsible' => TRUE,
  );
  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header settings'),
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/display/header', array('attributes' => array('target' => '_blank'))),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['times'] = array(
    '#type' => 'fieldset',
    '#title' => t('Time/date settings'),
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/utilities/formatDate', array('attributes' => array('target' => '_blank'))),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['style'] = array(
    '#type' => 'fieldset',
    '#title' => t('Style settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['defaultView'] = array(
    '#type' => 'select',
    '#title' => t('Initial display'),
    '#options' => array(
      'month' => 'Month',
      'agendaWeek' => 'Week (Agenda)',
      'basicWeek' => 'Week (Basic)',
      'agendaDay' => 'Day (Agenda)',
      'basicDay' => 'Day (Basic)',
    ),
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/views/Available_Views', array('attributes' => array('target' => '_blank'))),
    '#default_value' => $view->options['defaultView'],
    '#prefix' => '<div class="views-left-30">',
    '#suffix' => '</div>',
    '#fieldset' => 'display',
  );
  $form['firstDay'] = array(
    '#type' => 'select',
    '#title' => t('Week starts on'),
    '#options' => date_week_days(TRUE),
    '#default_value' => $view->options['firstDay'],
    '#prefix' => '<div class="views-left-30">',
    '#suffix' => '</div>',
    '#fieldset' => 'display',
  );
  $form['weekMode'] = array(
    '#type' => 'select',
    '#title' => t('Week mode'),
    '#options' => array(
      'fixed' => 'Fixed',
      'liquid' => 'Liquid',
      'variable' => 'Variable',
    ),
    '#default_value' => $view->options['weekMode'],
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/display/weekMode', array('attributes' => array('target' => '_blank'))),
    '#prefix' => '<div class="views-left-30">',
    '#suffix' => '</div>',
    '#fieldset' => 'display',
  );
  $form['left'] = array(
    '#type' => 'textfield',
    '#title' => t('Left'),
    '#default_value' => $view->options['left'],
    '#prefix' => '<div class="views-left-30">',
    '#suffix' => '</div>',
    '#size' => '30',
    '#fieldset' => 'header',
  );
  $form['center'] = array(
    '#type' => 'textfield',
    '#title' => t('Center'),
    '#default_value' => $view->options['center'],
    '#prefix' => '<div class="views-left-30">',
    '#suffix' => '</div>',
    '#size' => '30',
    '#fieldset' => 'header',
  );
  $form['right'] = array(
    '#type' => 'textfield',
    '#title' => t('Right'),
    '#default_value' => $view->options['right'],
    '#prefix' => '<div class="views-left-30">',
    '#suffix' => '</div>',
    '#size' => '30',
    '#fieldset' => 'header',
  );
  $form['times']['default_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a custom initial date'),
    '#description' => t('If unchecked, the calendar will load the current date.'),
    '#default_value' => $view->options['times']['default_date'],
    '#data_type' => 'bool',
    '#fieldset' => 'times',
  );
  $form['times']['date'] = array(
    '#type' => 'date',
    '#title' => t('Custom initial date'),
    '#title_display' => 'invisible',
    '#default_value' => $view->options['times']['date'],
    '#dependency' => array('edit-style-options-times-default-date' => array(1)),
    '#fieldset' => 'times',
  );
  $form['timeformat'] = array(
    '#type' => 'textfield',
    '#title' => t('Time format'),
    '#default_value' => $view->options['timeformat'],
    '#size' => '30',
    '#fieldset' => 'times',
    '#dependency' => array('edit-style-options-advanced' => array(0)),
  );
  $form['advanced'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable advanced time and date format settings'),
    '#default_value' => $view->options['advanced'],
    '#data_type' => 'bool',
    '#fieldset' => 'times',
  );
  $form['axisFormat'] = array(
    '#type' => 'textfield',
    '#title' => t('Axis format'),
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/agenda/axisFormat', array('attributes' => array('target' => '_blank'))),
    '#default_value' => $view->options['axisFormat'],
    '#size' => '30',
    '#fieldset' => 'times',
    '#dependency' => array('edit-style-options-advanced' => array(1)),
  );

  // Add the nine time/date formats.
  foreach (array('time', 'title', 'column') as $type) {
    foreach (array('Month', 'Week', 'Day') as $range) {
      $key = $type . 'format' . $range;
      $form[$key] = array(
        '#type' => 'textfield',
        '#title' => t($range),
        '#default_value' => $view->options[$key],
        '#prefix' => '<div class="views-left-30">',
        '#suffix' => '</div>',
        '#size' => '30',
        '#fieldset' => $type,
      );
    }
  }

  $form['time'] = array(
    '#type' => 'fieldset',
    '#title' => t('Time format'),
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/text/timeFormat', array('attributes' => array('target' => '_blank'))),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#fieldset' => 'times',
    '#dependency' => array('edit-style-options-advanced' => array(1)),
  );
  $form['title'] = array(
    '#type' => 'fieldset',
    '#title' => t('Title format'),
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/text/titleFormat', array('attributes' => array('target' => '_blank'))),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#fieldset' => 'times',
    '#dependency' => array('edit-style-options-advanced' => array(1)),
  );
  $form['column'] = array(
    '#type' => 'fieldset',
    '#title' => t('Column format'),
    '#description' => l(t('More info'), 'http://arshaw.com/fullcalendar/docs/text/columnFormat', array('attributes' => array('target' => '_blank'))),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#fieldset' => 'times',
    '#dependency' => array('edit-style-options-advanced' => array(1)),
  );
  $form['theme'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use jQuery UI Theme'),
    '#default_value' => $view->options['theme'],
    '#data_type' => 'bool',
    '#fieldset' => 'style',
  );
  $form['sameWindow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open events in same window'),
    '#default_value' => $view->options['sameWindow'],
    '#data_type' => 'bool',
    '#fieldset' => 'style',
  );
  $form['contentHeight'] = array(
    '#type' => 'textfield',
    '#title' => t('Calendar height'),
    '#size' => 4,
    '#default_value' => $view->options['contentHeight'],
    '#field_suffix' => 'px',
    '#data_type' => 'int',
    '#fieldset' => 'style',
  );
  if (module_implements('fullcalendar_droppable')) {
    $form['droppable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow external events to be added via drag and drop'),
      '#default_value' => $view->options['droppable'],
      '#data_type' => 'bool',
      '#fieldset' => 'style',
    );
  }
  $form['editable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent editing events via drag-and-drop'),
    '#default_value' => $view->options['editable'],
    '#data_type' => 'bool',
    '#fieldset' => 'style',
    '#description' => t('Modules can set custom access rules, but this will override those.'),
  );

  // Get the regular fields.
  $field_options = $view->display->handler->get_field_labels();
  // Get the date fields.
  $date_fields = $view->fullcalendar_parse_fields();

  $form['fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Customize fields'),
    '#description' => t('Add fields to the view in order to customize fields below.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fields']['title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a custom title'),
    '#default_value' => $view->options['fields']['title'],
    '#data_type' => 'bool',
    '#fieldset' => 'fields',
  );
  $form['fields']['title_field'] = array(
    '#type' => 'select',
    '#title' => t('Title field'),
    '#options' => $field_options,
    '#default_value' => $view->options['fields']['title_field'],
    '#description' => t('Choose the field with the custom title.'),
    '#process' => array('form_process_select'),
    '#dependency' => array('edit-style-options-fields-title' => array(1)),
    '#fieldset' => 'fields',
  );
  $form['fields']['url'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a custom redirect URL'),
    '#default_value' => $view->options['fields']['url'],
    '#data_type' => 'bool',
    '#fieldset' => 'fields',
  );
  $form['fields']['url_field'] = array(
    '#type' => 'select',
    '#title' => t('URL field'),
    '#options' => $field_options,
    '#default_value' => $view->options['fields']['url_field'],
    '#description' => t('Choose the field with the custom link.'),
    '#process' => array('form_process_select'),
    '#dependency' => array('edit-style-options-fields-url' => array(1)),
    '#fieldset' => 'fields',
  );
  $form['fields']['date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a custom date field'),
    '#default_value' => $view->options['fields']['date'],
    '#data_type' => 'bool',
    '#fieldset' => 'fields',
  );
  $form['fields']['date_field'] = array(
    '#type' => 'select',
    '#title' => t('Date fields'),
    '#options' => $date_fields,
    '#default_value' => $view->options['fields']['date_field'],
    '#description' => t('Select one or more date fields.'),
    '#multiple' => TRUE,
    '#size' => count($date_fields),
    '#process' => array('form_process_select'),
    '#dependency' => array('edit-style-options-fields-date' => array(1)),
    '#fieldset' => 'fields',
  );

  // Disable form elements when not needed.
  if (empty($field_options)) {
    $form['fields']['#description'] = t('All the options are hidden, you need to add fields first.');
    $form['fields']['title']['#type'] = 'hidden';
    $form['fields']['url']['#type'] = 'hidden';
    $form['fields']['date']['#type'] = 'hidden';
    $form['fields']['title_field']['#disabled'] = TRUE;
    $form['fields']['url_field']['#disabled'] = TRUE;
    $form['fields']['date_field']['#disabled'] = TRUE;
  }
  elseif (empty($date_fields)) {
    $form['fields']['date']['#type'] = 'hidden';
    $form['fields']['date_field']['#disabled'] = TRUE;
  }
}

/**
 * Implements hook_fullcalendar_options_submit().
 */
function fullcalendar_fullcalendar_options_submit($form, &$form_state, $view) {
  $options = &$form_state['values']['style_options'];

  // These field options have empty defaults, make sure they stay that way.
  foreach (array('title', 'url', 'date') as $field) {
    if (empty($options['fields'][$field])) {
      unset($options['fields'][$field . '_field']);
    }
  }
}

/**
 * Implements hook_fullcalendar_options_process().
 */
function fullcalendar_fullcalendar_options_process(&$variables, &$settings) {
  $view = &$variables['view'];

  static $fc_dom_id = 1;
  if (empty($view->dom_id)) {
    $view->dom_id = 'fc-' . $fc_dom_id++;
  }

  $options = $view->style_plugin->options;

  $options['gcal'] = array();
  foreach ($view->field as $field) {
    if ($field->field == 'gcal') {
      $options['gcal'][] = $field->render(array());
    }
  }

  unset($options['fields']);

  $settings += $options + array(
    'view_name' => $view->name,
    'view_display' => $view->current_display,
  );

  // Add JS and CSS files.
  $variables['element']['#attached'] = array(
    'library' => array(
      array('fullcalendar', 'fullcalendar'),
    ),
    'js' => array(
      ctools_attach_js('fullcalendar.library', 'fullcalendar') => array('group' => JS_LIBRARY),
      ctools_attach_js('fullcalendar.views', 'fullcalendar') => array('weight' => 20),
    ),
    'css' => array(
      ctools_attach_css('fullcalendar.theme', 'fullcalendar'),
    ),
  );

  if (!empty($settings['ajax'])) {
    $variables['element']['#attached']['js'][] = ctools_attach_js('fullcalendar.ajax', 'fullcalendar');
  }

  // Add CSS and JS for each option plugin that provides it.
  fullcalendar_include_api();
  $weights = array();
  $delta = 0;
  foreach (module_invoke_all('fullcalendar_options_info') as $module => $info) {
    // If a weight is specified, use it.
    if (isset($info['weight']) && !isset($weights[$info['weight']])) {
      $weights[$info['weight']] = $module;
    }
    // If not, make sure there are no conflicts.
    else {
      while (isset($weights[$delta])) {
        $delta++;
      }
      $weights[$delta] = $module;
    }

    // If this function is being provided by another module, set the parent.
    $parent = isset($info['parent']) ? $info['parent'] : $module;
    if (!empty($info['js'])) {
      $variables['element']['#attached']['js'][] = ctools_attach_js("$module.fullcalendar", $parent);
    }
    if (!empty($info['css'])) {
      $variables['element']['#attached']['css'][] = ctools_attach_css("$module.fullcalendar", $parent);
    }
  }
  ksort($weights);
  $settings['weights'] = array_values($weights);
}

/**
 * Implements hook_fullcalendar_options_pre_view().
 */
function fullcalendar_fullcalendar_options_pre_view(&$settings, &$view) {
  global $language;

  if (!empty($settings['editable'])) {
    $view->fullcalendar_disallow_editable = TRUE;
  }

  $options = array(
    'buttonText' => array(
      'day' => t('Day'),
      'week' => t('Week'),
      'month' => t('Month'),
      'today' => t('Today'),
    ),
    'allDayText' => t('All day'),
    'monthNames' => array_values(date_month_names(TRUE)),
    'monthNamesShort' => array_values(date_month_names_abbr(TRUE)),
    'dayNames' => date_week_days(TRUE),
    'dayNamesShort' => date_week_days_abbr(TRUE),
    'isRTL' => (bool) $language->direction,
  );
  $advanced = !empty($settings['advanced']);
  foreach ($settings as $key => $value) {
    if (is_array($value)) {
      if ($key == 'times') {
        $settings[$key]['date']['date'] = $value['date']['day'];
        unset($settings[$key]['date']['day']);
      }
      continue;
    }
    elseif (in_array($key, array('left', 'center', 'right'))) {
      $options['header'][$key] = $value;
    }
    elseif (in_array($key, array('timeformatMonth', 'timeformatWeek', 'timeformatDay'))) {
      if ($advanced) {
        $options['timeFormat'][strtolower(substr($key, 10))] = $value;
      }
    }
    elseif (in_array($key, array('columnformatMonth', 'columnformatWeek', 'columnformatDay'))) {
      if ($advanced) {
        $options['columnFormat'][strtolower(substr($key, 12))] = $value;
      }
    }
    elseif (in_array($key, array('titleformatMonth', 'titleformatWeek', 'titleformatDay'))) {
      if ($advanced) {
        $options['titleFormat'][strtolower(substr($key, 11))] = $value;
      }
    }
    elseif ($advanced && $key == 'axisFormat') {
      $options[$key] = $value;
    }
    elseif ($key == 'timeformat') {
      if (!$advanced) {
        $options['timeFormat'] = $value;
      }
    }
    elseif ($key == 'contentHeight' && empty($value)) {
      // Don't add this if it is 0.
    }
    elseif ($key == 'advanced') {
      // Don't add this value ever.
    }
    elseif ($key == 'sameWindow') {
      // Keep this at the top level.
      continue;
    }
    else {
      $options[$key] = $value;
    }
    // Unset all values that have been migrated.
    unset($settings[$key]);
  }
  $settings['fullcalendar'] = $options;

  // First, use the default date if set.
  if (!empty($settings['times']['default_date'])) {
    $settings['date'] = $settings['times']['date'];
  }
  // Unset times settings.
  unset($settings['times']);

  // Get the values from the URL.
  extract($view->get_exposed_input(), EXTR_SKIP);
  if (isset($year) && is_numeric($year)) {
    $settings['date']['year'] = $year;
  }
  if (isset($month) && is_numeric($month) && $month > 0 && $month <= 12) {
    $settings['date']['month'] = $month;
  }
  if (isset($day) && is_numeric($day) && $day > 0 && $day <= 31) {
    $settings['date']['date'] = $day;
  }
  if (isset($mode) && in_array($mode, array('month', 'basicWeek', 'basicDay', 'agendaWeek', 'agendaDay'))) {
    $settings['date']['defaultView'] = $mode;
  }

  // Ensure that some value is set.
  if (!isset($settings['date']['year'])) {
    $settings['date']['year'] = date('Y', strtotime('now'));
  }
  if (!isset($settings['date']['month'])) {
    $settings['date']['month'] = date('n', strtotime('now'));
  }
  // Change month to zero-based.
  $settings['date']['month']--;
}
