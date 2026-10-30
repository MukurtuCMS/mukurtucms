<?php

/**
 * @file
 * Hooks provided by the Registry Rebuild module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to perform tasks right before calling the
 * drupal_flush_all_cashes() function.
 *
 * By executing registry_rebuild, bootstrap will be initiated without invoking
 * calls to hook_init(). This hook allows a module to execute a task that might
 * be required to perform before Drupal starts for example rebuilding the menu.
 * (or any other task that is executed in drupal_flush_all_caches())
 *
 * @see drupal_flush_all_caches()
 */
function hook_pre_flush_all_caches() {
  // Tasks that require to be performed before calling
  // drupal_flush_all_cashes().
}
