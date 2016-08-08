<?php
/**
 * @file
 * Entity implementation for the paragraphs entity.
 */

/**
 * Class for paragraphs_item entities.
 */
class ParagraphsItemEntity extends Entity {

  /**
   * paragraphs field info.
   *
   * @var array
   */
  protected $fieldInfo;

  /**
   * The host entity object.
   *
   * @var object
   */
  protected $hostEntity;

  /**
   * The host entity ID.
   *
   * @var integer
   */
  protected $hostEntityId;

  /**
   * The host entity revision ID if this is not the default revision.
   *
   * @var integer
   */
  protected $hostEntityRevisionId;

  /**
   * The host entity type.
   *
   * @var string
   */
  protected $hostEntityType;

  /**
   * The host entity bundle.
   *
   * @var string
   */
  protected $hostEntityBundle;

  /**
   * The language under which the paragraphs item is stored.
   *
   * @var string
   */
  protected $langcode = LANGUAGE_NONE;

  /**
   * Entity ID.
   *
   * @var integer
   */
  public $item_id;

  /**
   * paragraphs revision ID.
   *
   * @var integer
   */
  public $revision_id;

  /**
   * The name of the paragraphs field this item is associated with.
   *
   * @var string
   */
  public $field_name;

  /**
   * Whether this revision is the default revision.
   *
   * @var bool
   */
  public $default_revision = TRUE;

  /**
   * Whether the paragraphs item is archived, i.e. not in use.
   *
   * @see ParagraphsItemEntity::isInUse()
   * @var bool
   */
  public $archived = FALSE;

  /**
   * The name of the paragraphs field this item is associated with.
   *
   * @var string
   */
  private $fetchedHostEntityDetails = NULL;

  /**
   * Constructs the entity object.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'paragraphs_item');
    if (isset($this->field_name)) {

      // Ok, we have the field name property, we can proceed and check the field's type
      $field_info = $this->fieldInfo();

      // Check if we have field info, if not, our field is deleted.
      if (!$field_info) {
        return FALSE;
      }

      // We only allow paragraphs type field for this entity.
      if ($field_info['type'] != 'paragraphs') {
        throw new Exception("Invalid field name given: {$this->field_name} is not a paragraphs field.");
      }
    }
  }

  /**
   * Provides info about the field on the host entity, which embeds this
   * paragraphs item.
   */
  public function fieldInfo() {
    return field_info_field($this->field_name);
  }

  /**
   * Provides info of the field instance containing the reference to this
   * paragraphs item.
   */
  public function instanceInfo() {
    return field_info_instance($this->hostEntityType(), $this->field_name, $this->hostEntityBundle());
  }

  /**
   * Returns the field instance label translated to interface language.
   */
  public function translatedInstanceLabel($langcode = NULL) {
    if ($info = $this->instanceInfo()) {
      if (module_exists('i18n_field')) {
        return i18n_string("field:{$this->field_name}:{$info['bundle']}:label", $info['label'], array('langcode' => $langcode));
      }
      return $info['label'];
    }
  }

  /**
   * Specifies the default label, which is picked up by label() by default.
   */
  public function defaultLabel() {
    if ($this->fetchHostDetails()) {

      // Don't show a label, our parent field already shows an label
      // If the user decides he wants to show one.
      return '';
    }

    // Should only happen when there is something wrong
    return t('Unconnected paragraphs item');
  }

  /**
   * Returns the path used to view the entity.
   */
  public function path() {
    return;
  }

  /**
   * Returns the URI as returned by entity_uri().
   */
  public function defaultUri() {
    return array(
      'path' => $this->path(),
    );
  }

