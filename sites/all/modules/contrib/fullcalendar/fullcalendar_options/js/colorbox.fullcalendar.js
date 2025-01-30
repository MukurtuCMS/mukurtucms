(function($) {

Drupal.fullcalendar.plugins.colorbox = {
  options: function (fullcalendar, settings) {
    if (!settings.colorbox) {
      return;
    }
    settings = settings.colorbox;

    var options = {
      eventClick: function(calEvent, jsEvent, view) {
        // Use colorbox only for events based on entities
        if (calEvent.eid !== undefined) {
          // Open in colorbox if exists, else open in new window.
          if ($.colorbox) {
            var url = calEvent.url;
            if (settings.colorboxClass !== '') {
              url += ' ' + settings.colorboxClass;
            }
            $.colorbox({
              href: url,
              width: settings.colorboxWidth,
              height: settings.colorboxHeight,
              iframe: settings.colorboxIFrame === 1 ? true : false
            });
          }
        }
        return false;
      }
    };
    return options;
  }
};

}(jQuery));
