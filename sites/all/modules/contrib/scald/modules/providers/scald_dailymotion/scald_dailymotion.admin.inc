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
  $types = array('user' => t('User'), 'tag' => t('Tag'));
  if (count($imports)) {
    $form['imports'] = array(
      '#type' => 'fieldset',
      '#title' => t('Current imports'),
      '#tree' => TRUE,
      '#theme' => 'scald_dailymotion_imports_table',
    );
    foreach ($imports as $key => $import) {
      $form['imports'][$key] = array(
        'type' => array(
          '#type' => 'select',
          '#title' => t('Type'),
          '#options' => array('delete' => t('<Delete>')) + $types,
          '#default_value' => $import['type'],
        ),
        'value' => array(
          '#type' => 'textfield',
          '#title' => t('Identifier'),
          '#default_value' => $import['value'],
        ),
      );
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
  $imports[$key] = array('type' => $values['type'], 'value' => $values['value']);
  variable_set('scald_dailymotion_imports', $imports);
  drupal_set_message(t('Import added'));
}

/**
 * Handles the submission of the whole form.
 */
function scald_dailymotion_imports_form_submit($form, &$form_state) {
  drupal_set_message(t('The configuration options have been saved.'));
  $imports = array();
  foreach ($form_state['values']['imports'] as $key => $import) {
    if ($import['type'] != 'delete') {
      $imports[$key] = $import;
    }
  }
  variable_set('scald_dailymotion_imports', $imports);
}

/**
 * Themes the current imports form.
 */
function theme_scald_dailymotion_imports_table($variables) {
  $form = $variables['form'];
  $header = array(t('Type'), t('Identifier'));
  $rows = array();
  foreach (element_children($form) as $key) {
    $rows[] = array(
      'data' => array(
        drupal_render($form[$key]['type']),
        drupal_render($form[$key]['value']),
      ),
    );
  }
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'scald-dailymotion-imports'),
  ));
  $output .= drupal_render_children($form);
  return $output;
}
