(function ($) {

/**
 * Collapsible snapshots.
 */
Drupal.behaviors.demoCollapse = {
  attach: function (context) {
    $('.demo-snapshots-widget .form-item-filename', context).once('demo-collapse', function () {
      var $item = $(this);
      $item
        .find('label')
          .click(function () {
            $item.find('.description').slideToggle('fast');
          })
          .end()
        .find('.description').hide();
    });
  }
};

})(jQuery);
