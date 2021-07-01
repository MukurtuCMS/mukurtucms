<?php

/**
 * @file
 * Holds features implementation.
 */

/**
 * Implements hook_features_export_options().
 */
function paragraphs_features_export_options() {
  $bundles = paragraphs_bundle_load();
  $names = array();
  foreach ($bundles as $key => $value) {
    $names[$key] = $value->name;
  }
  return $names;
}

/**
 * Implements hook_features_export().
 */
function paragraphs_features_export($data, &$export, $module_name = '') {
  $pipe = array();
  $map = features_get_default_map('paragraphs');

  foreach ($data as $type) {
    if ($info = paragraphs_bundle_load($type)) {
      $export['features']['paragraphs'][$type] = $type;
      $export['dependencies']['paragraphs'] = 'paragraphs';
      $export['dependencies']['features'] = 'features';

      $fields = field_info_instances('paragraphs_item', $type);
      foreach ($fields as $name => $field) {
        $pipe['field_instance'][] = "paragraphs_item-{$field['bundle']}-{$field['field_name']}";
      }
    }
  }

  return $pipe;

}

/**
 * Implements hook_features_export_render().
 */
function paragraphs_features_export_render($module, $data, $export = NULL) {
  $elements = array(
    'name' => FALSE,
    'bundle' => FALSE,
    'locked' => FALSE,
  );
  $output = array();
  $output[] = '  $items = array(';
  foreach ($data as $type) {
    if ($info = paragraphs_bundle_load($type)) {
      $output[] = "    '{$type}' => array(";
      foreach ($elements as $key => $t) {
        if ($t) {
          $text = str_replace("'", "\'", $info->$key);
          $text = !empty($text) ? "t('{$text}')" : "''";
          $output[] = "      '{$key}' => {$text},";
        }
        else {
          $output[] = "      '{$key}' => '{$info->$key}',";
        }
      }
      $output[] = "    ),";
    }
  }
  $output[] = '  );';
  $output[] = '  return $items;';
  $output = implode("\n", $output);
  return array('paragraphs_info' => $output);
}

/**
 * Implements hook_features_revert().
 *
 * @param $module
 * name of module to revert content for
 */
function paragraphs_features_revert($module = NULL) {
  if ($default_types = features_get_default('paragraphs', $module)) {
    foreach ($default_types as $type_name => $type_info) {
      db_delete('paragraphs_bundle')
        ->condition('bundle', $type_name)
        ->execute();
      $bundle = new stdClass();
      $bundle->bundle = $type_info['bundle'];
      $bundle->locked = $type_info['locked'];
      $bundle->name = $type_info['name'];
      paragraphs_bundle_save($bundle);
    }
    paragraphs_bundle_load(NULL, TRUE);
    menu_rebuild();
  }
}

/**
 * Implements hook_features_rebuild().
 */
function paragraphs_features_rebuild($module_name) {
  paragraphs_features_revert($module_name);
}
