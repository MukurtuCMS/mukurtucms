<?php

/**
 * @file
 * Contains FeedsEntityProcessorPropertyBoolean.
 */

/**
 * Handler for boolean property.
 */
class FeedsEntityProcessorPropertyBoolean extends FeedsEntityProcessorPropertyDefault {
  /**
   * {@inheritdoc}
   */
  public function getFormField(&$form, &$form_state, $default) {
    $field = parent::getFormField($form, $form_state, $default);
    $field['#type'] = 'checkbox';

    return $field;
  }
}
