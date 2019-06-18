jQuery(document).ready(function($){
    // Grid Handling for collections
    $(window).load(function() {
	$('.field-name-field-digital-heritage-items').masonry({
	    itemSelector: '.view-mode-search_result',
	    gutter: 30,
	});
    });
});
