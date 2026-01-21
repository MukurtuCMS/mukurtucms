<?php
/**
 * @file
 * oa_teams.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_teams_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
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
function oa_teams_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oa_teams_node_info() {
  $items = array(
    'oa_team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => t('An ad-hoc collection of users within a Space'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
