<?php
/**
 * @file
 * ma_glossary.context_config.inc
 */

/**
 * Implements hook_default_scald_context_config().
 */
function ma_glossary_default_scald_context_config() {
  $export = array();

  $context_config = new stdClass();
  $context_config->disabled = FALSE; /* Edit this to true to make a default context_config disabled initially */
  $context_config->api_version = 1;
  $context_config->context = 'mukurtu_glossary_table';
  $context_config->transcoder = array(
    'audio' => array(
      '*' => 'passthrough',
    ),
    'file' => array(
      '*' => 'passthrough',
    ),
    'image' => array(
      '*' => 'passthrough',
    ),
    'video' => array(
      '*' => 'passthrough',
    ),
  );
  $context_config->player = array(
    'audio' => array(
      '*' => 'default',
      'settings' => array(),
    ),
    'file' => array(
      '*' => 'default',
    ),
    'image' => array(
      '*' => 'default',
    ),
    'video' => array(
      '*' => 'default',
    ),
  );
  $context_config->data = array(
    'width' => '666px',
    'height' => '666px',
  );
  $export['mukurtu_glossary_table'] = $context_config;

  return $export;
}
