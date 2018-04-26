jQuery(document).ready(function($){
    $(window).load(function() {
	$('.slick-carousel-single').slick({
	    dots: true,
	    infinite: true,
	    speed: 300,
	    slidesToShow: 1,
	    adaptiveHeight: true,
	    mobileFirst: true,
	});

	
	$('.slick-carousel-slider-for').slick({
	    slidesToShow: 1,
	    slidesToScroll: 1,
	    arrows: false,
	    fade: true,
	    adaptiveHeight: true,
	    mobileFirst: true,
	    asNavFor: '.slick-carousel-slider-nav'
	});
	$('.slick-carousel-slider-nav').slick({
	    slidesToShow: 3,
	    slidesToScroll: 1,
	    asNavFor: '.slick-carousel-slider-for',
//	    dots: true,
	    centerMode: true,
	    focusOnSelect: true
	});
    });
});
