<?php

/**
 * @file
 * Hooks provided by the FullCalendar module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Constructs CSS classes for an entity.
 *
 * @param object $entity
 *   Object representing the entity.
 *
 * @return array
 *   Array of CSS classes.
 */
function hook_fullcalendar_classes($entity) {
  // Add the entity type as a class.
  return array(
    $entity->entity_type,
  );
}

/**
 * Alter the CSS classes for an entity.
 *
 * @param array $classes
 *   Array of CSS classes.
 * @param object $entity
 *   Object representing the entity.
 */
function hook_fullcalendar_classes_alter(&$classes, $entity) {
  // Remove all classes set by modules.
  $classes = array();
}

/**
 * Declare that you provide a droppable callback.
 *
 * Implementing this hook will cause a checkbox to appear on the view settings,
 * when checked FullCalendar will search for JS callbacks in the form
 * Drupal.fullcalendar.droppableCallbacks.MODULENAME.callback.
 *
 * @see http://arshaw.com/fullcalendar/docs/dropping/droppable
 */
function hook_fullcalendar_droppable() {
  // This hook will never be executed.
  return TRUE;
}

/**
 * Allows your module to affect the editability of the calendar.
 *
 * If any module implementing this hook returns FALSE, the value will be set to
 * FALSE. Use hook_fullcalendar_editable_alter() to override this if necessary.
 *
 * @param object $entity
 *   Object representing the entity.
 * @param object $view
 *   Object representing the view.
 *
 * @return bool
 *   A Boolean value dictating whether of not the calendar is editable.
 */
function hook_fullcalendar_editable($entity, $view) {
  return _fullcalendar_update_access($entity);
}

/**
 * Allows your module to forcibly override the editability of the calendar.
 *
 * @param bool $editable
 *   A Boolean value dictating whether of not the calendar is editable.
 * @param object $entity
 *   Object representing the entity.
 * @param object $view
 *   Object representing the view.
 */
function hook_fullcalendar_editable_alter(&$editable, $entity, $view) {
  $editable = FALSE;
}

/**
 * Alter the dates after they're loaded, before they're added for rendering.
 *
 * @param object $date1
 *   The start date object.
 * @param object $date2
 *   The end date object.
 * @param array $context
 *   An associative array containing the following key-value pairs:
 *   - instance: The field instance.
 *   - entity: The entity object for this date.
 *   - field: The field info.
 */
function hook_fullcalendar_process_dates_alter(&$date1, &$date2, $context) {
  // Always display dates only on one day.
  if ($date1->format(DATE_FORMAT_DATE) != $date2->format(DATE_FORMAT_DATE)) {
    $date2 = $date1;
  }
}

/**
 * Defines the location of your FullCalendar API includes.
 *
 * @return array
 *   An associative array containing the following key-value pairs:
 *   - api: The version of the FullCalendar API your module implements.
 *   - path: The location of your MODULENAME.fullcalendar.inc files.
 */
function hook_fullcalendar_api() {
  return array(
    'api' => fullcalendar_api_version(),
    'path' => drupal_get_path('module', 'MODULENAME') . '/includes',
  );
}

/**
 * Declares your FullCalendar configuration extender.
 *
 * @return array
 *   An associative array, keyed by your module's machine name, containing an
 *   associative array with the following key-value pairs:
 *   - name: The translated name of your module.
 *   - parent: (optional) The machine name of your module if you are providing
 *     functionality on behalf of another module.
 *   - css: (optional) TRUE if the module provides a CSS file.
 *   - js: (optional) TRUE if the module provides a JS file.
 *   - weight: (optional) A number defining the order in which the includes are
 *     processed and added to the form.
 *   - no_fieldset: (optional) TRUE if the module provides its own fieldset.
 */
function hook_fullcalendar_options_info() {
  // Colorbox integration is currently provided by fullcalendar_options, and it
  // provides a JS file.
  return array(
    'colorbox' => array(
      'name' => t('Colorbox'),
      'js' => TRUE,
      'parent' => 'fullcalendar_options',
    ),
  );
}

