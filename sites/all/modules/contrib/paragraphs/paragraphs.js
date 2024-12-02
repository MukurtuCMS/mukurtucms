/**
 * @file
 * Provides JavaScript for Paragraphs.
 */

(function ($) {

  /**
   * Allows submit buttons in entity forms to trigger uploads by undoing
   * work done by Drupal.behaviors.fileButtons.
   */
  Drupal.behaviors.paragraphs = {
    attach: function (context) {
      if (Drupal.file) {
        $('input.paragraphs-add-more-submit', context).unbind('mousedown', Drupal.file.disableFields);
      }
    },
    detach: function (context) {
      if (Drupal.file) {
        $('input.form-submit', context).bind('mousedown', Drupal.file.disableFields);
      }
    }
  };

})(jQuery);
