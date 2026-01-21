<?php
/**
 * @file
 * ma_taxonomy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_taxonomy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_taxonomy_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
