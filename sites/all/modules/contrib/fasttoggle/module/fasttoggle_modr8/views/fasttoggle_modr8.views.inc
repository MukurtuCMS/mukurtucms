<?php
/**
 * @file
 * Views data definitions for Fasttoggle.
 *
 * This file defines how Views should get Fasttoggle data.
 */

/**
 * Implementation of hook_views_data_alter()
 */

function fasttoggle_modr8_views_data_alter(&$data) {

  $data['node']['fasttoggle_moderate_node'] = array(
      'field' => array(
        'title' => t('Moderate Link (Fasttoggle)'),
        'help' => t('Provide a simple link to moderate the node.'),
        'handler' => 'fasttoggle_node_views_handler_field_node_link',
        'fasttoggle_node' => array(
          'key' => 'moderate',
          'additional_fields' => array('moderate' => 'moderate'),
          ),
        ),
      );
}
