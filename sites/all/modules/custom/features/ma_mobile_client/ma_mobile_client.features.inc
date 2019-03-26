<?php

/**
 * @file
 * ma_mobile_client.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_mobile_client_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
