/**
 * @file
 * File name: scald_youtube_search.js.
 *
 * YouTube Search related functionalities.
 */

(function ($) {
  /**
   * Selecting search items will input their video IDs into the form.
   */
  Drupal.behaviors.selectSearchItem = {
    attach: function (context, settings) {
      $('#search-results-wrapper .youtube-result-item', context).click(function(e){
        $('#scald-atom-add-form-add .form-item-identifier input').val($(this).find('.youtube-result-item-id').html());
        $('#scald-atom-add-form-add .continue-button').trigger('click');
      });
      $("#scald-atom-add-form-add .form-item-search-text input", context).keyup(function(e){
        if (event.keyCode == 13) {
          $("#scald-atom-add-form-add .search-button", context).trigger('mousedown');
        }
      });
    }
  };

}(jQuery));
