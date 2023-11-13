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

          // We need to define a function to call the initialization of the videos because
          // the inline script is directly executed when it is injected dynamically inside the page
          // and the network call for loading the library is too slow compared to an inline script.
          var script_element = iframe_document.createElement('script');
          script_element.type = 'text/javascript';
          var script_content = 'function loadYoutubeWysiwyg() {initializeYoutubeVideos(document);}';
          var text_node = document.createTextNode(script_content);
          script_element.appendChild(text_node);
          iframe_document.head.appendChild(script_element);

          var script_element_library = iframe_document.createElement('script');
          script_element_library.type = 'text/javascript';
          script_element_library.src = Drupal.settings.defer_youtube_video_js_library;
          iframe_document.head.appendChild(script_element_library);
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
