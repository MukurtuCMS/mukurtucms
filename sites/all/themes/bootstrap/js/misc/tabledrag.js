(function ($) {

  /**
   * Add an asterisk or other marker to the changed row.
   */
  Drupal.tableDrag.prototype.row.prototype.markChanged = function () {
    var $cell = $('td:first', this.element);
    // Find the first appropriate place to insert the marker.
    var $target = $($cell.find('.file-size').get(0) || $cell.find('.file').get(0) || $cell.find('.tabledrag-handle').get(0));
    if (!$cell.find('.tabledrag-changed').length) {
      $target.after(' ' + Drupal.theme('tableDragChangedMarker') + ' ');
    }
  };

})(jQuery);
