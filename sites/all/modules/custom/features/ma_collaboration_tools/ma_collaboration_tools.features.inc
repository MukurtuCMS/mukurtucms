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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ma_collaboration_tools_node_info() {
  $items = array(
    'oa_discussion_post' => array(
      'name' => t('Discussion Post'),
      'base' => 'node_content',
      'description' => t('A collaboration discussion post'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A collaboration Event'),
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
    'oa_section' => array(
      'name' => t('Collaboration Section'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_wiki_page' => array(
      'name' => t('Document Page'),
      'base' => 'node_content',
      'description' => t('An collaboration Document/Wiki page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
