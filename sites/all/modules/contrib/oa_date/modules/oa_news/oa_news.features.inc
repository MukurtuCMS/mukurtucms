<?php
/**
 * @file
 * oa_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
