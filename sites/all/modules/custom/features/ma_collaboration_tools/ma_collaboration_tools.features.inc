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
 * Implements hook_flag_default_flags().
 */
function ma_collaboration_tools_flag_default_flags() {
  $flags = array();
  // Exported flag: "Section Content Subscribe".
  $flags['subscribe_section_content'] = array(
    'entity_type' => 'node',
    'title' => 'Section Content Subscribe',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Follow',
    'flag_long' => 'Follow to receive messages related to this content',
    'flag_message' => 'Following',
    'unflag_short' => 'UnFollow',
    'unflag_long' => 'UnFollow to stop receiving messages about this content',
    'unflag_message' => 'UnFollowed',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'ma_collaboration_tools',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Archive".
  $flags['trash'] = array(
    'entity_type' => 'node',
    'title' => 'Archive',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'Archive This',
    'flag_long' => 'Move item to the site archive',
    'flag_message' => 'Item has been archived',
    'unflag_short' => 'Remove from archive',
    'unflag_long' => 'Unarchive item and restore previous access settings.',
    'unflag_message' => 'Item removed from archive',
    'unflag_denied_text' => 'Archived',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to archive this item? You may be unable to access it after archiving.',
    'unflag_confirmation' => 'Are you sure you want to remove this item from archive?',
    'module' => 'ma_collaboration_tools',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

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
    'document_library' => array(
      'name' => t('Document Library'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
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
    'oa_discussion_post' => array(
      'name' => t('Discussion Post'),
      'base' => 'node_content',
      'description' => t('A collaboration discussion post'),
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
