/**
 * Workaround for .position() behaviour which was changed in jQuery 3.3
 * @see https://github.com/jquery/api.jquery.com/issues/1081
 */
var Drupal = Drupal || {};

(function ($, Drupal) {
  // Overload Drupal.jsAC.prototype.populatePopup
  if (Drupal.jsAC !== undefined && Drupal.jsAC.prototype.populatePopup !== undefined) {
    Drupal.jsAC.prototype.populatePopup = function () {
      var $input = $(this.input);
      var offset = $input.offset();
      var offsetParent = $input.offsetParent().offset();
      // Show popup.
      if (this.popup) {
        $(this.popup).remove();
      }
      this.selected = false;
      this.popup = $('<div id="autocomplete"></div>')[0];
      this.popup.owner = this;
      $(this.popup).css({
        top: parseInt(offset.top - offsetParent.top + this.input.offsetHeight, 10) + 'px',
        left: parseInt(offset.left - offsetParent.left, 10) + 'px',
        width: $input.innerWidth() + 'px',
        display: 'none'
      });
      $input.before(this.popup);

      // Do search.
      this.db.owner = this;
      this.db.search(this.input.value);
    };
  }
})(jQuery, Drupal);
