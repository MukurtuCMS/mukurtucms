<?php

/**
 * @file
 * Make field required. If not present, the feed item will be removed.
 */

$plugin = array(
  'form' => 'feeds_tamper_required_form',
  'callback' => 'feeds_tamper_required_callback',
  'name' => 'Required field',
  'multi' => 'direct',
  'category' => 'Filter',
);

function feeds_tamper_required_form($importer, $element_key, $settings) {
  $form = array();

  $form['help'] = array(
    '#markup' => t('Make this field required. If it is empty, the feed item will not be saved.'),
  );

  $form['invert'] = array(
    '#type' => 'checkbox',
    '#title' => t('Invert filter'),
    '#default_value' => !empty($settings['invert']),
    '#description' => t('Inverting the filter will save items only if the field is empty.'),
  );

  $form['log'] = array(
    '#type' => 'checkbox',
    '#default_value' => !empty($settings['log']),
    '#title' => t('Log'),
    '#description' => t('Log to the Feed log and print a message when a required feed item is filtered.'),
  );

  return $form;
}

function feeds_tamper_required_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (!empty($settings['invert'])) {
    if (!empty($field) || $field == '0') {
      unset($result->items[$item_key]);
    }

    return;
  }

  if (!empty($field) || $field == '0') {
    // Mukurtu specific change. Because of the changes we've made to allow partial
    // updates in feeds imports, not all fields get cleared. This means we end up with
    // some untouched fields having single element arrays that contain a single empty
    // string. We check for that here and count that as missing.
    if (!(is_array($field) && count($field) == 1 && isset($field[0]) && empty($field[0]))) {
      return;
    }
  }

  unset($result->items[$item_key]);

  if (!empty($settings['log'])) {
    _feeds_tamper_required_log($source, $item_key, $element_key);
  }
}

function _feeds_tamper_required_log($source, $item_key, $element_key) {
  $args = array('@key' => $element_key, '@num' => $item_key);

  $source->log('feeds_tamper:required', 'Feed item number @num skipped because @key was empty.', $args);
  drupal_set_message(t('Feed item number @num skipped because @key was empty.', $args));
}
