<?php

/**
 * Defines a SQL-joinable tree storage.
 *
 * The query returned by this implementation is a SelectQueryInterface. Providers
 * using this implementation can join to denormalized tables.
 */
abstract class Tree_Storage_SQL implements Tree_Storage {

  /**
   * Gets the database connection for this storage.
   *
   * @return DatabaseConnection
   *   A DatabaseConnection object.
   */
  abstract public function getDatabase();

  /**
   * Gets the column map for this SQL-joinable storage.
   *
   * @retur array
   */
  abstract public function getColumnMap();

  /**
   * Gets the name of the base table.
   *
   * @return string
   */
  abstract public function getTableName();

  /**
   * Implements Tree_Storage::query().
   *
   * @return Tree_Storage_SQL_Query
   */
  function query() {
    return new Tree_Storage_SQL_Query($this->database, $this->tableName, $this->columnMap);
  }
}

/**
 * Defines a tree item stored in SQL.
 */
class Tree_Storage_SQL_Item implements Tree_Storage_Item {

  /**
   * @var int
   *
   * The ID of this tree item.
   */
  public $id = NULL;

  /**
   * @var int
   *
   * The parent ID of this tree item.
   */
  public $parent = NULL;

  /**
   * @var int
   *
   * The weight of this tree item.
   */
  public $weight = 0;

  /**
   * @var int
   *
   * The depth of this tree item.
   */
  public $depth = NULL;

  /**
   * @var array
   *
   * An array of tree item values.
   */
  protected $values = array();

  /**
   * @var array
   */
  protected $columnMap = array();

  /**
   * Constructs a Tree_Storage_SQL_Item object.
   */
  function __construct(array $values, array $column_map) {
    $this->values = $values;
    $this->columnMap = $column_map;

    foreach ($this->columnMap as $key => $row_key) {
      if (isset($this->values[$row_key])) {
        $this->$key = $this->values[$row_key];
      }
    }
  }

  /**
   * Returns the tree item values.
   *
   * @return array
   */
  function getValues() {
    $values = array();
    foreach ($this->columnMap as $key => $row_key) {
      $values[$row_key] = $this->$key;
    }

    return $values + $this->values;
  }
}

/**
 * Defines an implementation of Tree_Storage_Query that does a direct query on a
 * table.
 */
class Tree_Storage_SQL_Query implements Tree_Storage_Query {

  /**
   * @var SelectQueryInterface
   */
  public $query;

  /**
   * @var array
   */
  public $columnMap;

  /**
   * Constructs a Tree_Storage_SQL_Query object.
   */
  function __construct(DatabaseConnection $database, $table_name, array $column_map) {
    $this->query = $database->select($table_name, 't', array('fetch' => PDO::FETCH_ASSOC));
    $this->query->fields('t');
    $this->columnMap = $column_map;
  }

  /**
   * Implements Tree_Storage_Query::execute().
   */
  function execute() {
    $results = array();
    foreach ($this->query->execute() as $row) {
      $results[] = new Tree_Storage_SQL_Item($row, $this->columnMap);
    }
    return $results;
  }

  /**
   * Implements Tree_Storage_Query::condition().
   */
  function condition($column, $value, $operator = NULL) {
    $this->query->condition('t.' . $this->columnMap[$column], $value, $operator);
    return $this;
  }

  /**
   * Implements Tree_Storage_Query::orderBy().
   */
  function orderBy($column, $direction = 'ASC') {
    $this->query->orderBy('t.' . $this->columnMap[$column], $direction);
    return $this;
  }

  /**
   * Implements Tree_Storage_Query::isNull().
   */
  function isNull($column) {
    $this->query->isNull('t.' . $this->columnMap[$column]);
    return $this;
  }

  /**
   * Implements Tree_Storage_Query::isNotNull().
   */
  function isNotNull($column) {
    $this->query->isNotNull('t.' . $this->columnMap[$column]);
    return $this;
  }

  /**
   * Implements Tree_Storage_Query::alwaysFalse().
   */
  function alwaysFalse() {
    $this->query->where('1 = 0');
    return $this;
  }
}
