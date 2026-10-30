<?php
//$Id:

/**
 *
 * @author Jean-Philippe Hautin
 * This is a helper class to handle the whole data processing of exif  with exiftool
 *
 */
namespace Drupal\exif;

include_once drupal_get_path('module', 'exif') .'/ExifInterface.php';

class SimpleExifToolFacade implements ExifInterface {

  static private $instance = NULL;

  /**
   * We are implementing a singleton pattern
   */
  private function __construct() {
  }

  public static function getInstance() {
    if (is_null(self::$instance)) {
      self::$instance = new self;
    }
    return self::$instance;
  }

  public function getFieldKeys() {
    return array();
  }
  /*
  public static function getMetadataSections() {
    $sections = array(
      'File',
      'EXIF',
      'GPS',
      'IPTC',
      'XMP',
      'MakerNotes',
      'Photoshop',
      'ICC_Profile',
      'MIE',
      'APP12',
      'APP13',
      'APP14',
      'DICOM',
      'GeoTIFF',
      'JFIF',
      'Composite'
    );
    return $sections;
  }
  */

  /**
   * Going through all the fields that have been created for a given node type
   * and try to figure out which match the naming convention -> so that we know
   * which exif information we have to read
   *
   * Naming convention are: field_exif_xxx (xxx would be the name of the exif
   * tag to read
   *
   * @param $arCckFields array of CCK fields
   * @return array a list of exif tags to read for this image
   */
  public function getMetadataFields($arCckFields = array()) {
    foreach ($arCckFields as $drupal_field => $metadata_settings) {
      $metadata_field = $metadata_settings['metadata_field'];
      $ar = explode("_", $metadata_field);
      if (isset($ar[0])) {
        $section = $ar[0];
        unset($ar[0]);
        $arCckFields[$drupal_field]['metadata_field'] = array(
          'section' => $section,
          'tag' => implode("_", $ar)
        );
      }
    }
    return $arCckFields;
  }


  public static function checkConfiguration() {
    $exiftoolLocation = self::getExecutable();
    return isset($exiftoolLocation) && is_executable($exiftoolLocation);
  }

  public static function getExecutable() {
    return variable_get('exif_exiftool_location');
  }

  function runTool($file,$enable_sections = true,$enable_markerNote = false,$enable_non_supported_tags = false) {
    $params = ' -E -n -json ';
    if ($enable_sections) {
      $params .= '-g -struct ';
    }
    if ($enable_markerNote) {
      $params .= '-fast ';
    }
    else {
      $params .= '-fast2 ';
    }
    if ($enable_non_supported_tags) {
      $params .= '-u -U ';
    }
    // Escape all of the arguments passed to the function.
    // Note: If params is expanded so it is customizable, make sure that each
    // piece is passed through escapeshellarg().
    $commandline = escapeshellcmd('exiftool' . $params . escapeshellarg($file));
    $output = array();
    $returnCode = 0;
    exec($commandline,$output,$returnCode);
    //print_r($output);
    if ($returnCode!=0) {
      $output= "";
      watchdog('exif', 'Exiftool returns an error. Can not extract metadata from file !file', array('!file' => $file), WATCHDOG_WARNING);
    }
    $info = implode("\n",$output);
    return $info;
  }

  function tolowerJsonResult($data) {
    $result = array();
    foreach($data as $section => $values) {
      if (is_array($values)) {
        $result[strtolower($section)]=array_change_key_case($values);
      } else {
        $result[strtolower($section)]=$values;
      }

    }
    return $result;
  }

  function readAllInformation($file,$enable_sections = true,$enable_markerNote = false,$enable_non_supported_tags = false) {
    $jsonAsString = $this->runTool($file,$enable_sections,$enable_markerNote,$enable_non_supported_tags);
    $json = json_decode($jsonAsString,true);
    $errorCode = json_last_error();
    if ($errorCode == JSON_ERROR_NONE) {
      return $this->tolowerJsonResult($json[0]);
    } else {
      $errorMessage = "";
      switch ($errorCode) {
        case JSON_ERROR_DEPTH:
          $errorMessage='Maximum stack depth exceeded';
          break;
        case JSON_ERROR_STATE_MISMATCH:
          $errorMessage='Underflow or the modes mismatch';
          break;
        case JSON_ERROR_CTRL_CHAR:
          $errorMessage='Unexpected control character found';
          break;
        case JSON_ERROR_SYNTAX:
          $errorMessage='Syntax error, malformed JSON';
          break;
        case JSON_ERROR_UTF8:
          $errorMessage='Malformed UTF-8 characters, possibly incorrectly encoded';
          break;
        default:
          $errorMessage='Unknown error';
          break;
      }
      // Logs a notice
      watchdog('exif', 'Error reading information from exiftool for file !file: !message', array('!file' => $file, '!message' => $errorMessage), WATCHDOG_NOTICE);
      return array();
    }
  }

  /**
   * $arOptions liste of options for the method :
   * # enable_sections : (default : TRUE) retrieve also sections.
   * @param string $file
   * @param boolean $enable_sections
   * @return array $data
   */
  public function readMetadataTags($file, $enable_sections = TRUE) {
    if (!file_exists($file)) {
      return array();
    }
    $data = $this->readAllInformation($file, $enable_sections);
    return $data;
  }

  function filterMetadataTags($arSmallMetadata, $arTagNames) {
    $info = array();
    foreach ($arTagNames as $drupal_field => $metadata_settings) {
      $tagName = $metadata_settings['metadata_field'];
      if (!empty($arSmallMetadata[$tagName['section']][$tagName['tag']])) {
        $info[$tagName['section']][$tagName['tag']] = $arSmallMetadata[$tagName['section']][$tagName['tag']];
      }
    }
    return $info;
  }




}
