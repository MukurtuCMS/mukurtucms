/**
 * @file
 * Processes the FullCalendar options and passes them to the integration.
 */

(function ($) {

Drupal.fullcalendar.plugins.fullcalendar = {
  options: function (fullcalendar, settings) {
    if (settings.ajax) {
      fullcalendar.submitInit(settings);
    }

    var options = {
      eventClick: function (calEvent, jsEvent, view) {
        if (settings.sameWindow) {
          window.open(calEvent.url, '_self');
        }
        else {
          window.open(calEvent.url);
        }
        return false;
      },
      drop: function (date, allDay, jsEvent, ui) {
        for (var $plugin in Drupal.fullcalendar.plugins) {
          if (Drupal.fullcalendar.plugins.hasOwnProperty($plugin) && $.isFunction(Drupal.fullcalendar.plugins[$plugin].drop)) {
            try {
              Drupal.fullcalendar.plugins[$plugin].drop(date, allDay, jsEvent, ui, this, fullcalendar);
            }
            catch (exception) {
              alert(exception);
            }
          }
        }
      },
      events: function (start, end, callback) {
        // Fetch new items from Views if possible.
        if (settings.ajax && settings.fullcalendar_fields) {
          fullcalendar.dateChange(settings.fullcalendar_fields);
          if (fullcalendar.navigate) {
            if (!fullcalendar.refetch) {
              fullcalendar.fetchEvents();
            }
            fullcalendar.refetch = false;
          }
        }

        fullcalendar.parseEvents(callback);

        if (!fullcalendar.navigate) {
          // Add events from Google Calendar feeds.
          for (var entry in settings.gcal) {
            if (settings.gcal.hasOwnProperty(entry)) {
              fullcalendar.$calendar.find('.fullcalendar').fullCalendar('addEventSource',
                $.fullCalendar.gcalFeed(settings.gcal[entry][0], settings.gcal[entry][1])
              );
            }
          }
        }

        // Set navigate to true which means we've starting clicking on
        // next and previous buttons if we re-enter here again.
        fullcalendar.navigate = true;
      },
      eventDrop: function (event, dayDelta, minuteDelta, allDay, revertFunc) {
        $.post(
          Drupal.settings.basePath + 'fullcalendar/ajax/update/drop/' + event.eid,
          'field=' + event.field + '&entity_type=' + event.entity_type + '&index=' + event.index + '&day_delta=' + dayDelta + '&minute_delta=' + minuteDelta + '&all_day=' + allDay + '&dom_id=' + event.dom_id,
          fullcalendar.update
        );
        return false;
      },
      eventResize: function (event, dayDelta, minuteDelta, revertFunc) {
        $.post(
          Drupal.settings.basePath + 'fullcalendar/ajax/update/resize/' + event.eid,
          'field=' + event.field + '&entity_type=' + event.entity_type + '&index=' + event.index + '&day_delta=' + dayDelta + '&minute_delta=' + minuteDelta + '&dom_id=' + event.dom_id,
          fullcalendar.update
        );
        return false;
      }
    };

    // Merge in our settings.
    $.extend(options, settings.fullcalendar);

    // Pull in overrides from URL.
    if (settings.date) {
      $.extend(options, settings.date);
    }

    return options;
  }
};

}(jQuery));
