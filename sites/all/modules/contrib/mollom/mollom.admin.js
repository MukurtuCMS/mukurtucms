(function ($) {

/**
 * Attaches jQuery MultiSelect.
 */
Drupal.behaviors.mollomMultiSelect = {
  attach: function (context) {
    if ($().chosen) {
      $(context).find('select[multiple]').chosen({
        width: '90%',
        // @see search-results.tpl.php
        no_results_text: Drupal.t('Your search yielded no results')
      });
    }

    // Adjust the recommended display for discarding spam based on moderation
    // settings.
    $(context).find('#mollom-admin-configure-form').once(function() {
      function updateRecommendedDiscard($form) {
        $form.find('label[for="edit-mollom-discard-1"] .mollom-recommended').toggle(!$form.find('input[name="mollom[moderation]"]').is(':checked'));
        $form.find('label[for="edit-mollom-discard-0"] .mollom-recommended').toggle($form.find('input[name="mollom[moderation]"]').is(':checked'));
      }

      $(this).find('input[name="mollom[moderation]"]').change(function(e) {
        updateRecommendedDiscard($(this).closest('form'));
      });

      updateRecommendedDiscard($(this));
    });
  }
};

})(jQuery);
