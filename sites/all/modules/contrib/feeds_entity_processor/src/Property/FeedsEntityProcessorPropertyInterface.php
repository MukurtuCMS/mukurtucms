<?php

/**
 * @file
 * Contains FeedsEntityProcessorPropertyInterface.
 */

interface FeedsEntityProcessorPropertyInterface {
  /**
   * Returns the property's name.
   *
   * @return string
   *   The property name.
   */
  public function getName();

  /**
   * Returns info about the property.
   *
   * @return array
   *   The property info.
   */
  public function getPropertInfo();

  /**
   * Returns entity metata wrapper.
   *
   * @return EntityMetadataWrapper
   *   An instance of EntityMetadataWrapper.
   */
  public function entityWrapper();

  /**
   * Returns the processor that is processing the data.
   *
   * @return FeedsProcessor
   *   An instance of FeedsProcessor.
   */
  public function getProcessor();

  /**
   * Returns a field to insert a value for the property.
   *
   * @param array $form
   *   The form in which the field will appear.
   * @param array $form_state
   *   The form state.
   * @param mixed $default
   *   The default value for the field.
   *
   * @return array
   *   A Drupal Form API field.
   */
  public function getFormField(&$form, &$form_state, $default);

  /**
   * Validates the value for the property.
   *
   * @param mixed $value
   *   The value to validate.
   *
   * @return array
   *   A list of errors, if there are errors.
   */
  public function validate(&$value);

  /**
   * Returns a mapping target.
   *
   * @return array
   *   The mapping target.
   */
  public function getMappingTarget();

  /**
   * Sets a value on the entity.
   *
   * @param mixed $value
   *   The value to set.
   * @param array $mapping
   *   Mapping configuration.
   */
  public function setValue($value, array $mapping);
}
