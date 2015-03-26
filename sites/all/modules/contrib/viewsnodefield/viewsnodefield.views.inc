<?php

/**
 * Implements hook_views_data().
 */
function viewsnodefield_views_data_alter(&$data) {
  $data['node']['nodefield'] = array(
    'field' => array(
      'title' => t('Node field'),
      'help' => t('Renders the node view of a the node.'),
      'handler' => 'views_handler_field_node_field',
    ),
  );
}
