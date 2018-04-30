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

	// Digital Heritage Multi-page
	var initialDHPage = Drupal.settings.mukurtu.dh_multipage_initial_slide;
	$('.slick-carousel-multipage').slick({
	    dots: false,
	    focusOnSelect: true,
	    infinite: false,
	    initialSlide: initialDHPage,
	    speed: 300,
	    swipe: true,
	    swipeToSlide: true,
	    slidesToShow: 3,
	    slidesToScroll: 1,
	    adaptiveHeight: true,
	    mobileFirst: true,
	    responsive: [
		{
		    breakpoint: 768,
		    settings: {
			slidesToShow: 5,
			slidesToScroll: 1
		    }
		},
		{
		    breakpoint: 992,
		    settings: {
			slidesToShow: 7,
			slidesToScroll: 1
		    }
		},
		{
		    breakpoint: 1200,
		    settings: {
			slidesToShow: 9,
			slidesToScroll: 1
		    }
		},
		{
		    breakpoint: 1600,
		    settings: {
			slidesToShow: 11,
			slidesToScroll: 1
		    }
		},
		{
		    breakpoint: 2000,
		    settings: {
			slidesToShow: 15,
			slidesToScroll: 11
		    }
		}
	    ]
	});
	
	// Digital Heritage Multiple Media Items
	$('.slick-carousel-slider-for').slick({
	    slidesToShow: 1,
	    slidesToScroll: 1,
	    swipeToSlide: true,
	    arrows: false,
	    fade: true,
	    adaptiveHeight: true,
	    mobileFirst: true,
	    asNavFor: '.slick-carousel-slider-nav'
	});
	$('.slick-carousel-slider-nav').slick({
	    slidesToShow: 3,
	    slidesToScroll: 1,
	    swipeToSlide: true,
	    asNavFor: '.slick-carousel-slider-for',
	    centerMode: false,
	    focusOnSelect: true
	});
    });
});
