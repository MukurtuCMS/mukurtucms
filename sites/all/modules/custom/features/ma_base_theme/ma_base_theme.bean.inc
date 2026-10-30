<?php

/**
 * @file
 * ma_base_theme.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function ma_base_theme_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'hero_image_one_column';
  $bean_type->label = 'Hero Image: One Column';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['hero_image_one_column'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'hero_image_two_columns';
  $bean_type->label = 'Hero Image: Two Columns';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['hero_image_two_columns'] = $bean_type;

  return $export;
}
