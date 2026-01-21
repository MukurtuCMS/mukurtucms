<?php

/**
 * @file
 * ma_mobile_client.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_mobile_client_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'services_node_index_page_size';
  $strongarm->value = 0;
  $export['services_node_index_page_size'] = $strongarm;

  return $export;
}
