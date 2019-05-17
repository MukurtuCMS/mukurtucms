// Fix for bootstrap help tooltip not working on select widgets.
// Taken from https://gist.github.com/m8rge/61929a6c356349bf080c
(function ($) {
  Drupal.behaviors.showTooltipForSelect2 = {
    attach: function () {
      $(".select2-container").tooltip({
        title: function () {
          return $(this).prev().attr("title");
        },
        placement: "auto"
      });
    }
  };
})(jQuery);


