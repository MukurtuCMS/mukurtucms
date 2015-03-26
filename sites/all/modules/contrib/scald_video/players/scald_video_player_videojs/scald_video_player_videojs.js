/**
 * @file
 * Scald VideoJS javascript integration
 */

(function ($) {
  "use strict";
  Drupal.behaviors.scaldVideoPlayerVideoJS = {
    attach: function (context, settings) {
      $.each(Drupal.settings.scaldVideoPlayerVideoJS, function(key, value) {
        // We don't want videojs() to be called on CKEditor rte page, cause it won't find the video's id in the frame.
        var videoId = Drupal.settings.scaldVideoPlayerVideoJS[key].videoId;
        if ($('#' + videoId).length !== 0) {
          var player = videojs(videoId, { "controls": true, "autoplay": false, "preload": "auto" });
          player.width(Drupal.settings.scaldVideoPlayerVideoJS[key].videoWidth);
          player.height(Drupal.settings.scaldVideoPlayerVideoJS[key].videoHeight);
          $('#' + videoId).addClass('video-js vjs-default-skin');
        }
      });
    }
  };
})(jQuery);
