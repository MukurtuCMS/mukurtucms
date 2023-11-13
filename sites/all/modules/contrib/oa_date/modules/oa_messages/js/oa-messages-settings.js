/**
 * @file oa-message-settings.js
 *
 * Provides the tab and check / uncheck all functionality for the user message settings page.
 */
(function ($) {

  Drupal.behaviors.messagesSettings = {
    attach: function (context, settings) {
      $('.select-all').click(function() {
        $('.apply-to').prop('checked', this.checked);
      });

      // Set message types upon selecting a method.
      $('.column2 .form-select').change(function() {
        var id = $(this).attr('id');
        var children = $('#message-container-' + id + ' .form-checkbox');
        if ($(this).val() == null) {
          children.prop('checked', false);
        }
        else {
          children.prop('checked', true);
        }
      });
    }
  };

})(jQuery);
