<?php
/**
 * @file
 * ma_importexport_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_importexport_media_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_importexport_media_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
