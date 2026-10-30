<?php

/**
 * @file
 * ma_collaboration_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_collaboration_tools_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_collaboration_tools_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_collaboration_tools_node_info() {
  $items = array(
    'calendar' => array(
      'name' => t('Calendar'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'discussion_space' => array(
      'name' => t('Discussion Space'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'discussion_topic' => array(
      'name' => t('Discussion Topic'),
      'base' => 'node_content',
      'description' => t('A collaboration discussion topic'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'document_library' => array(
      'name' => t('Document Library'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'document_page' => array(
      'name' => t('Document Page'),
      'base' => 'node_content',
      'description' => t('An collaboration Document/Wiki page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A collaboration Event'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'following_notification' => array(
      'name' => t('Following Notification'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_ical_importer' => array(
      'name' => t('iCal Importer'),
      'base' => 'node_content',
      'description' => t('A feeds node to import event from an iCal feed.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
