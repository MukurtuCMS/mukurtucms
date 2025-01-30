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
	try {
		var initialDHPage = Drupal.settings.mukurtu.dh_multipage_initial_slide;
	}
	catch(err) {
		var initialDHPage = 0;
	}
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

	// Loader animation when clicking a page in the multi-page carousel
	$(".slick-carousel-multipage .slick-slide").click(function () {
	    if(!$(this).find(".mukurtu-loader").hasClass("mukurtu-loader-loading")) {
		$(this).find("img").addClass("mukurtu-loader-background");
		$(this).find(".mukurtu-loader").addClass("mukurtu-loader-loading");
	    }
	});

	// Skip to page
	$(".mukurtu-page-select-wrapper select").change(function () {
		var slide = $(this).find("option:selected")[0].index - 1;
	    $("#mukurtu-multipage-carousel").slick('slickGoTo', slide, false);
	    $("#mukurtu-multipage-carousel .slick-slide[data-slick-index='" + slide +"'] a")[0].click();
	});

	// Digital Heritage Multiple Media Items
	$('.slick-carousel-slider-for').slick({
		centerMode: false,
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
		arrows: true,
	    slidesToShow: 3,
	    slidesToScroll: 1,
	    swipeToSlide: true,
	    asNavFor: '.slick-carousel-slider-for',
	    centerMode: false,
	    focusOnSelect: true
	});
    });
});
