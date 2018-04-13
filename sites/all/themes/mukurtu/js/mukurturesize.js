jQuery(document).ready(function($){
    function refereshPanelAccordion() {
		var width = $(window).width();
		if(width < 768) {
		    $(".pane-content.collapse").not('.facet-glossary').each( function () {
			$(this).collapse("hide");
		    });
		} else {
		    $(".pane-content.collapse").each( function () {
			$(this).collapse("show");
		    });
		}
    }

    // Featured Content Video Resize
    function featuredContentResize() {
	$(".view-mode-featured_content .scald-atom .mejs-container").each ( function () {
	    var width = parseInt($(this).css("width"), 10);
	    var height = Math.floor(width * .6667);
	    $(this).css("min-height", height + "px");
	});
    }

    function mukurtuOnResize() {
	refereshPanelAccordion();
	featuredContentResize();
    }

    window.onresize = mukurtuOnResize;
    mukurtuOnResize();

    $(window).load(function() {
	mukurtuOnResize();
    });
    
});
