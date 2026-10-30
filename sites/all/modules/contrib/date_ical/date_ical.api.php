<?php
/**
 * @file
 * Documentation for the hooks provided by Date iCal.
 */

/******************************************************************************
 * ALTER HOOKS FOR EXPORTED ICAL FEEDS
*****************************************************************************/

/**
 * Alter the HTML from an event's text fields before they get exported.
 *
 * Because HTML must be converted to plaintext for iCal spec compliance, this
 * hook exists to allow users to alter the original HTML to ensure that it
 * gets converted into pretty plaintext.
 *
 * <p>, <h*>, and <div> tags are changed to newlines by the plaintext converter.
 *
 * @param array $text_fields
 *   A reference to an associative array with the following keys and values:
 *   - 'description': The description field string.
 *   - 'summary': The title field string
 *   - 'location': The location field string.
 * @param object $view
 *   The view object that is being executed to render the iCal feed.
 * @param array $context
 *   Depending on whether this event is being constructed using the Fields or
 *   Entity plugins, this context array will have different keys and values.
 *
 *   Entity Plugin:
 *   - 'entity_type': The type of entity being rendered (e.g. 'node').
 *   - 'entity': The fully loaded entity being rendered.
 *   - 'language': The language code that indicates which translation of field
 *     data should be used.
 *
 *   Fields Plugin:
 *   - 'row': The full Views row object being converted to an event.
 *   - 'row_index': The index into the query results for this view.
 *   - 'language': The language code that indicates which translation of field
 *     data should be used.
 *   - 'options': The Fields plugin options.
 */
function hook_date_ical_export_html_alter(&$text_fields, $view, $context) {

}

/**
 * Modify an event's raw data.
 *
 * This hook is invoked after Date iCal has gathered all the data it will use
 * to build an event object.
 *
 * @param array $event
 *   A reference to an associative array containing the event's raw data.
 * @param object $view
 *   The view object that is being executed to render the iCal feed.
 * @param array $context
 *   Depending on whether this event is being constructed using the Fields or
 *   Entity plugins, this context array will have different keys and values.
 *
 *   Entity Plugin:
 *   - 'entity_type': The type of entity being rendered (e.g. 'node').
 *   - 'entity': The fully loaded entity being rendered.
 *   - 'language': The language code that indicates which translation of field
 *     data should be used.
 *
 *   Fields Plugin:
 *   - 'row': The full Views row object being converted to an event.
 *   - 'row_index': The index into the query results for this view.
 *   - 'language': The language code that indicates which translation of field
 *     data should be used.
 *   - 'options': The Fields plugin options.
 */
function hook_date_ical_export_raw_event_alter(&$event, $view, $context) {
  // Example: adding a comment to an event from a simple
  // textfield called 'field_comment' (using the Entity plugin).
  if ($comments = field_get_items($context['entity_type'], $context['entity'], 'field_comment', $context['language'])) {
    foreach ($comments as $comment) {
      $event['comment'] = check_plain($comment['value']);
    }
  }

  // Example: Retrieving information from additional fields in the View (using
  // the Fields plugin).
  $event['comment'] = $view->style_plugin->get_field($context['row_index'], 'field_comment');
}

/**
 * Alter an iCal representation of an event.
 *
 * This hook allows you to modify an event as it is added to the iCal calendar.
 * If Date iCal doesn't support an iCal property that you want your feed to
 * include, you can add it to the event using this hook.
 *
 * @param object $vevent
 *   A reference to an iCalcreator vevent which will be exported in this feed.
 * @param object $view
 *   The view object that is being executed to render the iCal feed.
 * @param object $event_array
 *   The array representation of the event that's been rendered to the $vevent.
 */
function hook_date_ical_export_vevent_alter(&$vevent, $view, $event_array) {

}

/**
 * Alter the iCalcreator vcalendar object before it's exported as an iCal feed.
 *
 * You can use this hook to add sections to the generated iCal feed which Date
 * iCal might not support.
 *
 * @param object $vcalendar
 *   A reference to the iCalcreator vcalendar object representing this feed.
 * @param object $view
 *   The view object that is being executed to render the iCal feed.
 */
function hook_date_ical_export_vcalendar_alter(&$vcalendar, $view) {

}

/**
 * Alter the final rendered text of an iCal feed before it gets exported.
 *
 * This is a last resort hook, allowing you to alter the output of the feed
 * in case nothing else works.
 *
 * @param string $rendered_calendar
 *   A reference to the string containing the rendered the iCal feed.
 * @param object $view
 *   The view that is being executed to render this iCal feed.
 */
function hook_date_ical_export_post_render_alter(&$rendered_calendar, $view) {

}

/******************************************************************************
 * ALTER HOOKS FOR IMPORTED ICAL FEEDS
 *****************************************************************************/

