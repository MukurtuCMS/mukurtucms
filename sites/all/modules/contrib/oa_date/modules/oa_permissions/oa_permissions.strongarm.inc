<?php
/**
 * @file
 * oa_permissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_permissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_manager_admin_role';
  $strongarm->value = 1;
  $export['og_group_manager_admin_role'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_manager_full_access';
  $strongarm->value = 0;
  $export['og_group_manager_full_access'] = $strongarm;

  return $export;
}
