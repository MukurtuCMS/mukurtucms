<?php
/**
 * @file
 * Defines the iCal Fields row style plugin, which lets users map view fields
 * to the components of the VEVENTs in the iCal feed.
 */

/**
 * A Views plugin which builds an iCal VEVENT from a views row with Fields.
 */
class date_ical_plugin_row_ical_fields extends views_plugin_row {

  /**
   * Set up the options for the row plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['date_field'] = array('default' => '');
    $options['title_field'] = array('default' => '');
    $options['description_field'] = array('default' => '');
    $options['location_field'] = array('default' => '');
    $options['additional_settings']['skip_blank_dates'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Build the form for setting the row plugin's options.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $all_field_labels = $this->display->handler->get_field_labels();
    $date_field_labels = $this->get_date_field_candidates($all_field_labels);
    $date_field_label_options = array_merge(array('first_available' => t('First populated Date field')), $date_field_labels);
    $text_field_label_options = array_merge(array('' => t('- None -')), $all_field_labels);

    $form['instructions'] = array(
      // The surrounding <div> ensures that the settings dialog expands.
      '#prefix' => '<div style="font-size: 90%">',
      '#suffix' => '</div>',
      '#markup' => t("Once you've finished setting up the fields for this View, you may want to return to this dialog to set the Date field."),
    );
    $form['date_field'] = array(
      '#type' => 'select',
      '#title' => t('Date field'),
      '#description' => t('The views field to use as the start (and possibly end) time for each event (DTSTART/DTEND).
        If you retain the default ("First populated Date field"), Date iCal will use the first non-empty Date field in the row.'),
      '#options' => $date_field_label_options,
      '#default_value' => $this->options['date_field'],
      '#required' => TRUE,
    );
    $form['title_field'] = array(
      '#type' => 'select',
      '#title' => t('Title field'),
      '#description' => t('The views field to use as the title for each event (SUMMARY).'),
      '#options' => $text_field_label_options,
      '#default_value' => $this->options['title_field'],
      '#required' => FALSE,
    );
    $form['description_field'] = array(
      '#type' => 'select',
      '#title' => t('Description field'),
      '#description' => t("The views field to use as the body text for each event (DESCRIPTION).<br>
          If you wish to include more than one entity field in the event body, you may want to use the 'Content: Rendered Node' views field,
          and set it to the 'iCal' view mode. Then configure the iCal view mode on your event nodes to include the text you want."),
      '#options' => $text_field_label_options,
      '#default_value' => $this->options['description_field'],
      '#required' => FALSE,
    );
    $form['location_field'] = array(
      '#type' => 'select',
      '#title' => t('Location field'),
      '#description' => t('(optional) The views field to use as the location for each event (LOCATION).'),
      '#options' => $text_field_label_options,
      '#default_value' => $this->options['location_field'],
      '#required' => FALSE,
    );
    $form['additional_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Additional settings'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['additional_settings']['skip_blank_dates'] = array(
      '#type' => 'checkbox',
      '#title' => t('Skip blank dates'),
      '#description' => t('Normally, if a view result has a blank date field, the feed will display an error,
        because it is impossible to create an iCal event with no date. This option makes Views silently skip those results, instead.'),
      '#default_value' => $this->options['additional_settings']['skip_blank_dates'],
    );
  }

  /**
   * Set up the environment for the render() function.
   */
  public function pre_render($result) {
    // Get the language for this view.
    $this->language = $this->display->handler->get_option('field_language');
    $substitutions = views_views_query_substitutions($this->view);
    if (array_key_exists($this->language, $substitutions)) {
      $this->language = $substitutions[$this->language];
    }
    $this->repeated_dates = array();
  }

