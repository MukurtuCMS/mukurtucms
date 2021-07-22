<?php

/**
 * @file
 * ma_importexport_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_importexport_users_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_importexport_users_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