  /**
   * Sets the host entity. Only possible during creation of a item.
   *
   * @param $entity_type
   *   The entity type of the host.
   * @param $entity
   *   The host entity.
   * @param $langcode
   *   (optional) The field language code we should use for host entity.
   * @param $create_link
   *   (optional) Whether a field-item linking the host entity to the field
   *   collection item should be created.
   * @throws Exception
   *   When you try to set the host when the item has already been created.
   */
  public function setHostEntity($entity_type, $entity, $langcode = LANGUAGE_NONE, $create_link = TRUE) {
    $this->hostEntityType = $entity_type;
    $this->hostEntity = $entity;
    $this->langcode = $langcode;

    list($this->hostEntityId, $this->hostEntityRevisionId, $this->hostEntityBundle) = entity_extract_ids($this->hostEntityType, $this->hostEntity);
    // If the host entity is not saved yet, set the id to FALSE. So
    // fetchHostDetails() does not try to load the host entity details.
    if (!isset($this->hostEntityId)) {
      $this->hostEntityId = FALSE;
    }
    // We are create a new paragraphs for a non-default entity, thus
    // set archived to TRUE.
    if (!entity_revision_is_default($entity_type, $entity)) {
      $this->hostEntityId = FALSE;
      $this->archived = TRUE;
    }
    if ($create_link) {
      $entity->{$this->field_name}[$this->langcode][] = array('entity' => $this);
    }

    $this->fetchedHostEntityDetails = TRUE;
  }

  /**
   * Function to force change the host entity of this paragraph item.
   *
   * @param $entity
   *   The entity to force the host to.
   */
  public function forceHostEntity($entity) {
    $this->hostEntity = $entity;
  }

  /**
   * Function to force change the host entity type of this paragraph item.
   *
   * @param $entity_type
   *   The entity type to force the host to.
   */
  public function forceHostEntityType($entity_type) {
    $this->hostEntityType = $entity_type;
  }

  /**
   * Returns the host entity, which embeds this paragraph item.
   */
  public function hostEntity() {
    $this->fetchHostDetails();
    return $this->hostEntity;
  }

  /**
   * Returns the entity type of the host entity, which embeds this
   * paragraph item.
   */
  public function hostEntityType() {
    return $this->hostEntityType;
  }

  /**
   * Returns the id of the host entity, which embeds this paragraph item.
   */
  public function hostEntityId() {
    return $this->hostEntityId;
  }

  /**
   * Returns the revisions id of the host entity, which embeds this paragraph item.
   */
  public function hostEntityRevisionId() {
    return $this->hostEntityRevisionId;
  }

  /**
   * Returns the bundle of the host entity, which embeds this paragraphs
   * item.
   */
  public function hostEntityBundle() {
    return $this->hostEntityBundle;
  }

  /**
   * Fetches details of the host and saves it in the entity.
   *
   * @return bool
   *   Whether the fetching was successful.
   */
  protected function fetchHostDetails() {
    if ($this->fetchedHostEntityDetails === NULL) {
      if ($this->item_id) {
        // For saved paragraphs, query the field data to determine the
        // right host entity.
        $query = new EntityFieldQuery();
        $query->fieldCondition($this->fieldInfo(), 'revision_id', $this->revision_id);
        if (!$this->isInUse()) {
          $query->age(FIELD_LOAD_REVISION);
        }
        $result = $query->execute();
        list($this->hostEntityType, $data) = each($result);

        if ($data) {
          $data_values = array_shift($data);
          $host_entity_info = entity_get_info($this->hostEntityType);
          $host_entity_keys = $host_entity_info['entity keys'];

          $this->hostEntityId = (isset($data_values->{$host_entity_keys['id']}) ? $data_values->{$host_entity_keys['id']} : NULL);
          $this->hostEntityRevisionId = (isset($data_values->{$host_entity_keys['revision']}) ? $data_values->{$host_entity_keys['revision']} : NULL);
          $this->hostEntityBundle = (isset($data_values->{$host_entity_keys['bundle']}) ? $data_values->{$host_entity_keys['bundle']} : NULL);

          if ($this->isInUse()) {
            $this->hostEntity = entity_load_single($this->hostEntityType, $this->hostEntityId);
          }
          elseif ($this->hostEntityRevisionId) {
            $this->hostEntity = entity_revision_load($this->hostEntityType, $this->hostEntityRevisionId);
          }

          $this->fetchedHostEntityDetails = TRUE;
        }
        else {
          $this->hostEntityId = FALSE;
          $this->hostEntityRevisionId = FALSE;
          $this->hostEntityBundle = FALSE;
          $this->fetchedHostEntityDetails = FALSE;
        }
      }
      else {
        // No host entity available yet.
        $this->hostEntityId = FALSE;
        $this->hostEntityRevisionId = FALSE;
        $this->hostEntityBundle = FALSE;
        $this->fetchedHostEntityDetails = FALSE;
      }
    }
    return $this->fetchedHostEntityDetails;
  }

