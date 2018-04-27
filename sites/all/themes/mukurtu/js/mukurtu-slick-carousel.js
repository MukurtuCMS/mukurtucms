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
	    slidesToShow: 3,
	    slidesToScroll: 3,
	    adaptiveHeight: true,
	    mobileFirst: true,
	    responsive: [
		{
		    breakpoint: 768,
		    settings: {
			slidesToShow: 5,
			slidesToScroll: 5
		    }
		},
		{
		    breakpoint: 992,
		    settings: {
			slidesToShow: 7,
			slidesToScroll: 7
		    }
		},
		{
		    breakpoint: 1200,
		    settings: {
			slidesToShow: 9,
			slidesToScroll: 9
		    }
		},
		{
		    breakpoint: 1600,
		    settings: {
			slidesToShow: 11,
			slidesToScroll: 11
		    }
		},
		{
		    breakpoint: 2000,
		    settings: {
			slidesToShow: 15,
			slidesToScroll: 15
		    }
		}
	    ]
	});
	
	// Digital Heritage Multiple Media Items
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
	    centerMode: false,
	    focusOnSelect: true
	});
    });
});
