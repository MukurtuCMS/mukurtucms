/**
 * @file
 * Defines the behavior of the Memcache Admin module.
 */

(function ($) {

  'use strict';

  /**
   * Append the memcache debug info to the page.
   *
   * @type {Drupal~behavior}
   */
  Drupal.behaviors.memcacheAdmin = {
    attach: function attach() {
      $("body").append($("#memcache-devel"));
    }
  };

})(jQuery);