  /**
   * Determines the $delta of the reference pointing to this paragraph
   * item.
   */
  public function delta() {
    if (($entity = $this->hostEntity()) && isset($entity->{$this->field_name})) {
      foreach ($entity->{$this->field_name} as $langcode => &$data) {
        foreach ($data as $delta => $item) {
          if (isset($item['value']) && $item['value'] == $this->item_id) {
            $this->langcode = $langcode;
            return $delta;
          }
          elseif (isset($item['entity']) && $item['entity'] === $this) {
            $this->langcode = $langcode;
            return $delta;
          }
        }
      }
    }
  }

  /**
   * Determines the language code under which the item is stored.
   */
  public function langcode() {
    if ($this->delta() !== NULL) {
      return $this->langcode;
    }
  }

  /**
   * Determines whether this paragraphs item revision is in use.
   *
   * paragraphs items may be contained in from non-default host entity
   * revisions. If the paragraphs item does not appear in the default
   * host entity revision, the item is actually not used by default and so
   * marked as 'archived'.
   * If the paragraphs item appears in the default revision of the host
   * entity, the default revision of the paragraphs item is in use there
   * and the collection is not marked as archived.
   */
  public function isInUse() {
    return $this->default_revision && !$this->archived;
  }

  /**
   * Save the paragraphs item.
   *
   * By default, always save the host entity, so modules are able to react
   * upon changes to the content of the host and any 'last updated' dates of
   * entities get updated.
   *
   * For creating an item a host entity has to be specified via setHostEntity()
   * before this function is invoked. For the link between the entities to be
   * fully established, the host entity object has to be updated to include a
   * reference on this paragraphs item during saving. So do not skip
   * saving the host for creating items.
   *
   * @param $skip_host_save
   *   (internal) If TRUE is passed, the host entity is not saved automatically
   *   and therefore no link is created between the host and the item or
   *   revision updates might be skipped. Use with care.
   */
  public function save($skip_host_save = FALSE) {

    // Only save directly if we are told to skip saving the host entity. Else,
    // we always save via the host as saving the host might trigger saving
    // paragraphs items anyway (for example, if a new revision is created).
    if ($skip_host_save) {
      return entity_get_controller($this->entityType)->save($this);
    }
    else {
      $host_entity = $this->hostEntity();
      if (!$host_entity) {
        throw new Exception("Unable to save a paragraph without a valid reference to a host entity.");
      }
      // If this is creating a new revision, also do so for the host entity.
      if (!empty($this->revision) || !empty($this->is_new_revision)) {
        $host_entity->revision = TRUE;
        if (!empty($this->default_revision)) {
          entity_revision_set_default($this->hostEntityType, $host_entity);
        }
      }
      // Set the host entity reference, so the item will be saved with the host.
      // @see paragraphs_field_presave()
      $delta = $this->delta();
      if (isset($delta)) {
        $host_entity->{$this->field_name}[$this->langcode][$delta] = array('entity' => $this);
      }
      else {
        $host_entity->{$this->field_name}[$this->langcode][] =  array('entity' => $this);
      }
      return entity_save($this->hostEntityType, $host_entity);
    }
  }

  /**
   * Deletes the host entity's reference of the paragraphs item.
   */
  protected function deleteHostEntityReference() {
    $delta = $this->delta();
    if ($this->item_id && isset($delta)) {
      unset($this->hostEntity->{$this->field_name}[$this->langcode][$delta]);
      entity_save($this->hostEntityType, $this->hostEntity);
    }
  }

