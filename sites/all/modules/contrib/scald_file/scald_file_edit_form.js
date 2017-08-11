/**
 * @file
 * File: scald_file_edit_form.js.
 */

(function ($) {
  Drupal.behaviors.scaldFileEditForm = {
    attach: function (context, settings) {
      $('.atom-wrapper', context).once('scald-file-edit-form', function() {
        var wrapper = $(this);
        if (wrapper.find('.field-name-scald-file .file-icon').attr('title') !== 'application/pdf') {
          wrapper.find('.form-type-checkbox[class*=scald-thumbnail-default]').hide();
        }
        wrapper.delegate('.field-name-scald-file .form-managed-file input[type=file]', 'change', function(e) {
          var file = (e.srcElement || e.target).files[0];
          if (file.type === 'application/pdf') {
            wrapper.find('.form-type-checkbox[class*=scald-thumbnail-default]').show();
          }
          else {
            wrapper.find('.form-type-checkbox[class*=scald-thumbnail-default]').hide();
          }
        });
      });
    }
  };
})(jQuery);
