/**
 * @file
 * Initiate Owl Carousel.
 */

(function($) {

  Drupal.behaviors.owlcarousel = {
    attach: function(context, settings) {
      for (var carousel in settings.owlcarousel) {
        this.attachInit(carousel, settings.owlcarousel);
      }
    },

    /**
     * Find and select carousel element.
     *
     * @param carousel htmlSelector
     * @param settings object
     */
    attachInit: function(carousel, settings) {
      var element = $('#' + carousel + '.owl-carousel');
      this.attachOwlCarousel(element, settings[carousel].settings);
    },

    /**
     * Attaches each individual carousel instance
     * to the provided HTML selector.
     *
     * @param element htmlElement
     * @param settings object
     */
    attachOwlCarousel: function(element, settings) {
      // Provide settings alter before init.
      $(document).trigger('owlcarousel.alterSettings', settings);

      // lazyLoad support.
      if (settings.lazyLoad) {
        var images = element.find('img');

        $.each(images, function(i, image) {
          $(image).attr('data-src', $(image).attr('src'));
        });

        images.addClass('owl-lazy');
      }

      if (element.hasClass('disabled') || settings.forceDisplay) {
        element.show();
      }
      else {
        // Attach instance settings & provide alter.
        $(document).trigger('owlcarousel.alterInstance', [element.owlCarousel(settings)]);
      }
    }
  };

}(jQuery));
