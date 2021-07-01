<?php

/**
 * @file
 * Contains the iCal row style plugin.
 */

/**
 * A Views plugin which builds an iCal VEVENT from a single node.
 */
class date_ical_plugin_row_ical_entity extends views_plugin_row {

  // Basic properties that let the row style follow relationships.
  protected $base_table = 'node';
  protected $base_field = 'nid';

  // Stores the nodes loaded with pre_render.
  protected $entities = array();

  /**
   * Initialize the row plugin.
   */
  public function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);
    $this->base_table = $view->base_table;
    $this->base_field = $view->base_field;
  }

  /**
   * Set up the options for the row plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['date_field'] = array('default' => array());
    $options['summary_field'] = array('default' => array());
    $options['location_field'] = array('default' => array());
    return $options;
  }

  /**
   * Build the form for setting the row plugin's options.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Build the select dropdown for the Date field that the user wants to use
    // to populate the date properties in VEVENTs.
    $data = date_views_fields($this->base_table);
    $options = array();
    foreach ($data['name'] as $item => $value) {
      // We only want to see one value for each field, so we need to
      // skip '_value2' and other columns.
      if ($item == $value['fromto'][0]) {
        $options[$item] = $value['label'];
      }
    }
    $form['date_field'] = array(
      '#type' => 'select',
      '#title' => t('Date field'),
      '#options' => $options,
      '#default_value' => $this->options['date_field'],
      '#description' => t('Please identify the field to use as the iCal date for each item in this view.
          Add a Date Filter or a Date Argument to the view to limit results to content in a specified date range.'),
      '#required' => TRUE,
    );
    $form['instructions'] = array(
      // The surrounding <div> ensures that the settings dialog expands.
      '#prefix' => '<div style="font-size: 90%">',
      '#suffix' => '</div>',
      '#markup' => t("Each item's Title will be the SUMMARY and the rendered iCal view mode will be the DESCRIPTION in the VEVENTs output by this View.
        <br>To change the iCal view mode, configure it on the 'Manage Display' page for each Content Type.
        Please note that all HTML will be stripped from the output, to comply with iCal standards."),
    );

    // Build the select dropdown for the text/node_reference field that the user
    // wants to use to (optionally) populate the SUMMARY.
    $summary_fields = date_ical_get_summary_fields($this->base_table);
    $summary_options = array('default_title' => t('- Default Title -'));
    foreach ($summary_fields['name'] as $item => $value) {
      $summary_options[$item] = $value['label'];
    }
    $form['summary_field'] = array(
      '#type' => 'select',
      '#title' => t('SUMMARY field'),
      '#options' => $summary_options,
      '#default_value' => $this->options['summary_field'],
      '#description' => t('You may optionally change the SUMMARY component for each event in the iCal output.
        Choose which text, taxonomy term reference or Node Reference field you would like to be output as the SUMMARY.
        If using a Node Reference, the Title of the referenced node will be used.'),
    );

    // Build the select dropdown for the text/node_reference field that the user
    // wants to use to (optionally) populate the LOCATION.
    $location_fields = date_ical_get_location_fields($this->base_table);
    $location_options = array('none' => t('- None -'));
    foreach ($location_fields['name'] as $item => $value) {
      $location_options[$item] = $value['label'];
    }
    $form['location_field'] = array(
      '#type' => 'select',
      '#title' => t('LOCATION field'),
      '#options' => $location_options,
      '#default_value' => $this->options['location_field'],
      '#description' => t('You may optionally include a LOCATION component for each event in the iCal output.
        Choose which text or Node Reference field you would like to be output as the LOCATION.
        If using a Node Reference, the Title of the referenced node will be used.'),
    );
  }

  /**
   * Preload the list of entities which will appear in the view.
   *
   * TODO: When the date is coming in through a relationship, the nid
   * of the view is not the right node to use: we need the related node.
   * Need to sort out how that should be handled.
   */
  public function pre_render($values) {
    // Preload each entity used in this view from the cache.
    // Provides all the entity values relatively cheaply, and we don't
    // need to do it repeatedly for the same entity if there are
    // multiple results for one entity.
    $ids = array();
    foreach ($values as $row) {
      // Use the $id as the key so we create only value per entity.
      $id = $row->{$this->field_alias};

      // Node revisions need special loading.
      if ($this->view->base_table == 'node_revision') {
        $this->entities[$id] = node_load(NULL, $id);
      }
      // For other entities we just create an array of ids to pass
      // to entity_load().
      else {
        $ids[$id] = $id;
      }
    }

    $base_tables = date_views_base_tables();
    $this->entity_type = $base_tables[$this->view->base_table];
    if (!empty($ids)) {
      $this->entities = entity_load($this->entity_type, $ids);
    }

    // Get the language for this view.
    $this->language = $this->display->handler->get_option('field_language');
    $substitutions = views_views_query_substitutions($this->view);
    if (array_key_exists($this->language, $substitutions)) {
      $this->language = $substitutions[$this->language];
    }
  }

  /**
   * Renders the entities returned by the view into event arrays.
   */
  public function render($row) {
    $id = $row->{$this->field_alias};
    if (!is_numeric($id)) {
      return NULL;
    }

    // Load the specified entity:
    $entity = $this->entities[$id];
    if (empty($entity)) {
      // This can happen when an RRULE is involved.
      return NULL;
    }

    $date_fields = date_views_fields($this->base_table);
    $date_info = $date_fields['name'][$this->options['date_field']];
    $field_name  = str_replace(array('_value', '_value2'), '', $date_info['real_field_name']);
    $delta_field = $date_info['delta_field'];
    $is_field    = $date_info['is_field'];

    // Sometimes the timestamp is actually the revision timestamp.
    if ($this->view->base_table == 'node_revision' && $field_name == 'timestamp') {
      $field_name = 'revision_timestamp';
    }

    if (!isset($entity->$field_name)) {
      // This entity doesn't have the date property that the user configured
      // our view to use. We can't do anything with it.
      return NULL;
    }
    $date_field = $entity->$field_name;

    // Pull the date value from the specified field of the entity.
    $entity->date_id = array();
    $start = NULL;
    $end   = NULL;
    $delta = isset($row->$delta_field) ? $row->$delta_field : 0;
    if ($is_field) {
      $items = field_get_items($this->entity_type, $entity, $field_name);
      if (!$items) {
        // This entity doesn't have data in the date field that the user
        // configured our view to use. We can't do anything with it.
        return;
      }
      $date_field = $items[$delta];
      global $base_url;
      $domain = preg_replace('#^https?://#', '', $base_url);
      $entity->date_id[] = "calendar.$id.$field_name.$delta@$domain";

      if (!empty($date_field['value'])) {
        $start = new DateObject($date_field['value'], $date_field['timezone_db']);
        if (!empty($date_field['value2'])) {
          $end = new DateObject($date_field['value2'], $date_field['timezone_db']);
        }
        else {
          $end = clone $start;
        }
      }
    }
    elseif (!$is_field && !empty($date_field)) {
      $start = new DateObject($date_field, $date_field['timezone_db']);
      $end   = new DateObject($date_field, $date_field['timezone_db']);
    }

    // Set the item date to the proper display timezone.
    $start->setTimezone(new DateTimeZone($date_field['timezone']));
    $end->setTimezone(new DateTimeZone($date_field['timezone']));

    // Check if the start and end dates indicate that this is an All Day event.
    $all_day = date_is_all_day(
      date_format($start, DATE_FORMAT_DATETIME),
      date_format($end, DATE_FORMAT_DATETIME),
      date_granularity_precision($date_info['granularity'])
    );

    if ($all_day) {
      // According to RFC 2445 (clarified in RFC 5545) the DTEND value is
      // non-inclusive. When dealing with All Day values, they're DATEs rather
      // than DATETIMEs, so we need to add a day to conform to RFC.
      $end->modify("+1 day");
    }

    // If the user specified a LOCATION field, pull that data from the entity.
    $location = '';
    if (!empty($this->options['location_field']) && $this->options['location_field'] != 'none') {
      $location_fields = date_ical_get_location_fields($this->base_table);
      $location_info = $location_fields['name'][$this->options['location_field']];
      $location_field_name = $location_info['real_field_name'];

      // Only attempt this is the entity actually has this field.
      $items = field_get_items($this->entity_type, $entity, $location_field_name);
      if ($items) {
        $location_field = $items[0];
        if ($location_info['type'] == 'node_reference') {
          // Make sure this Node Reference actually references a node.
          if ($location_field['nid']) {
            $node = node_load($location_field['nid']);
            $location = $node->title;
          }
        }
        elseif ($location_info['type'] == 'addressfield') {
          $locations = array();
          // Get full country name
          if (!empty($location_field['country'])) {
            require_once DRUPAL_ROOT . '/includes/locale.inc';
            $countries = country_get_list();
            $location_field['country'] = $countries[$location_field['country']];
          }
          foreach ($location_field as $key => $loc) {
            if ($loc && !in_array($key, array('first_name', 'last_name'))) {
              $locations[] = $loc;
            }
          }
          $location = implode(', ', array_reverse($locations));
        }
        elseif ($location_info['type'] == 'location') {
          $included_fields = array(
            'name',
            'additional',
            'street',
            'city',
            'province_name',
            'postal_code',
            'country_name'
          );
          $location_data = array();
          foreach ($included_fields as $included_field) {
            if (!empty($location_field[$included_field])) {
              $location_data[] = $location_field[$included_field];
            }
          }
          $location = implode(', ', $location_data);
        }
        elseif ($location_info['type'] == 'node_reference') {
        // Make sure this Node Reference actually references a node.
          if ($location_field['nid']) {
            $node = node_load($location_field['nid']);
            $location = $node->title;
          }
        }
        elseif ($location_info['type'] == 'taxonomy_term_reference') {
          $terms = taxonomy_term_load_multiple(array_column($items,'tid'));
          // Make sure that there are terms that were loaded.
          if ($terms) {
            $term_names = array();
            foreach ($terms as $term) {
              $term_names[] = $term->name;
            }
            $location = implode(', ', $term_names);
          }
        }
        else {
          $location = $location_field['value'];
        }
      }
    }

    // Create the rendered event using the display settings from the
    // iCal view mode.
    $rendered_array = entity_view($this->entity_type, array($entity), 'ical', $this->language, TRUE);
    $data = array(
      'description' => drupal_render($rendered_array),
      'summary' => entity_label($this->entity_type, $entity),
    );
    if (!empty($this->options['summary_field']) && $this->options['summary_field'] != 'default_title') {
      $summary_fields = date_ical_get_summary_fields();
      $summary_info = $summary_fields['name'][$this->options['summary_field']];
      $summary_field_name = $summary_info['real_field_name'];
      // Only attempt this is the entity actually has this field.
      $items = field_get_items($this->entity_type, $entity, $summary_field_name);
      $summary = '';
      if ($items) {
        $summary_field = $items[0];
        if ($summary_info['type'] == 'node_reference') {
          // Make sure this Node Reference actually references a node.
          if ($summary_field['nid']) {
            $node = node_load($summary_field['nid']);
            $summary = $node->title;
          }
        }
        elseif ($summary_info['type'] == 'taxonomy_term_reference') {
          $terms = taxonomy_term_load_multiple(array_column($items,'tid'));
          // Make sure that there are terms that were loaded.
          if ($terms) {
            $term_names = array();
            foreach ($terms as $term) {
              $term_names[] = $term->name;
            }
            $summary = implode(', ', $term_names);
          }
        }
        else {
          $summary = trim($summary_field['value']);
        }
        $data['summary'] = $summary ? $summary : $data['summary'];
      }
    }
    // Allow other modules to alter the HTML of the Summary and Description,
    // before it gets converted to iCal-compliant plaintext. This allows users
    // to set up a newline between fields, for instance.
    $context = array(
      'entity' => $entity,
      'entity_type' => $this->entity_type,
      'language' => $this->language,
    );
    drupal_alter('date_ical_export_html', $data, $this->view, $context);

    $event = array();
    $event['summary'] = date_ical_sanitize_text($data['summary']);
    $event['description'] = date_ical_sanitize_text($data['description']);
    $event['all_day'] = $all_day;
    $event['start'] = $start;
    $event['end'] = $end;
    $uri = entity_uri($this->entity_type, $entity);
    $uri['options']['absolute'] = TRUE;
    $event['url'] = url($uri['path'], $uri['options']);
    if ($is_field && !empty($date_field['rrule'])) {
      $event['rrule'] = $date_field['rrule'];
    }
    if ($location) {
      $event['location'] = date_ical_sanitize_text($location);
    }

    // For this event's UID, use either the date_id generated by the Date
    // module, or the event page's URL if the date_id isn't available.
    $event['uid'] = !empty($entity->date_id) ? $entity->date_id[0] : $event['url'];

    // If we are using a repeat rule (and not just multi-day events) we
    // remove the item from the entities list so that its VEVENT won't be
    // re-created.
    if (!empty($event['rrule'])) {
      $this->entities[$id] = NULL;
    }

    // According to the iCal standard, CREATED and LAST-MODIFIED must be UTC.
    // Fortunately, Drupal stores timestamps in the DB as UTC, so we just need
    // to tell DateObject to treat the timestamp as UTC from the start.
    if (isset($entity->created)) {
      $event['created'] = new DateObject($entity->created, 'UTC');
    }
    // Pull the 'changed' date from the entity (if available), so that
    // subscription clients can tell if the event has been updated.
    if (isset($entity->changed)) {
      $event['last-modified'] = new DateObject($entity->changed, 'UTC');
    }
    elseif (isset($entity->created)) {
      // If changed is unset, but created is, use that for last-modified.
      $event['last-modified'] = new DateObject($entity->created, 'UTC');
    }

    // Allow other modules to alter the structured event object, before it gets
    // passed to the style plugin to be converted into an iCalcreator vevent.
    drupal_alter('date_ical_export_raw_event', $event, $this->view, $context);

    return $event;
  }
}
