(function ($) {
  // Change from emtpy star to filled star glyph.
  $.fn.mukurtuToggleStarOn = function (data) {
    $(this).removeClass('glyphicon-star-empty').addClass('glyphicon-star');
  };

  // Change from filled star to empty star glyph.
  $.fn.mukurtuToggleStarOff = function (data) {
    $(this).removeClass('glyphicon-star').addClass('glyphicon-star-empty');
  };
})(jQuery);
