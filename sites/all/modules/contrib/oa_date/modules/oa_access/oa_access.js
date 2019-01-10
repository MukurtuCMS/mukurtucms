/**
 * @file
 * Javascript for oa_access admin forms.
 */
(function ($) {
  Drupal.behaviors.oa_access = {
    attach: function (context, settings) {
      var all_nid = settings.oa_access.all_nid,
          all_selector = 'option[value=' + all_nid + ']',
          rest_selector = 'option[value!=' + all_nid + ']';

      // When 'All' option is select, we remove all the other options
      // and vice-versa.
      $('.chosen-widget')
        .once(function () {
          // Store the initial state of the all option.
          $(this).data('oa_access_all_selected', $(all_selector, this).is(':selected'));
        })
        .change(function () {
          var all_selected_now = $(all_selector, this).is(':selected'),
              all_selected_old = $(this).data('oa_access_all_selected'),
              none_selected = $('option:selected', this).length === 0,
              updated = false;

          // If nothing is selected, we don't have to worry.
          if (!none_selected) {
            if (all_selected_now && !all_selected_old) {
              // Something else was selected and the user chose the 'All' option.
              $(rest_selector, this).prop('selected', false);
              updated = true;
            }
            else if (all_selected_old) {
              // The all option was selected and the user chose something else.
              $(all_selector, this).prop('selected', false)
              all_selected_now = false;
              updated = true;
            }
            if (updated) {
              $(this).trigger('chosen:updated');
            }
          }

          // Store this value for later.
          $(this).data('oa_access_all_selected', all_selected_now);
        });
    }
  };
})(jQuery);
