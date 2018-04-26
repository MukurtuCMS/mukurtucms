jQuery(document).ready(function($){
    $(window).load(function() {
	$('.slick-carousel').slick({
	    dots: true,
	    infinite: true,
	    speed: 300,
	    slidesToShow: 1,
	    adaptiveHeight: true,
	    mobileFirst: true,
	});
    });
});
