<?php

/**
 * @file
 * File name: scald.features.inc.
 */

/**
 * Implements hook_features_export_options().
 */
function scald_context_type_features_export_options() {
  $options = array();

  // Get all contexts by types.
  $contexts = scald_contexts();
  $types = scald_types();

  foreach ($contexts as $cname => $cdata) {
    foreach ($types as $tname => $tdata) {
      $options[$cname . '-' . $tname] = drupal_ucfirst(check_plain($cdata['title'])) . ': ' . check_plain($tdata->title);
    }
  }

  return $options;
}

/**
 * Implements hook_features_export().
 */
function scald_context_type_features_export($data, &$export, $module_name = '') {
  // Add scald module as a dependency.
  $export['dependencies']['scald'] = 'scald';

  foreach ($data as $key => $name) {
    $context_name = _scald_context_type_extract($name, 'context');
    $context = scald_context_load($context_name);

    // Add dependency to module provider.
    $export['dependencies'][$context['provider']] = $context['provider'];

    // Add it to the export data.
    $export['features']['scald_context_type'][$name] = $name;
  }

  return $export;
}

/**
 * Implements hook_features_export_render().
 */
function scald_context_type_features_export_render($module, $data) {
  // Sanitize array if needed.
  foreach ($data as $key => $name) {
    unset($data[$key]);
    $data[$name] = $name;
  }

  // Iterate over data to export.
  $code  = '  $contexts = array();' . "\n";
  foreach ($data as $key => $name) {
    $context_name = _scald_context_type_extract($name, 'context');
    $type_name    = _scald_context_type_extract($name, 'type');

    // Clean context from other types.
    $context = _scald_context_type_clean($context_name, $type_name);

    // Export clean context config.
    $data[$name] = $context;

    // Generates code.
    $code .= '  $contexts[\'' . $name . '\'] = ' . features_var_export($data[$name], '  ') . ";" . "\n";
  }

  $code .= '  return $contexts;';

  // Try to find the old file "module.context_config.inc" and delete it.
  _scald_context_clean_export($module);

  return array('scald_default_context_types' => $code);
}

/**
 * Implements hook_features_revert().
 */
function scald_context_type_features_revert($module) {
  scald_context_type_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function scald_context_type_features_rebuild($module) {
  $contexts = module_invoke($module, 'scald_default_context_types');
  $regroup = array();

  // Get default contexts and regroup by type.
  foreach ($contexts as $key => $context) {
    $context_name = _scald_context_type_extract($key, 'context');

    // Ensure there's at least a stub for each of the exported properties.
    $context = array_merge_recursive($context, array(
      'player' => array(),
      'transcoder' => array(),
      'data' => array(),
    ));

    if (!isset($regroup[$context_name])) {
      // Initialize this context.
      $regroup[$context_name] = $context;
    }
    else {
      // Merge types data.
      $regroup[$context_name]['player']      = array_merge_recursive($regroup[$context_name]['player'], $context['player']);
      $regroup[$context_name]['transcoder']  = array_merge_recursive($regroup[$context_name]['transcoder'], $context['transcoder']);
      $regroup[$context_name]['data']        = array_merge_recursive($regroup[$context_name]['data'], $context['data']);
    }
  }

  // Once whole contexts are regrouped.
  foreach ($regroup as $name => $data) {
    $config = scald_context_config_load($name);

    foreach (scald_types() as $type) {
      if (isset($data['transcoder'][$type->type])) {
        $config->transcoder[$type->type] = $data['transcoder'][$type->type];
      }

      if (isset($data['player'][$type->type])) {
        $config->player[$type->type] = $data['player'][$type->type];
      }

      // At this point data is per-context, not per-context-per-bundle so this
      // is a little redundant to store on every bundle.  But if #2600088 is
      // resolved then this framework should support existing exports without
      // needing to change.
      if (isset($data['data'][$type->type])) {
        $config->data = $data['data'][$type->type];
      }
    }

    scald_context_config_save($config);
  }

  cache_clear_all('*', 'cache_scald', TRUE);
}

/**
 * Helper function to extract context name and type name from a string.
 *
 * @param string $string
 *   The array key to extract the context/type name from.
 * @param string $object
 *   The object name to extract : can be type or context.
 *
 * @return string
 *   The machine name of the extracted object.
 */
function _scald_context_type_extract($string, $object = 'context') {
  $regex = "/(.+)-(.+)/";

  preg_match($regex, $string, $matches);

  if ($object == 'context') {
    return $matches[1];
  }
  else {
    return $matches[2];
  }
}

/**
 * Helper function to clean a context given a type.
 *
 * @param string $name
 *   The context machine name.
 * @param string $type
 *   The type machine name.
 *
 * @return array
 *   Array with player, transcoder and data.
 */
function _scald_context_type_clean($name, $type) {
  $config = scald_context_config_load($name);
  return array(
    'player' => array(
      $type => $config->player[$type],
    ),
    'transcoder' => array(
      $type => $config->transcoder[$type],
    ),
    // At this point data is per-context, not per-context-per-bundle so this
    // is a little redundant to store on every bundle.  But if #2600088 is
    // resolved then this framework should support existing exports without
    // needing to change.
    'data' => array(
      $type => $config->data,
    ),
  );
}

/**
 * Helper function to clean old CTools export files.
 *
 * Used when the user choose to switch to new feature export,
 * after recreating the features.
 * It warns about deprecation of the old "module.context_config.inc" file.
 */
function _scald_context_clean_export($module) {
  $path = drupal_get_path('module', $module) . '/' . $module . '.context_config.inc';
  if (file_exists($path)) {
    features_log(t('The file @filename has been deprecated and can be removed.', array('@filename' => $path)), 'status');
  }
}
