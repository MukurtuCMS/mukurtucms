<?php

/**
 * @file
 * OEmbed Endpoint admin pages.
 */

/**
 * oEmbed admin settings page callback.
 */
function oembedprovider_settings() {
  $form = array();

  return system_settings_form($form);
}
