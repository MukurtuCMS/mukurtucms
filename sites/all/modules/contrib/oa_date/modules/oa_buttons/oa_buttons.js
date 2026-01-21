/**
 * @file
 * Javascript for oa_buttons
 */
(function ($) {
  Drupal.behaviors.oaButtons = {
    attach: function (context, settings) {
      $(document).on('oaCoreSpaceTypeChange', function (e) {
        if (e.override) {
          return;
        }

        var type;
        var root = $('#edit-field-oa-node-types', context);

        // Find right property setter. jQuery < 1.6 use attr, newer use prop.
        var setter = jQuery.fn.prop ? 'prop' : 'attr';

        // Override allowed node types.
        $('input:checkbox', root)[setter]({checked: false});
        if (e.options.node_options) {
          for (type in e.options.node_options) {
            $('input:checkbox[value="' + e.options.node_options[type] + '"]', root)[setter]({ checked: true });
          }
        }
      });
    }
  };
})(jQuery);
