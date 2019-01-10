<?php
/**
 * @file
 * Code for getting context from URL argument.
 */

/**
 * Implements hook_og_context_negotiation_info().
 */
function oa_core_og_context_negotiation_info() {
  $providers = array();
  $providers['oa_core_url'] = array(
    'name' => t('URL (content create)'),
    'description' => t('Select groups if they were passed in the node create URL (e.g. node/add/post?og_group_ref=4).'),
    'callback' => 'oa_core_context_handler_url',
  );
  return $providers;
}

/**
 * Context handler; Get groups from node create URL.
 */
function oa_core_context_handler_url() {
  $item = menu_get_item();
  if (strpos($item['path'], 'node/add/') === 0 && !empty($item['map'][2])) {
    $node_type = str_replace('-', '_', $item['map'][2]);
  }
  elseif (strpos($item['path'], 'api/oa_wizard/') === 0) {
    $wizard_name = str_replace('-', '_', $item['map'][2]);
    $wizard = oa_wizard_machine_name_load($wizard_name);
    if (!$wizard || empty($wizard->field_wizard_type[LANGUAGE_NONE][0]['value']) || !node_access('create', $wizard->field_wizard_type[LANGUAGE_NONE][0]['value'])) {
      return;
    }
    $node_type = $wizard->field_wizard_type[LANGUAGE_NONE][0]['value'];
  }
  if (empty($node_type) || !($fields = og_get_group_audience_fields('node', $node_type))) {
    return;
  }
  $gids = array();
  foreach ($fields as $field_name => $label) {
    $field = field_info_field($field_name);
    if (!empty($_GET[$field_name]) && ($node = node_load($_GET[$field_name])) && node_access('view', $node) && og_is_group('node', $node)) {
      $gids['node'][] = $node->nid;
    }
  }
  return $gids;
}
