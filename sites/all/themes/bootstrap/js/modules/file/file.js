(function ($) {
  // Override core JS so it works with "button" tags.
  /**
   * Attach behaviors to the file upload and remove buttons.
   */
  Drupal.behaviors.fileButtons = {
    attach: function (context) {
      $(':input.form-submit', context).bind('mousedown', Drupal.file.disableFields);
      $('div.form-managed-file :input.form-submit', context).bind('mousedown', Drupal.file.progressBar);
    },
    detach: function (context) {
      $(':input.form-submit', context).unbind('mousedown', Drupal.file.disableFields);
      $('div.form-managed-file :input.form-submit', context).unbind('mousedown', Drupal.file.progressBar);
    }
  };
  if (Drupal.file) {
    /**
     * Prevent file uploads when using buttons not intended to upload.
     */
    Drupal.file.disableFields = function (event){
      var clickedButton = this;

      // Only disable upload fields for Ajax buttons.
      if (!$(clickedButton).hasClass('ajax-processed')) {
        return;
      }

      // Check if we're working with an "Upload" button.
      var $enabledFields = [];
      if ($(this).closest('div.form-managed-file').length > 0) {
        $enabledFields = $(this).closest('div.form-managed-file').find(':input.form-file');
      }

      // Temporarily disable upload fields other than the one we're currently
      // working with. Filter out fields that are already disabled so that they
      // do not get enabled when we re-enable these fields at the end of behavior
      // processing. Re-enable in a setTimeout set to a relatively short amount
      // of time (1 second). All the other mousedown handlers (like Drupal's Ajax
      // behaviors) are excuted before any timeout functions are called, so we
      // don't have to worry about the fields being re-enabled too soon.
      // @todo If the previous sentence is true, why not set the timeout to 0?
      var $fieldsToTemporarilyDisable = $('div.form-managed-file :input.form-file').not($enabledFields).not(':disabled');
      $fieldsToTemporarilyDisable.attr('disabled', 'disabled');
      setTimeout(function (){
        $fieldsToTemporarilyDisable.attr('disabled', false);
      }, 1000);
    };
    /**
     * Add progress bar support if possible.
     */
    Drupal.file.progressBar = function (event) {
      var clickedButton = this;
      var $progressId = $(clickedButton).closest('div.form-managed-file').find(':input.file-progress');
      if ($progressId.length) {
        var originalName = $progressId.attr('name');

        // Replace the name with the required identifier.
        $progressId.attr('name', originalName.match(/APC_UPLOAD_PROGRESS|UPLOAD_IDENTIFIER/)[0]);

        // Restore the original name after the upload begins.
        setTimeout(function () {
          $progressId.attr('name', originalName);
        }, 1000);
      }
      // Show the progress bar if the upload takes longer than half a second.
      setTimeout(function () {
        $(clickedButton).closest('div.form-managed-file').find('div.ajax-progress-bar').slideDown();
      }, 500);
    };

    /**
     * Styling invalid file extension error message (Issue #2331595 by NetTantra).
     */
    Drupal.file.validateExtension = function (event) {
      // Remove any previous errors.
      $('.file-upload-js-error').remove();

      // Add client side validation for the input[type=file].
      var extensionPattern = event.data.extensions.replace(/,\s*/g, '|');
      if (extensionPattern.length > 1 && this.value.length > 0) {
        var acceptableMatch = new RegExp('\\.(' + extensionPattern + ')$', 'gi');
        if (!acceptableMatch.test(this.value)) {
          var error = Drupal.t("The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.", {
            // According to the specifications of HTML5, a file upload control
            // should not reveal the real local path to the file that a user
            // has selected. Some web browsers implement this restriction by
            // replacing the local path with "C:\fakepath\", which can cause
            // confusion by leaving the user thinking perhaps Drupal could not
            // find the file because it messed up the file path. To avoid this
            // confusion, therefore, we strip out the bogus fakepath string.
            '%filename': this.value.replace('C:\\fakepath\\', ''),
            '%extensions': extensionPattern.replace(/\|/g, ', ')
          });
          $(this).closest('div.form-managed-file').parents('.form-item').first().prepend('<div class="alert alert-danger alert-dismissible messages error file-upload-js-error" aria-live="polite" role="alert">\
            <button type="button" class="close" data-dismiss="alert">\
              <span aria-hidden="true">&times;</span>\
              <span class="sr-only">Close</span>\
            </button>' + error + '</div>');
          this.value = '';
          return false;
        }
      }
    };
  }
})(jQuery);
