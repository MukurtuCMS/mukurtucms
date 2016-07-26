/**
 * @file
 * dh_multipage_carousel.js
 */

(function($) {

    Drupal.behaviors.dh_multipage_carousel = {
	attach : function(context, settings) {
	    var callbacks = {onInitialized: afterChanged, onChanged: afterChanged};

	    for(var carousel in settings.owlcarousel) {
		$.extend(true, settings.owlcarousel[carousel].settings, callbacks);
	    }
	}
    };

    function afterChanged(property) {
	var pageLinks = document.querySelectorAll(".owl-item a");

	// For the Digital Heritage multi-page carousel, we want it to keep the same relative position on page reload.
	// This will add a position argument to the page links every time the carousel changes.
	$(".owl-item a").each(function () {
	    if($(this).attr("href")) {
		var argPos = $(this).attr("href").lastIndexOf('?position');
		if(argPos == -1) {
		    var newLink = $(this).attr("href") + '?position=' + property.item.index;
		} else {
		    var newLink = $(this).attr("href").substr(0, argPos) + '?position=' + property.item.index;
		}
		$(this).attr("href", newLink);
	    }
	});
    }
}(jQuery));
