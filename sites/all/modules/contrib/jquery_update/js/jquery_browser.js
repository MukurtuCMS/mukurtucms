/**
 * Workaround for deprecated $.browser which was removed in jQuery 1.9
 * @see https://api.jquery.com/jquery.browser/
 */
(function ($) {
  if ($.browser===undefined) {
    $.browser={};
    $.browser.msie=false;
    $.browser.version=0;
    if (navigator.userAgent.match(/MSIE ([0-9]+)\./)) {
      $.browser.msie=true;
      $.browser.version=RegExp.$1;
    }
  }
})(jQuery);
