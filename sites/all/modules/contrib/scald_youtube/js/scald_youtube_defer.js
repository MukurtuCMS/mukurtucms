/**
 * @file
 * File name: scald_youtube_defer.js.
 *
 * Defer YouTube Player in order to improve performance.
 */

(function ($) {

  /**
   * Set the src attributes of the Youtube videos.
   */
  Drupal.behaviors.scaldYoutubePlayer = {
    attach: function (context, settings) {
      // Initialize the Youtube videos.
      initializeYoutubeVideos(context);
    }
  };
}(jQuery));
