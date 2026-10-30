<?php

/**
 * @file
 * Support for migration into Geofield fields.
 *
 * Based on addressfield.migrate.inc
 * in the Address Field module.
 */

/**
 * Implements hook_migrate_api().
 */
function geofield_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array('MigrateGeofieldFieldHandler'),
  );
}

/**
 * Primary value passed to this field must be the Geometry type string.
 *
 * Arguments are used to specify all the other values.
 *
 * Add the source field mappings to the argument array then add null mappings to
 * avoid having fields flagged as as unmapped:
 * @code
 *
 *   $this->addFieldMapping('field_geofield', 'foo');
 *   $this->addFieldMapping('field_geofield:wkt', 'wkt');
 *   $this->addFieldMapping('field_geofield:lat', 'lat');
 *   $this->addFieldMapping('field_geofield:lon', 'lon');
 * @endcode
 */
class MigrateGeofieldFieldHandler extends MigrateFieldHandler {

  /**
   * Registers the geofield field type.
   */
  public function __construct() {
    $this->registerTypes(array('geofield'));
  }

  /**
   * Implementation of MigrateFieldHandler::fields().
   *
   * @param string $type
   *   The field type.
   * @param array $instance
   *   Instance info for the field.
   * @param object $migration
   *   The migration context for the parent field. We can look at the mappings
   *   and determine which subfields are relevant.
   *
   * @return array
   *   List of subfields.
   */
  public function fields($type, $instance, $migration = NULL) {
    return array(
      'input_format' => t('Subfield: Input Format'),
      'wkt' => t('Subfield: WKT'),
      'geo_type' => t('Subfield: Geo_type'),
      'json' => t('Subfield: GeoJSON'),
      'lat' => t('Subfield: Lat'),
      'lon' => t('Subfield: Lon'),
      'left' => t('Subfield: Left'),
      'top' => t('Subfield: Top'),
      'right' => t('Subfield: Right'),
      'bottom' => t('Subfield: Bottom'),
    );
  }

  /**
   * Implements MigrateFieldHandler::prepare().
   *
   * @param object $entity
   *   Entity which is going to embed the field.
   * @param array $field_info
   *   Info for the field.
   * @param array $instance
   *   Instance info for the field.
   * @param array $values
   *   Values to be stored in the field.
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    $arguments = array();
    if (isset($values['arguments'])) {
      $arguments = array_filter($values['arguments']);
      unset($values['arguments']);
    }
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    // Setup a Field API array for saving.
    // Use https://drupal.org/node/1854188 as a guide for geoPHP field type.
    $delta = 0;
    foreach ($values as $value) {
      $input_format = $arguments['input_format'];
      if (isset($input_format)) {
        $return[$language][$delta]['input_format'] = $arguments['input_format'];
        switch ($input_format) {
          case 'wkt':
            // Well known text - array of WKT data.
            $return[$language][$delta]['geom'] = $value;
            break;

          case 'json':
            // GeoJSON - requires array of JSON data.
            $return[$language][$delta]['geom'] = $value;
            break;

          case 'lat/lon':
            // Lat/Long - requires array of lat and lon source fields.
            $return[$language][$delta]['geom']['lat'] = $arguments['lat'];
            $return[$language][$delta]['geom']['lon'] = $arguments['lon'];
            break;

          case 'bounds':
            // Delimited area marked by an array of left (lon), top (lat), right
            // (long), bottom (lat) values.
            $return[$language][$delta]['geom']['left'] = $arguments['left'];
            $return[$language][$delta]['geom']['top'] = $arguments['top'];
            $return[$language][$delta]['geom']['right'] = $arguments['right'];
            $return[$language][$delta]['geom']['bottom'] = $arguments['bottom'];
            break;
        }
      }
      else {
        // If no input format specified the $value is assumed to represent a
        // a WKT value or another format that can be parsed by geoPHP.
        $return[$language][$delta]['geom'] = $value;
      }
      $delta++;
    }

    return isset($return) ? $return : NULL;
  }

  /**
   * Builds an array with additional data for the current $delta.
   *
   * @param array $arguments
   *   Arguments.
   * @param array $field_info
   *   Info for the field.
   * @param int $delta
   *   Order of value (typically for multi-valued fields).
   *
   * @return array
   *   Array with additional data.
   */
  protected function prepareArguments(array $arguments, array $field_info, $delta) {
    $result = array();

    foreach ($arguments as $column_key => $column_value) {
      $value = NULL;

      if (is_array($arguments[$column_key])) {
        if (!empty($arguments[$column_key][$delta])) {
          $value = $arguments[$column_key][$delta];
        }
      }
      else {
        $value = $arguments[$column_key];
      }

      if ($value && isset($field_info['columns'][$column_key])) {
        $result[$column_key] = $value;
      }
    }

    return $result;
  }

}
