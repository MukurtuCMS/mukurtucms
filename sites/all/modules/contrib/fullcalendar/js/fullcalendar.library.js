/**
 * @file
 * Provides FullCalendar defaults and functions.
 */

(function ($) {

Drupal.fullcalendar = Drupal.fullcalendar || {};
Drupal.fullcalendar.plugins = Drupal.fullcalendar.plugins || {};
Drupal.fullcalendar.cache = Drupal.fullcalendar.cache || {};

// Alias old fullCalendar namespace.
Drupal.fullCalendar = Drupal.fullcalendar;

Drupal.fullcalendar.fullcalendar = function (dom_id) {
  this.dom_id = dom_id;
  this.$calendar = $(dom_id);
  this.$options = {};
  this.navigate = false;
  this.refetch = false;

  // Hide the failover display.
  this.$calendar.find('.fullcalendar-content').hide();

  // Allow other modules to overwrite options.
  var $plugins = Drupal.fullcalendar.plugins;
  for (var i = 0; i < Drupal.settings.fullcalendar[dom_id].weights.length; i++) {
    var $plugin = Drupal.settings.fullcalendar[dom_id].weights[i];
    if ($plugins.hasOwnProperty($plugin) && $.isFunction($plugins[$plugin].options)) {
      $.extend(this.$options, $plugins[$plugin].options(this, Drupal.settings.fullcalendar[this.dom_id]));
    }
  }

  this.$calendar.find('.fullcalendar').once().fullCalendar(this.$options);

  $(this.$calendar).delegate('.fullcalendar-status-close', 'click', function () {
    $(this).parent().slideUp();
    return false;
  });
}

Drupal.fullcalendar.fullcalendar.prototype.update = function (result) {
  var fcStatus = $(result.dom_id).find('.fullcalendar-status');
  if (fcStatus.is(':hidden')) {
    fcStatus.html(result.msg).slideDown();
  }
  else {
    fcStatus.effect('highlight');
  }
  Drupal.attachBehaviors();
  return false;
};

/**
 * Parse Drupal events from the DOM.
 */
Drupal.fullcalendar.fullcalendar.prototype.parseEvents = function (callback) {
  var events = [];
  var details = this.$calendar.find('.fullcalendar-event-details');
  for (var i = 0; i < details.length; i++) {
    var event = $(details[i]);
    events.push({
      field: event.attr('field'),
      index: event.attr('index'),
      eid: event.attr('eid'),
      entity_type: event.attr('entity_type'),
      title: event.attr('title'),
      start: event.attr('start'),
      end: event.attr('end'),
      url: event.attr('href'),
      allDay: (event.attr('allDay') === '1'),
      className: event.attr('cn'),
      editable: (event.attr('editable') === '1'),
      dom_id: this.dom_id
    });
  }
  callback(events);
};

}(jQuery));
