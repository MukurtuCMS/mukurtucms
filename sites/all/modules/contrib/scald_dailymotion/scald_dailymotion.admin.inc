<?php

/**
 * @file
 * Provides admin form for DailyMotion's Scald Provider.
 */

/**
 * Defines the import settings form.
 */
function scald_dailymotion_imports_form() {
  $form = array();
  $imports = variable_get('scald_dailymotion_imports', array());
  $status = variable_get('scald_dailymotion_imports_status', array());
  $types = array('user' => t('User'), 'tag' => t('Tag'));
  if ($imports) {
    $form['imports'] = array(
      '#type' => 'fieldset',
      '#title' => t('Current imports'),
      '#tree' => TRUE,
      '#theme' => 'scald_dailymotion_imports_table',
    );
    foreach ($imports as $import) {
      $key = $import['type'] . ':' . $import['value'];
      $form['imports'][$key] = array(
        'type' => array(
          '#type' => 'select',
          '#options' => array('delete' => t('<Delete>')) + $types,
          '#default_value' => $import['type'],
        ),
        'value' => array(
          '#type' => 'textfield',
          '#default_value' => $import['value'],
          '#size' => 40,
        ),
        'options' => array(
          '#type' => 'container',
          'all' => array(
            '#type' => 'checkbox',
            '#title' => t('Import all videos'),
            '#default_value' => isset($import['options']['all']) ? $import['options']['all'] : FALSE,
          ),
        ),
      );
      if (!empty($status[$key])) {
        $form['imports'][$key]['options']['all']['#suffix'] = t('<p class="description last-video">Last video: @date</p>', array('@date' => format_date($status[$key])));
      }
    }

    $form['imports']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    );
  }

  $form['add'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add import'),
    '#collapsible' => TRUE,
    '#collapsed' => count($imports),
  );
  $form['add']['type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => $types,
  );
  $form['add']['value'] = array(
    '#type' => 'textfield',
    '#title' => t('Identifier'),
    '#description' => t("This field value meaning depends on the Type field defined above. For a <em>User</em> import, put the username whose videos you'd like to import here, for a tag import, use the tag name."),
  );
  $form['add']['options'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    'all' => array(
      '#type' => 'checkbox',
      '#title' => t('Import all videos'),
    ),
  );
  $form['add']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add this import'),
    '#submit' => array('scald_dailymotion_imports_form_add'),
  );
  return $form;
}

/**
 * Handles the submission of the form that adds a new import.
 */
function scald_dailymotion_imports_form_add($form, &$form_state) {
  $imports = variable_get('scald_dailymotion_imports', array());
  $values = $form_state['values'];
  $key = $values['type'] . '-' . $values['value'];
  $imports[$key] = array(
    'type' => $values['type'],
    'value' => $values['value'],
    'options' => $values['options'],
  );
  variable_set('scald_dailymotion_imports', $imports);
  drupal_set_message(t('Import added'));
}

/**
 * Handles the submission of the whole form.
 */
function scald_dailymotion_imports_form_submit($form, &$form_state) {
  drupal_set_message(t('The configuration options have been saved.'));
  $imports = variable_get('scald_dailymotion_imports', array());
  $status = variable_get('scald_dailymotion_imports_status', array());
  $imports_new = array();

  foreach ($form_state['values']['imports'] as $import) {
    if (!isset($import['type'])) {
      continue;
    }
    $key = $import['type'] . ':' . $import['value'];
    if ($import['type'] != 'delete') {
      // If the option 'All' changes from disabled to enabled, then reset the
      // timestamp.
      if (empty($imports[$key]['options']['all']) && $import['options']['all']) {
        $status[$key] = 0;
      }
      $imports_new[$key] = $import;
    }
  }
  variable_set('scald_dailymotion_imports', $imports_new);
  variable_set('scald_dailymotion_imports_status', $status);
}

/**
 * Themes the current imports form.
 */
function theme_scald_dailymotion_imports_table($variables) {
  $form = $variables['form'];
  $header = array(t('Type'), t('Identifier'), t('Options'));
  $rows = array();
  foreach (element_children($form) as $key) {
    if (!isset($form[$key]['type'])) {
      continue;
    }

    $rows[] = array(
      'data' => array(
        drupal_render($form[$key]['type']),
        drupal_render($form[$key]['value']),
        drupal_render($form[$key]['options']),
      ),
    );
  }
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'scald-dailymotion-imports'),
  ));
  $output .= '<div class="description">' . t('By default, only import the most recently @count videos. If <em>Import all videos</em> is checked, then import all videos starting from the oldest ones, @count videos per cron run.', array('@count' => SCALD_DAILYMOTION_MAX_ITEMS)) . '</div>';
  $output .= drupal_render_children($form);
  return $output;
}
