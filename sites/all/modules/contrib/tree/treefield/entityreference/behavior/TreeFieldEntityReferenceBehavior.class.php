<?php

/**
 * Extend an entityreference field to support tree-like structures.
 */
class TreeFieldEntityReferenceBehavior extends EntityReference_BehaviorHandler_Abstract {

  protected $providers = array();
  protected $storages = array();

  public function settingsForm($field, $instance) {
    $plugins = tree_get_providers('Tree_Storage_SQL_Field');
    $options = array();
    foreach ($plugins as $plugin_name => $plugin_info) {
      $options[$plugin_name] = $plugin_info['title'];
    }
    // This should never happen, since treefield comes with two builtin providers.
    if (empty($options)) {
      throw new TreeFieldMissingProviderException('No provider found for treefield.');
    }

    $default_provider = isset($field['settings']['handler_settings']['behaviors']['treefield_sql']['provider'])
      ? $field['settings']['handler_settings']['behaviors']['treefield_sql']['provider']
      : reset(array_keys($options));
    $form['provider'] = array(
      '#title' => t('Provider'),
      '#type' => 'select',
      '#required' => TRUE,
      '#multiple' => FALSE,
      '#size' => 1,
      '#options' => $options,
      '#default_value' => $default_provider,
    );
    return $form;
  }

  /**
   * @return Tree_Storage
   */
  public function storage($field) {
    if (!isset($this->storages[$field['field_name']])) {
      // @todo: Currently hardcoded. We should have two implementation here:
      // one for field_sql_storage fields and one for other fields.
      $this->storages[$field['field_name']] = new Tree_Storage_SQL_Field(Database::getConnection(), $field);
    }
    return $this->storages[$field['field_name']];
  }

  /**
   * @return Tree_Provider
   */
  public function provider($field) {
    if (!isset($this->providers[$field['field_name']])) {
      $provider_name = !empty($field['settings']['handler_settings']['behaviors']['treefield_sql']['provider']) ? $field['settings']['handler_settings']['behaviors']['treefield_sql']['provider'] : 'Tree_Provider_Simple';
      $provider = new $provider_name($this->storage($field));

      // Create the schema of the provider.
      // @todo: Move somewhere else.
      if ($provider instanceof Tree_Provider_SQL) {
        $provider_schema = $provider->schema();
        foreach ($provider_schema as $table_name => $table_schema) {
          if (!db_table_exists($table_name)) {
            db_create_table($table_name, $table_schema);
          }
        }
      }

      $this->providers[$field['field_name']] = $provider;
    }
    return $this->providers[$field['field_name']];
  }

  public function schema_alter(&$schema, $field) {
    // Treefield needs to store NULL values (roots) in target_id.
    $schema['columns']['target_id']['not null'] = FALSE;

    $schema['columns']['weight'] = array(
      'description' => 'The weight of the entity among its siblings.',
      'type' => 'int',
      'not null' => FALSE,
      'default' => 0,
    );

    // Add the depth column only if treefield_update_7000() has run (or the
    // module is freshly enabled).
    if (drupal_get_installed_schema_version('treefield') >= 7000) {
      $schema['columns']['depth'] = array(
        'description' => 'The depth of the entity in the tree structure.',
        'type' => 'int',
        'not null' => FALSE,
        'default' => 0,
      );
    }
  }

  public function property_info_alter(&$info, $entity_type, $field, $instance, $field_type) {
    $property = &$info[$entity_type]['bundles'][$instance['bundle']]['properties'][$field['field_name']];

    $property['type'] = 'struct';
    $property['getter callback'] = '_treefield_metadata_field_verbatim_get';
    $property['setter callback'] = 'entity_metadata_field_verbatim_set';
    $property['property info'] = array();

    $properties = &$property['property info'];

    $properties['parent'] = array(
      'type' => $field['settings']['target_type'],
      'label' => t('Direct parent'),
      'getter callback' => '_treefield_metadata_router_get',
      'setter callback' => '_treefield_metadata_parent_set',
      'field_name' => $field['field_name'],
      'behavior' => $this->plugin['name'],
    );
    $properties['root'] = array(
      'type' => $field['settings']['target_type'],
      'label' => t('Root'),
      'getter callback' => '_treefield_metadata_router_get',
      'field_name' => $field['field_name'],
      'behavior' => $this->plugin['name'],
    );
    $properties['ancestors'] = array(
      'type' => 'list<' . $field['settings']['target_type'] . '>',
      'label' => t('All the ancestors'),
      'getter callback' => '_treefield_metadata_router_get',
      'field_name' => $field['field_name'],
      'behavior' => $this->plugin['name'],
    );
    $properties['children'] = array(
      'type' => 'list<' . $field['settings']['target_type'] . '>',
      'label' => t('Children'),
      'getter callback' => '_treefield_metadata_router_get',
      'field_name' => $field['field_name'],
      'behavior' => $this->plugin['name'],
    );
    $properties['descendants'] = array(
      'type' => 'list<' . $field['settings']['target_type'] . '>',
      'label' => t('All the descendants'),
      'getter callback' => '_treefield_metadata_router_get',
      'field_name' => $field['field_name'],
      'behavior' => $this->plugin['name'],
    );
    $properties['siblings'] = array(
      'type' => 'list<' . $field['settings']['target_type'] . '>',
      'label' => t('Siblings'),
      'getter callback' => '_treefield_metadata_router_get',
      'field_name' => $field['field_name'],
      'behavior' => $this->plugin['name'],
    );
  }

