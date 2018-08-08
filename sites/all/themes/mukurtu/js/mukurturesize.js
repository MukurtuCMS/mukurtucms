jQuery(document).ready(function ($) {
	function refereshPanelAccordion() {
		var width = $(window).width();
		if (width < 768) {
			$(".pane-content.collapse").not('.facet-glossary').each(function () {
				$(this).collapse("hide");
			});
		} else {
			$(".pane-content.collapse").each(function () {
				$(this).collapse("show");
			});
		}
	}

	// Hero Image: Two Columns Resize
	// entity entity-bean bean-hero-image-two-columns view-mode-default 
	function heroImageTwoColumnsResize() {
		var width = $(window).width();
		$(".bean-hero-image-two-columns").each(function () {
			if (width > 768) {
				var totalHeight = parseInt($(this).css("height"), 10);
				$(this).find(".col-sm-6 img").css("min-height", totalHeight + "px");
			} else {
				$(this).find(".col-sm-6 img").css("min-height", "");
			}
		});
	}

	// Featured Content Video Resize
	function featuredContentResize() {
		$(".view-mode-featured_content .scald-atom .mejs-container").each(function () {
			var width = parseInt($(this).css("width"), 10);
			var height = Math.floor(width * .6667);
			$(this).css("min-height", height + "px");
		});
	}

	function mukurtuMediaelementResize() {
		for (var pKey in mejs.players) {
			mejs.players[pKey].setPlayerSize();
			mejs.players[pKey].setControlsSize();
		};
	}

	function mukurtuOnResize() {
		heroImageTwoColumnsResize();
		refereshPanelAccordion();
		featuredContentResize();
	}

	window.onresize = mukurtuOnResize;
	mukurtuOnResize();


	// Hook the MediaElement JS fullscreen functions so we can detect those events
	var mejsEnterFullScreen = new Event('mejsEnterFullScreen');
	var mejsExitFullScreen = new Event('mejsExitFullScreen');

	// Not currently in use but leaving around, it might be useful
    /*
    MediaElementPlayer.prototype.enterFullScreenOrg = MediaElementPlayer.prototype.enterFullScreen;
    MediaElementPlayer.prototype.enterFullScreen = function() {
	this.enterFullScreenOrg();
	this.media.dispatchEvent(mejsEnterFullScreen);
    }
    */
	// Create an event for exiting full screen mejs video
	MediaElementPlayer.prototype.exitFullScreenOrg = MediaElementPlayer.prototype.exitFullScreen;
	MediaElementPlayer.prototype.exitFullScreen = function () {
		this.exitFullScreenOrg();
		this.media.dispatchEvent(mejsExitFullScreen);
	}


	$(window).load(function () {
		mukurtuOnResize();

		// Slick Carousel resize handling. MediaElement JS elements need to be recalculated on resize.
		if ($(".slick-carousel").length > 0) {
			$(window).on('resize orientationchange', function () {
				$('.slick-carousel').slick('resize');
				mukurtuMediaelementResize();
			});

			$("a.quicktabs-tab-node").on('click', function () {
				$('.slick-initialized').hide();
				$('.slick-initialized').show();
				var event = window.document.createEvent('UIEvents');
				event.initUIEvent('resize', true, false, window, 0);
				window.dispatchEvent(event);
				event.initUIEvent('orientationchange', true, false, window, 0);
				window.dispatchEvent(event);

				// Click the active element on the CR page's slider
				var tabID = ($(this)[0].id).replace("-tab-", "-tabpage-");
				$('#' + tabID + " .slick-carousel-slider-nav .slick-active").click();
			});
		} 
		
		// Community Record MediaElement JS element resizing
		// When a mejs element is rendered hidden/off screen it's width is 100%, we need to 
		// handle that for community record tabs
		$("a.quicktabs-tab-node").on('click', function () {
			mukurtuMediaelementResize();
		});

		// Add MediaElement Listeners
		for (var pKey in mejs.players) {
			/*
			mejs.players[pKey].media.addEventListener('mejsEnterFullScreen', function (e) {
	
			}, false);
			*/
			// Add a listener for our custom exit fullscreen event. This fixes the carousel display after
			// exiting a full screen mejs view.
			mejs.players[pKey].media.addEventListener('mejsExitFullScreen', function (e) {
				// Resize carousel/mejs controls when exiting full screen
				var event = window.document.createEvent('UIEvents');

				// This hide/show cycle isn't ideal. The problem is when we ask the carousel to redraw,
				// the height of the mejs element can still be that of a fullscreen video which screws
				// up the carousel display. Hiding/showing seems to reset everything well enough to
				// redraw as expected.
				$('.slick-initialized').hide();
				$('.slick-initialized').show();
				event.initUIEvent('resize', true, false, window, 0);
				window.dispatchEvent(event);
				event.initUIEvent('orientationchange', true, false, window, 0);
				window.dispatchEvent(event);
			}, false);
		};
	});

});
