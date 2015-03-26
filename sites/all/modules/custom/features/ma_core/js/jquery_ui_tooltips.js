// $Id$
(function ($) {
  Drupal.behaviors.initJquery_Ui_Tooltip = {
    attach: function () {

      // activate the tool tip on appropriate items
      $( '.jquery-ui-tooltip' ).tooltip();

    }
  };
})(jQuery);
