jQuery(document).ready(function($){
    function refereshPanelAccordion() {
		var width = $(window).width();
		if(width < 768) {
			$(".pane-content.collapse").each( function () {
			$(this).collapse("hide");
			});
		} else {
			$(".pane-content.collapse").each( function () {
			$(this).collapse("show");
			});
		}
    }

    function mukurtuOnResize() {
		refereshPanelAccordion();
    }
    window.onresize = mukurtuOnResize;
    mukurtuOnResize();

    $(window).load(function() {
	mukurtuOnResize();
    });
});
