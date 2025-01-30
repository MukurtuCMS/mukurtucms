<?php

/**
 * @file
 * ma_base_theme.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_base_theme_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_base_theme_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ma_base_theme_image_default_styles() {
  $styles = array();

  // Exported image style: carousel_thumbnail.
  $styles['carousel_thumbnail'] = array(
    'label' => 'Carousel Thumbnail',
    'effects' => array(
      10 => array(
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 195,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: digital_heritage_full_content.
  $styles['digital_heritage_full_content'] = array(
    'label' => 'digital_heritage_full_content',
    'effects' => array(
      3 => array(
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 580,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: full.
  $styles['full'] = array(
    'label' => 'full',
    'effects' => array(
      12 => array(
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: mukurtu_theme_3_2_ratio.
  $styles['mukurtu_theme_3_2_ratio'] = array(
    'label' => 'Mukurtu theme 3:2 ratio',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 800,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: mukurtu_theme_4_3_ratio.
  $styles['mukurtu_theme_4_3_ratio'] = array(
    'label' => 'Mukurtu theme 4:3 ratio',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 600,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: mukurtu_theme_7_4_ratio.
  $styles['mukurtu_theme_7_4_ratio'] = array(
    'label' => 'Mukurtu theme 7:4 ratio',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: related_items_teaser.
  $styles['related_items_teaser'] = array(
    'label' => 'Related Items Teaser',
    'effects' => array(
      14 => array(
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      13 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 280,
          'height' => 280,
          'upscale' => 1,
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}
