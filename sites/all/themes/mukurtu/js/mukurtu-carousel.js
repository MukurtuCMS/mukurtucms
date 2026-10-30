jQuery(document).ready(function($){
    $(window).load(function() {
	var SingleMukurtuCarousel = $(".mukurtu-owl-carousel-single").owlCarousel({
	    autoHeight:true,
	    loop:true,
	    center:true,
	    margin:100,
	    nav:true,
	    navText:['',''],
	    dots: true,
	    rewind: true,
	    stagePadding: 50,
	    responsive:{
		0:{
		    items:1
		}
	    }
	});
    });   
});
