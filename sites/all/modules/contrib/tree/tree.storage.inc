<?php

/**
 * Defines an abstract storage for trees.
 */
interface Tree_Storage {

  /**
   * Builds a query for this tree.
   *
   * @return Tree_Storage_Query
   *   A Tree_Storage_Query object.
   */
  public function query();
}

/**
 * Defines a storage that is testable.
 *
 * Necessary for building fixtures for tests.
 */
interface Tree_Storage_Testable {

  /**
   * Sets the provider for this storage.
   */
  public function setProvider(Tree_Provider $provider);

  /**
   * Creates a memory representation of a tree item.
   *
   * @return Tree_Storage_Item
   */
  public function create();

  /**
   * Saves a tree item to the underlying storage.
   */
  public function save(Tree_Storage_Item $item);

  /**
   * Deletes a tree item from the underlying storage.
   */
  public function delete($item_id);
}

/**
 * Defines an abstract query for trees.
 */
interface Tree_Storage_Query {

  /**
   * Applies a condition to the query.
   *
   * @param string $column
   *   The name of the tree column to check ('id', 'parent', 'weight' or
   *   'depth').
   * @param mixed $value
   *   The value to test the column against. In most cases, this is a scalar.
   *   For more complex options, it is an array. The meaning of each element in
   *   the array is dependent on the $operator.
   * @param string $operator
   *   The comparison operator, such as =, <, or >=. It also accepts more
   *   complex options such as IN, LIKE, or BETWEEN. Defaults to IN if $value is
   *   an array, and = otherwise.
   *
   * @return Tree_Storage_Query
   *   The called object.
   */
  public function condition($column, $value, $operator = NULL);

  /**
   * Sets a condition that the specified column is NULL.
   *
   * @param string $column
   *   The name of the tree column to check ('id', 'parent', 'weight' or
   *   'depth').
   *
   * @return Tree_Storage_Query
   *   The called object.
   */
  public function isNull($column);

  /**
   * Sets a condition that the specified column is not NULL.
   *
   * @param string $column
   *   The name of the tree column to check ('id', 'parent', 'weight' or
   *   'depth').
   *
   * @return Tree_Storage_Query
   *   The called object.
   */
  public function isNotNull($column);

  /**
   * Sets a condition that is always false.
   *
   * @return Tree_Storage_Query
   *   The called object.
   */
  public function alwaysFalse();

  /**
   * Orders the result set by a given column.
   *
   * If called multiple times, the query will order by each specified field in
   * the order this method is called.
   *
   * @param string $column
   *   The name of the tree column to check ('id', 'parent', 'weight' or
   *   'depth').
   * @param string $direction
   *   The direction to sort ('ASC' or 'DESC').
   *
   * @return Tree_Storage_Query
   *   The called object.
   */
  public function orderBy($column, $direction = 'ASC');

  /**
   * Runs the query.
   *
   * @return array<Tree_Storage_Item>
   *   An array of Tree_Storage_Item objects.
   */
  public function execute();
}

/**
 * Defines an abstract item stored in a tree.
 *
 * Every tree item contains four public properties:
 *   - id: the ID of this item
 *   - parent: the ID of the parent of this item in the tree
 *   - weight: the weight of this item among its siblings
 *   - depth: the depth of this item
 */
interface Tree_Storage_Item {

}
