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
    return isset($entity_info['entity keys']['bundle']) ? $entity_info['entity keys']['bundle'] : FALSE;
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

    try {
      $property = $this->entityWrapper()->getPropertyInfo($bundle_key);
    }
    catch (EntityMetadataWrapperException $e) {
      // Ignore any metadata wrapper exceptions.
    }
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
   * @param object $entity
   *   (optional) The entity object to wrap.
   *
   * @return EntityMetadataWrapper
   *   An entity metadata wrapper.
   */
  protected function entityWrapper($entity = NULL) {
    if ($this->bundleKey()) {
      return entity_metadata_wrapper($this->entityType(), $entity, array('bundle' => $this->bundle()));
    }

    return entity_metadata_wrapper($this->entityType(), $entity);
  }

  /**
   * Implements FeedsProcessor::newEntity().
   */
  protected function newEntity(FeedsSource $source) {
    if ($bundle_key = $this->bundleKey()) {
      $entity = entity_create($this->entityType(), array($bundle_key => $this->bundle()) + $this->config['values']);
    }
    else {
      $entity = entity_create($this->entityType(), $this->config['values']);
    }

    // Set created/changed date. The entity type may support these values.
    $entity->created = REQUEST_TIME;
    $entity->changed = REQUEST_TIME;

    // Set properties on the entity.
    foreach ($this->entityProperties() as $name => $property) {
      if (isset($this->config['values'][$name]) && $this->config['values'][$name] !== '') {
        $plugin = feeds_entity_processor_plugin($name, $property, $this->entityWrapper($entity), $this);
        $plugin->setValue($this->config['values'][$name], array());
      }
    }

    return $entity;
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
   * Overrides FeedsConfigurable::hasConfigForm().
   */
  public function hasConfigForm() {
    return TRUE;
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
      $default = isset($this->config['values'][$name]) ? $this->config['values'][$name] : NULL;
      $plugin = feeds_entity_processor_plugin($name, $property, $this->entityWrapper(), $this);
      $form['values'][$name] = $plugin->getFormField($form, $form_state, $default);
    }

    return $form;
  }

  /**
   * Overrides parent::configFormValidate().
   */
  public function configFormValidate(&$values) {

    $form = parent::configFormValidate($values);

    foreach ($this->entityProperties() as $name => $property) {
      if (!isset($property['type']) || !array_key_exists($name, $values['values'])) {
        continue;
      }

      // Validate the value.
      $plugin = feeds_entity_processor_plugin($name, $property, $this->entityWrapper(), $this);
      $errors = $plugin->validate($values['values'][$name]);

      if (count($errors) === 1) {
        $error = reset($errors);
        form_set_error("values][$name", $error);
      }
      elseif (count($errors) > 1) {
        $errors = theme('item_list', array(
          'items' => $errors,
        ));
        form_set_error("values][$name", t('The field %field has the following errors: !errors', array(
          '%field' => $property['label'],
          '!errors' => $errors,
        )));
      }
    }
  }

  /**
   * Overrides parent::getMappingTargets().
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();

    foreach ($this->entityProperties() as $name => $property) {
      $plugin = feeds_entity_processor_plugin($name, $property, $this->entityWrapper(), $this);
      $targets[$name] = $plugin->getMappingTarget();
    }

    $entity_info = $this->entityInfo();
    $targets[$entity_info['entity keys']['id']]['optional_unique'] = TRUE;

    // Let other modules expose mapping targets.
    $this->getHookTargets($targets);

    return $targets;
  }

  /**
   * {@inheritdoc}
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value, array $mapping = array()) {
    $properties = $this->entityProperties();
    if (isset($properties[$target_element])) {
      $plugin = feeds_entity_processor_plugin($target_element, $properties[$target_element], $this->entityWrapper($target_item), $this);
      $plugin->setValue($value, $mapping);
    }
    else {
      parent::setTargetElement($source, $target_item, $target_element, $value);
    }
  }

  /**
   * Overrides FeedsProcessor::existingEntityId().
   *
   * Tries to retrieve entity by ID if marked as unique target.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    $targets = $this->uniqueTargets($source, $result);

    $entity_info = $this->entityInfo();
    $entity_type = $this->entityType();
    if (!empty($entity_info['entity keys']['id']) && isset($targets[$entity_info['entity keys']['id']])) {
      $entity_id = $targets[$entity_info['entity keys']['id']];
      // Check if entity ID exists.
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', $entity_type)
        ->entityCondition('entity_id', $entity_id);

      $query_result = $query->execute();
      if (!empty($query_result[$entity_type])) {
        return $entity_id;
      }
    }

    // If no entity was found by now, try parent.
    return parent::existingEntityId($source, $result);
  }

}
