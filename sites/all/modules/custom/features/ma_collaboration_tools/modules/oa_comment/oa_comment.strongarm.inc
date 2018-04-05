<?php
/**
 * @file
 * oa_comment.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_comment_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fasttoggle_comments_rw_only';
  $strongarm->value = 0;
  $export['fasttoggle_comments_rw_only'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fasttoggle_comment_status_settings';
  $strongarm->value = array(
    'status_status' => 'status_status',
  );
  $export['fasttoggle_comment_status_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fasttoggle_label_style';
  $strongarm->value = '1';
  $export['fasttoggle_label_style'] = $strongarm;

  return $export;
}
