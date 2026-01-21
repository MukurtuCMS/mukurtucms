(function ($) {

Drupal.fullcalendar.fullcalendar.prototype.dateChange = function (fields) {
  var view = this.$calendar.find('.fullcalendar').fullCalendar('getView');
  if (!this.toggle && view.name != 'month') {
    var name = view.name;
    this.toggle = true;
    var fullcalendar = this.$calendar.find('.fullcalendar').fullCalendar('changeView', 'month');
  }

  if (view.name == 'month') {
    var min = $.fullCalendar.formatDate(view.visStart, 'yyyy-MM-dd');
    var max = $.fullCalendar.formatDate(view.visEnd, 'yyyy-MM-dd');
    for (var i in fields) {
      this.$calendar.find('.views-widget-filter-' + i).hide();
      this.$calendar.find('#edit-' + fields[i] + '-min-date').attr('value', min);
      this.$calendar.find('#edit-' + fields[i] + '-max-date').attr('value', max);
    }
  }
  if (name) {
    this.toggle = false;
    fullcalendar.fullCalendar('changeView', name);
  }
};

Drupal.fullcalendar.fullcalendar.prototype.submitInit = function (settings) {
  var domId = this.dom_id.replace('.view-dom-id-', '');
  var ajaxView = Drupal.settings.views.ajaxViews['views_dom_id:' + domId];
  this.tm = settings.theme ? 'ui' : 'fc';
  var $submit = this.$calendar.find('.views-exposed-form .views-submit-button');
  if (this.$calendar.find('.views-exposed-widget').length == settings.fullcalendar_fields_count + 1) {
    $submit.hide();
  }
  var $submit_button = $submit.find('.form-submit');
  this.$submit = new Drupal.ajax('main', $submit_button[0], {
    event: 'fullcalendar_submit',
    url: Drupal.settings.basePath + 'fullcalendar/ajax/results/' + settings.view_name + '/' + settings.view_display + '/' + ajaxView.view_args,
    fullcalendar: this,
    submit: {dom_id: domId}
  });

  $submit_button.click($.proxy(this.fetchEvents, this));
};

Drupal.fullcalendar.fullcalendar.prototype.fetchEvents = function () {
  this.$calendar.find('.fc-button').addClass(this.tm + '-state-disabled');
  $(this.$submit.element).trigger('fullcalendar_submit');
};

Drupal.ajax.prototype.commands.fullcalendar_results_response = function (ajax, response, status) {
  ajax.element_settings.fullcalendar.refetch = true;
  ajax.element_settings.fullcalendar.$calendar
    .find('.fullcalendar-content')
      .html(response.data)
    .end()
    .find('.fullcalendar')
      .fullCalendar('refetchEvents')
      .find('.fc-button')
        .removeClass(ajax.element_settings.fullcalendar.tm + '-state-disabled')
      .end()
    .end();
};

}(jQuery));
