<?php

/**
 * @file
 * ma_shared_notification_components.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_shared_notification_components_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
