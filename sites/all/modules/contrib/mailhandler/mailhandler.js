/**
 * @file
 * Fix broken AJAX during connection tests.
 */

Drupal.behaviors.mailhandler = {
    attach: function(context, settings) {
      jQuery('form')
        .ajaxStart(function() {
          jQuery(this).submit(function() {
            return false;
          });
        })
        .ajaxStop(function() {
          jQuery(this).unbind('submit');
          jQuery(this).submit(function() {
            return true;
          });
        });
    }
}
