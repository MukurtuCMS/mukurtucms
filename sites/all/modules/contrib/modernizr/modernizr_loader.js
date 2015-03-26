
Drupal = Drupal || {};
Drupal.Modernizr = Drupal.Modernizr || {};
Drupal.Modernizr.hooks = Drupal.Modernizr.hooks || {};
Drupal.Modernizr.hooks.cookieSet = Drupal.Modernizr.hooks.cookieSet || {};

(function($) {
  $(function() {
    if (Drupal.settings.modernizrPath) {
      // adding the no-js class to html
      // in order to make modernizr triggered
      $('html').addClass('modernizr').addClass('no-js');
      // loading modernizr
      $.getScript(Drupal.settings.basePath + Drupal.settings.modernizrPath);
    }

    var checker = function() {
      if ($('html.no-js').length == 1) {
        setTimeout(checker, 100);
        return;
      }

      document.cookie = 'modernizr=' + escape(JSON.stringify(Modernizr)) + '; path=/';

      // invoking the hook
      for (var key in Drupal.Modernizr.hooks.cookieSet) {
        Drupal.Modernizr.hooks.cookieSet[key]();
      }
    };

    if (Drupal.settings.modernizrServerside) {
      checker();
    }
  });
})(jQuery);
