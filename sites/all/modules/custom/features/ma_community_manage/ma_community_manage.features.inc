<?php

/**
 * @file
 * ma_community_manage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_community_manage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_community_manage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
