<?php
//$Id:

/**
 *
 * @author Jean-Philippe Hautin
 * @author Raphael Schär
 * This is a helper class to handle the whole data processing of exif
 *
 */
namespace Drupal\exif;

include_once drupal_get_path('module', 'exif') .'/ExifInterface.php';

Class ExifPHPExtension implements ExifInterface {
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

  public static function getMetadataSections() {
    $sections = array(
      'exif',
      'file',
      'computed',
      'ifd0',
      'gps',
      'winxp',
      'iptc',
      'xmp'
    );
    return $sections;
  }

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
    $arSections = self::getMetadataSections();
    foreach ($arCckFields as $drupal_field => $metadata_settings) {
      $metadata_field = $metadata_settings['metadata_field'];
      $ar = explode("_", $metadata_field);
      if (isset($ar[0]) && in_array($ar[0], $arSections)) {
        $section = $ar[0];
        unset($ar[0]);
        $arCckFields[$drupal_field]['metadata_field'] = array(
          'section' => $section,
          'tag' => implode("_", $ar)
        );
      } else {
        //remove from the list a non usable description.
        unset($arCckFields[$drupal_field]);
        watchdog('exif', 'Not able to understand exif field settings !field', array('!field' => $metadata_field), WATCHDOG_WARNING);
      }
    }
    return $arCckFields;
  }

  public static function checkConfiguration() {
    return function_exists('exif_read_data') && function_exists('iptcparse');
  }


  /**
   * Helper function to reformat fields where required.
   *
   * Some values (lat/lon) break down into structures, not strings.
   * Dates should be parsed nicely.
   */
  function _reformat($data) {
    // Make the key lowercase as field names must be.
    $data = array_change_key_case($data, CASE_LOWER);
    foreach ($data as $key => &$value) {
      if (is_array($value))  {
        $value = array_change_key_case($value, CASE_LOWER);
        switch ($key) {
          // GPS values
          case 'gps_latitude':
          case 'gps_longitude':
          case 'gpslatitude':
          case 'gpslongitude':
            $value = $this->_exif_reformat_DMS2D($value, $data[$key . 'ref']);
            break;
        }
      } else {
        if (is_string($value)) {
          $value=trim($value);
        }
        if (!drupal_validate_utf8($value)) {
          $value = utf8_encode($value);
        }
        switch ($key) {
          // String values.
          case 'usercomment':
          case 'title':
          case 'comment':
          case 'author':
          case 'subject':
            if ($this->startswith($value, 'UNICODE')) {
              $value = substr($value, 8);
            }
            $value = $this->_exif_reencode_to_utf8($value);
            break;

          // Date values.
          case 'filedatetime':
          	$value=date('c',$value);
          	break;
          case 'datetimeoriginal':
          case 'datetime':
          case 'datetimedigitized':
            // In case we get a datefield, we need to reformat it
            // to the ISO 8601 standard which will look something
            // like '2004-02-12T15:19:21'.
            $date_time = explode(" ", $value);
            $date_time[0] = str_replace(":", "-", $date_time[0]);
            if (variable_get('exif_granularity', 0) == 1) {
              $date_time[1] = "00:00:00";
            }
            $value = implode("T", $date_time);
            break;
          // GPS values.
          case 'gpsaltitude':
          case 'gpsimgdirection':
            if (!isset($data[$key . 'ref'])) {
              $data[$key . 'ref'] = 0;
            }
            $value = $this->_exif_reformat_DMS2D($value, $data[$key . 'ref']);
            break;
          case 'componentsconfiguration':
          case 'compression':
          case 'contrast':
          case 'exposuremode':
          case 'exposureprogram':
          case 'flash':
          case 'focalplaneresolutionunit':
          case 'gaincontrol':
          case 'lightsource':
          case 'meteringmode':
          case 'orientation':
          case 'resolutionunit':
          case 'saturation':
          case 'scenecapturetype':
          case 'sensingmethod':
          case 'sensitivitytype':
          case 'sharpness':
          case 'subjectdistancerange':
          case 'whitebalance':
            $human_descriptions = $this->getHumanReadableDescriptions()[$key];
            if (isset($human_descriptions[$value])) {
              $value = $human_descriptions[$value];
            }
	         break;
          // Exposure values.
          case 'exposuretime':
            if (strpos($value, '/') !== FALSE) {
              $value = $this->_normalise_fraction($value) . 's';
            }
            break;
          // Focal Length values.
          case 'focallength':
            if (strpos($value, '/') !== FALSE) {
              $value = $this->_normalise_fraction($value) . 'mm';
            }
            break;
        }
      }
    }
    return $data;
  }

  public function startswith($hay, $needle) {
    return substr($hay, 0, strlen($needle)) === $needle;
  }


  function _exif_reencode_to_utf8($value) {
    $unicode_list = unpack("v*", $value);
    $result = "";
    foreach ($unicode_list as $key => $value) {
      if ($value != 0) {
        $one_character = pack("C", $value);
        $temp = mb_convert_encoding('&#' . $value . ';', 'UTF-8', 'HTML-ENTITIES');
        $result .= $temp;
      }
    }
    return $result;
  }

  /**
   * Normalise fractions.
   */
  function _normalise_fraction($fraction) {
    $parts = explode('/', $fraction);
    $top = $parts[0];
    $bottom = $parts[1];

    if ($top > $bottom) {
      // Value > 1
      if (($top % $bottom) == 0) {
        $value = ($top / $bottom);
      }
      else {
        $value = round(($top / $bottom), 2);
      }
    }
    else {
      if ($top == $bottom) {
        // Value = 1
        $value = '1';
      }
      else {
        // Value < 1
        if ($top == 1) {
          $value = '1/' . $bottom;
        }
        else {
          if ($top != 0) {
            $value = '1/' . round(($bottom / $top), 0);
          }
          else {
            $value = '0';
          }
        }
      }
    }
    return $value;
  }

  /**
   * Helper function to change GPS co-ords into decimals.
   */
  function _exif_reformat_DMS2D($value, $ref) {
    if (!is_array($value)) {
      $value = array($value);
    }
    $dec = 0;
    $granularity = 0;
    foreach ($value as $element) {
      $parts = explode('/', $element);
      $dec += (float) (((float) $parts[0] / (float) $parts[1]) / pow(60, $granularity));
      $granularity++;
    }
    if ($ref == 'S' || $ref == 'W') {
      $dec *= -1;
    }
    return $dec;
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
    $data1 = $this->readExifTags($file, $enable_sections);
    $data2 = $this->readIPTCTags($file, $enable_sections);
    $data = array_merge($data1, $data2);

    if (is_array($data)) {
      foreach ($data as $section => $section_data) {
        $section_data = $this->_reformat($section_data);
        $data[$section] = $section_data;
      }
    }
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

  /**
   * Read the Information from a picture according to the fields specified in CCK
   * @param $file
   * @param $enable_sections
   * @return array
   */
  public function readExifTags($file, $enable_sections = TRUE) {
    $ar_supported_types = array('jpg', 'jpeg');
    if (!in_array(strtolower($this->getFileType($file)), $ar_supported_types)) {
      return array();
    }
    $exif = array();
    try {
      $exif = @exif_read_data($file, 0, $enable_sections);
    }
    catch (Exception $e) {
      watchdog('exif', 'Error while reading EXIF tags from image: !message', array('!message' => $e->getMessage()), WATCHDOG_WARNING);
    }
    $arSmallExif = array();
    foreach ((array) $exif as $key1 => $value1) {

      if (is_array($value1)) {
        $value2 = array();
        foreach ((array) $value1 as $key3 => $value3) {
          $value[strtolower($key3)] = $value3;
        }
      } else {
        $value = $value1;
      }
      $arSmallExif[strtolower($key1)] = $value;

    }
    return $arSmallExif;
  }

  private function getFileType($file) {
    $ar = explode('.', $file);
    $ending = $ar[count($ar) - 1];
    return $ending;
  }

  /**
   * Read IPTC tags.
   *
   * @param String $file Path to image to read IPTC from
   * @param boolean $enable_sections
   *
   */
  public function readIPTCTags($file, $enable_sections) {
    $humanReadableKey = $this->getHumanReadableIPTCkey();
    $infoImage = array();
    $size = GetImageSize ($file, $infoImage);
    $iptc = empty($infoImage["APP13"]) ? array() : iptcparse($infoImage["APP13"]);
    $arSmallIPTC = array();
    if (is_array($iptc)) {
      foreach ($iptc as $key => $value) {
        if (count($value) == 1) {
          $resultTag = $value[0];
        }
        else {
          $resultTag = $value;
        }
        if (array_key_exists($key, $humanReadableKey)) {
          $humanKey = $humanReadableKey[$key];
          $arSmallIPTC[$humanKey] = $resultTag;
        }
        else {
          $arSmallIPTC[$key] = $resultTag;
        }
      }
    }
    if ($enable_sections) {
      return array('iptc' => $arSmallIPTC);
    }
    else {
      return $arSmallIPTC;
    }
  }


  public function getHumanReadableExifKeys() {
    return array(
      "file_filename",
      "file_filedatetime",
      "file_filesize",
      "file_filetype",
      "file_mimetype",
      "file_sectionsfound",
      "computed_filename",
      "computed_filedatetime",
      "computed_filesize",
      "computed_filetype",
      "computed_mimetype",
      "computed_sectionsfound",
      "computed_html",
      "computed_height",
      "computed_width",
      "computed_iscolor",
      "computed_copyright",
      "computed_byteordermotorola",
      "computed_ccdwidth",
      "computed_aperturefnumber",
      "computed_usercomment",
      "computed_usercommentencoding",
      "computed_thumbnail.filetype",
      "computed_thumbnail.mimetype",
      "ifd0_filename",
      "ifd0_filedatetime",
      "ifd0_filesize",
      "ifd0_filetype",
      "ifd0_mimetype",
      "ifd0_sectionsfound",
      "ifd0_html",
      "ifd0_height",
      "ifd0_width",
      "ifd0_iscolor",
      "ifd0_byteordermotorola",
      "ifd0_ccdwidth",
      "ifd0_aperturefnumber",
      "ifd0_usercomment",
      "ifd0_usercommentencoding",
      "ifd0_thumbnail.filetype",
      "ifd0_thumbnail.mimetype",
      "ifd0_imagedescription",
      "ifd0_make",
      "ifd0_model",
      "ifd0_orientation",
      "ifd0_xresolution",
      "ifd0_yresolution",
      "ifd0_resolutionunit",
      "ifd0_software",
      "ifd0_datetime",
      "ifd0_artist",
      "ifd0_ycbcrpositioning",
      "ifd0_title",
      "ifd0_comments",
      "ifd0_author",
      "ifd0_subject",
      "ifd0_exif_ifd_pointer",
      "ifd0_gps_ifd_pointer",
      "thumbnail_filename",
      "thumbnail_filedatetime",
      "thumbnail_filesize",
      "thumbnail_filetype",
      "thumbnail_mimetype",
      "thumbnail_sectionsfound",
      "thumbnail_html",
      "thumbnail_height",
      "thumbnail_width",
      "thumbnail_iscolor",
      "thumbnail_byteordermotorola",
      "thumbnail_ccdwidth",
      "thumbnail_aperturefnumber",
      "thumbnail_usercomment",
      "thumbnail_usercommentencoding",
      "thumbnail_thumbnail.filetype",
      "thumbnail_thumbnail.mimetype",
      "thumbnail_imagedescription",
      "thumbnail_make",
      "thumbnail_model",
      "thumbnail_orientation",
      "thumbnail_xresolution",
      "thumbnail_yresolution",
      "thumbnail_resolutionunit",
      "thumbnail_software",
      "thumbnail_datetime",
      "thumbnail_artist",
      "thumbnail_ycbcrpositioning",
      "thumbnail_title",
      "thumbnail_comments",
      "thumbnail_author",
      "thumbnail_subject",
      "thumbnail_exif_ifd_pointer",
      "thumbnail_gps_ifd_pointer",
      "thumbnail_compression",
      "thumbnail_jpeginterchangeformat",
      "thumbnail_jpeginterchangeformatlength",
      "exif_filename",
      "exif_filedatetime",
      "exif_filesize",
      "exif_filetype",
      "exif_mimetype",
      "exif_sectionsfound",
      "exif_html",
      "exif_height",
      "exif_width",
      "exif_iscolor",
      "exif_byteordermotorola",
      "exif_ccdwidth",
      "exif_aperturefnumber",
      "exif_usercomment",
      "exif_usercommentencoding",
      "exif_thumbnail.filetype",
      "exif_thumbnail.mimetype",
      "exif_imagedescription",
      "exif_make",
      "exif_model",
      "exif_lens",
      "exif_lensid",
      "exif_orientation",
      "exif_xresolution",
      "exif_yresolution",
      "exif_resolutionunit",
      "exif_software",
      "exif_datetime",
      "exif_artist",
      "exif_ycbcrpositioning",
      "exif_title",
      "exif_comments",
      "exif_author",
      "exif_subject",
      "exif_exif_ifd_pointer",
      "exif_gps_ifd_pointer",
      "exif_compression",
      "exif_jpeginterchangeformat",
      "exif_jpeginterchangeformatlength",
      "exif_exposuretime",
      "exif_fnumber",
      "exif_exposureprogram",
      "exif_isospeedratings",
      "exif_exifversion",
      "exif_datetimeoriginal",
      "exif_datetimedigitized",
      "exif_componentsconfiguration",
      "exif_shutterspeedvalue",
      "exif_aperturevalue",
      "exif_exposurebiasvalue",
      "exif_meteringmode",
      "exif_flash",
      "exif_focallength",
      "exif_flashpixversion",
      "exif_colorspace",
      "exif_exifimagewidth",
      "exif_exifimagelength",
      "exif_interoperabilityoffset",
      "exif_focalplanexresolution",
      "exif_focalplaneyresolution",
      "exif_focalplaneresolutionunit",
      "exif_imageuniqueid",
      "gps_filename",
      "gps_filedatetime",
      "gps_filesize",
      "gps_filetype",
      "gps_mimetype",
      "gps_sectionsfound",
      "gps_html",
      "gps_height",
      "gps_width",
      "gps_iscolor",
      "gps_byteordermotorola",
      "gps_ccdwidth",
      "gps_aperturefnumber",
      "gps_usercomment",
      "gps_usercommentencoding",
      "gps_thumbnail.filetype",
      "gps_thumbnail.mimetype",
      "gps_imagedescription",
      "gps_make",
      "gps_model",
      "gps_orientation",
      "gps_xresolution",
      "gps_yresolution",
      "gps_resolutionunit",
      "gps_software",
      "gps_datetime",
      "gps_artist",
      "gps_ycbcrpositioning",
      "gps_title",
      "gps_comments",
      "gps_author",
      "gps_subject",
      "gps_exif_ifd_pointer",
      "gps_gps_ifd_pointer",
      "gps_compression",
      "gps_jpeginterchangeformat",
      "gps_jpeginterchangeformatlength",
      "gps_exposuretime",
      "gps_fnumber",
      "gps_exposureprogram",
      "gps_isospeedratings",
      "gps_exifversion",
      "gps_datetimeoriginal",
      "gps_datetimedigitized",
      "gps_componentsconfiguration",
      "gps_shutterspeedvalue",
      "gps_aperturevalue",
      "gps_exposurebiasvalue",
      "gps_meteringmode",
      "gps_flash",
      "gps_focallength",
      "gps_flashpixversion",
      "gps_colorspace",
      "gps_exifimagewidth",
      "gps_exifimagelength",
      "gps_interoperabilityoffset",
      "gps_gpsimgdirectionref",
      "gps_gpsimgdirection",
      "gps_focalplanexresolution",
      "gps_focalplaneyresolution",
      "gps_focalplaneresolutionunit",
      "gps_imageuniqueid",
      "gps_gpsversion",
      "gps_gpslatituderef",
      "gps_gpslatitude",
      "gps_gpslongituderef",
      "gps_gpslongitude",
      "gps_gpsaltituderef",
      "gps_gpsaltitude",
      "interop_filename",
      "interop_filedatetime",
      "interop_filesize",
      "interop_filetype",
      "interop_mimetype",
      "interop_sectionsfound",
      "interop_html",
      "interop_height",
      "interop_width",
      "interop_iscolor",
      "interop_byteordermotorola",
      "interop_ccdwidth",
      "interop_aperturefnumber",
      "interop_usercomment",
      "interop_usercommentencoding",
      "interop_thumbnail.filetype",
      "interop_thumbnail.mimetype",
      "interop_imagedescription",
      "interop_make",
      "interop_model",
      "interop_orientation",
      "interop_xresolution",
      "interop_yresolution",
      "interop_resolutionunit",
      "interop_software",
      "interop_datetime",
      "interop_artist",
      "interop_ycbcrpositioning",
      "interop_title",
      "interop_comments",
      "interop_author",
      "interop_subject",
      "interop_exif_ifd_pointer",
      "interop_gps_ifd_pointer",
      "interop_compression",
      "interop_jpeginterchangeformat",
      "interop_jpeginterchangeformatlength",
      "interop_exposuretime",
      "interop_fnumber",
      "interop_exposureprogram",
      "interop_isospeedratings",
      "interop_exifversion",
      "interop_datetimeoriginal",
      "interop_datetimedigitized",
      "interop_componentsconfiguration",
      "interop_shutterspeedvalue",
      "interop_aperturevalue",
      "interop_exposurebiasvalue",
      "interop_meteringmode",
      "interop_flash",
      "interop_focallength",
      "interop_flashpixversion",
      "interop_colorspace",
      "interop_exifimagewidth",
      "interop_exifimagelength",
      "interop_interoperabilityoffset",
      "interop_focalplanexresolution",
      "interop_focalplaneyresolution",
      "interop_focalplaneresolutionunit",
      "interop_imageuniqueid",
      "interop_gpsversion",
      "interop_gpslatituderef",
      "interop_gpslatitude",
      "interop_gpslongituderef",
      "interop_gpslongitude",
      "interop_gpsaltituderef",
      "interop_gpsaltitude",
      "interop_interoperabilityindex",
      "interop_interoperabilityversion",
      "winxp_filename",
      "winxp_filedatetime",
      "winxp_filesize",
      "winxp_filetype",
      "winxp_mimetype",
      "winxp_sectionsfound",
      "winxp_html",
      "winxp_height",
      "winxp_width",
      "winxp_iscolor",
      "winxp_byteordermotorola",
      "winxp_ccdwidth",
      "winxp_aperturefnumber",
      "winxp_usercomment",
      "winxp_usercommentencoding",
      "winxp_thumbnail.filetype",
      "winxp_thumbnail.mimetype",
      "winxp_imagedescription",
      "winxp_make",
      "winxp_model",
      "winxp_orientation",
      "winxp_xresolution",
      "winxp_yresolution",
      "winxp_resolutionunit",
      "winxp_software",
      "winxp_datetime",
      "winxp_artist",
      "winxp_ycbcrpositioning",
      "winxp_title",
      "winxp_comments",
      "winxp_author",
      "winxp_subject",
      "winxp_exif_ifd_pointer",
      "winxp_gps_ifd_pointer",
      "winxp_compression",
      "winxp_jpeginterchangeformat",
      "winxp_jpeginterchangeformatlength",
      "winxp_exposuretime",
      "winxp_fnumber",
      "winxp_exposureprogram",
      "winxp_isospeedratings",
      "winxp_exifversion",
      "winxp_datetimeoriginal",
      "winxp_datetimedigitized",
      "winxp_componentsconfiguration",
      "winxp_shutterspeedvalue",
      "winxp_aperturevalue",
      "winxp_exposurebiasvalue",
      "winxp_meteringmode",
      "winxp_flash",
      "winxp_focallength",
      "winxp_flashpixversion",
      "winxp_colorspace",
      "winxp_exifimagewidth",
      "winxp_exifimagelength",
      "winxp_interoperabilityoffset",
      "winxp_focalplanexresolution",
      "winxp_focalplaneyresolution",
      "winxp_focalplaneresolutionunit",
      "winxp_imageuniqueid",
      "winxp_gpsversion",
      "winxp_gpslatituderef",
      "winxp_gpslatitude",
      "winxp_gpslongituderef",
      "winxp_gpslongitude",
      "winxp_gpsaltituderef",
      "winxp_gpsaltitude",
      "winxp_interoperabilityindex",
      "winxp_interoperabilityversion"
    );
  }

  /**
   * Just some little helper function to get the iptc fields
   * @return array
   *
   */
  public function getHumanReadableIPTCkey() {
    return array(
      "2#202" => "object_data_preview_data",
      "2#201" => "object_data_preview_file_format_version",
      "2#200" => "object_data_preview_file_format",
      "2#154" => "audio_outcue",
      "2#153" => "audio_duration",
      "2#152" => "audio_sampling_resolution",
      "2#151" => "audio_sampling_rate",
      "2#150" => "audio_type",
      "2#135" => "language_identifier",
      "2#131" => "image_orientation",
      "2#130" => "image_type",
      "2#125" => "rasterized_caption",
      "2#122" => "writer",
      "2#120" => "caption",
      "2#118" => "contact",
      "2#116" => "copyright_notice",
      "2#115" => "source",
      "2#110" => "credit",
      "2#105" => "headline",
      "2#103" => "original_transmission_reference",
      "2#101" => "country_name",
      "2#100" => "country_code",
      "2#095" => "state",
      "2#092" => "sublocation",
      "2#090" => "city",
      "2#085" => "by_line_title",
      "2#080" => "by_line",
      "2#075" => "object_cycle",
      "2#070" => "program_version",
      "2#065" => "originating_program",
      "2#063" => "digital_creation_time",
      "2#062" => "digital_creation_date",
      "2#060" => "creation_time",
      "2#055" => "creation_date",
      "2#050" => "reference_number",
      "2#047" => "reference_date",
      "2#045" => "reference_service",
      "2#042" => "action_advised",
      "2#040" => "special_instruction",
      "2#038" => "expiration_time",
      "2#037" => "expiration_date",
      "2#035" => "release_time",
      "2#030" => "release_date",
      "2#027" => "content_location_name",
      "2#026" => "content_location_code",
      "2#025" => "keywords",
      "2#022" => "fixture_identifier",
      "2#020" => "supplemental_category",
      "2#015" => "category",
      "2#010" => "subject_reference",
      "2#008" => "editorial_update",
      "2#007" => "edit_status",
      "2#005" => "object_name",
      "2#004" => "object_attribute_reference",
      "2#003" => "object_type_reference",
      "2#000" => "record_version",
      "1#090" => "envelope_character_set"
    );
  }

  public function getFieldKeys() {
    $exif_keys_temp = $this->getHumanReadableExifKeys();
    $exif_keys = array();
    foreach ($exif_keys_temp as $value) {
      $exif_keys[$value] = $value;
    }
    $iptc_keys_temp = array_values($this->getHumanReadableIPTCkey());
    $iptc_keys = array();
    foreach ($iptc_keys_temp as $value) {
      $current_value = "iptc_" . $value;
      $iptc_keys[$current_value] = $current_value;
    }
    $fields = array_merge($exif_keys, $iptc_keys);
    ksort($fields);
    return $fields;
  }

  /**
   * Convert machine tag values to their human-readable descriptions.
   * Sources:
   * 	http://www.sno.phy.queensu.ca/~phil/exiftool/TagNames/EXIF.html
   * 	http://www.cipa.jp/english/hyoujunka/kikaku/pdf/DC-008-2010_E.pdf
   */
  public function getHumanReadableDescriptions() {
    $machineToHuman = array();
    $machineToHuman['componentsconfiguration'] = array(
      '0' => t('-'),
      '1' => t('Y'),
      '2' => t('Cb'),
      '3' => t('Cr'),
      '4' => t('R'),
      '5' => t('G'),
      '6' => t('B'),
    );
    $machineToHuman['compression'] = array(
      '1' => t('Uncompressed'),
      '2' => t('CCITT 1D'),
      '3' => t('T4/Group 3 Fax'),
      '4' => t('T6/Group 4 Fax'),
      '5' => t('LZW'),
      '6' => t('JPEG (old-style)'),
      '7' => t('JPEG'),
      '8' => t('Adobe Deflate'),
      '9' => t('JBIG B&W'),
      '10' => t('JBIG Color'),
      '99' => t('JPEG'),
      '262' => t('Kodak 262'),
      '32766' => t('Next'),
      '32767' => t('Sony ARW Compressed'),
      '32769' => t('Packed RAW'),
      '32770' => t('Samsung SRW Compressed'),
      '32771' => t('CCIRLEW'),
      '32773' => t('PackBits'),
      '32809' => t('Thunderscan'),
      '32867' => t('Kodak KDC Compressed'),
      '32895' => t('IT8CTPAD'),
      '32896' => t('IT8LW'),
      '32897' => t('IT8MP'),
      '32898' => t('IT8BL'),
      '32908' => t('PixarFilm'),
      '32909' => t('PixarLog'),
      '32946' => t('Deflate'),
      '32947' => t('DCS'),
      '34661' => t('JBIG'),
      '34676' => t('SGILog'),
      '34677' => t('SGILog24'),
      '34712' => t('JPEG 2000'),
      '34713' => t('Nikon NEF Compressed'),
      '34715' => t('JBIG2 TIFF FX'),
      '34718' => t('Microsoft Document Imaging (MDI) Binary Level Codec'),
      '34719' => t('Microsoft Document Imaging (MDI) Progressive Transform Codec'),
      '34720' => t('Microsoft Document Imaging (MDI) Vector'),
      '65000' => t('Kodak DCR Compressed'),
      '65535' => t('Pentax PEF Compressed'),
    );
    $machineToHuman['contrast'] = array(
      '0' => t('Normal'),
      '1' => t('Low'),
      '2' => t('High'),
    );
    $machineToHuman['exposuremode'] = array(
      '0' => t('Auto'),
      '1' => t('Manual'),
      '2' => t('Auto bracket'),
    );
    // (the value of 9 is not standard EXIF, but is used by the Canon EOS 7D)
    $machineToHuman['exposureprogram'] = array(
      '0' => t('Not Defined'),
      '1' => t('Manual'),
      '2' => t('Program AE'),
      '3' => t('Aperture-priority AE'),
      '4' => t('Shutter speed priority AE'),
      '5' => t('Creative (Slow speed)'),
      '6' => t('Action (High speed)'),
      '7' => t('Portrait'),
      '8' => t('Landscape'),
      '9' => t('Bulb'),
    );
    $machineToHuman['flash'] = array(
      '0' => t('Flash did not fire'),
      '1' => t('Flash fired'),
      '5' => t('Strobe return light not detected'),
      '7' => t('Strobe return light detected'),
      '9' => t('Flash fired, compulsory flash mode'),
      '13' => t('Flash fired, compulsory flash mode, return light not detected'),
      '15' => t('Flash fired, compulsory flash mode, return light detected'),
      '16' => t('Flash did not fire, compulsory flash mode'),
      '24' => t('Flash did not fire, auto mode'),
      '25' => t('Flash fired, auto mode'),
      '29' => t('Flash fired, auto mode, return light not detected'),
      '31' => t('Flash fired, auto mode, return light detected'),
      '32' => t('No flash function'),
      '65' => t('Flash fired, red-eye reduction mode'),
      '69' => t('Flash fired, red-eye reduction mode, return light not detected'),
      '71' => t('Flash fired, red-eye reduction mode, return light detected'),
      '73' => t('Flash fired, compulsory flash mode, red-eye reduction mode'),
      '77' => t('Flash fired, compulsory flash mode, red-eye reduction mode, return light not detected'),
      '79' => t('Flash fired, compulsory flash mode, red-eye reduction mode, return light detected'),
      '89' => t('Flash fired, auto mode, red-eye reduction mode'),
      '93' => t('Flash fired, auto mode, return light not detected, red-eye reduction mode'),
      '95' => t('Flash fired, auto mode, return light detected, red-eye reduction mode'),
    );
    // (values 1, 4 and 5 are not standard EXIF)
    $machineToHuman['focalplaneresolutionunit'] = array(
      '1' => t('None'),
      '2' => t('inches'),
      '3' => t('cm'),
      '4' => t('mm'),
      '5' => t('um'),
    );
    $machineToHuman['gaincontrol'] = array(
      '0' => t('None'),
      '1' => t('Low gain up'),
      '2' => t('High gain up'),
      '3' => t('Low gain down'),
      '4' => t('High gain down'),
    );
    $machineToHuman['lightsource'] = array(
      '0' => t('Unknown'),
      '1' => t('Daylight'),
      '2' => t('Fluorescent'),
      '3' => t('Tungsten (Incandescent)'),
      '4' => t('Flash'),
      '9' => t('Fine Weather'),
      '10' => t('Cloudy'),
      '11' => t('Shade'),
      '12' => t('Daylight Fluorescent'),
      '13' => t('Day White Fluorescent'),
      '14' => t('Cool White Fluorescent'),
      '15' => t('White Fluorescent'),
      '16' => t('Warm White Fluorescent'),
      '17' => t('Standard Light A'),
      '18' => t('Standard Light B'),
      '19' => t('Standard Light C'),
      '20' => t('D55'),
      '21' => t('D65'),
      '22' => t('D75'),
      '23' => t('D50'),
      '24' => t('ISO Studio Tungsten'),
      '255' => t('Other'),
    );
    $machineToHuman['meteringmode'] = array(
      '0' => t('Unknown'),
      '1' => t('Average'),
      '2' => t('Center-weighted average'),
      '3' => t('Spot'),
      '4' => t('Multi-spot'),
      '5' => t('Multi-segment'),
      '6' => t('Partial'),
      '255' => t('Other'),
    );
    $machineToHuman['orientation'] = array(
      '1' => t('Horizontal (normal)'),
      '2' => t('Mirror horizontal'),
      '3' => t('Rotate 180'),
      '4' => t('Mirror vertical'),
      '5' => t('Mirror horizontal and rotate 270 CW'),
      '6' => t('Rotate 90 CW'),
      '7' => t('Mirror horizontal and rotate 90 CW'),
      '8' => t('Rotate 270 CW'),
    );
    // (the value 1 is not standard EXIF)
    $machineToHuman['resolutionunit'] = array(
      '1' => t('None'),
      '2' => t('inches'),
      '3' => t('cm'),
    );
    $machineToHuman['saturation'] = array(
      '0' => t('Normal'),
      '1' => t('Low'),
      '2' => t('High'),
    );
    $machineToHuman['scenecapturetype'] = array(
      '0' => t('Standard'),
      '1' => t('Landscape'),
      '2' => t('Portrait'),
      '3' => t('Night'),
    );
    // (values 1 and 6 are not standard EXIF)
    $machineToHuman['sensingmethod'] = array(
      '1' => t('Monochrome area'),
      '2' => t('One-chip color area'),
      '3' => t('Two-chip color area'),
      '4' => t('Three-chip color area'),
      '5' => t('Color sequential area'),
      '6' => t('Monochrome linear'),
      '7' => t('Trilinear'),
      '8' => t('Color sequential linear'),
    );
    // (applies to EXIF:ISO tag)
    $machineToHuman['sensitivitytype'] = array(
      '0' => t('Unknown'),
      '1' => t('Standard Output Sensitivity'),
      '2' => t('Recommended Exposure Index'),
      '3' => t('ISO Speed'),
      '4' => t('Standard Output Sensitivity and Recommended Exposure Index'),
      '5' => t('Standard Output Sensitivity and ISO Speed'),
      '6' => t('Recommended Exposure Index and ISO Speed'),
      '7' => t('Standard Output Sensitivity, Recommended Exposure Index and ISO Speed'),
    );
    $machineToHuman['sharpness'] = array(
      '0' => t('Normal'),
      '1' => t('Soft'),
      '2' => t('Hard'),
    );
    $machineToHuman['subjectdistancerange'] = array(
      '0' => t('Unknown'),
      '1' => t('Macro'),
      '2' => t('Close'),
      '3' => t('Distant'),
    );
    $machineToHuman['uncompressed'] = array(
      '0' => t('No'),
      '1' => t('Yes'),
    );
    $machineToHuman['whitebalance'] = array(
      '0' => t('Auto'),
      '1' => t('Manual'),
    );
    return $machineToHuman;

  }

}
