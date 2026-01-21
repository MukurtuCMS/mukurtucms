<?php

/**
 * @file
 * Contains FeedsEntityProcessorPropertyEntity.
 */

/**
 * Handler for entity property.
 */
class FeedsEntityProcessorPropertyEntity extends FeedsEntityProcessorPropertyDefault {

  /**
   * {@inheritdoc}
   */
  public function getFormField(array &$form, array &$form_state, $default) {
    $property_info = $this->getPropertyInfo();

    $field = array(
      '#type' => 'fieldset',
      '#title' => check_plain($property_info['label']),
      '#description' => isset($property_info['description']) ? check_plain($property_info['description']) : '',
      '#required' => !empty($property_info['required']),
      '#tree' => TRUE,
    );
    $field['entity_type'] = array(
      '#title' => t('Entity type'),
      '#type' => 'select',
      '#options' => array(
        '' => t('- Select -'),
      ) + $this->getEntityTypeOptions(),
      '#default_value' => isset($default['entity_type']) ? $default['entity_type'] : NULL,
      '#required' => !empty($property_info['required']),
    );
    $field['entity_id'] = array(
      '#title' => t('Entity ID'),
      '#type' => 'textfield',
      '#default_value' => isset($default['entity_id']) ? $default['entity_id'] : NULL,
      '#required' => !empty($property_info['required']),
    );

    return $field;
  }

  /**
   * Returns available entity types.
   *
   * @return array
   *   A list of entity types keyed by machine name => label.
   */
  public function getEntityTypeOptions() {
    $entity_type_options = &drupal_static(__METHOD__);

    if (empty($entity_type_options)) {
      $info = entity_get_info();
      foreach ($info as $entity_type => $entity_type_info) {
        $entity_type_options[$entity_type] = $entity_type_info['label'];
      }
    }

    return $entity_type_options;
  }

  /**
   * {@inheritdoc}
   */
  public function validate(&$value) {
    if (!empty($value['entity_type']) && !empty($value['entity_id'])) {
      $entity = entity_load_single($value['entity_type'], $value['entity_id']);
      if (!$entity) {
        $entity_types = $this->getEntityTypeOptions();
        return array(
          t('@entity_type with ID "@entity_id" does not exist.', array(
            '@entity_type' => $entity_types[$value['entity_type']],
            '@entity_id' => $value['entity_id'],
          )),
        );
      }

      $wrapper = entity_metadata_wrapper($value['entity_type'], $value['entity_id']);
      return parent::validate($wrapper);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getMappingTarget() {
    $target = parent::getMappingTarget();

    $target['form_callbacks'][] = array($this, 'mappingFormCallback');
    $target['summary_callbacks'][] = array($this, 'mappingSummaryCallback');

    return $target;
  }

  /**
   * Returns the entity type to map to.
   *
   * @param array $mapping
   *   The saved mapping configuration.
   *
   * @return string
   *   The entity type to map to, if known.
   *   NULL otherwise.
   */
  public function getMappingEntityType(array $mapping) {
    if (!empty($mapping['entity_type'])) {
      return $mapping['entity_type'];
    }

    $config = $this->getProcessor()->getConfig();
    if (!empty($config['values'][$this->getName()]['entity_type'])) {
      return $config['values'][$this->getName()]['entity_type'];
    }
  }

  /**
   * Form callback for 'entity' mapping target.
   */
  public function mappingFormCallback(array $mapping, $target, array $form, array $form_state) {
    return array(
      'entity_type' => array(
        '#type' => 'select',
        '#title' => t('Entity type'),
        '#options' => array(
          '' => t('- Select -'),
        ) + $this->getEntityTypeOptions(),
        '#default_value' => $this->getMappingEntityType($mapping),
        '#required' => TRUE,
      ),
    );
  }

  /**
   * Summary callback for 'entity' mapping target.
   */
  public function mappingSummaryCallback(array $mapping, $target, array $form, array $form_state) {
    $entity_type = $this->getMappingEntityType($mapping);

    if (!$entity_type) {
      return t('Entity type: %entity_type', array(
        '%entity_type' => t('None'),
      ));
    }
    else {
      $entity_types = $this->getEntityTypeOptions();
      return t('Entity type: %entity_type', array(
        '%entity_type' => $entity_types[$entity_type],
      ));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function setValue($value, array $mapping) {
    $wrapper = NULL;

    if (is_scalar($value)) {
      $entity_type = $this->getMappingEntityType($mapping);
      if (!$entity_type) {
        throw new FeedsValidationException(t('Mapping option %name not set for target %target.', array(
          '%name' => t('Entity type'),
          '%target' => !empty($mapping['target']) ? $mapping['target'] : $this->getName(),
        )));
      }
      $wrapper = entity_metadata_wrapper($entity_type, $value);
    }

    if (is_array($value) && !empty($value['entity_type']) && !empty($value['entity_id'])) {
      $wrapper = entity_metadata_wrapper($value['entity_type'], $value['entity_id']);
    }

    if ($wrapper) {
      parent::setValue($wrapper, $mapping);
    }
  }

}
