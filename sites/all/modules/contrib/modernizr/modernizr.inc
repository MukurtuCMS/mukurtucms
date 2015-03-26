<?php

/**
 * Modernizr class.
 *
 * Properties are dynamically constructed
 * from the JavaScript modernizr object.
 *
 * For the nested properties, '_' will be added
 * as a separator.
 *
 * This class is a singleton.
 */
class Modernizr {

  /**
   * List of the features.
   *
   * @var array
   */
  protected $features;

  /**
   * This variable holds the singleton instance.
   *
   * @var Modernizr
   */
  protected static $instance = NULL;

  /**
   * @constructor
   *
   * This function processes the cookie data.
   */
  protected function __construct() {
    if (empty($_COOKIE['modernizr'])) {
      throw new ModernizrCookieNotSetException();
    }

    $data = $_COOKIE['modernizr'];
    $data = drupal_json_decode(html_entity_decode($data));
    $this->features = array();
    $this->processData(NULL, $data);
  }

  /**
   * Processes the cookie data into prefixed values.
   *
   * @param string $key
   * @param mixed $data
   * @param string $prefix
   */
  private function processData($key, $data, $prefix = '') {
    if (is_array($data)) {
      foreach ($data as $k => $d) {
        $this->processData($k, $d, ltrim("{$prefix}{$key}_", '_'));
      }
    }
    else {
      $this->features[str_replace('-', '_', "{$prefix}{$key}")] = $data;
    }
  }

  /**
   * Implementation of the __get magic method.
   *
   * If the feature is not detected, then
   * ModernizrFeatureNotSupportedException will
   * be thrown.
   *
   * @param string $name
   * @return boolean
   */
  public function __get($name) {
    if (isset($this->features[$name])) {
      return $this->features[$name];
    }
    else {
      throw new ModernizrFeatureNotSupportedException();
    }
  }

  /**
   * Implementation of the __isset magic method.
   *
   * @param string $name
   * @return bool
   */
  public function __isset($name) {
    return isset($this->features[$name]);
  }

  /**
   * Returns an iterator for the features.
   *
   * @return ArrayIterator 
   */
  public function getIterator() {
    return new ArrayIterator($this->features);
  }
  
  /**
   * Returns the list of the features.
   *
   * @return array
   */
  public function getFeatureList() {
    return array_keys($this->features);
  }
  
  /**
   * Returns the internal features array.
   * 
   * The keys are the names of the features,
   * the value is boolean.
   *
   * @return array
   */
  public function getFeatures() {
    return $this->features;
  }

  /**
   * Returns the singleton instance.
   *
   * @return Modernizr
   */
  public static function getInstance() {
    if (self::$instance === NULL) {
      self::$instance = new Modernizr();
    }

    return self::$instance;
  }
}

class ModernizrCookieNotSetException extends RuntimeException {}
class ModernizrFeatureNotSupportedException extends RuntimeException {}
