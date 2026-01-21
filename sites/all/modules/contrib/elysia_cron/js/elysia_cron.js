(function ($) {

  Drupal.behaviors.elysiaCron = {
    attach: function (context, settings) {
      $('.ec-select').once().change(function () {
        if (this.value === 'custom') {
          var key = $(this).data('key');

          $("#_ec_select_" + key).hide();
          $("#_ec_custom_" + key).show();
        }
      });
    }
  }

})(jQuery);
