/**
 * @file
 * JavaScript enhancements for "Merge Duplicate Terms" form.
 */
(function ($) {

  /**
   * Behavior that elaborates Tableselect of duplicate terms.
   */
  Drupal.behaviors.termMergeDuplicateTableselect = {
    attach: function(context) {
      // We want to disable checkbox of a duplicate term if it is currently
      // selected as a trunk term in that group of duplicate terms, i.e. you
      // cannot (and should not) merge a term into itself.
      $('.term-merge-duplicate-trunk', context).closest(':has(.form-checkbox)').once('term-merge-duplicate-trunk', function() {
        var container = $(this);
        container.find('.term-merge-duplicate-trunk').change(function() {
          // Removing disabled from all disabled checkboxes.
          container.parents('table').find('.form-checkbox:disabled').removeAttr('disabled');
          if ($(this).is(':checked')) {
            container.find('.form-checkbox').attr('disabled', true);
          }
        });
      });
    }
  };

  /**
   * Behavior that kicks off general switch button on Duplicate terms form.
   */
  Drupal.behaviors.termMergeDuplicateGeneralSwitch = {
    attach: function (context) {
      $('.term-merge-duplicate-general-switch', context).once('term-merge-duplicate-general-switch', function() {
        var container = $(this).parents('form');
        $(this).change(function() {
          var term_branches = container.find('table:not(.sticky-header) .select-all .form-checkbox');
          if ($(this).is(':checked')) {
            term_branches.attr('checked', true).trigger({
              type: 'click',
              target: this
            });
            // For some reason the checkboxes get unchecked, we check them back.
            term_branches.attr('checked', true);

            // We also want to trigger "change" on those radio buttons, see
            // Drupal.behaviors.termMergeDuplicateTableselect for more info.
            container.find('table').find('.term-merge-duplicate-trunk:first').attr('checked', true).trigger('change');
          }
          else {
            term_branches.removeAttr('checked').trigger({
              type: 'click',
              target: this
            });
            // For some reason the checkboxes get checked, we uncheck them back.
            term_branches.removeAttr('checked');

            // We also want to trigger "change" on those radio buttons, see
            // Drupal.behaviors.termMergeDuplicateTableselect for more info.
            container.find('table').find('.term-merge-duplicate-trunk').removeAttr('checked').trigger('change');
          }
        });
      });
    }
  };

})(jQuery);
