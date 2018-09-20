<?php

/**
 * @file
 * Feeds hooks implementations.
 */

/**
 * Implements hook_feeds_config_defaults().
 *
 * @see feeds_tests_form_feedsimporter_feeds_form_alter()
 */
function feeds_tests_feeds_config_defaults(FeedsConfigurable $configurable) {
  if (!variable_get('feeds_tests_hook_config_defaults', FALSE)) {
    return;
  }

  if ($configurable instanceof FeedsImporter) {
    return array(
      'feeds_tests_extra_setting' => FALSE,
    );
  }
}

/**
 * Implements hook_feeds_PLUGIN_TYPE_config_defaults() for plugin 'fetcher'.
 *
 * @see feeds_tests_form_feedshttpfetcher_feeds_form_alter()
 */
function feeds_tests_feeds_fetcher_config_defaults(FeedsPlugin $plugin) {
  if (!variable_get('feeds_tests_hook_config_defaults', FALSE)) {
    return;
  }

  return array(
    'feeds_tests_fetcher_extra_setting' => FALSE,
  );
}

/**
 * Implements hook_feeds_PLUGIN_TYPE_config_defaults() for plugin 'parser'.
 *
 * @see feeds_tests_form_feedscsvparser_feeds_form_alter()
 */
function feeds_tests_feeds_parser_config_defaults(FeedsPlugin $plugin) {
  if (!variable_get('feeds_tests_hook_config_defaults', FALSE)) {
    return;
  }

  return array(
    'feeds_tests_parser_extra_setting' => TRUE,
  );
}

/**
 * Implements hook_feeds_PLUGIN_TYPE_config_defaults() for plugin 'processor'.
 *
 * @see feeds_tests_form_feedsnodeprocessor_feeds_form_alter()
 */
function feeds_tests_feeds_processor_config_defaults(FeedsPlugin $plugin) {
  if (!variable_get('feeds_tests_hook_config_defaults', FALSE)) {
    return;
  }

  return array(
    'feeds_tests_processor_extra_setting' => '',
  );
}