  /**
   * Intelligently delete a paragraphs item revision.
   *
   * If a host entity is revisioned with its paragraphs items, deleting
   * a paragraphs item on the default revision of the host should not
   * delete the collection item from archived revisions too. Instead, we delete
   * the current default revision and archive the paragraph.
   *
   */
  public function deleteRevision($skip_host_update = FALSE) {
    if (!$this->revision_id) {
      return;
    }

    if (!$skip_host_update) {
      // Just remove the item from the host, which cares about deleting the
      // item (depending on whether the update creates a new revision).
      $this->deleteHostEntityReference();
    }

    if (!$this->isDefaultRevision()) {
      entity_revision_delete('paragraphs_item', $this->revision_id);
    }
    // If deleting the default revision, take care!
    else {
      $row = db_select('paragraphs_item_revision', 'r')
        ->fields('r')
        ->condition('item_id', $this->item_id)
        ->condition('revision_id', $this->revision_id, '<>')
        ->execute()
        ->fetchAssoc();
      // If no other revision is left, delete. Else archive the item.
      if (!$row) {
        $this->delete();
      }
      else {
        // Make the other revision the default revision and archive the item.
        db_update('paragraphs_item')
          ->fields(array('archived' => 1, 'revision_id' => $row['revision_id']))
          ->condition('item_id', $this->item_id)
          ->execute();
        entity_get_controller('paragraphs_item')->resetCache(array($this->item_id));
        entity_revision_delete('paragraphs_item', $this->revision_id);
      }
    }
  }

  /**
   * Export the paragraphs item.
   *
   * Since paragraphs entities are not directly exportable (that is, do not
   * have 'exportable' set to TRUE in hook_entity_info()) and since Features
   * calls this method when exporting the paragraphs as a field attached
   * to another entity, we return the export in the format expected by
   * Features, rather than in the normal Entity::export() format.
   */
  public function export($prefix = '') {
    // Based on code in EntityDefaultFeaturesController::export_render().
    $export = "entity_import('" . $this->entityType() . "', '";
    $export .= addcslashes(parent::export(), '\\\'');
    $export .= "')";
    return $export;
  }

  /**
   * Ensure file fields on the entity have their URIs loaded for previews.
   * Copied from #1447338-7, thanks!
   */
  public function view($view_mode = 'full', $langcode = NULL, $page = NULL) {
    if ($langcode == NULL) {
      $langcode = LANGUAGE_NONE;
    }

    // Iterate over fields in the collection to add URIs for image fields.
    $field_instances = field_info_instances($this->entityType, $this->bundle);
    foreach ($field_instances as $field_name => $field) {
      $info = field_info_field($field_name);
      if (is_array($info) && $info['type'] == 'image' && $image_field = &$this->{$field_name}) {
        // Add the URI to the field on the entity for display.
        if (isset($image_field[$langcode])) {
          foreach ($image_field[$langcode] as &$field_to_be_updated) {
            if (!isset($field_to_be_updated['uri']) && isset($field_to_be_updated['fid'])) {
              $image = file_load($field_to_be_updated['fid']);
              if ($image) {
                $field_to_be_updated['uri'] = $image->uri;
              }
            }
          }
        }
      }
    }
    return entity_get_controller($this->entityType)->view(array($this), $view_mode, $langcode, $page);
  }

  /**
   * Magic method to only serialize what's necessary.
   */
  public function __sleep() {
    $vars = get_object_vars($this);

    unset($vars['entityInfo'], $vars['idKey'], $vars['nameKey'], $vars['statusKey']);
    unset($vars['fieldInfo']);

    // Also do not serialize the host entity.
    // We add our hostEntity in code.
    unset($vars['hostEntity']);

    // We unset our host entity, we have to let our object know.
    unset($vars['fetchedHostEntityDetails']);

    // Also key the returned array with the variable names so the method may
    // be easily overridden and customized.
    return drupal_map_assoc(array_keys($vars));
  }

  /**
   * Magic method to invoke setUp() on unserialization.
   *
   * @todo: Remove this once it appears in a released entity API module version.
   */
  public function __wakeup() {
    $this->setUp();
  }
}
