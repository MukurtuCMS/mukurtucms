<?php

/**
 * @file
 * Contains FeedsExJsonPath.
 */

/**
 * Parses JSON via JSONPath.
 */
class FeedsExJsonPath extends FeedsExBase {

  /**
   * {@inheritdoc}
   */
  protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $raw = $this->prepareRaw($fetcher_result);
    $parsed = FeedsExJsonUtility::decodeJsonArray($raw);
    $parsed = jsonPath($parsed, $this->config['context']['value']);
    if (!is_array($parsed)) {
      throw new RuntimeException(t('The context expression must return an object or array.'));
    }

    $state = $source->state(FEEDS_PARSE);
    if (!$state->total) {
      $state->total = count($parsed);
    }

    $start = (int) $state->pointer;
    $state->pointer = $start + $source->importer->getLimit();
    return array_slice($parsed, $start, $source->importer->getLimit());
  }

  /**
   * {@inheritdoc}
   */
  protected function cleanUp(FeedsSource $source, FeedsParserResult $result) {
    // Calculate progress.
    $state = $source->state(FEEDS_PARSE);
    $state->progress($state->total, $state->pointer);
  }

  /**
   * {@inheritdoc}
   */
  protected function executeSourceExpression($machine_name, $expression, $row) {
    $result = jsonPath($row, $expression);

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
    if (!$path = feeds_ex_jsonpath_library_path()) {
      throw new RuntimeException(t('The JSONPath library is not installed.'));
    }

    require_once DRUPAL_ROOT . '/' . $path;
  }

}
