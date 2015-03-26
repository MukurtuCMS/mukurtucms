// $Id$
(function ($) {
  Drupal.behaviors.initMukurtuSplash = {
    attach: function (context, settings) {

      $('.interlink').click(function(){
        tabSelect = $(this).attr("href").substr(6,$(this).attr("href").length);
        $("#tabs").tabs({'active': tabSelect-1});
      });

      $('.mukurtu-splash-link', context).click(function() {
        setTimeout($.colorbox.close, 2000);
      });
      // Set cookie that the user has already seen the prealpha message.
      document.cookie = 'prealpha_seen=1';
    }
  };
})(jQuery);
