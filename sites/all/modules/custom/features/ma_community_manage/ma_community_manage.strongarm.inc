<?php

/**
 * @file
 * ma_community_manage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_community_manage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_community';
  $strongarm->value = '0';
  $export['language_content_type_community'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_invite_send_invitation_by_rules';
  $strongarm->value = 0;
  $export['og_invite_send_invitation_by_rules'] = $strongarm;

  return $export;
}
