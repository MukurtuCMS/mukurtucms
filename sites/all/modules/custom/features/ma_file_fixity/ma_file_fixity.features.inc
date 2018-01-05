<?php
/**
 * @file
 * ma_file_fixity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_file_fixity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
