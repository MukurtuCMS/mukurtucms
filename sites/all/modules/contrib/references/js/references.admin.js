/**
 * @file
 * JavaScript for References Admin Pages.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.referencesAdmin = {
    attach: function (context, settings) {

      var config_check_uncheck_all_roles = jQuery('input:checkbox[value=user_reference_config_select_all_roles]', context);

      var role_options = jQuery('#edit-field-settings-referenceable-roles', context).find('input[type=checkbox]', context);

      jQuery(config_check_uncheck_all_roles).on('click', function () {
        role_options.not(this).prop('checked', this.checked);
      });
    }
  };
})(jQuery);