/**
 * Return an array to be added to FullCalendar's Views option definition.
 *
 * @return array
 *   An associative array in the form expected by Views option_definition().
 *   For usage in this context, it will generally be an associative array keyed
 *   by the module name, containing an associative array with the key
 *   'contains', which contains an associative array with the following
 *   key-value pairs:
 *   - default: The default value for this item.
 *   - bool: (optional) Whether or not the value is a Boolean.
 *
 * @see views_object::option_definition()
 */
function hook_fullcalendar_options_definition() {
  $options['colorbox']['contains'] = array(
    'colorbox' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
    'colorboxIFrame' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
    'colorboxClass' => array('default' => '#content'),
    'colorboxWidth' => array('default' => '80%'),
    'colorboxHeight' => array('default' => '80%'),
  );
  return $options;
}

/**
 * Return an array to be added to FullCalendar's Views options form.
 *
 * @param array $form
 *   The FullCalendar style plugin options form structure.
 * @param array $form_state
 *   The FullCalendar style plugin options form state.
 * @param object $view
 *   The FullCalendar view object.
 *
 * @see views_object::options_form()
 */
function hook_fullcalendar_options_form(&$form, &$form_state, &$view) {
  $form['colorbox']['colorbox'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open events with Colorbox'),
    '#default_value' => $view->options['colorbox']['colorbox'],
  );
  $form['colorbox']['colorboxIFrame'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open events in iFrame'),
    '#default_value' => $view->options['colorbox']['colorboxIFrame'],
  );
  $form['colorbox']['colorboxClass'] = array(
    '#type' => 'textfield',
    '#title' => t('Classname or ID selector'),
    '#default_value' => $view->options['colorbox']['colorboxClass'],
  );
  $form['colorbox']['colorboxWidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $view->options['colorbox']['colorboxWidth'],
  );
  $form['colorbox']['colorboxHeight'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => $view->options['colorbox']['colorboxHeight'],
  );

  $form['sameWindow']['#dependency'] = array('edit-style-options-colorbox-colorbox' => array(0));
}

/**
 * Allows validation of the FullCalendar Views options form.
 *
 * @param array $form
 *   The FullCalendar style plugin options form structure.
 * @param array $form_state
 *   The FullCalendar style plugin options form state.
 * @param object $view
 *   The FullCalendar view object.
 *
 * @see views_object::options_validate()
 */
function hook_fullcalendar_options_validate(&$form, &$form_state, &$view) {
  if (!is_numeric($form_state['values']['style_options']['example']['number'])) {
    form_error($form['example']['number'], t('!setting must be numeric.', array('setting' => 'Number')));
  }
}

/**
 * Allows custom submission handling for the FullCalendar Views options form.
 *
 * @param array $form
 *   The FullCalendar style plugin options form structure.
 * @param array $form_state
 *   The FullCalendar style plugin options form state.
 * @param object $view
 *   The FullCalendar view object.
 *
 * @see views_object::options_submit()
 */
function hook_fullcalendar_options_submit($form, &$form_state, $view) {
  $options = &$form_state['values']['style_options'];
  unset($options['my_unwanted_setting']);
}

/**
 * Allow any modules to have access to the view after the query is run.
 *
 * @param array $variables
 *   The variables array, containing the view object.
 * @param array $settings
 *   An array of settings to be passed to JavaScript.
 */
function hook_fullcalendar_options_process(&$variables, &$settings) {
  $view = &$variables['view'];
  $view->my_setting = TRUE;
}

/**
 * Allow any modules to have access to the view before the query is run.
 *
 * @param array $settings
 *   An array of settings to be passed to JavaScript.
 * @param object $view
 *   The FullCalendar view object.
 */
function hook_fullcalendar_options_pre_view(&$settings, &$view) {
  $settings['my_setting'] = array(
    'my_other_setting' => $settings['my_other_setting'],
    'my_another_setting' => $settings['my_another_setting'],
  );
}

/**
 * @} End of "addtogroup hooks".
 */
