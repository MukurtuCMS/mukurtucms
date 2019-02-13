<?php

/**
 * @file
 * Contains FeedsExJmesPath.
 */

// Version 1.
use JmesPath\Runtime\AstRuntime as AstRuntime1;
use JmesPath\Runtime\CompilerRuntime as CompilerRuntime1;
use JmesPath\Runtime\RuntimeInterface;

// Version 2.
use JmesPath\AstRuntime as AstRuntime2;
use JmesPath\CompilerRuntime as CompilerRuntime2;

use JmesPath\SyntaxErrorException;

/**
 * Parses JSON documents with JMESPath.
 */
class FeedsExJmesPath extends FeedsExBase {

  /**
   * The JMESPath parser.
   *
   * @var An object with an __invoke() method.
   */
  protected $runtime;

  /**
   * Returns the compilation directory.
   *
   * @return string
   *   The directory JmesPath uses to store generated code.
   */
  protected function getCompileDirectory() {
    // Look for a previous directory.
    $directory = variable_get('feeds_ex_jmespath_compile_dir');

    // The temp directory doesn't exist, or has moved.
    if (!$this->validateCompileDirectory($directory)) {
      $directory = $this->generateCompileDirectory();
      variable_set('feeds_ex_jmespath_compile_dir', $directory);

      // Creates the directory with the correct perms. We don't check the
      // return value since if it didn't work, there's nothing we can do. We
      // just fallback to the AstRuntime anyway.
      $this->validateCompileDirectory($directory);
    }

    return $directory;
  }

  /**
   * Generates a directory path to store auto-generated PHP files.
   *
   * @return string
   *   A temp directory path.
   */
  protected function generateCompileDirectory() {
    // A random prefix to store the generated files.
    $prefix = drupal_base64_encode(drupal_random_bytes(40));
    return file_directory_temp() . '/' . $prefix . '_feeds_ex_jmespath_dir';
  }

  /**
   * Validates that a compile directory exists and is valid.
   *
   * @param string $directory
   *   A directory path.
   *
   * @return bool
   *   True if the directory exists and is writable, false if not.
   */
  protected function validateCompileDirectory($directory) {
    if (!$directory) {
      return FALSE;
    }

    return file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
  }

  /**
   * Returns data from the input array that matches a JMESPath expression.
   *
   * @param string $expression
   *   JMESPath expression to evaluate.
   * @param mixed $data
   *   JSON-like data to search.
   *
   * @return mixed|null
   *   Returns the matching data or null.
   */
  protected function search($expression, $data) {
    if (!isset($this->runtime)) {
      $this->runtime = $this->createRuntime($this->getCompileDirectory());
    }

    // Stupid PHP.
    $runtime = $this->runtime;

    return $runtime($expression, $data);
  }

  /**
   * Creates a runtime object.
   *
   * Checks for different versions of JMESPath.php.
   *
   * @param string $directory
   *   The compile directory.
   *
   * @return object
   *   An invokable runtime object.
   */
  protected function createRuntime($directory) {
    // Version 2.
    if (class_exists('JmesPath\AstRuntime')) {
      try {
        $runtime = new CompilerRuntime2($directory);
      }
      catch (RuntimeException $e) {
        $runtime = new AstRuntime2();
      }
    }

    // Version 1.
    elseif (class_exists('JmesPath\Runtime\AstRuntime')) {
      try {
        $runtime = new CompilerRuntime1(array('dir' => $directory));
      }
      catch (RuntimeException $e) {
        $runtime = new AstRuntime1();
      }

      $runtime = new FeedsExJmesPathV1Wrapper($runtime);
    }

    // Oops.
    else {
      throw new RuntimeException(t('JMESPath.php is not installed correctly.'));
    }

    return $runtime;
  }

  /**
   * {@inheritdoc}
   */
  protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $raw = $this->prepareRaw($fetcher_result);
    $parsed = FeedsExJsonUtility::decodeJsonArray($raw);
    $parsed = $this->search($this->config['context']['value'], $parsed);
    if (!is_array($parsed)) {
      throw new RuntimeException(t('The context expression must return an object or array.'));
    }

    $state = $source->state(FEEDS_PARSE);
    if (!$state->total) {
      $state->total = count($parsed);
    }

    // @todo Consider using array slice syntax when it is supported.
    $start = (int) $state->pointer;
    $state->pointer = $start + $source->importer->getLimit();
    return array_slice($parsed, $start, $source->importer->getLimit());
  }

  /**
   * {@inheritdoc}
   */
  protected function cleanUp(FeedsSource $source, FeedsParserResult $result) {
    // @todo Verify if this is necessary. Not sure if the runtime keeps a
    // reference to the input data.
    unset($this->runtime);
    // Calculate progress.
    $state = $source->state(FEEDS_PARSE);
    $state->progress($state->total, $state->pointer);
  }

  /**
   * {@inheritdoc}
   */
  protected function executeSourceExpression($machine_name, $expression, $row) {
    $result = $this->search($expression, $row);

    if (is_scalar($result)) {
      return $result;
    }

    // Return a single value if there's only one value.
    return count($result) === 1 ? reset($result) : $result;
  }

  /**
   * {@inheritdoc}
   */
  protected function validateExpression(&$expression) {
    $expression = trim($expression);
    if (!strlen($expression)) {
      return;
    }

    try {
      $this->search($expression, array());
    }
    catch (SyntaxErrorException $e) {
      // Remove newlines after nl2br() to make testing easier.
      return str_replace("\n", '', nl2br(check_plain(trim($e->getMessage()))));
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function startErrorHandling() {
    // Clear the json errors from previous parsing.
    json_decode('');
  }

  /**
   * {@inheritdoc}
   */
  protected function getErrors() {
    if (!function_exists('json_last_error')) {
      return array();
    }

    if (!$error = json_last_error()) {
      return array();
    }

    $message = array(
      'message' => FeedsExJsonUtility::translateError($error),
      'variables' => array(),
      'severity' => WATCHDOG_ERROR,
    );
    return array($message);
  }

  /**
   * {@inheritdoc}
   */
  protected function loadLibrary() {
    if (!$path = feeds_ex_library_path('jmespath.php', 'vendor/autoload.php')) {
      throw new RuntimeException(t('The JMESPath library is not installed.'));
    }

    require_once DRUPAL_ROOT . '/' . $path;
  }

}

/**
 * Converts version 1 runtimes to version 2.
 */
class FeedsExJmesPathV1Wrapper {

  /**
   * The version 1 runtime.
   *
   * @var \JmesPath\Runtime\RuntimeInterface.
   */
  protected $runtime;

  /**
   * Constructs a FeedsExJmesPathV1Wrapper object.
   *
   * @param \JmesPath\Runtime\RuntimeInterface $runtime
   *   A version 1 JMESPath runtime object.
   */
  public function __construct(RuntimeInterface $runtime) {
    $this->runtime = $runtime;
  }

  /**
   * Version 2 runtimes are invokable objects.
   */
  public function __invoke($expression, $data) {
    return $this->runtime->search($expression, $data);
  }

}
