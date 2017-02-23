<?php

/**
 * @file
 * Mollom client class for Drupal.
 */

/**
 * Drupal Mollom client implementation.
 */
class MollomDrupal extends Mollom {

  /**
   * Overrides the connection timeout based on module configuration.
   *
   * @see Mollom::__construct().
   */
  public function __construct() {
    // Set any configured endpoint that may be different from the default.
    parent::__construct();
    $configured_server = $this->loadConfiguration('server');
    if (!empty($configured_server)) {
      $this->server = $configured_server;
    }
    $this->requestTimeout = variable_get('mollom_connection_timeout', 3);
  }

  /**
   * Mapping of configuration names to Drupal variables.
   *
   * @see Mollom::loadConfiguration()
   */
  public $configuration_map = array(
    'publicKey' => 'mollom_public_key',
    'privateKey' => 'mollom_private_key',
    'expectedLanguages' => 'mollom_languages_expected',
    'server' => 'mollom_api_endpoint',
  );

  /**
   * Implements Mollom::loadConfiguration().
   */
  public function loadConfiguration($name) {
    $name = $this->configuration_map[$name];
    return variable_get($name);
  }

  /**
   * Implements Mollom::saveConfiguration().
   */
  public function saveConfiguration($name, $value) {
    // Set local variable.
    if (property_exists('MollomDrupal', $name)) {
      $this->{$name} = $value;
    }
    // Persist in Drupal.
    $name = $this->configuration_map[$name];
    return variable_set($name, $value);
  }

  /**
   * Implements Mollom::deleteConfiguration().
   */
  public function deleteConfiguration($name) {
    $name = $this->configuration_map[$name];
    return variable_del($name);
  }

  /**
   * Implements Mollom::getClientInformation().
   */
  public function getClientInformation() {
    // Retrieve Drupal distribution and installation profile information.
    $profile = drupal_get_profile();
    $profile_info = system_get_info('module', $profile) + array(
      'distribution_name' => 'Drupal',
      'version' => VERSION,
    );

    // Retrieve Mollom module information.
    $mollom_info = system_get_info('module', 'mollom');
    if (empty($mollom_info['version'])) {
      // Manually build a module version string for repository checkouts.
      $mollom_info['version'] = DRUPAL_CORE_COMPATIBILITY . '-2.x-dev';
    }

    $data = array(
      'platformName' => $profile_info['distribution_name'],
      'platformVersion' => $profile_info['version'],
      'clientName' => $mollom_info['name'],
      'clientVersion' => $mollom_info['version'],
    );
    return $data;
  }

  /**
   * Overrides Mollom::writeLog().
   */
  function writeLog() {
    foreach ($this->log as $entry) {
      $entry['Request: ' . $entry['request']] = !empty($entry['data']) ? $entry['data'] : NULL;
      unset($entry['request'], $entry['data']);

      $entry['Request headers:'] = $entry['headers'];
      unset($entry['headers']);

      $entry['Response: ' . $entry['response_code'] . ' ' . $entry['response_message'] . ' (' . number_format($entry['response_time'], 3) . 's)'] = $entry['response'];
      unset($entry['response'], $entry['response_code'], $entry['response_message'], $entry['response_time']);

      // The client class contains the logic for recovering from certain errors,
      // and log messages are only written after that happened. Therefore, we
      // can normalize the severity of all log entries to the overall success or
      // failure of the attempted request.
      // @see Mollom::query()
      mollom_log($entry, $this->lastResponseCode === TRUE ? NULL : WATCHDOG_ERROR);
    }

    // After writing log messages, empty the log.
    $this->purgeLog();
  }

  /**
   * Implements Mollom::request().
   */
  protected function request($method, $server, $path, $query = NULL, array $headers = array()) {
    $request = array(
      'method' => $method,
      'headers' => $headers,
      'timeout' => $this->requestTimeout,
    );
    if (isset($query)) {
      if ($method == 'GET') {
        $path .= '?' . $query;
      }
      elseif ($method == 'POST') {
        $request['data'] = $query;
      }
    }

    $dhr = drupal_http_request($server . '/' . $path, $request);
    // @todo Core: Ensure that $dhr->code is an integer.
    $dhr->code = (int) $dhr->code;
    // @todo Core: Any other code than 200 is interpreted as error.
    if ($dhr->code >= 200 && $dhr->code < 300) {
      unset($dhr->error);
    }
    // @todo Core: data property is not assigned if there is no response body.
    if (!isset($dhr->data)) {
      $dhr->data = NULL;
    }
    // @todo Core: Timeout produces a bogus non-negative status code.
    // @see http://drupal.org/node/1246376
    if ($dhr->code === 1) {
      $dhr->code = -1;
    }

    $response = (object) array(
      'code' => $dhr->code,
      'message' => isset($dhr->error) ? $dhr->error : NULL,
      'headers' => isset($dhr->headers) ? $dhr->headers : array(),
      'body' => $dhr->data,
    );
    return $response;
  }

