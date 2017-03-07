<?php
/**
 * @file
 * Contains \Drupal\exif\ExifInterface
 */

namespace Drupal\exif;


interface ExifInterface {
  function getMetadataFields($arCckFields = array());

  function readMetadataTags($file, $enable_sections = TRUE);

  function getFieldKeys();
}
