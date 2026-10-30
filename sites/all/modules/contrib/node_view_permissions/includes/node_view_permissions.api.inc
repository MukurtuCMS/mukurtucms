<?php

/**
 * Get list of view permissions activate content types.
 * 
 * @return
 *   Array of node types.
 */
function node_view_permissions_get_configured_types() {
  $configured_types = array();
  
  foreach (node_type_get_types() as $type => $info) {
    if (variable_get('node_view_permissions_' . $type, 0)) {
      $configured_types[] = $type;
    }
  }
  
  return $configured_types;
}

/**
 * Check if content type view permissions are activate.
 * 
 * @param $type
 *   Node type.
 * 
 * @return
 *   TRUE if active.
 *   FALSE otherwise
 */
function node_view_permissions_check_node_type_activation($type) {
  return (bool) variable_get('node_view_permissions_' . $type, 0);
}
