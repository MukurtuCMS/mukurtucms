(function ($) {
  CKEDITOR.plugins.add('scald_youtube_defer_plugin', {
    init: function (editor) {

      /**
       * Add Defer Youtube JavaScript to the WYSIWYG iframe.
       */
      editor.on('mode', function (event) {
        if (event.editor.mode === 'wysiwyg') {
          var iframe = getIframe(event.editor);
          var iframe_document = iframe.contentWindow.document;
          var script_element = iframe_document.createElement('script');
          script_element.type = 'text/javascript';
          script_element.src = Drupal.settings.defer_youtube_video_js;
          iframe_document.head.appendChild(script_element);
        }
      });

      /**
       * Load Youtube videos when they are added in the WYSIWYG.
       */
      editor.on('change', function (event) {
        var iframe = getIframe(event.editor).contentWindow;
        if (typeof iframe.initializeYoutubeVideos === "function") {
          iframe.initializeYoutubeVideos();
        }
      });

      /**
       * Retrieves the WYSIWYG iframe from a CKEditor editor object.
       *
       * @param {object} editor_object
       *   The editor object.
       *
       * @return {object}
       *   The DOM node corresponding to the WYSIWYG iframe associated with the
       *   provided editor.
       */
      var getIframe = function (editor_object) {
        return document.querySelector('#' + editor_object.id + '_contents iframe');
      };

      editor.addCommand('defer_youtube_videos', {
        exec: function (editor) {
          getIframe(editor).contentWindow.initializeYoutubeVideos();
        }
      });

      editor.ui.addButton('scald_youtube_defer_button', {
        label: 'Defer Youtube videos',
        command: 'defer_youtube_videos'
      });
    }
  });
})(jQuery);
