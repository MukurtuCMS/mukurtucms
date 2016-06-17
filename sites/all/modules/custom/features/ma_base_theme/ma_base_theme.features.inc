<?php
/**
 * @file
 * ma_base_theme.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_base_theme_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ma_base_theme_image_default_styles() {
  $styles = array();

  // Exported image style: carousel_thumbnail.
  $styles['carousel_thumbnail'] = array(
    'name' => 'carousel_thumbnail',
    'label' => 'Carousel Thumbnail',
    'effects' => array(
      10 => array(
        'label' => 'Autorotate',
        'help' => 'Autorotate image based on EXIF orientation and reset that tag.',
        'effect callback' => 'imagecache_autorotate_effect',
        'dimensions callback' => 'imagecache_autorotate_dimensions',
        'form callback' => 'imagecache_autorotate_form',
        'summary theme' => 'imagecache_autorotate_summary',
        'module' => 'imagecache_autorotate',
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'digital_heritage_full_content',
    'label' => 'digital_heritage_full_content',
    'effects' => array(
      3 => array(
        'label' => 'Autorotate',
        'help' => 'Autorotate image based on EXIF orientation and reset that tag.',
        'effect callback' => 'imagecache_autorotate_effect',
        'dimensions callback' => 'imagecache_autorotate_dimensions',
        'form callback' => 'imagecache_autorotate_form',
        'summary theme' => 'imagecache_autorotate_summary',
        'module' => 'imagecache_autorotate',
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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
    'name' => 'full',
    'label' => 'full',
    'effects' => array(
      12 => array(
        'label' => 'Autorotate',
        'help' => 'Autorotate image based on EXIF orientation and reset that tag.',
        'effect callback' => 'imagecache_autorotate_effect',
        'dimensions callback' => 'imagecache_autorotate_dimensions',
        'form callback' => 'imagecache_autorotate_form',
        'summary theme' => 'imagecache_autorotate_summary',
        'module' => 'imagecache_autorotate',
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      11 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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

  // Exported image style: related_items_teaser.
  $styles['related_items_teaser'] = array(
    'name' => 'related_items_teaser',
    'label' => 'Related Items Teaser',
    'effects' => array(
      14 => array(
        'label' => 'Autorotate',
        'help' => 'Autorotate image based on EXIF orientation and reset that tag.',
        'effect callback' => 'imagecache_autorotate_effect',
        'dimensions callback' => 'imagecache_autorotate_dimensions',
        'form callback' => 'imagecache_autorotate_form',
        'summary theme' => 'imagecache_autorotate_summary',
        'module' => 'imagecache_autorotate',
        'name' => 'imagecache_autorotate',
        'data' => array(),
        'weight' => -10,
      ),
      13 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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