/**
 * Alter the vcalendar object imported from an iCal feed.
 *
 * @param object $calendar
 *   An instance of the iCalcreator library's vcalendar class.
 * @param array $context
 *   An associative array of context, with the following keys and values:
 *   - 'source' FeedsSource object for this Feed.
 *   - 'fetcher_result': The FeedsFetcherResult object for this Feed.
 */
function hook_date_ical_import_vcalendar_alter(&$calendar, $context) {

}

/**
 * Alter a calendar component imported from an iCal feed.
 *
 * @param object $component
 *   This will usually be an iCalcreator vevent object, but Date iCal also
 *   experimentally supports vtodo, vjournal, vfreebusy, and valarm.
 * @param array $context
 *   An associative array of context, with the following keys and values:
 *   - 'calendar': The iCalcreator vcalendar parent object of this component.
 *   - 'source': FeedsSource object for this Feed.
 *   - 'fetcher_result': The FeedsFetcherResult object for this Feed.
 */
function hook_date_ical_import_component_alter(&$component, $context) {
  // Example of what might be done with this alter hook.
  if ($component->objName == 'vevent') {
    // Do something for vevents...
  }
  elseif ($component->objName == 'valarm') {
    // Do something different for valarms...
  }
}

/**
 * Alter the parsed data for an event imported from an iCal feed.
 *
 * @param array $data
 *   An associative array of field data that represents an imported event.
 * @param array $context
 *   An associative array of context, with the following keys and values:
 *   - 'calendar': The iCalcreator vcalendar parent object of this component.
 *   - 'source': FeedsSource object for this Feed.
 *   - 'fetcher_result': The FeedsFetcherResult object for this Feed.
 */
function hook_date_ical_import_post_parse_alter(&$data, $context) {
  // Example of what might be done with this alter hook.
  if (!empty($context['calendar']->xprop['X-WR-CALNAME']['value'])) {
    // Do something with the calendar name....
  }
}

/**
 * Alter the timezone string from an imported iCal Feed.
 *
 * This is useful for when an iCal feed you're trying to import uses deprecated
 * timezone names, like "Eastern Standard Time" rather than "America/New_York",
 * or has date values with missing timezone information.
 *
 * @param string $tzid
 *   The timezone id sting to be altered (e.g. "America/Los_Angeles").
 *   If this value is NULL, not timezone id was set in the feed.
 * @param array $context
 *   An associative array of context, with the following keys and values:
 *   - 'property_key': The name of the property (e.g. DTSTART). Can be NULL.
 *   - 'calendar_component': The iCalcreator object (e.g VEVENT). Can be NULL.
 *   - 'calendar': The iCalcreater vcalendar object created from the feed.
 *   - 'feeds_source': A FeedsSource object with this feed's metadata.
 *   - 'feeds_detcher_result': The FeedsFeatcherResult for this import.
 *
 *   If property_key and calendar_component are NULL, this is the X-WR-TIMEZONE
 *   string for the entire feed.
 */
function hook_date_ical_import_timezone_alter(&$tzid, $context) {
  // Example of what might be done with this alter hook:
  if ($tzid == 'Eastern Standard Time') {
    // "Eastern Standard Time" is a deprecated tzid, which PHP doesn't accept.
    // However, it's equivalent to "America/New_York", which PHP is fine with.
    $tzid = 'America/New_York';
  }
}

/**
 * Add an additional custom source to be mapped by a feed.
 *
 * This is useful when you need to map fields from an iCal feed which
 * the Date iCal module does not currently support.
 *
 * @param array $sources
 *   An associative array containing the source's properties, as follows:
 *     name: The name that will appear in the feed importer Mapping page.
 *     description: The description of this field shown in the Mapping page.
 *     date_ical_parse_handler: The function in the ParserVcalendar class
 *       which should be used to parse this iCal property into a Drupal field.
 *
 * Available date_ical_parse_handlers are:
 *   parseTextProperty
 *   parseDateTimeProperty
 *   parseRepeatProperty
 *   parseMultivalueProperty
 *   parsePropertyParameter
 */
function hook_date_ical_mapping_sources_alter(&$sources) {
  // Example of what might be done with this alter hook:
  // Add the "ATTENDEE" iCal property to the mapping sources.
  $sources['ATTENDEE'] = array(
    'name' => t('Attendee'),
    'description' => t('The ATTENDEE property.'),
    'date_ical_parse_handler' => 'parseTextProperty',
  );
  // Add "ATTENDEE:CN" parameter to the mapping sources.
  $sources['ATTENDEE:CN'] = array(
    'name' => t('Attendee: CN'),
    'description' => t("The CN parameter of the ATTENDEE property: the attendee's Common Name."),
    'date_ical_parse_handler' => 'parsePropertyParameter',
  );
}
