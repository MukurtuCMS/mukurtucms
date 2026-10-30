/**
 * FullCalendar plugin implementation.
 */
Drupal.fullcalendar.plugins.awesome = {

  /**
   * Add in FullCalendar options.
   *
   * @param fullcalendar
   *   The fullcalendar object.
   *
   * @see http://arshaw.com/fullcalendar/docs
   */
  options: function (fullcalendar) {
    var settings = Drupal.settings.fullcalendar[fullcalendar.dom_id].awesome;
    var options = $.extend(
      {
        theme: false,
        minTime: 9,
        maxTime: 17
      },
      settings
    );
    return options;
  },

  /**
   * Respond to a jQuery UI draggable event being dropped onto the calendar.
   *
   * @param date
   *   The JavaScript Date object of where the event was dropped.
   * @param allDay
   *   A Boolean of where the event was dropped, TRUE for an all-day cell, or
   *   FALSE for a slot with a specific time.
   * @param jsEvent
   *   The primitive JavaScript event, with information like mouse coordinates.
   * @param ui
   *   The jQuery UI information.
   * @param object
   *   The DOM element that has been dropped.
   * @param fullcalendar
   *   The fullcalendar object.
   */
  drop: function (date, allDay, jsEvent, ui, object, fullcalendar) {
    var eventObject = $.extend({}, $(object).data('eventObject'));
    eventObject.start = date;
    eventObject.allDay = allDay ? 1 : 0;

    fullcalendar.$calendar.find('.fullcalendar').fullCalendar('renderEvent', eventObject, true);
  }
};
