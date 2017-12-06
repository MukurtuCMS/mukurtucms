// $Id$
(function ($) {
  Drupal.behaviors.initJquery_Ui_Tooltip = {
    attach: function () {
	// activate the tool tip on appropriate items
	if ($( '.jquery-ui-tooltip' ).length > 0) {
	    $( '.jquery-ui-tooltip' ).tooltip();
	}
    }
  };
})(jQuery);
