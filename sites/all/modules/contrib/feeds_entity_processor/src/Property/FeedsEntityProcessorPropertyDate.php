<?php

/**
 * @file
 * Contains FeedsEntityProcessorPropertyDate.
 */

/**
 * Handler for date property.
 */
class FeedsEntityProcessorPropertyDate extends FeedsEntityProcessorPropertyDefault {
  /**
   * {@inheritdoc}
   */
  public function validate(&$value) {
    // Entity API won't accept empty date values.
    if (empty($value)) {
      $value = NULL;
      return array();
    }

    return parent::validate($value);
  }
}
