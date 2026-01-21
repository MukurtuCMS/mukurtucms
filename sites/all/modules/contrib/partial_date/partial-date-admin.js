(function ($) {

Drupal.togglePartialDateCustomSettings = function (val) {
  if (val == 'custom') {
    $('#partial-date-custom-component-settings').show();
  }
  else {
    $('#partial-date-custom-component-settings').hide();
  }
}

Drupal.behaviors.partialDateCustomFormatToogle = {
  attach: function (context, settings) {
    $('#partial-date-format-selector', context).each(function () {
      Drupal.togglePartialDateCustomSettings($(this).val());
    }).change(function () {
      Drupal.togglePartialDateCustomSettings($(this).val());
    });
  }
}

})(jQuery);
