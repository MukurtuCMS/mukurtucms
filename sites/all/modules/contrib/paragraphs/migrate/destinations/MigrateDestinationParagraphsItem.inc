<?php

/**
 * Provides basic class for importing Paragraphs via Migrate API.
 */
class MigrateDestinationParagraphsItem extends MigrateDestinationEntity {

  /**
   * The bundle (node type, vocabulary, etc.) of the destination.
   *
   * @var string
   */
  protected $field_name;

  /**
   * {@inheritdoc}
   */
  public function getFieldName() {
    return $this->field_name;
  }

  /**
   * {@inheritdoc}
   */
  public static function getKeySchema() {
    return array(
      'item_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'ID of field collection item',
      ),
    );
  }

  /**
   * Basic initialization.
   *
   * @param object $bundle
   *   A bundle.
   * @param array $options
   *   (optional) Options applied to collections.
   */
  public function __construct($bundle, array $options = array()) {
    parent::__construct('paragraphs_item', $bundle, $options);

    $this->field_name = isset($options['field_name']) ? $options['field_name'] : '';
  }

  /**
   * Return an options array for node destinations.
   *
   * @param string $language
   *   Default language for nodes created via this destination class.
   * @param string $text_format
   *   Default text format for nodes created via this destination class.
   *
   * @return array
   *   An array of options.
   */
  public static function options($language, $text_format) {
    return compact('language', 'text_format');
  }

  /**
   * Returns a list of fields available to be mapped for the node type (bundle)
   *
   * @param Migration $migration
   *   Optionally, the migration containing this destination.
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields(Migration $migration = NULL) {
    $fields = array();

    $fields['field_name'] = t('Field name');
    $fields['archived'] = t('Archived status of the paragraph item');

    $fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle, $migration);
    $fields += migrate_handler_invoke_all('ParagraphsItem', 'fields', $this->entityType, $this->bundle, $migration);

    return $fields;
  }

  /**
   * Delete a batch of nodes at once.
   *
   * @param array $item_ids
   *   Array of node IDs to be deleted.
   */
  public function bulkRollback(array $item_ids) {
    migrate_instrument_start('paragraphs_item_delete_multiple');
    $this->prepareRollback($item_ids);
    entity_delete_multiple('paragraphs_item', $item_ids);
    $this->completeRollback($item_ids);
    migrate_instrument_stop('paragraphs_item_delete_multiple');
  }

  /**
   * Import a single node.
   *
   * @param object $paragraphs_item
   *   Node object to build Prefilled with any fields mapped in the Migration.
   * @param object $row
   *   Raw source data object - passed through to prepare/complete handlers.
   *
   * @return array|bool
   *   Array of key fields (nid only in this case) of the node that was saved if
   *   successful. FALSE on failure.
   *
   * @throws MigrateException
   */
  public function import(object $paragraphs_item, object $row) {
    $migration = Migration::currentMigration();

    // Updating previously-migrated content?
    if (isset($row->migrate_map_destid1)) {
      if (isset($paragraphs_item->item_id)) {
        if ($paragraphs_item->item_id != $row->migrate_map_destid1) {
          throw new MigrateException(t("Incoming item_id !item_id and map destination item_id !destid1 don't match",
            array('!item_id' => $paragraphs_item->item_id, '!destid1' => $row->migrate_map_destid1)));
        }
      }
      else {
        $paragraphs_item->item_id = $row->migrate_map_destid1;
        $paragraphs_item->is_new = FALSE;
        $paragraphs_item->is_new_revision = FALSE;

        // Get the existing revision_id so updates don't generate notices.
        $values = db_select('paragraphs_item', 'p')
          ->fields('p', array('revision_id'))
          ->condition('item_id', $paragraphs_item->item_id)
          ->execute()
          ->fetchAssoc();
        if (empty($values)) {
          throw new MigrateException(t("Incoming paragraphs ID !item_id no longer exists",
            array('!item_id' => $paragraphs_item->item_id)));
        }
        $paragraphs_item->revision_id = $values['revision_id'];
      }
    }

    // When updating, we make sure that id exists.
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      if (!isset($paragraphs_item->item_id)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but no destination item_id provided'));
      }

      // Hold raw original values for later.
      $raw_paragraph = $paragraphs_item;

      // This entity will be the one, we party on.
      $entity = paragraphs_item_load($paragraphs_item->item_id);
      if (empty($entity)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but paragraphs item !item_id does not exist',
          array('!item_id' => $paragraphs_item->item_id)));
      }
    }
    // Provide defaults for SOURCE d.
    else {
      // Set some default properties.
      $defaults = array(
        'language' => $this->language,
        'bundle' => $this->bundle,
        'field_name' => $this->field_name,
        'archived' => 0,
      );
      foreach ($defaults as $field => $value) {
        if (!isset($paragraphs_item->$field)) {
          $paragraphs_item->$field = $value;
        }
      }
    }

    $this->prepare($paragraphs_item, $row);

    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      foreach ($raw_paragraph as $field => $value) {
        $entity->$field = $paragraphs_item->$field;
      }
    }
    else {

      // This will be the entity we party on.
      $entity = entity_create('paragraphs_item', (array) $paragraphs_item);
    }

    if (isset($entity->item_id) && $entity->item_id) {
      $updating = TRUE;
    }
    else {
      $updating = FALSE;
    }

    migrate_instrument_start('paragraphs_item_save');
    $entity->save(TRUE);
    migrate_instrument_stop('paragraphs_item_save');

    $this->complete($entity, $row);
    if (isset($entity->item_id) && $entity->item_id > 0) {
      $return = array($entity->item_id);
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
    }
    else {
      $return = FALSE;
    }
    return $return;
  }

}