  /**
   * Returns an Event array row in the query with index: $row->index.
   */
  public function render($row) {
    $date_field_name = $this->options['date_field'];

    // If this view is set to use the first populated date field, check each
    // field in the row to find the first non-NULL Date field.
    if ($date_field_name == 'first_available') {
      foreach (get_object_vars($row) as $name => $value) {
        if (strpos($name, 'field_field') === 0) {
          // This property's name starts with "field_field", which means it's
          // the actual field data for a field in this view.
          if (!empty($value[0]['raw']['date_type'])) {
            // Cut off the first "field_" from $name to get the field name.
            $date_field_name = substr($name, 6);
            break;
          }
        }
      }
    }

    // Fetch the event's date information.
    try {
      if ($date_field_name == 'first_available') {
        // If $date_field_name is still 'first_available' at this point, we
        // couldn't find an available Date value. Processing cannot proceed.
        $title = strip_tags($this->view->style_plugin->get_field($row->index, $this->options['title_field']));
        if (empty($title)) {
          $title = "Undetermined title";
        }
        throw new BlankDateFieldException(t("The row titled %title has no available Date value. An iCal entry cannot be created for it.", array('%title' => $title)));
      }
      $date = $this->get_row_date($row, $date_field_name);
    }
    catch (BlankDateFieldException $e) {
      // Unless the user has specifically said that they want to skip rows
      // with blank dates, let this exception percolate.
      if ($this->options['additional_settings']['skip_blank_dates']) {
        return NULL;
      }
      else {
        throw $e;
      }
    }

    // Create the event by starting with the date array from this row.
    $event = $date;

    $entity = $row->_field_data[$this->view->base_field]['entity'];
    $entity_type = $row->_field_data[$this->view->base_field]['entity_type'];
    // Add the CREATED, LAST-MODIFIED, and URL components based on the entity.
    // According to the iCal standard, CREATED and LAST-MODIFIED must be UTC.
    // Fortunately, Drupal stores timestamps in the DB as UTC, so we just need
    // to specify that UTC be used rather than the server's local timezone.
    if (isset($entity->created)) {
      $event['created'] = new DateObject($entity->created, 'UTC');
    }
    if (isset($entity->changed)) {
      $event['last-modified'] = new DateObject($entity->changed, 'UTC');
    }
    elseif (isset($entity->created)) {
      // If changed is unset, but created is, use that for last-modified.
      $event['last-modified'] = new DateObject($entity->created, 'UTC');
    }
    $uri = entity_uri($entity_type, $entity);
    $uri['options']['absolute'] = TRUE;
    $event['url'] = url($uri['path'], $uri['options']);

    // Generate a unique ID for this event by emulating the way the Date module
    // creates a Date ID.
    if (isset($row->{"field_data_{$date_field_name}_delta"})) {
      $date_field_delta = $row->{"field_data_{$date_field_name}_delta"};
    }
    else {
      // I'm not sure why the "field_data_{field_name}_delta" field is part of
      // the $row, so it's possible that it will sometimes be missing. If it
      // is, make an educated guess about the delta by comparing this row's
      // start date to each of the entity's dates.
      $date_field_delta = 0;
      foreach ($entity->{$date_field_name}['und'] as $ndx => $date_array) {
        if ($date['start']->originalTime == $date_array['value']) {
          $date_field_delta = $ndx;
          break;
        }
      }
    }
    $entity_id = $row->{$this->view->base_field};
    global $base_url;
    $domain = preg_replace('#^https?://#', '', $base_url);
    $event['uid'] = "calendar.$entity_id.$date_field_name.$date_field_delta@$domain";

    // Because of the way that Date implements repeating dates, we're going to
    // be given a separate view result for each repeat. We only want to
    // render a VEVENT (with an RRULE) for the first instance of that date, so
    // we need to record the entity ID and field name for each result that has
    // an RRULE, then skip any that we've already seen.
    if (!empty($date['rrule'])) {
      $repeat_id = "$entity_id.$date_field_name";
      if (!isset($this->repeated_dates[$repeat_id])) {
        $this->repeated_dates[$repeat_id] = $repeat_id;
      }
      else {
        return FALSE;
      }
    }

    // Retrieve the rendered text fields.
    $text_fields['summary'] = $this->get_field($row->index, $this->options['title_field']);
    $text_fields['description'] = $this->get_field($row->index, $this->options['description_field']);
    $text_fields['location'] = $this->get_field($row->index, $this->options['location_field']);

    // Allow other modules to alter the rendered text fields before they get
    // sanitized for iCal-compliance. This is most useful for fields of type
    // "Content: Rendered Node", which are likely to have complex HTML.
    $context = array(
      'row' => $row,
      'row_index' => $row->index,
      'language' => $this->language,
      'options' => $this->options,
    );
    drupal_alter('date_ical_export_html', $text_fields, $this->view, $context);

    // Sanitize the text fields for iCal compliance, and add them to the event.
    $event['summary'] = date_ical_sanitize_text($text_fields['summary']);
    $event['location'] = date_ical_sanitize_text($text_fields['location']);
    $event['description'] = date_ical_sanitize_text($text_fields['description']);

    // Allow other modules to alter the event object before it gets passed to
    // the style plugin to be converted into an iCal VEVENT.
    drupal_alter('date_ical_export_raw_event', $event, $this->view, $context);

    return $event;
  }

