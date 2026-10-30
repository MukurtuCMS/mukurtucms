<?php

/**
 * A implementation of the SQL-joinable storage for fields stored in
 * field_sql_storage.
 */
class Tree_Storage_SQL_Field extends Tree_Storage_SQL {

  /**
   * Constructs a Tree_Storage_SQL_Field object.
   */
  public function __construct(DatabaseConnection $database, array $field) {
    $this->database = $database;
    $this->field = $field;

    $this->tableName = key($this->field['storage']['details']['sql'][FIELD_LOAD_CURRENT]);
    $this->columnMap = array(
      'id' => 'entity_id',
      'parent' => $this->field['storage']['details']['sql'][FIELD_LOAD_CURRENT][$this->tableName]['target_id'],
      'weight' => $this->field['storage']['details']['sql'][FIELD_LOAD_CURRENT][$this->tableName]['weight'],
    );
    // The depth column might not exist before treefield_update_7000() has run.
    if (isset($this->field['storage']['details']['sql'][FIELD_LOAD_CURRENT][$this->tableName]['depth'])) {
      $this->columnMap['depth'] = $this->field['storage']['details']['sql'][FIELD_LOAD_CURRENT][$this->tableName]['depth'];
    }

    $this->entityType = $this->field['settings']['target_type'];
  }

  /**
   * Implements Tree_Storage_SQL::getDatabase().
   */
  public function getDatabase() {
    return $this->database;
  }

  /**
   * Implements Tree_Storage_SQL::getColumnMap().
   */
  public function getColumnMap() {
    return $this->columnMap;
  }

  /**
   * Implements Tree_Storage_SQL::getTableName().
   */
  public function getTableName() {
    return $this->tableName;
  }

  /**
   * Overrides Tree_Storage_SQL::query().
   */
  function query() {
    return new Tree_Storage_SQL_Field_Query($this->database, $this->tableName, $this->entityType, $this->columnMap);
  }

  /**
   * Converts the values of a field item to a tree item.
   *
   * @param int $entity_id
   *   An entity ID.
   * @param array $field_data
   *   An array of field values.
   *
   * @return Tree_Storage_SQL_Item
   *   A Tree_Storage_SQL_Item object.
   */
  public function itemFromFieldData($entity_id, array $field_data) {
    $row = array(
      $this->columnMap['id'] => $entity_id,
      $this->columnMap['parent'] => isset($field_data['target_id']) ? $field_data['target_id'] : NULL,
      $this->columnMap['weight'] => isset($field_data['weight']) ? $field_data['weight'] : 0,
      $this->columnMap['depth'] => isset($field_data['depth']) ? $field_data['depth'] : NULL,
    );
    return new Tree_Storage_SQL_Item($row, $this->columnMap);
  }

  /**
   * Converts the properties of a tree item into values of a field item.
   *
   * @param Tree_Storage_SQL_Item $item
   *   A Tree_Storage_SQL_Item object.
   *
   * @return array
   *   An arrat of field item values.
   */
  public function itemToFieldData(Tree_Storage_SQL_Item $item) {
    $field_data = array(
      'target_id' => $item->parent,
      'weight' => $item->weight,
      'depth' => $item->depth,
    );
    return $field_data;
  }

  public function views_data_alter(&$data, $field) {
    $additional_fields = array();
    foreach ($this->columnMap as $name => $real_name) {
      $additional_fields[$name] = array('field' => $real_name);
    }
    $data[$this->tableName]['tree_draggable'] = array(
      'title' => t('Draggable'),
      'group' => t('Tree'),
      'field' => array(
        'handler' => 'treefield_views_handler_field_draggable',
        'click sortable' => FALSE,
        'real field' => $this->columnMap['parent'],
        'additional fields' => $additional_fields,
        'field api' => $this->field,
      ),
    );
  }
}

/**
 * Defines a Field API SQL-specific query implementation.
 */
class Tree_Storage_SQL_Field_Query extends Tree_Storage_SQL_Query {

  /**
   * Constructs a Tree_Storage_SQL_Field_Query object.
   */
  function __construct(DatabaseConnection $database, $table_name, $entity_type, array $column_map) {
    $this->query = $database->select($table_name, 't', array('fetch' => PDO::FETCH_ASSOC));
    $this->query->fields('t');

    // Join the field table to the entity table so that the missing IDs appear
    // in the tree.
    $entity_info = entity_get_info($entity_type);
    $this->query->leftJoin($entity_info['base table'], 'e', 'e.' . $entity_info['entity keys']['id'] . ' = t.entity_id');

    $this->columnMap = $column_map;
  }
}