  /**
   * Retrieves GET/HEAD or POST/PUT parameters of an inbound request.
   *
   * @return array
   *   An array containing either GET/HEAD query string parameters or POST/PUT
   *   post body parameters. Parameter parsing accounts for multiple request
   *   parameters in non-PHP format; e.g., 'foo=one&foo=bar'.
   */
  public static function getServerParameters() {
    $data = parent::getServerParameters();
    if ($_SERVER['REQUEST_METHOD'] == 'GET' || $_SERVER['REQUEST_METHOD'] == 'HEAD') {
      // Remove $_GET['q'].
      unset($data['q']);
    }
    return $data;
  }

}

/**
 * Drupal Mollom client implementation using testing API servers.
 */
class MollomDrupalTest extends MollomDrupal {
  /**
   * Overrides Mollom::$server.
   */
  public $server = 'dev.mollom.com';

  /**
   * Flag indicating whether to verify and automatically create testing API keys upon class instantiation.
   *
   * @var bool
   */
  public $createKeys;

  /**
   * Overrides Mollom::__construct().
   *
   * This class accounts for multiple scenarios:
   * - Straight low-level requests against the testing API from a custom script,
   *   caring for API keys on its own.
   * - Whenever the testing mode is enabled (either through the module's
   *   settings page or by changing the mollom_testing_mode system variable),
   *   the client requires valid testing API keys to perform any calls. Testing
   *   API keys are different to production API keys, need to be created first,
   *   and may vanish at any time (whenever the testing API server is
   *   redeployed). Since they are different, the class stores them in different
   *   system variables. Since they can vanish at any time, the class verifies
   *   the keys upon every instantiation, and automatically creates new testing
   *   API keys if necessary.
   * - Some automated unit tests attempt to verify that authentication errors
   *   are handled correctly by the class' error handling. The automatic
   *   creation and recovery of testing API keys would break those assertions,
   *   so said tests can disable the behavior by preemptively setting
   *   $createKeys or the 'mollom_testing_create_keys' system variable to FALSE,
   *   and manually create testing API keys (once).
   */
  function __construct() {
    // Some tests are verifying the production behavior of e.g. setting up API
    // keys, in which testing mode is NOT enabled and the test creates fake
    // "production" API keys on the local fake server on its own. This special
    // override must only be possible when executing tests.
    // @todo Add global test_info as condition?
    if (module_exists('mollom_test_server') && !variable_get('mollom_testing_mode', 0)) {
      // Disable authentication error auto-recovery.
      $this->createKeys = FALSE;
    }
    else {
      // Do not destroy production variables when testing mode is enabled.
      $this->configuration_map['publicKey'] = 'mollom_test_public_key';
      $this->configuration_map['privateKey'] = 'mollom_test_private_key';
      $this->configuration_map['server'] = 'mollom_test_api_endpoint';
    }

    // Load and set publicKey and privateKey configuration values.
    parent::__construct();

    // Unless pre-set, determine whether API keys should be auto-created.
    if (!isset($this->createKeys)) {
      $this->createKeys = (bool) variable_get('mollom_testing_create_keys', TRUE);
    }

    // Testing can require additional time.
    $this->requestTimeout = variable_get('mollom_connection_timeout', 3) + 10;
  }

  /**
   * Overrides Mollom::handleRequest().
   *
   * Automatically tries to generate new API keys in case of a 401 or 404 error.
   * Intentionally reacts on 401 or 404 errors only, since any other error code
   * can mean that either the Testing API is down or that the client site is not
   * able to perform outgoing HTTP requests in general.
   */
  protected function handleRequest($method, $server, $path, $data, $expected = array()) {
    try {
      $response = parent::handleRequest($method, $server, $path, $data, $expected);
    }
    catch (MollomException $e) {
      $is_auth_error = $e->getCode() == self::AUTH_ERROR || ($e->getCode() == 404 && strpos($path, 'site') === 0);
      $current_public_key = $this->publicKey;
      if ($this->createKeys && $is_auth_error && $this->createKeys()) {
        $this->saveKeys();
        // Avoid to needlessly hit the previous/invalid public key again.
        // Mollom::handleRequest() will sign the new request correctly.
        // If it was empty, Mollom::handleRequest() returned an AUTH_ERROR
        // without issuing a request.
        if ($path == 'site/') {
          $path = 'site/' . $this->publicKey;
        }
        elseif (!empty($current_public_key)) {
          $path = str_replace($current_public_key, $this->publicKey, $path);
        }
        $response = parent::handleRequest($method, $server, $path, $data, $expected);
      }
      else {
        throw $e;
      }
    }
    return $response;
  }