  /**
   * Returns an normalized array for the current row's datefield/timestamp.
   *
   * @param object $row
   *   The current row object.
   * @param string $date_field_name
   *   The name of the date field.
   *
   * @return array
   *   The normalized array.
   */
  protected function get_row_date($row, $date_field_name) {
    $start = NULL;
    $end   = NULL;
    $rrule = NULL;
    $delta = 0;
    $is_date_field = FALSE;

    // Fetch the date field value.
    $date_field_value = $this->view->style_plugin->get_field_value($row->index, $date_field_name);

    // Handle date fields.
    if (isset($date_field_value[$delta]) && is_array($date_field_value[$delta])) {
      $is_date_field = TRUE;
      $date_field = $date_field_value[$delta];

      $start = new DateObject($date_field['value'], $date_field['timezone_db']);
      if (!empty($date_field['value2'])) {
        $end = new DateObject($date_field['value2'], $date_field['timezone_db']);
      }
      else {
        $end = clone $start;
      }

      if (isset($date_field['rrule'])) {
        $rrule = $date_field['rrule'];
      }
    }
    elseif (is_numeric($date_field_value)) {
      // Handle timestamps, which are always in UTC.
      $start = new DateObject($date_field_value, 'UTC');
      $end   = new DateObject($date_field_value, 'UTC');
    }
    else {
      // Processing cannot proceed with a blank date value.
      $title = strip_tags($this->view->style_plugin->get_field($row->index, $this->options['title_field']));
      throw new BlankDateFieldException(t("The row %title has a blank date. An iCal entry cannot be created for it.", array('%title' => $title)));
    }

    // Set the display timezone to whichever tz is stored for this field.
    // If there isn't a stored TZ, use the site default.
    $timezone = isset($date_field['timezone']) ? $date_field['timezone'] : date_default_timezone(FALSE);
    $dtz = new DateTimeZone($timezone);
    $start->setTimezone($dtz);
    $end->setTimezone($dtz);

    $granularity = 'second';
    if ($is_date_field) {
      $granularity_settings = $this->view->field[$date_field_name]->field_info['settings']['granularity'];
      $granularity = date_granularity_precision($granularity_settings);
    }

    // Check if the start and end dates indicate that this is an All Day event.
    $all_day = date_is_all_day(
      date_format($start, DATE_FORMAT_DATETIME),
      date_format($end, DATE_FORMAT_DATETIME),
      $granularity
    );

    if ($all_day) {
      // According to RFC 2445 (clarified in RFC 5545) the DTEND value is
      // non-inclusive. When dealing with All Day values, they are DATEs rather
      // than DATETIMEs, so we need to add a day to conform to RFC.
      $end->modify("+1 day");
    }

    $date = array(
      'start' => $start,
      'end' => $end,
      'all_day' => $all_day,
      'rrule' => $rrule,
    );

    return $date;
  }

  /**
   * Filter the list of views fields down to only supported date-type fields.
   *
   * The supported date-type fields are timestamps and the three Date fields.
   *
   * @param array $view_fields
   *   An associative array like views_plugin_display::get_field_labels().
   *
   * @return array
   *   An associative array (alias => label) of date fields.
   */
  protected function get_date_field_candidates($view_fields) {
    $handlers = $this->display->handler->get_handlers('field');
    $field_candidates = array();
    // These are Date, Date (ISO format), and Date (Unix timestamp).
    $date_fields = array('datetime', 'date', 'datestamp');

    foreach ($view_fields as $alias => $label) {
      $handler_class = get_class($handlers[$alias]);
      if ($handler_class == 'views_handler_field_date'
          || ($handler_class == 'views_handler_field_field'
            && in_array($handlers[$alias]->field_info['type'], $date_fields))) {
        $field_candidates[$alias] = $label;
      }
    }
    return $field_candidates;
  }

  /**
   * Retrieves a field value from the style plugin.
   *
   * @param int $index
   *   The index count of the row
   * @param string $field_id
   *   The ID assigned to the required field in the display.
   *
   * @see views_plugin_style::get_field()
   */
  protected function get_field($index, $field_id) {
    if (empty($this->view->style_plugin) || !is_object($this->view->style_plugin) || empty($field_id)) {
      return '';
    }
    return $this->view->style_plugin->get_field($index, $field_id);
  }
}
