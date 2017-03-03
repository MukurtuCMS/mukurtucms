(function($) {
  Drupal.behaviors.search_api_ranges = {
    attach: function(context, settings) {

      var submitTimeout = '';

      $('div.search-api-ranges-widget').each(function() {

        var widget = $(this);
        var slider = widget.find('div.range-slider');
        var rangeMin = widget.find('input[name=range-min]');
        var rangeMax = widget.find('input[name=range-max]');
        var rangeFrom = widget.find('input[name=range-from]');
        var rangeTo = widget.find('input[name=range-to]');

        var widgetId = jQuery(this).parent('div').attr('id').replace('search-api-ranges-','');
        var step = 1;
        var roundPrecision = 0;//Is not used in this file yet. Maybe in the future will needed.
        if (Drupal.settings.search_api_ranges[widgetId] && Drupal.settings.search_api_ranges[widgetId]['slider-step'])
          step = parseFloat(Drupal.settings.search_api_ranges[widgetId]['slider-step']);
        if (Drupal.settings.search_api_ranges[widgetId] && Drupal.settings.search_api_ranges[widgetId]['round-precision'])
          roundPrecision = parseFloat(Drupal.settings.search_api_ranges[widgetId]['round-precision']);
          slider.slider({
          range: true,
          animate: true,

          step: step,
          min: parseFloat(rangeMin.val()),
          max: parseFloat(rangeMax.val()),
          values: [parseFloat(rangeFrom.val()), parseFloat(rangeTo.val())],

          // on change: when clicking somewhere in the bar
          change: function(event, ui) {
            widget.find('input[name=range-from]').val(ui.values[0]);
            widget.find('input[name=range-to]').val(ui.values[1]);
          },

          // on slide: when sliding with the controls
          slide: function(event, ui) {
            widget.find('input[name=range-from]').val(ui.values[0]);
            widget.find('input[name=range-to]').val(ui.values[1]);
          }
        });

        // submit once user stops changing values
        slider.bind('slidestop', function(event, ui) {
          clearTimeout(submitTimeout);
          delaySubmit(widget);
        });

        // cancel delayed submission if user starts changing values again
        slider.bind('slide', function(event, ui) {
          clearTimeout(submitTimeout);
        });

        rangeFrom.numeric({decimal : "."});
        rangeFrom.bind('blur', function() {
          clearTimeout(submitTimeout);
          if (!isNaN(rangeFrom.val()) && rangeFrom.val() !== '') {
            var value = parseFloat(rangeFrom.val());
            if (value > parseFloat(rangeTo.val())) {
              value = parseFloat(rangeTo.val());
            }
            slider.slider("option", "values", [value, parseFloat(rangeTo.val())]);
            delaySubmit(widget);
          }
        });

        rangeTo.numeric({decimal : "."});
        rangeTo.bind('blur', function() {
          clearTimeout(submitTimeout);
          if (!isNaN(rangeTo.val()) && rangeTo.val() !== '') {
            var value = parseFloat(rangeTo.val());
            if (value < parseFloat(rangeFrom.val())) {
              value = parseFloat(rangeFrom.val());
            }
            slider.slider("option", "values", [parseFloat(rangeFrom.val()), value]);
            delaySubmit(widget);
          }
        });
      });

      function delaySubmit(widget) {
        var autoSubmitDelay = widget.find('input[name=delay]').val();
        if (autoSubmitDelay != undefined && autoSubmitDelay != 0) {
          submitTimeout = setTimeout(function() {
            widget.find('form').submit();
          }, autoSubmitDelay);
        }
      };
    }
  };
})(jQuery);
