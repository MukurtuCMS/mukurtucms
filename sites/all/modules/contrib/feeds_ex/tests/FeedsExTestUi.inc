<?php

/**
 * @file
 * Contains FeedsExTestUi.
 */

/**
 * A minimal implementation of a parser for UI testing.
 */
class FeedsExTestUi extends FeedsExBase {

  /**
   * {@inheritdoc}
   */
  protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  protected function executeSourceExpression($machine_name, $expression, $row) {
  }

  /**
   * {@inheritdoc}
   */
  protected function validateExpression(&$expression) {
  }

  /**
   * {@inheritdoc}
   */
  protected function getErrors() {
    return array();
  }

}
