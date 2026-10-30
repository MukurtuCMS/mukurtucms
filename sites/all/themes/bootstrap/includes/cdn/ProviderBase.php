<?php

namespace Drupal\bootstrap\Backport\Plugin\Provider;

/**
 * CDN provider base class.
 *
 * Note: this class is a backport from the 8.x-3.x code base.
 *
 * @see https://drupal-bootstrap.org/api/bootstrap/namespace/Drupal%21bootstrap%21Plugin%21Provider/8
 *
 * @ingroup plugins_provider
 */
abstract class ProviderBase {

  /**
   * The plugin_id.
   *
   * @var string
   */
  protected $pluginId;

  /**
   * The currently set CDN assets.
   *
   * @var array
   */
  protected $cdnAssets;

  /**
   * The current theme name.
   *
   * @var string
   */
  protected $themeName;

  /**
   * The versions supplied by the CDN provider.
   *
   * @var array
   */
  protected $versions;

  /**
   * ProviderBase constructor.
   */
  public function __construct() {
    $this->themeName = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  /**
   * {@inheritdoc}
   */
  public function alterFrameworkLibrary(array &$framework, $min = NULL) {
    // In Drupal 7, CSS and JS are separated into individual hooks and alters,
    // so this has the potential to be invoked at a minimum of 3 times.
    static $drupal_static_fast;
    if (!isset($drupal_static_fast)) {
      // Attempt to retrieve CDN assets from a sort of permanent cached in the
      // theme settings. This is primarily used to avoid unnecessary API requests
      // and speed up the process during a cache rebuild. Theme settings are used
      // as they persist through cache rebuilds. In order to prevent stale data,
      // a hash is used based on current CDN settings and this "permacache" is
      // reset at least once a week regardless.
      // @see https://www.drupal.org/project/bootstrap/issues/3031415
      $cdnCache = variable_get('bootstrap_cdn_cache') ?: array();

      // Reset cache if expired.
      if (isset($cdnCache['expire']) && (empty($cdnCache['expire']) || REQUEST_TIME > $cdnCache['expire'])) {
        $cdnCache = array();
      }

      // Set expiration date (1 week by default).
      if (!isset($cdnCache['expire'])) {
        $cdnCache['expire'] = REQUEST_TIME + variable_get('bootstrap_cdn_cache_expire', 604800);
      }

      $cdnVersion = $this->getCdnVersion();
      $cdnTheme = $this->getCdnTheme();

      // Cache not found.
      $cdnHash = drupal_hash_base64("{$this->pluginId}:$cdnTheme:$cdnVersion");
      if (!isset($cdnCache[$cdnHash])) {
        // Retrieve assets and reset cache (should only cache one at a time).
        $cdnCache = array(
          'expire' => $cdnCache['expire'],
          $cdnHash => $this->getCdnAssets($cdnVersion, $cdnTheme),
        );
        variable_set('bootstrap_cdn_cache', $cdnCache);
      }

      // Immediately return if there are no theme CDN assets to use.
      if (empty($cdnCache[$cdnHash])) {
        return;
      }

      // Retrieve the system performance config.
      if (!isset($min)) {
        $min = array(
          'css' => variable_get('preprocess_css', FALSE),
          'js' => variable_get('preprocess_js', FALSE),
        );
      }
      else {
        $min = array('css' => !!$min, 'js' => !!$min);
      }

      // Iterate over each type.
      $assets = array();
      foreach (array('css', 'js') as $type) {
        $files = !empty($min[$type]) && isset($cdnCache[$cdnHash]['min'][$type]) ? $cdnCache[$cdnHash]['min'][$type] : (isset($cdnCache[$cdnHash][$type]) ? $cdnCache[$cdnHash][$type] : array());
        foreach ($files as $asset) {
          $assets[$type][$asset] = array('data' => $asset, 'type' => 'external');
        }
      }

      // Merge the assets into the library info.
      $drupal_static_fast = drupal_array_merge_deep_array(array($assets, $framework));

      // Override the framework version with the CDN version that is being used.
      $drupal_static_fast['version'] = $cdnVersion;
    }

    $framework = $drupal_static_fast;
  }

  /**
   * Retrieves a value from the CDN provider cache.
   *
   * @param string $key
   *   The name of the item to retrieve. Note: this can be in the form of dot
   *   notation if the value is nested in an array.
   * @param mixed $default
   *   Optional. The default value to return if $key is not set.
   * @param callable $builder
   *   Optional. If provided, a builder will be invoked when there is no cache
   *   currently set.
   *
   * @return mixed
   *   The cached value if it's set or the value supplied to $default if not.
   */
  protected function cacheGet($key, $default = NULL, $builder = NULL) {
    $cid = $this->getCacheId();
    $cache = cache_get($cid);
    $data = $cache && isset($cache->data) && is_array($cache->data) ? $cache->data : array();
    $parts = static::splitDelimiter($key);
    $value = drupal_array_get_nested_value($data, $parts, $key_exists);

    // Build the cache.
    if (!$key_exists && is_callable($builder)) {
      $value = $builder($default);
      if (!isset($value)) {
        $value = $default;
      }
      drupal_array_set_nested_value($data, $parts, $value);
      cache_set($cid, $data);
      return $value;
    }

    return $key_exists ? $value : $default;
  }

  /**
   * Sets a value in the CDN provider cache.
   *
   * @param string $key
   *   The name of the item to set. Note: this can be in the form of dot
   *   notation if the value is nested in an array.
   * @param mixed $value
   *   Optional. The value to set.
   */
  protected function cacheSet($key, $value = NULL) {
    $cid = $this->getCacheId();
    $cache = cache_get($cid);
    $data = $cache && isset($cache->data) && is_array($cache->data) ? $cache->data : array();
    $parts = static::splitDelimiter($key);
    drupal_array_set_nested_value($data, $parts, $value);
    cache_set($cid, $data);
  }

  /**
   * {@inheritdoc}
   */
  protected function discoverCdnAssets($version, $theme) {
    return array();
  }

  /**
   * Retrieves the unique cache identifier for the CDN provider.
   *
   * @return string
   *   The CDN provider cache identifier.
   */
  protected function getCacheId() {
    return "theme_registry:{$this->themeName}:provider:{$this->pluginId}";
  }

  /**
   * {@inheritdoc}
   */
  public function getCdnAssets($version = NULL, $theme = NULL) {
    if (!isset($version)) {
      $version = $this->getCdnVersion();
    }
    if (!isset($theme)) {
      $theme = $this->getCdnTheme();
    }

    if (!isset($this->cdnAssets)) {
      $this->cdnAssets = $this->cacheGet('cdn.assets', array());
    }

    if (!isset($this->cdnAssets[$version][$theme])) {
      $escapedVersion = static::escapeDelimiter($version);
      $instance = $this;
      $this->cdnAssets[$version][$theme] = $this->cacheGet("cdn.assets.$escapedVersion.$theme", array(), function () use ($version, $theme, $instance) {
        return $instance->discoverCdnAssets($version, $theme);
      });
    }

    return $this->cdnAssets[$version][$theme];
  }

  /**
   * {@inheritdoc}
   */
  public function getCdnTheme() {
    return bootstrap_setting("cdn_{$this->pluginId}_theme") ?: 'bootstrap';
  }

  /**
   * {@inheritdoc}
   */
  public function getCdnThemes($version = NULL) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getCdnVersion() {
    return bootstrap_setting("cdn_{$this->pluginId}_version") ?: BOOTSTRAP_VERSION;
  }

  /**
   * {@inheritdoc}
   */
  public function getCdnVersions() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getDescription() {
    return '';
  }

  /**
   * {@inheritdoc}
   */
  public function getLabel() {
    return t(ucfirst($this->pluginId));
  }

  /**
   * Allows providers a way to map a version to a different version.
   *
   * @param string $version
   *   The version to map.
   *
   * @return string
   *   The mapped version.
   */
  protected function mapVersion($version) {
    return $version;
  }

  /**
   * Retrieves JSON from a URI.
   *
   * @param string $uri
   *   The URI to retrieve JSON from.
   * @param array $options
   *   The options to pass to the HTTP client.
   * @param \Exception|null $exception
   *   The exception thrown if there was an error, passed by reference.
   *
   * @return array
   *   The requested JSON array.
   */
  protected function requestJson($uri, array $options = array(), &$exception = NULL) {
    $json = array();

    $options += array(
      'method' => 'GET',
      'headers' => array(
        'User-Agent' => 'Drupal Bootstrap 7.x-3.x (https://www.drupal.org/project/bootstrap)',
      ),
    );

    try {
      $response = drupal_http_request($uri, $options);
      if (!empty($response->error)) {
        throw new \Exception("$uri: {$response->error}", $response->code);
      }
      if ($response->code >= 200 && $response->code < 400) {
        $json = drupal_json_decode($response->data) ?: array();
      }
      else {
        throw new \Exception("$uri: Invalid response", $response->code);
      }
    }
    catch (\Exception $e) {
      $exception = $e;
    }

    return $json;
  }

  /**
   * Escapes a delimiter in a string.
   *
   * Note: this is primarily useful in situations where dot notation is used
   * where the values also contain dots, like in a semantic version string.
   *
   * @param string $string
   *   The string to search in.
   * @param string $delimiter
   *   The delimiter to escape.
   *
   * @return string
   *   The escaped string.
   *
   * @see \Drupal\bootstrap\Plugin\Provider\ProviderBase::splitDelimiter()
   */
  public static function escapeDelimiter($string, $delimiter = '.') {
    return str_replace($delimiter, "\\$delimiter", $string);
  }

  /**
   * Splits a string by a specified delimiter, allowing them to be escaped.
   *
   * Note: this is primarily useful in situations where dot notation is used
   * where the values also contain dots, like in a semantic version string.
   *
   * @param string $string
   *   The string to split into parts.
   * @param string $delimiter
   *   The delimiter used to split the string.
   * @param bool $escapable
   *   Flag indicating whether the $delimiter can be escaped using a backward
   *   slash (\).
   *
   * @return array
   *   An array of strings, split where the specified $delimiter was present.
   *
   * @see \Drupal\bootstrap\Plugin\Provider\ProviderBase::escapeDelimiter()
   * @see https://stackoverflow.com/a/6243797
   */
  public static function splitDelimiter($string, $delimiter = '.', $escapable = TRUE) {
    if (!$escapable) {
      return explode($delimiter, $string);
    }

    // Split based on delimiter.
    $parts = preg_split('~\\\\' . preg_quote($delimiter, '~') . '(*SKIP)(*FAIL)|\.~s', $string);

    // Iterate over the parts and remove backslashes from delimiters.
    return array_map(function ($string) use ($delimiter) {
      return str_replace("\\$delimiter", $delimiter, $string);
    }, $parts);
  }

}
