<?php

/**
 * @file
 * Contains the FullCalendar style plugin.
 */

class fullcalendar_plugin_style_fullcalendar extends views_plugin_style {

  /**
   * Check if there are no results behaviors set.
   */
  function even_empty() {
    return empty($this->view->empty) ? !empty($this->definition['even empty']) : FALSE;
  }

  /**
   * Map old setting names to new ones.
   * @todo Remove in 7.x-2.1.
   */
  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);

    if (!empty($options)) {

      // Set up a rename map from the old names to new names.
      $rename_map = array(
        'times' => array(
          'fc_default_date' => 'default_date',
          'fc_date' => 'date',
          'fc_timeformat' => 'timeformat',
        ),
        'header' => array(
          'fc_left' => 'left',
          'fc_center' => 'center',
          'fc_right' => 'right',
        ),
        'modules' => array(
          'fc_theme' => 'theme',
          'fc_window' => 'sameWindow',
          'fc_url_colorbox' => 'colorbox',
          'fc_url_colorbox_class' => 'colorboxClass',
          'fc_url_colorbox_height' => 'colorboxHeight',
          'fc_url_colorbox_width' => 'colorboxWidth',
        ),
        'display' => array(
          'fc_view' => 'defaultView',
          'fc_firstday' => 'firstDay',
          'fc_weekmode' => 'weekMode',
          'fc_content_height' => 'contentHeight',
        ),
      );

      $new_options = array();
      foreach ($options as $grouping => $option) {
        if (!isset($rename_map[$grouping])) {
          continue;
        }
        foreach ($rename_map[$grouping] as $old_option => $new_option) {
          if (!isset($options[$grouping][$old_option])) {
            continue;
          }

          // All new settings aren't nested, except date and default_date.
          if ($grouping == 'times' && in_array($old_option, array('fc_default_date', 'fc_date'))) {
            $new_options[$grouping][$new_option] = $options[$grouping][$old_option];
          }
          else {
            $new_options[$new_option] = $options[$grouping][$old_option];
          }
        }
      }

      // Set out new variable for later usage.
      $this->time = empty($options['times']['fc_clock']) ? '12' : '24';

      // Add new options to defaults.
      $this->unpack_options($this->options, array_filter($new_options));

      // Unset the obsolete settings.
      unset($this->options['display']);
      unset($this->options['modules']);
      unset($this->options['header']);
      unset($this->options['times']['fc_clock']);
      unset($this->options['times']['fc_date']);
      unset($this->options['times']['fc_default_date']);
      unset($this->options['times']['fc_timeformat']);
    }

    // Move Colorbox settings into their own array.
    $options = $this->options;
    if (isset($options['colorbox']) && !is_array($options['colorbox'])) {
      $colorbox = array();
      foreach ($options as $key => $value) {
        if (substr($key, 0, 8) == 'colorbox') {
          $colorbox[$key] = $value;
          unset($options[$key]);
        }
      }
      $options['colorbox'] = $colorbox;
      $this->unpack_options($this->options, $options);
    }
  }

  function option_definition() {
    // Load all FullCalendar options and merge in their form info.
    fullcalendar_include_api();
    return module_invoke_all('fullcalendar_options_definition');
  }

  function options_form(&$form, &$form_state) {
    // Load all FullCalendar options and merge in their form info.
    fullcalendar_include_api();
    $fullcalendar_options = module_invoke_all('fullcalendar_options_info');
    uasort($fullcalendar_options, 'drupal_sort_weight');
    if (!empty($fullcalendar_options)) {
      $arguments = array(&$form, &$form_state, &$this);
      // Create a separate fieldset for each module.
      foreach (array_intersect(array_keys($fullcalendar_options), module_implements('fullcalendar_options_form')) as $module) {
        if (empty($fullcalendar_options[$module]['no_fieldset'])) {
          $form[$module] = array(
            '#type' => 'fieldset',
            '#title' => t('@module options', array('@module' => $fullcalendar_options[$module]['name'])),
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            '#attributes' => array('class' => array($module)),
          );
        }
        $function = $module . '_fullcalendar_options_form';
        call_user_func_array($function, $arguments);
      }
    }
  }

  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);

    // If an option was defined with #data_type, cast the value to that.
    if (is_array($form_state['values']['style_options'])) {
      $this->fullcalendar_cast_nested_value($form_state['values']['style_options'], $form);
    }

    fullcalendar_include_api();
    $arguments = array(&$form, &$form_state, &$this);
    foreach (module_implements('fullcalendar_options_validate') as $module) {
      $function = $module . '_fullcalendar_options_validate';
      call_user_func_array($function, $arguments);
    }
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    fullcalendar_include_api();
    $arguments = array(&$form, &$form_state, $this);
    foreach (module_implements('fullcalendar_options_submit') as $module) {
      $function = $module . '_fullcalendar_options_submit';
      call_user_func_array($function, $arguments);
    }
  }

  function validate() {
    if ($this->display->display_plugin != 'default') {
      // Get the date fields.
      $date_fields = $this->fullcalendar_parse_fields();
      if (empty($date_fields)) {
        drupal_set_message(t('Display "@display" requires at least one date field.', array('@display' => $this->display->display_title)), 'error');
      }
    }

    return parent::validate();
  }

  function fullcalendar_parse_fields($include_gcal = TRUE) {
    // Ensure the handlers are there.
    $this->view->init_handlers();

    $labels = $this->display->handler->get_field_labels();
    $date_fields = array();
    foreach ($this->view->field as $id => $field) {
      if (fullcalendar_field_is_date($field, $include_gcal)) {
        $date_fields[$id] = $labels[$id];
      }
    }
    return $date_fields;
  }

  /**
   * If #data_type is defined, use that as the type for casting the value.
   *
   * @param array $values
   *   An array of View option form values.
   * @param array $form
   *   The Views option form definition.
   * @param string $current_key
   *   The current key being processed.
   * @param array $parents
   *   An array of parent keys when recursing through the nested array.
   */
  function fullcalendar_cast_nested_value(&$values, $form, $current_key = NULL, $parents = array()) {
    foreach ($values as $key => &$value) {
      // We are leaving a recursive loop, remove the last parent key.
      if (empty($current_key)) {
        array_pop($parents);
      }

      // In case we recurse into an array, or need to specify the key for
      // drupal_array_get_nested_value(), add the current key to $parents.
      $parents[] = $key;

      if (is_array($value)) {
        // Enter another recursive loop.
        $this->fullcalendar_cast_nested_value($value, $form, $key, $parents);
      }
      else {
        // Get the form definition for this key.
        $form_value = drupal_array_get_nested_value($form, $parents);
        // Check to see if #data_type is specified, if so, cast the value.
        if (isset($form_value['#data_type'])) {
          settype($value, $form_value['#data_type']);
        }
        // Remove the current key from $parents to move on to the next key.
        array_pop($parents);
      }
    }
  }
}
