<?php
/**
 * @file
 * Contains \Drupal\exif\ExifFactory
 */

namespace Drupal\exif;


include_once drupal_get_path('module', 'exif') .'/ExifPHPExtension.php';
include_once drupal_get_path('module', 'exif') .'/SimpleExiftoolFacade.php';

class ExifFactory {


  public static function getExtractionSolutions() {
    return array(
      "simple_exiftool" => "exiftool",
      "php_extensions"  => "php extensions"
    );
  }

  public static function getExifInterface() {
    $extractionSolution = variable_get('exif_extraction_solution');
    $useExifToolSimple  = $extractionSolution == "simple_exiftool";
    if (isset($useExifToolSimple) && $useExifToolSimple && SimpleExifToolFacade::checkConfiguration()) {
      return SimpleExifToolFacade::getInstance();
    } else {
      //default case for now (same behavior as previous versions)
      return ExifPHPExtension::getInstance();
    }
  }

}