  public function views_data_alter(&$data, $field) {
    $this->storage($field)->views_data_alter($data, $field);

    if ($this->provider($field) instanceof Tree_Provider_SQL) {
      $this->provider($field)->views_data_alter($data);
    }
  }

  public function presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
    if (count($items)) {
      list($id, , ) = entity_extract_ids($entity_type, $entity);
      $item = $this->storage($field)->itemFromFieldData($id, $items[0]);
      $this->provider($field)->preSave($item);
      $items[0] = $this->storage($field)->itemToFieldData($item);
    }
  }

  public function is_empty_alter(&$empty, $item, $field) {
    $empty = FALSE;
  }

  public function postInsert($entity_type, $entity, $field, $instance) {
    if (!empty($entity->{$field['field_name']})) {
      list($id, , ) = entity_extract_ids($entity_type, $entity);
      // TODO: not ideal, should we track per language?
      $items = reset($entity->{$field['field_name']});
      $item = reset($items);
      $item = $this->storage($field)->itemFromFieldData($id, $item);
      $this->provider($field)->postInsert($item);
    }
  }

  public function postUpdate($entity_type, $entity, $field, $instance) {
    if (!empty($entity->{$field['field_name']})) {
      list($id, , ) = entity_extract_ids($entity_type, $entity);
      // TODO: not ideal, should we track per language?
      $items = reset($entity->{$field['field_name']});
      $item = reset($items);
      $item = $this->storage($field)->itemFromFieldData($id, $item);
      $this->provider($field)->postUpdate($item);
    }
  }

  public function postDelete($entity_type, $entity, $field, $instance) {
    if (!empty($entity->{$field['field_name']})) {
      list($id, , ) = entity_extract_ids($entity_type, $entity);
      $this->provider($field)->postDelete($id);
    }
  }

  /**
   * Return the Storage item for the passed Drupal item.
   *
   * @param array $item
   *    Unused.
   * @param array $info
   * @param array $field
   *
   * @return array|NULL
   *   NULL is there is no matching Storage item.
   */
  protected function metadata_prepare_item($item, $info, $field) {
    // First, get the wrapper of the field.
    $field_wrapper = $info['parent'];
    $field_info = $field_wrapper->info();
    // Then, move one level up to the entity wrapper.
    $entity_wrapper = $field_info['parent'];
    $id = $entity_wrapper->getIdentifier();
    if ($id === FALSE) {
      $ret = NULL;
    }
    else {
      $entity_info = $entity_wrapper->entityInfo();
      $entity = $entity_wrapper->value();
      $ret = $this->storage($field)->itemFromFieldData($entity->{$entity_info['entity keys']['id']}, $item);
    }
    return $ret;
  }

  /**
   * Getter callback for hook_entity_property_info().
   *
   * Has to return NULL if the parent is not found
   *
   * @see hook_entity_property_info()
   */
  public function metadata_parent_get($item, $options, $name, $type, $info, $field) {
    $ret = NULL;
    $item = $this->metadata_prepare_item($item, $info, $field);
    if ($item) {
      $items = $this->provider($field)->parentOf($item)->execute();
      $parent = reset($items);
      if ($parent) {
        $ret = $parent->id;
      }
    }
    return $ret;
  }

  public function metadata_root_get($item, $options, $name, $type, $info, $field) {
    $item = $this->metadata_prepare_item($item, $info, $field);
    $items = $this->provider($field)->rootOf($item)->execute();
    $root = reset($items);
    if ($root) {
      return $root->id;
    }
  }

  public function metadata_ancestors_get($item, $options, $name, $type, $info, $field) {
    $item = $this->metadata_prepare_item($item, $info, $field);
    $ancestor_ids = array();
    if ($item instanceof Tree_Storage_Item) {
      $provider = $this->provider($field);
      foreach ($provider->ancestorsOf($item)->execute() as $ancestor) {
        $ancestor_ids[] = $ancestor->id;
      }
    }
    return $ancestor_ids;
  }

  public function metadata_children_get($item, $options, $name, $type, $info, $field) {
    $item = $this->metadata_prepare_item($item, $info, $field);
    $children_ids = array();
    if ($item instanceof Tree_Storage_Item) {
      $provider = $this->provider($field);
      foreach ($provider->childrenOf($item)->execute() as $child) {
        $children_ids[] = $child->id;
      }
    }
    return $children_ids;
  }

  public function metadata_descendants_get($item, $options, $name, $type, $info, $field) {
    $item = $this->metadata_prepare_item($item, $info, $field);
    $descendants_ids = array();
    foreach ($this->provider($field)->descendantsOf($item)->execute() as $child) {
      $descendants_ids[] = $child->id;
    }
    return $descendants_ids;
  }

  public function metadata_siblings_get($item, $options, $name, $type, $info, $field) {
    $item = $this->metadata_prepare_item($item, $info, $field);
    $sibling_ids = array();
    foreach ($this->provider($field)->siblingsOf($item)->execute() as $sibling) {
      $sibling_ids[] = $sibling->id;
    }
    return $sibling_ids;
  }
}
