(function ($) {
  Drupal.behaviors.dndModal= {
    attach: function (context, settings) {
      $('input[id^="edit-next"], button[id^="edit-next"]', context).click(function(e) {
        var form = $('#scald-atom-add-form-add');
        if (form.find('.plupload-element').length > 0) {
          var uploader = form.find('.plupload-element').first().pluploadQueue();
          if ((uploader.total.uploaded + uploader.total.failed) != uploader.files.length || uploader.files.length == 0) {
            uploader.start();
            uploader.bind('UploadComplete', function() {
              setTimeout(function(){
                $('input[id^="edit-next"], button[id^="edit-next"]', context).click();
              },500);
            });
            return false;
          }
        }
      });
    }
  };
})(jQuery);

