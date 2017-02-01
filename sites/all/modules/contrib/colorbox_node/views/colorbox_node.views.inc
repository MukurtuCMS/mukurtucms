<?php

/**
 * @file
 * colorbox_node.views.inc
 */

/**
 * Implementation of hook_views_data()
 */
function colorbox_node_views_data_alter(&$views_data) {
  // We are going to override our views_handler_field_node
  // This we we can provide extra options for our node to 
  // have the linked content displayed inside a colorbox.
  $views_data['node']['nid']['field']['handler'] = 'colorbox_node_handler_field_colorbox_node';
  $views_data['node']['title']['field']['handler'] = 'colorbox_node_handler_field_colorbox_node';
  $views_data['views_entity_node']['view_node']['field']['handler'] = 'colorbox_node_handler_field_colorbox_node_link';
}
