<?php

/**
 * @file
 * ma_scald.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function ma_scald_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: image
  $overrides["image.large.effects|0|data|height"]["DELETED"] = TRUE;
  $overrides["image.large.effects|0|data|upscale"]["DELETED"] = TRUE;
  $overrides["image.large.effects|0|data|width"]["DELETED"] = TRUE;
  $overrides["image.large.effects|0|name"] = 'imagecache_autorotate';
  $overrides["image.large.effects|0|weight"] = -2;
  $overrides["image.large.effects|1"] = array(
    'data' => array(),
    'name' => 'imagecache_autorotate',
    'weight' => -1,
  );
  $overrides["image.large.effects|2"] = array(
    'data' => array(
      'height' => 480,
      'upscale' => 0,
      'width' => 480,
    ),
    'name' => 'image_scale',
    'weight' => 0,
  );
  $overrides["image.medium.effects|0|data|height"]["DELETED"] = TRUE;
  $overrides["image.medium.effects|0|data|upscale"]["DELETED"] = TRUE;
  $overrides["image.medium.effects|0|data|width"]["DELETED"] = TRUE;
  $overrides["image.medium.effects|0|name"] = 'imagecache_autorotate';
  $overrides["image.medium.effects|0|weight"] = -2;
  $overrides["image.medium.effects|1"] = array(
    'data' => array(
      'height' => 220,
      'upscale' => 1,
      'width' => 220,
    ),
    'name' => 'image_scale',
    'weight' => 0,
  );
  $overrides["image.medium.effects|2"] = array(
    'data' => array(),
    'name' => 'imagecache_autorotate',
    'weight' => -1,
  );
  $overrides["image.thumbnail.effects|0|data|height"]["DELETED"] = TRUE;
  $overrides["image.thumbnail.effects|0|data|upscale"]["DELETED"] = TRUE;
  $overrides["image.thumbnail.effects|0|data|width"]["DELETED"] = TRUE;
  $overrides["image.thumbnail.effects|0|name"] = 'imagecache_autorotate';
  $overrides["image.thumbnail.effects|0|weight"] = -2;
  $overrides["image.thumbnail.effects|1"] = array(
    'data' => array(
      'height' => 100,
      'upscale' => 1,
      'width' => 100,
    ),
    'name' => 'image_scale',
    'weight' => 0,
  );
  $overrides["image.thumbnail.effects|2"] = array(
    'data' => array(),
    'name' => 'imagecache_autorotate',
    'weight' => -1,
  );

 return $overrides;
}