  /**
   * Creates new testing API keys.
   *
   * @todo Move site properties into $data argument (Drupal-specific values),
   *   rename to createTestingSite(), and move into Mollom class?
   */
  public function createKeys() {
    // Do not attempt to create API keys repeatedly.
    $this->createKeys = FALSE;

    // Without any API keys, the client does not even attempt to perform a
    // request. Set dummy API keys to overcome that sanity check.
    $this->publicKey = 'public';
    $this->privateKey = 'private';

    // Skip authorization for creating testing API keys.
    $oAuthStrategy = $this->oAuthStrategy;
    $this->oAuthStrategy = '';
    $result = $this->createSite(array(
      'url' => $GLOBALS['base_url'],
      'email' => variable_get('site_mail', 'mollom-drupal-test@example.com'),
    ));
    $this->oAuthStrategy = $oAuthStrategy;

    // Set class properties.
    if (is_array($result) && !empty($result['publicKey']) && !empty($result['privateKey'])) {
      $this->publicKey = $result['publicKey'];
      $this->privateKey = $result['privateKey'];
      return TRUE;
    }
    else {
      $this->publicKey = $this->privateKey = '';
      return FALSE;
    }
  }

  /**
   * Saves API keys to local configuration store.
   */
  public function saveKeys() {
    $this->saveConfiguration('publicKey', $this->publicKey);
    $this->saveConfiguration('privateKey', $this->privateKey);
  }

  /**
   * Deletes API keys from local configuration store.
   */
  public function deleteKeys() {
    $this->deleteConfiguration('publicKey');
    $this->deleteConfiguration('privateKey');
  }
}

/**
 * Drupal Mollom client implementation using local dummy/fake REST server.
 */
class MollomDrupalTestLocal extends MollomDrupalTest {

  /**
   * Overrides MollomDrupalTest::__construct().
   */
  function __construct() {
    // Replace server/endpoint with our local fake server.
    list(, $server) = explode('://', $GLOBALS['base_url'], 2);
    $this->server = $server . '/mollom-test/rest';

    // Do not destroy production server variables when testing mode is enabled.
    $this->configuration_map['server'] = 'mollom_test_local_api_endpoint';

    parent::__construct();
  }

  /**
   * Overrides MollomDrupal::saveKeys().
   */
  public function saveKeys() {
    parent::saveKeys();

    // Ensure that the site exists on the local fake server. Not required for
    // remote REST testing API, because our testing API keys persist there.
    // @see mollom_test_server_rest_site()
    $bin = 'mollom_test_server_site';
    $sites = variable_get($bin, array());
    if (!isset($sites[$this->publicKey])) {
      // Apply default values.
      $sites[$this->publicKey] = array(
        'publicKey' => $this->publicKey,
        'privateKey' => $this->privateKey,
        'url' => '',
        'email' => '',
      );
      variable_set($bin, $sites);
    }
  }

  /**
   * Overrides MollomDrupal::request().
   *
   * Passes-through SimpleTest assertion HTTP headers from child-child-site and
   * triggers errors to make them appear in parent site (where tests are ran).
   *
   * @todo Remove when in core.
   * @see http://drupal.org/node/875342
   */
  protected function request($method, $server, $path, $query = NULL, array $headers = array()) {
    $response = parent::request($method, $server, $path, $query, $headers);
    $keys = preg_grep('@^x-drupal-assertion-@', array_keys($response->headers));
    foreach ($keys as $key) {
      $header = $response->headers[$key];
      $header = unserialize(urldecode($header));
      $message = strtr('%type: !message in %function (line %line of %file).', array(
        '%type' => $header[1],
        '!message' => $header[0],
        '%function' => $header[2]['function'],
        '%line' => $header[2]['line'],
        '%file' => $header[2]['file'],
      ));
      trigger_error($message, E_USER_ERROR);
    }
    return $response;
  }
}

/**
 * Drupal Mollom client implementation using an invalid server.
 */
class MollomDrupalTestInvalid extends MollomDrupalTest {

  /**
   * Overrides MollomDrupalTest::$createKeys.
   *
   * Do not attempt to verify API keys against invalid server.
   */
  public $createKeys = FALSE;

  private $currentAttempt = 0;

  private $originalServer;

  /**
   * Overrides MollomDrupalTest::__construct().
   */
  function __construct() {
    parent::__construct();
    $this->originalServer = $this->server;
    $this->configuration_map['server'] = 'mollom_test_invalid_api_endpoint';
    $this->saveConfiguration('server', 'fake-host');
    $this->server = 'fake-host';
  }

  /**
   * Overrides Mollom::query().
   */
  public function query($method, $path, array $data = array(), array $expected = array()) {
    $this->currentAttempt = 0;
    return parent::query($method, $path, $data, $expected);
  }

  /**
   * Overrides Mollom::handleRequest().
   *
   * Mollom::$server is replaced with an invalid server, so all requests will
   * result in a network error. However, if the 'mollom_testing_server_failover'
   * variable is set to TRUE, then the last request attempt will succeed.
   */
  protected function handleRequest($method, $server, $path, $data, $expected = array()) {
    $this->currentAttempt++;

    if (variable_get('mollom_testing_server_failover', FALSE) && $this->currentAttempt == $this->requestMaxAttempts) {
      // Prior to PHP 5.3, there is no late static binding, so there is no way
      // to access the original value of MollomDrupalTest::$server.
      $server = strtr($server, array($this->server => $this->originalServer));
    }
    return parent::handleRequest($method, $server, $path, $data, $expected);
  }
}
