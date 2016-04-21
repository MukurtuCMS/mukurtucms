<?php

/**
 * @file
 * Make field required. If not present, the feed item will be removed.
 */

$plugin = array(
  'form' => 'mukurtu_feeds_tamper_plugins_require_valid_node_form',
  'callback' => 'mukurtu_feeds_tamper_plugins_require_valid_node_callback',
  'name' => 'Require valid node reference',
  'multi' => 'direct',
  'category' => 'Filter',
);

function mukurtu_feeds_tamper_plugins_require_valid_node_form($importer, $element_key, $settings) {
  $form = array();

  $form['help'] = array(
    '#markup' => t('Check if the field references a valid node of the specified type, either GUID or NID. If not, the feed item will not be saved.'),
  );

  $options = array('any' => t('Any'));
  foreach(node_type_get_types() as $node_type => $node_type_info) {
      $options[$node_type] = $node_type_info->name;
  }

  $form['allow_empty'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow this field to be empty'),
    '#default_value' => !empty($settings['allow_empty']),
    '#description' => t('Allowing this field to be empty will make this field optional.'),
  );

  $form['node_type'] = array(
      '#type' => 'radios',
      '#options' => $options,
      '#title' => t('Node Type'),
      '#default_value' => !empty($settings['node_type']) ? $settings['node_type'] : 'any'
  );

  return $form;
}

function mukurtu_feeds_tamper_plugins_require_valid_node_callback($result, $item_key, $element_key, &$field, $settings, $source) {
    // Check settings for allowed node type
    if(!empty($settings['node_type']) && in_array($settings['node_type'], array_keys(node_type_get_types()))) {
        $node_type = $settings['node_type'];
    } else {
        $node_type = 'any';
    }

    // Check settings to see if we are allowing empty values
    $allow_empty = (!empty($settings['allow_empty']) && $settings['allow_empty'] == 1) ? TRUE : FALSE;
    
    foreach($field as $node_ref) {
        if(empty($node_ref) && $allow_empty) {
            continue;
        }
        
        if(!is_numeric($node_ref)) {
            // Lookup NID from GUID
            $referenced_node_nid = _mukurtu_feeds_tamper_plugins_require_valid_node_lookup_node_by_guid($node_ref);
        } else {
            // Treat as a NID
            $referenced_node_nid = $node_ref;
        }
        $referenced_node = node_load($referenced_node_nid);

        if(!empty($referenced_node)) {
            
            // A setting of 'any' means any type is valid, so if it's a real node we can move on to the next          
            if($node_type == 'any') {
                continue;
            }

            // If the node doesn't match the specified type, don't import the item and also notify the user why it failed
            if($referenced_node->type != $node_type) {
                unset($result->items[$item_key]);
                _mukurtu_feeds_tamper_plugins_require_valid_node_log($source, $item_key, $element_key, $node_ref, 'did not reference the requried node type of "' . $node_type . '"');
                return;
            }
            
        } else {
            // The node could not be loaded, skip the import for this item and notify the user
            unset($result->items[$item_key]);
            _mukurtu_feeds_tamper_plugins_require_valid_node_log($source, $item_key, $element_key, $node_ref, 'was not a valid node reference');
            return;
        }
    }
}

/**
 *  Lookup nid from guid
 */
function _mukurtu_feeds_tamper_plugins_require_valid_node_lookup_node_by_guid($guid) {
  return db_select('feeds_item')
    ->fields('feeds_item', array('entity_id'))
    ->condition('entity_type', 'node')
    ->condition('guid', $guid)
    ->execute()
    ->fetchField();
}


// adapted from feeds required.inc
function _mukurtu_feeds_tamper_plugins_require_valid_node_log($source, $item_key, $element_key, $field, $reason) {
    $args = array('@key' => $element_key, '@num' => $item_key, '@field' => $field, '@reason' => $reason);
    $source->log('feeds_tamper:required valid node reference', 'Feed item number @num skipped because @key "@field" @reason.', $args);
    drupal_set_message(t('Feed item number @num skipped because @key "@field" @reason.', $args));
}