<?php

/**
 * @file
 * Provides extra FullCalendar configuration options.
 */

/**
 * Implements hook_fullcalendar_options_info().
 */
function fullcalendar_create_fullcalendar_options_info() {
  return array(
    'fullcalendar_create' => array(
      'name' => 'FullCalendar Create',
      'js' => TRUE,
      'css' => TRUE,
    ),
  );
}

/**
 * Implements hook_fullcalendar_options_definition().
 */
function fullcalendar_create_fullcalendar_options_definition() {
  $options['fullcalendar_create']['contains'] = array(
    'click' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
    'select' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
    'method' => array(
      'default' => 'modal',
    ),
    'node_type' => array('default' => ''),
    'date_field' => array('default' => array()),
    'days' => array(
      'default' => drupal_map_assoc(date_week_days_untranslated()),
    ),
  );
  return $options;
}

/**
 * Implements hook_fullcalendar_options_form().
 */
function fullcalendar_create_fullcalendar_options_form(&$form, &$form_state, &$view) {
  $node_type = node_type_get_names();
  $bundles = array();
  foreach ($view->view->field as $field_name => $field) {
    if (fullcalendar_field_is_date($field)) {
      foreach ($field->field_info['bundles']['node'] as $bundle) {
        $bundles[$bundle] = $node_type[$bundle];
      }
    }
  }

  $form['fullcalendar_create']['click'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add new events when clicking on a day'),
    '#default_value' => $view->options['fullcalendar_create']['click'],
    '#data_type' => 'bool',
  );
  $form['fullcalendar_create']['select'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add new events when selecting a day'),
    '#default_value' => $view->options['fullcalendar_create']['select'],
    '#data_type' => 'bool',
  );

  $dependency = array(
    'edit-style-options-fullcalendar-create-click' => array(1),
    'edit-style-options-fullcalendar-create-select' => array(1),
  );
  $form['fullcalendar_create']['method'] = array(
    '#type' => 'select',
    '#title' => t('Select prefered method of new node creation'),
    '#multiple' => FALSE,
    '#options' => array(
      'modal' => t('Modal'),
      'newwindow' => t('New window'),
      'link' => t('Link'),
    ),
    '#default_value' => $view->options['fullcalendar_create']['method'],
    '#dependency' => $dependency,
  );
  if (module_exists('overlay')) {
    $form['fullcalendar_create']['method']['#options']['overlay'] = t('Overlay');
  }
  $form['fullcalendar_create']['node_type'] = array(
    '#type' => 'select',
    '#title' => t('Select the node type to prepopulate'),
    '#options' => $bundles,
    '#default_value' => $view->options['fullcalendar_create']['node_type'],
    '#dependency' => $dependency,
  );
  $form['fullcalendar_create']['date_field'] = array(
    '#type' => 'select',
    '#title' => t('Select the date field to prepopulate'),
    '#multiple' => TRUE,
    '#options' => $view->fullcalendar_parse_fields(FALSE),
    '#default_value' => $view->options['fullcalendar_create']['date_field'],
    '#dependency' => $dependency,
  );
  $form['fullcalendar_create']['days'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allow creation of events on'),
    '#default_value' => $view->options['fullcalendar_create']['days'],
    '#options' => drupal_map_assoc(date_week_days_untranslated()),
    '#dependency' => $dependency,
  );
}

/**
 * Implements hook_fullcalendar_options_process().
 */
function fullcalendar_create_fullcalendar_options_process(&$variables, &$settings) {
  // Filter out the unselected days.
  if (!empty($settings['fullcalendar_create']['days'])) {
    $settings['fullcalendar_create']['days'] = array_filter($settings['fullcalendar_create']['days']);
  }

  if ((empty($settings['fullcalendar_create']['click']) && empty($settings['fullcalendar_create']['select'])) || !node_access('create', $settings['fullcalendar_create']['node_type'])) {
    unset($settings['fullcalendar_create']);
  }
  elseif ($settings['fullcalendar_create']['method'] == 'modal') {
    ctools_include('modal');
    ctools_modal_add_js();
  }
}
