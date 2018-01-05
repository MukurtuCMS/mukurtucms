<?php
/**
 * @file
 * ma_file_fixity.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ma_file_fixity_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filehash_algos';
  $strongarm->value = array(
    'md5' => 'md5',
    'sha1' => 'sha1',
    'sha256' => 'sha256',
  );
  $export['filehash_algos'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filehash_dedupe';
  $strongarm->value = 0;
  $export['filehash_dedupe'] = $strongarm;

  return $export;
}
