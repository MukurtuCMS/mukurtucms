/**
 * @file
 * File: scald_file.js.
 */

(function ($) {
  Drupal.behaviors.scaldFile = {
    attach: function (context, settings) {
      $('body').once('scald-file', function() {
        if (typeof CKEDITOR !== 'undefined') {
          CKEDITOR.on('instanceReady', function(ev) {
            CKEDITOR.instances[ev.editor.name].document.appendStyleSheet(Drupal.settings.basePath + settings.scaldFile.path);
          });
        }
      });
    }
  };
})(jQuery);
