(function ($) {

var findSiblings = Drupal.tableDrag.prototype.row.prototype.findSiblings;
Drupal.tableDrag.prototype.row.prototype.findSiblings = function (rowSettings) {
  if (rowSettings.relationship === 'root') {
    var siblings = [];
    var directions = ['prev', 'next'];
    var rowIndentation = this.indents;
    for (var d = 0; d < directions.length; d++) {
      var checkRow = $(this.element)[directions[d]]();
      while (checkRow.length) {
        // Check that the sibling contains a similar target field.
        if ($('.' + rowSettings.target, checkRow)) {
          siblings.push(checkRow[0]);
        }
        else {
          break;
        }
        checkRow = $(checkRow)[directions[d]]();
      }
      // Since siblings are added in reverse order for previous, reverse the
      // completed list of previous siblings. Add the current row and continue.
      if (directions[d] == 'prev') {
        siblings.reverse();
        siblings.push(this.element);
      }
    }
    return siblings;
  }
  else {
    return findSiblings.apply(this, arguments);
  }
};

})(jQuery);
