<?php

/**
 * A implementation of the SQL-joinable storage for test purposes.
 */
class Tree_Storage_SQL_Testable extends Tree_Storage_SQL implements Tree_Storage_Testable {
  public function __construct(DatabaseConnection $database, $table_name) {
    $this->database = $database;
    $this->tableName = $table_name;

    $this->columnMap = array(
      'id' => 'my_id',
      'parent' => 'my_parent_id',
      'weight' => 'my_weight',
      'depth' => 'my_depth',
    );
  }

  /**
   * Create the schema for the storage.
   */
  protected function createSchema() {
    $table_schema = array(
      'fields' => array(
        'my_id' => array(
          'description' => 'The ID of this item.',
          'type' => 'serial',
          'not null' => TRUE,
        ),
        'my_parent_id' => array(
          'description' => 'The ID of the parent of this item.',
          'type' => 'int',
          'not null' => FALSE,
          'default' => 0,
        ),
        'my_weight' => array(
          'description' => 'The weight of this item among its siblings.',
          'type' => 'int',
          'not null' => FALSE,
          'default' => 0,
        ),
        'my_depth' => array(
          'description' => 'The depth of this item.',
          'type' => 'int',
          'not null' => FALSE,
          'default' => 0,
        ),
      ),
      'primary key' => array('my_id'),
      'indexes' => array(
        'parent_id' => array('my_parent_id'),
      ),
    );

    db_create_table($this->tableName, $table_schema);

    // Create the schema of the provider.
    if ($this->provider instanceof Tree_Provider_SQL) {
      $provider_schema = $this->provider->schema();
      foreach ($provider_schema as $table_name => $table_schema) {
        db_create_table($table_name, $table_schema);
      }
    }
  }

  public function getDatabase() {
    return $this->database;
  }

  public function getColumnMap() {
    return $this->columnMap;
  }

  public function getTableName() {
    return $this->tableName;
  }

  public function setProvider(Tree_Provider $provider) {
    $this->provider = $provider;

    $this->createSchema();
  }

  function create() {
    return new Tree_Storage_SQL_Item(array(), $this->columnMap);
  }

  function save(Tree_Storage_Item $item) {
    $transaction = db_transaction();
    try {
      $this->provider->preSave($item);
      $row = $item->getValues();
      if (isset($row[$this->columnMap['id']])) {
        $this->database->update($this->tableName)
          ->fields($row)
          ->condition($this->columnMap['id'], $row[$this->columnMap['id']])
          ->execute();
        $this->provider->postUpdate($item);
      }
      else {
        $id = $this->database->insert($this->tableName)
          ->fields($row)
          ->execute();
        $item->id = $id;
        $this->provider->postInsert($item);
      }
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception('tree', $e);
      throw $e;
    }
  }

  function delete($id) {
    return $this->database->delete($this->tableName, 't')
      ->condition('t.' . $this->columnMap['id'], $id)
      ->execute();
  }
}
