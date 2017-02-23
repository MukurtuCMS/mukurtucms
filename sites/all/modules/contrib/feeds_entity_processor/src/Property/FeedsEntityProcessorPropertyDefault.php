<?php

/**
 * @file
 * Contains FeedsEntityProcessorPropertyDefault.
 */

/**
 * Default handler for entity properties.
 */
class FeedsEntityProcessorPropertyDefault implements FeedsEntityProcessorPropertyInterface {
  /**
   * The property name.
   *
   * @var string
   */
  private $name;

  /**
   * Info about the given property.
   *
   * @var array
   */
  private $propertyInfo;

  /**
   * Entity wrapper.
   *
   * @var EntityMetadataWrapper
   */
  private $wrapper;

  /**
   * The processor used to process the data.
   *
   * @var FeedsProcessor
   */
  private $processor;

  /**
   * FeedsEntityProcessorPropertyDefault object constructor.
   */
  public function __construct($name, array $property_info, EntityMetadataWrapper $wrapper, FeedsProcessor $processor) {
    $this->name = $name;
    $this->propertyInfo = $property_info;
    $this->wrapper = $wrapper;
    $this->processor = $processor;
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::getName().
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::getPropertInfo().
   */
  public function getPropertInfo() {
    return $this->propertyInfo;
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::entityWrapper().
   */
  public function entityWrapper() {
    return $this->wrapper;
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::getProcessor().
   */
  public function getProcessor() {
    return $this->processor;
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::getFormField().
   */
  public function getFormField(&$form, &$form_state, $default) {
    $property_info = $this->getPropertInfo();

    $field = array(
      '#type' => 'textfield',
      '#title' => check_plain($property_info['label']),
      '#description' => isset($property_info['description']) ? check_plain($property_info['description']) : '',
      '#default_value' => $default,
      '#required' => !empty($property_info['required']),
    );

    if (!empty($property_info['options list'])) {
      $field['#type'] = 'select';

      if (!is_array($field['#default_value'])) {
        $field['#default_value'] = array($field['#default_value']);
      }

      if (isset($property_info['type']) && entity_property_list_extract_type($property_info['type'])) {
        $field['#type'] = 'checkboxes';
      }

      $name = $this->getName();
      $field['#options'] = $this->entityWrapper()->$name->optionsList();
    }

    return $field;
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::validate().
   */
  public function validate(&$value) {
    $errors = array();
    $property_info = $this->getPropertInfo();

    if (entity_property_list_extract_type($property_info['type']) && !is_array($value)) {
      $value = array($value);
    }

    if ($value === '') {
      return $errors;
    }

    if (!entity_property_verify_data_type($value, $property_info['type'])) {
      $errors[] = t('Invalid data value given. Be sure it matches the required data type and format.');
    }

    return $errors;
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::getMappingTarget().
   */
  public function getMappingTarget() {
    $property_info = $this->getPropertInfo();

    return array(
      'name' => check_plain($property_info['label']),
      'description' => isset($property_info['description']) ? check_plain($property_info['description']) : '',
    );
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::setValue().
   */
  public function setValue($value, array $mapping) {
    $this->entityWrapper()->get($this->getName())->set($value);
  }
}
