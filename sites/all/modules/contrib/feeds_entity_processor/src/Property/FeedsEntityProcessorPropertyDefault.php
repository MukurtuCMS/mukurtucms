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
   * Implements FeedsEntityProcessorPropertyInterface::getPropertyInfo().
   */
  public function getPropertyInfo() {
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
  public function getFormField(array &$form, array &$form_state, $default) {
    $property_info = $this->getPropertyInfo();

    $field = array(
      '#type' => 'textfield',
      '#title' => check_plain($property_info['label']),
      '#description' => isset($property_info['description']) ? check_plain($property_info['description']) : '',
      '#default_value' => $default,
      '#required' => !empty($property_info['required']),
    );

    // Add machine name of property.
    if (!empty($field['#description'])) {
      $field['#description'] .= '<br />';
    }
    $field['#description'] .= t('Machine name: @name', array(
      '@name' => $this->name,
    ));

    // Add data type info, if available.
    $data_type = $this->getDataType();
    if ($data_type) {
      $field['#description'] .= '<br />' . t('Data type: @type', array(
        '@type' => $data_type,
      ));
    }

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
    $property_info = $this->getPropertyInfo();

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
    $property_info = $this->getPropertyInfo();

    $description = isset($property_info['description']) ? check_plain($property_info['description']) : '';

    // Add data type info, if available.
    $data_type = $this->getDataType();
    if ($data_type) {
      if (!empty($description)) {
        $description .= "\n";
      }
      $description .= t('Data type: @type', array(
        '@type' => $data_type,
      ));
    }

    return array(
      'name' => check_plain($property_info['label']),
      'description' => $description,
    );
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::setValue().
   */
  public function setValue($value, array $mapping) {
    $this->entityWrapper()->get($this->getName())->set($value);
  }

  /**
   * Returns the data type of the current property (if known).
   *
   * @return string|null
   *   The property's data type or NULL if data type is unknown.
   */
  protected function getDataType() {
    $property_info = $this->getPropertyInfo();
    if (isset($property_info['type'])) {
      return $property_info['type'];
    }
  }

}
