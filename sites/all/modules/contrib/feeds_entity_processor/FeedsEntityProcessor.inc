<?php

/**
 * @file
 * Contains FeedsEntityProcessor.
 */

/**
 * Creates entities from feed items.
 */
class FeedsEntityProcessor extends FeedsProcessor {

  /**
   * Returns the entity type.
   *
   * @return string
   *   The type of entity this processor will create.
   */
  public function entityType() {
    $plugin_info = $this->pluginDefinition();
    return $plugin_info['type'];
  }

  /**
   * Returns the bundle key.
   *
   * @return string|false
   *   The bundle key, or false if the entity type doesn't have one.
   */
  protected function bundleKey() {
    $entity_info = $this->entityInfo();
    return isset($entity_info['bundle keys']['bundle']) ? $entity_info['bundle keys']['bundle'] : FALSE;
  }

  /**
   * Returns the translated label for the bundle.
   *
   * @return string|false
   *   The translated label, or false if the entity does not have a label.
   */
  protected function bundleLabel() {
    if (!$bundle_key = $this->bundleKey()) {
      return FALSE;
    }

    $property = $this->entityWrapper()->getPropertyInfo($bundle_key);
    return isset($property['label']) ? check_plain($property['label']) : t('Bundle');
  }

  /**
   * Overrides parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = isset($info['label plural']) ? $info['label plural'] : $info['label'];

    return $info;
  }

  /**
   * Returns the entity properties that this processor is using.
   *
   * @return array
   *   An array keyed by property name.
   */
  protected function entityProperties() {
    $properties = array();
    $bundle_key = $this->bundleKey();

    foreach ($this->entityWrapper()->getPropertyInfo() as $name => $property) {
      // Skip bundle.
      if ($bundle_key === $name) {
        continue;
      }

      if (empty($property['setter callback']) || !empty($property['field'])) {
        continue;
      }

      $properties[$name] = $property;
    }

    return $properties;
  }

  /**
   * Returns the entity wrapper metadata for the processor's entity type.
   *
   * @return EntityMetadataWrapper
   *  An entity metadata wrapper.
   */
  protected function entityWrapper() {
    if ($this->bundleKey()) {
      return entity_metadata_wrapper($this->entityType(), NULL, array('bundle' => $this->bundle()));
    }

    return entity_metadata_wrapper($this->entityType());
  }

  /**
   * Implements FeedsProcessor::newEntity().
   */
  protected function newEntity(FeedsSource $source) {
    if ($bundle_key = $this->bundleKey()) {
      return entity_create($this->entityType(), array($bundle_key => $this->bundle()) + $this->config['values']);
    }

    return entity_create($this->entityType(), $this->config['values']);
  }

  /**
   * Overrides parent::entitySaveAccess().
   *
   * @todo Is checking the uid safe? A quick glance through core and some
   *   contrib seems to say yes.
   */
  protected function entitySaveAccess($entity) {
    // The check will be skipped for anonymous users.
    if (!$this->config['authorize'] || empty($entity->uid)) {
      return;
    }

    // If the uid was mapped directly, rather than by email or username, it
    // could be invalid.
    if (!$author = user_load($entity->uid)) {
      throw new FeedsAccessException(t('User %uid is not a valid user.', array('%uid' => $entity->uid)));
    }

    $op = !empty($entity->is_new) ? 'create' : 'update';

    // Check if user can create/update the entity.
    if (entity_access($op, $this->entityType(), $entity, $author)) {
      return;
    }

    $args = array(
      '%name' => $author->name,
      '%op' => $op,
      '%entity' => $this->entityType(),
    );

    throw new FeedsAccessException(t('User %name is not authorized to %op entity %entity.', $args));
  }

  /**
   * Implements FeedsProcessor::entitySave().
   */
  public function entitysave($entity) {
    entity_save($this->entityType(), $entity);
  }

  /**
   * Implements FeedsProcessor::entityDeleteMultiple().
   */
  protected function entityDeleteMultiple($ids) {
    entity_delete_multiple($this->entityType(), $ids);
  }

  /**
   * Overrides parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'values' => array(),
      'authorize' => TRUE,
    ) + parent::configDefaults();
  }

  /**
   * Overrides parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    $form['bundle']['#title'] = $this->bundleLabel();

    $form['values'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default values'),
      '#tree' => TRUE,
      '#description' => t('Most of the values below can be overriden by mapping a value.'),
    );

    $entity_info = $this->entityInfo();
    $label_plural = $entity_info['label plural'];

    $form['input_format']['#description'] = t('Select the default input format for the %entity to be created.', array('%entity' => $label_plural));

    foreach ($this->entityProperties() as $name => $property) {

      $form['values'][$name] = array(
        '#type' => 'textfield',
        '#title' => check_plain($property['label']),
        '#description' => isset($property['description']) ? check_plain($property['description']) : '',
        '#default_value' => isset($this->config['values'][$name]) ? $this->config['values'][$name] : NULL,
        '#required' => !empty($property['required']),
      );

      if (!empty($property['options list'])) {
        $form['values'][$name]['#type'] = 'select';

        if (!is_array($form['values'][$name]['#default_value'])) {
          $form['values'][$name]['#default_value'] = array($form['values'][$name]['#default_value']);
        }

        if (isset($property['type']) && entity_property_list_extract_type($property['type'])) {
          $form['values'][$name]['#type'] = 'checkboxes';
        }

        $form['values'][$name]['#options'] = $this->entityWrapper()->$name->optionsList();
      }

      elseif (!empty($property['type']) && $property['type'] === 'boolean') {
        $form['values'][$name]['#type'] = 'checkbox';
      }
    }

    return $form;
  }

  /**
   * Overrides parent::configFormValidate().
   */
  public function configFormValidate(&$values) {

    $form = parent::configFormValidate($values);

    foreach ($this->entityProperties() as $name => $property) {

      // Entity api won't accept empty date values.
      if (!empty($property['type']) && $property['type'] === 'date') {
        if (empty($values['values'][$name])) {
          unset($values['values'][$name]);
          continue;
        }
      }

      if (!isset($property['type']) || !array_key_exists($name, $values['values'])) {
        continue;
      }

      $value = $values['values'][$name];

      if (entity_property_list_extract_type($property['type']) && !is_array($value)) {
        $values['values'][$name] = array($value);
      }

      if ($value === '') {
        continue;
      }

      if (!entity_property_verify_data_type($value, $property['type'])) {
        form_set_error("values][$name", t('Invalid data value given. Be sure it matches the required data type and format.'));
      }
    }
  }

  /**
   * Overrides parent::getMappingTargets().
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();

    foreach ($this->entityProperties() as $name => $property) {
      $targets[$name] = array(
        'name' => check_plain($property['label']),
        'description' => isset($property['description']) ? check_plain($property['description']) : '',
      );
    }

    $entity_info = $this->entityInfo();
    $targets[$entity_info['entity keys']['id']]['optional_unique'] = TRUE;

    // Let other modules expose mapping targets.
    self::loadMappers();
    $type = $this->entityType();
    $bundle = $this->bundle();
    drupal_alter('feeds_processor_targets', $targets, $type, $bundle);

    return $targets;
  }

}
