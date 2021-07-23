<?php

/**
 * @file
 * ma_services.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_services_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'services_allowed_extensions';
  $strongarm->value = 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp mov mp4 webm mkv 3gp ts m4v wav ogg mp3 m4a ogv';
  $export['services_allowed_extensions'] = $strongarm;

  return $export;
}
