(function ($) {

Drupal.fullcalendar.plugins.fullcalendar_create = {
  options: function (fullcalendar, settings) {
    if (!settings.fullcalendar_create) {
      return;
    }
    settings = settings.fullcalendar_create;

    if (Drupal.ajax !== undefined) {
      Drupal.ajax.prototype.commands.fullcalendar_create_reload = function (ajax, data, status) {
        location.reload();
      };
    };

    var submit;
    var basepath = Drupal.settings.basePath;
    var options = {};
    if (settings.select) {
      options.selectable = true;
      options.select = function (startDate, endDate, allDay, jsEvent, view) {
        if (settings.days && !settings.days[$.fullCalendar.formatDate(startDate, 'dddd')]) {
          return;
        }
        submit = {
          fullcalendar_create_start_date: $.fullCalendar.formatDate(startDate, 'u'),
          fullcalendar_create_end_date: $.fullCalendar.formatDate(endDate, 'u'),
          fullcalendar_create_date_field: settings.date_field
        };
        for (extra in Drupal.settings) {
          if (extra.match(/^fullcalendar_create_/g) != null) {
            for (arg in Drupal.settings[extra]) {
              submit[arg] = Drupal.settings[extra][arg];
            }
          }
        }

        nodeadd(settings, submit);

      };
    }
    if (settings.click) {
      options.dayClick = function (date, allDay, jsEvent, view) {
        if (settings.days && !settings.days[$.fullCalendar.formatDate(date, 'dddd')]) {
          return;
        }
        submit = {
          fullcalendar_create_start_date: $.fullCalendar.formatDate(date, 'u'),
          fullcalendar_create_date_field: settings.date_field
        };
        for (extra in Drupal.settings) {
          if (extra.match(/^fullcalendar_create_/g) != null) {
            for (arg in Drupal.settings[extra]) {
              submit[arg] = Drupal.settings[extra][arg];
            }
          }
        }

        nodeadd(settings, submit);

      };
    }

    return options;
  }
};

function nodeadd (settings, submit) {
  // Construct GET query
  var query = '?';
  for (q in submit) {
    if (q == 'fullcalendar_create_date_field') {
      // The date field needs extra care.
      for (i in submit[q]) {
        submit[q] = i;
      }
    }
    query += q + '=' + submit[q] + '&';
  }
  query = query.substring(0, query.length-1);

  switch(settings.method) {
    case 'modal':
      var ajax = new Drupal.ajax('main', fullcalendar.$calendar[0], {
        event: 'fullcalendar_create_add_select',
        url: basepath + 'fullcalendar_create/ajax/add/' + settings.node_type,
        submit: submit
      });
      $(ajax.element)
        .bind('fullcalendar_create_add_select', Drupal.CTools.Modal.clickAjaxLink)
        .trigger('fullcalendar_create_add_select');
      this.unselect();
      break;

    case 'overlay':
      Drupal.overlay.open(window.location.pathname + '#overlay=' + 'node/add/' + settings.node_type + encodeURIComponent(query).replace(/%2F/g, '/'));
      break;

    case 'newwindow':
      window.open(Drupal.settings.basePath + 'node/add/' + settings.node_type + query);
      break;

    default:
      // Mukurtu patch -- pass the calendar NID through the link to the add event form, then redirect to the current page (the CP, or if not on the CP, the calendar).
      window.location.assign('//' + window.location.host + '/node/add/' + settings.node_type + '/' + Drupal.settings.calendarNid + query + '&destination=' + Drupal.settings.getQ);
  }
}

}(jQuery));
