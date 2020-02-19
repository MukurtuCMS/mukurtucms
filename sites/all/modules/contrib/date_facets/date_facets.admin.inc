<?php

/**
 * @file
 * Some functions for admin part of date facets.
 */

/**
 * Implements hook_form_alter().
 */
function date_facets_form_facetapi_facet_display_form_alter(&$form, &$form_state) {
  $visibility_options = array(
    array()
  );
  foreach (date_facets_get_supported_widgets() as $widget_name) {
    $visibility_options[0][] = array('select[name="widget"]' => array('value' => $widget_name));
    $visibility_options[0][] = 'or';
  }
  // Remove last 'or' from the array.
  array_pop($visibility_options[0]);

  $form['widget']['widget_settings']['date_ranges'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configured Date Ranges'),
    '#tree' => TRUE,
    '#attributes' => array('class' => array('clearfix')),
    '#states' => array(
      'visible' => $visibility_options,
    ),
  );
  $form['widget']['widget_settings']['ranges'] = array(
    '#type' => 'container',
    '#title' => t('Configured Date Ranges'),
    '#tree' => TRUE,
    '#states' => array(
      'visible' => $visibility_options,
    ),
  );

  $facet = facetapi_facet_load($form['#facetapi']['facet']['name'], $form['#facetapi']['adapter']->getSearcher());
  $settings = $form['#facetapi']['adapter']->getFacetSettings($facet, facetapi_realm_load('block'));

  if (!isset($settings->settings['ranges'])) {
    $settings->settings['ranges'] = date_facets_default_ranges();
  }
  uasort($settings->settings['ranges'], 'drupal_sort_weight');
  foreach($settings->settings['ranges'] as $range_data) {
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['label'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => (isset($range_data['label']) ? $range_data['label'] : NULL),
      '#size' => 40,
      '#tree' => TRUE,
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['machine_name'] = array(
      '#type' => 'machine_name',
      '#default_value' => (isset($range_data['machine_name']) ? $range_data['machine_name'] : NULL),
      '#maxlength' => 20,
      '#machine_name' => array(
        'exists' => 'date_facets_date_range_exists',
        'source' => array('widget', 'widget_settings', 'ranges', $range_data['machine_name'], 'label'),
      ),
      '#tree' => TRUE,
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['date_range_start_op'] = array(
      '#prefix' => t('FROM'),
      '#type' => 'select',
      '#title' => t('Date Range'),
      '#default_value' => (isset($range_data['date_range_start_op']) ? $range_data['date_range_start_op'] : NULL),
      '#options' => array(
        'NOW' => t('today'),
        '-' => t('past'),
        '+' => t('future'),
      ),
      '#tree' => TRUE,
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['date_range_start_amount'] = array(
      '#type' => 'textfield',
      '#title' => t('Date Range'),
      '#default_value' => (isset($range_data['date_range_start_amount']) ? $range_data['date_range_start_amount'] : NULL),
      '#size' => 5,
      '#tree' => TRUE,
      '#states' => array(
        'invisible' => array(
          ':input[name*="' . $range_data['machine_name'] . '][date_range_start_op]"]' => array('value' => 'NOW'),
        ),
      ),
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['date_range_start_unit'] = array(
      '#type' => 'select',
      '#title' => t('Date Range'),
      '#default_value' => (isset($range_data['date_range_start_unit']) ? $range_data['date_range_start_unit'] : NULL),
      '#options' => array(
        'HOUR' => t('hour'),
        'DAY' => t('day'),
        'MONTH' => t('month'),
        'YEAR' => t('year'),
      ),
      '#states' => array(
        'invisible' => array(
          ':input[name*="' . $range_data['machine_name'] . '][date_range_start_op]"]' => array('value' => 'NOW'),
        ),
      ),
      '#tree' => TRUE,
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['date_range_end_op'] = array(
      '#prefix' => t('TO'),
      '#type' => 'select',
      '#title' => t('Date Range'),
      '#default_value' => (isset($range_data['date_range_end_op']) ? $range_data['date_range_end_op'] : NULL),
      '#options' => array(
        'NOW' => t('today'),
        '-' => t('past'),
        '+' => t('future'),
      ),
      '#tree' => TRUE,
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['date_range_end_amount'] = array(
      '#type' => 'textfield',
      '#title' => t('Date Range'),
      '#default_value' => (isset($range_data['date_range_end_amount']) ? $range_data['date_range_end_amount'] : NULL),
      '#size' => 5,
      '#tree' => TRUE,
      '#states' => array(
        'invisible' => array(
          ':input[name*="' . $range_data['machine_name'] . '][date_range_end_op]"]' => array('value' => 'NOW'),
        ),
      ),
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['date_range_end_unit'] = array(
      '#type' => 'select',
      '#title' => t('Date Range'),
      '#default_value' => (isset($range_data['date_range_end_unit']) ? $range_data['date_range_end_unit'] : NULL),
      '#options' => array(
        'HOUR' => t('hour'),
        'DAY' => t('day'),
        'MONTH' => t('month'),
        'YEAR' => t('year'),
      ),
      '#states' => array(
        'invisible' => array(
          ':input[name*="' . $range_data['machine_name'] . '][date_range_end_op]"]' => array('value' => 'NOW'),
        ),
      ),
      '#tree' => TRUE,
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#default_value' => (isset($range_data['weight']) ? $range_data['weight'] : NULL),
      '#delta' => 10,
      '#attributes' => array('class' => array('date-range-weight')),
      '#tree' => TRUE,
    );
    $form['widget']['widget_settings']['ranges'][$range_data['machine_name']]['delete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete'),
      '#tree' => TRUE,
    );
  }

  // Add new range if we pressed on "Add new range" button.
  if (isset($form_state['add_new_range']) && $form_state['add_new_range']) {
    $form_state['add_new_range'] = FALSE;
    // Prepare the name for temp group.
    $user_input = $form_state['input']['ranges'];
    $i = 1;
    while($i) {
      $temp_range_name = "custom$i";
      // We need only one more item OR we need more than one?
      $i = empty($user_input[$temp_range_name]) ? 0 : $i + 1;

      // Fields of the new range.
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['label'] = array(
        '#type' => 'textfield',
        '#title' => t('Label'),
        '#default_value' => isset($user_input[$temp_range_name]['label']) ? $user_input[$temp_range_name]['label'] : NULL,
        '#size' => 40,
        '#tree' => TRUE,
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['machine_name'] = array(
        '#type' => 'machine_name',
        '#maxlength' => 20,
        '#default_value' => isset($user_input[$temp_range_name]['machine_name']) ? $user_input[$temp_range_name]['machine_name'] : NULL,
        '#machine_name' => array(
          'exists' => 'date_facets_date_range_exists',
          'source' => array('widget', 'widget_settings', 'ranges', $temp_range_name, 'label'),
        ),
        '#tree' => TRUE,
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['date_range_start_op'] = array(
        '#prefix' => t('FROM'),
        '#type' => 'select',
        '#title' => t('Date Range'),
        '#default_value' => isset($user_input[$temp_range_name]['date_range_start_op']) ? $user_input[$temp_range_name]['date_range_start_op'] : NULL,
        '#options' => array(
          'NOW' => t('today'),
          '-' => t('past'),
          '+' => t('future'),
        ),
        '#tree' => TRUE,
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['date_range_start_amount'] = array(
        '#type' => 'textfield',
        '#title' => t('Date Range'),
        '#default_value' => isset($user_input[$temp_range_name]['date_range_start_amount']) ? $user_input[$temp_range_name]['date_range_start_amount'] : NULL,
        '#size' => 5,
        '#tree' => TRUE,
        '#states' => array(
          'invisible' => array(
            ':input[name*="' . $temp_range_name . '][date_range_start_op]"]' => array('value' => 'NOW'),
          ),
        ),
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['date_range_start_unit'] = array(
        '#type' => 'select',
        '#title' => t('Date Range'),
        '#default_value' => isset($user_input[$temp_range_name]['date_range_start_unit']) ? $user_input[$temp_range_name]['date_range_start_unit'] : NULL,
        '#options' => array(
          'HOUR' => t('hour'),
          'DAY' => t('day'),
          'MONTH' => t('month'),
          'YEAR' => t('year'),
        ),
        '#states' => array(
          'invisible' => array(
            ':input[name*="' . $temp_range_name . '][date_range_start_op]"]' => array('value' => 'NOW'),
          ),
        ),
        '#tree' => TRUE,
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['date_range_end_op'] = array(
        '#prefix' => t('TO'),
        '#type' => 'select',
        '#title' => t('Date Range'),
        '#default_value' => isset($user_input[$temp_range_name]['date_range_end_op']) ? $user_input[$temp_range_name]['date_range_end_op'] : NULL,
        '#options' => array(
          'NOW' => t('today'),
          '-' => t('past'),
          '+' => t('future'),
        ),
        '#tree' => TRUE,
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['date_range_end_amount'] = array(
        '#type' => 'textfield',
        '#title' => t('Date Range'),
        '#default_value' => isset($user_input[$temp_range_name]['date_range_end_amount']) ? $user_input[$temp_range_name]['date_range_end_amount'] : NULL,
        '#size' => 5,
        '#tree' => TRUE,
        '#states' => array(
          'invisible' => array(
            ':input[name*="' . $temp_range_name . '][date_range_end_op]"]' => array('value' => 'NOW'),
          ),
        ),
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['date_range_end_unit'] = array(
        '#type' => 'select',
        '#title' => t('Date Range'),
        '#default_value' => isset($user_input[$temp_range_name]['date_range_end_unit']) ? $user_input[$temp_range_name]['date_range_end_unit'] : NULL,
        '#options' => array(
          'HOUR' => t('hour'),
          'DAY' => t('day'),
          'MONTH' => t('month'),
          'YEAR' => t('year'),
        ),
        '#states' => array(
          'invisible' => array(
            ':input[name*="' . $temp_range_name . '][date_range_end_op]"]' => array('value' => 'NOW'),
          ),
        ),
        '#tree' => TRUE,
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#default_value' => isset($user_input[$temp_range_name]['weight']) ? $user_input[$temp_range_name]['weight'] : NULL,
        '#delta' => 10,
        '#attributes' => array('class' => array('date-range-weight')),
        '#tree' => TRUE,
      );
      $form['widget']['widget_settings']['ranges'][$temp_range_name]['delete'] = array(
        '#type' => 'checkbox',
        '#title' => t('Delete'),
        '#tree' => TRUE,
        '#states' => array(
          'checked' => array(
            ':input[name*="' . $temp_range_name . '][label]"]' => array('value' => ''),
          ),
        ),
      );
    }
  }

  // Button to add new range.
  $form['widget']['widget_settings']['date_ranges']['add_range'] = array(
    '#type' => 'button',
    '#executes_submit_callback' => FALSE,
    '#value' => t('Add a new date range'),
    '#limit_validation_errors' => array(),
    '#ajax' => array(
      'callback' => 'date_facets_tabledrag_form_new_range',
      'wrapper' => 'date_facets_facet_config_form',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#weight' => 10,
  );

  $form['#validate'] = empty($form['#validate']) ? array() : $form['#validate'];
  $form['#submit'] = empty($form['#submit']) ? array() : $form['#submit'];
  $form['#validate'][] = 'date_facets_tabledrag_form_validate';
  $form['#submit'][] = 'date_facets_facet_settings_form_submit';

  $form['#theme'] = 'date_facets_tabledrag_form';
  $form['#prefix'] = '<div id="date_facets_facet_config_form">';
  $form['#suffix'] = '</div>';
}

/**
 * Custom date range AJAX handler. Rebuild the entire form for now, unfortunately.
 */
function date_facets_tabledrag_form_new_range($form, &$form_state) {
  $form_state['add_new_range'] = TRUE;
  return drupal_rebuild_form($form['#form_id'], $form_state, $form);
}

/**
 * Custom date range form validation.
 */
function date_facets_tabledrag_form_validate($form, &$form_state) {
  $error = FALSE;
  $temp_error = FALSE;
  foreach ($form_state['values']['ranges'] as $range_key => $range_data) {
    if ($range_data['delete']) {
      unset($form_state['values']['ranges'][$range_key]);
      continue;
    }
    foreach (array('date_range_start', 'date_range_end') as $item) {
      // If the op is NOW, we don't need to validate an amount.
      if ($range_data[$item . '_op'] != 'NOW') {
        if (empty($range_data[$item . '_amount'])) {
          $key = $item . '_amount';
          form_set_error("ranges][$range_key][$key", t('You must enter an amount.'));
          $error = TRUE;
        }
      }
    }
    foreach (array('label', 'machine_name') as $element) {
      if (empty($range_data[$element])) {
        form_set_error("ranges][$range_key][$element", t('%item is required.', array('%item' => $element)));
        $error = TRUE;
      }
    }
    if (!$error) {
      // If there were no validation errors, we move the date range to be keyed
      // by it's machine name.
      unset($form_state['values']['ranges'][$range_key]);
      $form_state['values']['ranges'][$range_data['machine_name']] = $range_data;
    }
  }
  return !$error;
}

/**
 * Submit callback for the facet settings form.
 */
function date_facets_facet_settings_form_submit($form, $form_state) {
  if (!empty($form_state['values']['widget'])) {
    // Update i18n_strings only when one of date facets widgets is active.
    if (in_array($form_state['values']['widget'], array('date_range', 'date_range_checkboxes'))) {
      // Update the i18n string if need.
      if (function_exists('i18n_string_update')) {
        foreach ($form_state['values']['ranges'] as $key => $range) {
          $name = array('date_facets', 'facet_label', $range['machine_name'], 'label');
          i18n_string_update($name, $range['label']);
        }
      }
    }
  }
}
