<?php

/**
 * @file
 * ma_collaboration_tools.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ma_collaboration_tools_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mailhandler_comments-status-default_value';
  $feeds_tamper->importer = 'mailhandler_comments';
  $feeds_tamper->source = 'status';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['mailhandler_comments-status-default_value'] = $feeds_tamper;

  return $export;
}
